#ifndef TREE_COMPARER_H
#define TREE_COMPARER_H

#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>

template <class MyTree, class ComparedTree, std::size_t nodes>
class TreeComparer
{
private:
    std::vector<int> data;
    template <class Tree>
    double compare_insert_duration(Tree &tree)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (const int &value : data)
        {
            tree.insert(value);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }

    void compare_insert(MyTree &my_tree, ComparedTree &compared_tree)
    {
        std::cout << "INSERT " << nodes << " NODES:"  << std::endl;
        double my_tree_duration = compare_insert_duration<MyTree>(my_tree);
        double compared_tree_duration = compare_insert_duration<ComparedTree>(compared_tree);

        std::cout << "My tree took: " << my_tree_duration << " seconds" << std::endl;
        std::cout << "Compared tree took " << compared_tree_duration << " seconds" << std::endl;
    }

    template<class Tree>
    double compare_has_value_duration(Tree &tree)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (const int &value : data)
        {
            tree.has_value(value);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }

    void compare_has_value(MyTree &my_tree, ComparedTree &compared_tree)
    {
        std::cout << "HAS VALUE " << nodes << " NODES:"  << std::endl;
        double my_tree_duration = compare_has_value_duration<MyTree>(my_tree);
        double compared_tree_duration = compare_has_value_duration<ComparedTree>(compared_tree);

        std::cout << "My tree took: " << my_tree_duration << " seconds" << std::endl;
        std::cout << "Compared tree took " << compared_tree_duration << " seconds" << std::endl;
    }

    template<class Tree>
    double compare_remove_duration(Tree &tree)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (const int &value : data)
        {
            tree.remove(value);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }

    void compare_remove(MyTree &my_tree, ComparedTree &compared_tree)
    {
        std::cout << "REMOVE " << nodes << " NODES:"  << std::endl;
        double my_tree_duration = compare_remove_duration<MyTree>(my_tree);
        double compared_tree_duration = compare_remove_duration<ComparedTree>(compared_tree);

        std::cout << "My tree took: " << my_tree_duration << " seconds" << std::endl;
        std::cout << "Compared tree took " << compared_tree_duration << " seconds" << std::endl;
    }

public:
    TreeComparer()
    {
        for (int i = 1; i <= nodes; ++i)
        {
            data.push_back(i);
        }
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(data.begin(), data.end(), std::default_random_engine(seed));
    }

    void run()
    {
        std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "COMPARE TREES WITH " << nodes << " NODES." << std::endl;
        MyTree my_tree;
        ComparedTree compared_tree;

        compare_insert(my_tree, compared_tree);
        compare_has_value(my_tree, compared_tree);
        compare_remove(my_tree, compared_tree);
        std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    }
};

#endif // TREE_COMPARER_H
