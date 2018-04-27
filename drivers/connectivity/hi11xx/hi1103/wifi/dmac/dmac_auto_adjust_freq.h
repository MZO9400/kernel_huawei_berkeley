

#ifndef __DMAC_AUTO_ADJUST_FREQ_H__
#define __DMAC_AUTO_ADJUST_FREQ_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#include "oam_ext_if.h"
#include "frw_ext_if.h"
#include "dmac_resource.h"

#undef  THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DMAC_AUTO_ADJUST_FREQ_H

/* ����1151��1102�ȵ�pps/����ͳ�Ƹ��ã�����AUTO_FREQ������ */
#define WLAN_AUTO_FREQ_THROUGHPUT_TIMEOUT     50   /* ������ͳ�ƶ�ʱ������ */

/* ppsͳ�ƽṹ�� */
typedef struct {
    oal_uint32             ul_last_timeout;
    oal_uint32             ul_pps_rate;
    oal_uint32             ul_hcc_rxtx_total;    /* hcc slave �շ�����֡ͳ�� */
    oal_uint8              uc_timer_reuse_count; /* ���ô˶�ʱ����ģ����� */
    oal_uint8              resv[3];

    frw_timeout_stru       timer;
} dmac_pps_statistics_stru;

extern dmac_pps_statistics_stru g_device_pps_statistics;
extern dmac_pps_statistics_stru *pst_dev_pps_stat;

#ifdef _PRE_WLAN_FEATURE_AUTO_FREQ

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/


/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define WLAN_AUTO_FREQ_NETBUF_THRESHOLD       OAL_NETBUF_HIGH_PRIORITY_COUNT    /* ��netbufʣ�ൽ������ȼ�����ˮ�ߣ��������Ƶ���� */
//#define WLAN_AUTO_FREQ_NETBUF_CNT             5     /* ��netbuf����������ֵ��������deviceƵ�ʵ���� */

#define WLAN_AUTO_FREQ_DATA_LOOP_THRESHOLD    20    /*�а�ʱ����20�����ڶ���Ҫ��Ƶ�Ž�Ƶ*/
#define WLAN_AUTO_FREQ_NO_DATA_LOOP_THRESHOLD 4     /*û�а�ʱ����2�����ڶ���Ҫ��Ƶ�Ž�Ƶ*/

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
typedef enum
{
    WLAN_BW_20 = 0,
    WLAN_HT_BW_40,
    WLAN_VHT_BW_40,
    WLAN_VHT_BW_80,
    WLAN_VHT_BW_160,

    WLAN_BW_20_MIMO,
    WLAN_HT_BW_40_MIMO,
    WLAN_VHT_BW_40_MIMO,
    WLAN_VHT_BW_80_MIMO,
    WLAN_VHT_BW_160_MIMO,

    WLAN_BW_BUTT
}wlan_auto_freq_bw_enum;
typedef oal_uint8 wlan_auto_freq_bw_enum_uint8;


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/
extern oal_uint16 g_device_speed_freq[][FREQ_BUTT];


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/
typedef struct {
    oal_bool_enum_uint8              uc_auto_freq_enable;  /*ʹ�ܿ���*/
    oal_bool_enum_uint8              uc_pm_enable;  /*�͹���״̬��־*/
    oal_device_freq_type_enum_uint8  uc_curr_freq_level;  /*��ǰ����Ƶ�ʼ���*/
    oal_device_freq_type_enum_uint8  uc_req_freq_level;   /*����netbuf�ж���Ҫ��Ƶ�ʼ���*/

    oal_uint32                       ul_pps_loop_count;

    /* netbuf ͳ����� *//* ������ʣ��151�� */
    //oal_uint32             ul_netbuf_loop_count;

} dmac_freq_control_stru;
extern dmac_freq_control_stru g_device_freq_type;

typedef struct {
    oal_uint32  ul_speed_level;    /*����������*/
    oal_uint32  ul_cpu_freq_level;  /*CPU��Ƶ����*/
} device_pps_freq_level_stru;
extern device_pps_freq_level_stru g_device_ba_pps_freq_level[];
extern device_pps_freq_level_stru g_device_no_ba_pps_freq_level[];

/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/
extern oal_void dmac_auto_set_freq_testcase_init(oal_void);
extern oal_void dmac_auto_set_freq_testcase_exit(oal_void);
extern oal_void dmac_auto_set_freq(oal_uint16 us_device_freq);
extern oal_void dmac_auto_set_device_freq(oal_void);
extern oal_void dmac_set_auto_freq_process_func(oal_void);
extern oal_void dmac_set_auto_freq_init(oal_void);
extern oal_void dmac_set_auto_freq_deinit(oal_void);
extern oal_void dmac_set_auto_freq_exit(oal_void);
extern dmac_freq_control_stru* dmac_get_auto_freq_handle(oal_void);
extern device_pps_freq_level_stru* dmac_get_ba_pps_freq_level(oal_void);
extern oal_void dmac_auto_freq_set_pps_level(oal_uint32 ul_pps_rate);
extern oal_void dmac_auto_freq_pps_process(oal_uint32 ul_pkt_count);
extern oal_uint8 dmac_get_device_bw_type(void);
extern oal_uint8 dmac_get_device_nss_type(void);
extern oal_uint8 dmac_get_device_bw_nss_type(wlan_auto_freq_bw_enum_uint8,wlan_nss_enum_uint8);
extern oal_uint32 dmac_get_device_freq_value(oal_device_freq_type_enum_uint8 uc_device_freq_type,wlan_auto_freq_bw_enum_uint8 uc_auto_freq_bw_nss_type,oal_uint16* pusdevice_freq_value);
#endif /* end of _PRE_WLAN_FEATURE_AUTO_FREQ */


/* ����1151��1102�ȵ�pps/����ͳ�Ƹ��ã�����AUTO_FREQ������ */
extern oal_uint32 dmac_auto_freq_pps_timeout(void *prg);
extern oal_void dmac_set_auto_freq_pps_stop(oal_void);
extern oal_void dmac_set_auto_freq_pps_start(oal_void);


OAL_STATIC OAL_INLINE  dmac_pps_statistics_stru* dmac_get_pps_statistics_handle(oal_void)
{
    return pst_dev_pps_stat;
}


OAL_STATIC OAL_INLINE oal_void dmac_auto_freq_pps_count(oal_uint32 pkt_cnt)
{
    pst_dev_pps_stat->ul_hcc_rxtx_total += pkt_cnt;
}


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of dmac_auto_adjust_freq.h */