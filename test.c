#include <mtool.h>
#include <stdio.h>

int main(void)
{
    int x = m_get_int("int: ");

    printf("%i", x);
}