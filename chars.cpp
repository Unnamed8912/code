#include <iostream>
using namespace std;

#define MATCH 0    /* Символ перечисляемого типа для совпадения */
#define INSERT 1    /* Символ перечисляемого типа для вставки */
#define DELETE 2    /* Символ перечисляемого типа для удаления */

// Функции, которые должны быть определены где-то еще
int indel(char c);           // Возвращает стоимость вставки/удаления символа
int match(char a, char b);   // Возвращает стоимость совпадения/замены

int string_compare_r(char *s, char *t, int i, int j) {
    int k;    /* Счетчик */
    int opt[3];    /* Стоимость трех опций */
    int lowest_cost;    /* Самая низкая стоимость */
    
    if (i == 0) {    /* indel = стоимость вставки или удаления */
        return(j * indel(' '));
    }
    if (j == 0) {
        return(i * indel(' '));
    }

    /* match = стоимость совпадения/замены */
    opt[MATCH] = string_compare_r(s, t, i-1, j-1) + match(s[i], t[j]);
    opt[INSERT] = string_compare_r(s, t, i, j-1) + indel(t[j]);
    opt[DELETE] = string_compare_r(s, t, i-1, j) + indel(s[i]);

    lowest_cost = opt[MATCH];
    for (k = INSERT; k <= DELETE; k++) {
        if (opt[k] < lowest_cost) {
            lowest_cost = opt[k];
        }
    }
    return(lowest_cost);
}

// Заглушки для недостающих функций
int indel(char c) {
    return 1;  // Простая стоимость: 1 за любую операцию
}

int match(char a, char b) {
    return (a == b) ? 0 : 1;  // 0 если совпадают, 1 если разные
}

// Пример использования
int main() {
    char s[] = "cat";
    char t[] = "car";
    
    // Внимание: индексы в коде начинаются с 1, не с 0!
    // Поэтому передаем длины строк
    int result = string_compare_r(s, t, 3, 3);
    
    cout << "Стоимость редактирования для 'cat' -> 'car': " << result << endl;
    
    // Проверим базовый случай
    cout << "Пустая строка -> 'abc': " << string_compare_r("", "abc", 0, 3) << endl;
    cout << "'abc' -> пустая строка: " << string_compare_r("abc", "", 3, 0) << endl;
    
    return 0;
}
