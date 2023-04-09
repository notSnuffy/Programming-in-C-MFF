#include <string>
#include <iostream>
#include <regex>
#include <map>
#include <fstream>
#include "types.h"
#include "args.h"

int main(int argc, char const *argv[])
{
    if(argc == 1) {
        return 0;
    }
    
    std::vector<std::string> args(argv, argv + argc);
    args.erase(args.begin());

    bool valid = true;
    Arguments arguments;
    arguments.get_arguments(args, valid);
    
    if(!valid) {
        return 0;
    }

    Table table;
    if (arguments.filename == "")
    {
        table = Parser::read_data(std::cin, arguments.delimiter, arguments.types, valid);
    }
    else
    {
        std::ifstream input{arguments.filename};
        if (!input.good())
        {
            return 0;
        }
        table = Parser::read_data(input, arguments.delimiter, arguments.types, valid);
        input.close();
    }

    if (!valid)
    {
        return 0;
    }
    
    sort(table, arguments.priority);
    
    if (arguments.output_filename == "")
    {
        print_table(std::cout, table, arguments.delimiter);
    }
    else
    {
        std::ofstream output(arguments.output_filename);
        print_table(output, table, arguments.delimiter);
        output.close();
    }

    return 0;
}
