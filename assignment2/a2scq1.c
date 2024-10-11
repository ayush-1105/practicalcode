#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copyAndConvert(const char *sourceFile, const char *destFile) {
    FILE *src = fopen(sourceFile, "r");
    FILE *dest = fopen(destFile, "w");

    if (src == NULL) {
        fprintf(stderr, "Error opening source file: %s\n", sourceFile);
        exit(1);
    }

    if (dest == NULL) {
        fprintf(stderr, "Error opening destination file: %s\n", destFile);
        fclose(src);
        exit(1);
    }

    char ch;
    while ((ch = fgetc(src)) != EOF) {
        // Check if the character is a vowel or consonant
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            fputc(toupper(ch), dest); // Convert vowels to uppercase
        } else if (isalpha(ch)) {
            fputc(tolower(ch), dest); // Convert consonants to lowercase
        } else {
            fputc(ch, dest); // Copy other characters as is
        }
    }

    fclose(src);
    fclose(dest);
    printf("File copied and converted successfully from %s to %s\n", sourceFile, destFile);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    copyAndConvert(argv[1], argv[2]);

    return 0;
}
