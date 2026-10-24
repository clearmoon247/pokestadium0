/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_3540B0.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "gfx_buffer.h"

void OwnerAnchoredFourStream_Update(f32 arg0, Vec3f* arg1, f32 arg2);
void OwnerAnchoredFourStream_UpdateNodeChain(OwnerAnchoredFourStream* arg0);

#ifdef NON_MATCHING
/* TODO: decompile func_8217DC80; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8217DC80.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8217DDD4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8217DDD4.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void OwnerAnchoredFourStream_Update(f32 arg0, Vec3f* arg1, f32 arg2) {
    UNUSED MtxF sp70;
    MtxF sp30;
    UNUSED s32 pad;

    guRotateF(sp30.mf, (arg0 * 360.0) / 6.2831854820251465, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(sp30.mf, 0.0f, 0.0f, arg2, &arg1->x, &arg1->y, &arg1->z);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8217E030.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void OwnerAnchoredFourStream_UpdateNodeChain(OwnerAnchoredFourStream* arg0) {
    s32 i;
    OwnerAnchoredFourStreamNode* var_s0 = &arg0->unk_01C[0];

    for (i = 0; i < 15; i++, var_s0++) {
        if (i == 0) {
            var_s0->unk_24 = var_s0->unk_04;
            var_s0->unk_28 = var_s0->unk_08;

            var_s0->unk_2C = var_s0->unk_0C;
            var_s0->unk_38 = var_s0->unk_18;

            var_s0->unk_0C.x += var_s0->unk_18.x;
            var_s0->unk_0C.y += var_s0->unk_18.y;
            var_s0->unk_0C.z += var_s0->unk_18.z;

            var_s0->unk_08 += arg0->unk_010;
            if (arg0->unk_006 > 0) {
                var_s0->unk_18.x += 0.4;
                if (var_s0->unk_18.x > 20.0) {
                    var_s0->unk_18.x = 20.0f;
                }
            } else {
                var_s0->unk_18.x -= 0.4;
                if (var_s0->unk_18.x < -20.0) {
                    var_s0->unk_18.x = -20.0f;
                }
            }

            BattleAnim_SetParticlePosition(arg0->unk_018, var_s0->unk_0C);

            var_s0->unk_04 += 2.0;
            if (arg0->unk_00C < var_s0->unk_04) {
                var_s0->unk_04 = arg0->unk_00C;
            }
        } else {
            var_s0->unk_24 = var_s0->unk_04;
            var_s0->unk_28 = var_s0->unk_08;

            var_s0->unk_2C = var_s0->unk_0C;
            var_s0->unk_38 = var_s0->unk_18;

            var_s0->unk_0C = var_s0[-1].unk_2C;
            var_s0->unk_08 = var_s0[-1].unk_28;
            var_s0->unk_18 = var_s0[-1].unk_38;
            var_s0->unk_04 = var_s0[-1].unk_24;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8217E0C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8217E34C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8217E34C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8217E3E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8217E3E0.s")
#endif
