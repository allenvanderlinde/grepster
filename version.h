#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "27";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] =  "14.11";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 5;
	static const long BUILD  = 530;
	static const long REVISION  = 29;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 1053;
	#define RC_FILEVERSION 0,5,530,29
	#define RC_FILEVERSION_STRING "0, 5, 530, 29\0"
	static const char FULLVERSION_STRING [] = "0.5.530.29";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 30;
	

}
#endif //VERSION_H
