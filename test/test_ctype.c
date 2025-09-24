#include <stdio.h>
#include "mtool.h"

int main(void) {
    char a = 'A';
    char b = 'z';
    char d = '5';
    char sp = ' ';
    char ex = '!';

    printf("m_isalnum('%c') = %d\n", d, m_isalnum(d));
    printf("m_isalpha('%c') = %d\n", a, m_isalpha(a));
    printf("m_iscntrl('\\n') = %d\n", m_iscntrl('\n'));
    printf("m_isdigit('%c') = %d\n", d, m_isdigit(d));
    printf("m_isgraph('%c') = %d\n", ex, m_isgraph(ex));
    printf("m_islower('%c') = %d\n", b, m_islower(b));
    printf("m_isupper('%c') = %d\n", a, m_isupper(a));
    printf("m_isprint('%c') = %d\n", sp, m_isprint(sp));
    printf("m_ispunct('%c') = %d\n", ex, m_ispunct(ex));
    printf("m_isspace(' ') = %d\n", m_isspace(sp));
    printf("m_isxdigit('%c') = %d\n", 'F', m_isxdigit('F'));

    printf("m_tolower('%c') = %c\n", a, m_tolower(a));
    printf("m_toupper('%c') = %c\n", b, m_toupper(b));

    return 0;
}