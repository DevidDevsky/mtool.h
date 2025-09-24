#include "mtool.h"

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