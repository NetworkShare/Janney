PLATFORM?=LINUX
DEBUG?=YES
TOPDIR:=$(word 1, $(subst /build/posix, ,$(shell pwd)))
INCDIR:=$(TOPDIR)/inc
SRCDIR:=$(TOPDIR)/src
LIBDIR:=$(TOPDIR)/lib/linux
EMULATIONDVR_MAKEFILE_V:=@
EMULATIONDVR_MAKE_PARA:=-s


ifeq ($(PLATFORM),LINUX) 
CROSS:=
CC:=$(CROSS)gcc
CXX:=$(CROSS)g++
AR:=$(CROSS)ar
STRIP:=$(CROSS)strip
LINK:=$(AR) rcs
RANLIB:=$(CROSS)ranlib
LIBDIR:=$(TOPDIR)/lib/linux
endif

ifeq ($(PLATFORM),HIS3521) 
CROSS:=arm-hisiv100nptl-linux-
CC:=$(CROSS)gcc
CXX:=$(CROSS)g++
AR:=$(CROSS)ar
STRIP:=$(CROSS)strip
LINK:=$(AR) rcs
RANLIB:=$(CROSS)ranlib
LIBDIR:=$(TOPDIR)/lib/his3521
endif

ifeq ($(PLATFORM),HIS3798) 
CROSS:=arm-hisiv200-linux-
CC:=$(CROSS)gcc
CXX:=$(CROSS)g++
AR:=$(CROSS)ar
STRIP:=$(CROSS)strip
LINK:=$(AR) rcs
RANLIB:=$(CROSS)ranlib
LIBDIR:=$(TOPDIR)/lib/his3798
endif

ifeq ($(PLATFORM),HIS3536) 
CROSS:=arm-hisiv300-linux-
CC:=$(CROSS)gcc
CXX:=$(CROSS)g++
AR:=$(CROSS)ar
STRIP:=$(CROSS)strip
LINK:=$(AR) rcs
RANLIB:=$(CROSS)ranlib
LIBDIR:=$(TOPDIR)/lib/his3536
endif


ifeq ($(PLATFORM),LINUX64) 
CROSS:=
CC:=$(CROSS)gcc
CXX:=$(CROSS)g++
AR:=$(CROSS)ar
STRIP:=$(CROSS)strip
LINK:=$(AR) rcs
RANLIB:=$(CROSS)ranlib
LIBDIR:=$(TOPDIR)/lib/linux64
CPPFLAGS+=-m64 -fpermissive
CFLAGS+=-m64 -fpermissive
endif

#EMULATIONDVR_LIBDIR=-L$(LIBDIR)   -lpthread  -lutility -llog4cpp -lz
#EMULATIONDVR_LIBDIR+=$(LIBDIR)/libz.a 
#EMULATIONDVR_LIBDIR+=$(LIBDIR)/libutility.a
#EMULATIONDVR_LIBDIR+=$(LIBDIR)/liblog4cpp.a
#EMULATIONDVR_LIBDIR+=-L$(LIBDIR) -lpthread 

CPPFLAGS := -Wall -O2 -fPIC  -I$(INCDIR)  

CFLAGS := -Wall -O2 -fPIC -I$(INCDIR)  

ifeq ($(DEBUG),YES)
CPPFLAGS+= -g -O0  -fbounds-check -fstack-check -fstack-protector-all
CFLAGS+= -g -O0  -fbounds-check -fstack-check -fstack-protector-all
else
CPPFLAGS+=-O2
CFLAGS+=-O2
endif

OBJS:=$(patsubst $(SRCDIR)/%.c, $(SRCDIR)/%.o, $(wildcard $(SRCDIR)/*.c))

OBJS+=$(patsubst $(SRCDIR)/%.cpp, $(SRCDIR)/%.o, $(wildcard $(SRCDIR)/*.cpp))

TARGET := DecoratorModel

.PHONY : clean all 

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(CPPFLAGS)  -lm -o  $@ $^ $(EMULATIONDVR_LIBDIR) 
	rm -f *.o
	
clean:
	rm -f $(TARGET)
	rm -f $(OBJS)

