#include <MDR_1923KX028_M2_Defs.h>

const uint32_t MDR_KX028_AxiAddrEMAC[KX028_EMAC_NUMS] =
{
    AXI_EMAC1_BASE_ADDR,
    AXI_EMAC2_BASE_ADDR,
    AXI_EMAC3_BASE_ADDR,
    AXI_EMAC4_BASE_ADDR,
    AXI_EMAC5_BASE_ADDR,
    AXI_EMAC6_BASE_ADDR,
    AXI_EMAC7_BASE_ADDR,
    AXI_EMAC8_BASE_ADDR,
    AXI_EMAC9_BASE_ADDR,
    AXI_EMAC10_BASE_ADDR,
    AXI_EMAC11_BASE_ADDR,
    AXI_EMAC12_BASE_ADDR,
    AXI_EMAC13_BASE_ADDR,
    AXI_EMAC14_BASE_ADDR,
    AXI_EMAC15_BASE_ADDR,
    AXI_EMAC16_BASE_ADDR
};

const uint32_t MDR_KX028_AxiAddrEGPI[KX028_EMAC_NUMS] =
{
    AXI_EGPI1_BASE_ADDR,
    AXI_EGPI2_BASE_ADDR,
    AXI_EGPI3_BASE_ADDR,
    AXI_EGPI4_BASE_ADDR,
    AXI_EGPI5_BASE_ADDR,
    AXI_EGPI6_BASE_ADDR,
    AXI_EGPI7_BASE_ADDR,
    AXI_EGPI8_BASE_ADDR,
    AXI_EGPI9_BASE_ADDR,
    AXI_EGPI10_BASE_ADDR,
    AXI_EGPI11_BASE_ADDR,
    AXI_EGPI12_BASE_ADDR,
    AXI_EGPI13_BASE_ADDR,
    AXI_EGPI14_BASE_ADDR,
    AXI_EGPI15_BASE_ADDR,
    AXI_EGPI16_BASE_ADDR
};

const uint32_t MDR_KX028_AxiAddrETGPI[KX028_EMAC_NUMS] =
{
    AXI_ETGPI1_BASE_ADDR,
    AXI_ETGPI2_BASE_ADDR,
    AXI_ETGPI3_BASE_ADDR,
    AXI_ETGPI4_BASE_ADDR,
    AXI_ETGPI5_BASE_ADDR,
    AXI_ETGPI6_BASE_ADDR,
    AXI_ETGPI7_BASE_ADDR,
    AXI_ETGPI8_BASE_ADDR,
    AXI_ETGPI9_BASE_ADDR,
    AXI_ETGPI10_BASE_ADDR,
    AXI_ETGPI11_BASE_ADDR,
    AXI_ETGPI12_BASE_ADDR,
    AXI_ETGPI13_BASE_ADDR,
    AXI_ETGPI14_BASE_ADDR,
    AXI_ETGPI15_BASE_ADDR,
    AXI_ETGPI16_BASE_ADDR
};


#define BUFFERS_WATERMARK_AFULL       0x40

MDR_KX028_AddrData_t sw_hwreg_settings[] = {
    // BMU1 cfg
    { AXI_BMU1_BASE_ADDR + AXI_BMU_CTRL,           AXI_BMU_CTRL_RESET_Msk },        //{ 0x00100004, 0x00000002 },
    { AXI_BMU1_BASE_ADDR + AXI_BMU_UCAST_CONFIG,   AXI_BMU_UCAST_BUF_CNT_MAX },     //{ 0x00100008, 0x00000800 },
    { AXI_BMU1_BASE_ADDR + AXI_BMU_UCAST_BASEADDR, CBUS_BASE_ADDR | AXI_LMEM0_BASE_ADDR },  //{ 0x0010000C, 0xC0200000 }, //LMEM_1
    { AXI_BMU1_BASE_ADDR + AXI_BMU_BUF_SIZE,       AXI_BMU_BUF_SIZE_128 },          //{ 0x00100010, 0x00000007 }, //size of buffer: 2^7 = 128 bytes
    { AXI_BMU1_BASE_ADDR + AXI_BMU_THRES,          AXI_BMU_THRES_UCAST_MAX },       //{ 0x00100018, 0x00000800 },
    { AXI_BMU1_BASE_ADDR + AXI_BMU_INT_SRC,        AXI_BMU_INT_SRC_ALL },           //{ 0x00100020, 0x000001FF },	//BMU_INT_SRC.
    { AXI_BMU1_BASE_ADDR + AXI_BMU_INT_ENABLE,     AXI_BMU_INT_DisALL },            //{ 0x00100024, 0x00000000 }, // All interrupts at BMU1 disable
    //{ AXI_BMU1_BASE_ADDR + AXI_BMU_HIGH_WATERMARK,     0x00000800 }, //{ 0x00100054, 0x00000800 },
    
    // BMU2 cfg
    { AXI_BMU2_BASE_ADDR + AXI_BMU_CTRL,           AXI_BMU_CTRL_RESET_Msk },        //{ 0x00700004, 0x00000002 },
    { AXI_BMU2_BASE_ADDR + AXI_BMU_UCAST_CONFIG,   AXI_BMU_UCAST_BUF_CNT_MAX - 1},  //{ 0x00700008, 0x000007FF }, //1 buffer (128 bytes) for read packets from memory throught SPI
    { AXI_BMU2_BASE_ADDR + AXI_BMU_UCAST_BASEADDR, CBUS_BASE_ADDR | AXI_LMEM1_BASE_ADDR },  //{ 0x0070000C, 0xC0400000 }, //LMEM_2
    { AXI_BMU2_BASE_ADDR + AXI_BMU_BUF_SIZE,       AXI_BMU_BUF_SIZE_128 },          //{ 0x00700010, 0x00000007 }, //size of buffer: 2^7 = 128 bytes
    { AXI_BMU2_BASE_ADDR + AXI_BMU_THRES,          AXI_BMU_THRES_UCAST_MAX },       //{ 0x00700018, 0x00000800 },
    { AXI_BMU2_BASE_ADDR + AXI_BMU_INT_SRC,        AXI_BMU_INT_SRC_ALL },           //{ 0x00700020, 0x000001FF },
    { AXI_BMU2_BASE_ADDR + AXI_BMU_INT_ENABLE,     AXI_BMU_INT_DisALL },            //{ 0x00700024, 0x00000000 }, // All interrupts at BMU2 disable
    //{ AXI_BMU2_BASE_ADDR + AXI_BMU_HIGH_WATERMARK,     0x00000800 }, //{ 0x00700054, 0x00000800 },
    
    // HGPI cfg
    { AXI_HGPI_BASE_ADDR + AXI_GPI_RX_CONFIG,         0x02000001 },         //{ 0x00650008, 0x02000001 },
    { AXI_HGPI_BASE_ADDR + AXI_GPI_HDR_SIZE,          0x00000030 },         //{ 0x0065000C, 0x00000030 },	
    { AXI_HGPI_BASE_ADDR + AXI_GPI_BUF_SIZE,          0x00000080 },         //{ 0x00650010, 0x00000080 },	
    { AXI_HGPI_BASE_ADDR + AXI_GPI_LMEM_ALLOC_ADDR,   CBUS_BASE_ADDR | AXI_BMU1_BASE_ADDR | AXI_BMU_ALLOC_CTRL },       //{ 0x00650014, 0xC0100030 },	//BMU_1
    { AXI_HGPI_BASE_ADDR + AXI_GPI_LMEM_FREE_ADDR,    CBUS_BASE_ADDR | AXI_BMU1_BASE_ADDR | AXI_BMU_FREE_CTRL  },       //{ 0x00650018, 0xC0100034 },	//BMU_1
    { AXI_HGPI_BASE_ADDR + AXI_GPI_CLASS_ADDR,        CBUS_BASE_ADDR | AXI_CLASS_HW1_BASE_ADDR | AXI_CLASS_INQ_PKTPTR}, //{ 0x00650024, 0xC0620010 },	//CLASS_HW_1 CLASS_INQ_PKTPTR    
    { AXI_HGPI_BASE_ADDR + AXI_GPI_DDR_DATA_OFFSET,   0x00000100 },         //{ 0x00650034, 0x00000100 },	//___Q no in spec
    { AXI_HGPI_BASE_ADDR + AXI_GPI_LMEM_DATA_OFFSET,  0x00000010 },         //{ 0x00650038, 0x00000010 },	//___Q no in spec
    { AXI_HGPI_BASE_ADDR + AXI_GPI_LMEM_SEC_BUF_DATA_OFFSET, 0x00000010 },  //{ 0x00650060, 0x00000010 },
    { AXI_HGPI_BASE_ADDR + AXI_GPI_TMLF_TX,           0x00000178 },         //{ 0x0065004C, 0x00000178 },
    { AXI_HGPI_BASE_ADDR + AXI_GPI_DTX_ASEQ,          0x00000040 },         //{ 0x00650050, 0x00000040 },
    //{ AXI_HGPI_BASE_ADDR + AXI_GPI_LMEM2_FREE_ADDR, CBUS_BASE_ADDR | AXI_BMU2_BASE_ADDR | AXI_BMU_FREE_CTRL}, //{ 0x00650148, 0xC0700034 },	//___Q no in spec!!!!	BMU_2
    //{ AXI_HGPI_BASE_ADDR + AXI_GPI_LMEM2_FREE_ADDR, CBUS_BASE_ADDR | AXI_BMU1_BASE_ADDR | AXI_BMU_FREE_CTRL}, //{ 0x00650148, 0xC0100034 },	//___Q no in spec!!!!	BMU_1
    
    // HIF cfg
    { AXI_HIF1_BASE_ADDR + AXI_HIF_TX_POLL_CTRL,              0x00400040 }, //{ 0x00640004, 0x00400040 },
    { AXI_HIF1_BASE_ADDR + AXI_HIF_RX_POLL_CTRL,              0x00400040 }, //{ 0x00640008, 0x00400040 },
    { AXI_HIF1_BASE_ADDR + AXI_HIF_MISC,                      0x5CC50001 },	//{ 0x0064000C, 0x5CC50001 },	//___Q in spec value 0x0000_0001
    { AXI_HIF1_BASE_ADDR + AXI_HIF_TIMEOUT_REG,               0xC92C3BCD },	//{ 0x00640010, 0xC92C3BCD },	//___Q no in spec    
    //{ AXI_HIF1_BASE_ADDR + AXI_HIF_RX_QUEUE_MAP_CH_NO_ADDR, 0x00000000 }, //{ 0x006400CC, 0x00000000 },	//___Q in spec value 0x3210_3210
    { AXI_HIF1_BASE_ADDR + AXI_HIF_RX_QUEUE_MAP_CH_NO_ADDR,   0x32103210 },	//{ 0x006400CC, 0x32103210 },	//___Q in spec value 0x3210_3210    
    //{ AXI_HIF1_BASE_ADDR + AXI_HIF_DMA_BURST_SIZE_ADDR,     0x00000000 }, //{ 0x006400C8, 0x00000000 },    
    //{ AXI_HIF1_BASE_ADDR + AXI_HIF_DMA_BURST_SIZE_ADDR,     0x1 },        //{ 0x006400C8, 0x1 },
    { AXI_HIF1_BASE_ADDR + AXI_HIF_CH0_BASE_ADDR + AXI_HIF_CH_LTC_MAX_PKT, 0x00000004 },	  //{ 0x006401E4, 0x00000004 },	//___Q no in spec
    
    
    //---------------
    // CLASS_HW1 cfg 
    //---------------
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_HDR_SIZE,                  0x00000030 }, //{ 0x00620014, 0x00000030 },
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_TM_INQ_ADDR,               CBUS_BASE_ADDR | AXI_TMU_BASE_ADDR  | AXI_TMU_PHY_INQ_PKTPTR}, //{ 0x00620114, 0xC0600008 },
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_BMU1_BUF_FREE,             CBUS_BASE_ADDR | AXI_BMU1_BASE_ADDR | AXI_BMU_FREE_CTRL },     //{ 0x0062024C, 0xC0100034 },    
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_BUS_ACCESS_BASE_ADDR,      0x000000C2 }, //{ 0x00620258, 0x000000C2 },    
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_GLOBAL_CFG,                0x00000001 }, //{ 0x006204AC, 0x00000001 },		//CLASS_GLOBAL_CFG
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_GLOBAL_CFG1,               0x00000000 }, //{ 0x006207E8, 0x00000000 },		//CLASS_GLOBAL_CFG1    
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_SNOOP_SPL_MCAST_MASK1_LSB, 0xFFFFFFFF }, //{ 0x00620378, 0xFFFFFFFF },
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_SNOOP_SPL_MCAST_MASK1_MSB, 0x0000FFFF }, //{ 0x0062037C, 0x0000FFFF },
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_SNOOP_SPL_MCAST_ADDR1_LSB, 0xC200000E }, //{ 0x00620368, 0xC200000E },
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_SNOOP_SPL_MCAST_ADDR1_MSB, 0x00000180 }, //{ 0x0062036C, 0x00000180 },    
    //{ AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_PUNT_COS,                0x02103210},  //{ 0x006204C0, 0x02103210 },	//CLASS_PUNT_COS
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_PUNT_COS,                  0x0 },		     //{ 0x006204C0, 0x0 },		      //CLASS_PUNT_COS
    
    
    //??????????????????????????????????????????????????
    /*
    3 � 0	csr_punt_mgmt_cos               5
    7 � 4	csr_punt_sa_l2_spl_cos          3
    11 � 8	csr_punt_sa_miss_cos            7
    15 � 12	csr_punt_sa_relearn_cos         6
    19 � 16	csr_punt_sa_is_actv_cos         4
    23 � 20	csr_punt_snp_upr_cos            2
    27 � 24	csr_punt_req_cos                1
    */
    //{ 0x006204C0, 0x01246735 },		//CLASS_PUNT_COS
    
    //{ 0x006204FC, 0x01011000 },	//CLASS_NPU_CTRL
    //{ 0x006207F0, 0x00000100 },	//CLASS_NPU_CTRL1	HIF - port 16 (count to 0)
    /*
    7 � 0	csr_punt_port_map
    10 � 8	csr_bcast_q_no
    12	        csr_qos_mode
    13	        csr_glbl_punt_dis
    19 � 16	csr_egts_cos
    31 � 24	csr_discard_cos_n
    */
    //{ 0x006204FC, 0x01071000 },	//CLASS_NPU_CTRL
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_NPU_CTRL,  0x01011000 },	//{ 0x006204FC, 0x01011000 },	//CLASS_NPU_CTRL
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_NPU_CTRL1, 0x00000100 },	//{ 0x006207F0, 0x00000100 },	//CLASS_NPU_CTRL1	HIF - port 16 (count to 0)
        
    //???????????????????? 0x00620290 = 0x200 ???????????
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_INQ_AFULL_THRES, BUFFERS_WATERMARK_AFULL }, //{ 0x00620290, BUFFERS_WATERMARK_AFULL },	//CLASS_ING_AFULL_THRES
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_USE_TMU_INQ, 0x00000001 },	                //{ 0x00620250, 0x00000001 },	              //CLASS_USE_TMU_INQ
    
    //---------------
    // CLASS_HW2 cfg 
    //---------------
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_HDR_SIZE,                  0x00000030 }, //{ 0x00770014, 0x00000030 },
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_TM_INQ_ADDR,               CBUS_BASE_ADDR | AXI_TMU_BASE_ADDR  | AXI_TMU_PHY_INQ_PKTPTR }, //{ 0x00770114, 0xC0600008 },
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_BMU1_BUF_FREE,             CBUS_BASE_ADDR | AXI_BMU2_BASE_ADDR | AXI_BMU_FREE_CTRL },      //{ 0x0077024C, 0xC0700034 },		//___Q must be 0xC070_0034 (BMU2)    
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_BUS_ACCESS_BASE_ADDR,      0x000000C2 }, //{ 0x00770258, 0x000000C2 },    
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_GLOBAL_CFG,                0x00000001 }, //{ 0x007704AC, 0x00000001 },		//CLASS_GLOBAL_CFG
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_GLOBAL_CFG1,               0x00000000 }, //{ 0x007707E8, 0x00000000 },		//CLASS_GLOBAL_CFG1    
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_SNOOP_SPL_MCAST_MASK1_LSB, 0xFFFFFFFF }, //{ 0x00770378, 0xFFFFFFFF },
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_SNOOP_SPL_MCAST_MASK1_MSB, 0x0000FFFF }, //{ 0x0077037C, 0x0000FFFF },
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_SNOOP_SPL_MCAST_ADDR1_LSB, 0xC200000E }, //{ 0x00770368, 0xC200000E },
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_SNOOP_SPL_MCAST_ADDR1_MSB, 0x00000180 }, //{ 0x0077036C, 0x00000180 },      
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_PUNT_COS,                  0x00000000 }, //{ 0x007704C0, 0x00000000 },		//CLASS_PUNT_COS
        
    //??????????????????????????????????????????????????
    /*
    3 � 0	csr_punt_mgmt_cos               5
    7 � 4	csr_punt_sa_l2_spl_cos          3
    11 � 8	csr_punt_sa_miss_cos            7
    15 � 12	csr_punt_sa_relearn_cos         6
    19 � 16	csr_punt_sa_is_actv_cos         4
    23 � 20	csr_punt_snp_upr_cos            2
    27 � 24	csr_punt_req_cos                1
    */
    //{ 0x007704C0, 0x01246735 },		//CLASS_PUNT_COS
    
    //{ 0x007704FC, 0x01011000 },	//CLASS_NPU_CTRL
    //{ 0x007707F0, 0x00000100 },	//CLASS_NPU_CTRL1	HIF - port 16 (count to 0)
    /*
    7 � 0	csr_punt_port_map
    10 � 8	csr_bcast_q_no
    12	        csr_qos_mode
    13	        csr_glbl_punt_dis
    19 � 16	csr_egts_cos
    31 � 24	csr_discard_cos_n
    */
    //{ 0x007704FC, 0x01071000 },	//CLASS_NPU_CTRL
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_NPU_CTRL,  0x01011000 },	//{ 0x007704FC, 0x01011000 },	//CLASS_NPU_CTRL
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_NPU_CTRL1, 0x00000100 },	//{ 0x007707F0, 0x00000100 },	//CLASS_NPU_CTRL1	HIF - port 16 (count to 0)
    
    //??????????????????????????????? 0x00770290 = 0x200 ???????????
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_INQ_AFULL_THRES,  BUFFERS_WATERMARK_AFULL }, //{ 0x00770290, BUFFERS_WATERMARK_AFULL },	//CLASS_ING_AFULL_THRES
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_USE_TMU_INQ,      0x00000001 },	             //{ 0x00770250, 0x00000001 },	//CLASS_USE_TMU_INQ
    
    //---------
    // TMU cfg 
    //--------- 
    { AXI_TMU_BASE_ADDR + AXI_TMU_INQ_WATERMARK, BUFFERS_WATERMARK_AFULL },   //{ 0x00600004, BUFFERS_WATERMARK_AFULL },	//TMU_INQ_WATERMARK
    { AXI_TMU_BASE_ADDR + AXI_TMU_BMU_INQ_ADDR, 0xC0100034 },                 //{ 0x00600100, 0xC0100034 },
    { AXI_TMU_BASE_ADDR + AXI_TMU_BMU_INQ_ADDR, 0xC0100034 },                 //{ 0x00600100, 0xC0100034 }, - VASSA - the same?

    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY0_INQ_ADDR,  CBUS_BASE_ADDR | AXI_EGPI1_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600200, 0xC0780030 },	//EGPI1
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY1_INQ_ADDR,  CBUS_BASE_ADDR | AXI_EGPI2_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600204, 0xC0790030 },	//EGPI2
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY2_INQ_ADDR,  CBUS_BASE_ADDR | AXI_EGPI3_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600208, 0xC07A0030 },	//EGPI3
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY3_INQ_ADDR,  CBUS_BASE_ADDR | AXI_EGPI4_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x0060020C, 0xC07B0030 },	//EGPI4
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY4_INQ_ADDR,  CBUS_BASE_ADDR | AXI_EGPI5_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600210, 0xC07C0030 },	//EGPI5
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY5_INQ_ADDR,  CBUS_BASE_ADDR | AXI_EGPI6_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600214, 0xC07D0030 },	//EGPI6
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY6_INQ_ADDR,  CBUS_BASE_ADDR | AXI_EGPI7_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600218, 0xC07E0030 },	//EGPI7
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY7_INQ_ADDR,  CBUS_BASE_ADDR | AXI_EGPI8_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x0060021C, 0xC07F0030 },	//EGPI8
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY8_INQ_ADDR,  CBUS_BASE_ADDR | AXI_EGPI9_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600220, 0xC0800030 },	//EGPI9
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY9_INQ_ADDR,  CBUS_BASE_ADDR | AXI_EGPI10_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600224, 0xC0810030 },	//EGPI10
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY10_INQ_ADDR, CBUS_BASE_ADDR | AXI_EGPI11_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600228, 0xC0820030 },	//EGPI11
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY11_INQ_ADDR, CBUS_BASE_ADDR | AXI_EGPI12_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x0060022C, 0xC0830030 },	//EGPI12
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY12_INQ_ADDR, CBUS_BASE_ADDR | AXI_EGPI13_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600230, 0xC0840030 },	//EGPI13
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY13_INQ_ADDR, CBUS_BASE_ADDR | AXI_EGPI14_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600234, 0xC0850030 },	//EGPI14
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY14_INQ_ADDR, CBUS_BASE_ADDR | AXI_EGPI15_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x00600238, 0xC0860030 },	//EGPI15
    { AXI_TMU_BASE_ADDR + AXI_TMU_PHY15_INQ_ADDR, CBUS_BASE_ADDR | AXI_EGPI16_BASE_ADDR | AXI_GPI_INQ_PKTPTR },	//{ 0x0060023C, 0xC0870030 },	//EGPI16
    
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY16_INQ_ADDR, CBUS_BASE_ADDR | CFG_NEW_PACKET_IN_LMEM_REG_ADDR }, //{ 0x00600240, CBUS_BASE_ADDR | AXI_NEW_PACKET_IN_LMEM_REG_ADDR },        //HGPI ADDRESS IN LMEM
    
    { AXI_TMU_BASE_ADDR +  AXI_TMU_CNTX_ACCESS_CTRL, 0x00000000 }, //{ 0x006002F0, 0x00000000 }, //INDIRECT ACCESS
    
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY0_TDQ_CTRL,  0x0000000F },	//{ 0x006002A0, 0x0000000F },	//TMU PHY0 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY1_TDQ_CTRL,  0x0000000F },	//{ 0x006002A4, 0x0000000F },	//TMU PHY1 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY2_TDQ_CTRL,  0x0000000F },	//{ 0x006002A8, 0x0000000F },	//TMU PHY2 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY3_TDQ_CTRL,  0x0000000F },	//{ 0x006002AC, 0x0000000F },	//TMU PHY3 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY4_TDQ_CTRL,  0x0000000F },	//{ 0x006002B0, 0x0000000F },	//TMU PHY4 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY5_TDQ_CTRL,  0x0000000F },	//{ 0x006002B4, 0x0000000F },	//TMU PHY5 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY6_TDQ_CTRL,  0x0000000F },	//{ 0x006002B8, 0x0000000F },	//TMU PHY6 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY7_TDQ_CTRL,  0x0000000F },	//{ 0x006002BC, 0x0000000F },	//TMU PHY7 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY8_TDQ_CTRL,  0x0000000F },	//{ 0x006002C0, 0x0000000F },	//TMU PHY8 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY9_TDQ_CTRL,  0x0000000F },	//{ 0x006002C4, 0x0000000F },	//TMU PHY9 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY10_TDQ_CTRL, 0x0000000F },	//{ 0x006002C8, 0x0000000F },	//TMU PHY10 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY11_TDQ_CTRL, 0x0000000F },	//{ 0x006002CC, 0x0000000F },	//TMU PHY11 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY12_TDQ_CTRL, 0x0000000F },	//{ 0x006002D0, 0x0000000F },	//TMU PHY12 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY13_TDQ_CTRL, 0x0000000F },	//{ 0x006002D4, 0x0000000F },	//TMU PHY13 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY14_TDQ_CTRL, 0x0000000F },	//{ 0x006002D8, 0x0000000F },	//TMU PHY14 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY15_TDQ_CTRL, 0x0000000F },	//{ 0x006002DC, 0x0000000F },	//TMU PHY15 TDQ
    { AXI_TMU_BASE_ADDR +  AXI_TMU_PHY16_TDQ_CTRL, 0x0000000F },	//{ 0x006002E0, 0x0000000F },	//TMU PHY16 TDQ (host)
    {  0 , 0 } };

    
MDR_KX028_AddrData_t sw_hwreg_enable_bmu_1_2_egpi_1_to_16[] =
{
    { AXI_BMU1_BASE_ADDR + AXI_BMU_CTRL, 0x00000001 },   //{ 0x00100004, 0x00000001 },         /* BMU1 enable */
    { AXI_BMU2_BASE_ADDR + AXI_BMU_CTRL, 0x00000001 },   //{ 0x00700004, 0x00000001 },         /* BMU2 enable */
    
    { AXI_EGPI1_BASE_ADDR + AXI_GPI_CTRL,  0x00000001 }, //{ 0x00780004, 0x00000001 },         /* EGPI1 enable */
    { AXI_EGPI2_BASE_ADDR + AXI_GPI_CTRL,  0x00000001 }, //{ 0x00790004, 0x00000001 },         /* EGPI2 enable */
    { AXI_EGPI3_BASE_ADDR + AXI_GPI_CTRL,  0x00000001 }, //{ 0x007A0004, 0x00000001 },         /* EGPI3 enable */
    { AXI_EGPI4_BASE_ADDR + AXI_GPI_CTRL,  0x00000001 }, //{ 0x007B0004, 0x00000001 },         /* EGPI4 enable */
    { AXI_EGPI5_BASE_ADDR + AXI_GPI_CTRL,  0x00000001 }, //{ 0x007C0004, 0x00000001 },         /* EGPI5 enable */
    { AXI_EGPI6_BASE_ADDR + AXI_GPI_CTRL,  0x00000001 }, //{ 0x007D0004, 0x00000001 },         /* EGPI6 enable */
    { AXI_EGPI7_BASE_ADDR + AXI_GPI_CTRL,  0x00000001 }, //{ 0x007E0004, 0x00000001 },         /* EGPI7 enable */
    { AXI_EGPI8_BASE_ADDR + AXI_GPI_CTRL,  0x00000001 }, //{ 0x007F0004, 0x00000001 },         /* EGPI8 enable */
    { AXI_EGPI9_BASE_ADDR + AXI_GPI_CTRL,  0x00000001 }, //{ 0x00800004, 0x00000001 },         /* EGPI9 enable */
    { AXI_EGPI10_BASE_ADDR + AXI_GPI_CTRL, 0x00000001 }, //{ 0x00810004, 0x00000001 },         /* EGPI10 enable */
    { AXI_EGPI11_BASE_ADDR + AXI_GPI_CTRL, 0x00000001 }, //{ 0x00820004, 0x00000001 },         /* EGPI11 enable */
    { AXI_EGPI12_BASE_ADDR + AXI_GPI_CTRL, 0x00000001 }, //{ 0x00830004, 0x00000001 },         /* EGPI12 enable */
    { AXI_EGPI13_BASE_ADDR + AXI_GPI_CTRL, 0x00000001 }, //{ 0x00840004, 0x00000001 },         /* EGPI13 enable */
    { AXI_EGPI14_BASE_ADDR + AXI_GPI_CTRL, 0x00000001 }, //{ 0x00850004, 0x00000001 },         /* EGPI14 enable */
    { AXI_EGPI15_BASE_ADDR + AXI_GPI_CTRL, 0x00000001 }, //{ 0x00860004, 0x00000001 },         /* EGPI15 enable */
    { AXI_EGPI16_BASE_ADDR + AXI_GPI_CTRL, 0x00000001 }, //{ 0x00870004, 0x00000001 },         /* EGPI16 enable */
    { 0, 0 }
};

MDR_KX028_AddrData_t sw_hwreg_enable_class_1_2[] =
{
    { AXI_HGPI_BASE_ADDR + AXI_GPI_CTRL,           0x00000001 }, //{ 0x00650004, 0x00000001 },         /* HGPI enable */    
    { AXI_CLASS_HW1_BASE_ADDR + AXI_CLASS_TX_CTRL, 0x00000001 }, //{ 0x00620004, 0x00000001 },         /* CLASS_HW1 enable */
    { AXI_CLASS_HW2_BASE_ADDR + AXI_CLASS_TX_CTRL, 0x00000001 }, //{ 0x00770004, 0x00000001 },         /* CLASS_HW2 enable */
    { 0, 0 }
};

MDR_KX028_AddrData_t sw_hwreg_enable_emac_1_to_16[] =
{  
    { AXI_EMAC1_BASE_ADDR,  0x0080001C }, //{ 0x00660000, 0x0080001C },         /* EMAC1 enable */
    { AXI_EMAC2_BASE_ADDR,  0x0080001C }, //{ 0x00670000, 0x0080001C },         /* EMAC2 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC3_BASE_ADDR,  0x0080001C }, //{ 0x00680000, 0x0080001C },         /* EMAC3 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC4_BASE_ADDR,  0x0080001C }, //{ 0x00690000, 0x0080001C },         /* EMAC4 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC5_BASE_ADDR,  0x0080001C }, //{ 0x006A0000, 0x0080001C },	        /* EMAC5 enable */  //Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC6_BASE_ADDR,  0x0080001C }, //{ 0x006B0000, 0x0080001C },         /* EMAC6 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC7_BASE_ADDR,  0x0080001C }, //{ 0x006C0000, 0x0080001C },         /* EMAC7 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC8_BASE_ADDR,  0x0080001C }, //{ 0x006D0000, 0x0080001C },         /* EMAC8 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC9_BASE_ADDR,  0x0080001C }, //{ 0x006E0000, 0x0080001C },         /* EMAC9 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC10_BASE_ADDR, 0x0080001C }, //{ 0x006F0000, 0x0080001C },         /* EMAC10 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC11_BASE_ADDR, 0x0080001C }, //{ 0x00760000, 0x0080001C },         /* EMAC11 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC12_BASE_ADDR, 0x0080001C }, //{ 0x00710000, 0x0080001C },         /* EMAC12 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC13_BASE_ADDR, 0x0080001C }, //{ 0x00720000, 0x0080001C },         /* EMAC13 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC14_BASE_ADDR, 0x0080001C }, //{ 0x00730000, 0x0080001C },         /* EMAC14 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC15_BASE_ADDR, 0x0080001C }, //{ 0x00740000, 0x0080001C },         /* EMAC15 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { AXI_EMAC16_BASE_ADDR, 0x0080001C }, //{ 0x00750000, 0x0080001C },         /* EMAC16 enable */	//Ext TSU timer port enable, RX enable,TX enable
    { 0, 0 }
};    


const uint32_t KX028_PortOffsStruct1[AXI_CLASS_PORT_COUNT] = {
  AXI_CLASS_PORT0_STRUC1,
  AXI_CLASS_PORT1_STRUC1,
  AXI_CLASS_PORT2_STRUC1,
  AXI_CLASS_PORT3_STRUC1,
  AXI_CLASS_PORT4_STRUC1,
  AXI_CLASS_PORT5_STRUC1,
  AXI_CLASS_PORT6_STRUC1,
  AXI_CLASS_PORT7_STRUC1,
  AXI_CLASS_PORT8_STRUC1,
  AXI_CLASS_PORT9_STRUC1,
  AXI_CLASS_PORT10_STRUC1,
  AXI_CLASS_PORT11_STRUC1,
  AXI_CLASS_PORT12_STRUC1,
  AXI_CLASS_PORT13_STRUC1,
  AXI_CLASS_PORT14_STRUC1,
  AXI_CLASS_PORT15_STRUC1,
  AXI_CLASS_PORT16_STRUC1,
};

const uint32_t KX028_PortOffsStruct2[AXI_CLASS_PORT_COUNT] = {
  AXI_CLASS_PORT0_STRUC2,
  AXI_CLASS_PORT1_STRUC2,
  AXI_CLASS_PORT2_STRUC2,
  AXI_CLASS_PORT3_STRUC2,
  AXI_CLASS_PORT4_STRUC2,
  AXI_CLASS_PORT5_STRUC2,
  AXI_CLASS_PORT6_STRUC2,
  AXI_CLASS_PORT7_STRUC2,
  AXI_CLASS_PORT8_STRUC2,
  AXI_CLASS_PORT9_STRUC2,
  AXI_CLASS_PORT10_STRUC2,
  AXI_CLASS_PORT11_STRUC2,
  AXI_CLASS_PORT12_STRUC2,
  AXI_CLASS_PORT13_STRUC2,
  AXI_CLASS_PORT14_STRUC2,
  AXI_CLASS_PORT15_STRUC2,
  AXI_CLASS_PORT16_STRUC2,
};



