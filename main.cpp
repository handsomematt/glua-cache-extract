// Garry's Mod Lua Cache Extractor
// See LICENSE distributed with this file
// for licensing details.

#include "Bootil/Bootil.h"

using namespace Bootil;

int main( int argc, char** argv )
{
	CommandLine::Set( argc, argv );

	BString strInFolder = CommandLine::GetArg( 0, Platform::CurrentDir() );
	BString strOutFolder = CommandLine::GetArg( 1, Platform::CurrentDir() );

	String::List listFiles;
	File::GetFilesInFolder(strInFolder, listFiles, false);

	Output::Msg( "Converting %i files.\n", listFiles.size() );

	BOOTIL_FOREACH_CONST(f, listFiles, String::List)
	{
		AutoBuffer inBuf;
		File::Read(strInFolder + "/" + *f, inBuf);

		// Extract using LZMA (first 4 bytes are junk)
		AutoBuffer outBuf;
		Compression::LZMA::Extract(inBuf.GetBase(4), inBuf.GetSize()-4, outBuf);

		File::Write(strOutFolder + "/" + *f, outBuf);
	}

	return 0;
}