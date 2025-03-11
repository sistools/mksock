# mksock - Installation and Use <!-- omit in toc -->


- [Requisites](#requisites)
- [Building](#building)
  - [via CMake](#via-cmake)
  - [via custom makefile (Clang / GCC)](#via-custom-makefile-clang--gcc)


## Requisites

The **mksock** program (implemented in [**entry.c**](./entry.c)) is implemented in terms of:

* [**CLASP**](https://github.com/synesissoftware/CLASP) - for command-line handling;
* [**STLSoft**](https://github.com/synesissoftware/STLSoft-1.10) - for CLI utility functions;

Further, the **mksock_test** program (implemented in [**mksock_test.cpp**](./mksock_test.cpp)), which is used only to test the **mksock** library, also depends on:

* [**Catch2**](https://github.com/catchorg/Catch2) - a sophisticated C++ unit-test library;
* [**xTests**](https://github.com/synesissoftware/xTests) - a simpler C/C++ unit-test library, from which some utility components are used to supplement the tests defined and executed with **Catch2**;

Detailed instructions are provided in the [**REQUISITES.md**](./REQUISITES.md) document for how to obtain and install each of these that you require.

> **NOTE**: if you do not wish to build **mksock_test**, then you need not obtain/install the **Catch2** and **xTests** dependencies.


## Building

### via CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **mksock**, from
   https://github.com/sistools/mksock/, e.g.

    ```bash
    $ mkdir -p ~/open-source
    $ cd ~/open-source
    $ git clone https://github.com/sistools/mksock/
    ```

2. Prepare the CMake configuration, via the **prepare_cmake.sh** script, as
   in:

    ```bash
    $ cd ~/open-source/mksock
    $ ./prepare_cmake.sh
    ```

   **NOTE**: if you intend only to build the **mksock** program then you can eschew building of tests (via flag `-T`) and use the command:

    ```bash
    $ cd ~/open-source/mksock
    $ ./prepare_cmake.sh -T
    ```

   In this case, you do not need to have installed [**Catch2**](https://github.com/catchorg/Catch2) or [**xTests**](https://github.com/synesissoftware/xTests); otherwise, you will need to do so (as described in [**REQUISITES.md**](./REQUISITES.md)).

3. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

    ```bash
    $ cd ~/open-source/mksock
    $ ./build_cmake.sh
    ```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 3 then you do
   not need this step.)

4. As a check, execute the built program, as in:

    ```bash
    $ cd ~/open-source/mksock
    $ ./_build/mksock --help
    ```

   You should see output along the lines of:

    ```plaintext
    Synesis System Tools
    mksock version 0.1.0.0
    Copyright (c) 2020-2024 Synesis Information Systems
    Strips any leading whitespace, if present, from input lines

    mksock [ ... flags/options ... ] [ { <input-file> | - } [ { <output-file> | - } ]]

    Flags:

        standard flags:

        --help
            displays this help and terminates

        --version
            displays version information and terminates
    ```

5. If, in Step 2, you did not skip preparation for building tests (via flag `-T`), you can run the tests as in:

    ```bash
    $ cd ~/open-source/mksock
    $ ./run_all_unit_tests.sh
    ```

   and you will see output such as:

   ```plaintext
    Executing make and then running all test programs
    [ 50%] Built target mksock
    [100%] Built target mksock_test

    executing /Users/my-user/open-source/mksock/_build/mksock_test:
    ===============================================================================
    All tests passed (33 assertions in 1 test case)
   ```

6. Finally, if you wish to do so, you can install the tool on the host, via `cmake`, as in:

    ```bash
    $ cd ~/open-source/mksock
    $ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
    ```

   This can be verified as follows:

    ```bash
    $ pwd
    /Users/.../sistools/mksock --help
    ```

    ```
    Synesis System Tools
    mksock version 0.0.0.0
    Copyright (c) 2025 Synesis Information Systems
    Creates a socket

    mksock [ ... flags/options ... ] <socket-path> [ <file-permissions> ]

    Flags:

        behaviour:

        -O
        --overwrite
            causes overwrite of socket


        standard flags:

        --help
            displays this help and terminates

        --version
            displays version information and terminates
    ```


### via custom makefile (Clang / GCC)

T.B.C.


<!-- ########################### end of file ########################### -->

