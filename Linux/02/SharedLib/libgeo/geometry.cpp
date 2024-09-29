#include "geometry.h"
#include <cmath> 


double circle_area(double radius) {
    return M_PI * radius * radius;
}


double circle_perimeter(double radius) {
    return 2 * M_PI * radius;
}


double rectangle_area(double width, double height) {
    return width * height;
}

double rectangle_perimeter(double width, double height) {
    return 2 * (width + height);
}
