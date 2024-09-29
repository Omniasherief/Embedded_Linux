#ifndef GEOMETRY_H
#define GEOMETRY_H

#ifdef _WIN32
    #ifdef LIBGEO_EXPORTS
        #define LIBGEO_API __declspec(dllexport)
    #else
        #define LIBGEO_API __declspec(dllimport)
    #endif
#else
    #define LIBGEO_API
#endif

// Circle operations
LIBGEO_API double circle_area(double radius);
LIBGEO_API double circle_perimeter(double radius);

// Rectangle operations
LIBGEO_API double rectangle_area(double width, double height);
LIBGEO_API double rectangle_perimeter(double width, double height);

#endif 