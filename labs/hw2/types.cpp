#include "types.h"

String::String(const std::string & _value)
{
    value = _value;
}
void String::print(std::ostream &output) const
{
    output << value;
}

bool String::operator==(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const String &>(other);
    return value == casted_other.value;
}

bool String::operator!=(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const String &>(other);
    return value != casted_other.value;
}

bool String::operator<(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const String &>(other);
    return value < casted_other.value;
}

bool String::operator>(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const String &>(other);
    return value > casted_other.value;
}

bool String::operator<=(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const String &>(other);
    return value <= casted_other.value;
}

bool String::operator>=(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const String &>(other);
    return value >= casted_other.value;
}

Numeric::Numeric(long long _value)
{
    value = _value;
}
void Numeric::print(std::ostream &output) const
{
    output << value;
}

bool Numeric::operator==(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const Numeric &>(other);
    return value == casted_other.value;
}

bool Numeric::operator!=(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const Numeric &>(other);
    return value != casted_other.value;
}

bool Numeric::operator<(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const Numeric &>(other);
    return value < casted_other.value;
}

bool Numeric::operator>(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const Numeric &>(other);
    return value > casted_other.value;
}

bool Numeric::operator<=(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const Numeric &>(other);
    return value <= casted_other.value;
}

bool Numeric::operator>=(const Type &other) const
{
    auto &&casted_other = dynamic_cast<const Numeric &>(other);
    return value >= casted_other.value;
}


bool Parser::convert_token(std::vector<std::unique_ptr<Type>> &row,
                           const std::string &value,
                           const std::string &type,
                           const std::regex &regex,
                           std::unique_ptr<Type> &&pointer,
                           const std::string &token)
{
    if (value == type)
    {
        if (!std::regex_search(token, regex))
        {
            return false;
        }
        row.push_back(std::move(pointer));
    }
    return true;
}

bool Parser::tokenize_line(Table &table,
                           const std::map<long long, std::string> &types,
                           const std::string &delimiter,
                           const std::string &line)
{
    std::string_view line_view = line;
    std::vector<std::unique_ptr<Type>> row;
    size_t position = 0;
    std::string token;

    size_t column_count = 0;
    while ((position = line_view.find(delimiter)) != std::string_view::npos)
    {

        if (!get_token(row, token, position, types, column_count, line_view))
        {
            return false;
        }
        line_view.remove_prefix(position + delimiter.length());
        ++column_count;
    }

    if (!get_token(row, token, position, types, column_count, line_view))
    {
        return false;
    }

    table.push_back(std::move(row));
    return true;
}

bool Parser::get_token(std::vector<std::unique_ptr<Type>> &row,
                       std::string &token,
                       size_t position,
                       const std::map<long long, std::string> &types,
                       size_t column_count,
                       const std::string_view &line_view)
{
    std::string_view token_view = line_view.substr(0, position);
    token = {token_view.begin(), token_view.end()};
    if (auto search = types.find(column_count); search != types.end())
    {
        if (!convert_token(row, search->second, "N", std::regex("^-?[0-9]+$"), std::move(std::make_unique<Numeric>(std::stoll(token))), token))
        {
            return false;
        }
    }
    else
    {
        row.push_back(std::make_unique<String>(token));
    }
    return true;
}

Table Parser::read_data(std::istream &input,
                        const std::string &delimiter,
                        const std::map<long long, std::string> &types,
                        bool &valid)
{
    std::string line;
    Table table;
    while (std::getline(input, line))
    {
        if (!tokenize_line(table, types, delimiter, line))
        {
            valid = false;
        }
    }

    if (!validate_table(table))
    {
        valid = false;
    }

    return table;
}



bool validate_table(const Table &table)
{
    for (size_t i = 0; i < table.size() - 1; ++i)
    {
        if (table[i].size() != table[i + 1].size())
        {
            return false;
        }
    }
    return true;
}

void sort(Table &table, const std::vector<long long> &priority)
{
    std::sort(table.begin(), table.end(), [&priority](const std::vector<std::unique_ptr<Type>> &row_a, const std::vector<std::unique_ptr<Type>> &row_b)
              { 
                long long column = priority[0];
                for(size_t i = 0; i < priority.size(); ++i) {
                    column = priority[i];
                    if(*row_a.at(column) != *row_b.at(column)) {
                        return *row_a.at(column) < *row_b.at(column);
                    }
                }
                return *row_a.at(column) == *row_b.at(column); });
}

void print_table(std::ostream &output, const Table &table, const std::string &delimiter)
{
    for (auto &&row : table)
    {
        for (size_t j = 0; j < row.size() - 1; ++j)
        {
            row[j]->print(output);
            output << delimiter;
        }
        row[row.size() - 1]->print(output);
        output << std::endl;
    }
}

