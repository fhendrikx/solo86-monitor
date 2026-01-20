# Solo86-monitor

This repository contains the code and tools required to build Solo86-monitor.


## What is Solo86-monitor?

Solo86-monitor is an boot monitor built for the IBM PC and Solo86 platforms.


## Hardware

Solo86-monitor is targetted at the Solo86 platform and the IBM PC platform.
These platforms both consist of single CPU boards, with a standardised set
of peripherals, and up to 1024KB of RAM.


## Building Solo86-monitor

### What tools do I need to build Solo86-monitor?

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


### Building Solo86-monitor

Load the environment for building:

    source env.sh

Then, export the environment you want to build for:

    export ARCH="ibmpc"

or

    export ARCH="solo86"

Then build the system:

    make


### Booting Solo86-monitor

If you compiled for the IBM PC platform, there should be a single boot16.img
file in the boot/ directory. This is a bootable image that will boot on your
emulator, or on actual hardware.

