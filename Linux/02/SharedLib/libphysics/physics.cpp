#include "physics.h"

double calculate_velocity(double distance, double time) {
    return distance / time;
}


double calculate_acceleration(double velocity, double time) {
    return velocity / time;
}

double calculate_force(double mass, double acceleration) {
    return mass * acceleration;
}
