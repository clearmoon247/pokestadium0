/* Stadium Zero fragment000_80C00. */
/* C ported from the Stadium 1 decomp: src/fragments/gb_tower_emulator/gb_tower_emulator_7F9A0.c. */

#include "global.h"
#include "fragments/gb_tower_emulator/gb_tower_emulator.h"
#include "game_state.h"
#include "jpeg_stream.h"
#include "scheduler.h"
#include "gfx_rect.h"
#include "controller.h"
#include "memory.h"
#include "variables.h"
typedef struct unk_D_8122C4FA {
  /* 0x00 */ u8 unk_00;
  /* 0x01 */ u8 unk_01;
} unk_D_8122C4FA;
typedef struct unk_D_8122B2F8 {
  /* 0x000000 */ char unk000000[0x1FEAE8];
} unk_D_8122B2F8;
typedef struct unk_D_8122B1E8 {
  /* 0x00 */ OSMesg mesg[1];
  /* 0x04 */ OSMesgQueue queue;
  /* 0x1C */ char unk1C[0x4];
  /* 0x20 */ s32 unk_20;
  /* 0x24 */ s32 unk_24;
  /* 0x28 */ void* unk_28;
  /* 0x2C */ s32 unk_2C;
  /* 0x30 */ char unk30[0x8];
  /* 0x38 */ s32 unk_38;
  /* 0x3C */ s32 unk_3C;
  /* 0x40 */ void* unk_40;
  /* 0x44 */ char unk44[0x4];
  /* 0x48 */ void* unk_48;
  /* 0x4C */ void* unk_4C;
  /* 0x50 */ u32 unk_50;
  /* 0x54 */ s32 unk_54;
  /* 0x58 */ void* unk_58;
  /* 0x5C */ s32 unk_5C;
  /* 0x60 */ char unk60[0x8];
} unk_D_8122B1E8;
typedef struct unk_func_812009D0 {
  /* 0x00 */ u8 unk00[0x34];
  /* 0x34 */ u8 data[0x10];  
  /* 0x44 */ u16 unk_44;
  /* 0x46 */ u8 unk_46;
  /* 0x47 */ u8 unk47;
  /* 0x48 */ u8 unk_48;
  /* 0x49 */ u8 unk_49;
  /* 0x4A */ u8 unk_4A;
} unk_func_812009D0;
typedef struct unk_D_8120D7F3 {
    u8 pad[0x116];
    u8 unk116;
} unk_D_8120D7F3;
extern OSThread gGbPakServiceThread;
extern u8 gGbPakServiceThreadStack[0x1000];
extern OSMesg gGbPakServiceQueueMessages[4];
extern OSMesgQueue gGbPakServiceQueue;
extern OSMesgQueue* gGbPakSiEventQueue;
extern volatile u8 gGbPakServiceThreadActive;
extern u8 gGbEmuPresentationMode;
extern unk_D_8122C4FA gGbEmuButtonBindingSelections;
extern u8* gGbEmuFont1Data;
extern u8* gGbEmuFont2Data;
void func_812070A0(void);
void GbApu_SelectRegionClock(s32);
void func_81117068(u16, u8, u16);
void GbApu_ResetChannels(void);
void GbApu_Reset(unk_D_8122B2F8*);
void func_811173F4(void);
void GbAudio_SetAlternateRendererEnabled(s32);
#define GB_EMU_PAL_Y_SCALE 0.833f

#include "m2c_macros.h"

s32 GbEmu_PixelOpDitherA(s32 arg0, s32 arg1);
s32 GbEmu_PixelOpDitherB(s32 arg0, s32 arg1);
s32 GbEmu_PixelOpAverage555(s32 arg0, s32 arg1);
s32 GbEmu_PixelOpReplace(UNUSED s32 arg0, s32 arg1);
void GbEmu_BlitWithPixelOp(u16* dst, u16* src, s32 mode, s32 width, s32 height);
void func_81103D60(u16* dst, u16* src, s32 color, s32 width, s32 height);
void func_8110427C(u16* dst, u8* alpha_map, s32 color, s32 width, s32 height, u32 alpha_stride);
void GbEmu_Delay(OSTime arg0);
void func_81107128(u16* arg0, u16* arg1, s16* arg2, s32 arg3, s32 arg4);

#ifdef NON_MATCHING
/* TODO: decompile func_81101FA0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81101FA0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81101FE8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81101FE8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811020A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811020A8.s")
#endif

s32 func_80051110(s32, s8 *, s8 *);             /* extern */

s32 func_81102168(s8 *arg0) {
    s32 temp_v0;
    s32 var_v1;

    M2C_FIELD(arg0, s8 *, 0xA2) = 1;
    temp_v0 = func_80051110(M2C_FIELD(arg0, s32 *, 0x50), arg0 + 0x9B, arg0);
    var_v1 = temp_v0;
    if ((temp_v0 == 0) && ((M2C_FIELD(arg0, u8 *, 0x9B) & 9) != 9)) {
        var_v1 = 0x63;
    }
    if (var_v1 != 0) {
        return var_v1;
    }
    M2C_FIELD(arg0, s8 *, 0xA2) = 0;
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_811021D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811021D4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81102280; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81102280.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81102344; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81102344.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811023DC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811023DC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81102460; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81102460.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81102690; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81102690.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811027A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811027A8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81102970; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81102970.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81102AC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81102AC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81102C20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81102C20.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81102EB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81102EB0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81102F7C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81102F7C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811030F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811030F0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811035B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811035B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81103728; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81103728.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81103850; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81103850.s")
#endif

s32 GbEmu_PixelOpDitherA(s32 arg0, s32 arg1) {
  return (arg1 & 1) ? arg1 : arg0;
}

s32 GbEmu_PixelOpDitherB(s32 arg0, s32 arg1) {
  return (arg1 & 1) ? arg0 : arg1;
}

s32 GbEmu_PixelOpAverage555(s32 arg0, s32 arg1) {
  return (((s32) ((arg0 & 0xF800) + (arg1 & 0xF800)) >> 1) & 0xF800) | (((s32) ((arg0 & 0x7C0) + (arg1 & 0x7C0)) >> 1) & 0x7C0) | (((s32) ((arg0 & 0x3E) + (arg1 & 0x3E)) >> 1) & 0x3E);
}

s32 GbEmu_PixelOpReplace(UNUSED s32 arg0, s32 arg1) {
  return arg1;
}

void GbEmu_BlitWithPixelOp(u16* dst, u16* src, s32 mode, s32 width, s32 height) {
  s32 (*operation)(s32, s32);
  s32 x;
  s32 y;
  width = ((width + 3) & 0xFFC);
  switch (mode) {
      case 0:  operation = GbEmu_PixelOpDitherA; break;
      case 1:  operation = GbEmu_PixelOpDitherB; break;
      case 2:  operation = GbEmu_PixelOpAverage555; break;
      default: operation = GbEmu_PixelOpReplace; break;
  }

  for (x = 0; x != height; x++) {
      for (y = 0; y != width; y++) {
          *dst = operation(*dst, *src);
          dst++;
          src++;
      }
      dst = dst - width + 0x140;
  }
}

M2C_UNK func_8004FD20(s32, M2C_UNK);                /* extern */
M2C_UNK func_8005C0A0();                            /* extern */
extern s32 D_8115658C;

void func_81103D30(void) {
    func_8004FD20(D_8115658C, 0x2800);
    func_8005C0A0();
}

void func_81103D60(u16* dst, u16* src, s32 color, s32 width, s32 height) {
    s32 x;
    s32 y;
    s32 intensity;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            intensity = (src[y * width + x] & 0x3E) >> 1;
            dst[y * 320 + x] = ((((color & 0xF800) * intensity) / 31) & 0xF800) |
                               ((((color & 0x7C0) * intensity) / 31) & 0x7C0) |
                               ((((color & 0x3E) * intensity) / 31) & 0x3E);
        }
    }
}

void func_8110427C(u16* dst, u8* alpha_map, s32 color, s32 width, s32 height, u32 alpha_stride) {
  u16* dst_row;
  u8* alpha_row;
  s32 x;
  s32 y;
  s32 var_t0;
  s32 var_t4;
  s32 var_a0;
  for (y = 0; y < height; y++) {
      for (x = 0; x < width; x++) {
          var_a0 = alpha_map[y * alpha_stride + x] & 0xF;
          var_t0 = (dst[y * 320 + x] & 0xF800) + (((color & 0xF800) * var_a0) / 15 & 0xF800);
          if (var_t0 > 0xF800) var_t0 = 0xF800;
          var_t4 = var_t0;
          var_t0 = (dst[y * 320 + x] & 0x07C0) + (((color & 0x07C0) * var_a0) / 15 & 0x07C0);
          if (var_t0 > 0x07C0) var_t0 = 0x07C0;
          var_t4 |= var_t0;
          var_t0 = (dst[y * 320 + x] & 0x003E) + (((color & 0x003E) * var_a0) / 15 & 0x003E);
          if (var_t0 > 0x003E) var_t0 = 0x003E;
          dst[y * 320 + x] = (s16)(var_t4 | var_t0);
      }
  }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8110445C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110445C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81104540; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81104540.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81104618; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81104618.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811047A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811047A0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81104930; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81104930.s")
#endif

M2C_UNK func_8004FD20(s32, M2C_UNK);                /* extern */
extern s32 D_81156550;

void func_81104AE4(void) {
    func_8004FD20(D_81156550 + 0x12D00, 0x20);
}

#ifdef NON_MATCHING
/* TODO: decompile func_81104B18; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81104B18.s")
#endif

M2C_UNK func_81102970(u8, s32);                     /* extern */
extern u8 D_811565A0;

void func_81104B60(s32 arg0) {
    func_81102970(D_811565A0, arg0);
}

void GbEmu_Delay(OSTime arg0) {
  OSMesgQueue sp68;
  void* sp64;
  OSTimer sp40;

  osCreateMesgQueue(&sp68, &sp64, 1);
  osSetTimer(&sp40, (1000 * arg0) * 64 / 3, 0, &sp68, NULL);
  osRecvMesg(&sp68, NULL, 1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_81104C30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81104C30.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81104CD4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81104CD4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81104D84; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81104D84.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81104DD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81104DD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811056CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811056CC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811064DC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811064DC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8110659C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110659C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8110665C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110665C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81106700; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81106700.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811067B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811067B0.s")
#endif

extern s8 D_81156546;

void func_81106820(void) {
    D_81156546 = 1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_81106830; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81106830.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811068A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811068A0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81106AA0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81106AA0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81106CC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81106CC8.s")
#endif

void func_81107128(u16* arg0, u16* arg1, s16* arg2, s32 arg3, s32 arg4) {
    s32 i;
    s32 j;
    s32 var_v1;
    s32 var_t4;

    for (j = 0; j < arg3; j++) {
        for (i = 0; i < 320; i++) {
            var_v1 = (arg0[(j * 320) + ((arg4 + i) % 320)] & 0xF800) + (arg1[(j * 320) + i] & 0xF800);
            if (var_v1 > 0xF800) {
                var_v1 = 0xF800;
            }
            var_t4 = var_v1;
            var_v1 = (arg0[(j * 320) + ((arg4 + i) % 320)] & 0x7C0) + (arg1[(j * 320) + i] & 0x7C0);
            if (var_v1 > 0x7C0) {
                var_v1 = 0x7C0;
            }
            var_t4 |= var_v1;
            var_v1 = (arg0[(j * 320) + ((arg4 + i) % 320)] & 0x3E) + (arg1[(j * 320) + i] & 0x3E);
            if (var_v1 > 0x3E) {
                var_v1 = 0x3E;
            }
            arg2[(j * 320) + i] = var_t4 | var_v1;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8110724C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8110724C.s")
#endif
