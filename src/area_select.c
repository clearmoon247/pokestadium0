/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/fragments/area_select/area_select.c. */

#include "fragments/area_select/area_select.h"
#include "graphics_textures.h"
#include "input.h"
#include "game_state.h"
#include "save_data.h"
#include "text_system.h"
#include "jpeg_stream.h"
#include "audio_sfx.h"
#include "cry.h"
#include "gfx_buffer.h"
#include "DDC0.h"
#include "matrix.h"
#include "controller.h"
#include "memory.h"
#include "stage_loader.h"
#include "math_util.h"
#include "variables.h"
typedef struct AreaSelectEntryConfig {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 orbitRadius;
    /* 0x06 */ s8 upArea;
    /* 0x07 */ s8 downArea;
    /* 0x08 */ s8 leftArea;
    /* 0x09 */ s8 rightArea;
    /* 0x0A */ Color_RGBA8 exitColor;
} AreaSelectEntryConfig;
typedef struct AreaSelectMagnemitePoint {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 diameter;
} AreaSelectMagnemitePoint;
typedef struct AreaSelectMagnemiteTrail {
    /* 0x00 */ s16 centerX;
    /* 0x02 */ s16 centerY;
    /* 0x04 */ s16 orbitRadius;
    /* 0x06 */ s16 scalePercent;
    /* 0x08 */ s16 orbitAngle;
    /* 0x0A */ s16 spriteFrame;
    // FAKE: AdvanceMagnemiteTrail and DrawAndAdvanceMagnemites access six
    // afterimages; this four-element declaration gives overlapping 0x24-byte trails.
    /* 0x0C */ AreaSelectMagnemitePoint afterimages[4];
} AreaSelectMagnemiteTrail;
typedef struct AreaSelectExitFade {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 halfExtent;
    /* 0x06 */ s16 blackBlendAlpha;
    /* 0x08 */ Color_RGBA8 color;
} AreaSelectExitFade;
extern s16 sAreaSelectBackgroundFadeAlpha;
extern s16 sAreaSelectGlowDiameter;
extern s16 sAreaSelectStateIds[];
extern u8* sAreaSelectNameBannerTextures[];
#define AREA_STADIUM 0
#define AREA_FREE_BATTLE 1
#define AREA_GYM_LEADER_CASTLE 2
#define AREA_VS_MEWTWO 3
#define AREA_MINIGAMES 4
#define AREA_HALL_OF_FAME 5
#define AREA_OAKS_LAB 6
#define AREA_GB_TOWER 7
#define AREA_NONE 8
#define AREA_SELECT_INTRO 0
#define AREA_SELECT_INPUT 1
#define AREA_SELECT_MOVE 2
#define AREA_SELECT_SHRINK 3
#define AREA_SELECT_CANCEL 4
#define AREA_SELECT_EXIT_FADE 5
#define AREA_SELECT_MEWTWO_EXIT 6
#define AREA_SELECT_DONE 7
#define AREA_SELECT_REVEAL_MEWTWO 8
extern AreaSelectEntryConfig sAreaSelectEntryConfigs[9];
extern u8* sAreaSelectMagnemiteTextures[];
extern char** sAreaSelectStrings;
extern BinArchive* sAreaSelectBackgroundArchive;
extern Vp sAreaSelectViewport;
extern Mtx sAreaSelectProjectionMtx;
extern u8* sAreaSelectCurrentBackground;
extern u8* sAreaSelectNextBackground;
extern AreaSelectExitFade sAreaSelectExitFade;
extern AreaSelectMagnemiteTrail sAreaSelectMagnemiteTrails[3];
extern s32 pad_D_822031D0[0x2];
extern s16 sAreaSelectSelectedIndex;
extern s16 sAreaSelectPreviousIndex;
extern s16 sAreaSelectTransitionFrame;
extern ModeSettings sAreaSelectModeSettings;
extern GameOptions sAreaSelectGameOptions;
#define AREA_BACKGROUND_NIGHT_DODRIO 2
#define AREA_BACKGROUND_DAY_DODRIO 1
#define AREA_BACKGROUND_DAY_DODUO 19
#define AREA_BACKGROUND_DAY_NORMAL 18

void func_8005B388(void);

#ifdef NON_MATCHING
/* TODO: decompile func_8005AE20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8005AE20.s")
#endif

void func_8005B388(void) {
    // Empty function; purpose unknown.
}
