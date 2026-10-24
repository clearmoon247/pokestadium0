/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/rom_device.c. */

#include "rom_device.h"
extern OSMesgQueue D_80100170;
extern OSPiHandle* D_80100188;

void Rom_DmaRead(u32 dev_addr, u32 dram_addr, u32 size);

#ifdef NON_MATCHING
/* TODO: decompile func_80046040; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80046040.s")
#endif

void Rom_DmaRead(u32 dev_addr, u32 dram_addr, u32 size) {
    OSIoMesg msg;
    u32 dev = dev_addr;
    u32 dram = dram_addr;
    s32 var_s0;

    while (size != 0) {
        if (size > 0x4000) {
            var_s0 = 0x4000;
        } else {
            var_s0 = size;
        }

        msg.hdr.pri = 0;
        msg.hdr.retQueue = &D_80100170;
        msg.dramAddr = dram;
        msg.devAddr = dev;
        msg.size = var_s0;

        osInvalDCache(msg.dramAddr, var_s0);
        osEPiStartDma(D_80100188, &msg, 0);
        osRecvMesg(&D_80100170, NULL, 1);

        dev += var_s0;
        dram += var_s0;
        size -= var_s0;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_80046170; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80046170.s")
#endif
