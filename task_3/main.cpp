#include <iostream>
#include <assert.h>
#include "gcodeparser.h"

void test_task_3()
{
    GcodeParser parser;
    std::string str = "10 20 0\n"
                      "X10;Y20;Z30;\n"
                      "X40;Y-20;Z20;\n"
                      "X-10;-20;Z-10;\n";
    std::string str_2 = "10 20 0\n"
            "X10;Y20;Z30;\n"
            "X40;Y-20;<Z20;\n"
            "X-10;>20;Z-10;\n";
    std::string str_3 = "10 20 0\n"
                        "X10;Y20;dadaZ30;\n"
                        "X40;Y-20;Z20;\n";
    std::string str_4 = "1020 0\n"
                        "X10;Y20;Z30;\n"
                        "X40;Y-20Z20;\n";
    std::string str_5 = "10;20 0\n"
                        "X10;Y20;Z30;\n"
                        "X40;Y-20Z20;\n";
    std::string str_6 = "1056 202 345\n"
                      "X123;Y35;Z064;\n"
                      "X621;Y-356;Z537;\n"
                      "X-426;-21;Z-77;\n";
    std::string answer_1 = parser.process_gcode(str);
    std::string answer_2 = parser.process_gcode(str_2);
    std::string answer_3 = parser.process_gcode(str_3);
    std::string answer_4 = parser.process_gcode(str_4);
    std::string answer_5 = parser.process_gcode(str_5);
    std::string answer_6 = parser.process_gcode(str_6);
    assert(answer_1 == "50 0 40");
    assert(answer_2 == "20 40 30\nERROR SCRIPT");
    assert(answer_3 == "10 20 0\nERROR SCRIPT");
    assert(answer_4 == "ERROR SCRIPT");
    assert(answer_5 == "ERROR SCRIPT");
    assert(answer_6 == "1374 -140 869");
    std::cout << "TEST 1:\ntested_gcode:\n" + str;
    std::cout << "result: " << answer_1 << "\n\n";
    std::cout << "TEST 2:\ntested_gcode:\n" + str_2;
    std::cout << "result: " << answer_2 << "\n\n";
    std::cout << "TEST 3:\ntested_gcode:\n" + str_3;
    std::cout << "result: " << answer_3 << "\n\n";
    std::cout << "TEST 4:\ntested_gcode:\n" + str_4;
    std::cout << "result: " << answer_4 << "\n\n";
    std::cout << "TEST 5:\ntested_gcode:\n" + str_5;
    std::cout << "result: " << answer_5 << "\n\n";
    std::cout << "TEST 6:\ntested_gcode:\n" + str_6;
    std::cout << "result: " << answer_6 << "\n\n";
    std::cout << "TEST PASSED" << std::endl;
}

int main()
{
    test_task_3();
    return 0;
}
