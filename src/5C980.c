/* Stadium Zero resident code. */

#include "global.h"

extern OSDevMgr D_80079370;
extern u32 D_8007938C;
extern OSThread D_80104100;
extern u8 D_801042B0[];
extern OSMesgQueue D_801052B0;
extern OSMesg D_801052C8[5];
extern OSIoMesg D_801052E0;
extern OSIoMesg D_801052F8;
void __osTimerServicesInit(void);
void func_80058980(void);
void func_8005BF00(void*);
void func_8005BD80(OSPri pri) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (D_80079370.active) {
        return;
    }
    __osTimerServicesInit();
    D_8007938C = 0;
    osCreateMesgQueue(&D_801052B0, D_801052C8, 5);
    D_801052E0.hdr.type = OS_MESG_TYPE_VRETRACE;
    D_801052E0.hdr.pri = OS_MESG_PRI_NORMAL;
    D_801052E0.hdr.retQueue = NULL;
    D_801052F8.hdr.type = OS_MESG_TYPE_COUNTER;
    D_801052F8.hdr.pri = OS_MESG_PRI_NORMAL;
    D_801052F8.hdr.retQueue = NULL;
    osSetEventMesg(OS_EVENT_VI, &D_801052B0, &D_801052E0);
    osSetEventMesg(OS_EVENT_COUNTER, &D_801052B0, &D_801052F8);
    oldPri = -1;
    myPri = osGetThreadPri(NULL);

    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }

    savedMask = __osDisableInt();
    D_80079370.active = TRUE;
    D_80079370.thread = &D_80104100;
    D_80079370.cmdQueue = &D_801052B0;
    D_80079370.evtQueue = &D_801052B0;
    D_80079370.acsQueue = NULL;
    D_80079370.dma = NULL;
    D_80079370.edma = NULL;
    osCreateThread(&D_80104100, 0, func_8005BF00, &D_80079370, &D_801042B0[0x1000], pri);
    func_80058980();
    osStartThread(&D_80104100);
    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8005BF00; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8005BF00.s")
#endif
