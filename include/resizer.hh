#ifndef RESIZER_H
#define RESIZER_H

#include <filesystem>
#include <iostream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

namespace rr
{
	static bool _RR_VERBOSE = false;
	static const std::string _RR_VERSION = "v0.1.1";

	struct dimentions
	{
		int width;
		int height;
	};

	class Resizer
	{
	private:
		std::filesystem::path _origin;
		std::filesystem::path _destination;
		std::string _extension = ".jpg";

		const int _target_w = 1920;
		const int _target_h = 1280;

		void resize_image(std::filesystem::path path);
		rr::dimentions get_new_dimentions(cv::Mat image);

	public:
		Resizer(std::string origin, const std::string destination);
		~Resizer();

		void resize();
		bool verbose();
	};
} // namespace dslrwwebcam

#endif // RESIZER_H