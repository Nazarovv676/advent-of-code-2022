#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * file;
    char * buffLine = NULL;
    size_t lengthOfBuffLine = 0;
    ssize_t readCharsCount;
    int elfesCounter = 0;
    int currentElfRecordsCount = 0;
    int currentElfCallories = 0;
    int maxCallories = 0;
    int maxCalloriesElfIndex = 0;
    int elfesLoopIndex = 0;

    file = fopen("input.txt", "r");
    if (file == NULL)
        exit(EXIT_FAILURE);


    while ((readCharsCount = getline(&buffLine, &lengthOfBuffLine, file)) != -1) {
        if (readCharsCount == 1) {
            if (currentElfCallories > maxCallories) {
                maxCallories = currentElfCallories;
                maxCalloriesElfIndex = elfesCounter;
            }

            printf("Records count: %i\n", currentElfRecordsCount);
            elfesCounter = elfesCounter + 1;
            currentElfRecordsCount = 0;

            printf("Elf callories count: %i\n", currentElfCallories);
            currentElfCallories = 0;

            elfesLoopIndex = elfesLoopIndex + 1;
            continue;
        }
        int buffNumber;
        sscanf(buffLine, "%i", &buffNumber);
        printf("%i\n", buffNumber);
        currentElfCallories = currentElfCallories + buffNumber;
        currentElfRecordsCount = currentElfRecordsCount + 1;
        elfesLoopIndex = elfesLoopIndex + 1;
    }
    if(elfesLoopIndex != 0) { // file is not empty
        if (currentElfCallories > maxCallories) {
            maxCallories = currentElfCallories;
            maxCalloriesElfIndex = elfesCounter;
        }

        printf("Records count: %i\n", currentElfRecordsCount);
        elfesCounter = elfesCounter + 1;
        currentElfRecordsCount = 0;

        printf("Elf callories count: %i\n", currentElfCallories);
        currentElfCallories = 0;
    }

    printf("Count of Elfes: %i\n", elfesCounter);
    printf("Elf with %i callories count is %i\n", maxCallories, maxCalloriesElfIndex + 1);

    fclose(file);
    if (buffLine)
        free(buffLine);
    exit(EXIT_SUCCESS);
}