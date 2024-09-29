#ifndef PHYSICS_H
#define PHYSICS_H

#ifdef _WIN32
    #ifdef LIBPHYSICS_EXPORTS
        #define LIBPHYSICS_API __declspec(dllexport)
    #else
        #define LIBPHYSICS_API __declspec(dllimport)
    #endif
#else
    #define LIBPHYSICS_API
#endif

LIBPHYSICS_API double calculate_velocity(double distance, double time);
LIBPHYSICS_API double calculate_acceleration(double velocity, double time);
LIBPHYSICS_API double calculate_force(double mass, double acceleration);

#endif 