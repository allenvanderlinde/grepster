#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "28";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] =  "14.11";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 5;
	static const long BUILD  = 574;
	static const long REVISION  = 63;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 1149;
	#define RC_FILEVERSION 0,5,574,63
	#define RC_FILEVERSION_STRING "0, 5, 574, 63\0"
	static const char FULLVERSION_STRING [] = "0.5.574.63";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 74;
	

}
#endif //VERSION_H
