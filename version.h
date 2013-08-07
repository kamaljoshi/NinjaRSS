#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "18";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2012";
	static const char UBUNTU_VERSION_STYLE[] = "12.05";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 1;
	static const long BUILD = 2;
	static const long REVISION = 81;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 7;
	#define RC_FILEVERSION 1,1,2,81
	#define RC_FILEVERSION_STRING "1, 1, 2, 81\0"
	static const char FULLVERSION_STRING[] = "1.1.2.81";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 1;
	

}
#endif //VERSION_H
