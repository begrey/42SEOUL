#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        std::string speak(argv[i]);
        for (int j = 0; j < (int)speak.length(); j++)
            speak[j] = toupper(speak[j]);
        std::cout << speak;
    }
    std::cout << std::endl;
    return 0;
}