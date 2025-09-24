#include <stdio.h>
#include <string.h>
#include "mtool.h"

// --- SUM CHAR UTF8 ---
static size_t utf8_strlen(const char *s) {
    size_t count = 0;
    unsigned char *p = (unsigned char *)s;

    while (*p) {
        if ((*p & 0xC0) != 0x80) { // не продолжение многобайтового символа
            count++;
        }
        p++;
    }
    return count;
}

// --- INTPUT INT ---
int m_get_int(const char *prompt) {
    int n;
    char buf[100];

    while (1) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) {  // READ STRING
            clearerr(stdin);
            continue;
        }

        if (sscanf(buf, "%d", &n) == 1) {
            return n;
        } else {
            printf("Неверный ввод. Попробуйте снова.\n");
        }
    }
}

// --- INPUT FLOAT ---
double m_get_double(const char *prompt) {
    double n;
    char buf[100];

    while (1) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) {
            clearerr(stdin);
            continue;
        }

        if (sscanf(buf, "%lf", &n) == 1) {
            return n;
        } else {
            printf("Неверный ввод. Попробуйте снова.\n");
        }
    }
}

// --- INPUT STRING ---
string m_get_string(const char *prompt) {
    printf("%s", prompt);

    size_t capacity = 100;
    char *buffer = malloc(capacity);
    if (!buffer) { fprintf(stderr, "Ошибка выделения памяти\n"); exit(1); }

    int c;
    size_t length_bytes = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (length_bytes + 1 >= capacity) {
            capacity *= 2;
            buffer = realloc(buffer, capacity);
            if (!buffer) { fprintf(stderr, "Ошибка выделения памяти\n"); exit(1); }
        }
        buffer[length_bytes++] = (char)c;
    }
    buffer[length_bytes] = '\0';

    string s;
    s.data = buffer;
    s.length = utf8_strlen(buffer); 
    return s;
}