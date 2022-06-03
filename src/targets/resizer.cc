#include <iostream>
#include <filesystem>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

void resizeImage(fs::path path);

const fs::path assets{"assets"}; // Base path to assets

const fs::path from{assets/"original"}; // Location of original images
const fs::path to{assets/"resized"}; // Location of resized images

struct dimentions {
	int width;
	int height;
};

dimentions get_new_dimentions(Mat image);

int main(int argc, const char **argv)
{
	cout << "Started resizing...\n";

	for (const auto &entry : fs::directory_iterator(fs::current_path() / from))
	{
		resizeImage(entry.path());
	}

	waitKey(0);
	return 0;
}

void resizeImage(fs::path path)
{
	cout << "Image: " << path.filename() << " ... ";

	Mat image = imread(path.string());
	
	const string extension = ".jpg";
	const string destination = to.string() + "/" + path.stem().string() + extension;

	auto [new_width, new_height] = get_new_dimentions(image);

	Mat resized;

	resize(image, resized, Size(new_width, new_height), INTER_LINEAR);

	if (imwrite(destination, resized)) {
		cout << "Done.\n";
	} else {
		cout << "Couldn't write image to system.\n";
	}
}

dimentions get_new_dimentions(Mat image) {
	dimentions original {image.cols, image.rows};

	if (original.width >= original.height) return {
		1920,
		1280
	};

	return {
		1280,
		1920
	};
}