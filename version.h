#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "07";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2015";
	static const char UBUNTU_VERSION_STYLE[] =  "15.04";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 9;
	static const long BUILD  = 49;
	static const long REVISION  = 4;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 3667;
	#define RC_FILEVERSION 1,9,49,4
	#define RC_FILEVERSION_STRING "1, 9, 49, 4\0"
	static const char FULLVERSION_STRING [] = "1.9.49.4";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 58;
	

}
#endif //VERSION_H
