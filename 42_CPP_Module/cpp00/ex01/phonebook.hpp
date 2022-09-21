#ifndef _PHONEBOOK_HPP
#define _PHONEBOOK_HPP
#include <iostream>

class phoneBook {
private:
    //멤버변수
    std::string f_name;
    std::string l_name;
    std::string nickname;
    std::string phone;
    std::string secret;

public:
    //생성자
    phoneBook()
    {
        this->f_name = "";
        this->l_name = "";
        this->nickname = "";
        this->phone = "";
        this->secret = "";
        //std::cout << "default phonebook." << std::endl;
    }
    phoneBook(std::string f_name, std::string l_name, std::string nickname, std::string phone, std::string secret) {
        this->f_name = f_name;
        this->l_name = l_name;
        this->nickname = nickname;
        this->phone = phone;
        this->secret = secret;
    }
    std::string getFname(){
        return f_name;
    }
    std::string getLname(){
        return l_name;
    }
    std::string getNickname(){
        return nickname;
    }
    std::string getPhone(){
        return phone;
    }
    std::string getSecret(){
        return secret;
    }
    void setFname(std::string n){
        this->f_name = n;
    }
    void setLname(std::string n){
        this->l_name = n;
    }
    void setNickname(std::string n){
        this->nickname = n;
    }
    void setPhone(std::string p){
        this->phone = p;
    }
    void setSecret(std::string s){
        this->secret = s;
    }
};
#endif