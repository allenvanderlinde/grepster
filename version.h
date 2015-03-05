#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "04";
	static const char MONTH[] = "03";
	static const char YEAR[] = "2015";
	static const char UBUNTU_VERSION_STYLE[] =  "15.03";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 2;
	static const long BUILD  = 1211;
	static const long REVISION  = 60;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 2348;
	#define RC_FILEVERSION 1,2,1211,60
	#define RC_FILEVERSION_STRING "1, 2, 1211, 60\0"
	static const char FULLVERSION_STRING [] = "1.2.1211.60";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 11;
	

}
#endif //VERSION_H
