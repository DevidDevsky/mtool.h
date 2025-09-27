#ifndef MTOOL_H
#define MTOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Define the string struct used by m_get_string
typedef struct {
    char *data;
    size_t length;
} string;

// Function prototypes
int m_get_int(const char *prompt);
double m_get_double(const char *prompt);
string m_get_string(const char *prompt);
void m_mprintf(const char *format, ...);
int m_isalnum(char c);
int m_isalpha(char c);
int m_iscntrl(char c);
int m_isdigit(char c);
int m_isgraph(char c);
int m_islower(char c);
int m_isupper(char c);
int m_isprint(char c);
int m_ispunct(char c);
int m_isspace(char c);
int m_isxdigit(char c);
char m_tolower(char c);
char m_toupper(char c);

#endif // MTOOL_H
