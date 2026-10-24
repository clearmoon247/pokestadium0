/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/math_util.c. */

#include "global.h"
#include "math_util.h"
#include "trig_tables.inc.c"

u16 MathUtil_Atan2Lookup(f32 y, f32 x);
s16 MathUtil_Atan2s(f32 y, f32 x);
s32 MathUtil_Random16(void);
f32 MathUtil_Random_ZeroOne(void);

/**
 * Helper function for atan2s. Does a look up of the arctangent of y/x assuming
 * the resulting angle is in range [0, 0x2000] (1/8 of a circle).
 */
u16 MathUtil_Atan2Lookup(f32 y, f32 x) {
    u16 ret;

    if (x == 0) {
        ret = gArctanTable[0];
    } else {
        ret = gArctanTable[(s32)(y / x * 1024 + 0.5f)];
    }
    return ret;
}

/**
 * Compute the angle from (0, 0) to (x, y) as a s16. Given that terrain is in
 * the xz-plane, this is commonly called with (z, x) to get a yaw angle.
 */
s16 MathUtil_Atan2s(f32 y, f32 x) {
    u16 ret;

    if (x >= 0) {
        if (y >= 0) {
            if (y >= x) {
                ret = MathUtil_Atan2Lookup(x, y);
            } else {
                ret = 0x4000 - MathUtil_Atan2Lookup(y, x);
            }
        } else {
            y = -y;
            if (y < x) {
                ret = 0x4000 + MathUtil_Atan2Lookup(y, x);
            } else {
                ret = 0x8000 - MathUtil_Atan2Lookup(x, y);
            }
        }
    } else {
        x = -x;
        if (y < 0) {
            y = -y;
            if (y >= x) {
                ret = 0x8000 + MathUtil_Atan2Lookup(x, y);
            } else {
                ret = 0xC000 - MathUtil_Atan2Lookup(y, x);
            }
        } else {
            if (y < x) {
                ret = 0xC000 + MathUtil_Atan2Lookup(y, x);
            } else {
                ret = -MathUtil_Atan2Lookup(x, y);
            }
        }
    }
    return ret;
}

/**
 * Gets a random 16-bit value determined by the guRandom call.
 */
s32 MathUtil_Random16(void) {
    return guRandom() & 0xFFFF; // would prototype this as u16, but doesnt match with other calls.
}

/**
 * Gets a random float between 0.0 to 1.0.
 */
f32 MathUtil_Random_ZeroOne(void) {
    return MathUtil_Random16() / 65536.0f;
}
