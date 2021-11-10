#include "Bootil/Bootil.h"

using namespace Bootil;

void decompress(BString& in, BString& out)
{
	Output::Msg("%s", in.c_str());

	AutoBuffer inBuf;
	File::Read(in, inBuf);

	// Extract using LZMA with 32 bytes as base
	AutoBuffer outBuf;
	Compression::LZMA::Extract(inBuf.GetBase(32), inBuf.GetSize() - 32, outBuf);

	File::Write(out, outBuf);

	Output::Msg(" -> %s (%i bytes)\n", out.c_str(), outBuf.GetSize());
}

int main( int argc, char** argv )
{
	Debug::SuppressPopups( true );
	CommandLine::Set( argc, argv );

	BString strInFolder = CommandLine::GetArg( 0, "" );
	BString strOutFolder = CommandLine::GetArg( 1, strInFolder );

	if (strInFolder == "")
		Output::Error("Usage: gluaextract <in> [out]");

	String::List files;
	String::List folders;
	File::Find(&files, &folders, strInFolder + "/*.lua", false);
	File::CreateFolder(strOutFolder);
	
	Output::Msg("Converting %i files\n", files.size());

	BOOTIL_FOREACH_CONST(f, files, String::List)
	{
		BString strInFile = strInFolder + "/" + *f;
		BString strOutFile = strOutFolder + "/" + *f;
		decompress(strInFile, strOutFile);
	}

	Output::Msg("Done!\n");

	return 0;
}