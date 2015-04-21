#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "21";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2015";
	static const char UBUNTU_VERSION_STYLE[] =  "15.04";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 2;
	static const long MINOR  = 7;
	static const long BUILD  = 86;
	static const long REVISION  = 89;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 5196;
	#define RC_FILEVERSION 2,7,86,89
	#define RC_FILEVERSION_STRING "2, 7, 86, 89\0"
	static const char FULLVERSION_STRING [] = "2.7.86.89";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 2;
	

}
#endif //VERSION_H
