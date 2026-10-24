/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/audio_commands.c. */

#include "audio_commands.h"
#include "audio_commands_category2.h"
#include "audio_commands.h"
#include "3D140.h"
#include "libnumus/player.h"
#include "rom_device.h"
#include "audio_channel.h"
#include "audio_cache.h"
#include "cry.h"
#include "audio_fade.h"
typedef struct unk_D_80077970 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
} unk_D_80077970;
extern u8 pad_D_800FC694[4];
extern unk_D_800FC6CC* D_800B41E4;
extern u8* D_800B41E8;
extern unk_D_800FC6D4* D_800FD688;
extern s16* D_800B41EC;
extern u32* gAudioRegions;
extern s32 pad_D_800FC70C;
extern s32 pad_D_800FC710;
extern u8 pad_D_800FC718[0x80];
#define AUDIO_HEAP_SIZE 300000
extern s32 pad_D_80077C80;

#include "m2c_macros.h"

void Audio_RelocateOffsets(u32* arg0, u32 arg1, s32 arg2);
void Audio_CreateFrameTaskWrapper(void* arg0);

void Audio_RelocateOffsets(u32* arg0, u32 arg1, s32 arg2) {
    u32 i;

    for (i = 0; i < arg2; i++, arg0++) {
        *arg0 += arg1;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8003E1F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003E1F8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003EECC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003EECC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003F654; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003F654.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003F6AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003F6AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003F96C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003F96C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003FE34; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003FE34.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003FE58; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003FE58.s")
#endif

void Audio_CreateFrameTaskWrapper(void* arg0) {
    Audio_CreateFrameTask(arg0);
}

M2C_UNK func_80037AC4(s32, M2C_UNK);                /* extern */
extern u8 D_80077524;
extern s32 D_800FD64C;
extern s32 D_800FD650;

void func_80040738(void) {
    if (D_80077524 != 0) {
        func_80037AC4(D_800FD64C, 0x32);
        func_80037AC4(D_800FD650, 0x32);
    } else {
        func_80037AC4(D_800FD64C, 0x5A);
        func_80037AC4(D_800FD650, 0x5A);
    }
    D_800FD64C = 0;
    D_800FD650 = 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_800407B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800407B0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80041374; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80041374.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800414B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800414B0.s")
#endif

M2C_UNK func_8003834C(s32, s32, s32, M2C_UNK, s32, s32, s32); /* extern */
extern s32 D_800B418C;
extern s32 D_800B41A8;

void func_80041834(s32 arg0) {
    func_8003834C(D_800B418C, D_800B41A8, arg0, 0x80, 0x80, 0, -1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8004187C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8004187C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800418A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800418A4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800418CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800418CC.s")
#endif

extern s8 D_80077538;

void func_800418F0(s32 arg0) {
    if (arg0 != 0) {
        D_80077538 = 1;
        return;
    }
    D_80077538 = 0;
}

extern M2C_UNK D_800FD6B2;
extern M2C_UNK D_800FD6B4;

void func_80041914(s32 arg0, s32 arg1) {
    s8 temp_v0;
    s8 temp_v1;

    temp_v0 = arg0 * 2;
    temp_v1 = arg1 * 2;
    M2C_FIELD(&D_800FD6B2, s8 *, 0) = temp_v0;
    M2C_FIELD(&D_800FD6B4, s8 *, 0) = temp_v0;
    M2C_FIELD(&D_800FD6B2, s8 *, 1) = temp_v1;
    M2C_FIELD(&D_800FD6B4, s8 *, 1) = temp_v1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80041940; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80041940.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800419F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800419F8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80042508; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80042508.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80042A6C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80042A6C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80042FF8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80042FF8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80043860; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80043860.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80043A10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80043A10.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80043B00; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80043B00.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80043CE8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80043CE8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80043DD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80043DD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80044158; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80044158.s")
#endif
