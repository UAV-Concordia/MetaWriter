#ifndef METAWRITER_H_RQVHQZNS
#define METAWRITER_H_RQVHQZNS

#include "ExifTool.h"
#include <string>
#include <ctime>

// Default values
#define PIX_H 180
#define PIX_W 180
#define FOCAL_LENGTH 4.3

class MetaWriter {
	public:
		MetaWriter();
		~MetaWriter();

		// The filename point to a JPEG picture
		bool saveMeta(std::string filename);

		void setLatitude(double lat);
		void setLongitude(double lon);
		void setAltitude(double alt);
		void setPixelSize(double x=PIX_W, double y=PIX_H);
		void setFocalLength(double length=FOCAL_LENGTH);

		double getLatitude();
		double getLongitude();
		double getAltitude();
		double getFocalLength();
		double getPixelHeight();
		double getPixelWidth();

	private:
		double   latitude;
		double   longitude;
		double   altitude;
		double   focal_length;
		double   x_resolution;
		double   y_resolution;
		ExifTool *ex;
};

#endif /* end of include guard: METAWRITER_H_RQVHQZNS */
