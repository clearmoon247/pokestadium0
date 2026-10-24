/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/DDC0.c. */

#include <PR/os_internal_reg.h>
#include "global.h"
#include "dp_intro.h"
#include "profiler.h"
#include "audio_loop_point.h"
#include "scheduler.h"
#include "gb_tower_audio.h"
#include "audio_commands.h"
#include "audio_category_fade.h"
#include "audio_sound_state.h"
#include "audio_channel.h"
#include "audio_loop_point.h"
typedef struct unk_D_800A8480 {
  /* 0x0000 */ OSThread thread;
  /* 0x01B0 */ char unk01B0[0x2030];
} unk_D_800A8480;
extern s32 D_800AAE30;
extern s32 D_800AAF3C;

void func_8000A798(void);
void Audio_ResetCurrentMusic(void);
void Audio_PlayMusicIfChanged(s32 arg0);
void Audio_StopMusic(s32 arg0);
s32 Audio_WaitForIdle(s32 arg0);
void Audio_FadeOutForShutdown(void);
void Audio_Disable(void);
void Audio_Enable(void);

void func_8000A798(void) {
}

void Audio_ResetCurrentMusic(void) {
    D_800AAF3C = -1;
}

void Audio_PlayMusicIfChanged(s32 arg0) {
    if (arg0 != D_800AAF3C) {
        if (D_800AAF3C >= 0) {
            Audio_FadeOutAll(0);
        }
        Audio_StartMusicTrack(arg0);
        D_800AAF3C = arg0;
    }
}

void Audio_StopMusic(s32 arg0) {
    if (D_800AAF3C >= 0) {
        Audio_FadeOutAll(arg0);
        D_800AAF3C = -1;
    }
}

s32 Audio_WaitForIdle(s32 arg0) {
    s32 retvar = 0;

    if (arg0 != 0) {
        Audio_FadeCategoriesAndStreams(2);
    }
    while (Audio_GetActivityScore() != 0) {
        if (retvar < 1000000) {
            retvar++;
        } else if (retvar == 1000000) {
            Audio_FadeCategoriesAndStreamsDefault();
            retvar++;
        }
    }
    return retvar;
}

void Audio_FadeOutForShutdown(void) {
    Audio_FadeCategoriesAndStreamsWithDuration(0x10);
}

void Audio_Disable(void) {
    D_800AAE30 = 0;
    Audio_SetEnabled(0);
}

void Audio_Enable(void) {
    Audio_SetEnabled(1);
    D_800AAE30 = 1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8000A92C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000A92C.s")
#endif
