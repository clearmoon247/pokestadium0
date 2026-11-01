/* Stadium Zero resident code. */

#include "global.h"

/*
 * func_80051C70
 *
 * Starts a read of the controller buttons over the serial interface (SI).
 * It has the same structure, and the same size (132 bytes), as libultra's
 * osContStartReadData(OSMesgQueue* mq) (lib/ultralib/src/io/contreaddata.c).
 * The names in brackets are the ones symbol_addrs.txt gives the same
 * addresses; func_80051D80 has no name there, and its role below is taken
 * from the libultra source and was not checked against its code.
 *
 *   1. func_80051A50 takes the SI access lock (__osSiGetAccess).
 *   2. If the byte at D_80102810 (__osContLastCmd) is not 1 (the "read
 *      buttons" command): func_80051D80 prepares the request in the PIF RAM
 *      image at D_801027D0 (__osContPifRam), func_80052CC0 with direction 1
 *      (OS_WRITE) sends it (__osSiRawStartDma), and func_8004D1C0 (osRecvMesg)
 *      then waits on the queue arg0, with flag 1 (OS_MESG_BLOCK) and no
 *      message pointer, until the transfer is done.
 *   3. func_80052CC0 with direction 0 (OS_READ) reads the PIF RAM back; its
 *      result is the return value.
 *   4. 1 is stored in D_80102810 and func_80051A94 releases the lock
 *      (__osSiRelAccess).
 */
s32 func_8004D1C0(OSMesgQueue*, OSMesg*, s32);      /* osRecvMesg */
void func_80051A50(void);                           /* __osSiGetAccess */
void func_80051A94(void);                           /* __osSiRelAccess */
void func_80051D80(void);
s32 func_80052CC0(s32, void*);                      /* __osSiRawStartDma */
extern u8 D_801027D0;                               /* __osContPifRam */
extern u8 D_80102810;                               /* __osContLastCmd */

s32 func_80051C70(OSMesgQueue* arg0) {
    s32 ret;

    func_80051A50();
    if (D_80102810 != 1) {
        func_80051D80();
        func_80052CC0(1, &D_801027D0);
        func_8004D1C0(arg0, NULL, 1);
    }
    ret = func_80052CC0(0, &D_801027D0);
    D_80102810 = 1;
    func_80051A94();
    return ret;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80051CF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80051CF4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80051D80; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80051D80.s")
#endif
