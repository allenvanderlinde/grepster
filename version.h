#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "30";
	static const char MONTH[] = "03";
	static const char YEAR[] = "2015";
	static const char UBUNTU_VERSION_STYLE[] =  "15.03";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 6;
	static const long BUILD  = 44;
	static const long REVISION  = 5;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 3131;
	#define RC_FILEVERSION 1,6,44,5
	#define RC_FILEVERSION_STRING "1, 6, 44, 5\0"
	static const char FULLVERSION_STRING [] = "1.6.44.5";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 50;
	

}
#endif //VERSION_H
