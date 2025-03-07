/* Copyright (C) 2009 Trend Micro Inc.
 * All right reserved.
 *
 * This program is a free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation
 */

#ifndef _CCONFIG__H
#define _CCONFIG__H

#include "shared.h"

/* Configuration structure */
typedef struct __Config {
    u_int8_t logall;
    u_int8_t logall_json;
    u_int8_t stats;
    u_int8_t integrity;
    u_int8_t syscheck_auto_ignore;
    u_int8_t syscheck_alert_new;
    u_int8_t rootcheck;
    u_int8_t hostinfo;
    u_int8_t mailbylevel;
    u_int8_t logbylevel;
    u_int8_t logfw;
    int decoder_order_size;


    /* Prelude support */
    u_int8_t prelude;
    /* which min. level the alert must be sent to prelude */
    u_int8_t prelude_log_level;
    /* prelude profile name */
    char *prelude_profile;

    /* GeoIP DB */
    char *geoipdb_file;

    /* ZEROMQ Export */
    u_int8_t zeromq_output;
    char *zeromq_output_uri;
    char *zeromq_output_server_cert;
    char *zeromq_output_client_cert;

    /* JSONOUT Export */
    u_int8_t jsonout_output;

    /* Not currently used */
    u_int8_t keeplogdate;

    /* Mail alerting */
    short int mailnotify;

    /* Mail smtp auth */
    short int authsmtp;
    short int securesmtp;

    /* Custom Alert output*/
    short int custom_alert_output;
    char *custom_alert_output_format;

    /* For the active response */
    int ar;

    /* For the correlation */
    int memorysize;

    /* List of files to ignore (syscheck) */
    char **syscheck_ignore;

    /* List of ips to never block */
    os_ip **allow_list;

    /* List of hostnames to never block */
    char **hostname_allow_list;

    /* List of rules */
    char **includes;

    /* List of Lists */
    char **lists;

    /* List of decoders */
    char **decoders;

    /* Global rule hash */
    OSHash *g_rules_hash;

#ifdef LIBGEOIP_ENABLED
    /* GeoIP support */
    u_int8_t loggeoip;
    char *geoip_db_path;
    char *geoip6_db_path;
    int geoip_jsonout;
#endif

    /* MD5 DB support */
    char *md5_allowlist;

} _Config;

#endif /* _CCONFIG__H */

