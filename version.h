#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "13";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2015";
	static const char UBUNTU_VERSION_STYLE[] =  "15.05";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 2;
	static const long MINOR  = 7;
	static const long BUILD  = 18;
	static const long REVISION  = 76;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 5258;
	#define RC_FILEVERSION 2,7,18,76
	#define RC_FILEVERSION_STRING "2, 7, 18, 76\0"
	static const char FULLVERSION_STRING [] = "2.7.18.76";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 35;
	

}
#endif //VERSION_H
