#include <stdio.h>
#include <string.h>
#include "DateCalculator.h"
#include "ToDO.h"


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
