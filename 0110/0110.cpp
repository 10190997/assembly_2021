// Задание 1. Дан массив из десяти знаковых чисел (int или short). 
// Требуется 4.	Найти количество положительных чисел. Массив short.

#include <iostream>;

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    short mas[] = { 1, -2, 3, -5, 4, 6, 7, 0, -10, 11 };
    short res = 0;
    short n = 10;
    _asm {
        xor ax, ax
        mov cx, n
        lea esi, mas
        jcxz EXITER
    COMPARER:
        mov dx, [esi]
        cmp dx, 0
        jl NEGAT;   0 считается
        inc ax
    NEGAT:
        inc esi
        inc esi
        dec cx;     взамен loop, который работает плохо в сочетании с lea
        cmp cx, 0
        jg COMPARER
    EXITER:
        mov res, ax
    }
    cout << "Положительных чисел: " << res;

    // Задание 2. Дан массив из n знаковых чисел (int или short). 
    // Требуется вычислить : 14.	
    // 1) количество отрицательных элементов массива;

    res = 0;
    n = 10;
    _asm {
        xor ax, ax
        mov cx, n
        lea esi, mas
        jcxz EXITER1
    COMPARER1:
        mov dx, [esi]
        cmp dx, 0
        jge POSIT;   0 не считается
        inc ax
    POSIT:
        inc esi
        inc esi
        dec cx;     взамен loop, который работает плохо в сочетании с lea
        cmp cx, 0
        jg COMPARER1
    EXITER1:
        mov res, ax
    }
    cout << "\nОтрицательных чисел: " << res;

    // 2) сумму модулей элементов массива, расположенных после минимального по модулю элемента.

    return 0;
}