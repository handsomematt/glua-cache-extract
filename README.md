## Synopsis

Very simple utility application to extract the LZMA compressed Lua cache downloaded from Garry's Mod servers.

## Usage

This program decompiles the **WHOLE** lua folder, not just one file.
Therefore, you must provide the garrysmod\lua folder as the first argument.


NOTE: Without setting a custom output folder, this WILL OVERRIDE all exsisting files with their decompiled versions.
Make sure to set the output folder to somewhere else to avoid having to redownload the original files.

Syntax: `gluaextract <[GMOD FOLDER]\garrysmod\lua> [output folder]` (*`out` is optional and defaults to `in`*)

## Prerequisites

Depends on `Bootil` which is included as a git submodule and `premake5` to build project files.

## Building From Source

First run: `git submodule update --init --recursive` to grab Bootil.

* **Windows**: Generate your project files using `premake5 vs2015` and build using `project/gluacacheextract.sln`
* **Linux**: Run `premake5 gmake && make`

## License

[The MIT License (MIT) - Copyright (c) 2014-2017 Matt Stevens](LICENSE)
