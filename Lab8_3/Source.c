#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	float res = 0;
	puts("������� n:");
	scanf_s("%d", &n);
	for (float i = 2; i <= 2 * n; i += 2)
		res += (1.f - 1 / i);
	printf("�������� ��������� ��� ��������� n: %.2f", res);

}