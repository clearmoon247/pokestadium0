/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/matrix.c. */

#include "matrix.h"
#include "game_state.h"
#include "math_util.h"
extern Mtx gIdentityMtx;
extern Vec3f D_80060450;
extern Vec3s D_8006045C;
extern Vec3f D_80060464;
#define GET_HIGH_S16_OF_32(var) (((s16*)&(var))[0])
#define GET_LOW_S16_OF_32(var) (((s16*)&(var))[1])

s16 Math_StepToS(s16 current, s16 target, s16 delta);
s32 Math_StepToS32(s32 current, s32 target, s32 increase, s32 decrease);
f32 Math_StepToF(f32 current, f32 target, f32 increase, f32 decrease);
s16 PackedBits_ReadSigned(s16* packed, s32 offset, s32 length);
void Color_RGBToHSV(f32 r, f32 g, f32 b, Vec3f* dest);
void Color_RGBA8ToHSV(Color_RGBA8_u32 color, Vec3f* dest);
void Color_RGB5551ToHSV(u16 color, Vec3f* dest);
f32 Color_HSVInterpolate(f32 hue, f32 low, f32 high);
void Color_HSVToRGB(f32* arg0, f32* arg1, f32* arg2, Vec3f* arg3);
u16 Color_HSVToRGB5551(Vec3f* arg0);
Color_RGBA8_u32* Color_HSVToRGBA8(Color_RGBA8_u32* arg0, Vec3f* arg1, s32 arg2);
u16 Color_AdjustRGB5551(u16 arg0, arg1_func_80010CA8 arg1);
u32 Color_AdjustRGBA8(u32 arg0, arg1_func_80010CA8 arg1);

s16 Math_StepToS(s16 current, s16 target, s16 delta) {
    s16 temp_v0 = target - current;

    if (temp_v0 < 0) {
        temp_v0 += delta;
        if (temp_v0 > 0) {
            temp_v0 = 0;
        }
    } else {
        temp_v0 -= delta;
        if (temp_v0 < 0) {
            temp_v0 = 0;
        }
    }

    return target - temp_v0;
}

s32 Math_StepToS32(s32 current, s32 target, s32 increase, s32 decrease) {
    //! If target is close to the max or min s32, then it's possible to overflow
    // past it without stopping.

    if (current < target) {
        current += increase;
        if (current > target) {
            current = target;
        }
    } else {
        current -= decrease;
        if (current < target) {
            current = target;
        }
    }
    return current;
}

f32 Math_StepToF(f32 current, f32 target, f32 increase, f32 decrease) {
    if (current < target) {
        current += increase;
        if (current > target) {
            current = target;
        }
    } else {
        current -= decrease;
        if (current < target) {
            current = target;
        }
    }
    return current;
}

s16 PackedBits_ReadSigned(s16* packed, s32 offset, s32 length) {
    Vec2s_s32 spC;
    s16* temp_a3 = &packed[(offset * length) / 16];
    s16* p_spC = &spC.x;

    p_spC[0] = temp_a3[0];
    p_spC[1] = temp_a3[1];

    spC.xy <<= ((offset * length) % 16);
    spC.xy >>= -length;
    return spC.y;
}

void Color_RGBToHSV(f32 r, f32 g, f32 b, Vec3f* dest) {
    f32 temp_ft4;
    f32 var_ft5;
    f32 var_fv0;
    f32 var_fv1;
    s32 var_v0;

    var_v0 = 0x47;
    if (g <= r) {
        var_fv0 = r;
        var_v0 = 0x52;
    } else {
        var_fv0 = g;
    }

    if (var_fv0 < b) {
        var_fv0 = b;
        var_v0 = 0x42;
    }

    if (r <= g) {
        var_fv1 = r;
    } else {
        var_fv1 = g;
    }

    if (b < var_fv1) {
        var_fv1 = b;
    }

    temp_ft4 = var_fv0 + var_fv1;
    dest->z = temp_ft4 - 1.0f;
    if (var_fv0 == var_fv1) {
        dest->y = 0.0f;
        dest->x = 0.0f;
        return;
    }

    if (dest->z <= 0.0f) {
        var_ft5 = var_fv0 - var_fv1;
        dest->y = var_ft5 / temp_ft4;
    } else {
        var_ft5 = var_fv0 - var_fv1;
        dest->y = var_ft5 / (2.0 - temp_ft4);
    }

    if (var_v0 == 0x52) {
        dest->x = (g - b) / var_ft5;
    } else if (var_v0 == 0x47) {
        dest->x = ((b - r) / var_ft5) + 2.0;
    } else {
        dest->x = ((r - g) / var_ft5) + 4.0;
    }

    dest->x *= 60.0f;
    if (dest->x < 0.0f) {
        dest->x += 360.0f;
    }
}

void Color_RGBA8ToHSV(Color_RGBA8_u32 color, Vec3f* dest) {
    Color_RGBToHSV((s32)color.r / 255.0f, (s32)color.g / 255.0f, (s32)color.b / 255.0f, dest);
}

void Color_RGB5551ToHSV(u16 color, Vec3f* dest) {
    Color_RGBToHSV(((color & 0xF800) >> 0xB) / 31.0f, ((color & 0x7C0) >> 6) / 31.0f, ((color & 0x3E) >> 1) / 31.0f, dest);
}

f32 Color_HSVInterpolate(f32 hue, f32 low, f32 high) {
    f32 channel;

    if (hue < 0.0f) {
        hue += 360.0f;
    } else {
        while (hue >= 360.0f) {
            hue -= 360.0f;
        }
    }

    if (hue < 60.0f) {
        channel = (((high - low) * hue) / 60.0f) + low;
    } else if ((hue >= 60.0f) && (hue < 180.0f)) {
        channel = high;
    } else if ((hue >= 180.0f) && (hue < 240.0f)) {
        channel = low + (((high - low) * (240.0 - hue)) / 60.0);
    } else {
        channel = low;
    }

    return channel;
}

void Color_HSVToRGB(f32* arg0, f32* arg1, f32* arg2, Vec3f* arg3) {
    f32 sp24;
    f32 sp20;
    f32 temp_ft4;

    if (arg3->z < -1.0f) {
        arg3->z = -1.0f;
    } else if (arg3->z > 1.0f) {
        arg3->z = 1.0f;
    }

    if (arg3->y < 0.0f) {
        arg3->y = 0.0f;
    } else {
        sp24 = 1.0f;
        if (arg3->y > 1.0f) {
            arg3->y = 1.0f;
        }
    }

    if (arg3->x < 0.0f) {
        arg3->x += 360.0f;
    } else {
        while (arg3->x >= 360.0f) {
            arg3->x -= 360.0f;
        }
    }

    if (arg3->z <= 0.0f) {
        temp_ft4 = arg3->z + 1.0f;
        sp24 = temp_ft4 * 0.5f * (1.0f - arg3->y);
        sp20 = temp_ft4 - sp24;
    } else {
        temp_ft4 = arg3->z + 1.0f;
        sp20 = (temp_ft4 * 0.5 * (1.0f - arg3->y)) + arg3->y;
        sp24 = temp_ft4 - sp20;
    }

    *arg0 = Color_HSVInterpolate(arg3->x + 120.0f, sp24, sp20);
    *arg1 = Color_HSVInterpolate(arg3->x, sp24, sp20);
    *arg2 = Color_HSVInterpolate(arg3->x - 120.0f, sp24, sp20);
}

u16 Color_HSVToRGB5551(Vec3f* arg0) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;

    Color_HSVToRGB(&sp2C, &sp28, &sp24, arg0);

    var_a1 = (sp2C * 31.0f) + 0.5f;
    if (var_a1 >= 0x20) {
        var_a1 = 0x1F;
    }

    var_v1 = (sp28 * 31.0f) + 0.5f;
    if (var_v1 >= 0x20) {
        var_v1 = 0x1F;
    }

    var_a0 = (sp24 * 31.0f) + 0.5f;
    if (var_a0 >= 0x20) {
        var_a0 = 0x1F;
    }

    return (var_a1 << 0xB) | (var_v1 << 6) | (var_a0 * 2) | 1;
}

Color_RGBA8_u32* Color_HSVToRGBA8(Color_RGBA8_u32* arg0, Vec3f* arg1, s32 arg2) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    Color_RGBA8_u32 sp1C;

    Color_HSVToRGB(&sp34, &sp30, &sp2C, arg1);

    var_a1 = (sp34 * 255.0f) + 0.5f;
    if (var_a1 >= 0x100) {
        var_a1 = 0xFF;
    }

    var_v1 = (sp30 * 255.0f) + 0.5f;
    if (var_v1 >= 0x100) {
        var_v1 = 0xFF;
    }

    var_a0 = (sp2C * 255.0f) + 0.5f;
    if (var_a0 >= 0x100) {
        var_a0 = 0xFF;
    }

    sp1C.r = var_a1;
    sp1C.g = var_v1;
    sp1C.b = var_a0;
    sp1C.a = arg2;

    *arg0 = sp1C;

    return arg0;
}

u16 Color_AdjustRGB5551(u16 arg0, arg1_func_80010CA8 arg1) {
    Vec3f sp24;
    s32 a;
    s32 b;

    if (arg0 & 1) {
        Color_RGB5551ToHSV(arg0, &sp24);

        if (arg1.unk_00 != 0) {
            sp24.x += (arg1.unk_00 * 0.015625f);
        }

        if (arg1.unk_02 != 0) {
            if (arg1.unk_02 > 0) {
                sp24.y += ((1.0f - sp24.y) * arg1.unk_02 * 0.125f);
            } else {
                sp24.y += (sp24.y * arg1.unk_02 * 0.125f);
            }
        }

        if (arg1.unk_03 != 0) {
            a = (((sp24.z + 1.0f) * 0.5f * 255.0f));
            if (arg1.unk_03 > 0) {
                b = arg1.unk_03 + 7;
            } else {
                b = arg1.unk_03 + 8;
            }

            sp24.z = (2.0f * (D_8006BBB0[b][a] / 65535.0f)) - 1.0f;
        }

        arg0 = Color_HSVToRGB5551(&sp24);
    }
    return arg0;
}

u32 Color_AdjustRGBA8(u32 arg0, arg1_func_80010CA8 arg1) {
    Vec3f sp2C;
    Color_RGBA8_u32 arg;
    s32 a;
    s32 b;

    arg.rgba = arg0;

    if (arg.a > 0) {
        Color_RGBA8ToHSV(arg, &sp2C);

        if (arg1.unk_00 != 0) {
            sp2C.x += (arg1.unk_00 * 0.015625f);
        }

        if (arg1.unk_02 != 0) {
            if (arg1.unk_02 > 0) {
                sp2C.y += ((1.0f - sp2C.y) * arg1.unk_02 * 0.125f);
            } else {
                sp2C.y += (sp2C.y * arg1.unk_02 * 0.125f);
            }
        }

        if (arg1.unk_03 != 0) {
            a = (((sp2C.z + 1.0f) * 0.5f * 255.0f));

            if (arg1.unk_03 > 0) {
                b = arg1.unk_03 + 7;
            } else {
                b = arg1.unk_03 + 8;
            }

            sp2C.z = (2.0f * (D_8006BBB0[b][a] / 65535.0f)) - 1.0f;
        }

        Color_HSVToRGBA8(&arg, &sp2C, arg.a);
    }

    return arg.rgba;
}
