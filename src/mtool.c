#include "mtool.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// --- SUM CHAR UTF8 ---
static size_t utf8_strlen(const char *s) {
    size_t count = 0;
    unsigned char *p = (unsigned char *)s;

    while (*p) {
        if ((*p & 0xC0) != 0x80) { // NOT CONTINUE MOREBYTES SYMBOLS
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

// --- JUST FOR PRINT ---
void m_mprintf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);  // DEFULT PRINTF WITH ARGS
}

// ---CHAR OR INT---
int m_isalnum(char c) {
    return ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z'));
}

// ---ONLY CHAR---
int m_isalpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// ---MANAGER CHAR (0–31, 127)---
int m_iscntrl(char c) {
    return ((c >= 0 && c <= 31) || c == 127);
}

// ---INT---
int m_isdigit(char c) {
    return (c >= '0' && c <= '9');
}

// ---(33–126)---
int m_isgraph(char c) {
    return (c >= 33 && c <= 126);
}

// ---LOWER CHAR---
int m_islower(char c) {
    return (c >= 'a' && c <= 'z');
}

// ---UPPER CHAR---
int m_isupper(char c) {
    return (c >= 'A' && c <= 'Z');
}

// ---(32–126)---
int m_isprint(char c) {
    return (c >= 32 && c <= 126);
}

// ---PUNCTUATIONS---
int m_ispunct(char c) {
    return (m_isprint(c) && !m_isalnum(c) && c != ' ');
}

// ---SPACE, TAB, \n, \r, \f, \v---
int m_isspace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\r' || c == '\f' || c == '\v');
}

// ---HEX-DIGIT---
int m_isxdigit(char c) {
    return ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'f') ||
            (c >= 'A' && c <= 'F'));
}

// ---TO LOWER---
char m_tolower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

// ---TO UPPER---
char m_toupper(char c) {
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    return c;
}