#include <iostream>
#include "TemplateVB.h"

int main()
{
    std::string input1;
    std::string input2;

    while (true)
    {
        std::cout << "Geef waarde 1:";
        std::cin >> input1;

        std::cout << "Geef waarde 2:";
        std::cin >> input2;

        TemplateVB<std::string> obj;

        std::string result = obj.Sum(input1, input2);

        std::cout << "Result: " << result << std::endl;
    }
}