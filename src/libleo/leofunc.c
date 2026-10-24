/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libleo/leofunc.c. */

#include "global.h"
#include "libleo/internal.h"
#include "PR/os_message.h"
extern const u8 LEO_ZERO_MESG[];
extern s32 __leoResetCalled;
extern s32 __leoQueuesCreated;
extern OSMesgQueue LEOpost_que;
extern OSMesg LEOpost_que_buf[1];
extern leo_sys_form LEO_sys_data;
extern OSThread LEOcommandThread;
extern OSThread LEOinterruptThread;
extern u8 LEOinterruptThreadStack[0x400];
extern u8 LEOcommandThreadStack[0x400];
extern OSMesgQueue LEOcommand_que;
extern OSMesgQueue LEOevent_que;
extern OSMesgQueue LEOcontrol_que;
extern OSMesgQueue LEOdma_que;
extern OSMesgQueue LEOblock_que;
extern OSMesg LEOevent_que_buf[1];
extern OSMesg LEOcontrol_que_buf[1];
extern OSMesg LEOdma_que_buf[2];

#include "m2c_macros.h"

s32 __leoSetReset(void);
s32 LeoResetClear(void);

M2C_UNK func_8004CFB0(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80051B20(M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK *, s32); /* extern */
M2C_UNK func_800552D0(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800567E0(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_8005C130(M2C_UNK *);                   /* extern */
extern M2C_UNK D_80100190;
extern M2C_UNK D_801001A8;
extern M2C_UNK D_80100298;
extern M2C_UNK D_80100448;
extern M2C_UNK D_801009F8;
extern M2C_UNK D_80100DF8;
extern M2C_UNK D_80100E10;
extern M2C_UNK D_80100E28;
extern M2C_UNK D_80100E40;
extern M2C_UNK D_80100E58;
extern M2C_UNK D_80100E70;
extern M2C_UNK D_80100E74;
extern M2C_UNK D_80100E78;
extern M2C_UNK D_80100E80;
extern M2C_UNK func_800487A0;
extern M2C_UNK func_800491A0;

void func_800483E0(s32 arg0, s32 arg1, M2C_UNK *arg2, M2C_UNK arg3) {
    func_800567E0(&D_80100DF8, arg2, arg3);
    func_800567E0(&D_80100E28, &D_80100E74, 1);
    func_800567E0(&D_80100E10, &D_80100E70, 1);
    func_800567E0(&D_80100E40, &D_80100E78, 2);
    func_800567E0(&D_80100E58, &D_80100E80, 1);
    func_800567E0(&D_80100190, &D_801001A8, 1);
    func_80051B20(&D_80100298, 1, &func_800491A0, 0, &D_801009F8, arg0);
    func_8005C130(&D_80100298);
    func_80051B20(&D_80100448, 1, &func_800487A0, 0, &D_80100DF8, arg1);
    func_8005C130(&D_80100448);
    func_800552D0(2, &D_80100E10, 0x30000);
    func_8004CFB0(&D_80100E58, 0, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80048530; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80048530.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80048650; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80048650.s")
#endif

s32 __leoSetReset(void) {
    leoDrive_reset();
    return 0;
}

s32 LeoResetClear(void) {
    LEOCmdHeader resetclear;

    resetclear.command = 0xF;
    resetclear.control = LEO_CONTROL_POST;
    resetclear.status = 0;
    resetclear.post = &LEOpost_que;
    if (osSendMesg(&LEOcommand_que, &resetclear.command, 0) != 0) {
        return LEO_SENSE_QUEUE_FULL;
    }
    osRecvMesg(&LEOpost_que, NULL, 1);
    if (resetclear.status == LEO_STATUS_GOOD) {
        return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
    }
    return resetclear.sense;
}
