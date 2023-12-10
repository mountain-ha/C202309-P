#include <stdio.h>
#include <string.h>
#include "DateCalculator.h"

#define MAX_TODO_ITEMS 10
#define MAX_DATE_LENGTH 20

// ���� ����
char dates[MAX_TODO_ITEMS][MAX_DATE_LENGTH];
int tasks[MAX_TODO_ITEMS];
int itemCount = 0;

// ������ �׸� ���� ���
void removeOldestTodo() {
    if (itemCount <= 0) {
        printf("������ �׸��� �����ϴ�.\n");
        return;
    }

    // ���� ������ �׸� ����
    for (int i = 0; i < itemCount - 1; i++) {
        strcpy_s(dates[i], sizeof(dates[i]), dates[i + 1]);
        tasks[i] = tasks[i + 1];
    }

    itemCount--;
}

// �� �� �߰� ���
void addTodo() {
    if (itemCount >= MAX_TODO_ITEMS) {
        printf("TODO ����Ʈ�� ���� á���ϴ�. ������ �׸��� �����մϴ�.\n");
        removeOldestTodo();
    }

    printf("��¥ �Է� (��: 2023-01-01): ");
    scanf_s("%s", &dates[itemCount], sizeof(dates[itemCount]));

    printf("�� �� �Է� (1=�� �����ֱ�, 2=�� �ֱ�, 3=���� û��): ");
    scanf_s("%d", &tasks[itemCount]);

    itemCount++;
    printf("TODO�� �߰��Ǿ����ϴ�.\n");
}


// ��¥ ��� �� �� �� �˸� ���: ���� �Ϸ�
void calculateDueDate() {
    if (itemCount <= 0) {
        printf("�� ���� �����ϴ�.\n");
        return;
    }

    printf("�ֱٿ� �� �Ϸκ��� ��¥�� ����մϴ�.\n");
    for (int i = 0; i < itemCount; i++) {
        printf("�ֱٿ� �� ��: %s, ", dates[i]);

        switch (tasks[i]) {
        case 1:
            printf("�� �����ֱ�: ");
            break;
        case 2:
            printf("�� �ֱ�: ");
            break;
        case 3:
            printf("���� û��: ");
            break;
        default:
            printf("�� �� ���� �۾�: ");
        }

        // �� �κ��� DateCalculator.h�� calculateDate �Լ��� ��ü
        struct Date currentDate;
        sscanf_s(dates[i], "%d-%d-%d", &currentDate.year, &currentDate.month, &currentDate.day);
        struct Date dueDate = calculateDate(currentDate, tasks[i] == 1 ? 7 : (tasks[i] == 2 ? 14 : 30));

        printf("%d�� %d�� %d�Ͽ� �ٽ� �ؾ� �մϴ�.\n", dueDate.year, dueDate.month, dueDate.day);
    }
}

// �������� �� �� ��� ���
void printAllTodo() {
    if (itemCount <= 0) {
        printf("������ �� ���� �����ϴ�.\n");
        return;
    }

    printf("�������� �� �ϰ� ��¥�� ����մϴ�.\n");
    for (int i = 0; i < itemCount; i++) {
        printf("��¥: %s, ", dates[i]);

        switch (tasks[i]) {
        case 1:
            printf("�� �����ֱ�\n");
            break;
        case 2:
            printf("�� �ֱ�\n");
            break;
        case 3:
            printf("���� û��\n");
            break;
        default:
            printf("�� �� ���� �۾�\n");
        }
    }
}



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
