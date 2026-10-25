/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_34A420.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "gallery.h"
#include "gfx_buffer.h"
#include "math_util.h"
#include "math.h"
typedef struct Strip400State {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s16 unk_2A;
    /* 0x2C */ Vtx* unk_2C;
    /* 0x30 */ Color_RGB8 unk_30;
    /* 0x33 */ Color_RGB8 unk_33;
} Strip400State;
typedef struct Strip400Node {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} Strip400Node;
extern Strip400State sTrailState;
extern Strip400Node sTrailPoints[400];
extern s32 pad_D_84398F48[2];
extern s32 pad_D_84389178[2];

void Radial20_Init(f32 arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9);
f32 Strip400_GetTailFadeRatio(void);
void Radial20_RotateVertexOffset(f32 arg0, UNUSED Vec3f* arg1, Vec3f* arg2, f32 arg3, UNUSED f32 arg4, UNUSED f32 arg5,
                   UNUSED f32 arg6);

void Radial20_Init(f32 arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9) {
    Strip400State* ptr1 = &sTrailState;
    Strip400Node* ptr2;
    s32 i;

    ptr1->unk_00 = 0;
    ptr1->unk_02 = 0;
    ptr1->unk_04 = 0;
    ptr1->unk_06 = 0x46;
    ptr1->unk_08 = arg0;
    ptr1->unk_0C = arg1;
    ptr1->unk_10 = arg2;
    ptr1->unk_14 = arg3 * 40.0;
    ptr1->unk_18 = arg3 * 20.0;
    ptr1->unk_1C = 0.0f;
    ptr1->unk_20 = arg3;
    ptr1->unk_24 = 1.0f;
    ptr1->unk_28 = 0;
    ptr1->unk_2A = 0;
    ptr1->unk_30.r = arg4;
    ptr1->unk_30.g = arg5;
    ptr1->unk_30.b = arg6;
    ptr1->unk_33.r = arg7;
    ptr1->unk_33.g = arg8;
    ptr1->unk_33.b = arg9;

    ptr2 = &sTrailPoints[0];
    for (i = 0; i < 400; i++, ptr2++) {
        ptr2->unk_00 = arg0;
        ptr2->unk_04 = arg1;
        ptr2->unk_08 = arg2;
        ptr2->unk_0C = ptr1->unk_14;
    }
}

f32 Strip400_GetTailFadeRatio(void) {
    Strip400State* ptr = &sTrailState;
    f32 tmp;
    s32 tmp2 = ptr->unk_00;

    if (tmp2 < (ptr->unk_06 - 0x34)) {
        return 1.0f;
    }

    if (ptr->unk_18 == 0.0f) {
        return 1.0f;
    }

    tmp = (sTrailPoints[ptr->unk_06 * 0].unk_0C * 2.0f) / (ptr->unk_14 + ptr->unk_18);
    return tmp;
}

#ifdef NON_MATCHING
/* TODO: decompile func_821742F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821742F0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821748CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821748CC.s")
#endif

extern Radial20 D_821A3490[10];
void Radial20_ResetPool(void) {
    s16 temp_v0;
    s32 i;
    s32 j;
    Radial20* var_a2;
    Radial20Node* var_v1;

    temp_v0 = AuxiliaryEffect_Alloc();
    var_a2 = &D_821A3490[0];

    for (i = 0; i < 10; i++) {
        var_a2->unk_000 = 0;
        var_a2->unk_004 = 0;
        var_a2->unk_006 = 0;

        var_v1 = &var_a2->unk_048[0];
        for (j = 0; j < 20; j++, var_v1++) {
            var_v1->unk_00 = 0.0f;
            var_v1->unk_04 = 0;
            var_v1->unk_08 = 1.0f;
            var_v1->unk_0C = 0.0f;
            var_v1->unk_10.x = 0.0f;
            var_v1->unk_10.y = 0.0f;
            var_v1->unk_10.z = 0.0f;
            var_v1->unk_1C.x = 0.0f;
            var_v1->unk_1C.y = 0.0f;
            var_v1->unk_1C.z = 0.0f;
        }

        var_a2->unk_002 = temp_v0;
        var_a2++;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82174C30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82174C30.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82174E64; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82174E64.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82175068; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82175068.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82175440; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82175440.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82175828; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82175828.s")
#endif

void Radial20_RotateVertexOffset(f32 arg0, UNUSED Vec3f* arg1, Vec3f* arg2, f32 arg3, UNUSED f32 arg4, UNUSED f32 arg5,
                   UNUSED f32 arg6) {
    UNUSED MtxF pad;
    MtxF sp30;
    UNUSED s32 pad2[2];

    guRotateF(sp30.mf, (arg0 * 360.0) / TWO_PI, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(sp30.mf, 0.0f, 0.0f, arg3, &arg2->x, &arg2->y, &arg2->z);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82175C74; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82175C74.s")
#endif

extern Radial20 D_821A3490[10];
s32 Radial20_IsComplete(void) {
    s32 i;
    s32 var_s2 = 0;
    Radial20* var_s0 = D_821A3490;

    for (i = 0; i < 10; i++, var_s0++) {
        if (var_s0->unk_000 == 1) {
            var_s0->unk_004++;
            if (var_s0->unk_006 < var_s0->unk_004) {
                var_s0->unk_000 = 0;
                if (var_s0->unk_008 == 9) {}
            } else {
                Radial20_UpdateNode(var_s0);
                var_s2++;
            }
            AuxiliaryEffect_Update(var_s0->unk_002);
        }
    }

    if (var_s2 > 0) {
        return 0;
    }
    return -1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_821765B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821765B4.s")
#endif
