#include <stdio.h>
#include <stdlib.h>

// Oponent  You     Choice name
// A        X       rock
// B        Y       paper
// C        Z       scissors

int main() {
    FILE * file;
    char * buff_line = NULL;
    size_t length_of_buff_line = 0;
    ssize_t read_chars_count;

    int your_score = 0;
    
    file = fopen("input.txt", "r");
    if (file == NULL)
        exit(EXIT_FAILURE);

    while ((read_chars_count = getline(&buff_line, &length_of_buff_line, file)) != -1) {
        char oponent_choice = buff_line[0];
        char your_choice = buff_line[2];
        int choice_score;
        int win_score;

        printf("Oponent choice: %c. Your choice: %c\n", oponent_choice, your_choice);

        switch (your_choice)
        {
        case 'X':
            choice_score = 1;
            break;
        
        case 'Y':
            choice_score = 2;
            break;
        
        case 'Z':
            choice_score = 3;
            break;
        
        default:
            printf("Unknown choice %c\n", your_choice);
            break;
        }
        
        switch (oponent_choice)
        {
        case 'A':
            switch (your_choice)
            {
            case 'X':
                win_score = 3;
                break;
            
            case 'Y':
                win_score = 6;
                break;
            
            case 'Z':
                win_score = 0;
                break;
            
            default:
                printf("Unknown choice %c\n", your_choice);
                break;
            }
            break;
        
        case 'B':
            switch (your_choice)
            {
            case 'X':
                win_score = 0;
                break;
            
            case 'Y':
                win_score = 3;
                break;
            
            case 'Z':
                win_score = 6;
                break;
            
            default:
                printf("Unknown choice %c\n", your_choice);
                break;
            }
            break;
        
        case 'C':
            switch (your_choice)
            {
            case 'X':
                win_score = 6;
                break;
            
            case 'Y':
                win_score = 0;
                break;
            
            case 'Z':
                win_score = 3;
                break;
            
            default:
                printf("Unknown choice %c\n", your_choice);
                break;
            }
            break;
        
        default:
            printf("Unknown choice %c\n", oponent_choice);
            break;
        }

        your_score = your_score + choice_score + win_score;
    }

    printf("Your score is: %i\n", your_score);

    fclose(file);
    if (buff_line)
        free(buff_line);
    exit(EXIT_SUCCESS);
}