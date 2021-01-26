# Caprice32 - Amstrad CPC Emulator PPC64 port

Link to the original Caprice32 source code https://github.com/ColinPitrat/caprice32

# What is it ?

Caprice32 is a software emulator of the Amstrad CPC 8bit home computer series running on Linux and Windows. The emulator faithfully imitates the CPC464, CPC664, and CPC6128 models. By recreating the operations of all hardware components at a low level, the emulator achieves a high degree of compatibility with original CPC software. These programs or games can be run unmodified at real-time or higher speeds, depending on the emulator host environment.

# Features

Caprice32 provides:
  * Complete emulation of CPC464, CPC664 and CPC6128
  * Mostly working support of Plus Range: CPC464+/CPC6128+/GX4000 (missing vectored & DMA interrupts, analog joysticks and 8 bit printer)
  * Joystick support - it can be fully used with joystick only, thanks to an integrated virtual keyboard.
  * Joystick emulation - joystick-only games can be played using the keyboard
  * English, French or Spanish keyboards
  * DSK and [IPF](http://softpres.org/glossary:ipf) files for disks - VOC and CDT files for tapes - CPR files for cartridge
  * Snapshots (SNA files)
  * Direct load of ZIP files
  * Custom disk formats
  * Printer support
  * Memory tool to inspect and modify memory (peek and poke)
  * Experimental support of Multiface 2 (you should prefer using memory tool)
  * Text mode graphics (using [aalib](http://aa-project.sourceforge.net/aalib/) or [libcaca](http://caca.zoy.org/wiki/libcaca))

You see something missing ? Do not hesitate to open an issue to suggest it.

# Installation

from repo.powerprogress.org : apt-get install caprice32
