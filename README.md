# mksock <!-- omit in toc -->

Makes a named socket.


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Installation](#installation)
- [Components](#components)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
    - [Tests-only Dependencies](#tests-only-dependencies)
  - [Related projects](#related-projects)
  - [License](#license)

## Introduction

**mksock** is a small, standalone utility program that removes end-of-line sequence from lines in its input.


## Installation

Detailed instructions - via **CMake**, via bundling, via custom makefile
parameters - are provided in the accompanying [INSTALL.md](./INSTALL.md)
file.


## Components

The project creates a single executable program, **mksock**.


## Examples

```bash
$ pwd
mksock /tmp/mysocket.sock
$ ll /tmp/
 . . .
srwxr-xr-x   1 mwsis  wheel     0B 11 Mar 19:34 mysocket.sock
 . . .
$
```


## Project Information

### Where to get help

[GitHub Page](https://github.com/sistools/mksock "GitHub Page")

### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on [the **cstring** GitHub page](https://github.com/sistools/mksock).

### Dependencies

**mksock** depends on:

* [**CLASP**](https://github.com/synesissoftware/CLASP);
* [**STLSoft 1.10**](https://github.com/synesissoftware/STLSoft-1.10);


#### Tests-only Dependencies

For unit-testing, **mksock** depends additionally on:

* [**Catch2**](https://github.com/catchorg/catch2) - for the unit-test specification and results assessment;
* [**xTests**](https://github.com/synesissoftware/xTests) - for utility components;


### Related projects

Other (similar) project include:

* [**chomp**](https://github.com/sistools/chomp)
* [**errni**](https://github.com/sistools/errni)
* [**lstrip**](https://github.com/sistools/lstrip)
* [**rstrip**](https://github.com/sistools/rstrip)


### License

**mksock** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->

