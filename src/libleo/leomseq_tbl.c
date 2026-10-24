/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libleo/leomseq_tbl.c. */

#include "global.h"
#include "libleo/internal.h"
extern vu16 LEOrw_flags;
extern u32 mseq_tbl[0x10];
extern const u32 rd_mseq_code[0x10];
extern const u32 wt_mseq_code[0x10];

void leoSet_mseq(u16 rwmode);

void leoSet_mseq(u16 rwmode) {
    u32* tbl;
    u32 sct_byte_x;
    u32 sct_byte_u;
    u8 i;
    LEOasic_seq_ctl_shadow &= 0xBFFFFFFF;
    osEPiWriteIo(LEOPiInfo, LEO_SEQ_STATUS, LEOasic_seq_ctl_shadow);
    if (rwmode == 1) {
        tbl = wt_mseq_code;
    } else {
        tbl = rd_mseq_code;
    }
    for (i = 0; i < 0x10; i++, tbl++) {
        mseq_tbl[i] = *tbl;
    }

    sct_byte_x = sct_byte_u = LEOtgt_param.sec_bytes - 1;
    sct_byte_u += 7;
    sct_byte_x <<= 8;
    mseq_tbl[4] |= sct_byte_x;

    osWritebackDCache(mseq_tbl, 0x40);
    LEOPiDmaParam.dramAddr = mseq_tbl;
    LEOPiDmaParam.devAddr = LEO_RAM_ADDR;
    LEOPiDmaParam.size = 0x40;
    LEOPiInfo->transferInfo.cmdType = 2;
    osEPiStartDma(LEOPiInfo, &LEOPiDmaParam, 1);
    osRecvMesg(&LEOdma_que, NULL, 1);
    osEPiWriteIo(LEOPiInfo, LEO_SEC_BYTE, (sct_byte_u | 0x5900) << 0x10);

    if (LEOrw_flags & 0x800) {
        sct_byte_x += 0x100;
    }
    osEPiWriteIo(LEOPiInfo, LEO_HOST_SECBYTE, sct_byte_x << 8);
    LEOasic_seq_ctl_shadow |= LEO_STATUS_DATA_REQUEST;
    osEPiWriteIo(LEOPiInfo, LEO_SEQ_CTL, LEOasic_seq_ctl_shadow);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8004BA70; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8004BA70.s")
#endif
