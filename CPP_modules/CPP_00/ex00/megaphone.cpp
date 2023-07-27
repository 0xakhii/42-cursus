#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        for (int i = 1; av[i]; i++)
        {
            for(int j = 0; av[i][j]; j++)
                av[i][j] = toupper(av[i][j]);
            std:: cout << av[i];
            if (ac != 2)
                std :: cout << " ";
        }
        std :: cout << "\n";
    }
    return (0);
}