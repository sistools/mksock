
#include "mksock.h"

#include <inetstl/util/uds_helpers.h>
#include <platformstl/platformstl.h>

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int
sistool_mksock(
    char const* socket_path
,   long        file_permissions
,   int         flags
) {
    int sk;

    if (-1 == (sk = socket(AF_UNIX, SOCK_DGRAM, 0)))
    {
        return -1;
    }
    else
    {
        size_t              cb_actual;
        struct sockaddr_un  sa;

        int const r = inetstl_c_sockaddr_un_init_from_path(&sa, sizeof(sa), socket_path, &cb_actual);

        if (0 != r) {
            close(sk);

            return ENAMETOOLONG;
        } else {
            if (0 != (SISTOOL_MKSOCK_F_OVERWRITE & flags))
            {
                unlink(socket_path);
            }

            {
                int const r = bind(sk, (struct sockaddr*)&sa, sizeof(sa));
                int const e = errno;

                close(sk);

                if (0 != r) {
                    return e;
                }
            }
        }
    }

    return 0;
}


/* ///////////////////// end of file //////////////////// */

