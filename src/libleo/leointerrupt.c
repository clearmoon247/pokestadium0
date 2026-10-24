/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libleo/leointerrupt.c. */

#include "global.h"
#include "libleo/internal.h"
#include "PR/os_system.h"
#include "lib/ultralib/src/os/osint.h"
extern OSThread* __osRunQueue;
extern OSThread* __osPopThread(OSThread**);
extern void __osEnqueueThread(OSThread**, OSThread*);
extern OSIntMask __OSGlobalIntMask;
void __osLeoAbnormalResume(void);
void __osLeoResume(void);
extern s32 osEPiRawStartDma(OSPiHandle*, s32, u32, void*, u32);

void __osLeoAbnormalResume(void);
void __osLeoResume(void);

#ifdef NON_MATCHING
/* TODO: decompile func_8004FDC0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8004FDC0.s")
#endif

void __osLeoAbnormalResume(void) {
    __OSTranxInfo* info;
    u32 pi_stat;

    info = &__osDiskHandle->transferInfo;
    pi_stat = HW_REG(PI_STATUS_REG, u32);
    while (pi_stat & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
        pi_stat = HW_REG(PI_STATUS_REG, u32);
    }

    HW_REG(0x5000510, u32) = info->bmCtlShadow | 0x10000000;
    pi_stat = HW_REG(PI_STATUS_REG, u32);
    while (pi_stat & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
        pi_stat = HW_REG(PI_STATUS_REG, u32);
    }

    HW_REG(0x5000510, u32) = info->bmCtlShadow;
    __osLeoResume();
    HW_REG(PI_STATUS_REG, u32) = 2;
    __OSGlobalIntMask |= 0x100401;
}

void __osLeoResume(void) {
    __OSEventState* es;
    OSMesgQueue* mq;
    s32 last;

    es = &__osEventStateTab[8];
    mq = es->messageQueue;
    if ((mq == 0) || (mq->validCount >= mq->msgCount)) {
        return;
    }
    last = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[last] = es->message;
    mq->validCount++;
    if (mq->mtqueue->next != NULL) {
        __osEnqueueThread(&__osRunQueue, __osPopThread(&mq->mtqueue));
    }
}
