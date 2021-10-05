// Задание 1. Дан массив из десяти знаковых чисел (int или short). 
// Требуется 4.	Найти количество положительных чисел. Массив short.

#include <iostream>;

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    short mas[] = { 1, -2, 3, -5, 4, 6, 7, 0, -10, 11 };
#pragma region ass

    short res = 0;
    short n = 10;
    _asm {
        xor ax, ax
        mov cx, n
        lea esi, mas
        jcxz EXITER
        COMPARER :
        mov dx, [esi]
            cmp dx, 0
            jl NEGAT;   0 считается
            inc ax
            NEGAT :
        inc esi
            inc esi
            dec cx;     взамен loop, который работает плохо в сочетании с lea
            cmp cx, 0
            jg COMPARER
            EXITER :
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
        COMPARER1 :
        mov dx, [esi]
            cmp dx, 0
            jge POSIT;   0 не считается
            inc ax
            POSIT :
        inc esi
            inc esi
            dec cx;     взамен loop, который работает плохо в сочетании с lea
            cmp cx, 0
            jg COMPARER1
            EXITER1 :
        mov res, ax
    }
    cout << "\nОтрицательных чисел: " << res;

#pragma endregion 
    // 2) сумму модулей элементов массива, расположенных после минимального по модулю элемента.
    short sum = 0;
    short mi, nmi = 0;
    _asm {
        mov cx, n
        xor bx, bx
        lea esi, mas
        mov ax, [esi]
        cmp ax, 0
        jge M1
        neg ax
    M1:
        mov mi, ax
        mov dx, 1
        add esi, 2
    ANALYZER:
        mov ax, [esi]
        cmp ax, 0
        jge ABS
        neg ax
    ABS:
        cmp ax, mi
        jge M2
        mov mi, ax
        mov nmi, dx
    M2:
        inc esi
        inc esi
        inc dx
        dec cx  ;взамен loop, который работает плохо в сочетании с lea
        cmp cx, 0
        jg ANALYZER
        xor cx, cx
        xor esi, esi
        xor ax, ax

        mov cx, n
    ANALYZER2:
        lea esi, mas
        mov ax, [esi + (nmi * 2)]
    //    cmp ax, 0
    //    jge M3
    //    neg ax
    //M3:
    //    inc esi
    //    inc esi
    //    add bx, ax
    //    dec cx  ;взамен loop, который работает плохо в сочетании с lea
    //    cmp cx, 0
    //    jg ANALYZER2
    //    mov sum, bx
    }
    cout << endl << mi << "  " << nmi << endl;
    cout << "\nСумма модулей элементов массива, расположенных после минимального по модулю элемента: " << sum;

    return 0;
}