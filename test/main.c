#include <stdio.h>
#include <stdlib.h>
#include "mtool.h"

int main() {
    // --- Тест m_get_int ---
    int age = m_get_int("Введите ваш возраст: ");
    printf("Вы ввели целое число: %d\n", age);

    // --- Тест m_get_double ---
    double height = m_get_double("Введите ваш рост (например, 1.75): ");
    printf("Вы ввели число с плавающей точкой: %.2f\n", height);

    // --- Тест m_get_string ---
    string name = m_get_string("Введите ваше имя: ");
    printf("Вы ввели строку: %s (длина: %zu)\n", name.data, name.length);
    free(name.data); // обязательно освобождаем память

    return 0;
}