#include <stdio.h>
#include <stdlib.h>

// A        rock
// B        paper
// C        scissors

//          You
// X        lose
// Y        draw
// Z        win

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
        char result = buff_line[2];
        char your_choice;
        int win_score;
        int choice_score;

        printf("Oponent choice: %c. Result of round: %c\n", oponent_choice, result);

        switch (result)
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
            printf("Unknown result %c\n", result);
            exit(EXIT_FAILURE);

        }
        
        switch (oponent_choice)
        {
        case 'A':
            switch (result)
            {
            case 'X':
                your_choice = 'C';
                break;
            
            case 'Y':
                your_choice = 'A';
                break;
            
            case 'Z':
                your_choice = 'B';
                break;
            
            default:
                printf("Unknown result %c\n", result);
                exit(EXIT_FAILURE);
            }
            break;
        
        case 'B':
            switch (result)
            {
            case 'X':
                your_choice = 'A';
                break;
            
            case 'Y':
                your_choice = 'B';
                break;
            
            case 'Z':
                your_choice = 'C';
                break;
            
            default:
                printf("Unknown result %c\n", result);
                exit(EXIT_FAILURE);
            }
            break;
        
        case 'C':
            switch (result)
            {
            case 'X':
                your_choice = 'B';
                break;
            
            case 'Y':
                your_choice = 'C';
                break;
            
            case 'Z':
                your_choice = 'A';
                break;
            
            default:
                printf("Unknown result %c\n", result);
                exit(EXIT_FAILURE);
            }
            break;
        
        default:
            printf("Unknown choice %c\n", oponent_choice);
            exit(EXIT_FAILURE);
        }

        switch (your_choice)
        {
        case 'A':
            choice_score = 1;
            break;
        
        case 'B':
            choice_score = 2;
            break;
        
        case 'C':
            choice_score = 3;
            break;
        
        default:
            printf("Unknown choice %c\n", your_choice);
            exit(EXIT_FAILURE);
        }

        your_score = your_score + choice_score + win_score;
    }

    printf("Your score is: %i\n", your_score);

    fclose(file);
    if (buff_line)
        free(buff_line);
    exit(EXIT_SUCCESS);
}