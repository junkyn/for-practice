#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
typedef struct ListNode {
	int data;
	struct ListNode* next;
}ListNode;

int ListLength(ListNode* h) {
	ListNode* current = h;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}
void InsertInLinkedList(ListNode** h, int data, int position) {
	int k = 1;
	if (position > ListLength(*h)+1) {
		printf("index ����\n");
		return;
	}
	struct ListNode* p, * q, * newNode;
	p = q = newNode = NULL;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode) {
		printf("Memory Error");
		return;
	}
	newNode->data = data;
	p = *h;
	if (position == 1 || *h == NULL) {
		newNode->next = p;
		*h = newNode;
	}
	else {
		while ((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}
		if (p == NULL) {
			q->next = newNode;
			newNode->next = NULL;
		}
		else {
			newNode->next = p;
			q->next = newNode;
		}
	}
}
void printList(ListNode** h) {
	ListNode* p;
	p = *h;
	int count = 1;
	if (*h == NULL) {
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
	}
	while(p !=NULL) {
		if (count == 1) 
			printf("{ ");
		printf("%d", p->data);
		if (count == ListLength(*h))
			printf(" }\n");
		else
			printf(", ");
		count++;
		p = p->next;
	}
}
void setLinkedList(ListNode** h, int index, int data) {
	ListNode* p;
	p = *h;
	if (index > ListLength(*h)) {
		printf("index ����\n");
		return;
	}
	for (int i = 1; i < index; i++) {
		p = p->next;
	}
	p->data = data;
}
void containsLinkedList(ListNode** h, int data) {
	ListNode* p;
	p = *h;
	int count = 1;
	int isFind = 0;
	while (p != NULL) {
		if (p->data == data) {
			printf("%d��°�� ����Ǿ��ֽ��ϴ�.\n", count);
			isFind++;
		}
		p = p->next;
		count++;
	}
	if (isFind == 0)
		printf("����Ǿ����� �ʽ��ϴ�.\n");
}
void getLinkedList(ListNode** h, int index) {
	ListNode* p;
	p = *h;
	if (index > ListLength(*h)) {
		printf("index ����\n");
		return;
	}
	for (int i = 1; i < index; i++) {
		p = p->next;
	}
	printf("%d��° ������ %d�Դϴ�.\n", index, p->data);
}
void removeLinkedList(ListNode** h, int index) {
	ListNode* p, * q;
	p = *h;
	q = NULL;
	if (index > ListLength(*h)) {
		printf("index ����\n");
		return;
	}
	for (int i = 1; i < index; i++) {
		q = p;
		p = p->next;
	}
	if (q == NULL) {
		*h = p->next;
	}
	else {
		q->next = p->next;
		p = NULL;
	}
}
int main() {
	ListNode* h = (ListNode*)malloc(sizeof(ListNode)); // ���
	h = NULL; // NULL�� �ʱ�ȭ
	printf("**���Ḯ��Ʈ**\n\n");
	int menu;
	char* order;
	do {
		printf("\n");
		printf("add int - ������ �� ���� �߰�\n");
		printf("add int index  - �־��� index�� ������ �߰�\n");
		printf("set index int - �־��� index�� ����� ������ �Է��� ���������� �ٲ�\n");
		printf("contains int - ����Ʈ�� ������ ����Ǿ��ִ��� ����\n");
		printf("get index - �־��� index�� ����� ������ ���\n");
		printf("size - ����Ʈ�� ũ��\n");
		printf("clear - ����Ʈ �ʱ�ȭ\n");
		printf("remove index - index�� ����� ���� ����\n");
		printf("turnoff - ���α׷� ����\n\n");
		char str[100];
		printf("��ɾ �Է��ϼ���.\n");
		gets(str);
		char* ch;
		ch = strtok(str, " ");
		order = ch;
		printf("\n");
		if (strcmp(ch, "add") == 0) {
			ch = strtok(NULL, " ");
			int data = atoi(ch);
			ch = strtok(NULL, " ");
			if (ch == NULL) {
				InsertInLinkedList(&h, data, ListLength(h)+1);
			}
			else {
				InsertInLinkedList(&h, data, atoi(ch));
			}
		}
		else if (strcmp(ch, "set") == 0) {
			ch = strtok(NULL, " ");
			int idx = atoi(ch);
			ch = strtok(NULL, " ");
			int data = atoi(ch);
			setLinkedList(&h, idx, data);
		}
		else if (strcmp(ch, "contains") == 0) {
			ch = strtok(NULL, " ");
			int data = atoi(ch);
			containsLinkedList(&h, data);
		}
		else if (strcmp(ch, "get") == 0) {
			ch = strtok(NULL, " ");
			int idx = atoi(ch);
			getLinkedList(&h, idx);
		}
		else if (strcmp(ch, "size") == 0) {
			printf("����Ʈ���� %d���� ������ ����Ǿ��ֽ��ϴ�.\n", ListLength(h));
		}
		else if (strcmp(ch, "clear") == 0) {
			h = NULL;
		}
		else if (strcmp(ch, "remove") == 0) {
			ch = strtok(NULL, " ");
			int idx = atoi(ch);
			removeLinkedList(&h, idx);
		}
		printList(&h);
	} while (strcmp(order, "turnoff") != 0);
	printf("\n���α׷��� �����մϴ�. ");
	return 0;

}