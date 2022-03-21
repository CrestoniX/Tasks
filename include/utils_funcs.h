#ifndef UTILS_FUNCS_H
#define UTILS_FUNCS_H
#include "manipulator.h"

double calculate_distance(const Point&, const Point&);
std::string_view choose_manipulator(const manipulator& _1, const manipulator& _2, const Point& point);


#endif // UTILS_FUNCS_H
