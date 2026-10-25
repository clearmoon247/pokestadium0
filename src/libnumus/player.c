/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnumus/player.c. */

#include "libnumus/player.h"
#include "3D140.h"
#include "libnaudio/n_synsetpriority.h"
typedef u8* (*command_func_t)(channel_t*, u8*);
typedef u8* (*api_func_t)(u8*);
extern s32 mus_song_stop_countdown;
extern u8 mus_voice_start_immediate_mode;
extern command_func_t command_func_jumptable[];
extern api_func_t api_func_jumptable[];
extern ALPlayer plr_player;
extern ALHeap heap;
extern s32 pad_D_800FC7C8;
extern u32 max_channels;
extern channel_t* mus_channels;
extern u32 mus_vsyncs_per_second;
extern u32 mus_next_frame_time;
extern u16 mus_master_volume_effects;
extern u16 mus_master_volume_songs;
extern u32 mus_current_handle;
extern s32 mus_random_seed;
extern u8* mus_command_queue;
extern s32 mus_command_queue_size;
extern u32 mus_command_queue_max_size;
extern u8 mus_use_fixed_pan_mode;
extern u32 mus_current_frame_counter;
extern audio_voice_t* mus_voices;
extern audio_voice_t* mus_free_voice_1;
extern audio_voice_t* mus_free_voice_2;
extern audio_voice_t* mus_releasing_voice_3;
extern audio_voice_t* mus_releasing_voice_4;
extern ALHeap* audio_heap;
extern u32 mus_num_vvoices;
extern s32 mus_free_voices_count;
extern s32 mus_releasing_voices_count;

#include "m2c_macros.h"

u8* Audio_EnableVoiceVelocityFromStream(channel_t* cp, u8* ptr);
u8* Audio_DisableVoiceVelocityFromStream(channel_t* cp, u8* ptr);
u8* Audio_DisableVoicePeriodicPitchModulation(channel_t* cp, u8* ptr);
u8* Audio_SkipVoiceCommandWord(UNUSED channel_t* cp, u8* ptr);
u8* Audio_SkipVoiceCommandByte(UNUSED channel_t* cp, u8* ptr);
void Audio_RelocateSoundBankWrapper(s32 arg0, s32 arg1);
f32 Audio_ExpApproximation(f32 arg0);
void Audio_RelocateSoundBank(u8* arg0, s32 arg1);
s32 Audio_RandomScale(s32 arg0);
void Audio_FillBytes(u8* arg0, u8 arg1, u32 arg2);
void Audio_RelocatePointerArray(u8* arg0, u32 arg1, u32 arg2);

s32 func_80036640(s8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x84) = 0;
    M2C_FIELD(arg0, s16 *, 0xB2) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    return 0;
}

u8* Audio_SetVoiceSampleIndex(channel_t* cp, u8* ptr) {
    u16 wave = *ptr++;

    if (wave & 0x80) {
        wave = (wave & 0x7F) << 8;
        wave |= *ptr++;
    }

    cp->wave = wave;
    return ptr;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80036698; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80036698.s")
#endif

s32 func_800366BC(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0xC6) = 0;
    return arg1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_800366C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800366C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80036818; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80036818.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800368E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800368E4.s")
#endif

u8* Audio_SetVoiceFixedDuration(channel_t* cp, u8* ptr) {
    s16 tmp = *ptr++ << 8;

    tmp |= *ptr++;

    cp->cutoff = tmp;
    cp->endit = 0;

    return ptr;
}

u8* Audio_EnableVoiceVibrato(channel_t* cp, u8* ptr) {
    cp->vib_delay = *ptr++;
    cp->vib_speed = *ptr++;
    cp->vib_amount = (f32)*ptr++ / 50.0;
    return ptr;
}

u8* Audio_EnableVoiceVibratoDown(channel_t* cp, u8* ptr) {
    cp->vib_delay = *ptr++;
    cp->vib_speed = *ptr++;
    cp->vib_amount = -(f32)*ptr++ / 50.0;

    return ptr;
}

s32 func_800369DC(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0xE8) = 0;
    M2C_FIELD(arg0, f32 *, 0x78) = 0.0f;
    return arg1;
}

u8* Audio_SetVoiceDurationOverride(channel_t* cp, u8* ptr) {
    u8 value = *ptr++;

    if (value < 0x80) {
        cp->fixed_length = value;
    } else {
        cp->fixed_length = (value & 0x7F) << 8;
        cp->fixed_length += *ptr++;
    }
    return ptr;
}

s32 func_80036A34(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0xC5) = 1;
    return arg1;
}

s8 *func_80036A44(s8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, u8 *, 0xC7) = (u8) *arg1;
    return arg1 + 1;
}

s32 func_80036A54(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0xC8) = 1;
    return arg1;
}

u8* Audio_SetVoiceFinePitch(channel_t* cp, u8* ptr) {
    s32 value = *ptr++;

    if (value & 0x80) {
        value |= ~0xFF;
    }
    cp->freqoffset -= cp->distort;
    cp->distort = (f32)value / 100.0;
    cp->freqoffset += cp->distort;
    return ptr;
}

u8* Audio_SetVoiceEnvelopeFromTable(channel_t* cp, u8* ptr) {
    s32 value = *ptr++;

    if (value & 0x80) {
        value = (value & 0x7F) << 8;
        value |= *ptr++;
    }

    Audio_SetVoiceVolumeEnvelope(cp, (u8*)&cp->song_addr->env_table[value]);
    return ptr;
}

u8* Audio_EnableVoiceVelocityFromStream(channel_t* cp, u8* ptr) {
    cp->velocity_on = 1;
    return ptr;
}

u8* Audio_DisableVoiceVelocityFromStream(channel_t* cp, u8* ptr) {
    cp->velocity_on = 0;
    return ptr;
}

s32 func_80036B44(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0xEA) = 1;
    return arg1;
}

s32 func_80036B54(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0xEA) = 0;
    return arg1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80036B60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80036B60.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80036C4C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80036C4C.s")
#endif

s8 *func_80036D04(s8 *arg0, s8 *arg1) {
    M2C_FIELD(arg0, u8 *, 0xEB) = (u8) M2C_FIELD(arg1, u8 *, 0);
    M2C_FIELD(arg0, u8 *, 0xE1) = (u8) M2C_FIELD(arg1, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 0xE2) = (u8) M2C_FIELD(arg1, u8 *, 2);
    return arg1 + 3;
}

s32 func_80036D24(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0xE1) = 0;
    return arg1;
}

s32 func_80036D30(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0xE5) = 1;
    return arg1;
}

u8* Audio_DisableVoicePeriodicPitchModulation(channel_t* cp, u8* ptr) {
    cp->wobble_on_speed = 0;
    return ptr;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80036D4C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80036D4C.s")
#endif

s8 *func_80036D60(s8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, s8 *, 0xCB) = (s8) ((s32) *arg1 / 2);
    return arg1 + 1;
}

u8* Audio_SkipVoiceCommandWord(UNUSED channel_t* cp, u8* ptr) {
    ptr++;
    ptr++;
    return ptr;
}

u8* Audio_SetVoiceSubEnvelopePointer(channel_t* cp, u8* ptr) {
    u8* addr = (u8*)&cp->song_addr->num_channels + cp->song_addr->drum_table[*ptr++];

    cp->pdrums = addr;
    return ptr;
}

s32 func_80036DB4(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
    return arg1;
}

u8* Audio_SkipVoiceCommandByte(UNUSED channel_t* cp, u8* ptr) {
    #ifdef _AUDIODEBUG
        osSyncPrintf("PLAYER_COMMANDS.C: Audio_SkipVoiceCommandByte -  %d (channel frame=%d)\n", *ptr++,  cp->channel_frame);
        return ptr;
    #else
        ptr++;
        return ptr;
    #endif
}

#ifdef NON_MATCHING
/* TODO: decompile func_80036DCC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80036DCC.s")
#endif

s8 *func_80036E30(s8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, u8 *, 0xDE) = (u8) *arg1;
    return arg1 + 1;
}

u8* Audio_SetRandomVoiceDetune(channel_t* cp, u8* ptr) {
    cp->transpose = Audio_RandomScale(*ptr++);
    cp->transpose += *ptr++;
    return ptr;
}

u8* Audio_SetRandomVoiceVolume(channel_t* cp, u8* ptr) {
    cp->volume = Audio_RandomScale(*ptr++);
    cp->volume += *ptr++;
    return ptr;
}

u8* func_80036EE0(channel_t* cp, u8* ptr) {
    M2C_FIELD(cp, u8*, 0xCB) = Audio_RandomScale(*ptr++);
    M2C_FIELD(cp, u8*, 0xCB) += *ptr++;
    return ptr;
}

s8 *func_80036F30(s8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, u8 *, 0xCA) = (u8) *arg1;
    return arg1 + 1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80036F40; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80036F40.s")
#endif

u8* Audio_SetVoiceVolumeScale(channel_t* cp, u8* ptr) {
    cp->bendrange = (f32)*ptr++ * 0.015625;
    cp->pitchbend_calc = SQ(cp->pitchbend);
    return ptr;
}

u8* Audio_SetVoicePanModulation(channel_t* cp, u8* ptr) {
    M2C_FIELD(cp, u8*, 0xE7) = *ptr++;
    if (!M2C_FIELD(cp, u8*, 0xE7)) {
        M2C_FIELD(cp, u16*, 0xBC) = 0x80;
    }
    return ptr;
}

#ifdef NON_MATCHING
/* TODO: decompile func_800370AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800370AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800371A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800371A4.s")
#endif

extern s16 D_800B3654;
extern s16 D_800B3656;
void func_800374E0(s32 arg0, s32 arg1) {
    if (arg0 & 1) {
        D_800B3654 = arg1;
    }
    if (arg0 & 2) {
        D_800B3656 = arg1;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_80037508; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80037508.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800376E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800376E8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80037828; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80037828.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003798C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003798C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80037A48; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80037A48.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80037AC4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80037AC4.s")
#endif

s32 func_80037B7C(s32 handle) {
    channel_t* cp;
    s32 i;
    s32 count;
    u32 mask;

    if (handle == 0) {
        return 0;
    }

    mask = osSetIntMask(1);

    for (i = 0, count = 0, cp = mus_channels; i < (s32)max_channels; i++, cp++) {
        if (handle == cp->handle) {
            count++;
        }
    }

    osSetIntMask(mask);

    return count;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80037C04; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80037C04.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80037CA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80037CA4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80037D4C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80037D4C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80037DF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80037DF4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80037E84; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80037E84.s")
#endif

void Audio_RelocateSoundBankWrapper(s32 arg0, s32 arg1) {
    Audio_RelocateSoundBank(arg0, arg1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80037F68; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80037F68.s")
#endif

M2C_UNK func_800376E8(M2C_UNK);                     /* extern */
extern s8 *D_800B3664;
extern s8 *D_800B3668;

void func_80037FCC(s8 *arg0, M2C_UNK arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, s32 *, 0x10) & 1)) {
        D_800B3664 = arg0;
    }
    func_800376E8(arg1);
    D_800B3664 = D_800B3668;
}

M2C_UNK func_80037828(s32, s32, s32, s32, s32);     /* extern */
extern s8 *D_800B3664;
extern s8 *D_800B3668;

void func_80038014(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, s32 *, 0x10) & 1)) {
        D_800B3664 = arg0;
    }
    func_80037828(arg1, arg2, arg3, arg4, arg5);
    D_800B3664 = D_800B3668;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8003807C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003807C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800380D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800380D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003815C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003815C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003821C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003821C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8003834C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003834C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800383DC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800383DC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800384D8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800384D8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80038588; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80038588.s")
#endif

s32 func_8004D300(s32);                             /* extern */
extern s32 D_800B3638;
extern s8 *D_800B3640;

s32 func_800386E4(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s8 *var_s0;

    if (arg0 == 0) {
        return 0;
    }
    if (arg1 != 0) {
        var_s3 = arg1;
    } else {
        var_s3 = 1;
    }
    var_s0 = D_800B3640;
    var_s1 = 0;
    var_s2 = 0;
    if (D_800B3638 > 0) {
        do {
            temp_a0 = func_8004D300(1);
            if (arg0 == M2C_FIELD(var_s0, s32 *, 0x5C)) {
                M2C_FIELD(var_s0, s32 *, 0x38) = arg1;
                M2C_FIELD(var_s0, s32 *, 0x3C) = var_s3;
                var_s2 += 1;
            }
            func_8004D300(temp_a0);
            var_s1 += 1;
            var_s0 += 0x148;
        } while (var_s1 < D_800B3638);
    }
    return var_s2;
}

#ifdef NON_MATCHING
/* TODO: decompile func_800387BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800387BC.s")
#endif

s32 func_8004D300(s32);                             /* extern */
extern s8 D_8007754C;
extern s32 D_800B3CD0;

void func_80038880(void) {
    s32 temp_v0;

    temp_v0 = func_8004D300(1);
    D_8007754C = 0;
    D_800B3CD0 = 1;
    func_8004D300(temp_v0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_800388BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800388BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80039010; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80039010.s")
#endif

s32 Audio_ComputeVoiceVolume(channel_t* cp) {
    u32 volume = cp->volume * cp->env_current_vol * cp->velocity * cp->volume_scale;

    volume >>= 0xD;
    if (volume >= 0x8000) {
        volume = 0x7FFF;
    }

    if (cp->IsFX == 0) {
        volume *= mus_master_volume_songs;
    } else {
        volume *= mus_master_volume_effects;
    }

    volume >>= 0xF;

    if (cp->duration != -1) {
        volume = (cp->duration * volume) / cp->duration_scale;
    }

    return volume;
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
f32 Audio_AdvanceVoicePitch(channel_t* arg0, f32 offset) {
    f32 temp_fv1;
    f32 var_fv1;
    f32 var_fv1_2;
    s32 temp_lo;

    temp_fv1 = arg0->base_note;
    if (arg0->port != 0) {
        if (arg0->port >= arg0->wobble_frame) {
            var_fv1_2 = ((temp_fv1 - arg0->last_note) / arg0->port);
            var_fv1_2 *= arg0->wobble_frame;
            temp_fv1 = arg0->last_note + var_fv1_2;
        }
        arg0->port_base = temp_fv1;
    }

    temp_lo = arg0->transpose * (1 - arg0->ignore_transpose);

    arg0->ignore_transpose = 0;

    temp_fv1 += (offset + arg0->pitchbend_calc + temp_lo);
    if (temp_fv1 == arg0->pitch_current) {
        return 0.0f;
    }
    arg0->pitch_current = temp_fv1;

    temp_fv1 = Audio_ExpApproximation(temp_fv1 * 0.0833333333333333287);
    if (temp_fv1 > 2.0) {
        temp_fv1 = 2.0f;
        arg0->velocity = 0;
    }

    return temp_fv1;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800393F8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80039530; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80039530.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800395D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800395D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80039A44; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80039A44.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80039A60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80039A60.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80039B2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80039B2C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80039B7C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80039B7C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80039C10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80039C10.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80039D08; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80039D08.s")
#endif

f32 Audio_ExpApproximation(f32 arg0) {
    f32 temp_fa1;
    f32 temp_fv1;

    if (arg0 == 0.0f) {
        return 1.0f;
    }

    if (arg0 > 0.0f) {
        temp_fv1 = SQ(arg0);
        temp_fa1 = SQ(temp_fv1);
        return (arg0 * 0.693147180559944953) + 1.0 + (temp_fv1 * 0.240226506959100999) +
               ((temp_fv1 * arg0) * 0.055504108664821597) + (temp_fa1 * 0.00961812910762848035) +
               ((temp_fa1 * arg0) * 0.00133335581464283999) + ((temp_fa1 * temp_fv1) * 0.000154035303933816006);
    } else {
        arg0 = -arg0;
        temp_fv1 = SQ(arg0);
        temp_fa1 = SQ(temp_fv1);
        return 1.0 / ((arg0 * 0.693147180559944953) + 1.0 + (temp_fv1 * 0.240226506959100999) +
                      ((temp_fv1 * arg0) * 0.055504108664821597) + (temp_fa1 * 0.00961812910762848035) +
                      ((temp_fa1 * arg0) * 0.00133335581464283999) + ((temp_fa1 * temp_fv1) * 0.000154035303933816006));
    }
}

void Audio_RelocateSoundBank(u8* arg0, s32 arg1) {
    UNUSED s32 pad;
    u32 i;
    f32 var_fv0;
    SoundBank* soundbank = arg0;
    u8 temp_v1;

    if (soundbank->flags & 1) {
        return;
    }

    soundbank->flags |= 1;

    Audio_RelocatePointerArray(&soundbank->basenote, arg0, 3);
    Audio_RelocatePointerArray(soundbank->wave_list, arg0, soundbank->count);

    for (i = 0; i < soundbank->count; i++) {
        f32* ptr = &soundbank->detune[i];

        temp_v1 = *(u8*)ptr;
        if (temp_v1 & 0x80) {
            var_fv0 = -(0x100 - temp_v1);
        } else {
            var_fv0 = (s32)temp_v1;
        }
        *ptr = var_fv0 / 100.0;

        temp_v1 = soundbank->basenote[i] - 0x30;
        if (temp_v1 & 0x80) {
            var_fv0 = -(0x100 - temp_v1);
        } else {
            var_fv0 = (s32)temp_v1;
        }
        *ptr += var_fv0;

        if (soundbank->wave_list[i]->flags == 0) {
            u32 tmp = soundbank->wave_list[i]->base;

            if ((tmp & 0xFF000000) != 0xFF000000) {
                tmp += arg1;
                soundbank->wave_list[i]->base = tmp;
            }

            soundbank->wave_list[i]->flags = 1;

            if (soundbank->wave_list[i]->waveInfo.rawWave.loop != NULL) {
                soundbank->wave_list[i]->waveInfo.rawWave.loop =
                    (u32)soundbank + (u32)soundbank->wave_list[i]->waveInfo.rawWave.loop;
            }

            if (soundbank->wave_list[i]->type == AL_ADPCM_WAVE) {
                soundbank->wave_list[i]->waveInfo.adpcmWave.book =
                    (u32)soundbank + (u32)soundbank->wave_list[i]->waveInfo.adpcmWave.book;
            }
        }
    }

    osWritebackDCacheAll();
}

s32 Audio_RandomScale(s32 arg0) {
    s32 i;
    s32 tmp;
    f32 tmpf;

    for (i = 0; i < 8; i++) {
        tmp = mus_random_seed & 0x48000000;
        mus_random_seed <<= 1;
        if ((tmp == 0x48000000) || (tmp == 0x08000000)) {
            mus_random_seed |= 1;
        }
    }

    tmpf = mus_random_seed / 65536.0f;
    tmpf /= 65536.0f;
    return arg0 * tmpf;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8003A2B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003A2B8.s")
#endif

s32 func_8004D300(s32);                             /* extern */
extern s8 *D_800B3640;

u32 func_8003A4A8(s32 arg0, M2C_UNK arg1) {
    s32 temp_a0;
    s32 var_s2;
    u32 var_s1;
    s8 *var_s0;

    var_s2 = 0;
    var_s0 = D_800B3640;
    var_s1 = 0;
    if (D_800B3638 != 0) {
loop_2:
        temp_a0 = func_8004D300(1);
        if (M2C_FIELD(var_s0, s32 *, 0x30) == 0) {
            M2C_FIELD(var_s0, s32 *, 0x30) = -1;
            var_s2 = 1;
        }
        func_8004D300(temp_a0);
        if (var_s2 != 0) {
            return var_s1;
        }
        var_s1 += 1;
        var_s0 += 0x148;
        if (var_s1 >= (u32) D_800B3638) {
            goto block_7;
        }
        goto loop_2;
    }
block_7:
    return -1U;
}

void Audio_FillBytes(u8* arg0, u8 arg1, u32 arg2) {
    u8* a0 = arg0;

    while (arg2--) {
        *a0++ = arg1;
    }
}

void Audio_RelocatePointerArray(u8* arg0, u32 arg1, u32 arg2) {
    u32* ptr = arg0;
    u32 i;

    for (i = 0; i < arg2; i++) {
        if (ptr[i] != 0) {
            ptr[i] += arg1;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8003A638; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003A638.s")
#endif
