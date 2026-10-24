/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/util.c. */

#include "global.h"
#include "memmap.h"
#include "memory.h"
#include "util.h"
extern u32 gExpansionRAMStart;
extern MainPool** gMainPool;
void Dma_InitializeCompletionQueue(void);
s32 StageContext_IsHighResolution(void);

#include "m2c_macros.h"

uintptr_t Util_ConvertAddrToVirtAddr(uintptr_t addr);
void Util_Memcpy(u32* dest, u32* src, int size);
void* Util_Malloc(s32 size);
void Util_Free(void* ptr);
void Util_DrawRect(Gfx** dlist, s32 ulx, s32 lrx, u16 color);

/**
 * Convert any valid address to its virtual (KSEG0) counterpart.
 */
uintptr_t Util_ConvertAddrToVirtAddr(uintptr_t addr) {
    uintptr_t retaddr = NULL; // any invalid cases are treated as NULL return.

    // convert physical (in installed memory range) to virtual.
    if (addr < osMemSize) {
        retaddr = addr | 0x80000000;
        // convert segmented to virtual.
    } else if (addr < 0x10000000U) {
        retaddr = Memmap_GetSegmentVaddr(addr);
        // convert a fragment pre-relocated address to a post-relocated virtual address.
    } else if ((addr >= 0x81000000U) &&
               (addr < 0x90000000U)) { // is the address in fragment space? convert it to its post-relocated address.
        retaddr = Memmap_GetFragmentVaddr(addr);
        // pass-through addresses that are already virtual (in installed memory range)
    } else if ((addr >= 0x80000000U) && (addr < (uintptr_t)(osMemSize + 0x80000000U))) {
        retaddr = addr;
    }

    return retaddr;
}

/**
 * Copy memory from one address to the other.
 */
void Util_Memcpy(u32* dest, u32* src, int size) {
    while (size-- > 0) {
        *(dest++) = *(src++);
    }
}

M2C_UNK func_800020C0(M2C_UNK *, M2C_UNK);          /* extern */
s32 func_80002840(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80003670();                            /* extern */
extern s32 D_800A94E0;
extern M2C_UNK D_80105360;

void func_80002D58(void) {
    func_800020C0(&D_80105360, 0x80400000);
    func_80003670();
    D_800A94E0 = func_80002840(0x10000, 0);
}

/**
 * Allocate memory from the main pool.
 */
void* Util_Malloc(s32 size) {
    return mem_pool_alloc(gMainPool, size);
}

/**
 * Free a pointer being used in the main pool.
 */
void Util_Free(void* ptr) {
    mem_pool_free(gMainPool, ptr);
}

/**
 * Draws a profiler rectangle with given coordinates. Solely used by the next function
 * which facilitates the tacked on memory profiler.
 */
void Util_DrawRect(Gfx** dlist, s32 ulx, s32 lrx, u16 color) {
    s32 uly = 15;
    s32 lry = 17;
    Gfx* gfx = *dlist;

    if (StageContext_IsHighResolution() != 0) {
        ulx <<= 1;
        lrx <<= 1;
        uly <<= 1;
        lry <<= 1;
    }

    gDPPipeSync(gfx++);
    gDPSetFillColor(gfx++, color << 16 | color);
    gDPFillRectangle(gfx++, ulx, uly, lrx, lry);
    *dlist = gfx;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80002EC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80002EC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800030B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800030B0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800030EC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800030EC.s")
#endif
