# Pokémon Stadium Zero (JP) — Team Hippodrome
# Follows pret's decompilation conventions; pret is not involved with this recomp.

# Build options can be changed by modifying the makefile or by building with 'make SETTING=value'.
# It is also possible to override the settings in Defaults in a file called .make_options as 'SETTING=value'.

-include .make_options

MAKEFLAGS += --no-builtin-rules

# Ensure the build fails if a piped command fails
SHELL = /bin/bash
.SHELLFLAGS = -o pipefail -c

# OS Detection
ifeq ($(OS),Windows_NT)
  DETECTED_OS = windows
  MAKE = make
  VENV_BIN_DIR = Scripts
  PYTHON = $(VENV)/$(VENV_BIN_DIR)/python.exe
  N_THREADS ?= 1
else
  UNAME_S := $(shell uname -s)
  ifneq ($(filter MINGW% MSYS% CYGWIN%,$(UNAME_S)),)
    DETECTED_OS = windows
    MAKE = make
    VENV_BIN_DIR = Scripts
    PYTHON = $(VENV)/$(VENV_BIN_DIR)/python.exe
    N_THREADS ?= 1
  endif
  ifeq ($(UNAME_S),Linux)
    DETECTED_OS = linux
    MAKE = make
    VENV_BIN_DIR = bin
  endif
  ifeq ($(UNAME_S),Darwin)
    DETECTED_OS = macos
    MAKE = gmake
    VENV_BIN_DIR = bin
  endif
endif

#### Defaults ####
# Target game version. Currently only the following version is supported:
#   jp   N64 JP (default, Stadium Zero is Japan-only)
VERSION ?= jp
# If COMPARE is 1, check the output md5sum after building
COMPARE ?= 1
# Python virtual environment
VENV ?= .venv
# Python interpreter
PYTHON ?= $(VENV)/$(VENV_BIN_DIR)/python3

MIPS_BINUTILS_PREFIX ?= mips-linux-gnu-

PRINT = printf

TARGET  := pokestadium0

BASEROM_DIR := baseroms/$(VERSION)
BASEROM     := $(BASEROM_DIR)/baserom.z64

### Output ###

BUILD_DIR := build
ROM       := $(BUILD_DIR)/$(TARGET)-$(VERSION).z64
ELF       := $(ROM:.z64=.elf)
MAP       := $(ROM:.z64=.map)
LDSCRIPT  := $(ROM:.z64=.ld)

#### Setup ####

BUILD_DEFINES ?=

ifeq ($(VERSION),jp)
  BUILD_DEFINES += -DVERSION_JP=1
else
$(error Invalid VERSION variable detected. Please use 'jp')
endif

ifeq ($(NON_MATCHING),1)
  BUILD_DEFINES += -DNON_MATCHING -DAVOID_UB
  COMPARE := 0
endif

CPPFLAGS += -fno-dollars-in-identifiers -P

#### Tools ####
ifneq ($(shell type $(MIPS_BINUTILS_PREFIX)ld >/dev/null 2>/dev/null; echo $$?), 0)
$(error Unable to find $(MIPS_BINUTILS_PREFIX)ld. Please install or build MIPS binutils, commonly mips-linux-gnu. (or set MIPS_BINUTILS_PREFIX if your MIPS binutils install uses another prefix))
endif

AS              := $(MIPS_BINUTILS_PREFIX)as
LD              := $(MIPS_BINUTILS_PREFIX)ld
OBJCOPY         := $(MIPS_BINUTILS_PREFIX)objcopy
OBJDUMP         := $(MIPS_BINUTILS_PREFIX)objdump
NM              := $(MIPS_BINUTILS_PREFIX)nm

SPLAT           := $(PYTHON) -m splat split
SPLAT_YAML      := $(TARGET)-$(VERSION).yaml

#### Files ####

$(shell mkdir -p asm/$(VERSION) assets/$(VERSION) linker_scripts/$(VERSION)/auto)

#### Main Targets ####

rom: $(ROM)
	@$(PRINT) "Building ROM...\n"

clean:
	@$(PRINT) "Cleaning ROM build files...\n"
	$(V)$(RM) -r $(BUILD_DIR)

distclean: clean
	@$(PRINT) "Performing full source distribution clean...\n"
	$(V)$(RM) -r $(BUILD_DIR) asm/ assets/ .splat/
	$(V)$(RM) -r linker_scripts/$(VERSION)/auto $(LDSCRIPT)

venv:
	@$(PRINT) "Testing venv and setting up python requirements...\n"
	$(V)test -d $(VENV) || python3 -m venv $(VENV)
	$(V)$(PYTHON) -m ensurepip --upgrade
	$(V)$(PYTHON) -m pip install -U pip
	$(V)$(PYTHON) -m pip install -U -r requirements.txt

setup:
	@$(PRINT) "Setting up tools...\n"
	# TODO: vendor IDO 7.1 / asm-processor / splat tooling once verified for Stadium Zero.

extract:
	@$(PRINT) "Running ROM extraction...\n"
	$(V)test -f $(BASEROM) || (echo "ERROR: $(BASEROM) not found. Place the JP Stadium Zero rom in $(BASEROM_DIR) as baserom.z64."; exit 1)
	$(V)$(RM) -r asm/$(VERSION) assets/$(VERSION)
	$(V)$(CAT) yamls/$(VERSION)/header.yaml yamls/$(VERSION)/rom.yaml > $(SPLAT_YAML) 2>/dev/null || (echo "ERROR: yamls/$(VERSION)/rom.yaml is not yet populated. Extract/split layout is a pending bootstrap task."; exit 1)
	$(V)$(SPLAT) $(SPLAT_YAML)

diff-init: rom
	$(RM) -r expected/
	mkdir -p expected/
	cp -r $(BUILD_DIR) expected/$(BUILD_DIR)

init: distclean
	$(MAKE) venv
	$(MAKE) setup
	$(MAKE) extract
	$(MAKE) diff-init

.PHONY: all rom clean distclean venv setup extract diff-init init
.DEFAULT_GOAL := rom
# Prevent removing intermediate files
.SECONDARY:

#### Various Recipes ####

# TODO: wire ROM link once Stadium Zero segment layout, IDO toolchain and
# link order are confirmed against the target ROM. Until then `make rom`
# intentionally fails here rather than silently building a donor game.
$(ROM):
	@echo "ERROR: Stadium Zero link step is not yet bootstrapped."
	@echo "Run 'make init' after placing baserom.z64 and populating yamls/jp/rom.yaml."
	@exit 1
