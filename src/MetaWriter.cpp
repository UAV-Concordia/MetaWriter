#include "MetaWriter.h"
#include <sstream>

void MetaWriter::setLatitude(double lat)          { this->latitude = lat; }
void MetaWriter::setLongitude(double lon)         { this->longitude = lon; }
void MetaWriter::setAltitude(double alt)          { this->altitude = alt; }
void MetaWriter::setPixelSize(double x, double y) { this->x_resolution = x; this->y_resolution = y; }
void MetaWriter::setFocalLength(double fl)        { this->focal_length = fl; }

double MetaWriter::getLatitude()    { return this->latitude; }
double MetaWriter::getLongitude()   { return this->longitude; }
double MetaWriter::getAltitude()    { return this->altitude; }
double MetaWriter::getFocalLength() { return this->focal_length; }
double MetaWriter::getPixelHeight() { return this->y_resolution; }
double MetaWriter::getPixelWidth()  { return this->x_resolution; }

MetaWriter::MetaWriter(){
	this->ex = new ExifTool();
	this->x_resolution = PIX_W;
	this->y_resolution = PIX_H;
	this->focal_length = FOCAL_LENGTH;
}

MetaWriter::~MetaWriter(){
	delete ex;
}

bool MetaWriter::saveMeta(std::string filename){
	std::ostringstream os;
	os << getLatitude();
	ex->SetNewValue("GPSLatitude", os.str().c_str());
	os.str("");
	os << getLongitude();
	ex->SetNewValue("GPSLongitude", os.str().c_str());
	os.str("");
	os << getAltitude();
	ex->SetNewValue("GPSAltitude", os.str().c_str());
	os.str("");
	os << getPixelWidth();
	ex->SetNewValue("XResolution", os.str().c_str());
	os.str("");
	os << getPixelHeight();
	ex->SetNewValue("YResolution", os.str().c_str());
	os.str("");
	os << getFocalLength();
	ex->SetNewValue("FocalLength", os.str().c_str());

	ex->WriteInfo(filename.c_str());
	return ex->Complete(10) > 0;
}
