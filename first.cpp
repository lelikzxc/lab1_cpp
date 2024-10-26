#include <iostream>
int main()
{
    int num = 0;
    for (int i = 32; i >= 0; --i)
    {
        std::cout << ((num << i) & 1) << "";
    }
    std::cout << "\n";
    unsigned int lol = -1;
    for (int i = 32; i >= 0; --i)
    {
        std::cout << ((lol << i) & 1) << "";
    }
    std::cout << "\n";
    int a = INT_MAX + 1;
    std::cout << INT_MAX;
    std::cout << "\n";
    std::cout << a;
    std::cout << "\n";
    for (int i = 32; i >= 0; --i)
    {
        std::cout << ((a << i) & 1) << "";
    }
    std::cout << "\n";
    unsigned int b = 0 - 1;
    std::cout << b;
    std::cout << "\n";
    for (int i = 32; i >= 0; --i)
    {
        std::cout << ((b << i) & 1) << "";
    }
}