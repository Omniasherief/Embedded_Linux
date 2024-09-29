#include <iostream>
#include "math.h"
#include "geometry.h"
#include "physics.h"

int main() {
    // Using libmath
    int x = 5, y = 3;
    std::cout << "Addition of " << x << " and " << y << " is: " << add(x, y) << std::endl;
    std::cout << "Subtraction of " << x << " and " << y << " is: " << subtract(x, y) << std::endl;

    // Using libgeometry
    double radius = 7.0;
    std::cout << "Area of circle with radius " << radius << " is: " << circle_area(radius) << std::endl;
    std::cout << "Perimeter of circle with radius " << radius << " is: " << circle_perimeter(radius) << std::endl;

    double width = 10.0, height = 5.0;
    std::cout << "Area of rectangle with width " << width << " and height " << height << " is: " << rectangle_area(width, height) << std::endl;
    std::cout << "Perimeter of rectangle with width " << width << " and height " << height << " is: " << rectangle_perimeter(width, height) << std::endl;

    // Using libphysics
    double distance = 100.0, time = 10.0;
    std::cout << "Velocity with distance " << distance << " and time " << time << " is: " << calculate_velocity(distance, time) << std::endl;

    double velocity = calculate_velocity(distance, time);
    std::cout << "Acceleration with velocity " << velocity << " and time " << time << " is: " << calculate_acceleration(velocity, time) << std::endl;

   
}