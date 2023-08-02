# Resizer

An image resizing utility for my photography needs.

It's a tool that takes in a folder and resizes all of the images inside it to a resolution of `1920x1280` pixels while preserving the orientation.

It's very limited cause it's made to fit my workflow so I don't recommend using it right now. You can still have a look around if you wish... 😉

## Prerequisites

The tool uses `OpenCV` for image processing, so make sure to have that installed on your system before using it.

## Installation

From the root of the project run the following commands in your terminal:

1. `cmake . -B build/`
2. `cmake --build build/`
3. `cd build/`
4. `make -j$(nproc)`
5. `sudo make install`

If you ran them in this order you should be good to go. The utility should have been installed under `/usr/local/bin/rr`

## Uninstall

To uninstall it run either `sudo make uninstall` or `xargs rm < install_manifest.txt` from inside the `build` directory.
