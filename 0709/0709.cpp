//2. ����� ���������� ������ ������������ �������� �����. 
//���������� ����������� ��������� ��� �������� ����� ������������� ��������� �������.

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
        dec cx;     ������ loop, ������� �������� ����� � ��������� � lea
        cmp cx, 0
        jg COMPARER
     EXITER: 
        mov res, ax
    }
    cout << "����� ������������� ��������� �������: " << res;

	return 0;
}