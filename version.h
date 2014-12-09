#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "08";
	static const char MONTH[] = "12";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] =  "14.12";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 7;
	static const long BUILD  = 772;
	static const long REVISION  = 44;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 1538;
	#define RC_FILEVERSION 0,7,772,44
	#define RC_FILEVERSION_STRING "0, 7, 772, 44\0"
	static const char FULLVERSION_STRING [] = "0.7.772.44";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 72;
	

}
#endif //VERSION_H
