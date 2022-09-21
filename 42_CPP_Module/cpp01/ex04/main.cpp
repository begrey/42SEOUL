#include "replace.hpp"
// * c++에서는 RAII 이 지원됨, 즉 소멸자가 있어서 close가 필수적이지 않다.

void op_and_wr_file(std::string file, std::string str1, std::string str2)
{
    std::string line;
    std::string::size_type n;
    std::string str;

    std::ifstream fin(file); // ? 파일 읽기
    if (fin.fail()) {
        std::cerr << "FILE FIN ERROR" << std::endl;
        exit(100);
    }
    std::string output = file + ".replace";
    std::ofstream fout(output); // ? 파일 쓰기
    if (fout.fail()) {
        std::cerr << "FILE FOUT ERROR" << std::endl;
        exit(100);
    }
    while (std::getline(fin, line)) {
        while ((n = line.find(" ")) != std::string::npos) {
            str = line.substr(0, n);
            if (str == str1) 
                fout << str2 << " ";
            else if (str != " ")
                fout << str << " ";
            line = line.substr(n + 1, std::string::npos); // ? npos일경우 알아서 문자열 끝까지 지정
        }
        if (line == str1) 
            fout << str2;
        else if (line != " ")
            fout << line;
        if (!fin.eof())
            fout << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
        std::cout << "Input : [filename] [string1] [string2]" << std::endl;
    else
    {
        std::string filename = argv[1];
        std::string str1 = argv[2];
        std::string str2 = argv[3];
        if (str1.empty() || str2.empty())
            std::cout << "string is empty" << std::endl;
        else
            op_and_wr_file(filename, str1, str2);
    }

    return 0;
}