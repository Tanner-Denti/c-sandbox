#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


int roman_char_to_int(char character) {
    switch (tolower(character)) {
        case 'i': return 1;
        case 'v': return 5;
        case 'x': return 10;
        case 'l': return 50;
        case 'c': return 100;
        case 'd': return 500;
        case 'm': return 1000;
        default: return 0;
    }
}

int roman_str_to_int(char *str) {
    int prev = 0;
    int res = 0;
    int len = strlen(str);
    int final_index = 0;

    if (len > 0 && str[0] == '-') {
        final_index = 1;
    }

    for (int i = len - 1; i >= final_index; i--) {
        int cur = roman_char_to_int(str[i]);

        if (cur >= prev) {
            res += cur;
        } else {
            res -= cur;
        }

        prev = cur;
    }

    if (final_index == 1) return -res;

    return res;
}

bool is_valid_int(char *str) {
    if (*str == '-') {
        str++;
    }

    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    
    return true;
}

bool is_valid_roman_numeral(char *str) {

    char *valid_roman_numerals = "IVXLCDMivxlcdm";

    if (*str == '-') {
        str++;
    }

    while (*str) {
        if (strchr(valid_roman_numerals, *str) == NULL) {
            return false;
        }
        str++;
    }

    return true;
}

int main(int argc, char** argv) {

    if (argc == 1) {
        printf("0");
        return 0;
    } 

    int sum = 0;
    for (int i = 1; i < argc; i++) {
        if (is_valid_int(argv[i])) {
            sum += atoi(argv[i]);
        } else if (is_valid_roman_numeral(argv[i])) {
            sum += roman_str_to_int(argv[i]);
        } else {
            printf("Invalid input: %s", argv[i]);
            return 1;
        }
    }

    printf("%d", sum);

    return 0;
}
