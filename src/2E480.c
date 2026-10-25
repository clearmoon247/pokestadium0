/* Stadium Zero resident code. */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_8002D880; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002D880.s")
#endif

void func_8002D900(u8* arg0);

void func_8002D8D8(s8 *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    func_8002D900((u8*)arg0);
}

void func_8002D900(u8* arg0) {
    s32 i;

    for (i = 0; i < M2C_FIELD(M2C_FIELD(arg0, u8**, 0), s32*, 4); i++) {
        M2C_FIELD(arg0, s16**, 4)[i] = 0;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002D948; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002D948.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002D9B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002D9B8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002DAD8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002DAD8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002DC04; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002DC04.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002DCE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002DCE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002DDFC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002DDFC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002DECC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002DECC.s")
#endif

void func_8002DF54(u8* arg0);

void func_8002DF2C(s8 *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    func_8002DF54((u8*)arg0);
}

void func_8002DF54(u8* arg0) {
    s32 i;

    for (i = 0; i < M2C_FIELD(M2C_FIELD(arg0, u8**, 0), s32*, 4); i++) {
        M2C_FIELD(arg0, s16**, 4)[i] = 0;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002DF9C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002DF9C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002E078; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002E078.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002E230; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002E230.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002E3F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002E3F0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002E70C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002E70C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002EC24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002EC24.s")
#endif

void func_8002D900(u8* arg0);

void func_8002ED18(s8 *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    func_8002D900((u8*)arg0);
}

void func_8002ED50(s8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x34);
    if (temp_v0 < M2C_FIELD(arg0, s32 *, 0x2C)) {
        M2C_FIELD(arg0, s32 *, 0x2C) = temp_v0;
    }
}

void func_8002ED70(s8 *arg0)
{
  s32 *new_var3;
  s32 *new_var2;
  int temp_v0;
  s8 *new_var;
  s32 *new_var4;
  new_var = (s8 *) arg0;
  new_var4 = (s32 *) (new_var + 0x34);
  new_var3 = &(*new_var4);
  temp_v0 = ((*(new_var2 = new_var3)) - ((*((s32 *) (((s8 *) arg0) + 0x24))) * (*((s32 *) (((s8 *) arg0) + 0x10))))) + 1;
  if ((*((s32 *) (((s8 *) arg0) + 0x2C))) < temp_v0)
  {
    *((s32 *) (new_var + 0x2C)) = temp_v0;
  }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002EDA8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002EDA8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002F030; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002F030.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002F32C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002F32C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002F3C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002F3C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002F6C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002F6C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002F9D8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002F9D8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002FD8C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002FD8C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80030230; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80030230.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800306E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800306E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80030744; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80030744.s")
#endif

void WidgetTree_SetPagedGridSelectionWithOffset(s8* arg0, s32 arg1, s32 arg2) {
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_lo;
    s32 temp_v1;
    s32 var_v0_2;
    s8* temp_v0 = M2C_FIELD(arg0, s8**, 0);

    if (M2C_FIELD(temp_v0, s32*, 8) != 0) {
        M2C_FIELD(arg0, s32*, 0x40) = 0;
        temp_v1 = M2C_FIELD(temp_v0, s32*, 8) - 1;
        if (arg1 >= temp_v1) {
            arg1 = temp_v1;
        }
        M2C_FIELD(arg0, s32*, 8) = arg1;
        M2C_FIELD(arg0, s32*, 0x34) = M2C_FIELD(arg0, s32*, 0x10) * arg1;

        temp_a2 = M2C_FIELD(temp_v0, s32*, 8) - M2C_FIELD(arg0, s32*, 0x24);
        temp_lo = M2C_FIELD(arg0, s32*, 0x10) * ((temp_a2 > 0) ? temp_a2 : 0);

        temp_a2_2 = -(arg2 * M2C_FIELD(arg0, s32*, 0x10)) + M2C_FIELD(arg0, s32*, 0x34);
        if (temp_a2_2 > 0) {
            var_v0_2 = temp_a2_2;
        } else {
            var_v0_2 = 0;
        }

        temp_v1 = (var_v0_2 < temp_lo) ? var_v0_2 : temp_lo;
        M2C_FIELD(arg0, s32*, 0x2C) = temp_v1;
        M2C_FIELD(arg0, s32*, 0x30) = temp_v1;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_80030894; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80030894.s")
#endif

void func_8002D900(u8* arg0);

void func_800309D4(s8 *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    func_8002D900((u8*)arg0);
}

void func_800309FC(s8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x34);
    if (temp_v0 < M2C_FIELD(arg0, s32 *, 0x2C)) {
        M2C_FIELD(arg0, s32 *, 0x2C) = temp_v0;
    }
}

void func_80030A1C(s8 *arg0)
{
  s32 temp_v0;
  s8 *new_var;
  temp_v0 = ((*((s32 *) (((s8 *) arg0) + 0x34))) - ((*((s32 *) (((s8 *) arg0) + 0x24))) * (*((s32 *) (((s8 *) arg0) + 0x10))))) + 1;
  new_var = ((s8 *) arg0) + 0x2C;
  if ((*((s32 *) (((s8 *) arg0) + 0x2C))) < temp_v0)
  {
    *((s32 *) new_var) = temp_v0;
  }
}

#ifdef NON_MATCHING
/* TODO: decompile func_80030A54; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80030A54.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80030D3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80030D3C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80031004; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80031004.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800310D8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800310D8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80031464; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80031464.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003152C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003152C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80031AB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80031AB0.s")
#endif

M2C_UNK func_8002DDFC();                            /* extern */
M2C_UNK func_80031AB0(s8 *, s32);                 /* extern */

void func_80031B88(s8 *arg0) {
    func_8002DDFC();
    func_80031AB0(arg0, M2C_FIELD(arg0, s32 *, 8));
}
