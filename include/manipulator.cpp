#include "manipulator.h"
#include <cmath>

manipulator::manipulator()
{

}

manipulator::manipulator(double x, double y, double radius) : _center_coords({x, y}), _radius(radius)
{

}

manipulator::manipulator(Point p, double radius) : _center_coords(p), _radius(radius)
{

}

void manipulator::set_center_coords(Point p)
{
    _center_coords = p;
}

Point manipulator::get_point()
{
    return _center_coords;
}

double manipulator::get_radius()
{
    return _radius;
}

Point manipulator::get_point() const
{
    return _center_coords;
}

double manipulator::get_radius() const
{
    return _radius;
}

std::string_view manipulator::get_name()
{
    return _name;
}

std::string_view manipulator::get_name() const
{
    return _name;
}

void manipulator::set_name(const std::string_view& str)
{
    _name = str;
}





