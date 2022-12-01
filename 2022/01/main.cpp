#include <iostream>
#include <string>
#include <fstream>

const unsigned int count = 3;

int main()
{
    std::fstream input("input.txt", std::ios::in);

    std::string line = "";

    unsigned int current = 0;

    unsigned int max_1 = 0;
    unsigned int max_2 = 0;
    unsigned int max_3 = 0;

    while (getline(input, line))
    {
        if (line == "")
        {
            if (current > max_1)
                {
                    max_3 = max_2;
                    max_2 = max_1;
                    max_1 = current;
                }
            else if (current > max_2)
            {
                max_3 = max_2;
                max_2 = current;
            }
            else if (current > max_3)
            {
                max_3 = current;
            }

            current = 0;
        }
        else
        {
            current += std::stoul(line);
        }
    }

    std::cout << max_1 << std::endl
              << max_1 + max_2 + max_3 << std::endl;

    system("PAUSE");

    return 0;
}