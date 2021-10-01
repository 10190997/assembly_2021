//2. Задан одномерный массив двухбайтовых знаковых чисел. 
//Необходимо разработать программу для подсчета суммы положительных элементов массива.

#include <iostream>;

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	short mas[9] = { 1, -2, 3, -5, 4, 6, 7, 0, -10 };
    short res = 0;
    short n = 9;
    _asm {
        xor ax, ax
        mov cx, n
        lea esi, mas
        jcxz EXITER
     COMPARER: 
        mov dx, [esi]
        cmp dx, 0
        jnge NEGAT
        add ax, dx
     NEGAT: 
        inc esi
        inc esi
        dec cx;     взамен loop, который работает плохо в сочетании с lea
        cmp cx, 0
        jg COMPARER
     EXITER: 
        mov res, ax
    }
    cout << "Сумма положительных элементов массива: " << res;

	return 0;
}