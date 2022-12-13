#include <iostream>
#include <fstream>
#include <string>

#define ELVES_GROUP_SIZE 3

int main() 
{
    std::ifstream file ("input.txt");
    std::string buff;
    std::string elves_group[ELVES_GROUP_SIZE];
    int result = 0;

    if (file.is_open()) 
    {
        int file_line_index = 0;
        while (file.good())
        {
            file >> buff;
            int group_index = file_line_index % ELVES_GROUP_SIZE;
            elves_group[group_index] = buff;

            std::cout << buff << std::endl;
            
            if(group_index == ELVES_GROUP_SIZE - 1) {
                std::string intersection = elves_group[0];
                std::sort(intersection.begin(), intersection.end());
                for(int i = 1; i < ELVES_GROUP_SIZE; i++) {
                    std::string group = elves_group[i];
                    std::sort(group.begin(), group.end());
                    std::string new_intersection;
                    std::set_intersection(intersection.begin(), intersection.end(), group.begin(), group.end(), std::back_inserter(new_intersection));
                    intersection = new_intersection;
                }

                std::cout << "Intersect supplies is: " << intersection << std::endl;
                char supply = intersection[0];
                int code;
                if (supply >= 'a' && supply <= 'z') {
                    code = supply - 'a' + 1;
                } else if (supply >= 'A' && supply <= 'Z') {
                    code = supply - 'A' + 27;
                }
                result += code;
                std::cout << "For supply " << supply << " code is " << code << std::endl << std::endl;
            }

            file_line_index++;
        }
    }

    std::cout << std::endl << "Result is " << result << std::endl;
    
    return 0;
}