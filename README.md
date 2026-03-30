# Solo/86 Monitor

This repository contains the code and tools required to build the Solo86 Monitor. The Monitor is effectively the BIOS and first programme loaded when booting a Solo/86 machine.

PLEASE NOTE: this repository contains on-going work and should NOT be considered final. The existing monitor contained in the main [Solo/86](https://github.com/fhendrikx/solo86/tree/main/software) repository is the current production version. This version is the intended replacement.


## What is the Monitor?

The Monitor is an boot monitor (and BIOS) built for the Solo/86 (with some additional code included to make it compatible with the IBM PC) platform.

This version of the Solo/86 monitor will have the following features when completed:
- Solo/86 hardware support
- IBM PC hardware support (limited)
- ATA drivers
- FAT16/32 support
- Debug tools


## Hardware

The Monitor is targetted at the Solo/86 platform (and somewhat at the IBM PC platform). These platforms both consist of single CPU boards, with a standardised set of peripherals, and up to 1024KB of RAM.


## Building the Monitor

### What tools do I need to build the Monitor?

You'll need to install the following:
- gcc
- make
- mtools
- nasm
- dosfstools
- bison
- flex
- texinfo
- texi2html


### Building Cross-Compiler

Load the environment for building:

    source env.sh

Buld the GCC IA-16 cross compiler:

    cd cross
    make


### Building the Monitor

Load the environment for building:

    source env.sh

Then, export the environment you want to build for:

    export ARCH="solo86"

or

    export ARCH="ibmpc"

Then build the system:

    make

