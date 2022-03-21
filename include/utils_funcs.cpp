#include "utils_funcs.h"
#include <cmath>
#include <string>


double calculate_distance(const Point &point_1, const Point& point_2)
{
    return std::sqrt(pow(point_2.x - point_1.x, 2) + pow(point_2.y - point_1.y, 2));
}

std::string_view choose_manipulator(const manipulator& _1, const manipulator& _2, const Point& point)
{
    auto dist_1 = calculate_distance(_1.get_point(), point);
    auto dist_2 = calculate_distance(_2.get_point(), point);
    return dist_1 <= dist_2 ? _1.get_name() : _2.get_name();
}
