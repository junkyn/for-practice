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
		printf("index 오류\n");
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
		printf("리스트가 비어있습니다.\n");
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
		printf("index 오류\n");
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
			printf("%d번째에 저장되어있습니다.\n", count);
			isFind++;
		}
		p = p->next;
		count++;
	}
	if (isFind == 0)
		printf("저장되어있지 않습니다.\n");
}
void getLinkedList(ListNode** h, int index) {
	ListNode* p;
	p = *h;
	if (index > ListLength(*h)) {
		printf("index 오류\n");
		return;
	}
	for (int i = 1; i < index; i++) {
		p = p->next;
	}
	printf("%d번째 정수는 %d입니다.\n", index, p->data);
}
void removeLinkedList(ListNode** h, int index) {
	ListNode* p, * q;
	p = *h;
	q = NULL;
	if (index > ListLength(*h)) {
		printf("index 오류\n");
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
	ListNode* h = (ListNode*)malloc(sizeof(ListNode)); // 헤더
	h = NULL; // NULL로 초기화
	printf("**연결리스트**\n\n");
	int menu;
	char* order;
	do {
		printf("\n");
		printf("add int - 정수를 맨 끝에 추가\n");
		printf("add int index  - 주어진 index에 정수를 추가\n");
		printf("set index int - 주어진 index에 저장된 정수를 입력한 정수값으로 바꿈\n");
		printf("contains int - 리스트에 정수가 저장되어있는지 여부\n");
		printf("get index - 주어진 index에 저장된 정수를 출력\n");
		printf("size - 리스트의 크기\n");
		printf("clear - 리스트 초기화\n");
		printf("remove index - index에 저장된 정수 삭제\n");
		printf("turnoff - 프로그램 종료\n\n");
		char str[100];
		printf("명령어를 입력하세요.\n");
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
			printf("리스트에는 %d개의 정수가 저장되어있습니다.\n", ListLength(h));
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
	printf("\n프로그램을 종료합니다. ");
	return 0;

}