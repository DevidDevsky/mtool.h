#include <stdio.h>
#include <stdarg.h>
#include "mtool.h"

// --- JUST FOR PRINT ---
void m_mprintf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);  // DEFULT PRINTF WITH ARGS
}