#include <stdio.h>
#include <string.h>
#include "DateCalculator.h"

#define MAX_TODO_ITEMS 10
#define MAX_DATE_LENGTH 20

// 전역 변수
char dates[MAX_TODO_ITEMS][MAX_DATE_LENGTH];
int tasks[MAX_TODO_ITEMS];
int itemCount = 0;

// 오래된 항목 삭제 기능
void removeOldestTodo() {
    if (itemCount <= 0) {
        printf("삭제할 항목이 없습니다.\n");
        return;
    }

    // 가장 오래된 항목 삭제
    for (int i = 0; i < itemCount - 1; i++) {
        strcpy_s(dates[i], sizeof(dates[i]), dates[i + 1]);
        tasks[i] = tasks[i + 1];
    }

    itemCount--;
}

// 한 일 추가 기능
void addTodo() {
    if (itemCount >= MAX_TODO_ITEMS) {
        printf("TODO 리스트가 가득 찼습니다. 오래된 항목을 삭제합니다.\n");
        removeOldestTodo();
    }

    printf("날짜 입력 (예: 2023-01-01): ");
    scanf_s("%s", &dates[itemCount], sizeof(dates[itemCount]));

    printf("한 일 입력 (1=물 갈아주기, 2=밥 주기, 3=수조 청소): ");
    scanf_s("%d", &tasks[itemCount]);

    itemCount++;
    printf("TODO가 추가되었습니다.\n");
}


// 날짜 계산 및 할 일 알림 기능: 수정 완료
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

        // 이 부분을 DateCalculator.h의 calculateDate 함수로 대체
        struct Date currentDate;
        sscanf_s(dates[i], "%d-%d-%d", &currentDate.year, &currentDate.month, &currentDate.day);
        struct Date dueDate = calculateDate(currentDate, tasks[i] == 1 ? 7 : (tasks[i] == 2 ? 14 : 30));

        printf("%d년 %d월 %d일에 다시 해야 합니다.\n", dueDate.year, dueDate.month, dueDate.day);
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