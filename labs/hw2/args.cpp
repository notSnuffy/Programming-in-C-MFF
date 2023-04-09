#include "args.h"

// I wanted to use string views here but unfortunately regex from my research
// does not work on views yet

void Arguments::get_arguments(std::vector<std::string> &args, bool &valid)
{
    size_t index = 0;
    const std::regex input_parameter("^-i.*\\..*");
    const std::regex separator_parameter("^-s.*");
    const std::regex output_parameter("^-o.*\\..*");
    const std::regex columns_parameter("^(N|S)[1-9][0-9]*$");
    while (index != args.size())
    {
        if (args[index] == "-i")
        {
            ++index;
            if (!evaluate_IO_with_space(filename, args[index])) {
                valid = false;
                return;
            }
        }
        else if (std::regex_search(args[index], input_parameter))
        {
            evaluate_optional_parameters_without_space(filename, args[index]);
        }
        else if (args[index] == "-s")
        {
            ++index;
            delimiter = args[index];
        }
        else if (is_parameter_without_space(args[index], separator_parameter))
        {
            evaluate_optional_parameters_without_space(delimiter, args[index]);
        }
        else if (args[index] == "-o")
        {
            ++index;
            if (!evaluate_IO_with_space(output_filename, args[index])) {
                valid = false;
                return;
            }
        }
        else if (is_parameter_without_space(args[index], output_parameter))
        {
            evaluate_optional_parameters_without_space(output_filename, args[index]);
        }
        else if (is_column_with_space(args[index]))
        {
            ++index;
            if (!evaluate_column_argument_with_space(args[index - 1], args[index]))
            {
                valid = false;
                return;
            }
        }
        else if (is_parameter_without_space(args[index], columns_parameter))
        {
            evaluate_column_argument_without_space(args[index]);
        }
        else
        {
            valid = false;
            return;
        }
        ++index;
    }
}

bool Arguments::is_parameter_without_space(const std::string &argument, const std::regex &regex)
{
    return std::regex_search(argument, regex);
}
void Arguments::evaluate_column_argument_without_space(std::string &argument)
{
    std::string type(1, argument[0]);
    argument.erase(0, 1);
    priority.push_back(std::stoll(argument) - 1);
    if (type == "N")
    {
        types[std::stoll(argument) - 1] = type;
    }
}

bool Arguments::is_column_with_space(const std::string &argument)
{
    return argument == "S" || argument == "N";
}

bool Arguments::evaluate_column_argument_with_space(const std::string &argument_left, const std::string &argument_right)
{
    std::regex number_regex("^[1-9][0-9]*$");
    if (!std::regex_search(argument_right, number_regex))
    {
        return false;
    }

    priority.push_back(std::stoll(argument_right) - 1);
    if (argument_left == "N")
    {
        types[std::stoll(argument_right) - 1] = "N";
    }
    return true;
}

void Arguments::evaluate_optional_parameters_without_space(std::string &property, std::string_view argument)
{
    argument.remove_prefix(2);
    property = {argument.begin(), argument.end()};
}

bool Arguments::evaluate_IO_with_space(std::string &filename, const std::string &argument)
{
    std::regex regex("^.*\\..*$");
    if (!std::regex_search(argument, regex))
    {
        return false;
    }
    filename = argument;
    return true;
}
