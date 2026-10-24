/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_317E70.c, src/fragments/particle_math/particle_math_269820.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "geo_render.h"
#include "model_renderer.h"
#include "matrix.h"
#include "fragments/particle_math/particle_math.h"
#include "memory.h"

#include "fragments/particle_math/particle_math.h"
#include "geo_render.h"
extern ParticleDescriptor gDefaultParticleDescriptor;

#include "m2c_macros.h"

void BattleAnim_FreeEffectSlot(BattleAnimEffectSlot* arg0);
Particle* Particle_New(void);
Particle* Particle_AllocChain(u8 arg0);
void BattleAnim_EmitParticleBurst(Particle* arg0, ParticleUpdateCallback arg1, ParticleDescriptor* arg2, s16 arg3);
void BattleAnim_UpdateOrDestroyParticle(Particle* arg0);
void BattleAnim_SpawnSingleParticle(BattleAnimEffectSlot* arg0);
void BattleAnim_DispatchParticleEmission(BattleAnimEffectSlot* arg0);
void BattleAnim_TickEffectSlots(void);
s32 Particle_CountActiveAlias(void);
void BattleAnim_ReleaseParticleModel(Particle* arg0);
s32 BattleAnim_IsEffectSpawningEnabled(void);
void BattleAnim_EnableEffectSpawning(void);

void BattleAnim_CloneParticleState(Particle* arg0, Particle* arg1, ParticleUpdateCallback arg2, ParticleDescriptor* arg3,
                   s32 arg4);
Particle* BattleAnim_CreateProceduralParticle(s16 arg0, s16 arg1, s32 arg2, f32 arg3);
void BattleAnim_DestroyParticle(Particle* arg0);
void BattleAnim_InitializeParticleFromEffect(Particle* arg0, ActivePokemon* arg1, BattleAnimEffectSlot* arg2, s16 arg3);
void BattleAnim_SpawnStandardParticles(BattleAnimEffectSlot* arg0);
void BattleAnim_SpawnBatchedParticles(BattleAnimEffectSlot* arg0);
void BattleAnim_SetEffectStateFlag(s32 arg0);
Particle* Particle_Alloc(void);
s32 Particle_CountActive(void);
s32 Particle_IsInactive(Particle* arg0);
s32 Particle_HasFlags(Particle* arg0, s32 arg1);
void Particle_UpdateWorldTransform(Particle* arg0);

s32 func_800023C4(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8004FD20(s32, M2C_UNK);                /* extern */
extern s32 D_8219CA50;
extern s32 D_8219CA54;
extern s32 D_8219CA58;
extern s32 D_8219CA5C;

void func_821398A0(void) {
    D_8219CA54 = func_800023C4(0x20D0, 0);
    D_8219CA50 = func_800023C4(0xF3C0, 0);
    func_8004FD20(D_8219CA54, 0x20D0);
    func_8004FD20(D_8219CA50, 0xF3C0);
    D_8219CA5C = 0;
    D_8219CA58 = 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213990C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213990C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82139A88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82139A88.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82139B54; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82139B54.s")
#endif

void func_82139BE8(s8 *arg0) {
    s8 **temp_v0;
    s8 *temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s8 ***, 4);
    if (temp_v0 != NULL) {
        *temp_v0 = M2C_FIELD(arg0, s8 **, 0);
    }
    temp_v0_2 = M2C_FIELD(arg0, s8 **, 0);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, s8 ***, 4) = (s8 **) M2C_FIELD(arg0, s8 ***, 4);
    }
    M2C_FIELD(arg0, s8 ***, 4) = NULL;
    M2C_FIELD(arg0, s8 **, 0) = NULL;
    M2C_FIELD(arg0, s8 *, 0xCC) = 0;
}

void BattleAnim_FreeEffectSlot(BattleAnimEffectSlot* arg0) {
    arg0->unk_0E = 0;
    arg0->unk_15 = 0;
    arg0->unk_14 = 0;
    arg0->unk_0C = arg0->unk_0E;
}

Particle* Particle_New(void) {
    return Particle_Alloc();
}

Particle* Particle_AllocChain(u8 arg0) {
    s32 i;
    Particle* sp28;
    Particle* temp_v0;
    Particle* var_s0;

    sp28 = Particle_Alloc();

    if ((u32)sp28 != -1) {
        var_s0 = sp28;
        arg0--;

        for (i = 0; i < arg0; i++) {
            temp_v0 = Particle_Alloc();
            if ((u32)temp_v0 == -1) {
                break;
            }
            var_s0->next = temp_v0;
            temp_v0->prev = var_s0;
            var_s0 = temp_v0;
        }
    }

    return sp28;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82139CE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82139CE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82139D84; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82139D84.s")
#endif

void BattleAnim_EmitParticleBurst(Particle* arg0, ParticleUpdateCallback arg1, ParticleDescriptor* arg2, s16 arg3) {
    s16 i;
    Particle* temp_v0;

    for (i = 0; i < arg3; i++) {
        temp_v0 = Particle_New();
        if ((u32)temp_v0 == -1) {
            break;
        }
        BattleAnim_CloneParticleState(temp_v0, arg0, arg1, arg2, i);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82139F00; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82139F00.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82139FD4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82139FD4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213A07C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213A07C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213A3B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213A3B4.s")
#endif

void BattleAnim_UpdateOrDestroyParticle(Particle* arg0) {
    if (Particle_IsInactive(arg0) != 0) {
        BattleAnim_DestroyParticle(arg0);
    } else {
        Particle_UpdateWorldTransform(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213A68C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213A68C.s")
#endif

M2C_UNK func_8213A904(s8 *);                      /* extern */
M2C_UNK func_8213A9C4(s8 *, s32);                 /* extern */
s32 func_8213CAFC(s8 *, M2C_UNK);                 /* extern */
s32 func_8213CB1C(s8 *, M2C_UNK);                 /* extern */

void func_8213A784(s32 arg0) {
    s32 var_s3;
    s8 *var_s0;
    s8 *var_s2;

    var_s2 = D_8219CA50;
    var_s3 = 0;
    do {
        if ((M2C_FIELD(var_s2, s8 *, 0xCC) != 0) && (M2C_FIELD(var_s2, s32 *, 4) == 0) && (func_8213CB1C(var_s2, 8) != 0)) {
            func_8213A904(var_s2);
            var_s0 = var_s2;
            if (var_s2 != NULL) {
                do {
                    if ((func_8213CAFC(var_s0, 4) != 0) && (M2C_FIELD(var_s0, s16 *, 0xAE) >= 2)) {
                        func_8213A9C4(var_s0, arg0);
                    }
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0);
                } while (var_s0 != NULL);
            }
        }
        var_s3 += 1;
        var_s2 += 0xD0;
    } while (var_s3 != 0x12C);
}

M2C_UNK func_8213A904(s8 *);                      /* extern */
M2C_UNK func_8213A9C4(s8 *, s32);                 /* extern */
s32 func_8213CAFC(s8 *, M2C_UNK);                 /* extern */

void func_8213A858(s32 arg0) {
    s32 var_s1;
    s8 *var_s0;

    var_s0 = D_8219CA50;
    var_s1 = 0;
    do {
        if ((M2C_FIELD(var_s0, s8 *, 0xCC) != 0) && (func_8213CAFC(var_s0, 8) != 0)) {
            func_8213A904(var_s0);
            if ((func_8213CAFC(var_s0, 4) != 0) && (M2C_FIELD(var_s0, s16 *, 0xAE) >= 2)) {
                func_8213A9C4(var_s0, arg0);
            }
        }
        var_s1 += 1;
        var_s0 += 0xD0;
    } while (var_s1 != 0x12C);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213A904; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213A904.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213A9C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213A9C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213AA78; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213AA78.s")
#endif

s32 func_82139C38();                                /* extern */
s32 func_82139C58(s32);                             /* extern */
M2C_UNK func_8213AA78(s32, s32, s8 *, s16);       /* extern */

void func_8213AB88(s8 *arg0) {
    s16 temp_s2;
    s16 var_s0;
    s32 temp_s3;

    temp_s3 = M2C_FIELD(arg0, s32 *, 8);
    temp_s2 = M2C_FIELD(arg0, s16 *, 0x12);
    if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), s16 *, 2) == 0) {
        var_s0 = 0;
        if (temp_s2 > 0) {
            do {
                func_8213AA78(func_82139C38(), temp_s3, arg0, var_s0);
                var_s0 += 1;
            } while (var_s0 < temp_s2);
        }
    } else {
        func_8213AA78(func_82139C58(temp_s2 & 0xFF), temp_s3, arg0, 0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213AC3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213AC3C.s")
#endif

void BattleAnim_SpawnSingleParticle(BattleAnimEffectSlot* arg0) {
    UNUSED s32 pad;
    ActivePokemon* sp18 = arg0->unk_08;

    BattleAnim_InitializeParticleFromEffect(Particle_New(), sp18, arg0, 0);
}

void BattleAnim_DispatchParticleEmission(BattleAnimEffectSlot* arg0) {
    switch (arg0->unk_16) {
        case 18:
            BattleAnim_SpawnBatchedParticles(arg0);
            break;

        case 22:
            BattleAnim_InitializeParticleFromEffect(BattleAnim_CreateProceduralParticle(0xA0, 0x78, 0, 1.0f), 0, arg0, 0);
            break;

        case 24:
            BattleAnim_InitializeParticleFromEffect(BattleAnim_CreateProceduralParticle(0, 0, 0, 1.0f), 0, arg0, 0);
            break;

        case 23:
            BattleAnim_SetEffectStateFlag(arg0->unk_19);
            break;

        case 25:
            BattleAnim_QueueEffectList9(arg0->unk_19);
            break;

        case 26:
            BattleAnim_SpawnSingleParticle(arg0);
            break;

        default:
            BattleAnim_SpawnStandardParticles(arg0);
            break;
    }
}

void BattleAnim_TickEffectSlots(void) {
    s32 i;
    BattleAnimEffectSlot* var_s0 = gBattleAnimEffectSlots;

    for (i = 0; i < 300; i++, var_s0++) {
        if (var_s0->unk_15 != 0) {
            var_s0->unk_0E--;
            if (var_s0->unk_0E <= 0) {
                if (var_s0->unk_14 >= 0) {
                    BattleAnim_DispatchParticleEmission(var_s0);
                    if (var_s0->unk_14 != 0x7F) {
                        var_s0->unk_14--;
                    }

                    if (var_s0->unk_14 <= 0) {
                        BattleAnim_FreeEffectSlot(var_s0);
                    } else {
                        var_s0->unk_0E = var_s0->unk_0C;
                    }
                } else if (var_s0->unk_14 == -1) {
                    var_s0->unk_0E = var_s0->unk_0C;
                    BattleAnim_DispatchParticleEmission(var_s0);
                }
            }
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213AF50; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213AF50.s")
#endif

s32 Particle_CountActiveAlias(void) {
    return Particle_CountActive();
}

void BattleAnim_ReleaseParticleModel(Particle* arg0) {
    if (arg0->unk_14 != NULL) {
        if (Particle_HasFlags(arg0, 0x400) != 0) {
            BattleAnim_FreeParticleDisplayContext(arg0->unk_14);
        } else {
            BattleAnim_FreeOwnerDisplayContext(arg0->unk_14);
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213B038; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213B038.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213B108; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213B108.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213B234; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213B234.s")
#endif

s32 BattleAnim_IsEffectSpawningEnabled(void) {
    s32 var_v1 = 0;

    if (D_8219A830 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

extern s32 D_8219A830;

void func_8213B2E0(void) {
    D_8219A830 = 1;
}

void BattleAnim_EnableEffectSpawning(void) {
    D_8219A830 = 0;
}
