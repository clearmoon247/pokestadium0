/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/controller.c. */

#include "global.h"
#include "controller.h"
#include "gb_tower.h"
#include "math_util.h"
extern Controller* gPlayer1Controller;
extern Controller* gPlayer2Controller;
extern Controller* gPlayer3Controller;
extern Controller* gPlayer4Controller;
extern Controller gControllers[4];
extern OSMesgQueue gSIEventMesgQueue;
extern u8 gControllerBits;
extern u8 gEepromProbe;
extern OSContStatus gControllerStatuses[4];
extern OSContPad gControllerPads[4];
extern OSMesg gSIEventMesgBuf[1];
extern OSMesg gEepromMesgBuf[1];
extern OSMesgQueue gEepromMesgQueue;

#include "m2c_macros.h"

void Cont_AdjustAnalogStick(Controller* controller);

/*
 * Take the updated controller struct and calculate
 * the new x, y, and distance floats.
 */
void Cont_AdjustAnalogStick(Controller* controller) {
    // reset the controller's x and y floats.
    controller->stickX = 0.0f;
    controller->stickY = 0.0f;

    // modulate the rawStickX and rawStickY to be the new f32 values by adding/subtracting 6.
    if (controller->rawStickX <= -8) {
        controller->stickX = controller->rawStickX + 6;
    }

    if (controller->rawStickX >= 8) {
        controller->stickX = controller->rawStickX - 6;
    }

    if (controller->rawStickY <= -8) {
        controller->stickY = controller->rawStickY + 6;
    }

    if (controller->rawStickY >= 8) {
        controller->stickY = controller->rawStickY - 6;
    }

    // calculate f32 magnitude from the center by vector length.
    controller->stickMag = sqrtf(controller->stickX * controller->stickX + controller->stickY * controller->stickY);

    // magnitude cannot exceed 64.0f: if it does, modify the values appropriately to
    // flatten the values down to the allowed maximum value.
    if (controller->stickMag > 64) {
        controller->stickX *= 64 / controller->stickMag;
        controller->stickY *= 64 / controller->stickMag;
        controller->stickMag = 64;
    }

    if (controller->stickMag > 0.0f) {
        controller->angle = MathUtil_Atan2s(-controller->stickY, controller->stickX);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8000AFE4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000AFE4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8000B170; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000B170.s")
#endif

M2C_UNK func_80051C70(M2C_UNK *);                   /* extern */
extern M2C_UNK D_800AAFE0;

void func_8000B1FC(void) {
    func_80051C70(&D_800AAFE0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8000B220; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000B220.s")
#endif

extern u8 D_800AAFF8;

u8 func_8000B2E8(void) {
    return D_800AAFF8;
}
