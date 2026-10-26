/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_3540B0.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "gfx_buffer.h"
#include "m2c_macros.h"

extern OwnerLinkedFourStream D_821B5E30[4];
void OwnerAnchoredFourStream_Update(f32 arg0, Vec3f* arg1, f32 arg2);
void OwnerAnchoredFourStream_UpdateNodeChain(OwnerAnchoredFourStream* arg0);

typedef struct OwnerLinkedFourStreamZero {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ char unk006[0x16];
    /* 0x01C */ OwnerLinkedFourStreamNode unk_01C[15];
} OwnerLinkedFourStreamZero; // size = 0x418

extern OwnerLinkedFourStreamZero D_821B6F00[4];

void func_8217DC80(void) {
    s32 i;
    s32 j;
    OwnerLinkedFourStreamZero* var_a2 = &D_821B6F00[0];
    OwnerLinkedFourStreamNode* var_v0;

    for (i = 0; i < 4; i++, var_a2++) {
        var_a2->unk_000 = 0;
        var_a2->unk_002 = 0;
        var_a2->unk_004 = 0;

        var_v0 = &var_a2->unk_01C[0];
        for (j = 0; j < 15; j++, var_v0++) {
            var_v0->unk_00 = 0;
            var_v0->unk_04 = 1.0f;
            var_v0->unk_08 = 0.0f;
            var_v0->unk_0C.z = var_v0->unk_0C.y = var_v0->unk_0C.x = 0.0f;
            var_v0->unk_18.z = var_v0->unk_18.y = var_v0->unk_18.x = 0.0f;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8217DDD4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8217DDD4.s")
#endif

void OwnerAnchoredFourStream_Update(f32 arg0, Vec3f* arg1, f32 arg2) {
    UNUSED MtxF sp70;
    MtxF sp30;
    UNUSED s32 pad;

    guRotateF(sp30.mf, (arg0 * 360.0) / 6.2831854820251465, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(sp30.mf, 0.0f, 0.0f, arg2, &arg1->x, &arg1->y, &arg1->z);
}

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

M2C_UNK func_8217E0C0(M2C_UNK *);                   /* extern */
s32 func_8217E34C(void)
{
  s8 *new_var;
  s32 var_s1;
  new_var = (s8*)D_821B6F00;
  var_s1 = 0;
  do
  {
    new_var = (s8 *) ((0, new_var));
    if ((*((s16 *) (new_var + 0))) == 1)
    {
      new_var = new_var;
      *((s16 *) (new_var + 2)) = (s16) ((*((s16 *) (new_var + 2))) + 1);
      if ((*((s16 *) (new_var + 4))) < (*((s16 *) (new_var + 2))))
      {
        *((s16 *) (new_var + 0)) = 0;
      }
      else
      {
        func_8217E0C0(new_var);
      }
    }
    var_s1 += 1;
    new_var += 0x418;
  }
  while (var_s1 != 4);
  return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8217E3E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8217E3E0.s")
#endif
