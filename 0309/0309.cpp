#include <iostream>;

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int i, n, S1, S0, d = 3;
	cout << "n = "; cin >> n;
	i = 1; S1 = S0 = 0;
	_asm {
		mov ecx, n;
		mov eax, 1;

		xor esi, esi;
		xor edi, edi;
		mov ebx, eax;
	sum:
		xor edx, edx;
		shl eax, 1;
		div d;
		add esi, eax;
		add edi, edx;
		inc ebx;
		mov eax, ebx;
		loop sum;
		mov S1, esi;
		mov S0, edi;
	}
	cout << "S1 = " << S1 << endl;
	cout << "S0 = " << S0;
	return 0;
}