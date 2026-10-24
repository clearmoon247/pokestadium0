/* Stadium Zero fragment000_80C00. */
/* C ported from the Stadium 1 decomp: src/audio_sound_state.c, src/fragments/battle_engine/battle_engine_2FA4D0.c, src/fragments/battle_engine/battle_engine_317E70.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "graphics_textures.h"
#include "ui_graphics.h"
#include "status_icons.h"
#include "game_state.h"
#include "text_system.h"
#include "3D140.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "matrix.h"
#include "controller.h"
#include "memmap.h"
#include "memory.h"

#include "audio_sound_state.h"
#include "libnumus/player.h"
#include "audio_stream.h"
#include "3D140.h"
#include "audio_commands.h"

#include "fragments/battle_engine/battle_engine.h"
#include "geo_render.h"
#include "model_renderer.h"
#include "matrix.h"
#include "fragments/particle_math/particle_math.h"
#include "memory.h"

#include "m2c_macros.h"

void func_8110FC30(void);
void func_8110FC38(void);
void func_8110FC40(void);
void func_8110FE90(void);
s32 Audio_CountCategorySounds(s32 arg0);
void BattleAnim_ClearEffectStateFlag(void);
void BattleAnim_EffectStartNop(void);
void BattleAnim_DisableEffectSpawningAlias(void);

void BattleAnim_DisableEffectSpawning(void);

void func_8110FC30(void) {
}

void func_8110FC38(void) {
}

void func_8110FC40(void) {
}

M2C_UNK func_800567E0(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
extern s8 D_811861DA;
extern s8 D_811861DB;
extern s8 D_811861DC;
extern M2C_UNK D_811861E0;
extern M2C_UNK D_811861E8;
extern M2C_UNK *D_81186200;
extern M2C_UNK D_81186208;
extern M2C_UNK D_81186218;
extern M2C_UNK *D_81186230;
extern M2C_UNK D_81186234;
extern M2C_UNK D_81186238;
extern M2C_UNK *D_81186250;

void func_8110FC48(void) {
    D_811861DA = 0;
    D_811861DB = 0;
    D_811861DC = 0;
    D_81186200 = &D_811861E8;
    D_81186230 = &D_81186218;
    D_81186250 = &D_81186238;
    func_800567E0(D_81186200, &D_811861E0, 1);
    func_800567E0(D_81186230, &D_81186208, 4);
    func_800567E0(D_81186250, &D_81186234, 1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8110FCF0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110FCF0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8110FD48; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110FD48.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8110FD6C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110FD6C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8110FD90; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110FD90.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8110FDC0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110FDC0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8110FDF0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110FDF0.s")
#endif

void func_8110FE74(void) {
    (*(u8 *)&D_811861DB) = (*(u8 *)&D_811861DA);
    (*(s8 *)&D_811861DC) = 0;
}

void func_8110FE90(void) {
}

s32 func_8004D1C0(M2C_UNK *, u32 *, M2C_UNK);       /* extern */
extern M2C_UNK D_811855D8;

u32 func_8110FE98(s32 *arg0) {
    u32 sp1C;

    if (func_8004D1C0(&D_811855D8, &sp1C, 0) == -1) {
        *arg0 = 0;
        return 0U;
    }
    *arg0 = sp1C & 0xFFFFFF;
    return sp1C >> 0x18;
}

s32 Audio_CountCategorySounds(s32 arg0) {
    return Audio_CountActiveSoundsByCategory(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8110FF1C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110FF1C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8110FF74; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110FF74.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8110FFC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110FFC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81110060; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81110060.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8111009C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8111009C.s")
#endif

extern s8 D_811847BC;
s8 func_811100F8(s32 arg0, s32 arg1) {
    return *(&D_811847BC + ((arg0 * 0x15C) + arg1));
}

M2C_UNK func_811098C0(M2C_UNK *, s32, M2C_UNK);     /* extern */
extern M2C_UNK D_811842A0;

void func_81110128(s32 arg0, M2C_UNK arg1) {
    func_811098C0(&D_811842A0, arg0, arg1);
}

void BattleAnim_ClearEffectStateFlag(void) {
    D_811842A0 = 0;
}

void BattleAnim_EffectStartNop(void) {
}

void BattleAnim_DisableEffectSpawningAlias(void) {
    BattleAnim_DisableEffectSpawning();
}
