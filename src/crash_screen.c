/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/crash_screen.c. */

#include "global.h"
#include "string.h"
#include <PR/os_internal_thread.h>
#include "stdarg.h"
#include "crash_screen.h"
#include "memmap.h"
#include "controller.h"
#include "stdarg.h"
extern CrashScreen gCrashScreen;
extern u8 gCrashScreenCharToGlyph[128];
extern u32 gCrashScreenFont[];
extern const char* gFaultCauses[18];
extern const char* gFPCSRFaultCauses[6];
extern u16 gCrashScreenUnlockInputs[];

void crash_screen_draw_rect(s32 x, s32 y, s32 width, s32 height);
void crash_screen_draw_glyph(s32 x, s32 y, s32 glyph);
char* crash_screen_copy_to_buf(char* buffer, const char* data, size_t size);
void crash_screen_printf(s32 x, s32 y, const char* fmt, ...);
void crash_screen_sleep(s32 ms);
void crash_screen_print_fpr(s32 x, s32 y, s32 regNum, void* addr);
void crash_screen_print_fpcsr(u32 fpcsr);
OSThread* crash_screen_get_faulted_thread(void);
void crash_screen_set_draw_info(u16* frameBufPtr, u16 width, u16 height);
void crash_screen_init(void);
void crash_screen_printf_with_bg(s16 x, s16 y, const char* fmt, ...);

void crash_screen_thread_entry(UNUSED void* unused);

void crash_screen_draw_rect(s32 x, s32 y, s32 width, s32 height) {
    u16* ptr;
    s32 i;
    s32 j;

    if (gCrashScreen.width == (0x140 * 2)) {
        x <<= 1;
        y <<= 1;
        width <<= 1;
        height <<= 1;
    }

    ptr = gCrashScreen.frameBuf + gCrashScreen.width * y + x;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            *ptr = ((*ptr & 0xE738) >> 2) | 1;
            ptr++;
        }

        ptr += gCrashScreen.width - width;
    }
}

void crash_screen_draw_glyph(s32 x, s32 y, s32 glyph) {
    s32 shift = ((glyph % 5) * 6);
    const u32* data = &gCrashScreenFont[glyph / 5 * 7];
    s32 i;
    s32 j;

    if (gCrashScreen.width == SCREEN_WIDTH) {
        u16* ptr = gCrashScreen.frameBuf + (gCrashScreen.width) * y + x;

        for (i = 0; i < 7; i++) {
            u32 bit = 0x80000000U >> shift;
            u32 rowMask = *data++;

            for (j = 0; j < 6; j++) {
                *ptr++ = (bit & rowMask) ? 0xFFFF : 1;
                bit >>= 1;
            }

            ptr += gCrashScreen.width - 6;
        }
    } else if (gCrashScreen.width == (SCREEN_WIDTH * 2)) {
        u16* ptr = gCrashScreen.frameBuf + (y * 0x500) + (x * 2);

        for (i = 0; i < 7; i++) {
            u32 bit = 0x80000000U >> shift;
            u32 rowMask = *data++;

            for (j = 0; j < 6; j++) {
                u16 temp = (bit & rowMask) ? 0xFFFF : 1;

                ptr[0] = temp;
                ptr[1] = temp;
                ptr[(SCREEN_WIDTH * 2)] = temp;
                ptr[(SCREEN_WIDTH * 2) + 1] = temp;
                ptr += 2;
                bit >>= 1;
            }

            ptr += (0x9E8 / 2);
        }
    }
}

char* crash_screen_copy_to_buf(char* buffer, const char* data, size_t size) {
    return (char*)memcpy(buffer, data, size) + size;
}

void crash_screen_printf(s32 x, s32 y, const char* fmt, ...) {
    signed char* ptr;
    u32 glyph;
    s32 size;
    signed char buf[0x100];

    va_list args;
    va_start(args, fmt);

    size = _Printf(crash_screen_copy_to_buf, (char*)buf, fmt, args);

    if (size > 0) {
        ptr = buf;

        while (size > 0) {

            glyph = gCrashScreenCharToGlyph[*ptr & 0x7f];

            if (glyph != 0xff) {
                crash_screen_draw_glyph(x, y, glyph);
            }

            size--;

            ptr++;
            x += 6;
        }
    }

    va_end(args);
}

void crash_screen_sleep(s32 ms) {
    u64 cycles = OS_USEC_TO_CYCLES(ms * 1000LL); // why not just do OS_NSEC_TO_CYCLES and not multiply by 1000LL?

    osSetTime(0);
    while (osGetTime() < cycles) {}
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void crash_screen_print_fpr(s32 x, s32 y, s32 regNum, void* addr) {
    u32 bits;
    s32 exponent;

    bits = *(u32*)addr;
    exponent = ((bits & 0x7f800000U) >> 0x17) - 0x7f;
    if ((exponent >= -0x7e && exponent <= 0x7f) || bits == 0) {
        crash_screen_printf(x, y, "F%02d:%+.3e", regNum, *(f32*)addr);
    } else {
        crash_screen_printf(x, y, "F%02d:---------", regNum);
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800079D4.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void crash_screen_print_fpcsr(u32 fpcsr) {
    s32 i;
    u32 bit = 1 << 17;

    crash_screen_printf(30, 155, "FPCSR:%08XH", fpcsr);

    for (i = 0; i < 6; i++) {
        if (fpcsr & bit) {
            crash_screen_printf(132, 155, "(%s)", gFPCSRFaultCauses[i]);
            break;
        }
        bit >>= 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80007A58.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80007AE4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80007AE4.s")
#endif

OSThread* crash_screen_get_faulted_thread(void) {
    OSThread* thread = __osGetActiveQueue();

    while (thread->priority != -1) {
        if (thread->priority > 0 && thread->priority < 0x7F && (thread->flags & 3)) {
            return thread;
        }

        thread = thread->tlnext;
    }

    return NULL;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80007F74; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80007F74.s")
#endif

void crash_screen_set_draw_info(u16* frameBufPtr, u16 width, u16 height) {
    gCrashScreen.frameBuf = (u16*)((uintptr_t)frameBufPtr | 0xA0000000);
    gCrashScreen.width = width;
    gCrashScreen.height = height;
}

void crash_screen_init(void) {
    gCrashScreen.frameBuf = (u16*)(uintptr_t)((osMemSize | 0xA0000000) - ((SCREEN_WIDTH * SCREEN_HEIGHT) * 2));
    gCrashScreen.width = SCREEN_WIDTH;
    gCrashScreen.height = 16;
    osCreateMesgQueue(&gCrashScreen.queue, &gCrashScreen.mesg, 1);
    osCreateThread(&gCrashScreen.thread, 2, crash_screen_thread_entry, NULL,
                   gCrashScreen.stack + sizeof(gCrashScreen.stack), 128);
    osStartThread(&gCrashScreen.thread);
}

void crash_screen_printf_with_bg(s16 x, s16 y, const char* fmt, ...) {
    signed char* ptr;
    u32 glyph;
    s32 size;
    signed char buf[0x100];
    va_list args;

    va_start(args, fmt);

    size = _Printf(crash_screen_copy_to_buf, (char*)buf, fmt, args);

    if (size > 0) {
        crash_screen_draw_rect(x - 6, y - 6, (size + 2) * 6, 19);
        ptr = buf;

        while (size > 0) {
            glyph = gCrashScreenCharToGlyph[*ptr & 0x7F];

            if (glyph != 0xFF) {
                crash_screen_draw_glyph(x, y, glyph);
            }

            ptr++;
            size--;
            x += 6;
        }
    }

    va_end(args);
}
