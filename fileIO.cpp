#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>

// 读取所有空格隔开的字符
std::string ReadDataFromFile() {
    std::ostringstream ret;
    std::ifstream fin("data.txt");

    if(!fin.is_open()) {
        
    }

    std::string s;
    while(fin>>s) {
        ret<<s<<" ";
    }
    fin.close();
    return ret.str();
}

// 
std::string ReadDataFromFileLinebyLine() {
    std::ostringstream ret;
    std::ifstream fin("data.txt");
    if(!fin.is_open()) {

    }
    std::string s;
    while(std::getline(fin, s)) {
        ret<<s<<"\n";
    }
    fin.close();
    return ret.str();
}



int main() {


    return 0;
}