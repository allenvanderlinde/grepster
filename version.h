#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "16";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2015";
	static const char UBUNTU_VERSION_STYLE[] =  "15.04";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 2;
	static const long MINOR  = 5;
	static const long BUILD  = 76;
	static const long REVISION  = 74;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 4946;
	#define RC_FILEVERSION 2,5,76,74
	#define RC_FILEVERSION_STRING "2, 5, 76, 74\0"
	static const char FULLVERSION_STRING [] = "2.5.76.74";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 91;
	

}
#endif //VERSION_H
