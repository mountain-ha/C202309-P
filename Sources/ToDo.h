#include <stdio.h>
#include <string.h>
#include "DateCalculator.h"

#define MAX_TODO_ITEMS 10
#define MAX_DATE_LENGTH 20


// ������ �׸� ���� ���
void removeOldestTodo();


// �� �� �߰� ���
void addTodo();

// ��¥ ��� �� �� �� �˸� ���: ���� �Ϸ�
void calculateDueDate();

// �������� �� �� ��� ���
void printAllTodo();
