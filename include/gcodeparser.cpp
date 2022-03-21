#include "gcodeparser.h"

std::variant<IntTuple, std::string> GcodeParser::process_section(const std::string &str, const char current_del)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int num_of_iteration = 0;
    std::string::const_iterator sec_begin = str.begin();
    while (sec_begin != str.end()) {
        std::string section_of_section;
        std::string::const_iterator place_of_del;
        if(num_of_iteration == 2 && current_del == space_del)
            place_of_del = str.end();
        else
        {
            place_of_del = std::find(sec_begin, str.end(), current_del);
            if(place_of_del == str.end())
                return "ERROR SCRIPT";
        }
        section_of_section = std::string(sec_begin, place_of_del); // -1
        int value = 0;
        int num_of_char = 1;
        for(int i = section_of_section.size() - 1; i >= 0; --i)
        {
            if(std::isdigit(section_of_section[i]))
                value += (section_of_section[i] - '0') * num_of_char;
            else if(section_of_section[i] == '-')
                value *= -1;
            num_of_char *= 10;
        }
        if(num_of_iteration == 0)
            x += value;
        else if(num_of_iteration == 1)
            y += value;
        else
            z += value;
        num_of_iteration == 2 ? sec_begin = str.end(): sec_begin = place_of_del + 1;
        num_of_iteration++;
    }
    return std::tuple<int, int, int>(x, y, z);
}

std::string GcodeParser::form_answer(int num_of_iteration, int x, int y, int z, bool error_code)
{
    std::string answer;
    if(num_of_iteration == 0)
        answer = "ERROR SCRIPT";
    else {
        answer = std::to_string(x) +
                " " + std::to_string(y) + " " +
                std::to_string(z);
        if(error_code)
            answer += "\nERROR SCRIPT";
    }
    return answer;
}

char GcodeParser::check_for_delimiter(const std::string &str)
{
    char current_del;
    if(std::find(str.begin(), str.end(), space_del) != str.end())
        current_del = space_del;
    else if(std::find(str.begin(), str.end(), del) != str.end())
        current_del = del;
    else
        current_del = '/';
    return current_del;
}

GcodeParser::GcodeParser()
{

}

std::string GcodeParser::process_gcode(const std::string &gcode)
{
    std::string answer;
    int num_of_iteration = 0;
    std::regex reg("^[X]?[-]?\\d+[;| ][Y]?[-]?\\d+[;| ][Z]?[-]?\\d+[;]?$");
    int x = 0;
    int y = 0;
    int z = 0;
    std::string::const_iterator it = gcode.begin();
    while(it < gcode.end())
    {
        std::string current_section{};
        std::string::const_iterator end_of_section =
                std::find(it, gcode.end(), '\n');
        if(end_of_section != gcode.end())
        {
            current_section = std::string(it, end_of_section);
            if(std::regex_search(current_section, reg))
            {
                std::variant<IntTuple, std::string> processed;
                char dele = check_for_delimiter(current_section);
                if(dele == '/')
                    return answer = form_answer(num_of_iteration, x, y, z, true);
                try {
                    processed = process_section(current_section, dele);
                    auto ints = std::get<IntTuple>(processed);
                }  catch (...) {
                    return answer = form_answer(num_of_iteration, x, y, z, true);
                }
                auto [_x, _y, _z] = std::get<IntTuple>(processed);
                x += _x;
                y += _y;
                z += _z;
            }
            else
            {
                answer = form_answer(num_of_iteration, x, y, z, true);
                return answer;
            }
        }
        num_of_iteration++;
        it = end_of_section + 1;
    }

    answer = form_answer(num_of_iteration, x, y, z, false);
    return answer;
}
