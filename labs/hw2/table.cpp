// #include "table.h"
// #include <string>
// #include <iostream>
// #include <vector>
// #include <memory>
// #include <map>
// #include <regex>
// #include <algorithm>
// #include <string_view>

// bool validate_table(const Table &table)
// {
//     for (size_t i = 0; i < table.size() - 1; ++i)
//     {
//         if (table[i].size() != table[i + 1].size())
//         {
//             return false;
//         }
//     }
//     return true;
// }

// void sort(Table &table, const std::vector<long long> &priority)
// {
//     std::sort(table.begin(), table.end(), [&priority](const std::vector<std::unique_ptr<Type>> &row_a, const std::vector<std::unique_ptr<Type>> &row_b)
//               { 
//                 long long column = priority[0];
//                 for(size_t i = 0; i < priority.size(); ++i) {
//                     column = priority[i];
//                     if(*row_a.at(column) != *row_b.at(column)) {
//                         return *row_a.at(column) < *row_b.at(column);
//                     }
//                 }
//                 return *row_a.at(column) == *row_b.at(column); });
// }

// void print_table(std::ostream &output, const Table &table, const std::string &delimiter)
// {
//     for (auto &&row : table)
//     {
//         for (size_t j = 0; j < row.size() - 1; ++j)
//         {
//             row[j]->print(output);
//             output << delimiter;
//         }
//         row[row.size() - 1]->print(output);
//         output << std::endl;
//     }
// }
