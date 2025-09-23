#ifndef MTOOL_H
#define MTOOL_H

#include <stddef.h> 

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
int m_misdigit(char c);
int m_misalpha(char c);
char m_mto_lower(char c);
char m_mto_upper(char c);

#endif