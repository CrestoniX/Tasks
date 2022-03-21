#ifndef MANIPULATOR_H
#define MANIPULATOR_H
#include "structures.h"
#include <string>
#include <string_view>

class manipulator
{
    Point _center_coords;
    const double _radius = 0;
    std::string_view _name{};

public:
    manipulator();
    manipulator(double x, double y, double radius);
    manipulator(Point p, double radius);
    void set_center_coords(Point p);
    Point get_point();
    double get_radius();
    Point get_point() const;
    double get_radius() const;
    std::string_view get_name();
    std::string_view get_name() const;
    void set_name(const std::string_view& str);
};

#endif // MANIPULATOR_H
