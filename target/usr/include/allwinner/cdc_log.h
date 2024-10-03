
/*
* Copyright (c) 2008-2016 Allwinner Technology Co. Ltd.
* All rights reserved.
*
* File : cdc_log.h
* Description :
* History :
*   Author  : xyliu <xyliu@allwinnertech.com>
*   Date    : 2015/04/13
*   Comment :
*
*
*/

#ifndef LOG_H
#define LOG_H

#ifndef LOG_TAG
#define LOG_TAG "cedarc"
#endif

enum CDX_LOG_LEVEL_TYPE {
    LOG_LEVEL_VERBOSE = 2,
    LOG_LEVEL_DEBUG = 3,
    LOG_LEVEL_INFO = 4,
    LOG_LEVEL_WARNING = 5,
    LOG_LEVEL_ERROR = 6,
};

extern enum CDX_LOG_LEVEL_TYPE GLOBAL_LOG_LEVEL;

#ifdef __ANDROID__
    #ifdef CONF_OREO_AND_NEWER
    #include <log/log.h>
    #else
    #include <cutils/log.h>
    #endif

#define CDCLOG(level, fmt, arg...)  \
    do { \
        if (level >= GLOBAL_LOG_LEVEL) \
            LOG_PRI((android_LogPriority)level, LOG_TAG, "<%s:%u>: " fmt, __FUNCTION__, __LINE__, ##arg); \
    } while (0)

#define CC_LOG_ASSERT(e, fmt, arg...)                               \
        LOG_ALWAYS_FATAL_IF(                                        \
                !(e),                                               \
                "<%s:%d>check (%s) failed:" fmt,                    \
                __FUNCTION__, __LINE__, #e, ##arg)                  \

#else

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

extern const char *CDX_LOG_LEVEL_NAME[];
#define CDCLOG(level, fmt, arg...)  \
    do { \
        if (level >= GLOBAL_LOG_LEVEL && level <= LOG_LEVEL_ERROR) \
        { \
            time_t time_current = time(0); \
            char format_time[255]; \
            strftime(format_time, 255, "%Y-%m-%d %H:%M:%S", localtime(&time_current)); \
            printf("[%s] %s: %s <%s:%u>: " fmt "\n", \
                    format_time, CDX_LOG_LEVEL_NAME[level], LOG_TAG, __FUNCTION__, __LINE__, ##arg); \
        } \
    } while (0)


#define CC_LOG_ASSERT(e, fmt, arg...)                                       \
                do {                                                        \
                    if (!(e))                                               \
                    {                                                       \
                        loge("check (%s) failed:"fmt, #e, ##arg);           \
                        assert(0);                                          \
                    }                                                       \
                } while (0)

#endif

#define loge(fmt, arg...) CDCLOG(LOG_LEVEL_ERROR, "\033[40;31m" fmt "\033[0m", ##arg)
#define logw(fmt, arg...) CDCLOG(LOG_LEVEL_WARNING, fmt, ##arg)
#define logi(fmt, arg...) CDCLOG(LOG_LEVEL_INFO, fmt, ##arg)
#define logd(fmt, arg...) CDCLOG(LOG_LEVEL_DEBUG, fmt, ##arg)
#define logv(fmt, arg...) CDCLOG(LOG_LEVEL_VERBOSE, fmt, ##arg)

#define omx_loge(fmt, arg...) CDCLOG(LOG_LEVEL_ERROR, "\033[40;31m" fmt "\033[0m", ##arg)
#define omx_logw(fmt, arg...) CDCLOG(LOG_LEVEL_WARNING, fmt, ##arg)
#define omx_logi(fmt, arg...) CDCLOG(LOG_LEVEL_INFO, fmt, ##arg)
#define omx_logd(fmt, arg...) CDCLOG(LOG_LEVEL_DEBUG , fmt, ##arg)
#define omx_logv(fmt, arg...) CDCLOG(LOG_LEVEL_VERBOSE, fmt, ##arg)


void log_set_level(unsigned level);

#define CEDARC_UNUSE(param) (void)param  //just for remove compile warning

#define CEDARC_DEBUG (0)

#endif

