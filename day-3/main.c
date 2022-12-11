#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE * file;
    char * buff_line = NULL;
    size_t length_of_buff_line = 0;
    ssize_t read_chars_count;

    int prioritize = 0;
    
    file = fopen("input.txt", "r");
    if (file == NULL)
        exit(EXIT_FAILURE);

    while ((read_chars_count = getline(&buff_line, &length_of_buff_line, file)) != -1) {
        size_t compartment_size = (read_chars_count / 2) * sizeof(char);
        char compartment1[compartment_size];
        char compartment2[compartment_size];

        char supplies_in_rucksack[compartment_size];
        int count_of_supplies_in_rucksack = 0;

        memcpy(compartment1, &buff_line[0], compartment_size);
        memcpy(compartment2, &buff_line[read_chars_count / 2], compartment_size);
        compartment1[compartment_size] = '\0';
        compartment2[compartment_size] = '\0';

        printf("Supplies in rucksack:\t\t%s", buff_line);
        printf("Supplies in first compartment:\t%s\n", compartment1);
        printf("Supplies in second compartment:\t%s\n", compartment2);

        for (int i = 0; i < compartment_size; i = i + 1) {
            char current_supply_from_complartment1 = compartment1[i];
            for (int j = 0; j < compartment_size; j = j + 1) {
                char current_supply_from_complartment2 = compartment2[j];
                if (current_supply_from_complartment1 == current_supply_from_complartment2 
                    && strchr(supplies_in_rucksack, current_supply_from_complartment1) == NULL) {
                    int code = (int)current_supply_from_complartment1;
                    printf("Found match for %c. Code is %i\n", current_supply_from_complartment1, code);
                    if(code >= 65 && code <= 90) { // for uppercase
                        code = code - 65 + 27; // 27 here is overstocked for lowercase
                    } else if (code >= 97 && code <= 122) { // for lowercase
                        code = code - 96;
                    } else {
                        printf("Input %c is not supported character\n", current_supply_from_complartment1);
                        exit(EXIT_FAILURE);
                    }
                    printf("Prioritize is %i\n", code);
                    prioritize = prioritize + code;
                    supplies_in_rucksack[count_of_supplies_in_rucksack] = current_supply_from_complartment1;
                    count_of_supplies_in_rucksack = count_of_supplies_in_rucksack + 1;
                    break;
                }
            }
        }
        printf("\n");
    }

    printf("Total prioritize is %i\n", prioritize);

    fclose(file);
    if (buff_line)
        free(buff_line);
    exit(EXIT_SUCCESS);
}