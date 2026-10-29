/* Stadium Zero resident code (next to libultra io/piacs.c). */

#include "global.h"

extern OSDevMgr __osPiDevMgr;
extern u32 __osPiAccessQueueEnabled;
extern OSThread D_80102CB0;
extern OSMesgQueue D_80103E60;
extern OSMesg D_80103E78[1];
extern OSMesgQueue D_80103E88;
void func_80054C2C(void);
void __osPiCreateAccessQueue(void);
s32 func_800551F0(s32, u32, void*, u32);
s32 func_800574C0(OSPiHandle*, s32, u32, void*, u32);
void func_80054D60(void*);
void func_80054AB0(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (__osPiDevMgr.active) {
        return;
    }
    func_80054C2C();
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&D_80103E60, D_80103E78, 1);

    if (!__osPiAccessQueueEnabled) {
        __osPiCreateAccessQueue();
    }

    osSetEventMesg(OS_EVENT_PI, &D_80103E60, (OSMesg)0x22222222);
    oldPri = -1;
    myPri = osGetThreadPri(NULL);

    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }

    savedMask = __osDisableInt();
    __osPiDevMgr.active = 1;
    __osPiDevMgr.thread = &D_80102CB0;
    __osPiDevMgr.cmdQueue = cmdQ;
    __osPiDevMgr.evtQueue = &D_80103E60;
    __osPiDevMgr.acsQueue = &D_80103E88;
    __osPiDevMgr.dma = func_800551F0;
    __osPiDevMgr.edma = func_800574C0;
    osCreateThread(&D_80102CB0, 0, func_80054D60, &__osPiDevMgr, &D_80103E60, pri);
    osStartThread(&D_80102CB0);
    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_80054C2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80054C2C.s")
#endif
