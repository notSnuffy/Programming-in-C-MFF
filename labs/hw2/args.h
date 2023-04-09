#pragma once
#include <string>
#include <vector>
#include <map>
#include <string_view>
#include <regex>

struct Arguments
{
    std::string filename;
    std::string output_filename;
    std::string delimiter = " ";
    std::vector<long long> priority;
    std::map<long long, std::string> types;
    void get_arguments(std::vector<std::string> &args, bool &valid);

private:
    bool evaluate_column_argument_with_space(const std::string &argument_left, const std::string &argument_right);
    bool is_column_with_space(const std::string &argument);
    void evaluate_column_argument_without_space(std::string &argument);
    bool is_parameter_without_space(const std::string &argument, const std::regex &regex);
    void evaluate_optional_parameters_without_space(std::string &property, std::string_view argument);
    bool evaluate_IO_with_space(std::string &filename, const std::string &argument);
};
