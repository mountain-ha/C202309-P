#include <stdio.h>
#include <string.h>

#define MAX_TODO_ITEMS 100
#define MAX_DATE_LENGTH 20

// 전역 변수
char dates[MAX_TODO_ITEMS][MAX_DATE_LENGTH];
int tasks[MAX_TODO_ITEMS];
int itemCount = 0;

// 함수 선언
void addTodo();
void removeOldestTodo();
void calculateDueDate();
void printAllTodo();

int main() {
    int choice;

    do {
        printf("\n=== TODO 관리 프로그램 ===\n");
        printf("1. 한 일 추가\n");
        printf("2. 날짜 계산 및 할 일 알림\n");
        printf("3. 이전까지 한 일 출력\n");
        printf("4. 종료\n");
        printf("선택: ");
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
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("올바른 선택이 아닙니다. 다시 선택해주세요.\n");
        }

    } while (choice != 4);

    return 0;
}

// 한 일 추가 기능
void addTodo() {
    if (itemCount >= MAX_TODO_ITEMS) {
        printf("TODO 리스트가 가득 찼습니다. 오래된 항목을 삭제합니다.\n");
        removeOldestTodo();
    }

    printf("날짜 입력 (예: 2023-01-01): ");
    scanf_s("%s", dates[itemCount]);

    printf("한 일 입력 (1=물 갈아주기, 2=밥 주기, 3=수조 청소): ");
    scanf_s("%d", &tasks[itemCount]);

    itemCount++;
    printf("TODO가 추가되었습니다.\n");
}

// 오래된 항목 삭제 기능
void removeOldestTodo() {
    if (itemCount <= 0) {
        printf("삭제할 항목이 없습니다.\n");
        return;
    }

    // 가장 오래된 항목 삭제
    /*for (int i = 0; i < itemCount - 1; i++) {
        strcpy_s(dates[i], dates[i + 1]);
        tasks[i] = tasks[i + 1];
    }*/

    itemCount--;
}

// 날짜 계산 및 할 일 알림 기능
void calculateDueDate() {
    if (itemCount <= 0) {
        printf("할 일이 없습니다.\n");
        return;
    }

    printf("최근에 한 일로부터 날짜를 계산합니다.\n");
    for (int i = 0; i < itemCount; i++) {
        printf("최근에 한 일: %s, ", dates[i]);

        switch (tasks[i]) {
        case 1:
            printf("물 갈아주기: ");
            break;
        case 2:
            printf("밥 주기: ");
            break;
        case 3:
            printf("수조 청소: ");
            break;
        default:
            printf("알 수 없는 작업: ");
        }

        printf("%d일 후에 다시 해야 합니다.\n", tasks[i] == 1 ? 7 : (tasks[i] == 2 ? 14 : 30));
    }
}

// 이전까지 한 일 출력 기능
void printAllTodo() {
    if (itemCount <= 0) {
        printf("이전에 한 일이 없습니다.\n");
        return;
    }

    printf("이전까지 한 일과 날짜를 출력합니다.\n");
    for (int i = 0; i < itemCount; i++) {
        printf("날짜: %s, ", dates[i]);

        switch (tasks[i]) {
        case 1:
            printf("물 갈아주기\n");
            break;
        case 2:
            printf("밥 주기\n");
            break;
        case 3:
            printf("수조 청소\n");
            break;
        default:
            printf("알 수 없는 작업\n");
        }
    }
}
