/* Stadium Zero fragment008_1720F0. */

#include "global.h"
#include "m2c_macros.h"
#include "graphics_textures.h"

s32 func_800246A8(M2C_UNK, s32);                    /* extern */

s32 func_88100020(void) {
    s32 var_s0;

    var_s0 = 0;
loop_1:
    if (func_800246A8(0x10, var_s0) == 0) {
        return var_s0;
    }
    var_s0 += 1;
    if (var_s0 == 0x10) {
        return -1;
    }
    goto loop_1;
}

typedef struct Entry88100078 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04[0x50];
} Entry88100078; // size = 0x54
s32 func_80020AFC(s32, s32, s32, s32);
s32 func_80020CE4(void*, s32, s32);
M2C_UNK func_80020C60(s32);
void func_88100078(s32 arg0, s32 arg1, s32 arg2, s32* arg3) {
    Entry88100078* entry = (Entry88100078*)arg3[0];
    s32 handle = func_80020AFC(arg0, arg1, arg2, 0);
    s32 i;

    for (i = 0; i < 6; i++, entry++) {
        if (func_80020CE4(entry->unk_04, 1, handle) == 0) {
            break;
        }
        entry->unk_00 = 0;
    }
    func_80020C60(handle);
    arg3[2] = i;
}

s32 func_80020B94(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s8 *, s32); /* extern */
M2C_UNK func_80020C60(s32);                         /* extern */
s32 func_80020DF0(s32, M2C_UNK, s32);               /* extern */
void func_88100100(s8 *arg0, M2C_UNK arg1)
{
  s32 temp_s3;
  s32 var_s0;
  s32 var_s1;
  var_s1 = *((s32 *) (((s8 *) arg0) + 0x18));
  if ((!arg0) && (!arg0))
  {
  }
  temp_s3 = func_80020B94(0x10, 0, arg1, 0, arg0 + 8, *((s32 *) (((s8 *) arg0) + 4)));
  var_s0 = 0;
  if ((*((s32 *) (((s8 *) arg0) + 0x20))) > 0)
  {
    loop_1:
    if (func_80020DF0(var_s1 + 4, 1, temp_s3) != 0)
    {
      var_s0 += 1;
      var_s1 += 0x54;
      if (var_s0 < (*((s32 *) (((s8 *) arg0) + 0x20))))
      {
        goto loop_1;
      }
    }

  }
  func_80020C60(temp_s3);
}

#ifdef NON_MATCHING
/* TODO: decompile func_881001A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881001A8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8810024C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_8810024C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100348; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100348.s")
#endif

extern Color_RGBA8 D_88102D74;
void func_8002A0AC(s32, s32, s32, s32, Color_RGBA8);
void func_80027F20(s32);

void func_88100428(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4, s32* arg5) {
    s32 temp_v0 = *arg5;

    if (arg4 & 0x10) {
        func_8002A0AC(arg0 + 3, arg1 + 3, temp_v0 - 6, 0x1A, D_88102D74);
    }
    Font_BeginTranslucentTextRendering();
    func_80027F20(arg4);
    Font_SetActive(0x10, 0);
    Font_Printf(arg0 + 8, arg1 + 4, arg2);
    Font_EndTexturedTextRendering();
}

#ifdef NON_MATCHING
/* TODO: decompile func_881004CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881004CC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881005E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881005E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881007AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881007AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100898; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100898.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881009A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881009A0.s")
#endif

s32 func_8002B390(void*);
M2C_UNK func_8002BC14(s32);
extern s32 D_800603C0;
s32 func_88100B2C(s32 arg0) {
    s32 sp1C = 0;

    if (func_8002B390((u8*)arg0 + 0xA4) == 0) {
        sp1C = func_8002BC14(D_800603C0);
        if (sp1C == 1) {
            switch (M2C_FIELD(arg0, s32*, 0xA8)) {
                case 0:
                    sp1C = 1;
                    break;
                case 1:
                    sp1C = -1;
                    break;
            }
        }
    }
    return sp1C;
}

#ifdef NON_MATCHING
/* TODO: decompile func_88100BA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100BA4.s")
#endif

s32 func_8002AE6C();
extern u8 D_800734A8[4];
void Gallery_AlbumDrawStatusText(s8* arg0) {
    u8* c;

    if (func_8002AE6C() == 0) {
        Font_BeginTranslucentTextRendering();
        c = D_800734A8;
        Gfx_SetEnvColor(c[0], c[1], c[2], c[3]);
        Font_SetActive(8, 0);
        Font_SetLineHeight(0x1C);
        Font_Printf(M2C_FIELD(arg0, s32*, 0) + 0xE, M2C_FIELD(arg0, s32*, 4) + 0xE, M2C_FIELD(arg0, char**, 0x2C));
        Font_EndTexturedTextRendering();
    }
}

M2C_UNK func_8002BC14(s32);                         /* extern */
extern s32 D_800603C0;

void func_88100CA8(s32 arg0) {
    func_8002BC14(D_800603C0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_88100CD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100CD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100D30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100D30.s")
#endif

typedef struct Color88100D9C {
    u8 c[4];
} Color88100D9C;
extern Gfx D_80060270[];
void func_80029028(s32, s32, s32, s32, Color88100D9C);
void func_88100D9C(s32 arg0, s32 arg1, Color88100D9C arg2) {
    gSPDisplayList(gDisplayListHead++, D_80060270);
    func_80029028(arg0, arg1, 0x214, 1, arg2);
    func_80029028(arg0, arg1 + 0x63, 0x214, 1, arg2);
}

#ifdef NON_MATCHING
/* TODO: decompile func_88100E34; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100E34.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8810105C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_8810105C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8810112C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_8810112C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8810137C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_8810137C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101478; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101478.s")
#endif

void func_8810165C(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = 0xF;
}

void func_88101670(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = 0xF;
    M2C_FIELD(arg0, s32 *, 0) = (s32) (arg1 * 0xF);
}

s32 func_88101690(s8 *arg0)
{
 if (0) { }
  return (*((s32 *) (((s8 *) arg0) + 0))) >= ((*((s32 *) (((s8 *) arg0) + 4))) * (*((s32 *) (((s8 *) arg0) + 8))));
}

s32 func_881016B0(s32 *arg0) {
    return *arg0 == 0;
}

s32 func_881016BC(s8* arg0) {
    if (M2C_FIELD(arg0, s32*, 0) < M2C_FIELD(arg0, s32*, 4) * M2C_FIELD(arg0, s32*, 8)) {
        M2C_FIELD(arg0, s32*, 0) += 1;
    }
    return func_88101690(arg0);
}

void Audio_QueueSoundAvoidingRecent(s32* arg0) {
    if (*arg0 > 0) {
        *arg0 -= 1;
    }
    func_881016B0(arg0);
}

s32 func_88101734(s32 *arg0) {
    return *arg0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8810173C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_8810173C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101A38; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101A38.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101D7C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101D7C.s")
#endif

void func_88101DB4(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xBC) = arg1;
    switch (arg1) {                                 /* irregular */
    case 0:
        M2C_FIELD(arg0, s32 *, 4) = 0;
        return;
    case 1:
        M2C_FIELD(arg0, s32 *, 4) = 1;
        return;
    case 2:
        M2C_FIELD(arg0, s32 *, 4) = 2;
        return;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_88101DF8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101DF8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101EC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101EC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101F1C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101F1C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102184; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102184.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881025C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881025C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102600; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102600.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102688; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102688.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102710; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102710.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102794; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102794.s")
#endif

void func_800069CC(void);
void func_8002C064(s32, s32, s32, s32, s32);
extern u8 D_88102D70[];
void func_881005E4(s32*, s32);
void func_88101F1C(s32*);
M2C_UNK func_88102834(s32 a) {
    s32* arg0 = (s32*)a;
    func_800069CC();
    func_8002C064(0x38, 0x1E0, D_88102D70[0], D_88102D70[1], D_88102D70[2]);
    switch (arg0[0]) {
        case 0:
            func_881005E4(arg0 + 1, 2);
            break;
        case 1:
            func_88101F1C(arg0 + 0x22);
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_881028B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881028B8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881029E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881029E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102A2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102A2C.s")
#endif

M2C_UNK func_8000B1FC();                            /* extern */
M2C_UNK func_8000B220();                            /* extern */
M2C_UNK func_88102834(s32);                         /* extern */
M2C_UNK func_881028B8(s32);                         /* extern */
extern s32 D_881030F8;

void func_88102B58(s32 arg0) {
    func_8000B1FC();
    func_8000B220();
    func_88102834(D_881030F8);
    func_881028B8(D_881030F8);
}

M2C_UNK func_80002DC0(s32);                         /* extern */
extern s32 D_881030F8;

void func_88102B98(void) {
    func_80002DC0(D_881030F8);
}

#ifdef NON_MATCHING
/* TODO: decompile func_88102BBC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102BBC.s")
#endif
