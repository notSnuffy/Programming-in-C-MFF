#include <exception>
#include <iostream>

struct MyException
    : std::exception
{
	const char * what () const throw ()
    {
    	return "C++ Exception";
    }
};

void bar() {
    throw MyException();
}

void baz() {
    bar();
}

int main(int, char **) {
    try {
        bar();
    } catch (const MyException & e) {
        std::cerr << e.what() << std::endl;
    }
}
