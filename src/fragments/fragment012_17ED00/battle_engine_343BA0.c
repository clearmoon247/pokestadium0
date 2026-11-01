/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_343BA0.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "gallery.h"
#include "gfx_buffer.h"
#include "math.h"
#include "math_util.h"
extern u8* sBattleAnimAssetPointers[256];
extern s16 sBattleAnimResourceList[0x10];
extern arg1_func_80019420* sBattleAnimResourceTablePointers[40];
extern s16 D_8219CAC0;
extern s16 D_8219CAC2;
extern Mtx D_8219CAC8;
extern s16 D_8219CB08;
extern s16 D_8219CB0A;
extern s16 D_8219CB0C;
extern s16 D_8219CB0E;
extern s16 D_8219CB10;
extern s16 D_8219CB12;
extern s16 D_8219CB14;
extern s16 D_8219CB16;
extern s16 D_8219CB18;
extern s16 D_8219CB1A;
extern const char D_821978C8[];

#include "m2c_macros.h"

void func_821329F0(void);

void func_821329F0(void) {
}

M2C_UNK func_80006998(M2C_UNK);                     /* extern */
M2C_UNK func_8212188C();                            /* extern */
M2C_UNK func_82121D78(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_82124984(s8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_82136918(s32, M2C_UNK);                /* extern */
extern s8 *D_82199DE0;
extern s8 *D_8219A580;
extern s8 *D_8219A5A0;

void func_821329F8(s32 arg0) {
    s8 *sp1C;

    sp1C = D_82199DE0 + 0x78C;
    M2C_FIELD(D_8219A5A0, s32 *, 0x50) = 0;
    func_82121D78(arg0, 0x41A00000, 0x457A0000);
    func_8212188C();
    M2C_FIELD(D_8219A5A0, u16 *, 0x2C) = 0U;
    D_8219A580 = (&D_82199DE0)[M2C_FIELD(D_8219A5A0, u16 *, 0x2C)];
    M2C_FIELD(sp1C, s32 *, 8) = 0;
    func_82124984(D_8219A580, arg0, 3);
    func_82136918(M2C_FIELD(D_8219A580, s32 *, 0x85C), 9);
    func_80006998(0);
    M2C_FIELD(D_8219A5A0, s32 *, 0x20) = (s32) (M2C_FIELD(D_8219A5A0, s32 *, 0x20) + 1);
}

s32 func_82101FD4(s32);                             /* extern */
extern s8 *D_8219A5A0;

void func_82132AC4(s32 arg0) {
    if (func_82101FD4(D_8219A580) != 0) {
        M2C_FIELD(D_8219A5A0, s32 *, 0x20) = (s32) (M2C_FIELD(D_8219A5A0, s32 *, 0x20) + 1);
    }
}

/*
 * func_82132B04
 *
 * Clears the byte at D_8219A4F1, calls func_821351F8(arg0, D_8219A580) and
 * func_82104C68(D_8219A580, 1), then adds 1 to the word at offset 0x20 of the
 * structure that D_8219A5A0 points to.  That word is advanced by neighbouring
 * functions in this file in the same way (see func_82132AC4), so it looks
 * like a step counter, but this is not established from the code alone.
 */
extern s8 D_8219A4F1;
void func_821351F8(CameraNode* arg0, s8* arg1);
void func_82104C68(s8* arg0, s32 arg1);

void func_82132B04(CameraNode* arg0) {
    D_8219A4F1 = 0;
    func_821351F8(arg0, D_8219A580);
    func_82104C68(D_8219A580, 1);
    M2C_FIELD(D_8219A5A0, s32 *, 0x20) = (s32) (M2C_FIELD(D_8219A5A0, s32 *, 0x20) + 1);
}

/*
 * func_82132B54
 *
 * Calls func_82135894(arg0, D_8219A580).  If that returns non-zero, adds 1
 * to the word at offset 0x20 of the structure that D_8219A5A0 points to.
 * func_82132AC4, just above, is the same pattern with func_82101FD4 and a
 * single argument.  What the counter at +0x20 counts is not established
 * from the code alone.
 */
s32 func_82135894(CameraNode* arg0, s8* arg1);

void func_82132B54(CameraNode* arg0) {
    if (func_82135894(arg0, D_8219A580) != 0) {
        M2C_FIELD(D_8219A5A0, s32 *, 0x20) = (s32) (M2C_FIELD(D_8219A5A0, s32 *, 0x20) + 1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82132B90; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82132B90.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82132C14; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82132C14.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82132CDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82132CDC.s")
#endif

// Zero's version takes only the particle; the header keeps Stadium 1's callback signature.
void func_82132D3C(Particle* arg0) {
    BattleAnim_DrawI4AtlasYScaled(arg0, D_8219A580);
}

void func_82132B04(CameraNode* arg0);
void func_82132B54(CameraNode* arg0);
void func_82132B90(CameraNode* arg0);
void func_82132C14(CameraNode* arg0);
void func_82132CDC(CameraNode* arg0);

void func_82132D60(CameraNode* arg0) {
    switch (sBattleScene.scene->unk_20) {
        case 0:
            func_821329F8((s32)arg0);
            break;
        case 1:
            func_82132AC4((s32)arg0);
            break;
        case 2:
            func_82132B04(arg0);
            break;
        case 3:
            func_82132B54(arg0);
            break;
        case 4:
            func_82132B90(arg0);
            break;
        case 5:
            func_82132C14(arg0);
            break;
        case 6:
            func_82132CDC(arg0);
            break;
        case 7:
            func_82132D3C((Particle*)arg0);
            break;
    }
}
