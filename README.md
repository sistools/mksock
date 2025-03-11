# mksock <!-- omit in toc -->

Strips trailing new line(s) from input


## Table of Contents

- [Table of Contents](#table-of-contents)
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

**mksock** is a small, standalone utility program that creates a socket.


## Installation

Detailed instructions - via **CMake**, via bundling, via custom makefile
parameters - are provided in the accompanying [INSTALL.md](./INSTALL.md)
file.


## Components

The project creates a single executable program, **mksock**.


## Examples

```bash
$ mksock /tmp/socket.sock 0777
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
* [**lstrip**](https://github.com/sistools/lstrip)
* [**rstrip**](https://github.com/sistools/rstrip)


### License

**mksock** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->

