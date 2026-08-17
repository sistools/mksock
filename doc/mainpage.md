# mksock {#mainpage}

**mksock** is a small utility and internal C library for creating UNIX-domain
sockets.


## Components

| Unit | File(s) | Summary |
| ---- | ------- | ------- |
| Public API | `mksock.h`, `mksock.c` | Version macros, flags, and `sistool_mksock()` |
| Program entry | `entry.c` | Command-line handling and program lifecycle |


## API

The `sistool_mksock()` function creates and binds a UNIX-domain socket at the
requested path, optionally replacing an existing socket.


<!-- ########################### end of file ########################### -->
