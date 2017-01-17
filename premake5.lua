solution "gluacacheextract"
	configurations { "Debug", "Release" }
	platforms { "x32", "x64" }

	language		"C++"
	characterset	"MBCS"
	location		"project"
	targetdir		"bin"

	filter "platforms:x32"
		architecture "x32"

	filter "platforms:x64"
		architecture "x64"

	project "gluacacheextract"
		kind	"ConsoleApp"
		targetname "gluaextract"
		flags { "Symbols", "NoEditAndContinue", "NoPCH", "StaticRuntime", "EnableSSE" }
		links "bootil_static"
		includedirs "Bootil/include"

		files { "src/main.cpp" }

	include "Bootil/projects/bootil_premake5.lua"