/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/gallery_debugger/gallery_debugger.c, src/fragments/gallery_enlarge/gallery_enlarge.c, src/fragments/gym_leader_castle/gym_leader_castle.c, src/fragments/jigglypuff_doodle/jigglypuff_doodle.c. */

#include "fragments/gallery_debugger/gallery_debugger.h"
#include "graphics_textures.h"
#include "input.h"
#include "save_data.h"
#include "jpeg_stream.h"
#include "gfx_buffer.h"
#include "controller.h"
#include "memory.h"
#include "stage_loader.h"
typedef struct unk_D_839006B0 {
    /* 0x00 */ BattleMon unk_00;
    /* 0x54 */ char unk54[0x38];
} unk_D_839006B0;
typedef struct unk_D_83902700 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk04[0x70];
} unk_D_83902700;

#include "fragments/gallery_enlarge/gallery_enlarge.h"
#include "display_object_textures.h"
#include "graphics_textures.h"
#include "input.h"
#include "gallery.h"
#include "jpeg_stream.h"
#include "audio_sfx.h"
#include "gfx_buffer.h"
#include "controller.h"
#include "fragments/gallery_backgrounds/gallery_backgrounds.h"
#include "memory.h"
#include "stage_loader.h"

#include "fragments/gym_leader_castle/gym_leader_castle.h"
#include "graphics_textures.h"
#include "ui_graphics.h"
#include "save_data.h"
#include "game_state.h"
#include "text_system.h"
#include "jpeg_stream.h"
#include "audio_sfx.h"
#include "audio_commands_category2.h"
#include "DDC0.h"
#include "memory.h"
#include "stage_loader.h"
extern char** sUiText;
extern char** sTrainerNameText;
extern GymLeaderCastleTrainer sCurrentNodeTrainers[4];
extern BinArchive* sTrainerDataArchive;
extern BinArchive* sPortraitArchive;
extern BinArchive* sBackgroundArchive;
extern u8* sGymLeaderCastleTexture;
extern u8* sEliteFourTexture;
extern s16 sCurrentHoverNodeIndex;
#define CHAMPION 11
#define ELITE_4 10
#define ELITE_4_TO_GLC 9
#define GLC_TO_ELITE_4 8
#define GIOVANNI 7
extern CastleMapNode sCastleMapNodes[];
extern s16 sSelectedMapNode;
extern s16 sCursorMoveTimer;
extern s16 sRoomDescriptionHeight;
extern s16 sEliteFourTransition;

#include "fragments/jigglypuff_doodle/jigglypuff_doodle.h"
#include "math.h"
#include "geo_render.h"
#include "model_animation_events.h"
#include "geo_layout.h"
#include "display_object_textures.h"
#include "model_renderer.h"
#include "graphics_textures.h"
#include "input.h"
#include "ui_graphics.h"
#include "gallery.h"
#include "jpeg_stream.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "matrix.h"
#include "controller.h"
#include "fragments/widget_toolkit/widget_toolkit.h"
#include "fragments/minigame_shared_graphics/minigame_shared_graphics.h"
#include "memory.h"
#include "stage_loader.h"
typedef struct unk_D_86301730 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ DisplayObject unk_004;
    /* 0x16C */ Vec3f unk_16C;
    /* 0x178 */ s8 unk_178;
    /* 0x179 */ s8 unk_179;
    /* 0x17A */ s8 unk_17A;
    /* 0x17B */ s8 unk_17B;
    /* 0x17C */ u16 unk_17C;
    /* 0x17E */ char pad17E[6];
} unk_D_86301730;

#include "m2c_macros.h"

void func_82183DC4(void);
void GalleryDebugger_SaveControllerPak(void);
void GalleryDebugger_LoadControllerPak(void);
void func_821853F4(void);
void func_821853FC(void);
void JigglypuffGame_UpdateEffects(void);

void func_82183DC4(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82183DCC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82183DCC.s")
#endif

void GalleryDebugger_SaveControllerPak(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82183E24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82183E24.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82183E88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82183E88.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82183F04; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82183F04.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82183F6C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82183F6C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82183FD4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82183FD4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8218403C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8218403C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821840B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821840B8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82184134; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82184134.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8218419C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8218419C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82184AA8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82184AA8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82184ADC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82184ADC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82184BC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82184BC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82184CE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82184CE0.s")
#endif

s32 func_82184D9C(s8 *arg0, s32 arg1) {
    if ((arg1 == M2C_FIELD(arg0, u8 *, 0x28)) || (arg1 == M2C_FIELD(arg0, u8 *, 0x29))) {
        return 1;
    }
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82184DC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82184DC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82185044; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82185044.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82185108; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82185108.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821851B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821851B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82185220; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82185220.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82185378; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82185378.s")
#endif

void GalleryDebugger_LoadControllerPak(void) {
}

void func_821853F4(void) {
}

void func_821853FC(void) {
}

void JigglypuffGame_UpdateEffects(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_8218540C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8218540C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82185450; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82185450.s")
#endif

extern s8 *D_821CF2A0;

s32 func_82185494(void) {
    return (M2C_FIELD(D_821CF2A0, u8 *, 0x59) & 0x10) == 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_821854AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821854AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821855F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821855F0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82185684; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82185684.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821857CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821857CC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821858DC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821858DC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82185A30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82185A30.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82185BE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82185BE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82185D44; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82185D44.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82186394; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82186394.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821864D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821864D4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8218663C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8218663C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821866F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821866F0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821867A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821867A8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82186834; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82186834.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821868E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821868E8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821869C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821869C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82186AF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82186AF4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82186CA8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82186CA8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82186F28; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82186F28.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821870D8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821870D8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82187134; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82187134.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82187414; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82187414.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82187738; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82187738.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821879A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821879A4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82187DB4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82187DB4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82188050; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82188050.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8218824C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8218824C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82188394; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82188394.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821886F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821886F0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82188770; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82188770.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82188B8C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82188B8C.s")
#endif
