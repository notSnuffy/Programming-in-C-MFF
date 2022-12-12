#include <iostream>

struct Histogram {
    Histogram(std::istream & input) : input(input) {}

    std::size_t char_count(char c) const {
        char x;
        std::size_t count;
        while(input >> x) {
            if (x == c) ++count;
        }
        return count;
    }

    std::size_t word_length(std::size_t length) const {
        return 0;
    }

    std::size_t line_length(std::size_t length) const {
        return 0;
    }

 private:
    std::istream & input;
    // Define your containers here

    void process() {
        // read the chars, word and line lengths count from the input and store them in a container
    }
};
