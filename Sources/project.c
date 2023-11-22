#include <stdio.h>
#include <string.h>

#define MAX_TODO_ITEMS 100
#define MAX_DATE_LENGTH 20

// ���� ����
char dates[MAX_TODO_ITEMS][MAX_DATE_LENGTH];
int tasks[MAX_TODO_ITEMS];
int itemCount = 0;

// �Լ� ����
void addTodo();
void removeOldestTodo();
void calculateDueDate();
void printAllTodo();

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

// �� �� �߰� ���
void addTodo() {
    if (itemCount >= MAX_TODO_ITEMS) {
        printf("TODO ����Ʈ�� ���� á���ϴ�. ������ �׸��� �����մϴ�.\n");
        removeOldestTodo();
    }

    printf("��¥ �Է� (��: 2023-01-01): ");
    scanf_s("%s", dates[itemCount]);

    printf("�� �� �Է� (1=�� �����ֱ�, 2=�� �ֱ�, 3=���� û��): ");
    scanf_s("%d", &tasks[itemCount]);

    itemCount++;
    printf("TODO�� �߰��Ǿ����ϴ�.\n");
}

// ������ �׸� ���� ���
void removeOldestTodo() {
    if (itemCount <= 0) {
        printf("������ �׸��� �����ϴ�.\n");
        return;
    }

    // ���� ������ �׸� ����
    /*for (int i = 0; i < itemCount - 1; i++) {
        strcpy_s(dates[i], dates[i + 1]);
        tasks[i] = tasks[i + 1];
    }*/

    itemCount--;
}

// ��¥ ��� �� �� �� �˸� ���
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

        printf("%d�� �Ŀ� �ٽ� �ؾ� �մϴ�.\n", tasks[i] == 1 ? 7 : (tasks[i] == 2 ? 14 : 30));
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
