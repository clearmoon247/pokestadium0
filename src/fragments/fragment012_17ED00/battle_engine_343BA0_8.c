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

void BattleAnim_StartEffect98Radial20_Init(void);
s32 BattleAnim_StartEffect98Radial20_Update(void);
void BattleAnim_StartEffect98Radial20_Draw(void);
void BattleAnim_StartEffect11Trail50Alt_Init(void);
s32 BattleAnim_StartEffect11Trail50Alt_Update(void);
void BattleAnim_StartEffect11Trail50Alt_Draw(void);
void BattleAnim_StartEffect57Trail50_Init(void);
s32 BattleAnim_StartEffect57Trail50_Update(void);
void BattleAnim_StartEffect57Trail50_Draw(void);
void BattleAnim_StartEffect42Trail40_Init(void);
s32 BattleAnim_StartEffect42Trail40_Update(void);
void BattleAnim_StartEffect42Trail40_Draw(void);
void BattleAnim_StartEffect43Trail40Variant_Init(void);
s32 BattleAnim_StartEffect43Trail40Variant_Update(void);
void BattleAnim_StartEffect43Trail40Variant_Draw(void);
void BattleAnim_StartEffect44Trail40GridAlt_Init(void);
s32 BattleAnim_StartEffect44Trail40GridAlt_Update(void);
void BattleAnim_StartEffect44Trail40GridAlt_Draw(void);
void BattleAnim_StartEffect45FourStreamTrail_Init(void);
void BattleAnim_StartEffect45FourStreamTrail_Draw(void);
void BattleAnim_StartEffect62OwnerLinkedFourStream_Init(void);
s32 BattleAnim_StartEffect62OwnerLinkedFourStream_Update(void);
void BattleAnim_StartEffect62OwnerLinkedFourStream_Draw(void);
void BattleAnim_StartEffect67OwnerAnchoredFourStream_Init(void);
s32 BattleAnim_StartEffect67OwnerAnchoredFourStream_Update(void);
void BattleAnim_StartEffect67OwnerAnchoredFourStream_Draw(void);
void BattleAnim_StartEffect78Radial20_Init(void);
s32 BattleAnim_StartEffect78Radial20_Update(void);
void BattleAnim_StartEffect78Radial20_Draw(void);
void BattleAnim_StartEffect26DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect26DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect26DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect26DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect47SixSlotTrail_Seed(void);
void BattleAnim_StartEffect47SixSlotTrail_Init(void);
s32 BattleAnim_StartEffect47SixSlotTrail_Update(void);
void BattleAnim_StartEffect47SixSlotTrail_Draw(void);
void BattleAnim_StartEffect4DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect4DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect4DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect4DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect77DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect77DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect77DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect77DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect70DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect70DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect70DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect70DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect39DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect39SixSlotTrail_Seed(void);
void BattleAnim_StartEffect39CombinedTrail_Init(void);
s32 BattleAnim_StartEffect39CombinedTrail_Update(void);
void BattleAnim_StartEffect39CombinedTrail_Draw(void);

void BattleAnim_EffectSecondaryOwnerAnchorPosition(Vec3f* arg0);
f32 BattleAnim_EffectSecondaryOwnerModelScale(void);
void BattleAnim_CalcVectorAtToDm(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5);
void BattleAnim_ResetSharedEffectMatrix(void);
void BattleAnim_StartEffect98Radial20_EmitVariantD(void);
void BattleAnim_StartEffect78Radial20_EmitVariantA(void);

void BattleAnim_StartEffect98Radial20_Init(void) {
    D_8219CB16 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_ResetPool();
    BattleAnim_StartEffect98Radial20_EmitVariantD();
}

s32 BattleAnim_StartEffect98Radial20_Update(void) {
    D_8219CB16++;
    if (D_8219CB16 >= 0xB5) {
        return -1;
    }

    if ((D_8219CB16 < 0x78) && ((D_8219CB16 % 7) == 0)) {
        BattleAnim_StartEffect98Radial20_EmitVariantD();
    }

    return Radial20_IsComplete();
}

void BattleAnim_StartEffect98Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Radial20_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect11Trail50Alt_Init(void) {
    D_8219CB18 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Trail50EffectAlt_Init();
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
s32 BattleAnim_StartEffect11Trail50Alt_Update(void) {
    UNUSED s32 pad[1];
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    UNUSED s32 pad2[2];
    f32 var_fv0;
    f32 sp44;

    D_8219CB18++;
    if (!(D_8219CB18 & 1)) {
        sp44 = BattleAnim_EffectSecondaryOwnerModelScale();
        BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp60);
        sp5C = (((guRandom() % 50) - 0x19) * sp44) + sp60.x;
        sp58 = (((guRandom() % 60) - 0x1E) * sp44) + sp60.y;
        sp54 = (((guRandom() % 50) - 0x19) * sp44) + sp60.z;
        var_fv0 = 10.0f;
        if (sp5C > 0.0) {
            var_fv0 = -var_fv0;
        }
        Trail50EffectAlt_Start(sp5C, sp58, sp54, var_fv0, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0x64, 0.3f, 1.0f, 4.0f, 0x1E);
    }
    Trail50EffectAlt_IsComplete();
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216EDB4.s")
#endif

void BattleAnim_StartEffect11Trail50Alt_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail50EffectAlt_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect57Trail50_Init(void) {
    D_8219CB1A = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Trail50Effect_Init();
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
s32 BattleAnim_StartEffect57Trail50_Update(void) {
    UNUSED s32 pad[1];
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    UNUSED s32 pad2[2];
    f32 var_fv0;
    f32 sp44;

    D_8219CB1A++;
    if (!(D_8219CB1A & 1)) {
        sp44 = BattleAnim_EffectSecondaryOwnerModelScale();
        BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp60);
        sp5C = (((guRandom() % 50) - 0x19) * sp44) + sp60.x;
        sp58 = (((guRandom() % 60) - 0x1E) * sp44) + sp60.y;
        sp54 = (((guRandom() % 50) - 0x19) * sp44) + sp60.z;
        var_fv0 = 10.0f;
        if (sp5C > 0.0) {
            var_fv0 = -var_fv0;
        }
        Trail50Effect_Start(sp5C, sp58, sp54, var_fv0, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0x64, 0.3f, 1.0f, 4.0f, 0x1E);
    }
    Trail50Effect_IsComplete();
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216EFB4.s")
#endif

void BattleAnim_StartEffect57Trail50_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail50Effect_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect42Trail40_Init(void) {
    Vec3f sp1C;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    Trail40_Init(0x708);
}

s32 BattleAnim_StartEffect42Trail40_Update(void) {
    return Trail40_IsComplete();
}

void BattleAnim_StartEffect42Trail40_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail40_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect43Trail40Variant_Init(void) {
    Vec3f sp1C;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    Trail40Variant_InitPool(0x708);
}

s32 BattleAnim_StartEffect43Trail40Variant_Update(void) {
    return Trail40Variant_AdvanceTimer();
}

void BattleAnim_StartEffect43Trail40Variant_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail40Variant_BuildGfx(gDisplayListHead);
}

void BattleAnim_StartEffect44Trail40GridAlt_Init(void) {
    Vec3f sp1C;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    Trail40GridAlt_Init(0x708);
}

s32 BattleAnim_StartEffect44Trail40GridAlt_Update(void) {
    return Trail40GridAlt_IsComplete();
}

void BattleAnim_StartEffect44Trail40GridAlt_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail40GridAlt_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect45FourStreamTrail_Init(void) {
    D_8219CAC0 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    FourStreamTrail_Init();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216F3A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216F3A0.s")
#endif

void BattleAnim_StartEffect45FourStreamTrail_Draw(void) {
    if (D_8219CAC0 >= 2) {
        gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDisplayListHead = FourStreamTrail_Draw(gDisplayListHead);
    }
}

void BattleAnim_StartEffect62OwnerLinkedFourStream_Init(void) {
    D_8219CAC2 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    OwnerLinkedFourStream_Init();
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
s32 BattleAnim_StartEffect62OwnerLinkedFourStream_Update(void) {
    s32 var_v1;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;

    D_8219CAC2++;
    if (((D_8219CAC2 >> 2) < 4) && !(D_8219CAC2 & 3)) {
        BattleAnim_CalcVectorAtToDm(&sp60, &sp5C, &sp58, &sp54, &sp50, &sp4C);
        sp48 = ((2 - (((D_8219CAC2 >> 2) + 2) % 3)) * 0.5235988f) + 0.34906587f;
        sp54 *= 7.0f * __cosf(sp48);
        sp50 = __sinf(sp48) * 10.0f;
        sp4C = 0.0f;
        OwnerLinkedFourStream_Start(sp60, sp5C, sp58, sp54, sp50, 0.0f, 0xD0, 0xFF, 0xFF, 0x80, 0.8f, 2.0f, 4.0f, 0x28);
    }

    if (D_8219CAC2 >= 2) {
        var_v1 = OwnerLinkedFourStream_IsComplete();
    } else {
        var_v1 = 0;
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216F674.s")
#endif

void BattleAnim_StartEffect62OwnerLinkedFourStream_Draw(void) {
    if (D_8219CAC2 >= 2) {
        gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDisplayListHead = OwnerLinkedFourStream_Draw(gDisplayListHead);
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_StartEffect67OwnerAnchoredFourStream_Init(void) {
    Vec3f sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    D_8219CB08 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    OwnerAnchoredFourStream_Init();
    BattleAnim_CalcVectorAtToDm(&sp58, &sp54, &sp50, &sp4C, &sp48, &sp44);
    sp4C *= 5.0;
    sp48 *= 5.0;
    sp44 *= 5.0;
    OwnerAnchoredFourStream_Start(sp58, sp54, sp50, sp4C, sp48, sp44, 0xC0, 0xFF, 0xFF, 0xA0, 0.6f, 2.0f, 4.0f, 0x28);
    sp5C.x = sp58;
    sp5C.y = sp54;
    sp5C.z = sp50;
    BattleAnim_SpawnSecondaryOwnerParticle(sp5C, 1);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216F860.s")
#endif

s32 BattleAnim_StartEffect67OwnerAnchoredFourStream_Update(void) {
    D_8219CB08++;
    if (D_8219CB08 >= 0x32) {
        return -1;
    }

    return OwnerAnchoredFourStream_IsComplete();
}

void BattleAnim_StartEffect67OwnerAnchoredFourStream_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = OwnerAnchoredFourStream_Draw(gDisplayListHead);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216FA40; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216FA40.s")
#endif

void BattleAnim_StartEffect78Radial20_Init(void) {
    D_8219CB0A = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_ResetPool();
    BattleAnim_StartEffect78Radial20_EmitVariantA();
}

s32 BattleAnim_StartEffect78Radial20_Update(void) {
    D_8219CB0A++;
    if (D_8219CB0A >= 0xB5) {
        return -1;
    }
    return Radial20_IsComplete();
}

void BattleAnim_StartEffect78Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Radial20_Draw(gDisplayListHead);
}

#ifdef NON_MATCHING
// Matches the ROM, but uses data/rodata data that is not placed in this file yet.
void BattleAnim_StartEffect26DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84387FC0 = { 2, 1, 0xE, 1, 2, 2, 3, 1 };
    static unk_D_843C2C00_024 D_84387FE0 = { 3, 5, 0, 5, 3, 7, 0, 5 };
    static unk_D_843C2C00_024 D_84388000 = { 2, 1, 0xE, 1, 2, 1, 3, 1 };
    static unk_D_843C2C00_024 D_84388020 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x8F, 0x8F, 6, 0xA, 0xF, 0xE,
                  -3, 5, 0, 0xF, &D_84387FC0, &D_84387FE0, 0xFF, 0xFF, 0, 0x96, 0x64, 0xFF, 0, 0xC8, 0x32, 0xFF, 0x96,
                  0xFF, 0x78);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x8F, 0x90, 2, 6, 0, 0xF, -4,
                  2, 0, 0, &D_84388000, &D_84388020, 0, 0xFF, 0x64, 0x96, 0x64, 0x64, 0, 0xFF, 0xC8, 0, 0, 0, 0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216FBEC.s")
#endif

void BattleAnim_StartEffect26DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect26DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect26DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect26DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

#ifdef NON_MATCHING
// Matches the ROM, but uses data/rodata data that is not placed in this file yet.
void BattleAnim_StartEffect47SixSlotTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388040 = { 3, 5, 1, 5, 1, 7, 3, 7 };
    static unk_D_843C2C00_024 D_84388060 = { 0x1F, 0x1F, 0x1F, 0, 7, 7, 7, 0 };

    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;

    BattleAnim_CalcVectorAtToDm(&spA4, &spA0, &sp9C, &sp98, &sp94, &sp90);
    sp94 += 0.2f * __cosf((RAND(10) * M_PI_F) / 10.0f);
    sp90 += 0.2f * __cosf((RAND(10) * M_PI_F) / 10.0f);

    sp98 *= 12.0f;
    sp94 *= 12.0f;
    sp90 *= 12.0f;

    BattleAnim_SixSlotTrail_Spawn(0, spA4, spA0, sp9C, sp98, sp94, sp90, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0x64, 0xFF, 0xFF, 0.4f, 2.0f,
                  20.0f, 0x3C, 0x95, 0x95, 0, 0xA, 0, 0xD, 0, 0, 0, 0, &D_84388040, &D_84388060);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216FF24.s")
#endif

void BattleAnim_StartEffect47SixSlotTrail_Init(void) {
    D_8219CB0C = 0;
    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_SixSlotTrail_ResetPool();
    BattleAnim_StartEffect47SixSlotTrail_Seed();
}

s32 BattleAnim_StartEffect47SixSlotTrail_Update(void) {
    D_8219CB0C++;
    if ((D_8219CB0C % 10) == 0) {
        BattleAnim_StartEffect47SixSlotTrail_Seed();
    }
    return BattleAnim_SixSlotTrail_UpdateAll();
}

void BattleAnim_StartEffect47SixSlotTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = BattleAnim_SixSlotTrail_DrawAll(gDisplayListHead);
}

#ifdef NON_MATCHING
// Matches the ROM, but uses data/rodata data that is not placed in this file yet.
void BattleAnim_StartEffect4DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388080 = { 3, 5, 1, 5, 6, 7, 2, 3 };
    static unk_D_843C2C00_024 D_843880A0 = { 0x1F, 0x1F, 0x1F, 0, 0, 7, 5, 7 };
    static unk_D_843C2C00_024 D_843880C0 = { 3, 5, 2, 5, 1, 7, 3, 7 };
    static unk_D_843C2C00_024 D_843880E0 = { 0x1F, 0x1F, 0x1F, 0, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x93, 0x93, 5, 0xA, 0xF, 0xF,
                  -5, 5, 0xF, 0xF, &D_84388080, &D_843880A0, 0xC8, 0xC8, 0, 0x64, 0, 0, 0xC8, 0, 0xFF, 0, 0xFF, 0,
                  0x5A);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x91, 0x91, -2, 0xA, 0xF,
                  0xF, 5, 0xF, 0xF, 0xF, &D_843880C0, &D_843880E0, 0xFF, 0x32, 0x64, 0xC8, 0, 0x64, 0x32, 0xFF, 0xFF, 0,
                  0, 0, 0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821701D8.s")
#endif

void BattleAnim_StartEffect4DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect4DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect4DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect4DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

#ifdef NON_MATCHING
// Matches the ROM, but uses data/rodata data that is not placed in this file yet.
void BattleAnim_StartEffect77DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388100 = { 2, 1, 0xE, 1, 2, 7, 1, 3 };
    static unk_D_843C2C00_024 D_84388120 = { 3, 5, 0, 5, 0, 7, 5, 7 };
    static unk_D_843C2C00_024 D_84388140 = { 2, 1, 0xE, 1, 2, 7, 1, 3 };
    static unk_D_843C2C00_024 D_84388160 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x97, 0x98, -5, 0x14, 0xF,
                  0xD, -5, 0x14, 0, 0xE, &D_84388100, &D_84388120, 0xFF, 0xFF, 0xFF, 0x32, 0x64, 0x64, 0, 0xFF, 0xFF,
                  0xC8, 0xFF, 0xFF, 0x96);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x98, 5, 0xF, 0xF, 0xE,
                  0, 0xF, 0xF, 0xF, &D_84388140, &D_84388160, 0xFF, 0xFF, 0xFF, 0x32, 0x64, 0x64, 0x64, 0xFF, 0xFF, 0,
                  0, 0, 0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82170514.s")
#endif

void BattleAnim_StartEffect77DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect77DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect77DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect77DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

#ifdef NON_MATCHING
// Matches the ROM, but uses data/rodata data that is not placed in this file yet.
void BattleAnim_StartEffect70DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388180 = { 2, 1, 0xE, 1, 2, 1, 3, 1 };
    static unk_D_843C2C00_024 D_843881A0 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x94, 0, 0x14, 0xE,
                  0xF, 0, 0x14, 0xF, 0xE, &D_84388180, &D_843881A0, 0xFF, 0xFF, 0xFF, 0x96, 0x96, 0xFF, 0xFF, 0, 0xFF,
                  0xFF, 0xFF, 0, 0x96);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8217085C.s")
#endif

void BattleAnim_StartEffect70DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect70DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect70DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect70DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

#ifdef NON_MATCHING
// Matches the ROM, but uses data/rodata data that is not placed in this file yet.
void BattleAnim_StartEffect39DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_843881C0 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000007, 0x00000007, 0x00000007, 0x00000003,
    };
    static unk_D_843C2C00_024 D_843881E0 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000007, 0x00000007, 0x00000007, 0x00000000,
    };
    static unk_D_843C2C00_024 D_84388200 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000001,
    };
    static unk_D_843C2C00_024 D_84388220 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000000, 0x00000007, 0x00000005, 0x00000007,
    };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 12.0f;
    spA4 *= 12.0f;
    spA0 *= 12.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x91, 0x92, 5, 0x1E, 0, 0xD,
                  -5, 0x1E, 0xF, 0xD, &D_843881C0, &D_843881E0, 0xFF, 0xFF, 0, 0xFF, 0x96, 0x32, 0, 0, 0xFF, 0xFF, 0xC8,
                  0x64, 0xC8);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x96, 6, 0x14, 0xE,
                  0xF, -3, 0xA, 0, 0xF, &D_84388200, &D_84388220, 0xFF, 0xFF, 0x64, 0x96, 0xFF, 0xFF, 0x64, 0, 0xC8, 0,
                  0, 0, 0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82170A84.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses data/rodata data that is not placed in this file yet.
void BattleAnim_StartEffect39SixSlotTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388240 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000001,
    };
    static unk_D_843C2C00_024 D_84388260 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000000, 0x00000007, 0x00000005, 0x00000007,
    };

    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;

    BattleAnim_CalcVectorAtToDm(&spA4, &spA0, &sp9C, &sp98, &sp94, &sp90);

    sp94 += (0.4f * __cosf((RAND(10) * M_PI_F) / 10));
    sp90 += (0.4f * __cosf((RAND(10) * M_PI_F) / 10));

    sp98 *= 12.0f;
    sp94 *= 12.0f;
    sp90 *= 12.0f;

    BattleAnim_SixSlotTrail_Spawn(0, spA4, spA0, sp9C, sp98, sp94, sp90, 0xFF, 0xFF, 0x64, 0x32, 0xC8, 0xFF, 0x32, 0, 0xFF, 0.4f, 2.0f,
                  5.0f, 0x3C, 0x95, 0x95, 0, 0x14, 0, 0xD, 0, 0x19, 0, 0xD, &D_84388240, &D_84388260);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82170D28.s")
#endif

void BattleAnim_StartEffect39CombinedTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect39DoubleTextureTrail_Seed();
    BattleAnim_SixSlotTrail_ResetPool();
    BattleAnim_StartEffect39SixSlotTrail_Seed();
}

s32 BattleAnim_StartEffect39CombinedTrail_Update(void) {
    D_8219CB14++;
    if ((D_8219CB14 % 10) == 0) {
        BattleAnim_StartEffect39SixSlotTrail_Seed();
    }
    BattleAnim_SixSlotTrail_UpdateAll();
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect39CombinedTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
    gDisplayListHead = BattleAnim_SixSlotTrail_DrawAll(gDisplayListHead);
}
