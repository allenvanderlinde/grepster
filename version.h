#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "11";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2015";
	static const char UBUNTU_VERSION_STYLE[] =  "15.04";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 2;
	static const long MINOR  = 1;
	static const long BUILD  = 65;
	static const long REVISION  = 55;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 4087;
	#define RC_FILEVERSION 2,1,65,55
	#define RC_FILEVERSION_STRING "2, 1, 65, 55\0"
	static const char FULLVERSION_STRING [] = "2.1.65.55";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 76;
	

}
#endif //VERSION_H
