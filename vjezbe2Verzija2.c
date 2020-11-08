
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h> 

#define MAX 20

struct person;
typedef struct person* Position;
typedef struct person {
	char name[MAX];
	char surname[MAX];
	int birthYear;
	Position next;
}Person;

Person* enterData(void);
void entryAtBeginning(Position, Position);
void printList(Person *);
void entryAtEnd(Position, Position);
Person* search(char[MAX], Person *);
void erase(char[], Person *);




int main(void) {
	Person *head, *prototype;
	head = (Person*)malloc(sizeof(Person));
	head->next = 0;
	int choice, constant = 1;
	char subject_search[MAX];
	while (constant) {
		printf("\nMENU\n(1)Unesi element na pocetak liste\n(2)Ispisi listu\n(3)Dodaj element na kraju liste\n(4)Pronadi element po prezimenu\n(5)Izbrisi odredeni element\n(6)Kraj\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			prototype = enterData();
			entryAtBeginning(prototype, head);
			break;
		case 2:
			printList(head->next);
			break;
		case 3:
			prototype = enterData();
			entryAtEnd(prototype, head);
			break;
		case 4: {
			printf("\nUnesi prezime osobe koje zelis naci");
			scanf("%s", subject_search);
			Person* subjectSearch = search(subject_search, head);
			printf("\nTrazena osoba je:%s\t%s\t%d\n", subjectSearch->next->name, subjectSearch->next->surname, subjectSearch->next->birthYear);
			break;
		}
		case 5: {
			printf("\nUnesi prezime osobe koju zelis izbrisati");
			scanf("%s", subject_search);
			erase(subject_search, head);
			break;
		}
		case 6:
			constant = 0;
			break;
		default:
			printf("Greska");
		}
	}
	free(head);
	system("pause"); 
	return 0;
}

Person* enterData(void) {
	Person* P;
	P = (Person*)malloc(sizeof(Person));
	printf("Unesi ime\n");
	scanf("%s", P->name);
	printf("Unesi prezime\n");
	scanf("%s", P->surname);
	printf("Unesi godinu rodenja\n");
	scanf("%d", &P->birthYear);
	P->next = NULL;
	return P;
}

void entryAtBeginning(Person* person, Person* head) {
	person->next = head->next;
	head->next = person;
}

void printList(Person *head) {
	printf("IME\tPREZIME\tGODINA RODENJA");
	while (head != NULL) {
		printf("\n%s\t%s\t%d", head->name, head->surname, head->birthYear);
		head = head->next;
	}
}

void entryAtEnd(Person* person, Position head) {
	while (head->next != NULL)
		head = head->next;
	entryAtBeginning(person, head);

}

Person* search(char surname[MAX], Position head) {
	while (head->next != NULL && strcmp(head->next->surname, surname) != 0)
		head = head->next;
	return head;
}

void erase(char surname[], Position head) {
	Position previous;
	previous = search(surname, head);
	if (previous != NULL) {
		head = previous->next;
		previous->next = head->next;
	}
	free(head);
}
