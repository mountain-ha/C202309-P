#include <stdio.h>
#include <string.h>
#include "DateCalculator.h"
#include "ToDO.h"


int main() {
    int choice;

    do {
        printf("\n=== TODO ���� ���α׷� ===\n");
        printf("1. �� �� �߰�\n");
        printf("2. ��¥ ��� �� �� �� �˸�\n");
        printf("3. �������� �� �� ���\n");
        printf("4. ����\n");
        printf("����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addTodo();
            break;
        case 2:
            calculateDueDate();
            break;
        case 3:
            printAllTodo();
            break;
        case 4:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�ùٸ� ������ �ƴմϴ�. �ٽ� �������ּ���.\n");
        }

    } while (choice != 4);

    return 0;
}
