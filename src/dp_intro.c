/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/audio_loop_point.c, src/controller.c, src/dp_intro.c. */

#include "global.h"
#include <PR/os_internal_reg.h>
#include "dp_intro.h"
#include "scheduler.h"
#include "gfx_rect.h"
#include "crash_screen.h"
#include "profiler.h"
#include "memory.h"
extern u64 F3DEX2_data_bin[];
extern s32 D_800733F0;
extern UnkStruct80083CA0_2 D_800870A0;
extern u64 D_80087B88[0x100 / sizeof(u64)];
extern u64 D_80087C88[0x408 / sizeof(u64)];
extern u64 D_80088090[0xC08 / sizeof(u64)];
extern u64 D_80088C98[0x20000 / sizeof(u64)];
void Display_ClearFramebufferLine(u16 color);
void Display_SetBufferConfig(struct UnkArray4* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5, s32 arg6, s32 arg7);

#include "audio_loop_point.h"
#include "libnumus/player.h"
#include "audio_channel.h"
#include "audio_commands_category2.h"
#include "rom_device.h"
#include "audio_stream.h"
#include "audio_cache.h"
#include "3D140.h"
#include "audio_commands.h"

#include "global.h"
#include "controller.h"
#include "gb_tower.h"
#include "math_util.h"
extern Controller* gPlayer1Controller;
extern Controller* gPlayer2Controller;
extern Controller* gPlayer3Controller;
extern Controller* gPlayer4Controller;
extern Controller gControllers[4];
extern OSMesgQueue gSIEventMesgQueue;
extern u8 gControllerBits;
extern u8 gEepromProbe;
extern OSContStatus gControllerStatuses[4];
extern OSContPad gControllerPads[4];
extern OSMesg gSIEventMesgBuf[1];
extern OSMesg gEepromMesgBuf[1];
extern OSMesgQueue gEepromMesgQueue;

#include "m2c_macros.h"

void DisplayTask_Initialize(UnkStruct80001380* arg0);
void DisplayTask_Submit(UnkStruct80001380* arg0, struct UnkArray4* arg1, s32 arg2);
u16 Display_GetFramebufferClearColor(void);
void Display_WaitForCompletion(void);
void Display_QueueFramebufferRequest(void* arg0);
void Display_WaitForFrames(s32 arg0);
void Display_SetBufferConfig(struct UnkArray4* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5, s32 arg6, s32 arg7);
u32 Audio_GetSpecialSequenceState(void);
u8 Cont_GetControllerBits(void);

void DisplayTask_Initialize(UnkStruct80001380* arg0) {
    arg0->task.t.type = M_GFXTASK;
    arg0->task.t.flags = 0;
    arg0->task.t.ucode_boot = D_80087B88;
    arg0->task.t.ucode_boot_size = 0x100;
    arg0->task.t.ucode = _binary_assets_us_F3DEX2_bin_start;
    arg0->task.t.ucode_data = F3DEX2_data_bin;
    arg0->task.t.ucode_size = 0x1000;
    arg0->task.t.ucode_data_size = 0x800;
    arg0->task.t.dram_stack = (void*)ALIGN16((uintptr_t)D_80087C88);
    arg0->task.t.dram_stack_size = 0x400;
    arg0->task.t.yield_data_ptr = (void*)ALIGN16((uintptr_t)D_80088090);
    arg0->task.t.yield_data_size = 0xC00;
    arg0->task.t.output_buff = (D_80088C98);
    arg0->task.t.output_buff_size = (D_80088C98 + (0x20000 / sizeof(u64)));
    osCreateMesgQueue(&arg0->queue, &arg0->mesg, 1);
}

void DisplayTask_Submit(UnkStruct80001380* arg0, struct UnkArray4* arg1, s32 arg2) {
    arg0->task.t.data_ptr = (void*)(uintptr_t)arg1->unk_04;
    arg0->task.t.data_size = arg1->unk_08;
    Sched_SubmitTask(arg0, arg2);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80001234; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80001234.s")
#endif

extern M2C_UNK D_800870D0;

void func_800012AC(s8 *arg0) {
    if (arg0 == NULL) {
        M2C_FIELD(&D_800870D0, s32 *, 0xA88) = 0;
        M2C_FIELD(&D_800870D0, s32 *, 0xA8C) = 0;
        M2C_FIELD(&D_800870D0, s32 *, 0xA90) = 0;
        M2C_FIELD(&D_800870D0, u8 *, 0xA85) = (u8) M2C_FIELD(&D_800870D0, u8 *, 0xA95);
        M2C_FIELD(&D_800870D0, u8 *, 0xA86) = (u8) M2C_FIELD(&D_800870D0, u8 *, 0xA96);
        M2C_FIELD(&D_800870D0, u8 *, 0xA84) = (u8) M2C_FIELD(&D_800870D0, u8 *, 0xA94);
        return;
    }
    M2C_FIELD(&D_800870D0, u8 *, 0xA85) = (u8) M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(&D_800870D0, u8 *, 0xA86) = (u8) M2C_FIELD(arg0, u8 *, 2);
    M2C_FIELD(&D_800870D0, u8 *, 0xA84) = (u8) M2C_FIELD(arg0, u8 *, 0);
    M2C_FIELD(&D_800870D0, s32 *, 0xA88) = (s32) M2C_FIELD(arg0, s32 *, 4);
    M2C_FIELD(&D_800870D0, s32 *, 0xA8C) = (s32) M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(&D_800870D0, s32 *, 0xA90) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(&D_800870D0, u8 *, 0xA87) = (u8) M2C_FIELD(arg0, u8 *, 3);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80001328; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80001328.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80001558; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80001558.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800016C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800016C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80001868; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80001868.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80001948; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80001948.s")
#endif

u16 Display_GetFramebufferClearColor(void) {
    u16* ptr = (u16*)D_800870A0.unk_9E0->img_p;
    return *ptr;
}

void Display_WaitForCompletion(void) {
    osRecvMesg(&D_800870A0.unk_A04, NULL, 1);
}

void Display_QueueFramebufferRequest(void* arg0) {
    osSendMesg(&D_800870A0.unk_9EC, arg0, 0);
}

void Display_WaitForFrames(s32 arg0) {
    while (arg0-- > 0) {
        Display_QueueFramebufferRequest(0);
        Display_WaitForCompletion();
    }
}

void Display_SetBufferConfig(struct UnkArray4* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5, s32 arg6, s32 arg7) {
    arg0->unk_01 = arg1;
    arg0->unk_02 = arg2;
    arg0->unk_00 = arg3;
    arg0->unk_03 = arg4;
    arg0->unk_04 = arg5;
    arg0->unk_08 = arg6;
    arg0->unk_0C = (struct unk_D_80068BB0*)(uintptr_t)arg7;
}

u32 Audio_GetSpecialSequenceState(void) {
    return D_80087B80;
}

M2C_UNK func_80001234(s8, s8);                      /* extern */
extern M2C_UNK D_800870D0;

void func_80001A78(void) {
    func_80001234(M2C_FIELD(&D_800870D0, s8 *, 0xAA5), M2C_FIELD(&D_800870D0, s8 *, 0xAA6));
}

extern M2C_UNK D_800870D0;

s32 func_80001AA4(void) {
    s32 var_v1;

    var_v1 = 1;
    if (M2C_FIELD(&D_800870D0, s32 *, 0xA98) != 0) {
        var_v1 = M2C_FIELD(&D_800870D0, s32 *, 0xA24) > 0;
    }
    return var_v1;
}

/*
 * Retrieve the current controller bits.
 */
u8 Cont_GetControllerBits(void) {
    return gControllerBits;
}
