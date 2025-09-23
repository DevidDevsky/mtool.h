#include "mtool.h"
#include <stdlib.h>

int main() {
    int age = m_get_int("Введите ваш возраст: ");
    double height = m_get_double("Введите ваш рост: ");
    string name = m_get_string("Введите ваше имя: ");

    m_mprintf("Имя: %s\n", name.data);
    m_mprintf("Возраст: %d\n", age);
    m_mprintf("Рост: %.2f\n", height);

    free(name.data);
    return 0;
}