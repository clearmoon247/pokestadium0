/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/controller.c, src/input.c. */

#include "global.h"
#include "input.h"
extern s32 pad_D_800AC880[0x2];
extern s32 D_800AB02C;
extern Controller* D_800AB030;

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

void Input_SetRepeatController(Controller* arg0);
s32 Input_GetRepeatedDPad(void);
s32 Cont_IsEepromPresent(void);

void Input_SetRepeatController(Controller* arg0) {
    D_800AB02C = 0xA;
    D_800AB030 = arg0;
}

s32 Input_GetRepeatedDPad(void) {
    if (D_800AB030->buttonPressed & 0x800) {
        D_800AB02C = 0xA;
        return 0x800;
    }

    if (D_800AB030->buttonPressed & 0x400) {
        D_800AB02C = 0xA;
        return 0x400;
    }

    if (D_800AB030->buttonPressed & 0x200) {
        D_800AB02C = 0xA;
        return 0x200;
    }

    if (D_800AB030->buttonPressed & 0x100) {
        D_800AB02C = 0xA;
        return 0x100;
    }

    D_800AB02C--;
    if (D_800AB02C <= 0) {
        D_800AB02C = 0;

        // clang-format off
        if (D_800AB030->buttonDown & 0x800) {
            D_800AB02C = 2; return 0x800;
        }
        // clang-format on

        if (D_800AB030->buttonDown & 0x400) {
            D_800AB02C = 2;
            return 0x400;
        }

        if (D_800AB030->buttonDown & 0x200) {
            D_800AB02C = 2;
            return 0x200;
        }

        if (D_800AB030->buttonDown & 0x100) {
            D_800AB02C = 2;
            return 0x100;
        }
    }

    return 0;
}

/*
 * Check if an EEPROM is connected. Since probe 0x00 is not connected and
 * 0x01 and 0x02 are otherwise, a non-0 probe means it is connected.
 */
s32 Cont_IsEepromPresent(void) {
    return gEepromProbe != 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8000B438; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000B438.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8000B4D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000B4D4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8000B570; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000B570.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8000B638; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000B638.s")
#endif
