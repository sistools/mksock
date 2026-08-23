# mksock - Changes <!-- omit in toc -->


## 0.1.1 - 24th August 2026

* Added Doxygen API documentation (**Doxyfile**, **doc/mainpage.md**, **generate_doxygen.sh**) and a section-1 man page (**doc/mksock.1**);
* Updated **CMakeLists.txt** for C17/C++17 defaults, STLSoft 1.11.1, man-page installation, and build diagnostics;
* Updated helper scripts with shared CMake build-directory support and improved diagnostics;
* Expanded CI push-branch coverage and added installation verification for the man page;
* Modernised **.gitattributes**, **.vimrc**, and **.vscode/settings.json**;


## 0.1.0 - 7th August 2026

* Consume **sistools-common-c** for `--help` / `--version` via **`stcc_show_help()`** / **`stcc_show_version()`**;
* Version output now uses **Diagnosticism** version strings (via **sistools-common-c**);
* Copyright years updated to 2025-2026;


## 0.0.1 - 3rd August 2026

* Added modular GitHub Actions CI (**ci.yml** / **ci-cell.yml**) for Linux/macOS (Unix-only tool);
* Modernised **CMakeLists.txt** (explicit Unix-only guard; **CLASP** / **STLSoft** 1.11 / **Catch2** / **xTests**; imported targets; MSVC options; `BUILD_TESTING`);
* Fixed empty/null `socket_path` handling to return `EINVAL`;
* Canonicalised CMake helper scripts (**prepare_cmake.sh**, **build_cmake.sh**, **clean_cmake.sh**, **remove_cmake_artefacts.sh**, **run_all_unit_tests.sh**) with **SIS_CMAKE_*** support and MinGW/MSVC flags;
* Added **.sis/script_info_lines.txt** and **.sis/project_name.txt**;
* Project boilerplate updates (**.gitattributes**, **.gitignore**, **.vimrc**, **.vscode/settings.json**);
* Added **NEWS.md** and README badge row (incl. CI → **ci.yml**);
* Updated homepage to **https://github.com/sistools/mksock**;
* Updated **LICENSE** copyright years to 2025-2026;


## 0.0.0 - 11th March 2025

* Initial implementation;


<!-- ########################### end of file ########################### -->
