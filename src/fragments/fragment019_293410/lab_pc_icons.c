/* Stadium Zero fragment019_293410. */
/* C ported from the Stadium 1 decomp: src/fragments/lab_pc_icons/lab_pc_icons.c. */

#include "fragments/lab_pc_icons/lab_pc_icons.h"
#include "display_object_textures.h"
#include "poke_icon.h"
#include "graphics_textures.h"
#include "ui_graphics.h"
#include "gb_data.h"
#include "table_view.h"
#include "text_system.h"
#include "gb_save.h"
#include "jpeg_stream.h"
#include "audio_sfx.h"
#include "memmap.h"
#include "memory.h"
#include "stage_loader.h"
#include "util.h"
#include "fragments/widget_tree/widget_tree.h"
#include "fragments/pokemon_lab_support/pokemon_lab_support.h"
typedef struct unk_D_88605B00 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unk_D_88605B00;

#include "m2c_macros.h"

s32 LabPC_ComputeExpForLevel(s32 arg0, s32 arg1);

#ifdef NON_MATCHING
/* TODO: decompile func_8A200020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A200020.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A20009C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A20009C.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
extern s8* D_8A21DA50;
void UI_DrawTextureRgba16(s32 arg0, s32 arg1, s32 arg2) {
    gSPDisplayList(gDisplayListHead++, D_80060290);

    Gfx_DrawTextureRgba16(arg0, arg1, 0x28, 0x28, M2C_FIELD(M2C_FIELD(M2C_FIELD(D_8A21DA50, s8**, 8) + arg2 * 0x14, s8**, 0xC), u8**, 8), 0x28, 0x200000);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A2001C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A200274; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A200274.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A20034C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A20034C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A2003C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A2003C0.s")
#endif

extern Color_RGBA8 D_8A203304;
void func_8002A0AC(s32, s32, s32, s32, Color_RGBA8);
void func_80027F20(s32);

void func_8A200770(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4) {
    if (arg4 & 0x10) {
        func_8002A0AC(arg0 + 3, arg1 + 3, 0xA2, 0x1E, D_8A203304);
    }
    Font_BeginTranslucentTextRendering();
    func_80027F20(arg4);
    Font_SetActive(0x10, 0);
    Font_Printf(arg0 + 0xC, arg1 + 6, arg2);
    Font_EndTexturedTextRendering();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A20080C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A20080C.s")
#endif

s32 func_8002AB84();                                /* extern */
M2C_UNK func_8002D9B8(s8 *, s32, s32, M2C_UNK, s32); /* extern */

void func_8A2008F4(s8 *arg0) {
    if (func_8002AB84() == 0) {
        func_8002D9B8(arg0 + 0x2C, M2C_FIELD(arg0, s32 *, 0) + 6, M2C_FIELD(arg0, s32 *, 4) + 0xC, 0xFEF, 0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A20093C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A20093C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A2009CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A2009CC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A200B78; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A200B78.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A200D44; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A200D44.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A200DE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A200DE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A2010C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A2010C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A201394; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A201394.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A201598; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A201598.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A2018E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A2018E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A201C08; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A201C08.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A201D3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A201D3C.s")
#endif

M2C_UNK func_80019008(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_80029658(s32, s32, s32, M2C_UNK *);    /* extern */
M2C_UNK func_80029864(s32, s32, s32, M2C_UNK *);    /* extern */
s32 func_8002AB84();                                /* extern */
M2C_UNK func_8A2009CC(s32, s32, s32);               /* extern */
M2C_UNK func_8A200B78(s32, s32, s32);               /* extern */
M2C_UNK func_8A200DE0(s32, s32, s32);               /* extern */
M2C_UNK func_8A2010C8(s32, s32, s32, s32);          /* extern */
M2C_UNK func_8A201394(s32, s32, s32);               /* extern */
M2C_UNK func_8A2018E0(s32, s32, s32, s32);          /* extern */
M2C_UNK func_8A201C08(M2C_UNK, M2C_UNK, s32);       /* extern */
extern s8 D_8007356C;
extern s32 D_8A21DA4C;
void func_8A201EAC(s8 *arg0, s32 arg1)
{
  s32 temp_v0;
  if (((*((s32 *) (((s8 *) arg0) + 0x28))) != 2) && (func_8002AB84() == 0))
  {
    if (arg1 == 0)
    {
      func_80029864((*((s32 *) (((s8 *) arg0) + 0))) + 0xF9, *((s32 *) (((s8 *) arg0) + 4)), *((s32 *) (((s8 *) arg0) + 0xC)), &D_8007356C);
      func_80029658(*((s32 *) (((s8 *) arg0) + 0)), (*((s32 *) (((s8 *) arg0) + 4))) + 0xD7, 0x100, &D_8007356C);
      func_80029658((*((s32 *) (((s8 *) arg0) + 0))) + 0xFA, (*((s32 *) (((s8 *) arg0) + 4))) + 0x95, 0x12E, &D_8007356C);
      func_8A2009CC((*((s32 *) (((s8 *) arg0) + 0))) + 6, (*((s32 *) (((s8 *) arg0) + 4))) + 0xDE, *((s32 *) (((s8 *) arg0) + 0x2C)));
      func_8A200B78((*((s32 *) (((s8 *) arg0) + 0))) + 0x100, (*((s32 *) (((s8 *) arg0) + 4))) + 6, *((s32 *) (((s8 *) arg0) + 0x2C)));
      func_8A200DE0((*((s32 *) (((s8 *) arg0) + 0))) + 0x100, (*((s32 *) (((s8 *) arg0) + 4))) + 0x9C, *((s32 *) (((s8 *) arg0) + 0x2C)));
    }
    else
    {
      func_80029658(*((s32 *) (((s8 *) arg0) + 0)), (*((s32 *) (((s8 *) arg0) + 4))) + 0xD7, *((s32 *) (((s8 *) arg0) + 8)), &D_8007356C);
      func_80029864((*((s32 *) (((s8 *) arg0) + 0))) + 0xF9, *((s32 *) (((s8 *) arg0) + 4)), 0xDE, &D_8007356C);
      func_8A201394((*((s32 *) (((s8 *) arg0) + 0))) + 0x100, (*((s32 *) (((s8 *) arg0) + 4))) + 6, *((s32 *) (((s8 *) arg0) + 0x2C)));
      func_8A2010C8((*((s32 *) (((s8 *) arg0) + 0))) + 6, (*((s32 *) (((s8 *) arg0) + 4))) + 0xDE, *((s32 *) (((s8 *) arg0) + 0x2C)), *((s32 *) (((s8 *) arg0) + 0x30)));
      func_8A2018E0((*((s32 *) (((s8 *) arg0) + 0))) + 0x100, (*((s32 *) (((s8 *) arg0) + 4))) + 0x54, *((s32 *) (((s8 *) arg0) + 0x2C)), *((s32 *) (((s8 *) arg0) + 0x30)));
    }
  }
  temp_v0 = *((s32 *) (((s8 *) arg0) + 0x28));
  if (((temp_v0 ^ 0) == 1) || (temp_v0 == 2))
  {
    if ((*((s32 *) (((s8 *) arg0) + 0x34))) == 0)
    {
      *((s32 *) (((s8 *) arg0) + 0x34)) = 1;
      func_80019008(D_8A21DA4C, *((s32 *) (((s8 *) arg0) + 0x2C)), 0x108D);
    }
    func_8A201C08(0x32, 0x5A, *((s32 *) (((s8 *) arg0) + 0x2C)));
  }
}

s32 func_80022B40();                                /* extern */
s32 func_8002D454(s32, s32, s8 *);                /* extern */
M2C_UNK func_8003F6AC(M2C_UNK);                     /* extern */
extern s8 *D_800603C0;

s32 func_8A202078(s8 *arg0) {
    s32 var_s0;
    u16 temp_v0;

    var_s0 = -1;
    if (func_80022B40() != 0) {
        temp_v0 = M2C_FIELD(D_800603C0, u16 *, 8);
        if (temp_v0 & 8) {
            var_s0 = 0;
        } else if (temp_v0 & 1) {
            var_s0 = 1;
        } else if (temp_v0 & 4) {
            var_s0 = 2;
        } else if (temp_v0 & 2) {
            var_s0 = 3;
        }
        if (var_s0 >= 0) {
            if (func_8002D454(M2C_FIELD(arg0, s32 *, 0x2C), var_s0, arg0) == -1) {
                func_8003F6AC(8);
            } else {
                func_8003F6AC(2);
                M2C_FIELD(arg0, s32 *, 0x30) = var_s0;
                if (M2C_FIELD(arg0, s32 *, 0x28) <= 0) {
                    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
                } else {
                    M2C_FIELD(arg0, s32 *, 0x24) = 4;
                }
            }
        }
    }
    return var_s0 >= 0;
}

M2C_UNK func_8002C064(M2C_UNK, M2C_UNK, u8, u8, s32); /* extern */
extern M2C_UNK D_8A203300;

void func_8A202160(void) {
    func_8002C064(0x38, 0x1E0, M2C_FIELD(&D_8A203300, u8 *, 0), M2C_FIELD(&D_8A203300, u8 *, 1), (s32) M2C_FIELD(&D_8A203300, u8 *, 2));
}

s32 LabPC_ComputeExpForLevel(s32 arg0, s32 arg1) {
    s32 sp4;

    switch (gBaseStats[arg0].unk_13) {
        case 0:
            sp4 = arg1 * arg1 * arg1;
            break;

        case 1:
            sp4 = (((arg1 * arg1 * arg1 * 3) / 4) + (arg1 * 0xA * arg1)) - 0x1E;
            break;

        case 2:
            sp4 = (((arg1 * arg1 * arg1 * 3) / 4) + (arg1 * 0x14 * arg1)) - 0x1E;
            break;

        case 3:
            sp4 = ((((arg1 * arg1 * arg1 * 6) / 5) - (arg1 * 0xF * arg1)) + (arg1 * 0x64)) - 0x8C;
            break;

        case 4:
            sp4 = (arg1 * arg1 * arg1 * 4) / 5;
            break;

        case 5:
            sp4 = (arg1 * arg1 * arg1 * 5) / 4;
            break;
    }
    return sp4;
}

s32 func_80020AFC(M2C_UNK, s32, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_80020C60(s32);                         /* extern */
s32 func_80020CE4(s32, s32, s32);                   /* extern */
extern s32 D_8A21DA40;

void func_8A202390(s8 *arg0) {
    s32 sp1C;
    s32 sp18;
    s32 temp_v0;

    sp1C = M2C_FIELD(arg0, s32 *, 0);
    temp_v0 = func_80020AFC(0x20, D_8A21DA40, 0, 0);
    sp18 = temp_v0;
    M2C_FIELD(arg0, s32 *, 8) = func_80020CE4(sp1C, M2C_FIELD(arg0, s32 *, 4), temp_v0);
    func_80020C60(sp18);
}

void func_80022118(s32);
void func_80020DF0(s32, s32, s32);
s32 func_8002207C(s32);
void func_8002D7D4(s32);
void func_80022188(s32);
M2C_UNK func_8A20261C(M2C_UNK *);

void func_8A2023F4(s32* arg0, s32 arg1) {
    s32* sp2C;
    s32 i;
    s32 temp_s3;

    sp2C = (s32*)arg0[0];
    func_80022118(D_8A21DA40);
    temp_s3 = func_80020AFC(0x20, D_8A21DA40, 0, 1);

    for (i = 0; i < arg0[2]; i++) {
        func_80020DF0(sp2C[i], 1, temp_s3);
    }

    func_80020C60(temp_s3);
    if (func_8002207C(D_8A21DA40) == 0) {
        func_8002D7D4(D_8A21DA40);
        func_8A20261C((M2C_UNK*)arg1);
    }
    func_80022188(D_8A21DA40);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A2024D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A2024D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A20261C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A20261C.s")
#endif

void func_8A202904(s8 *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s32 *, 0x24) = 7;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0xC) = arg2;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A20291C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A20291C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A202EF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A202EF4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A202F50; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A202F50.s")
#endif

M2C_UNK func_8000B1FC();                            /* extern */
M2C_UNK func_8000B220();                            /* extern */
M2C_UNK func_800158C0();                            /* extern */
M2C_UNK func_8001B5F0();                            /* extern */
M2C_UNK func_8A20261C(M2C_UNK *);                   /* extern */
M2C_UNK func_8A20291C(M2C_UNK *);                   /* extern */
extern M2C_UNK D_8A21DA80;

void func_8A203070(s32 arg0) {
    func_8000B1FC();
    func_8000B220();
    func_8001B5F0();
    func_800158C0();
    func_8A20261C(&D_8A21DA80);
    func_8A20291C(&D_8A21DA80);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A2030C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment019_293410/func_8A2030C0.s")
#endif
