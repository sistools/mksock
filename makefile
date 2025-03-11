############################################################################
# File:     makefile
#
# Purpose:  Makefile for the mksock project,
#           for any GCC-compatible compiler,
#           on UNIX
#
# Created:  6th February 2025
# Updated:  6th February 2025
#
############################################################################


############################################################################
# environment check

ifndef CLASP_USE_INSTALL
ifndef CLASP_ROOT
$(error CLASP_ROOT not defined. If you have installed CLASP, then define CLASP_USE_INSTALL; otherwise, you will need to obtain the library in source form and point this directory to it)
endif # CLASP_ROOT
endif # CLASP_USE_INSTALL

ifndef STLSOFT_USE_INSTALL
ifndef STLSOFT
$(error STLSOFT not defined. If you have installed STLSOFT, then define STLSOFT_USE_INSTALL; otherwise, you will need to obtain the library in source form and point this directory to it)
endif # STLSOFT
endif # STLSOFT_USE_INSTALL

ifndef CATCH_USE_INSTALL
ifndef CATCH
$(error CATCH not defined. If you have installed CATCH, then define CATCH_USE_INSTALL; otherwise, you will need to obtain the library in source form and point this directory to it)
endif # CATCH
endif # CATCH_USE_INSTALL

ifndef XTESTS_USE_INSTALL
ifndef XTESTS_C_ROOT
$(error XTESTS_C_ROOT not defined. If you have installed xTests, then define XTESTS_USE_INSTALL; otherwise, you will need to obtain the library in source form and point this directory to it)
endif # XTESTS_C_ROOT
endif # XTESTS_USE_INSTALL


############################################################################
# symbols

CLASP_SRC_NAMES_=\
 clasp.api.c\
 clasp.diagnostics.c\
 clasp.memory.c\
 clasp.string.c\
 clasp.usage.FILE.c\
 clasp.usage.c\
 \

CLASP_OBJS=$(CLASP_SRC_NAMES_:%.c=%.o)
ifndef CLASP_USE_INSTALL
CLASP_SRCS=$(CLASP_SRC_NAMES_:%="$(CLASP_ROOT)/src/%")
endif # CLASP_USE_INSTALL


CH_C_INCLUDES_=
ifndef CLASP_USE_INSTALL
CH_C_INCLUDES_+="$(CLASP_ROOT)/include"
endif # CLASP_USE_INSTALL
ifndef STLSOFT_USE_INSTALL
CH_C_INCLUDES_+="$(STLSOFT)/include"
endif # STLSOFT_USE_INSTALL

CH_CXX_INCLUDES_=$(CH_C_INCLUDES_)
ifndef CATCH_USE_INSTALL
CH_CXX_INCLUDES_+="$(CATCH)/include"
endif # CATCH_USE_INSTALL
ifndef XTESTS_USE_INSTALL
CH_CXX_INCLUDES_+="$(XTESTS_C_ROOT)/include"
endif # XTESTS_USE_INSTALL

CH_C_INCLUDES=$(CH_C_INCLUDES_:%=-I %)
CH_CXX_INCLUDES=$(CH_CXX_INCLUDES_:%=-I %)

CFLAGS+=$(CH_C_INCLUDES)
CXXFLAGS+=$(CH_CXX_INCLUDES)

CFLAGS+=-Wall -Werror -pedantic -pedantic-errors
CXXFLAGS+=-Wall -Werror -pedantic -pedantic-errors

COMMON_FLAGS_=
COMMON_FLAGS_+=-Wno-unused-function

CFLAGS+=-Wno-incompatible-pointer-types-discards-qualifiers
# CFLAGS+=-Wno-format
CFLAGS+=$(COMMON_FLAGS_)
CFLAGS+=-DNDEBUG
CFLAGS+=-O2
CFLAGS+=-std=c11

CXXFLAGS+=-std=c++14

LDLIBS+=-lclasp -lstdc++


############################################################################
# targets

build: \
 mksock\
 \

build.test: \
 mksock_test\
 \

build.all: \
 build\
 build.test\
 \


test: build.test
	./mksock_test

clean:
	@rm -f *.a
	@rm -f *.o
	@rm -f mksock_test
	@rm -f mksock


mksock.o: mksock.c mksock.h
mksock_test.o: mksock_test.cpp mksock.h
entry.o: entry.c mksock.h

clasp.%.o: $(CLASP_ROOT)/src/clasp.%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

ifndef CLASP_USE_INSTALL
libclasp.a: $(CLASP_OBJS)
	@rm -f $@
	$(AR) -ru $@ $< $(CLASP_OBJS)
endif # CLASP_USE_INSTALL

mksock: entry.o mksock.o

mksock_test: mksock_test.o mksock.o


################################ end of file ###############################

