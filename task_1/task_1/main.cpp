#include <iostream>
#include "utils_funcs.h"
#include <assert.h>


void test_task_1()
{
    Point _1{1.1, 2.2};
    Point _2{45.66, 22.55};
    Point _3{6.2, 6.4};
    manipulator m_1(12.0, 23.0, 10.0);
    m_1.set_name("manipulator_1");
    manipulator m_2(11.0, 18.0, 15.0);
    m_2.set_name("manipulator_2");
    assert(m_2.get_name() == choose_manipulator(m_1, m_2, _1));
    assert(m_2.get_name() == choose_manipulator(m_2, m_2, _1));
    assert(m_2.get_name() == choose_manipulator(m_2, m_2, _1));
    std::cout << "TEST_PASSED" << std::endl;
}

using namespace std;

int main()
{
    test_task_1();
    return 0;
}
