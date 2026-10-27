/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/fragments/particle_math/particle_math_269820.c, src/gb_save.c. */

#include "gb_save.h"
#include "input.h"
#include "gb_data.h"
#include "pokemon_stats.h"
#include "save_data.h"
#include "game_state.h"
#include "audio_sfx.h"
#include "gfx_buffer.h"
#include "controller.h"
#include "memory.h"
#include "stage_loader.h"
extern u32 D_8007360C[];
extern u8 pad_D_80075944[];

#include "fragments/particle_math/particle_math.h"
#include "geo_render.h"
extern ParticleDescriptor gDefaultParticleDescriptor;

#include "m2c_macros.h"

void GbSave_BuildPortSummary(unk_func_8002D860* arg0, s32 arg1);
void Particle_SetVelocityXZFromRotationY(Particle* arg0);
s32 Ui_AdjustVerticalSelection(unk_func_8002DCB8_arg0* arg0, s32 arg1);
s32 Ui_HandleVerticalSelectionInput(s32 arg0);
s32 Ui_AdjustHorizontalSelection(unk_func_8002DD98_arg0* arg0, s32 arg1);
s32 Ui_HandleHorizontalSelectionInput(unk_func_8002DD98_arg0* arg0);
void Ui_AdjustSteppedScrollSelection(unk_func_8002DE78_arg0* arg0);
s32 Ui_HandleNumericSelectionInput(unk_func_8820E99C_030_030* arg0);
s32 Ui_AdjustSteppedRangeSelection(unk_func_8002E128_arg0* arg0);
s32 Ui_GetSelectionDirection(unk_func_8002EBD8_arg0* arg0);
Color_RGBA8 Color_InterpolateFromGray(Color_RGBA8 arg0, f32 arg1);

s32 Ui_AdjustNumericSelection(unk_func_8830867C_044_038_030* arg0, s32 arg1);
void Particle_Field50_SetXZFromField7C_09BB4(Particle* arg0);
void Particle_Field7C_SetXZFromField74AngleY_0B278(Particle* arg0);

M2C_UNK func_8001AA9C(u8, u8, u8, u8);              /* extern */
extern s8 D_800734A8;
extern s8 D_800734B0;
extern s8 D_800734B8;
void func_80027F20(s32 arg0)
{
  s8 *new_var;
  if (arg0 & 0x18)
  {
    new_var = &D_800734B8;
  }
  else
    if (arg0 & 1)
  {
    new_var = &D_800734B0;
    new_var = new_var;
  }
  else
  {
    new_var = &D_800734A8;
  }
  if (!(arg0 & 2))
  {
    new_var += 4;
  }
  new_var = (s8 *) new_var;
  func_8001AA9C(*((u8 *) (new_var + 0)), *((u8 *) (new_var + 1)), *((u8 *) (new_var + 2)), *((u8 *) (((s8 *) new_var) + 3)));
}

#ifdef NON_MATCHING
/* TODO: decompile func_80027F8C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80027F8C.s")
#endif

void GbSave_BuildPortSummary(unk_func_8002D860* arg0, s32 arg1) {
    if (GbSave_GetSaveState(arg1) != 0) {
        arg0->unk_00 = 1;
    } else {
        arg0->unk_00 = 0;
        arg0->unk_08 = GbSave_GetTrainerId(arg1);
        GbSave_GetPlayerName(arg1, &arg0[1]);
    }
    arg0->unk_04 = GbSave_GetPortGame(arg1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80028060; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80028060.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80028C80; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80028C80.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80028E5C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80028E5C.s")
#endif

void Trade_DrawSolidFillRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8 arg4) {
    s32 color = RGBA5551(arg4.r, arg4.g, arg4.b, 1);

    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (color << 0x10) | color);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_800290F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800290F0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800291F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800291F8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800292A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800292A8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800295E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800295E8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80029658; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80029658.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80029864; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80029864.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80029A64; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80029A64.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002A0AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002A0AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002A32C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002A32C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002A354; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002A354.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002A3F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002A3F8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002A550; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002A550.s")
#endif

void func_8002A8C4(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  s8 *new_var;
  *((s32 *) (((s8 *) arg0) + 0)) = arg1;
  *((s32 *) (((s8 *) arg0) + 4)) = arg2;
  new_var = arg0;
  *((s32 *) (((s8 *) arg0) + 8)) = arg3;
  *((s32 *) (((s8 *) new_var) + 0xC)) = arg4;
  *((s32 *) (((s8 *) arg0) + 0x10)) = 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002A8E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002A8E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002AAC4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002AAC4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002AB84; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002AB84.s")
#endif

void Particle_SetVelocityXZFromRotationY(Particle* arg0) {
    Particle_Field7C_SetXZFromField74AngleY_0B278(arg0);
    Particle_Field50_SetXZFromField7C_09BB4(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002AE94; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002AE94.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002AF04; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002AF04.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002B018; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002B018.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002B054; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002B054.s")
#endif

s32 Ui_AdjustVerticalSelection(unk_func_8002DCB8_arg0* arg0, s32 arg1) {
    s32 ret = 0;

    switch (arg1) {
        case 0x800:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_04 == 0) {
                arg0->unk_04 += arg0->unk_08;
            }
            arg0->unk_04--;
            ret = 1;
            break;

        case 0x400:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_04 >= (arg0->unk_08 - 1)) {
                arg0->unk_04 -= arg0->unk_08;
            }
            arg0->unk_04++;
            ret = 1;
            break;
    }

    return ret;
}

s32 Ui_HandleVerticalSelectionInput(s32 arg0) {
    s32 sp1C = Input_GetRepeatedDPad() & 0xFFFF;

    Ui_AdjustVerticalSelection(arg0, sp1C);
    return sp1C;
}

s32 Ui_AdjustHorizontalSelection(unk_func_8002DD98_arg0* arg0, s32 arg1) {
    s32 ret = 0;

    switch (arg1) {
        case 0x200:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_04 == 0) {
                arg0->unk_04 += arg0->unk_08;
            }
            arg0->unk_04--;
            ret = 1;
            break;

        case 0x100:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_04 >= (arg0->unk_08 - 1)) {
                arg0->unk_04 -= arg0->unk_08;
            }
            arg0->unk_04++;
            ret = 1;
            break;
    }

    return ret;
}

s32 Ui_HandleHorizontalSelectionInput(unk_func_8002DD98_arg0* arg0) {
    s32 sp1C = Input_GetRepeatedDPad() & 0xFFFF;

    Ui_AdjustHorizontalSelection(arg0, sp1C);
    return sp1C;
}

void Ui_AdjustSteppedScrollSelection(unk_func_8002DE78_arg0* arg0) {
    s32 temp_v0 = Input_GetRepeatedDPad();
    s32 sp18 = arg0->unk_0C;

    if (gPlayer1Controller->buttonDown & 0x2000) {
        sp18 = ((arg0->unk_08 - arg0->unk_04) + 1) / 10;
    }

    switch (temp_v0) {
        case 0x800:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_00 - sp18 < arg0->unk_04) {
                arg0->unk_00 = arg0->unk_04;
            } else {
                arg0->unk_00 -= sp18;
            }
            break;

        case 0x400:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_08 < arg0->unk_00 + sp18) {
                arg0->unk_00 = arg0->unk_08;
            } else {
                arg0->unk_00 += sp18;
            }
            break;
    }
}

s32 Ui_AdjustNumericSelection(unk_func_8830867C_044_038_030* arg0, s32 arg1) {
    s32 var_t1;
    s32 var_a2;
    s32 i;

    var_a2 = 1;

    for (i = arg0->unk_10; i > 0; i--) {
        var_a2 *= 10;
    }

    switch (arg1) {
        case 0x200:
            if (arg0->unk_10 + 1 < arg0->unk_0C) {
                arg0->unk_10 = arg0->unk_10 + 1;
            }
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            var_t1 = 1;
            break;

        case 0x100:
            if (arg0->unk_10 > 0) {
                arg0->unk_10--;
            }
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            var_t1 = 1;
            break;

        case 0x800:
            if (arg0->unk_00 == arg0->unk_08) {
                arg0->unk_00 = arg0->unk_00 - ((arg0->unk_00 / var_a2) * var_a2);
                if (arg0->unk_00 < arg0->unk_04) {
                    arg0->unk_00 = arg0->unk_04;
                }
            } else {
                arg0->unk_00 += var_a2;
                if (arg0->unk_08 < arg0->unk_00) {
                    arg0->unk_00 = arg0->unk_08;
                }
            }
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            var_t1 = 1;
            break;

        case 0x400:
            if (arg0->unk_00 == arg0->unk_04) {
                arg0->unk_00 = arg0->unk_08;
            } else {
                arg0->unk_00 -= var_a2;
                if (arg0->unk_00 < arg0->unk_04) {
                    arg0->unk_00 = arg0->unk_04;
                }
            }
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            var_t1 = 1;
            break;
    }
    return var_t1;
}

s32 Ui_HandleNumericSelectionInput(unk_func_8820E99C_030_030* arg0) {
    s32 sp1C = Input_GetRepeatedDPad() & 0xFFFF;

    Ui_AdjustNumericSelection(arg0, sp1C);
    return sp1C;
}

s32 Ui_AdjustSteppedRangeSelection(unk_func_8002E128_arg0* arg0) {
    s32 sp1C = Input_GetRepeatedDPad() & 0xFFFF;
    s32 sp18 = arg0->unk_0C;

    if (sp1C != 0) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);

        switch (sp1C) {
            case 0x200:
                sp18 *= 0xA;

            case 0x800:
                if (arg0->unk_00 >= arg0->unk_08) {
                    arg0->unk_00 = arg0->unk_04;
                } else if (arg0->unk_08 < (arg0->unk_00 + sp18)) {
                    arg0->unk_00 = arg0->unk_08;
                } else {
                    arg0->unk_00 = arg0->unk_00 + sp18;
                }
                break;

            case 0x100:
                sp18 *= 0xA;

            case 0x400:
                if (arg0->unk_04 >= arg0->unk_00) {
                    arg0->unk_00 = arg0->unk_08;
                } else if ((arg0->unk_00 - sp18) < arg0->unk_04) {
                    arg0->unk_00 = arg0->unk_04;
                } else {
                    arg0->unk_00 = arg0->unk_00 - sp18;
                }
                break;
        }
    }

    return sp1C;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002B788; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002B788.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002B940; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002B940.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002BAB8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002BAB8.s")
#endif

s32 Ui_GetSelectionDirection(unk_func_8002EBD8_arg0* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_08 & 0x4000) {
        var_v1 = -1;
    } else if (arg0->unk_08 & 0x8000) {
        var_v1 = 1;
    }

    return var_v1;
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
s32 GbSave_GameToCategoryIndex(s32 arg0) {
    static s32 D_80075910[] = { 0, 0, 1, 2, 0, 0, 0, 3, 0, 0, 0, 0 };

    return D_80075910[arg0];
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002BC44.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002BC58; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002BC58.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002BE24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002BE24.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002C064; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002C064.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002C1B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002C1B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002C5A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002C5A4.s")
#endif

Color_RGBA8 Color_InterpolateFromGray(Color_RGBA8 arg0, f32 arg1) {
    static Color_RGBA8 D_80075940 = { 0xC8, 0xC8, 0xC8, 0xFF };

    Color_RGBA8 sp4;

    sp4.r = (s32)((arg0.r - D_80075940.r) * arg1) + D_80075940.r;
    sp4.g = (s32)((arg0.g - D_80075940.g) * arg1) + D_80075940.g;
    sp4.b = (s32)((arg0.b - D_80075940.b) * arg1) + D_80075940.b;
    sp4.a = arg0.a;

    return sp4;
}

extern Color_RGBA8 D_800736A8;
void func_8002A0AC(s32, s32, s32, s32, Color_RGBA8);

void BattleInfoWidget_DrawLabel(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4) {
    if (arg4 & 0x18) {
        func_8002A0AC(arg0 + 3, arg1 + 3, 0xE6, 0x16, D_800736A8);
    }

    Font_BeginTranslucentTextRendering();
    func_80027F20(arg4);
    Font_SetActive(8, 0);
    Font_Printf(arg0 + 8, arg1 + 4, arg2);
    Font_EndTexturedTextRendering();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002CA34; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002CA34.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002CAD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002CAD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002CC44; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002CC44.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002CD7C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002CD7C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002CE5C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002CE5C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002CEEC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002CEEC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002D024; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002D024.s")
#endif

s32 func_8002D138(UNUSED s32 arg0) {
    s32 ret = 0;

    if (gPlayer1Controller->buttonPressed & (BTN_A | BTN_B)) {
        ret = 1;
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
    }
    return ret;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002D188; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002D188.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002D2BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002D2BC.s")
#endif

s32 func_8002D3D0(u8* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (arg0[i + 9] == 0) {
            return i;
        }
    }
    return 4;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002D430; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002D430.s")
#endif

s32 func_8002D3D0(u8*);
s32 func_8002D430(s32, s32);                        /* extern */

s32 func_8002D454(s32 arg0, s32 arg1) {
    if (arg1 >= func_8002D3D0((u8*)arg0)) {
        return -1;
    }
    return func_8002D430(arg0, arg1);
}

s32 func_8001FA8C(s32);

s32 func_8002D498(BattleMon* arg0, s32 arg1) {
    s32 idx = arg0->unk_00.unk_00 - 1;
    s32 type;

    if (arg1 == 1) {
        if (gSpeciesData[idx].type1 == gSpeciesData[idx].type2) {
            return -1;
        }
        type = gSpeciesData[idx].type2;
    } else {
        type = gSpeciesData[idx].type1;
    }
    return func_8001FA8C(type);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002D520; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002D520.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002D7D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002D7D4.s")
#endif
