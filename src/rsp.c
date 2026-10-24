/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/rsp.c. */

#include "global.h"
#include "rsp.h"
#include "flash.h"
#include "util.h"
#define SRAM_START_ADDR 0x08000000
#define SRAM_SIZE 0x8000
#define SRAM_latency 0x5
#define SRAM_pulse 0x0c
#define SRAM_pageSize 0xd
#define SRAM_relDuration 0x2
extern OSThread gRspThread;
extern u8 gRspThreadStack[0x9C];
extern OSMesg D_80086F7C;
extern struct UnkStruct80083BD0 D_80087000;
extern s16 D_8008704C;

#include "m2c_macros.h"

s32 Storage_InitializeLeoManager(void);
OSPiHandle* Storage_GetSramHandle(void);
s32 Storage_ReadSram(struct UnkStruct800006C4_2* arg0);
s32 Storage_WriteSram(struct UnkStruct800006C4_2* arg0);
s32 Storage_ReadRom(struct UnkStruct800006C4_2* arg0, s32 arg1);
void* Storage_WaitForIoMessage(void);
void* Storage_ReadDisk(struct UnkStruct800006C4_2* arg0);
void* Storage_WriteDisk(struct UnkStruct800006C4_2* arg0);
void* Storage_ReadDiskId(struct UnkStruct80000A80* arg0);
void* Storage_SeekDisk(struct UnkStruct80000A80* arg0);
void* Storage_SetDiskMotor(struct UnkStruct80000A80* arg0);
void* Storage_ReadRtc(struct UnkStruct80000A80* arg0);
void* Storage_WriteRtc(struct UnkStruct80000A80* arg0);
void Storage_ResetDisk(void);
void Storage_QueueRequest(void* arg0, s32 arg1);

s32 Storage_InitializeLeoManager(void) {
    UNUSED s32 unused;
    UNUSED s32 unused2[6];
    s32 result;

    result = LeoCJCreateLeoManager(0x95, 0x96, &D_80086F7C, 0x10);
    if (result == 0) {
        if (osGetMemSize() >= 0x800000U) {
            D_8008704C = 1;
        }
    }
    D_8008704C = !result;
    return result;
}

#ifdef NON_MATCHING
// Matches the ROM, but uses bss data that is not placed in this file yet.
OSPiHandle* Storage_GetSramHandle(void) {
    static OSPiHandle sramHandle;

    void* baseAddr = OS_PHYSICAL_TO_K1(SRAM_START_ADDR);
    if (baseAddr != (void*)(uintptr_t)sramHandle.baseAddress) {
        sramHandle.type = DEVICE_TYPE_SRAM;
        sramHandle.baseAddress = (uintptr_t)baseAddr;
        sramHandle.latency = SRAM_latency;
        sramHandle.pulse = SRAM_pulse;
        sramHandle.pageSize = SRAM_pageSize;
        sramHandle.relDuration = SRAM_relDuration;

        sramHandle.domain = PI_DOMAIN2;
        sramHandle.speed = 0;
        bzero(&sramHandle.transferInfo, sizeof(sramHandle.transferInfo));
        osEPiLinkHandle(&sramHandle);
    }
    return &sramHandle;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80000628.s")
#endif

s32 Storage_ReadSram(struct UnkStruct800006C4_2* arg0) {
    OSIoMesg msg;
    OSPiHandle* handle = Storage_GetSramHandle();

    msg.hdr.pri = 0;
    msg.hdr.retQueue = &D_80087000.queue2;
    msg.dramAddr = arg0->vaddr;
    msg.devAddr = arg0->unk1C;
    msg.size = arg0->size;

    osInvalDCache(arg0->vaddr, arg0->size);
    osEPiStartDma(handle, &msg, 0);
    osRecvMesg(&D_80087000.queue2, &D_80087000.unk0, 1);
    return 0;
}

s32 Storage_WriteSram(struct UnkStruct800006C4_2* arg0) {
    OSIoMesg msg;
    OSPiHandle* handle = Storage_GetSramHandle();

    msg.hdr.pri = 0;
    msg.hdr.retQueue = &D_80087000.queue2;
    msg.dramAddr = arg0->vaddr;
    msg.devAddr = arg0->unk1C;
    msg.size = arg0->size;

    osWritebackDCache(arg0->vaddr, arg0->size);
    osEPiStartDma(handle, &msg, 1);
    osRecvMesg(&D_80087000.queue2, &D_80087000.unk0, OS_MESG_BLOCK);
    return 0;
}

s32 Storage_ReadRom(struct UnkStruct800006C4_2* arg0, s32 arg1) {
    OSIoMesg msg;
    OSPiHandle* handle;

    if (arg1 == 0) {
        handle = osCartRomInit();
    } else {
        handle = osDriveRomInit();
    }

    msg.hdr.pri = 0;
    msg.hdr.retQueue = &D_80087000.queue2;
    msg.dramAddr = arg0->vaddr;
    msg.devAddr = arg0->unk1C;
    msg.size = arg0->size;

    osInvalDCache(arg0->vaddr, arg0->size);
    osEPiStartDma(handle, &msg, 0);
    osRecvMesg(&D_80087000.queue2, &D_80087000.unk0, OS_MESG_BLOCK);
    return 0;
}

void* Storage_WaitForIoMessage(void) {
    void* msg;

    osRecvMesg(&D_80087000.queue2, &msg, OS_MESG_BLOCK);
    return msg;
}

void* Storage_ReadDisk(struct UnkStruct800006C4_2* arg0) {
    LeoReadWrite(arg0, 0, arg0->unk1C, arg0->vaddr, arg0->size, &D_80087000.queue2);
    return Storage_WaitForIoMessage();
}

void* Storage_WriteDisk(struct UnkStruct800006C4_2* arg0) {
    LeoReadWrite(arg0, 1, arg0->unk1C, arg0->vaddr, arg0->size, &D_80087000.queue2);
    return Storage_WaitForIoMessage();
}

void* Storage_ReadDiskId(struct UnkStruct80000A80* arg0) {
    LeoReadDiskID(&arg0->cmd, arg0->addr, &D_80087000.queue2);
    return Storage_WaitForIoMessage();
}

void* Storage_SeekDisk(struct UnkStruct80000A80* arg0) {
    LeoSeek(&arg0->cmd, arg0->lba, &D_80087000.queue2);
    return Storage_WaitForIoMessage();
}

void* Storage_SetDiskMotor(struct UnkStruct80000A80* arg0) {
    LeoSpdlMotor(&arg0->cmd, arg0->mode, &D_80087000.queue2);
    return Storage_WaitForIoMessage();
}

void* Storage_ReadRtc(struct UnkStruct80000A80* arg0) {
    void* temp_v0;

    LeoReadRTC(&arg0->cmd, &D_80087000.queue2);
    temp_v0 = Storage_WaitForIoMessage();
    if (temp_v0 == NULL) {
        *(LEODiskTime*)arg0->addr = arg0->cmd.data.time;
    }
    return temp_v0;
}

void* Storage_WriteRtc(struct UnkStruct80000A80* arg0) {
    LeoSetRTC(&arg0->cmd, arg0->addr, &D_80087000.queue2);
    return Storage_WaitForIoMessage();
}

#ifdef NON_MATCHING
/* TODO: decompile func_80000A58; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80000A58.s")
#endif

M2C_UNK func_80051B20(M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK *, s32); /* extern */
M2C_UNK func_80054AB0(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800567E0(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_8005C130(M2C_UNK *);                   /* extern */
extern M2C_UNK D_80084D30;
extern M2C_UNK D_80086EE0;
extern M2C_UNK D_80086EFC;
extern M2C_UNK D_80086FBC;
extern M2C_UNK D_80086FFC;
extern M2C_UNK D_80087004;
extern M2C_UNK D_8008701C;
extern M2C_UNK D_80087034;
extern M2C_UNK func_80000A58;

void func_80000C14(void) {
    func_800567E0(&D_80087034, &D_80086FFC, 1);
    func_800567E0(&D_8008701C, &D_80086FBC, 0x10);
    func_80054AB0(0x96, &D_80087004, &D_80086EFC, 0x20);
    func_80051B20(&D_80084D30, 0xA, &func_80000A58, 0, &D_80086EE0, 0x5A);
    func_8005C130(&D_80084D30);
}

void Storage_ResetDisk(void) {
    if (D_8008704C != 0) {
        LeoReset();
        D_8008704C = 0;
    }
}

void Storage_QueueRequest(void* arg0, s32 arg1) {
    if (arg1 == 1) {
        osJamMesg(&D_80087000.queue1, arg0, OS_MESG_BLOCK);
        return;
    }
    osSendMesg(&D_80087000.queue1, arg0, OS_MESG_BLOCK);
}
