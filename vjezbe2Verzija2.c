#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

#define MAX_NAME_SIZE 32

typedef struct _person* Position;
typedef struct _person {
	char name[MAX_NAME_SIZE];
	char surname[MAX_NAME_SIZE];
	int birthYear;
	Position next;
}Person;

Position createPerson(void);
int enterAtBeginning(Position, Position);
int enterAtEnd(Position, Position);
int deletePerson(const char[], Position);
Position findPerson(const char[], Position);
int printList(Position);
Position findPreviousPerson(const char[], Position); 
int freeList(Position);

int main(void) {
	Position head;
	head = (Position)malloc(sizeof(struct _person));
	if (!head)
		return -1;
	head->next = NULL;
	enterAtBeginning(createPerson(), head);
	enterAtEnd(createPerson(), head);
	findPerson("firic", head);
	deletePerson("firic", head);
	printList(head->next); 
	freeList(head);
	system("pause");
	return 0;
}

Position createPerson(void) {
	Position person;
	person = (Position)malloc(sizeof(struct _person));
	if (!person)
		return NULL;
	person->next = NULL;
	printf("\nUnesite ime osobe ");
	scanf("%s", person->name);
	printf("\nUnesite prezime osobe ");
	scanf("%s", person->surname);
	printf("\nUnesite godinu rodjenja osobe ");
	scanf("%d", &person->birthYear);
	return person;
}

int enterAtBeginning(Position person, Position head) {
	person->next = head->next;
	head->next = person;
	return 0;
}

int enterAtEnd(Position person, Position head) {
	while (head->next != NULL)
		head = head->next;
	enterAtBeginning(person, head);
	return 0;
}

int deletePerson(const char surname[], Position head) {
	head = findPreviousPerson(surname, head);
	if (head == NULL)
		return 1;
	Position temp = head->next;
	head->next = temp->next;
	free(temp);
	return 0;
}

Position findPerson(const char surname[], Position head) {
	while (head != NULL && strcmp(surname, head->surname) != 0)
		head = head->next;
	printf("\nTrazena osoba je: %s\t%s\t%d", head->name, head->surname, head->birthYear);
	return head;
}

int printList(Position head) {
	printf("\nIME\tPREZIME\tGODINA RODENJA ");
	while (head != NULL) {
		printf("\n%s\t%s\t%d", head->name, head->surname, head->birthYear);
		head = head->next;
	}
	return 0;
}

Position findPreviousPerson(const char surname[], Position head) {
	Position prev = head;
	head = head->next;
	while (head != NULL && (strcmp(surname, head->surname) != 0)) {
		prev = head;
		head = head->next;
	}
	if (head == NULL)
		return NULL;
	return prev;
} 

int freeList(Position head) {
	while (head->next) {
		Position temp = head->next;
		head->next = temp->next;
		free(temp);
	}
	return 0;
}
