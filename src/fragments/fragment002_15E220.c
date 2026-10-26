/* Stadium Zero fragment002_15E220. */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_81200020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment002_15E220/func_81200020.s")
#endif

u32 osGetCount(void);
f32 MathUtil_Random_ZeroOne(void);
void func_80025758(s32, s32, s32);
extern u8 D_81200DAC[];

void func_81200190(void) {
    s32 temp_s0;
    s32 sp38;

    temp_s0 = osGetCount() & 0xFF;
    while (temp_s0-- > 0) {
        MathUtil_Random_ZeroOne();
    }

    temp_s0 = MathUtil_Random_ZeroOne() * 40.0f;
    do {
        sp38 = MathUtil_Random_ZeroOne() * 40.0f;
    } while (temp_s0 == sp38);

    func_80025758(3, D_81200DAC[temp_s0], D_81200DAC[sp38]);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8120023C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment002_15E220/func_8120023C.s")
#endif

extern s32 D_81201010;
void func_8120047C(void) {
    u8* image = (u8*)D_81201010;
    s32 i;
    s32 j;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gDPSetCombine(gDisplayListHead++, 0x17FE2F, 0x77FCF87C);
    gDPSetTextureConvert(gDisplayListHead++, G_TC_CONV);
    gDPSetConvert(gDisplayListHead++, G_CV_K0, G_CV_K1, G_CV_K2, G_CV_K3, G_CV_K4, G_CV_K5);
    gDPPipeSync(gDisplayListHead++);

    for (i = 0; i < 0xF0; i += 0x10) {
        for (j = 0; j < 0x140; j += 0x10) {
            gDPLoadTextureBlockYuv(gDisplayListHead++, image, G_IM_FMT_YUV, G_IM_SIZ_16b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, j << 2, i << 2, (j + 0x10) << 2, (i + 0x10) << 2, G_TX_RENDERTILE,
                                0, 0, 0x0400, 0x0400);
            image += 0x200;
        }
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);
}

#ifdef NON_MATCHING
/* TODO: decompile func_812007B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment002_15E220/func_812007B0.s")
#endif

extern s32 D_81201018;
s32 func_81200970(s32 arg0)
{
  s32 var_v1_2;
  var_v1_2 = arg0 == 5;
  if (var_v1_2 == 0)
  {
    var_v1_2 = arg0 == 0;
    if (var_v1_2 == 0)
    {
      var_v1_2 = arg0 == 1;
      if (var_v1_2 == 0)
      {
        var_v1_2 = arg0 == 3;
      }
    }
  }
  var_v1_2 = var_v1_2 != 0;
  if (var_v1_2 != 0)
  {
    var_v1_2 = D_81201018 >= 0x10;
  }
  return var_v1_2;
}

s32 func_800384D8(void);

s32 func_812009C4(s32 arg0) {
    s32 var_v1 = 0;

    if ((D_81201018 >= 0x259) && (func_800384D8() == 0) && (func_81200970(arg0) != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_81200A20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment002_15E220/func_81200A20.s")
#endif

s32 func_800023C4(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8000256C(M2C_UNK);                     /* extern */
M2C_UNK func_80002620(M2C_UNK);                     /* extern */
s32 func_80003EB8(u32, M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80005040(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_800050AC();                            /* extern */
s32 func_8000645C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80006680(s32);                         /* extern */
M2C_UNK func_800066C8();                            /* extern */
s32 func_800068DC(M2C_UNK *, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8000A838(M2C_UNK);                     /* extern */
M2C_UNK func_8000D280();                            /* extern */
M2C_UNK func_8001A194(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_800407B0(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_80044158(s32);                         /* extern */
M2C_UNK func_80044268();                            /* extern */
extern M2C_UNK D_002E0BE0;
extern M2C_UNK D_002E2B90;
extern M2C_UNK D_002EBCB0;
extern M2C_UNK D_002F0A50;
extern M2C_UNK D_01000000;
extern M2C_UNK D_02000000;
extern s32 D_81201010;
extern s32 D_81201014;
extern s32 D_81201018;
extern s32 D_8120101C;
extern s32 D_81201020;
extern M2C_UNK func_81200A20;

s32 func_81200B80(s32 arg0, M2C_UNK arg1) {
    s32 sp24;
    s32 sp20;

    func_8000256C(0x5449544C);
    func_80005040(0x10000, 0);
    sp20 = func_8000645C(0, 1, 2, 0, 2, 1);
    func_8001A194(6, 0);
    func_80003EB8((u32) ((s32) &D_01000000 & 0x0F000000) >> 0x18, &D_002E0BE0, &D_002E2B90, 0);
    func_80003EB8((u32) ((s32) &D_02000000 & 0x0F000000) >> 0x18, &D_002EBCB0, &D_002F0A50, 0);
    D_81201014 = func_800023C4(0x4510, 0);
    D_8120101C = func_800023C4(0x100000, 0);
    D_81201010 = func_80003EB8(0U, &D_002E2B90, &D_002EBCB0, 0);
    D_81201018 = 0;
    D_81201020 = 0;
    func_80044158(D_8120101C);
    func_80006680(sp20);
    sp24 = func_800068DC(&func_81200A20, 0x10, 0x10);
    func_800066C8();
    func_8000D280();
    func_8000A838(0);
    func_80044268();
    if (sp24 == 0x8080) {
        func_800407B0(0x3C, 0xA, 0);
    }
    func_800050AC();
    func_80002620(0x5449544C);
    return sp24;
}
