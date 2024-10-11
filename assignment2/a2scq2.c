#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countFileContents(const char *filename, int *lineCount, int *wordCount, int *charCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char ch;
    int inWord = 0; // Flag to track if we are in a word

    *lineCount = 0;
    *wordCount = 0;
    *charCount = 0;

    while ((ch = fgetc(file)) != EOF) {
        (*charCount)++; // Count characters

        if (ch == '\n') {
            (*lineCount)++; // Count lines
        }

        if (isspace(ch)) {
            if (inWord) {
                inWord = 0; // End of a word
            }
        } else {
            if (!inWord) {
                inWord = 1; // Start of a new word
                (*wordCount)++;
            }
        }
    }

    // If the last line does not end with a newline character, count it
    if (*charCount > 0 && ch != '\n') {
        (*lineCount)++;
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int lines, words, characters;
    countFileContents(argv[1], &lines, &words, &characters);

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    return 0;
}
