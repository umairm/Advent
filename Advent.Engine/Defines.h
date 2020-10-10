#pragma once

#if _WIN32 || _WIN64
#define PLATFORM_WINDOWS
#elif __linux__
#define PLATFORM_LINUX
#elif __APPLE__
#define PLATFORM_MAC
#else
#error "Unknown platform!"
#endif

#ifdef PLATFORM_WINDOWS

#define FORCE_INLINE __forceinline
#define FORCE_NOT_INLINE _declspec(noinline)

#ifdef ADVENT_BUILD_LIB
#define ADVENT_API _declspec(dllexport) 
#else 
#define ADVENT_API _declspec(dllimport)
#endif

#endif //PLATFORM_WINDOWS

//ASSERTIONS
#define ASSERTIONS_ENABLED
#ifdef ASSERTIONS_ENABLED
#include<iostream>
#if _MSC_VER
#include<intrin.h>
#define debugBreak() __debugbreak()
#else 
#define debugBreak() _asm(int 3)
#endif //MSC

FORCE_INLINE void reportAssertionFailure(const char* expression, const char* message, const char* file, int line) {
	std::cerr << "Assertion Failure: " << expression << " message: '" << message << "' in file: " << file << " in line: " << line << "\n";
}

#define ASSERT(expr) { \
	if (expr) { \
	} else { \
		reportAssertionFailure(#expr, "", __FILE__, __LINE__); \
		debugBreak(); \
	} \
}

#define ASSERT_MSG(expr, message) { \
	if (expr) { \
	} else { \
		reportAssertionFailure(#expr, message, __FILE__, __LINE__); \
		debugBreak(); \
	} \
}

#ifdef _DEBUG

#define ASSERT_DEBUG(expr) { \
	if (expr) { \
	} else { \
		reportAssertionFailure(#expr, "", __FILE__, __LINE__); \
		debugBreak(); \
	} \
}
#else
#define ASSERT_DEBUG(expr) //do nothing is not debug
#endif //ASSERTIONS DEBUG

#else 

#define ASSERT(expr)
#define ASSERT_MSG(expr, message)
#define ASSERT_DEBUG(expr)


#endif // ASSERTIONS_ENABLED
