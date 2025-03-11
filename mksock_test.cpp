
/* *********************************************************
 * includes
 */

#include "mksock.h"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <xtests/util/temp_file.hpp>

#include <platformstl/filesystem/file_lines.hpp>
#include <platformstl/filesystem/FILE_stream.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>

#include <stdio.h>


/* *********************************************************
 * types
 */

using ::xtests::cpp::util::temp_file;


/* *********************************************************
 * compatibility
 */

#if 0
#elif PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_MAJOR > 2 || \
      (  PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_MAJOR == 2 && \
         PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_MINOR >= 2)

# define FILE_stream_HAS_read_all
#endif


/* *********************************************************
 * tests
 */

SCENARIO("empty-input") {

    GIVEN("an empty socket-path") {

        {
            char const* const   socket_path =   "";

            int const r = sistool_mksock(socket_path, 0777, 0);

            REQUIRE(0 != r);
        }
    }
}


/* ///////////////////// end of file //////////////////// */

