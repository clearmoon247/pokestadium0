/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libleo/leocmdex.c. */

#include "global.h"
#include "leo.h"
#include "libleo/internal.h"
#include "PR/leo.h"
extern void (*D_80079520[16])(void);
extern LEOCmdRead leo_sys_read_cmd;
extern const u8 leo_sys_form_lbas[];
u8 leoRead_system_area(void);
extern OSMesg LEOblock_que_buf[1];
extern u8* LEOwrite_pointer;
extern LEOCmd* LEOcur_command;
extern u32 LEOasic_bm_ctl_shadow;
extern u32 LEOasic_seq_ctl_shadow;
extern u8 LEOdrive_flag;
extern vu8 LEOclr_que_flag;
extern u16 LEOrw_flags;
extern u8 LEOdisk_type;

u8 leoRead_system_area(void);

#ifdef NON_MATCHING
/* TODO: decompile func_800491A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800491A0.s")
#endif

u8 leoRead_system_area(void) {
    LEOCmdRead temp_cmd;
    LEOCmd* prev_cmd;
    u32 retry_cntr;
    s32 read_mode;

    prev_cmd = LEOcur_command;
    LEOcur_command = (LEOCmd*)&temp_cmd;
    read_mode = 0;
    retry_cntr = 0;

    while (1) {
        LEOdisk_type = 0;
        // For lba_to_phys to avoid dealing with alternative tracks on the disk
        LEO_sys_data.param.defect_num[0] = 0;
        LEOrw_flags = 0x3000;
        temp_cmd = leo_sys_read_cmd;
        temp_cmd.buff_ptr = &LEO_sys_data;

        if (read_mode == 0) {
            // read System LBA 12 (+0, this is an offset value for leoRead_common)
            // see leo_sys_read_cmd premade struct
            leoRead_common(0);
            switch (temp_cmd.header.sense) {
                case LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION:
                    do {
                        // if expecting a retail disk, LBA 12 is expected to do a read error, if not then freeze
                    } while (LEO_country_code != 0);
                    retry_cntr = 0;
                    read_mode--;
                    continue;
                case LEO_SENSE_UNRECOVERED_READ_ERROR:
                    do {
                        // if expecting a development disk, LBA 12 is expected to read correctly, if not then freeze
                    } while (LEO_country_code == 0);
                    retry_cntr = 0;
                    read_mode--;
                    continue;
            }
        } else {
            // read System LBA 0,1,8,9 (or 2,3,10,11 for dev)
            temp_cmd.lba = leo_sys_form_lbas[retry_cntr & 3];
            if (LEO_country_code == 0) {
                temp_cmd.lba += 2;
            }
            leoRead_common(0);
            if (temp_cmd.header.status == LEO_STATUS_GOOD) {
                do {
                    // if disk country and set country code in libleo mismatch, then freeze
                } while (LEO_sys_data.param.country != LEO_country_code);
                break;
            }
        }
    system_retry:
        if (leoChk_err_retry(temp_cmd.header.sense) != LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
            break;
        }
        if (retry_cntr++ >= 0x40U) {
            break;
        }
        if ((retry_cntr & 7) == 0) {
            // Recalibrate drive every 8th tries
            if ((temp_cmd.header.sense = leoSend_asic_cmd_w(ASIC_RECAL, 0)) ==
                LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
                continue;
            }
            goto system_retry;
        }
    }
    LEOcur_command = prev_cmd;
    prev_cmd->header.sense = temp_cmd.header.sense;
    return prev_cmd->header.sense;
}
