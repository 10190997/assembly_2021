//2. Задан одномерный массив двухбайтовых знаковых чисел. 
//Необходимо разработать программу для подсчета суммы положительных элементов массива.

#include <iostream>;

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	short dim[] = { 1, -2, 3, -5, 4, 6, 7, 0, -10 };
    short res;
    short n = 9;
    _asm {
        xor ax, ax; 
     PREPARE: 
        mov cx, n; 
        xor ebx, ebx;
        lea ebx, dim;
        jcxz EXITER;
     COMPARE: 
        mov dx, [ebx];
        cmp dx, 0; 
        jnge NEGAT; 
     POSIT: 
        add ax, dx; 
     NEGAT: 
        inc ebx;
        inc ebx;
loop COMPARE; 
     EXITER: 
        mov res, ax
    }
    cout << res;

	return 0;
}