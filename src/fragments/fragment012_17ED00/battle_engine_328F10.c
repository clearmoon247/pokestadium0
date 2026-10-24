/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_328F10.c, src/gallery.c. */

#include "fragments/battle_engine/battle_engine.h"

#include "gallery.h"
#include "fragments/gallery_camera/gallery_camera.h"
#include "fragments/particle_data_library/particle_data_library.h"
#include "fragments/particle_math/particle_math.h"
#include "geo_node.h"
#include "geo_render.h"
#include "model_animation.h"
#include "model_animation_events.h"
#include "geo_layout.h"
#include "display_object_textures.h"
#include "model_renderer.h"
#include "graphics_textures.h"
#include "game_state.h"
#include "jpeg_stream.h"
#include "audio_sfx_wrapper.h"
#include "audio_loop_point.h"
#include "memory.h"
#include "util.h"
typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;

    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
} unk_D_800761B0;
typedef struct unk_func_8003013C_arg1 {
    /* 0x00 */ u8 pad00[0x1C];
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
} unk_func_8003013C_arg1;
typedef struct unk_func_80031660_sp24 {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 unk_18;
} unk_func_80031660_sp24;
s32 Gallery_ConfigurePhotoCamera();
s32 Gallery_SetScenePoseCamera();
s32 Gallery_SetCameraAngleOffsets();
s32 Gallery_SetCameraAngleOffsetsAlternate();
s32 Gallery_SetSceneModelNode();
s32 Gallery_SetSceneRenderState();
s32 Gallery_SetSceneGraphNode();
s32 func_800303C8();
void Gallery_ClearActiveScene(void);
void func_82183DA4(void);
typedef union unk_func_80026268_arg0_000_raw {
    struct {
        u8 unk_00;
        u8 unk_01;
        u16 unk_02;
    };
    f32 raw;
} unk_func_80026268_arg0_000_raw;
typedef struct unk_func_80026268_arg0_raw {
    /* 0x00 */ unk_func_80026268_arg0_000_raw unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09[4];
    /* 0x0D */ u8 pad0D;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u16 unk_1E;
    /* 0x20 */ u8 unk_20[4];
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ u8 unk_30[11];
    /* 0x3B */ u8 unk_3B[11];
    /* 0x46 */ u8 unk_46[11];
    /* 0x51 */ char unk51[0x1];
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
} unk_func_80026268_arg0_raw;
typedef struct unk_D_83403C60_raw {
    /* 0x00 */ unk_func_80026268_arg0_raw unk_00;
    /* 0x54 */ char unk54[0x18];
    /* 0x6C */ u8 unk_6C;
    /* 0x6D */ char unk6D[0x3];
    /* 0x70 */ unk_D_83407AC8 unk_70;
    /* 0x8A */ char unk8A[0x2];
} unk_D_83403C60_raw;

#include "m2c_macros.h"

void BattleAnim_InitStartEffect139Descriptor42FallingScale(Particle* arg0);
void BattleAnim_InitStartEffect139Descriptor22SpinFade(Particle* arg0);
void BattleAnim_InitStartEffects133And134And143Descriptor44ModeOrbit(Particle* arg0);
void BattleAnim_InitStartEffects133And134And143Descriptor38MetadataBurst(Particle* arg0);
void Gallery_ResetActiveScene(void);
void func_82150EB0(void);
void BattleAnim_StartEffect122GlobalAndOwnerTintFade(void);

void Gallery_ClearActiveScene(void);

#ifdef NON_MATCHING
/* TODO: decompile func_8214FFD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214FFD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821500CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821500CC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821501B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821501B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82150210; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82150210.s")
#endif

void BattleAnim_InitStartEffect139Descriptor42FallingScale(Particle* arg0) {
    s16 sp2E = Particle_FieldCF_GetS16_0C058(arg0);
    s16 sp2C = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.05f);
    Particle_SetRotation(arg0, ParticleMath_RandomRange(0x10000), ParticleMath_RandomRange(0x10000), 0);
    Particle_Field74_SetScaled_0AD8C(arg0, 1.2f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp2E);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2C * 1);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215036C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215036C.s")
#endif

void BattleAnim_InitStartEffect139Descriptor22SpinFade(Particle* arg0) {
    UNUSED s16 pad;
    s16 sp2C;

    Particle_FieldAC_GetS16_0C038(arg0);
    sp2C = Particle_FieldCF_GetS16_0C058(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.175f);
    Particle_SetRotation(arg0, ParticleMath_RandomRange(0x10000), ParticleMath_RandomRange(0x10000), 0);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp2C);
    Particle_SetPrimAlpha(arg0, 0x80);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_8213E528(s8 *);                      /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821406B4(s8 *);                      /* extern */
M2C_UNK func_82150474(s8 *);                      /* extern */

void func_82150504(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82150474(arg0);
        return;
    case 2:
        func_82140228(arg0, 0x3DCCCCCD, 0x3C23D70A);
        func_82140518(arg0, 0, 8);
        func_8213E528(arg0);
        func_821406B4(arg0);
        return;
    case 3:
        func_8213C938(arg0);
        return;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821505A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821505A8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821506A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821506A4.s")
#endif

void BattleAnim_InitStartEffects133And134And143Descriptor44ModeOrbit(Particle* arg0) {
    s16 sp36;
    s16 sp34;
    s16 sp32 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp30 = Particle_FieldCF_GetS16_0C058(arg0);
    s16 sp2E = Particle_FieldCE_GetS32_0C040(arg0);

    Particle_SetRotation(arg0, ParticleMath_RandomRange(0x10000), ParticleMath_RandomRange(0x10000), 0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.01f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp30);

    switch (sp2E) {
        case 0:
            Particle_FieldAE_SetS16_0BF4C(arg0, ParticleMath_RandomRangeOffset(0x14, 0x14));
            Particle_FieldB0_SetS16_0BFEC(arg0, 0);
            sp36 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            sp34 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            Particle_FieldA8_SetS16_0BE14(arg0, 8);
            break;

        case 1:
            Particle_FieldAE_SetS16_0BF4C(arg0, ParticleMath_RandomRangeOffset(0x28, 0x14));
            Particle_FieldB0_SetS16_0BFEC(arg0, 1);
            sp36 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            sp34 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            Particle_FieldA8_SetS16_0BE14(arg0, 0x10);
            break;

        case 2:
            Particle_FieldAE_SetS16_0BF4C(arg0, ParticleMath_RandomRangeOffset(0x1E, 0x14));
            Particle_FieldB0_SetS16_0BFEC(arg0, 2);
            sp36 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            sp34 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            Particle_FieldA8_SetS16_0BE14(arg0, 0xA);
            break;

        case 3:
            Particle_FieldAE_SetS16_0BF4C(arg0, 0x1E - sp32);
            Particle_FieldB0_SetS16_0BFEC(arg0, 2);
            sp36 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            sp34 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            Particle_FieldA8_SetS16_0BE14(arg0, 0xA);
            break;
    }

    Particle_Field9A_SetX_0A3C4(arg0, sp36);
    Particle_Field9A_SetY_0A3D8(arg0, sp34);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp32 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_821509D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821509D4.s")
#endif

void BattleAnim_InitStartEffects133And134And143Descriptor38MetadataBurst(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    Particle_Field38_AddYScaled_08E90(arg0, 5.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp26);
    Particle_SetPrimAlpha(arg0, 0x40);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82150BD8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82150BD8.s")
#endif

M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E698;
extern M2C_UNK D_8218E798;
extern M2C_UNK func_8215036C;

void func_82150D1C(void) {
    func_8213B5D8(0, 1, 0x1E, &func_82150504, &D_8218E698, 0x10, 1, 0x1E, 0, 0x3B, 0);
    func_8213B5D8(0, 1, 0x1E, &func_8215036C, &D_8218E798, 0x10, 2, 0x1E, 0, 0x3B, 0);
}

void Gallery_ResetActiveScene(void) {
    Gallery_ClearActiveScene();
}

#ifdef NON_MATCHING
/* TODO: decompile func_82150DEC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82150DEC.s")
#endif

void func_82150EB0(void) {
    func_82150DEC();
}

#ifdef NON_MATCHING
/* TODO: decompile func_82150ED0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82150ED0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82151054; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82151054.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82151270; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82151270.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821513F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821513F4.s")
#endif

void BattleAnim_StartEffect122GlobalAndOwnerTintFade(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0xFF, 0);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x14, 0, 0, 0xFF, 0x10);
}
