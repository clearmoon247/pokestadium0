/* Stadium Zero fragment006_162BE0. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_2FA4D0.c, src/fragments/battle_engine/battle_engine_3020D0.c, src/fragments/trade_machine/trade_machine_291D60.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "graphics_textures.h"
#include "ui_graphics.h"
#include "status_icons.h"
#include "game_state.h"
#include "text_system.h"
#include "3D140.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "matrix.h"
#include "controller.h"
#include "memmap.h"
#include "memory.h"

#include "fragments/trade_machine/trade_machine.h"
#include "graphics_textures.h"
#include "ui_graphics.h"
#include "pokemon_stats.h"
#include "text_system.h"
#include "audio_sfx.h"
#define U64_NOP(x) ((u32)((u64)(x) | 0ULL))

#include "fragments/battle_engine/battle_engine.h"
#include "graphics_textures.h"
#include "ui_graphics.h"
#include "status_icons.h"
#include "game_state.h"
#include "text_system.h"
#include "3D140.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "matrix.h"
#include "controller.h"
#include "memmap.h"
#include "memory.h"
#include "stdarg.h"
#include "moves.h"
extern unk_D_843901A0* gBattleMessageQueues;

#include "m2c_macros.h"

void BattleHud_Noop(void);
void func_88400100(void);
void Trade_DrawSaveSeqMessageBackdrop(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_884022A4(void);

extern s32 D_88403358;

void func_88400020(s32 arg0, s8 *arg1) {
    if (arg0 == 2) {
        if (D_88403358 >= 0) {
            M2C_FIELD(arg1, u8 *, 1) = (u8) (M2C_FIELD(arg1, u8 *, 1) | 1);
            return;
        }
        M2C_FIELD(arg1, u8 *, 1) = (u8) (M2C_FIELD(arg1, u8 *, 1) & 0xFFFE);
    }
}

void BattleHud_Noop(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_88400064; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88400064.s")
#endif

M2C_UNK func_8000B1FC();                            /* extern */
M2C_UNK func_8000B220();                            /* extern */
M2C_UNK func_8001B5F0();                            /* extern */

s32 func_884000CC(void) {
    func_8000B1FC();
    func_8000B220();
    func_8001B5F0();
    return 0;
}

void func_88400100(void) {
}

M2C_UNK func_80005770(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800069CC();                            /* extern */
M2C_UNK func_8001560C(s32);                         /* extern */
M2C_UNK func_800158C0();                            /* extern */
M2C_UNK func_884000CC();                            /* extern */
extern M2C_UNK D_800AA150;
extern s32 D_88403370;

s32 func_88400108(s32 arg0) {
    func_884000CC();
    func_800158C0();
    func_800069CC();
    func_80005770(&D_800AA150, 0, 0, 0x140, 0xF0);
    func_8001560C(D_88403370);
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_88400168; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88400168.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88400458; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88400458.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8840079C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_8840079C.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses data data that is not placed in this file yet.
void Trade_DrawSaveSeqMessageBackdrop(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    Color_RGB8 sp24 = { 0x58, 0x08, 0x00 };
    Color_RGB8 sp20 = { 0x58, 0x08, 0x00 };

    Ui_DrawGradientPanel(arg0, arg1, arg2, arg3, &sp24, &sp20);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88400A1C.s")
#endif

M2C_UNK func_80006780();                            /* extern */
M2C_UNK func_88400108(M2C_UNK);                     /* extern */
M2C_UNK func_88400A1C(s16, s16, s16, s16);          /* extern */

void func_88400A98(void) {
    s16 var_s0;
    s16 var_s1;
    s32 var_s2;

    var_s0 = 0x20;
    var_s1 = 0x14;
    var_s2 = 0;
    do {
        func_88400108(0);
        func_88400A1C((s16) (0xA0 - (var_s0 / 2)), (s16) (0x3C - (var_s1 / 2)), var_s0, var_s1);
        func_80006780();
        var_s2 += 1;
        var_s0 += 0x14;
        var_s1 += 4;
    } while (var_s2 != 8);
}

M2C_UNK func_80006780();                            /* extern */
M2C_UNK func_88400108(M2C_UNK);                     /* extern */
M2C_UNK func_88400A1C(s16, s16, s16, s16);          /* extern */

void func_88400B70(void) {
    s16 var_s0;
    s16 var_s1;
    s32 var_s2;

    var_s0 = 0xC4;
    var_s1 = 0x34;
    var_s2 = 0;
    do {
        func_88400108(0);
        func_88400A1C((s16) (0xA0 - (var_s0 / 2)), (s16) (0x3C - (var_s1 / 2)), var_s0, var_s1);
        func_80006780();
        var_s2 += 1;
        var_s0 -= 0x14;
        var_s1 -= 4;
    } while (var_s2 != 8);
}

extern s32 D_88403364;
void func_88400C48(s16 arg0, s16 arg1) {
    s32 var_a3;

    if (D_88403364 < 0x10) {
        var_a3 = D_88403364 * 0x10;
    } else if (D_88403364 < 0x23) {
        var_a3 = 0xFF;
    } else if (D_88403364 < 0x32) {
        var_a3 = (-D_88403364 * 0x10) + 0x320;
    } else {
        var_a3 = 0;
    }

    D_88403364++;
    if (D_88403364 >= 0x3D) {
        D_88403364 = 0;
    }

    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, var_a3);
    Font_DrawCharAt(arg0, arg1, 0x2177);
}

M2C_UNK func_80006780();                            /* extern */
M2C_UNK func_8001A384(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8001A944(M2C_UNK, M2C_UNK, s32);       /* extern */
M2C_UNK func_8001AB2C(M2C_UNK);                     /* extern */
M2C_UNK func_8001AB6C();                            /* extern */
M2C_UNK func_8001ABBC();                            /* extern */
M2C_UNK func_8003F6AC(M2C_UNK);                     /* extern */
M2C_UNK func_88400108(M2C_UNK);                     /* extern */
extern s8 *D_800603C0;
extern s32 D_88402D70;
extern s32 D_88403364;

void func_88400CE8(s32 arg0) {
    D_88403364 = 0x10;
    do {
        func_88400108(0);
        func_88400A1C(0x1E, 0x20, 0x104, 0x34);
        func_8001AB6C();
        func_8001A384(4, -1);
        func_8001AB2C(0x14);
        func_8001A944(0x2E, 0x28, arg0);
        func_88400C48(0x104, 0x3C);
        func_8001ABBC();
        func_80006780();
    } while (!(M2C_FIELD(D_800603C0, u16 *, 8) & 0x8000));
    func_8003F6AC(1);
    D_88402D70 = arg0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_88400DAC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88400DAC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88400F4C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88400F4C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88401040; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88401040.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8840115C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_8840115C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88401290; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88401290.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_884014B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_884014B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8840173C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_8840173C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88401970; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88401970.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88401A88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88401A88.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88401B40; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88401B40.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88401D54; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88401D54.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88401E24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88401E24.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88401F38; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88401F38.s")
#endif

M2C_UNK func_80006828(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_80006998(M2C_UNK);                     /* extern */
M2C_UNK func_800199E4(M2C_UNK *);                   /* extern */
extern s32 D_88403358;
extern M2C_UNK D_88403378;
extern M2C_UNK D_88403648;

void func_88402038(void) {
    func_80006998(0xFFFF);
    func_80006828(0x13, &func_88400108);
    M2C_FIELD(&D_88403648, u8 *, 2) = (u8) (M2C_FIELD(&D_88403648, u8 *, 2) & 0xFFDF);
    if (D_88403358 >= 0) {
        func_800199E4(&D_88403378);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_88402098; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88402098.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88402174; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88402174.s")
#endif

void func_884022A4(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_884022AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_884022AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88402334; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88402334.s")
#endif

M2C_UNK func_80005B98(M2C_UNK);                     /* extern */
M2C_UNK func_800067BC(M2C_UNK);                     /* extern */
M2C_UNK func_80006828(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_8000D520(s32, s8 *);                 /* extern */
M2C_UNK func_80025BE4(s32);                         /* extern */
M2C_UNK func_884000CC();                            /* extern */
M2C_UNK func_8840115C();                            /* extern */
M2C_UNK func_884022AC();                            /* extern */
extern s8 D_88402DD0;
extern s8 D_88402DEC;
extern s32 D_88403358;
extern s32 D_88403360;
s32 func_884023F0(void) {
    s32 sp1C;

    sp1C = M2C_FIELD(D_88403370, s32 *, 0xC);
    func_80025BE4(D_88403358);
    D_88403360 = 0;
    func_884000CC();
    func_800067BC(1);
    func_80005B98(0x1E);
    func_8000D520(sp1C + 0xB4, &D_88402DD0 + 2);
    func_8000D520(sp1C + 0xA8, &D_88402DEC + 2);
    func_80006828(5, &func_88400108);
    func_8840115C();
    func_884022AC();
    return 1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8840248C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_8840248C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88402538; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88402538.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_884025E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_884025E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_884026A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_884026A4.s")
#endif

s32 func_800023C4(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_800051C0(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
s32 func_800051F0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800052E8(s32, s32);                    /* extern */
extern s8 *D_88403368;
extern s8 *D_8840336C;

void func_884029FC(void) {
    s32 sp2C;

    sp2C = func_800051F0(0, 2, 0x140, 0xF0, 0);
    M2C_FIELD(D_8840336C, s32 *, 0x18) = func_800023C4(0x10, 0);
    M2C_FIELD(D_8840336C, s32 *, 0x1C) = func_800023C4(0x10, 0);
    func_800051C0(M2C_FIELD(D_8840336C, s32 *, 0x18), 0, 2, 0x140, 0xF0, M2C_FIELD(M2C_FIELD(D_88403368, s8 **, 0x18), s32 *, 8));
    func_800051C0(M2C_FIELD(D_8840336C, s32 *, 0x1C), 0, 2, 0x140, 0xF0, M2C_FIELD(M2C_FIELD(D_88403368, s8 **, 0x1C), s32 *, 8));
    func_800052E8(M2C_FIELD(D_8840336C, s32 *, 0x18), sp2C);
    func_800052E8(M2C_FIELD(D_8840336C, s32 *, 0x1C), sp2C);
}

#ifdef NON_MATCHING
/* TODO: decompile func_88402AF0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment006_162BE0/func_88402AF0.s")
#endif
