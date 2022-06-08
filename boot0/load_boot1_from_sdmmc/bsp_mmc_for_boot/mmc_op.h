/*
 * (C) Copyright 2007-2012
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 *
 * Description: MMC driver for general mmc operations
 * Author: Aaron <leafy.myeh@allwinnertech.com>
 * Date: 2012-2-3 14:18:18
 */

#ifndef _MMC_OP_H_
#define _MMC_OP_H_

//物理操作
__s32 SDMMC_PhyInit(__u32 card_no, __u32 bus_width);
__s32 SDMMC_PhyExit(__u32 card_no);

__s32 SDMMC_PhyRead(__u32 start_sector, __u32 nsector, void *buf, __u32 card_no);
__s32 SDMMC_PhyWrite(__u32 start_sector, __u32 nsector, void *buf, __u32 card_no);

//逻辑操作
__s32 SDMMC_LogicalInit(__u32 card_no, __u32 card_offset, __u32 bus_width);
__s32 SDMMC_LogicalExit(__u32 card_no);

__s32 SDMMC_LogicalRead (__u32 start_sector, __u32 nsector, void *buf, __u32 card_no);
__s32 SDMMC_LogicalWrite(__u32 start_sector, __u32 nsector, void *buf, __u32 card_no);
void set_mmc_para(int smc_no,void *sdly_addr );

#endif /* _MMC_H_ */
