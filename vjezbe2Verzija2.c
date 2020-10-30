#define _CRT_SECURE_NO_WARNINGS //NEDOVRSENO!!

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
Position search(char[MAX], Person *); 
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
		case 4: 
			printf("\nUnesi prezime osobe koje zelis naci");
			scanf("%s", &subject_search);
			Position subjectSearch = search(subject_search, head); 
			printf("\nTrazena osoba je:%s\t%s\t%d", subjectSearch->name, subjectSearch->surname, subjectSearch->birthYear); 
			break;
		case 5: 
			printf("\nUnesi prezime osobe koju zelis izbrisati");
			scanf("%s", &subject_search);  
			erase(subject_search, head); 
			break;
	
		
		}
	}
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

void entryAtBeginning(Position what, Position where) {
	what->next = where->next;
	where->next = what;
}

void printList(Person *head) {
	while (&head != NULL) {
		printf("\n%s\t%s\t%d", head->name, head->surname, head->birthYear);
		head = head->next;
	}
} 

void entryAtEnd(Position what, Position where) { 
	while (what->next != NULL)
		what = what->next; 
	entryAtBeginning(what, where);

} 

Position search(char what[MAX], Position where) {
	while (strcmp(where->next->surname, what) != 0 && where->next != NULL)
		where = where->next; 
	return where->next;
} 

void erase(char what[], Position where) {
	Position previous; 
	previous = search(what, where); 
	if (previous != NULL) {
		where = previous->next; 
		previous->next = where->next; 
	} 
	free(where);
}
