#ifndef MATH_H
#define MATH_H
#ifdef _WIN32
    #ifdef LIBMATH_EXPORTS
        #define LIBMATH_API __declspec(dllexport)
    #else
        #define LIBMATH_API __declspec(dllimport)
    #endif
#else
    #define LIBMATH_API
#endif
LIBMATH_API int add(int a, int b);

// Function for subtracting two integers
LIBMATH_API int subtract(int a, int b);
#endif // MATH_H