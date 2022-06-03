#include <iostream>

#include <cxxopts.hpp>

#include "resizer.hh"

using namespace std;
namespace fs = std::filesystem;

int main(int argc, const char *argv[])
{
	cxxopts::Options program_options("rr", "A small image resizing utility.");

	program_options.add_options()("i,input", "Relative path to the directory containing the input fles.", cxxopts::value<string>()->default_value("original"))("o,output", "Relative path to the directory where you want to store the resized images.", cxxopts::value<string>()->default_value("resized"))("v,version", "Print the current version number.", cxxopts::value<bool>()->default_value("false"))("V,verbose", "Give verbose output. (Not implemented yet)", cxxopts::value<bool>()->default_value("false"))("h,help", "Print usage");

	cxxopts::ParseResult parsed_options;
	try
	{
		parsed_options = program_options.parse(argc, argv);
	}
	catch (const cxxopts::option_not_exists_exception &e)
	{
		cout << "Unrecognised argument provided...\n"
			  << "Try 'rr --help' for more information.\n";
		exit(1);
	}

	if (parsed_options.count("help"))
	{
		cout << program_options.help() << endl;
		exit(0);
	}

	if (parsed_options.count("version"))
	{
		cout << rr::_RR_VERSION << "\n";
		exit(0);
	}

	// Resizer setup and start

	rr::Resizer resizer(parsed_options["input"].as<string>(), parsed_options["output"].as<string>());

	if (parsed_options.count("verbose"))
	{
		resizer.verbose();
	}

	resizer.resize();

	return 0;
}