#include <stdio.h>
#include <locale.h>
#define D 2.54
#define pul 2.32166
#define mm 1.852
#define spm 1609
#define rm 1475
#define srm 7468
#define gm 7412600


int main()
{
	setlocale(LC_ALL, "RUS");

	int n, g;

	puts("������� ����� ������: ");
	scanf_s("%d", &n);
	printf("%d ����. ������ = %.2f �����������, � %d ���. ������ = %.2f �����������\n", n, n * D, n, n * pul);

	//2a

	puts("������� ����� ����: ");
	scanf_s("%d", &g);
	printf("%d ������� ���� = %.2f ��;\n%d ���������� ���� = %.2f ��;\n%d ������� ���� = %.2f ��;\n%d ������������ ���� = %.2f ��;\n%d �������������� ���� = %.2f ��;\n ", g, g * mm / 1000.f,
		g, g * spm / 1000.f, g, g * rm / 1000.f, g, g * srm / 1000.f, g, g * gm / 1000.f);
}