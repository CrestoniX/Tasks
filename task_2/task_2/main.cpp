#include <iostream>
#include "utils_funcs.h"
#include <vector>
#include <math.h>

std::pair<std::string, std::string> solve_task_2(const std::vector<Point>& vector_of_points,
                                                   manipulator& m_1,
                                                   manipulator& m_2)
{
    if(vector_of_points.empty())
        return std::pair<std::string, std::string>();
    std::string man_1(m_1.get_name());
    std::string man_2(m_2.get_name());
    man_1 += ": ";
    man_2 += ": ";
    for(const auto& point : vector_of_points)
    {
        if(choose_manipulator(m_1, m_2, point) == m_1.get_name())
        {
            m_1.set_center_coords(point);
            man_1 += "{" + std::to_string(point.x) + ", " + std::to_string(point.y) + "}" + " ";
        }
        else
        {
            m_2.set_center_coords(point);
            man_2 += "{" + std::to_string(point.x) + ", " + std::to_string(point.y) + "}" + " ";
        }
    }
    return std::pair<std::string, std::string>(man_1, man_2);
}


int main()
{
    std::vector<Point> v{{1.0,3.3}, {2.0, 1.41}, {0.2, -7.0}, {-5.0, -1.0}, {0.0,9.0}};
    manipulator m_1(0.0, 0.0, 4.0);
    m_1.set_name("manipulator_1");
    manipulator m_2(2.0, 1.0, 3.0);
    m_2.set_name("manipulator_2");
    auto pair = solve_task_2(v, m_1, m_2);
    std::cout << pair.first << "\n" << pair.second << std::endl;
    return 0;
}
