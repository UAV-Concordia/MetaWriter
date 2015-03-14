#include "MetaWriter.h"
#include <iostream>

int main(int argc, char **argv){
	MetaWriter *wr = new MetaWriter();
	wr->setLongitude(1.1111);
	wr->setLatitude(2.2222);
	wr->setAltitude(3.3333);
	if(wr->saveMeta(argv[1]))
			std::cout << "Writing " << argv[1] << std::endl;
	delete wr;
}