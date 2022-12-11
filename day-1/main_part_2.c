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
    int maxCallories1 = 0;
    int maxCalloriesElfIndex1 = 0;
    int maxCallories2 = 0;
    int maxCalloriesElfIndex2 = 0;
    int maxCallories3 = 0;
    int maxCalloriesElfIndex3 = 0;
    int elfesLoopIndex = 0;

    file = fopen("input.txt", "r");
    if (file == NULL)
        exit(EXIT_FAILURE);


    while ((readCharsCount = getline(&buffLine, &lengthOfBuffLine, file)) != -1) {
        if (readCharsCount == 1) {
            if (currentElfCallories > maxCallories1) {
                // 3 <- 2
                maxCallories3 = maxCallories2;
                maxCalloriesElfIndex3 = maxCalloriesElfIndex2;

                // 2 <- 1
                maxCallories2 = maxCallories1;
                maxCalloriesElfIndex2 = maxCalloriesElfIndex1;

                // 1 <- new
                maxCallories1 = currentElfCallories;
                maxCalloriesElfIndex1 = elfesCounter;
            } else if (currentElfCallories > maxCallories2) {
                // 3 <- 2
                maxCallories3 = maxCallories2;
                maxCalloriesElfIndex3 = maxCalloriesElfIndex2;

                // 2 <- new
                maxCallories2 = currentElfCallories;
                maxCalloriesElfIndex2 = elfesCounter;
            } else if (currentElfCallories > maxCallories3) {
                // 3 <- new
                maxCallories3 = currentElfCallories;
                maxCalloriesElfIndex3 = elfesCounter;
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
        if (currentElfCallories > maxCallories1) {
            // 3 <- 2
            maxCallories3 = maxCallories2;
            maxCalloriesElfIndex3 = maxCalloriesElfIndex2;

            // 2 <- 1
            maxCallories2 = maxCallories1;
            maxCalloriesElfIndex2 = maxCalloriesElfIndex1;

            // 1 <- new
            maxCallories1 = currentElfCallories;
            maxCalloriesElfIndex1 = elfesCounter;
        } else if (currentElfCallories > maxCallories2) {
            // 3 <- 2
            maxCallories3 = maxCallories2;
            maxCalloriesElfIndex3 = maxCalloriesElfIndex2;

            // 2 <- new
            maxCallories2 = currentElfCallories;
            maxCalloriesElfIndex2 = elfesCounter;
        } else if (currentElfCallories > maxCallories3) {
            // 3 <- new
            maxCallories3 = currentElfCallories;
            maxCalloriesElfIndex3 = elfesCounter;
        }

        printf("Records count: %i\n", currentElfRecordsCount);
        elfesCounter = elfesCounter + 1;
        currentElfRecordsCount = 0;

        printf("Elf callories count: %i\n", currentElfCallories);
        currentElfCallories = 0;
    }

    printf("Count of Elfes: %i\n", elfesCounter);
    printf("Top 3 Elves callories count %i\n", maxCallories1 + maxCallories2 + maxCallories3);

    fclose(file);
    if (buffLine)
        free(buffLine);
    exit(EXIT_SUCCESS);
}