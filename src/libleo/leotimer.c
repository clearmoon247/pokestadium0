/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libleo/leotimer.c. */

#include "global.h"
#include "libleo/internal.h"
extern const u8 ymdupper[6];
extern const u8 dayupper[13];

void leoReadTimer(void);
void leoSetTimer(void);

u8 __locReadTimer(__LOCTime* time);
u8 __locSetTimer(__LOCTime* time);

void leoReadTimer(void) {
    UNUSED u8* rdparam;
    UNUSED u8 data[4];
    __LOCTime time;
    u8 sense_code = __locReadTimer(&time);
    LEOcur_command->data.time.yearlo = time.year;
    LEOcur_command->data.time.month = time.month;
    LEOcur_command->data.time.day = time.day;
    LEOcur_command->data.time.hour = time.hour;
    LEOcur_command->data.time.minute = time.minute;
    LEOcur_command->data.time.second = time.second;
    if (sense_code != 0) {
        LEOcur_command->header.sense = sense_code;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if ((u8)LEOcur_command->data.time.yearlo >= 0x96U) {
        LEOcur_command->data.time.yearhi = 0x19;
    } else {
        LEOcur_command->data.time.yearhi = 0x20;
    }
    LEOcur_command->header.status = 0;
}

void leoSetTimer(void) {
    UNUSED LEOCmdReadTimer rd_timer;
    u8* p_tmp = &LEOcur_command->data.time.yearlo;
    u32 year;
    u32 month;
    u32 temp;
    u32 ymd;
    u8 result;
    __LOCTime time;

    // Verify values (if they're correct BCD or within limits)

    for (ymd = 0; ymd < 6; ymd++) {
        temp = *p_tmp;

        // Verify right nybble (only right nybble for some reason)
        if ((temp & 0xF) > 9) {
            // nybble is above 0x9 therefore the BCD value is invalid
            LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
            LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
            return;
        }

        // Convert BCD value to binary value
        temp = temp - ((temp >> 4) * 6);

        switch (ymd) {
            case 2:
                // Day value check
                if ((dayupper[month] < temp) && ((temp != 0x1D) || (year & 3))) {
                    LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    return;
                }
            case 1:
                // Month value cannot be 0
                if (temp == 0) {
                    LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    return;
                }
            default:
                // Verify max value of each time info
                if (ymdupper[ymd] < temp) {
                    LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    return;
                }
        }

        year = month;
        month = temp;
        p_tmp++;
    }

    // Every value has been ymd good, now set the values in hardware

    // Prepare the time info to use
    time.year = LEOcur_command->data.time.yearlo;
    time.month = LEOcur_command->data.time.month;
    time.day = LEOcur_command->data.time.day;
    time.hour = LEOcur_command->data.time.hour;
    time.minute = LEOcur_command->data.time.minute;
    time.second = LEOcur_command->data.time.second;

    // Set the new time
    result = __locSetTimer(&time);
    if (result != 0) {
        LEOcur_command->header.sense = result;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    // Get the time
    result = __locReadTimer(&time);
    if (result != 0) {
        LEOcur_command->header.sense = result;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    // Check if the time is set correctly
    if ((time.year != LEOcur_command->data.time.yearlo) || (time.month != LEOcur_command->data.time.month) ||
        (time.day != LEOcur_command->data.time.day) || (time.hour != LEOcur_command->data.time.hour) ||
        (time.minute != LEOcur_command->data.time.minute) || (time.second != LEOcur_command->data.time.second)) {
        LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    LEOcur_command->header.status = LEO_STATUS_GOOD;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8004C7B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8004C7B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8004C924; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8004C924.s")
#endif
