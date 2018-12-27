BStone
======

A source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike.


Contents
========

1. Disclaimer
2. Overview  
2.1 Overview (PS Vita)
3. Required assets
4. Profile
5. Compiling
6. Command-line options
7. Cheat key
8. Debug keys
9. Third party use
10. Credits
11. Links


1 - Disclaimer
==============

Copyright (c) 1992-2013 Apogee Entertainment, LLC  
Copyright (c) 2013-2018 Boris I. Bendovsky (<bibendovsky@hotmail.com>)

This program is free software; you can redistribute it and/or  
modify it under the terms of the GNU General Public License  
as published by the Free Software Foundation; either version 2  
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,  
but WITHOUT ANY WARRANTY; without even the implied warranty of  
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
GNU General Public License for more details.

You should have received a copy of the GNU General Public License  
along with this program; if not, write to the Free Software  
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

For a copy of the GNU General Public License see file LICENSE.  
For an original source code license see file "Blake Stone source code license.doc".


2 - Overview
============

BStone is a source port of Blake Stone game series: Aliens of Gold and Planet Strike.

Features:
* High resolution rendering of world (extended vanilla engine)
* Modern and vanilla controls
* Allows to customize control bindings
* Separate volume control of sound effects and music

Supported games:
* Aliens of Gold (v1.0/v2.0/v2.1/v3.0) full or shareware
* Planet Strike (v1.0/v1.1)


2.1 - Overview (PS Vita)
========================
See README-PSVITA.md for details about the source port on PS Vita.


3 - Required assets
===================

Since all titles are not free (except shareware) you have to own a copy of the game(s) in order to play.

Required files for full Aliens of Gold:
* AUDIOHED.BS6
* AUDIOT.BS6
* EANIM.BS6
* GANIM.BS6
* IANIM.BS6
* MAPHEAD.BS6
* MAPTEMP.BS6
* SANIM.BS6
* VGADICT.BS6
* VGAGRAPH.BS6
* VGAHEAD.BS6
* VSWAP.BS6

Required files for shareware Aliens of Gold:
* AUDIOHED.BS1
* AUDIOT.BS1
* IANIM.BS1
* MAPHEAD.BS1
* MAPTEMP.BS1
* SANIM.BS1
* VGADICT.BS1
* VGAGRAPH.BS1
* VGAHEAD.BS1
* VSWAP.BS1

Required files for Planet Strike:
* AUDIOHED.VSI
* AUDIOT.VSI
* EANIM.VSI
* IANIM.VSI
* MAPHEAD.VSI
* MAPTEMP.VSI
* VGADICT.VSI
* VGAGRAPH.VSI
* VGAHEAD.VSI
* VSWAP.VSI


4 - Profile
===========

The port stores configuration file, saved game files, etc. in user's profile.  
The path to those files depends on platform.  
To override the path use --profile_dir option.

On Windows, the path might look like:  
"C:\\Users\\john\\AppData\\Roaming\\bibendovsky\\bstone\\"

On Linux, the path might look like:  
"/home/john/.local/share/bibendovsky/bstone/"

On Mac OS X, the path might look like:  
"/Users/john/Library/Application Support/bibendovsky/bstone/"

Configuration file name: bstone_config  
Log file name: bstone_log.txt  
High scores file name: bstone_game_high_scores  
Saved game file name: bstone_game_saved_game

Where "game" is:  
* aog_sw - Aliens of Gold (shareware)  
* aog_full - Aliens of Gold (full)  
* ps - Planet Strike


5 - Compiling
=============

Minimum requirements:
* C++14 compatible compiler.

* CMake 3.1.3  
  (<http://cmake.org/>)

* SDL v2.0.4
  (<http://www.libsdl.org/>)

CMake variables:
* CMAKE_BUILD_TYPE  
  Selects which build(s) to compile.  
  Use semicolon to separate entries. 
  Usually it's Debug or Release.  
  For other values see CMake documentation.

* CMAKE_INSTALL_PREFIX  
  Selects location where install files to.

* BSTONE_PANDORA  
  Enables build for Open Pandora.

* BSTONE_USE_PCH  
  If enabled utilizes precompiled headers to speed up compilation.  
  Note: Visual C++ only

* BSTONE_USE_STATIC_LINKING  
  If enabled links modules statically to avoid dependency on  
  system and custom libraries at run-time.

* SDL2W_SDL2_DIR  
  Defines directory with SDL2 CMake configuration file or with official SDL2 development Windows build.


Notes:
* Use ON value to enable option and value OFF to disable option.


6 - Command-line options
========================

* --version  
  Outputs the port's version to standard output and  
  into message box.

* --aog_sw  
  Switches the port to Blake Stone: Aliens of Gold (shareware, v3.0) mode.  
  If appropriate data files will not be found the port will fail.  
  Default switch strategy: AoG (full) -> AoG (SW) -> PS

* --ps  
  Switches the port to Blake Stone: Planet Strike (full, v1.0/v1.1) mode.  
  If appropriate data files will not be found the port will fail.  
  Default switch strategy: AoG (full) -> AoG (SW) -> PS

* --no_screens  
  Skips start-up screens (AoG/PS) and ending promo pages (AoG SW only).

* --cheats  
  Enables so called "debug mode" without much fuss.

* --data_dir path_to_data  
  Specifies location to the game's data files.  
  Default: current working directory.

* --mod_dir path_to_data  
  Specifies location to the mod's data files.  
  Default: undefined.

* --profile_dir path  
  Overrides default location of the game's profile files.  

* --vid_renderer [d3d|ogl|ogles|ogles2|soft]  
  Forces to use a specified SDL renderer.  
  "d3d" selects a Direct3D renderer.  
  "ogl" selects an OpenGL renderer.  
  "ogles" selects an OpenGL ES renderer.  
  "ogles2" selects an OpenGL ES 2.0 renderer.  
  "soft" selects a software renderer.  
  Fallback renderer: soft.  
  Default order without this option: d3d, ogl, ogles, ogles2, soft.

* --vid_windowed  
  Runs the game in windowed mode.  
  Default video mode: 640x480

* --vid_mode width height  
  Selects the specified resolution for windowed mode.  
  Without this option the game will use desktop's resolution.  
  Minimum width: 640  
  Minimum height: 480

* --vid_no_vsync  
  Disables vertical synchronization.

* --vid_scale factor  
  Refinement factor. The higher a value the greater internal resolution  
  mode will be used to render a scene. The dimensions of the resolution mode  
  are proportional to the original one (320x200) by 'factor' value.  
  This option can greatly affect the performance of a renderer (especially a  
  software one).  
  Minimum factor: 1 (identical to the original game)  
  Default factor: depends on the game's resolution mode.

* --vid_window_x offset  
  Sets a horizontal offset from the left side of the desktop screen.  
  Applicable for windowed mode only.

* --vid_window_y offset  
  Sets a vertical offset from the top side of the desktop screen.  
  Applicable for windowed mode only.

* --snd_rate sampling_rate  
  Specifies sampling rate of mixer in hertz.  
  Default: 44100 Hz  
  Minimum: 11025 Hz

* --snd_mix_size duration  
  Specifies mix data size in milliseconds.  
  Default: 40 ms  
  Minimum: 20 ms


7 - Cheat key
=============

[J] [A] [M] [Enter]  
Press specified keys sequentially.  
Shows message "NOW you're jammin'!!", and gives to you all keys,  
all weapons and restores health to 100% but zeroes score points.  
Not available in shareware version.


8 - Debug keys
==============

Add option "--cheats" to enable these keys.

* [Backspace]+[A]  
  Toggles visibility of actors on auto-map.

* [Backspace]+[C]  
  Shows counts of total static objects, in use static objects,  
  doors, total actors, active actors.

* [Backspace]+[D]  
  Toggles player's invisibility.

* [Backspace]+[E]  
  Win mission instantly.

* [Backspace]+[F]  
  Shows player's coordinates and direction.

* [Backspace]+[G]  
  Toggles god mode.

* [Backspace]+[H]  
  Hurt yourself by 1%.

* [Backspace]+[I]  
  Each usage adds 99% health, 5 tokens, 50 ammo, one new weapon.

* [Backspace]+[K]  
  Shows total counts of enemies, points and informants on the map.

* [Backspace]+[M]  
  Memory information.

* [Backspace]+[O]  
  Shows push walls on auto-map.

* [Backspace]+[Q]  
  Instant quit.

* [Backspace]+[R]  
  Shows full map.

* [Backspace]+[S]  
  Slow motion.

* [Backspace]+[U]  
  Unlocks all maps.

* [Backspace]+[W]  
  Warps to specified map.

* [Backspace]+[Shift/Caps Lock]+[W]  
  Warps to specified map but loads it from scratch  
  rather from a saved game file/memory.

* [Backspace]+[Home]  
  Selects previous ceiling texture.

* [Backspace]+[Page Up]  
  Selects next ceiling texture.

* [Backspace]+[End]  
  Selects previous flooring texture.

* [Backspace]+[Page Down]  
  Selects next flooring texture.

* [Backspace]+[-]  
  Decreases shading depth.

* [Backspace]+[=]  
  Increases shading depth.

* [Backspace]+['[']  
  Decreases shading drop off.

* [Backspace]+[']']  
  Increases shading drop off.


9 - Third party use
===================

* Simple DirectMedia Library (v2)  
  <http://libsdl.org/>  
  See file COPYING-SDL2.txt for a license information.

* DOSBox  
  <http://www.dosbox.com/>  
  See file dosbox/COPYING for a license information.  
  Note: The source port uses only an OPL emulation code.


10 - Credits
===========

* id Software  
  Developing Wolfenstein 3D engine.  
  <http://www.idsoftware.com/>

* JAM Productions  
  Developing the game.

* Apogee Entertainment, LLC  
  Publishing the game and releasing a source code.  
  <http://www.apogeesoftware.com/>

* Scott Smith  
  Adaptation to Pandora console, various fixes.

* Filipe Tolhuizen  
  Testing the port.


11 - Links
==========

* Home page:  
  <http://bibendovsky.github.io/bstone/>

* Apogee's article about releasing of an original source code:  
  <http://www.apogeesoftware.com/uncategorized/apogee-releases-blake-stone-source-code>

* Official shareware Blake Stone: Aliens of Gold, patches and maps (search for "Blake Stone: Aliens of Gold" section):
  <http://legacy.3drealms.com/downloads.html>
