#include <iostream>
#include <string>
#include <utility>

    std::string bounce(std::string str)
{
    int m = 0;
    int n = str.size() - 1;

    while (m < n)
    {
        m = str.find_first_of("trampoline", m);
        n = str.find_last_of("trampoline", n);
        if (m < n)
        {
            std::swap(str[m++], str[n--]);
        }
    }

    return str;
}

int main()
{
    std::string mashed = bounce("potatobot");
    std::cout << mashed << std::endl;

    std::string alphabet = "abcdefghijklmnop";
    std::cout << alphabet.find_first_of("b", 2);

    
}
