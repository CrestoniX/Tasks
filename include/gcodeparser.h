#ifndef GCODEPARSER_H
#define GCODEPARSER_H
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <variant>

using IntTuple = std::tuple<int, int, int>;

class GcodeParser
{
    const char space_del = ' ';
    const char del = ';';
    std::variant<IntTuple, std::string> process_section(const std::string& str, const char current_del);
    std::string form_answer(int num_of_iteration, int x, int y, int z, bool error_code);
    char check_for_delimiter(const std::string& str);

public:
    GcodeParser();
    std::string process_gcode(const std::string& gcode);

};

#endif // GCODEPARSER_H
