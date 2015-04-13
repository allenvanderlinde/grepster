#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "13";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2015";
	static const char UBUNTU_VERSION_STYLE[] =  "15.04";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 2;
	static const long MINOR  = 3;
	static const long BUILD  = 68;
	static const long REVISION  = 59;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 4534;
	#define RC_FILEVERSION 2,3,68,59
	#define RC_FILEVERSION_STRING "2, 3, 68, 59\0"
	static const char FULLVERSION_STRING [] = "2.3.68.59";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 81;
	

}
#endif //VERSION_H
