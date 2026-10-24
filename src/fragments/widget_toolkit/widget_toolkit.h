#ifndef _FRAGMENT2_H_
#define _FRAGMENT2_H_

#include "global.h"

typedef struct unk_func_87801684 {
    /* 0x00 */ u32* unk_00;
    /* 0x04 */ s16 unk_04;
} unk_func_87801684; // size = 0x8
























void Widget_Init(void);
void Widget_DrawControllerDisconnectBanner(void);
void Rand_Advance(void);
u32 Rand_Range(u32 arg0);
void Widget_DrawProgressBar(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void Widget_DrawMeterBar(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void Minigame_InitSharedState(s16 arg0);
void Widget_FillRect(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void Widget_MeasureLabelBox(s32* arg0, s32* arg1, char* arg2, char* arg3, s32 arg4);
s32 Text_MeasureStringWidth(UNUSED FontContext* arg0, char* arg1);
void Widget_DrawPlayerIconScaled(s32 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4);
void Widget_DrawPlayerIcon(s32 arg0, s16 arg1, s16 arg2, f32 arg3);
void Widget_DrawAnimIcon16(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void Widget_DrawAnimIcon16B(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void Widget_DrawAnimIcon16C(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void Widget_DrawAnimIcon40x20(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void Widget_DrawAnimIcon40x20B(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void Widget_DrawAnimIcon24(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void Widget_DrawAnimIcon28(s16 arg0, s16 arg1, s16 arg2, unk_func_87801684* arg3);
void Widget_DrawSplitBanner(s16 arg0, s16 arg1, s16 arg2);
void Widget_DrawStripedBar(s16 arg0, s16 arg1);

void Widget_CountdownComputeScale(s16 arg0, s16 arg1, f32* arg2, f32* arg3);
void Widget_CountdownInit(void);
void Widget_CountdownUpdate(void);
void Widget_CountdownStart(s16 arg0);
s32 Widget_CountdownGetState(void);

void Widget_PauseMenuInit(void);
void Widget_PauseMenuResetWinStreak(void);

void Widget_PauseMenuTrigger(s16 arg0);
void Widget_PauseMenuRecordWin(s32 arg0);
void Widget_PauseMenuCheckTournamentEnd(void);
s32 Widget_PauseMenuCheckHyperUnlock(void);
void Widget_PauseMenuFindLeaders(void);
s32 Widget_PauseMenuGetResult(void);
void Widget_DrawPanel(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, u8* arg5);
void MathUtil_BuildTransformMtx(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA);
void Widget_PauseMenuDrawWinIcons(s16 arg0);
void Widget_PauseMenuDrawIconQuad(s32 arg0, u32* arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD, f32 argE);


void Widget_PauseMenuDrawPlayerIcons(s16 arg0);
s32 Widget_PauseMenuUpdate(void);

#endif // _FRAGMENT2_H_
