#include <iostream>
#include <string>
#include <iomanip>
#include "phonebook.hpp"

std::string * set_input(void)
{
    std::string *input = new std::string[5];

    input[0] = "first name";
    input[1] = "last name";
    input[2] = "nickname";
    input[3] = "phone number";
    input[4] = "dark secret";
    return (input);
}

void add_phonebook(phoneBook *pb, int num)
{
    std::string *input = new std::string[5];
    std::string field[5];

    input = set_input();
    num %= 8;
    for (int i = 0; i < 5; i++)
    {
        std::cout << input[i] << ": ";
        std::cin >> field[i];
        if (std::cin.eof())
        {
            std::cin.ignore();
            std::cout << "EOF" <<std::endl;
            exit(0);
        }
    }
    pb[num] = phoneBook(field[0], field[1], field[2], field[3], field[4]);
}

void print(std::string field)
{
    if ((int)field.length() > 10)
    {
        field = field.substr(0,9);
        field += ".";
    }
    std::cout << std::setw(10) << std::right << field << "|"; 
}

void print_contact(phoneBook pb)
{

    std::cout << pb.getFname() << std::endl;
    std::cout << pb.getLname() << std::endl;
    std::cout << pb.getNickname() << std::endl;
    std::cout << pb.getPhone() << std::endl;
    std::cout << pb.getSecret() << std::endl;
}

void search_phonebook(phoneBook *pb, int num)
{
    int index;

    if (num == 0)
    {
        std::cout << "No Contact! please ADD contact!" << std::endl;
        return ;
    }
    if (num > 8)
        num = 8;
    for (int i = 0; i < num; i++)
    {
        print(std::to_string(i + 1));
        print(pb[i].getFname());
        print(pb[i].getLname());
        print(pb[i].getNickname());
        std::cout << std::endl;
    }
    std::cout << "Enter index to show full page: ";
    std::cin >> index;
    if (std::cin.eof())
    {
        std::cin.ignore();
        std::cout << "EOF" <<std::endl;
        exit(0);
    }
    else if (index > num || index < 1 || std::cin.fail())
    {
        std::cout << "Wrong index!!" << std::endl;
        std::cin.clear();
    }
    else 
        print_contact(pb[index- 1]);
}

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        std::cout << argv[1] << "NOT ALLOWED ARGUMENT" << std::endl;
        return 0;
    }
    int num = 0;
    std::string command;
    phoneBook pb[8];
    do
    {
        std::cout << "Enter Command [ADD] OR [SEARCH] OR [EXIT] : ";
        std::cin >> command;
        if (std::cin.eof())
            break;
        else if ((command.compare("ADD")) == 0)
        {
            add_phonebook(pb, num);
            num++;
        }
        else if ((command.compare("SEARCH")) == 0)
            search_phonebook(pb, num);
        std::cin.ignore();
    } while(command.compare("EXIT"));
    //delete pb;
    std::cout << "EXIT XD" << std::endl;
    return 0;
}