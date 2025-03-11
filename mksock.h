
#ifndef MKSOCK_INCL_H_MKSOCK
#define MKSOCK_INCL_H_MKSOCK

#define SISTOOL_MKSOCK_VER_MAJOR        0
#define SISTOOL_MKSOCK_VER_MINOR        0
#define SISTOOL_MKSOCK_VER_PATCH        0


/* *********************************************************
 * includes
 */

#include <stdio.h>


/* *********************************************************
 * API flags
 */

#define SISTOOL_MKSOCK_F_OVERWRITE          (0x00000001)    /*!< causes overwrite of socket */


/* *********************************************************
 * API functions
 */

#ifdef __cplusplus
extern "C"
#endif /* __cplusplus */
int
sistool_mksock(
    char const* socket_path
,   long        file_permissions
,   int         flags
);

#endif /* !MKSOCK_INCL_H_MKSOCK */


/* ///////////////////// end of file //////////////////// */

