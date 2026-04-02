#ifndef TEMPLATEVB_TEMPLATE_H
#define TEMPLATEVB_TEMPLATE_H
#endif

#include <iostream>
#include <string>
#include <cctype>

template<typename T>
class TemplateVB
{
    bool isNumber(const std::string& str)
    {
        for (char c : str)
        {
            if (!std::isdigit(c))
                return false;
        }
        return true;
    }

public:
    T Sum(const T& a, const T& b)
    {
        if (isNumber(a) && isNumber(b))
        {
            return std::to_string(std::stoi(a) + std::stoi(b));
        }
        else
        {
            return a + b;
        }
    }
};

/*
 *  template<typename T, typename U=T>
 *  U add(const T& a, const T& b) {
 *      return a+b;
 *  };
 *
 *  template<>
 *      std::string add<char,std::string>(const char& a, const char& b) {
 *          std::string cas = std::string();
 *          cas += a;
 *          cas += b;
 *          return cas;
 *  }
 *
 *  std::cout << add<char,std::string>('a','b');
 *
 *  std::cout << add<char>('a', 'b');
 *  std::cout << add<char>(a, b);
 */