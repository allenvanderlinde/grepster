#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "19";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] =  "14.11";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 2;
	static const long BUILD  = 278;
	static const long REVISION  = 14;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 524;
	#define RC_FILEVERSION 0,2,278,14
	#define RC_FILEVERSION_STRING "0, 2, 278, 14\0"
	static const char FULLVERSION_STRING [] = "0.2.278.14";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 78;
	

}
#endif //VERSION_H
