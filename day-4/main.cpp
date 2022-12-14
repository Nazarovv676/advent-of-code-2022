#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#define ELVES_GROUP_SIZE 3

int main() 
{
    std::ifstream file ("input.txt");
    std::regex regex("^(\\d+)-(\\d+),(\\d+)-(\\d+)$");
    std::string buff;
    int result = 0;

    if (file.is_open()) 
    {
        while (file.good())
        {
            buff.clear();
            file >> buff;

            std::smatch match;
            bool is_match = std::regex_match(buff, match, regex);
            if(!is_match) {
                continue;
            }
            int a1 = std::stoi(match[1].str());
            int a2 = std::stoi(match[2].str());
            int b1 = std::stoi(match[3].str());
            int b2 = std::stoi(match[4].str());

            std::cout << buff << std::endl;


            if(b1 <= a1 && a2 <= b2 || a1 <= b1 && b2 <= a2) {
                result++;
                std::cout << "Found" << std::endl;
            }

            std::cout << std::endl;
        }
    }

    std::cout << std::endl << "Result is " << result << std::endl;
    
    return 0;
}