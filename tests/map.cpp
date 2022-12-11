#include "tests.hpp"
#include <map>
#include <utility>

template <class T>
static void print_map(T &map)
{
    typename T::iterator it = map.begin();
    std::cout << " --- Map of size " << map.size() << " ---" << std::endl;
    while (it != map.end())
    {
        std::cout << it->first << ": " << it->second << std::endl;
        ++it;
    }
    std::cout << " --- " << std::endl;
}

void test_map(void)
{
    print_header("Map");
}