#include <filesystem>
#include <iostream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

#include "resizer.hh"

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

namespace rr
{
	Resizer::Resizer(string origin, string destination) : _origin{fs::canonical({origin})}, _destination{fs::canonical({destination})}
	{
	}

	Resizer::~Resizer() {}

	void Resizer::resize()
	{
		cout << "Started resizing images.\n\n";
		if (_RR_VERBOSE)
			cout << "Origin: " << _origin << "\n\n";

		for (const auto &entry : fs::directory_iterator(_origin))
		{
			resize_image(entry.path());
		}
	}

	void Resizer::resize_image(fs::path path)
	{
		cout << "Image: " << path.filename() << (_RR_VERBOSE ? "\n" : " ... ");
		if (_RR_VERBOSE)
			cout << "Path: " << path << endl;

		Mat image = imread(path.string());

		fs::path outPath{_destination / path.filename()};
		outPath.replace_extension(_extension);

		auto [new_width, new_height] = get_new_dimentions(image);

		Mat resized;

		cv::resize(image, resized, Size(new_width, new_height), INTER_LINEAR);

		if (_RR_VERBOSE)
			cout << "Destinaiton: " << outPath << "\n\n";

		if (imwrite(outPath.string(), resized))
		{
			cout << "Done.\n"
				  << (_RR_VERBOSE ? "\n" : "");
		}
		else
		{
			cout << "Couldn't write image to system.\n"
				  << (_RR_VERBOSE ? "\n" : "");
		}
	}

	dimentions Resizer::get_new_dimentions(Mat image)
	{
		dimentions original{image.cols, image.rows};

		if (original.width >= original.height)
			return {
				 _target_w,
				 _target_h};

		return {
			 _target_h,
			 _target_w};
	}

	bool Resizer::verbose()
	{
		_RR_VERBOSE = true;

		return _RR_VERBOSE;
	}
}