/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/DDC0.c, src/audio_sound_state.c, src/save_data.c. */

#include "save_data.h"
#include "save_data.h"
#include "gb_data.h"
#include "jpeg_stream.h"
#include "memory.h"

#include "audio_sound_state.h"
#include "libnumus/player.h"
#include "audio_stream.h"
#include "3D140.h"
#include "audio_commands.h"

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

#include "m2c_macros.h"

u16 Save_Checksum(u8* arg0, s32 arg1);
s32 Save_RecordIsValid(u8* arg0, s32 arg1);
void Save_WriteFooter(u8* arg0, s32 arg1, s32 arg2);
s32 Audio_GetFreeVoiceCount(void);
void func_80024044(void);
void Save_ResetAndCommitTypedRecord(s32 arg0, s32 arg1);
s32 Deck_IsSaveEntryPresent(s32 arg0, s32 arg1);

s32 Save_IsTypedRecordFlagSet(s32 arg0, s32 arg1, s16 arg2);
void Save_CommitTypedRecord(s32 arg0, s32 arg1);
void Save_ClearTypedRecord(s32 arg0, s32 arg1);

u16 Save_Checksum(u8* arg0, s32 arg1) {
    u16 var_v1 = 0;

    while (arg1-- > 2) {
        var_v1 += *arg0++;
    }
    return var_v1;
}

s32 Save_RecordIsValid(u8* arg0, s32 arg1) {
    u16* temp_v1 = arg1 + arg0;

    temp_v1 -= 3;

    if (temp_v1[0] != 'PO') {
        return 0;
    }

    if (temp_v1[1] != 'KE') {
        return 0;
    }

    if (temp_v1[2] != Save_Checksum(arg0, arg1)) {
        return 0;
    }

    return 1;
}

void Save_WriteFooter(u8* arg0, s32 arg1, s32 arg2) {
    u16* temp_v1;

    if (arg2 != 0) {
        temp_v1 = arg1 + arg0;

        temp_v1 -= 3;
        *temp_v1++ = 'PO';
        *temp_v1++ = 'KE';
        *temp_v1++ = Save_Checksum(arg0, arg1);
    } else {
        temp_v1 = arg1 + arg0;
        temp_v1 -= 3;

        *temp_v1++ = 'XX';
        *temp_v1++ = 'XX';
        *temp_v1++ = Save_Checksum(arg0, arg1) ^ 0xFF;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_80023890; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80023890.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800238D8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800238D8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80023954; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80023954.s")
#endif

M2C_UNK func_80058410(s32, s32, s32);               /* extern */

void func_800239C4(s32 arg0, s32 arg1) {
    func_80058410(arg0 + arg1, arg0, arg1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_800239F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800239F0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80023A20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80023A20.s")
#endif

extern s32 D_8006BBA0;
extern s32 D_800AE8E0;

void func_80023C08(s32 arg0, s32 arg1) {
    if (arg1 == 0x42553634) {
        D_8006BBA0 = 0;
        D_800AE8E0 = 0;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_80023C30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80023C30.s")
#endif

s32 Audio_GetFreeVoiceCount(void) {
    return mus_free_voices_count;
}

M2C_UNK func_8001FB10(s32, s32);                    /* extern */
M2C_UNK func_8001FE84();                            /* extern */
M2C_UNK func_800203FC(s32);                         /* extern */
M2C_UNK func_80058410(s32, s32, M2C_UNK);           /* extern */

void func_80023D3C(s32 arg0, s32 arg1) {
    s32 sp24;
    s32 temp_a0;

    func_8001FE84();
    func_800203FC(arg0);
    temp_a0 = arg1 + 0x27;
    sp24 = temp_a0;
    func_80058410(temp_a0, arg0 + 0x3D, 3);
    func_80058410(arg1 + 0x2A, arg0 + 0x4D, 3);
    func_8001FB10(arg0 + 0x30, arg1 + 0x21);
    func_8001FB10(arg0 + 0x40, sp24);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80023DB8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80023DB8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80023E28; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80023E28.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80023F38; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80023F38.s")
#endif

void func_80024044(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002404C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002404C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80024170; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80024170.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80024294; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80024294.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800243B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800243B8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80024470; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80024470.s")
#endif

void Save_ResetAndCommitTypedRecord(s32 arg0, s32 arg1) {
    Save_ClearTypedRecord(arg0, arg1);
    Save_CommitTypedRecord(arg0, arg1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80024610; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80024610.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002465C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002465C.s")
#endif

s32 Deck_IsSaveEntryPresent(s32 arg0, s32 arg1) {
    return Save_IsTypedRecordFlagSet(arg0, arg1, 1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_800246C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800246C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002479C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002479C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002488C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002488C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80024954; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80024954.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80024ADC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80024ADC.s")
#endif

M2C_UNK func_80023F38(s32, s32, M2C_UNK);           /* extern */
s32 func_80024ADC();                                /* extern */

void func_80024B90(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 < func_80024ADC()) {
        switch (arg0) {                             /* irregular */
        case 16:
            M2C_FIELD((D_800AE8E0 + (arg1 * 0x250)), s16 *, 0x12) = (s16) arg2;
            break;
        case 17:
            M2C_FIELD((D_800AE8E0 + (arg1 * 0xAC0)), s16 *, 0x2512) = (s16) arg2;
            break;
        case 18:
            M2C_FIELD((D_800AE8E0 + (arg1 * 0x1C0)), s16 *, 0x500A) = (s16) arg2;
            break;
        case 19:
            M2C_FIELD(D_800AE8E0, s16 *, 0x5702) = (s16) arg2;
            break;
        }
        func_80023F38(arg0, arg1, 2);
    }
}

M2C_UNK func_80023F38(s32, s32, M2C_UNK);           /* extern */
s32 func_80024610(s32);                             /* extern */
s32 func_80024ADC();                                /* extern */

void func_80024C80(s32 arg0, s32 arg1) {
    s32 sp1C;

    sp1C = func_80024ADC();
    if (sp1C < func_80024610(arg0)) {
        switch (arg0) {                             /* irregular */
        case 16:
            M2C_FIELD((D_800AE8E0 + (arg1 * 0x250)), s16 *, 0x12) = (s16) (sp1C + 1);
            break;
        case 17:
            M2C_FIELD((D_800AE8E0 + (arg1 * 0xAC0)), s16 *, 0x2512) = (s16) (sp1C + 1);
            break;
        case 18:
            M2C_FIELD((D_800AE8E0 + (arg1 * 0x1C0)), s16 *, 0x500A) = (s16) (sp1C + 1);
            break;
        case 19:
            M2C_FIELD(D_800AE8E0, s16 *, 0x5702) = (s16) (sp1C + 1);
            break;
        }
        func_80023F38(arg0, arg1, 2);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_80024D88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80024D88.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80024F14; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80024F14.s")
#endif

s32 func_80025100(s8 *arg0, s32 *arg1) {
    if (arg0 != NULL) {
        *arg0 = M2C_FIELD(D_800AE8E0, s8 *, 0x7A42);
    }
    if (arg1 != NULL) {
        *arg1 = M2C_FIELD(D_800AE8E0, s32 *, 0x7A44);
    }
    return 1;
}

M2C_UNK func_80023F38(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

s32 func_80025130(s32 arg0) {
    M2C_FIELD(D_800AE8E0, s32 *, 0x7A44) = arg0;
    func_80023F38(0x14, 0, 2);
    return 1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80025168; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80025168.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800251A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800251A8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800251C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800251C8.s")
#endif

u8 func_80025214(void) {
    return M2C_FIELD(D_800AE8E0, u8 *, 0x7A43);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80025224; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80025224.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80025260; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80025260.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800253BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800253BC.s")
#endif
