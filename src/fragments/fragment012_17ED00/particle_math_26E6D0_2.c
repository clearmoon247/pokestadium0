/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/particle_math/particle_math_26E6D0.c. */

#include "fragments/particle_math/particle_math.h"
extern u8 gParticlePalette[][3];
extern u8 gParticlePaletteSetA[];
extern u8 gParticlePaletteSetB[];
extern u8 gParticleRandomPaletteIndices[];
extern u8 gParticlePalettePairs[][2];

#include "m2c_macros.h"

void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4WrapST_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackIa8WrapST_64x64(UNUSED Particle* arg0, u8* texture);

void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameDiv2 & 7) * (64 * 64 / 2)], 64, 64);
}

M2C_UNK func_8216BFE8(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_82140EAC(s8 *arg0, s32 arg1) {
    func_8216BFE8((M2C_FIELD(arg0, s8 *, 0xC3) << 0xB) + arg1, 0x40, 0x40);
}

void ParticleGfx_LoadTextureCallbackI4WrapST_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4WrapST(texture, 64, 64);
}

void ParticleGfx_LoadTextureCallbackIa8WrapST_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureIa8WrapST(texture, 64, 64);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82140F38; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82140F38.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82140FAC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82140FAC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141038; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141038.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141128; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141128.s")
#endif

extern Vtx D_82190FC0[];

void ParticleGfx_DrawBillboardTextureAlphaRotatedQuad(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetTextureAlphaCombine(arg0->prim_a);
    ParticleGfx_DrawModelQuadRotated(arg1, arg0->unk_2C, arg0->unk_1C, D_82190FC0, arg0->unk_94.z);
}

extern Vtx D_82190E90[];

void func_82141220(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_82190E90);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8214127C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214127C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141308; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141308.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8214139C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214139C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141428; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141428.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821414B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821414B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141540; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141540.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821415CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821415CC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821416BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821416BC.s")
#endif
