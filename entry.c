
/* *********************************************************
 * includes
 */

#include "mksock.h"

#include <clasp/clasp.h>

#include <platformstl/filesystem/path_functions.h>
#include <platformstl/system/console_functions.h>

#include <errno.h>
#include <stdio.h>
#include <string.h>


/* *********************************************************
 * macros
 */

#define SIS_DOTSTAR(slice)                  (int)(slice).len, (slice).ptr


/* *********************************************************
 * constants
 */

#define TOOLNAME                            "mksock"
#define PROGRAM_VER_MAJOR                   SISTOOL_MKSOCK_VER_MAJOR
#define PROGRAM_VER_MINOR                   SISTOOL_MKSOCK_VER_MINOR
#define PROGRAM_VER_PATCH                   SISTOOL_MKSOCK_VER_PATCH
#define SUMMARY                             "Synesis System Tools"
#define COPYRIGHT                           "Copyright (c) 2025 Synesis Information Systems"
#define DESCRIPTION                         "Creates a socket"
#define USAGE                               TOOLNAME " [ ... flags/options ... ] <socket-path> [ <file-permissions> ]"

#define FILE_PERMISSIONS_DEFAULT            0666


static clasp_alias_t const Aliases[] = {

    CLASP_GAP_SECTION("behaviour:"),

    CLASP_BIT_FLAG("-O", "--overwrite", SISTOOL_MKSOCK_F_OVERWRITE, "causes overwrite of socket"),

    CLASP_GAP_SECTION("standard flags:"),

    CLASP_FLAG(NULL, "--help", "displays this help and terminates"),
    CLASP_FLAG(NULL, "--version", "displays version information and terminates"),

    CLASP_ALIAS_ARRAY_TERMINATOR
};


/* *********************************************************
 * functions
 */

static
int
run(
    clasp_arguments_t const*    args
,   clasp_alias_t const*        aliases
)
{
    char const* socket_path;
    long        file_permissions = -1;
    int         r;
    int         flags = 0;
    char*       endptr;

    clasp_argument_t const* firstUnusedFlagOrOption;

    if (clasp_flagIsSpecified(args, "--help")) {

        clasp_showUsage(
            args
        ,   Aliases
        ,   TOOLNAME
        ,   SUMMARY
        ,   COPYRIGHT
        ,   DESCRIPTION
        ,   USAGE
        ,   PROGRAM_VER_MAJOR, PROGRAM_VER_MINOR, PROGRAM_VER_PATCH
        ,   clasp_showHeaderByFILE, clasp_showBodyByFILE, stdout
        ,   0
        ,   (int)platformstl_C_get_console_width()
        ,   -4
        ,   1
        );

        return EXIT_SUCCESS;
    }

    if (clasp_flagIsSpecified(args, "--version")) {

        clasp_showVersion(
            args
        ,   TOOLNAME
        ,   PROGRAM_VER_MAJOR, PROGRAM_VER_MINOR, PROGRAM_VER_PATCH
        ,   clasp_showVersionByFILE, stdout
        ,   0
        );

        return EXIT_SUCCESS;
    }

    clasp_checkAllFlags(args, aliases, &flags);

    if (0 != clasp_reportUnusedFlagsAndOptions(args, &firstUnusedFlagOrOption, 0)) {

        fprintf(stderr, "%.*s: unrecognised flag/option: '%.*s'\n", SIS_DOTSTAR(args->programName), SIS_DOTSTAR(firstUnusedFlagOrOption->resolvedName));

        return EXIT_FAILURE;
    }

    switch (args->numValues) {
    case 2:
        file_permissions = strtol(args->values[1].value.ptr, &endptr, 0);

        if (0 == file_permissions &&
            '\0' != *endptr)
        {
            fprintf(stderr, "%.*s: socket path not specified; use --help for usage\n", SIS_DOTSTAR(args->programName));

            return EXIT_FAILURE;
        }

        /* fall-through */
    case 1:

        socket_path = args->values[0].value.ptr;
        break;
    case 0:

        fprintf(stderr, "%.*s: socket path not specified; use --help for usage\n", SIS_DOTSTAR(args->programName));

        return EXIT_FAILURE;
    default:

        fprintf(stderr, "%.*s: too many arguments; use --help for usage\n", SIS_DOTSTAR(args->programName));

        return EXIT_FAILURE;
    }

    r = sistool_mksock(socket_path, file_permissions, flags);

    if (0 != r) {
        fprintf(stderr, "%.*s: failed to create socket at '%s' with permissions %lo: %s\n"
        ,   SIS_DOTSTAR(args->programName)
        ,   socket_path
        ,   file_permissions
        ,   strerror(r)
        );

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


/* *********************************************************
 * main
 */

int main(int argc, char* argv[]) {

    stlsoft_C_string_slice_m_t const    programName =   platformstl_C_get_directory_path_from_path(argv[0]);

    unsigned                            flags       =   0;
    clasp_alias_t const*                aliases     =   Aliases;
    clasp_diagnostic_context_t const*   ctxt        =   NULL;
    clasp_arguments_t const*            args        =   NULL;

    int const r =
        clasp_parseArguments(
            flags
        ,   argc
        ,   argv
        ,   aliases
        ,   ctxt
        ,   &args
        );

    if (0 != r) {

        fprintf(stderr, "%.*s: failed to initialise the command-line parsing libraries: %s\n", SIS_DOTSTAR(programName), strerror(r));

        return EXIT_FAILURE;
    } else {

        int xc = run(args, aliases);

        clasp_releaseArguments(args);

        return xc;
    }
}


/* ///////////////////// end of file //////////////////// */

