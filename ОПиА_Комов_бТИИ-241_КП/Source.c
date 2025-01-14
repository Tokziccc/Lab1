#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct smart_speaker {
    char manufacturer[20]; // �������������
    int power; // ��������
    char assistant[50]; // ����� ��������
};
typedef struct smart_speaker ss_t;

// ��������� ��� ������ ���������� � ������������ ���� �������
int main() {
    setlocale(LC_ALL, "RUS");
    ss_t* massiv = NULL; // ������� ��������� ������
    ss_t* massiv2 = NULL; // ������� ������ ��� ������ ������ �� �����
    int vibor = 999, vibor1 = 0; // ������� ����������, �������������� � ������ ���������
    int size1 = 0, size2 = 0; // ������� ���������� ��� �������� ��������
    char fname1[30] = "", fname2[30] = ""; // ������� ���������� ��� �������� ������

    // ��������� ��������� ������� ��� ������
    printf("1 - ������� ������\n---------------------------\n2 - �������� ������ �� �����\n");
    vibor1 = get_valid_input(1, 2);
    switch (vibor1) {
    case 1:
        printf("������� ������ �������(�� 1 �� 100):\n");
        size1 = get_valid_input(1, 100); // ������������ ������ �����
        massiv = (ss_t*)malloc(size1 * sizeof(ss_t));
        fill_array(massiv, size1);
        print_array(massiv, size1);
        break;
    case 2:
        printf("������� ������ ������� ������� ���������� �������(�� 100):\n");
        size2 = get_valid_input(1, 100); 
        printf("������� �������� ����� �� �������� ����� ������� ����������(��������: file.txt):\n");
        scanf("%s", fname2);
        if (!file_have(fname2)) {
            printf("���� � ����� ������ �� ����������. ����������, ������� ���������� ��� �����.\n");
            break;
        }
        massiv2 = (ss_t*)malloc(size2 * sizeof(ss_t));
        size2 = output_file(fname2, massiv2, size2);
        massiv = massiv2;
        size1 = size2;
        print_array(massiv, size1);
        break;
    default:
        break;
    }

    // ����, ���������� �������� ������ ����
    while (vibor != 0) {
        printf("����:\n1)�������� ����� ������\n2)����� ������\n3)������ � ����\n4)������ �� �����\n5)���������� ������\n6)������� ������� ������\n0)�����\n");
        vibor = get_valid_input(0, 6);
        switch (vibor) {
        case 1:
            // �������� ������
            printf("������� ������ �������(�� 1 �� 100):\n");
            size1 = get_valid_input(1, 100);
            massiv = (ss_t*)malloc(size1 * sizeof(ss_t));
            fill_array(massiv, size1);
            print_array(massiv, size1);
            break;
        case 2:
            // ����� �� �������
            find_element(massiv, size1);
            break;
        case 3:
            // �������� ��������� ������ � ����
            printf("������� �������� �����:\n");
            scanf("%s", fname1);
            input_file(fname1, massiv, size1);
            print_array(massiv, size1);
            break;
        case 4:
            // ������� ����
            printf("������� ������ ������� ������� ���������� �������(�� 100):\n");
            size2 = get_valid_input(1, 100); 
            printf("������� �������� ����� �� �������� ����� ������� ����������:\n");
            scanf("%s", fname2);
            if (!file_have(fname2)) {
                printf("���� � ����� ������ �� ����������. ����������, ������� ���������� ��� �����.\n");
                break;
            }
            massiv2 = (ss_t*)malloc(size2 * sizeof(ss_t));
            size2 = output_file(fname2, massiv2, size2);
            massiv = massiv2;
            size1 = size2;
            print_array(massiv, size1);
            break;
        case 5:
            // ����������
            sort_massiv(massiv, size1);
            break;
        case 6:
            // ����� �������
            print_array(massiv, size1);
            break;
        default:
            break;
        }
    }

    // ������������ ������
    free(massiv);
    free(massiv2);
    return 0;
}

// ����������� �������
// ����� �������
int print_array(ss_t* massiv, int size) {
    for (int i = 0; i < size; i++) {
        printf("�������������: %s, ��������(��): %i, ����� ��������: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
    }
    return size;
}

// ���������� ������� � ����
int input_file(char* fname, ss_t* massiv, int size) {
    FILE* out = fopen(fname, "wt"); // ���� �������� �����, � ������� ����� �������� ������
    if (!out) {
        printf("������ �������� �����\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        fprintf(out, "�������������: %s ��������(��): %i ����� ��������: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
    }
    fclose(out);
    return size;
}

// ���������� �������
int fill_array(ss_t* massiv, int size) {
    printf("�������� ��� ���������� �����\n1) ������������� - ����� ��������\n2)�������� - ����� �����\n3)����� �������� - ����� ��������\n");

    for (int i = 0; i < size; i++) {
        int valid_input = 0; // �������� �� ������ ������� ������� ������

        while (!valid_input) {
            printf("������� ������ � ������� � �������: �������������, ��������, ����� ��������\n");
            int result = scanf("%14s %i %14s", massiv[i].manufacturer, &massiv[i].power, massiv[i].assistant);

            if (result == 3) {
                valid_input = 1;
                printf("�������������: %s, ��������(��): %i, ����� ��������: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
            }
            else {
                printf("������������ ������.\n");
                while (getchar() != '\n'); // ������� ������ �����
            }
        }   
    }
    return size;
}

// ���������� �����
int output_file(char* fname, ss_t* massiv, int size) {
    FILE* in = fopen(fname, "rt"); // �������� �����, �������������� ����� ���� ��������
    if (!in) {
        printf("������ �������� �����\n");
        return 1;
    }
    int count = 0; // ������� ���-�� ��������� ��������
    while (count < size && fscanf(in, "�������������: %14s ��������: %i ����� ��������: %14s\n", massiv[count].manufacturer, &massiv[count].power, massiv[count].assistant) == 3) {
        count++;
    }
    if (count < size) {
        printf("� ����� �� ���������� ������.\n");
    }
    fclose(in);
    return count;
}

// ������� ������
int find_element(ss_t* massiv, int size) {
    char s[20], s1[50]; // ��� �������� ������
    int n1, n2; // n1 - ������ ����, n2 - ���-� �����

    printf("������� ���������� ����� ��� ������:\n");
    n2 = get_valid_input(1, 2);
    if (n2 == 1) {
        printf("������� ���� ��� ������ (1-����� ��������, 2-�������������):\n");
        n1 = get_valid_input(1, 2);

        if (n1 == 1) {
            printf("������� ������ ���������:\n");
            scanf("%14s", s);

            for (int i = 0; i < size; i++) {
                if (strcmp(massiv[i].assistant, s) == 0)
                    printf("�������������: %s, ��������(��): %i, ����� ��������: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
            }
        }
        else if (n1 == 2) {
            printf("������� �������������:\n");
            scanf("%14s", s);

            for (int i = 0; i < size; i++) {
                if (strcmp(massiv[i].manufacturer, s) == 0)
                    printf("�������������: %s, ��������(��): %i, ����� ��������: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
            }
        }
    }
    else if (n2 == 2) {
        printf("������ ����� �� ����� �����\n");
        printf("������� �������� ������ ���������:\n");
        scanf("%14s", s);
        printf("������� �������� �������������:\n");
        scanf("%14s", s1);
        for (int i = 0; i < size; i++) {
            if ((strcmp(massiv[i].assistant, s) == 0) && (strcmp(massiv[i].manufacturer, s1) == 0))
                printf("�������������: %s, ��������(��): %i, ����� ��������: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
        }
    }
    return size;
}

// ������� ����������
int sort_massiv(ss_t* massiv, int size) {
    int p, p1; // p - �������� ����������, p1 - ��� ����������
    printf("������� �������� ��� ���������� (1-�������������, 2-��������):\n");
    p = get_valid_input(1, 2);
    printf("�������� ��� ���������� (1-�� �����������, 2-�� ��������):\n");
    p1 = get_valid_input(1, 2);
        
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int sort = 0;

            switch (p) {
            case 1: sort = strcmp(massiv[j].manufacturer, massiv[j + 1].manufacturer); break;
            case 2: sort = (massiv[j].power > massiv[j + 1].power) ? 1 : -1; break;
            default: break;
            }

            if ((p1 == 1 && sort > 0) || (p1 == 2 && sort < 0)) {
                ss_t temp = massiv[j];
                massiv[j] = massiv[j + 1];
                massiv[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("�������������: %s, ��������(��): %i, ����� ��������: %s\n", massiv[i].manufacturer, massiv[i].power, massiv[i].assistant);
    }
    return size;
}

// ���� ������� ������� � ��� �������� 
int get_valid_input(int min, int max) {
    int input;
    char buffer[256];
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &input) == 1 && input >= min && input <= max) {
                return input;
            }
            else {
                printf("����������, ������� ����� �� %d �� %d: ", min, max);
            }
        }
    }
}

// �������� ������� �����
int file_have(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}
