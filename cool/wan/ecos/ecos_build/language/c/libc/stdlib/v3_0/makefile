# eCos makefile

# This is a generated file - do not edit

export PREFIX := /home/water/workspace/WSN-Audio/Software/fpga/wan/ecos/ecos_install
export COMMAND_PREFIX := sparc-elf-
export CC := $(COMMAND_PREFIX)gcc
export OBJCOPY := $(COMMAND_PREFIX)objcopy
export HOST := UNIX
export AR := $(COMMAND_PREFIX)ar

export REPOSITORY := /home/water/workspace/WSN-Audio/Software/fpga/ecos/ecos-3.0/packages
PACKAGE := language/c/libc/stdlib/v3_0
OBJECT_PREFIX := language_c_libc_stdlib
CFLAGS := -msoft-float -Wall -Wpointer-arith -Wstrict-prototypes -Winline -Wundef -Woverloaded-virtual -g -O2 -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fvtable-gc
LDFLAGS := -msoft-float -g -nostdlib -fvtable-gc -Wl,--gc-sections -Wl,-static
VPATH := $(REPOSITORY)/$(PACKAGE)
INCLUDE_PATH := $(INCLUDE_PATH) -I$(PREFIX)/include $(foreach dir,$(VPATH),-I$(dir) -I$(dir)/src -I$(dir)/tests) -I.
MLT := $(wildcard $(REPOSITORY)/$(PACKAGE)/include/pkgconf/mlt*.ldi $(REPOSITORY)/$(PACKAGE)/include/pkgconf/mlt*.h)
TESTS := tests/abs tests/atoi tests/atol tests/bsearch tests/div tests/getenv tests/labs tests/ldiv tests/qsort tests/rand1 tests/rand2 tests/rand3 tests/rand4 tests/srand tests/strtol tests/strtoul

build: headers libtarget.a.stamp

LIBRARY := libtarget.a
COMPILE := src/abs.cxx src/atox.cxx src/bsearch.cxx src/div.cxx src/getenv.cxx src/qsort.cxx src/rand.cxx src/strtod.cxx src/strtol.cxx src/strtoul.cxx src/system.cxx src/strtoll.cxx src/strtoull.cxx
OBJECTS := $(COMPILE:.cxx=.o.d)
OBJECTS := $(OBJECTS:.cpp=.o.d)
OBJECTS := $(OBJECTS:.c=.o.d)
OBJECTS := $(OBJECTS:.S=.o.d)

$(LIBRARY).stamp: $(OBJECTS)
	$(AR) rcs $(PREFIX)/lib/$(@:.stamp=) $(foreach obj,$?,$(if $(obj:%.o=),$(dir $(obj))$(OBJECT_PREFIX)_$(notdir $(obj:.o.d=.o)),$(obj)))
	@cat $(foreach obj,$^,$(obj:.o=.o.d)) > $(@:.stamp=.deps)
	@touch $@

headers: mlt_headers $(PREFIX)/include/cyg/libc/stdlib/atox.inl $(PREFIX)/include/cyg/libc/stdlib/div.inl $(PREFIX)/include/cyg/libc/stdlib/abs.inl

$(PREFIX)/include/cyg/libc/stdlib/atox.inl: $(REPOSITORY)/$(PACKAGE)/include/atox.inl
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/libc/stdlib/div.inl: $(REPOSITORY)/$(PACKAGE)/include/div.inl
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/libc/stdlib/abs.inl: $(REPOSITORY)/$(PACKAGE)/include/abs.inl
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

include $(REPOSITORY)/pkgconf/rules.mak

