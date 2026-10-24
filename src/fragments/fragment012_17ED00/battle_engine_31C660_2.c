/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_31C660.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "model_renderer.h"

#include "m2c_macros.h"

void BattleAnim_SetupOwnerModelTintPaletteFade(Particle* arg0);
void BattleAnim_SetupParticleRecolorTransparent(Particle* arg0);
void BattleAnim_SetupDescriptor25AlphaFadeInHoldOut(Particle* arg0);
void BattleAnim_SetupDescriptor25AlphaFadeInHold(Particle* arg0);
void BattleAnim_SetupDescriptor25PaletteFadeOut(Particle* arg0);
void BattleAnim_SetupDescriptor25PaletteFadeIn(Particle* arg0);

void BattleAnim_SetupOwnerModelTintPaletteFade(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_FieldAE_SetS16_0BF4C(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_80019B28(s32, u8, u8, u8, s32);        /* extern */
M2C_UNK func_8213C930(s8 *);                      /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
s32 func_8214083C(s8 *, s16, u8);                 /* extern */
s32 func_821436A0(s8 *, u8, u8);                  /* extern */
M2C_UNK func_82144130(s8 *);                      /* extern */

void func_82144170(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82144130(arg0);
        break;
    case 2:
        if (func_8214083C(arg0, M2C_FIELD(arg0, s16 *, 0xA2), M2C_FIELD(arg0, u8 *, 0xCA)) != 0) {
            func_8213C9D0(arg0);
        }
        break;
    case 3:
        if (func_821436A0(arg0, M2C_FIELD(arg0, u8 *, 0xC9), M2C_FIELD(arg0, u8 *, 0xA7)) != 0) {
            func_8213C9D0(arg0);
        }
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        func_80019B28(M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, u8 *, 0xBA), M2C_FIELD(arg0, u8 *, 0xBB), M2C_FIELD(arg0, u8 *, 0xBC), (s32) M2C_FIELD(arg0, s16 *, 0xAA));
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82144258; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82144258.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82144324; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82144324.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82144414; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82144414.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821444D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821444D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82144644; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82144644.s")
#endif

M2C_UNK func_80019B6C(s32, u8);                     /* extern */
M2C_UNK func_8213C930(s8 *);                      /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
s32 func_82140518(s8 *, u8, u8);                  /* extern */
M2C_UNK func_82144644(s8 *);                      /* extern */

void func_82144668(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82144644(arg0);
        break;
    case 2:
        if (func_82140518(arg0, M2C_FIELD(arg0, u8 *, 0xC9), M2C_FIELD(arg0, u8 *, 0xA7)) != 0) {
            func_8213C9D0(arg0);
        }
        break;
    case 3:
        func_8213C930(arg0);
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        func_80019B6C(M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, u8 *, 0xC0));
    }
}

void BattleAnim_SetupParticleRecolorTransparent(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_80019B28(s32, u8, u8, u8, s32);        /* extern */
M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_82144710(s8 *);                      /* extern */

void func_82144750(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82144710(arg0);
        break;
    case 2:
        func_82140518(arg0, 0x80, 4);
        break;
    case 3:
        if (func_82140518(arg0, 0, 8) != 0) {
            func_8213C938(arg0);
        }
        break;
    }
    func_80019B28(M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, u8 *, 0xBA), M2C_FIELD(arg0, u8 *, 0xBB), M2C_FIELD(arg0, u8 *, 0xBC), (s32) M2C_FIELD(arg0, u8 *, 0xC0));
}

void BattleAnim_SetupDescriptor25AlphaFadeInHoldOut(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8214483C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214483C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821448D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821448D4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8214491C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214491C.s")
#endif

void BattleAnim_SetupDescriptor25AlphaFadeInHold(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_821449D8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821449D8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82144A54; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82144A54.s")
#endif

M2C_UNK func_8213C938(s8 *);                      /* extern */
s32 func_82140690();                                /* extern */
M2C_UNK func_82144A54();                            /* extern */

void func_82144A9C(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82144A54();
        return;
    case 2:
        if (func_82140690() != 0) {
            func_8213C938(arg0);
        }
        return;
    }
}

void BattleAnim_SetupDescriptor25PaletteFadeOut(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82144B3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82144B3C.s")
#endif

void BattleAnim_SetupDescriptor25PaletteFadeIn(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82144C0C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82144C0C.s")
#endif
