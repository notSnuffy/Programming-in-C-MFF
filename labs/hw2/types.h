#pragma once

#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <vector>
#include <memory>
#include <string_view>
#include <algorithm>


class Type
{
public:
    virtual ~Type() = default;
    virtual void print(std::ostream &output) const = 0;
    virtual bool operator==(const Type &other) const = 0;
    virtual bool operator!=(const Type &other) const = 0;
    virtual bool operator<(const Type &other) const = 0;
    virtual bool operator>(const Type &other) const = 0;
    virtual bool operator<=(const Type &other) const = 0;
    virtual bool operator>=(const Type &other) const = 0;
};

class String : public Type
{
private:
    std::string value;

public:
    String(const std::string &_value);
    void print(std::ostream &output) const;
    bool operator==(const Type &other) const;
    bool operator!=(const Type &other) const;
    bool operator<(const Type &other) const;
    bool operator>(const Type &other) const;
    bool operator<=(const Type &other) const;
    bool operator>=(const Type &other) const;
};

class Numeric : public Type
{
private:
    int value;

public:
    Numeric(long long _value);
    void print(std::ostream &output) const;
    bool operator==(const Type &other) const;
    bool operator!=(const Type &other) const;
    bool operator<(const Type &other) const;
    bool operator>(const Type &other) const;
    bool operator<=(const Type &other) const;
    bool operator>=(const Type &other) const;
};

using Table = std::vector<std::vector<std::unique_ptr<Type>>>;

bool validate_table(const Table &table);

void sort(Table &table, const std::vector<long long> &priority);

void print_table(std::ostream &output, const Table &table, const std::string &delimiter);

struct Parser
{
    static Table read_data(std::istream &input,
                           const std::string &delimiter,
                           const std::map<long long, std::string> &types,
                           bool &valid);

private:
    static bool convert_token(std::vector<std::unique_ptr<Type>> &row,
                              const std::string &value,
                              const std::string &type,
                              const std::regex &regex,
                              std::unique_ptr<Type> &&pointer,
                              const std::string &token);
    static bool get_token(std::vector<std::unique_ptr<Type>> &row,
                          std::string &token,
                          size_t position,
                          const std::map<long long, std::string> &types,
                          size_t column_count,
                          const std::string_view &line_view);
    static bool tokenize_line(Table &table,
                              const std::map<long long, std::string> &types,
                              const std::string &delimiter,
                              const std::string &line);
};

