#include <iostream>
#include <string>


int main(int ac, char **av)
{
    std::string upper;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    for (int i = 1; av[i]; i++)
    {
        for(int j = 0; av[i][j]; j++)
        {
            upper = toupper(av[i][j]);
            std:: cout << upper;
        }
        if (ac != 2)
            std :: cout << " ";
    }
    std :: cout << std::endl;
    return (0);
}