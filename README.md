Firelight
=========

Next-generation procedural lighting engine.
Details coming soon.

Developing on Linux
-------------------

Instructions coming soon...

Developing on Windows
---------------------

1. Download Requirements
  * Qt 5.2 or newer (http://qt-project.org/downloads)
  * MingW 4.8 or newer (included with Qt installer, or from http://www.mingw.org/wiki/Getting_Started)
  * Boost 1.55 or newer (http://www.boost.org/)
  * Boost.Numpy (https://github.com/ndarray/Boost.NumPy)
  * Portaudio v19 (http://www.portaudio.com/download.html)
  * Python 2.7 (https://www.python.org/downloads/)
  * Cmake (http://www.cmake.org/cmake/resources/software.html)
2. Install Qt
  * Launch Qt Online installer
  * Select latest version, and under Tools, select MingW 4.8 (if you don't already have MingW)
  * Grab some coffee
3. Build Boost
  * Extract the zip file to a folder (e.g. `boost_1_55_0`)
  * Open a MingW-enabled command prompt (found under Qt in the start menu) to that folder
  * Run `bootstrap.bat mingw`
  * Run `b2.exe toolset=gcc`
  * Grab some more coffee
  * When complete, make sure the `BOOST_ROOT` environment variable is set to point to the `boost_1_55_0` folder.
4. Build Boost.Numpy
  * Install CMake, making sure to add it to the PATH.
  * Clone the Boost.Numpy repo to a folder (e.g. `Boost.Numpy`)
  * Open a MingW-enabled command prompt to the folder
  * Run `cmake -G "MinGW Makefiles"`
  * Run `cmake --build . --config release`
  * Run `cmake --build . --config release --target install`
5. Build portaudio
  * Extract the archive to a folder (e.g. `portaudio`)
  * Open a MingW-enabled command prompt to the folder
  * Run `./configure --enable-cxx`
  * Run `make`
  * Run `make install`
6. Configure Qt Creator
  * Open Qt Creator
  * File -> Open, select `src/firelight.pro` from the working copy of this repo
  * Qt Creator should automatically list your MingW compiler settings.  Click `Configure` to confirm.
7. Build and Run
  * Click the build button (hammer) in the lower left
  * If you have problems, make sure that your paths are set up correctly to Boost, Python, Boost.Numpy, and portaudio.


Licensing and Attribution
-------------------------

First-party code is (c) Jonathan Evans and released under the MIT License (see LICENSE.txt)
Third-party components are licensed as follows:

Firelight uses the Silk icon set by Mark James (http://www.famfamfam.com/lab/icons/silk/)
