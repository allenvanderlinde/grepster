#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "21";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] =  "14.11";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 4;
	static const long BUILD  = 422;
	static const long REVISION  = 35;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 811;
	#define RC_FILEVERSION 0,4,422,35
	#define RC_FILEVERSION_STRING "0, 4, 422, 35\0"
	static const char FULLVERSION_STRING [] = "0.4.422.35";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 22;
	

}
#endif //VERSION_H
