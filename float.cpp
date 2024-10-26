#include <iostream>
#include <bitset>
#include <climits>

int main()
{
    union
    {
        float input;
        int output;
    } data;

    data.input = 1;

    std::bitset<sizeof(float) * CHAR_BIT> bits(data.output);
    std::cout << bits << std::endl;

    float smt = 16777216;
    float aaa = smt + 1;
    std::cout << aaa - smt << "\n";

    /// for (int i = 1; i < 100000000; i++)
    ///{
    ///     float x = i;
    ///     if (x == x + 1)
    ///     {
    ///         std::cout << i;
    ///         break;
    ///     }
    /// }
    float sum = 0;
    float n = 2.09716e+06;
    for (float k = 1; k <= n; ++k)
    {
        if (sum == sum + 1 / k)
        {
            std::cout << k << "\n";
            break;
        }
        sum += 1 / k;
    }
    std::cout << sum << "\n";

    float part_sum1 = 0;
    float part_sum2 = 0;
    for (float k = 1; k <= 2.09715e+06 + 100; ++k)
    {
        part_sum1 += 1 / k;
    }
    std::cout << part_sum1 << "\n";
    for (float k = 2.09715e+06 + 100; k >= 1; --k)
    {
        part_sum2 += 1 / k;
    }
    std::cout << part_sum2 << "\n";
    float a = 0.001, eps = 0.000001;
    if (a == 0.001)
    {
        std::cout << 'YES';
    }
    if (a - 0.001 <= eps)
    {
        std::cout << "AHAHAHA";
    }
    if (((1000000000000*1.0 + 1) - 1000000000000*1.0) == (1000000000000*1.0 - 1000000000000*1.0) + 1) {
        std::cout << "YES";
    }
}