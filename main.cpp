#include "Bootil/Bootil.h"

using namespace Bootil;

int main( int argc, char** argv )
{
	CommandLine::Set( argc, argv );

	BString strInFolder = CommandLine::GetArg( 0, "" );
	BString strOutFolder = CommandLine::GetArg( 1, strInFolder );

	if (strInFolder == "")
		Output::Error("Usage: gmluaextract <in> [out]");

	String::List files;
	String::List folders;
	File::Find( &files, &folders, strInFolder + "/*.lua", false );

	Output::Msg( "Converting %i files.\n", files.size() );

	BOOTIL_FOREACH_CONST(f, files, String::List)
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
