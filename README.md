# Solo86 Monitor

This repository contains the code and tools required to build the Solo86
Monitor. The Monitor is effectively the BIOS and first programme loaded
when booting a Solo86 machine.


## What is the Monitor?

The Monitor is an boot monitor built for the Solo86 (with some options
included to make it compatible with the IBM PC platform).


## Hardware

The Monitor is targetted at the Solo86 platform (and somewhat at the
IBM PC platform). These platforms both consist of single CPU boards, with
a standardised set of peripherals, and up to 1024KB of RAM.


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

