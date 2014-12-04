#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "03";
	static const char MONTH[] = "12";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] =  "14.12";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 7;
	static const long BUILD  = 726;
	static const long REVISION  = 18;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 1469;
	#define RC_FILEVERSION 0,7,726,18
	#define RC_FILEVERSION_STRING "0, 7, 726, 18\0"
	static const char FULLVERSION_STRING [] = "0.7.726.18";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 26;
	

}
#endif //VERSION_H
