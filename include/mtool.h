#ifndef MTOOL_H
#define MTOOL_H

#include <stddef.h> 
#include <stdlib.h> 

// --- TYPE STRING ---
typedef struct {
    char *data;      // STRING
    size_t length;   // LENGTH STRING
} string;

// --- INPUT ---
int m_get_int(const char *prompt);
double m_get_double(const char *prompt);
string m_get_string(const char *prompt);

// --- PRINT ---
void m_mprintf(const char *format, ...);

// --- MATH ---
int m_mfactorial(int n);
double m_mpow(double base, double exp);
double m_msqrt(double x);

// --- CTYPE ---
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

#endif