// #pragma once

// #include "types.h"
// #include "table.h"
// #include <iostream>
// #include <map>
// #include <string>
// #include <regex>
// #include <vector>
// #include <memory>
// #include <string_view>

// struct Parser
// {
//     static Table read_data(std::istream &input,
//                            const std::string &delimiter,
//                            const std::map<long long, std::string> &types,
//                            bool &valid);

// private:
//     static bool convert_token(std::vector<std::unique_ptr<Type>> &row,
//                               const std::string &value,
//                               const std::string &type,
//                               const std::regex &regex,
//                               std::unique_ptr<Type> &&pointer,
//                               const std::string &token);
//     static bool get_token(std::vector<std::unique_ptr<Type>> &row,
//                           std::string &token,
//                           size_t position,
//                           const std::map<long long, std::string> &types,
//                           size_t column_count,
//                           const std::string_view &line_view);
//     static bool tokenize_line(Table &table,
//                               const std::map<long long, std::string> &types,
//                               const std::string &delimiter,
//                               const std::string &line);
// };
