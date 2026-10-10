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
else
  UNAME_S := $(shell uname -s)
  ifneq ($(filter MINGW% MSYS% CYGWIN%,$(UNAME_S)),)
    DETECTED_OS = windows
    MAKE = make
    VENV_BIN_DIR = Scripts
    PYTHON = $(VENV)/$(VENV_BIN_DIR)/python.exe
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

PRINT = printf

TARGET  := pokestadium0

BASEROM_DIR := baseroms/$(VERSION)
BASEROM     := $(BASEROM_DIR)/baserom.z64

### Output ###

BUILD_DIR := build
ROM       := $(BUILD_DIR)/$(TARGET)-$(VERSION).z64

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

#### Main Targets ####

# All build and extraction targets are currently unsupported stubs.
# They fail loudly rather than silently claiming to have run.
.NOTPARALLEL:

.PHONY: all rom clean distclean venv setup extract diff-init init
.DEFAULT_GOAL := rom
.SILENT:
.SECONDARY:

define unsupported_build
	@echo "ERROR: Stadium Zero build and extraction are not yet bootstrapped."
	@echo "Place baserom.z64 in baseroms/jp/, populate yamls/jp/rom.yaml, and"
	@echo "verify the IDO toolchain per docs/bootstrap.md."
	@exit 1
endef

rom: $(ROM)
	$(call unsupported_build)

clean:
	@$(PRINT) "Cleaning ROM build files...\n"
	$(V)$(RM) -r $(BUILD_DIR)

distclean: clean
	@$(PRINT) "Performing full source distribution clean...\n"
	$(V)$(RM) -r $(BUILD_DIR) asm/ assets/ .splat/

venv:
	@$(PRINT) "Testing venv and setting up python requirements...\n"
	$(V)test -d $(VENV) || python3 -m venv $(VENV)
	$(V)$(PYTHON) -m ensurepip --upgrade
	$(V)$(PYTHON) -m pip install -U pip
	$(V)$(PYTHON) -m pip install -U -r requirements.txt

setup:
	@$(PRINT) "Setting up tools...\n"
	@echo "NOTE: IDO 7.1 / asm-processor / splat tooling are pending per docs/bootstrap.md."
	@exit 1

extract:
	$(call unsupported_build)

diff-init:
	$(call unsupported_build)

init: distclean
	$(MAKE) venv
	$(MAKE) setup
	$(MAKE) extract
	$(MAKE) diff-init

$(ROM):
	$(call unsupported_build)
