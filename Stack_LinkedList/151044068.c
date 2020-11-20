#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
	char name[100];
	char surname[100];
	char musical_Work[100];
	int age;
	struct person *next;
} *top;

// global variables for stack
int top_point=-1;
top top_element;
top top_person;

/* there are the funtions */
void addNode(char name[], char surname[], char creation[], int age);
void deleteNode();
void Sort_Alphabetically();
void Sort_Increasingly();
void print_stack(top element);
void menu();

// prints all the stack 
void print_stack(top element) {
	int i=1;
	if(top_point<0) 
		printf("There is no element in your stack.\n");
	else {
		while(element != NULL) {
			printf("%d) ", i++);
			printf("%s\n", element->name);
			printf("%s\n", element->surname);
			printf("%s\n", element->musical_Work);
			printf("%d\n", element->age);
			element = element->next;
		} 
	}
}

// takes information about person from user and adds to the stack
void addNode(char name[], char surname[], char creation[], int age) {
	printf("Name: ");
	scanf(" %99[^\n]s", name);
	printf("Surname: ");
	scanf(" %99[^\n]s", surname);
	printf("Creation: ");
	scanf(" %99[^\n]s", creation);
	printf("Age: ");
	scanf("%d", &age);

	// if stack is empty, create a node and add it to top and print
	if(top_point == -1) {
		top_element = (top)calloc(1, sizeof(top));
		strcpy(top_element->name, name);
		strcpy(top_element->surname, surname);
		strcpy(top_element->musical_Work, creation);
		top_element->age = age;
		top_element->next = NULL;
		++top_point;
	}
	else { //if stack is not empty, create a node and add it to top and print
		top_person = (top)calloc(1, sizeof(top));
		strcpy(top_person->name, name);
		strcpy(top_person->surname, surname);
		strcpy(top_person->musical_Work, creation);
		top_person->age = age;

		top_person->next = top_element;
		top_element = top_person;
		++top_point;
	}
	print_stack(top_element);
}

// removes the top node from the stack
void deleteNode() {
	// if stack is empty
	if(top_point<0) {
		printf("There is no element in your stack.\n");
	}
	else { // if stack has something 
		// select the top node and remove it from the stack and print the stack
		top some = top_element;
		top_person = NULL;
		int i=0;
		while(i<top_point) {
			i++;
			some = top_element->next;
		}
		top_person = some;
		top_element = some;
		top_point--;
		print_stack(top_element);
	}
}

// global variables to use in the Sort_Alphabetically function
top first_temp;
top second_temp;

// sorts stack alphabetically respect to node's name's 
void Sort_Alphabetically() {
	// if stack is empty
	if(top_point<0) {
		printf("There is no element in your stack.\n");
	}
	else {
		first_temp = top_element;
		second_temp = first_temp->next;
		while(first_temp != NULL && second_temp != NULL) {
			// compare names letter by letter 
			// if the top node is smaller than its below, it is true, update below node
			while(first_temp != NULL && second_temp != NULL && first_temp->name[0] < second_temp->name[0]) {
				second_temp = second_temp->next;
			}
			// if the top node is bigger than its below, change their all values
			while(first_temp != NULL && second_temp != NULL && first_temp->name[0] > second_temp->name[0]) {
				char name[100];
				char surname[100];
				char creation[100];
				strcpy(name, first_temp->name);
				strcpy(surname, first_temp->surname);
				strcpy(creation, first_temp->musical_Work);
				int age = first_temp->age;
				
				strcpy(first_temp->name, second_temp->name);
				strcpy(first_temp->surname, second_temp->surname);
				strcpy(first_temp->musical_Work, second_temp->musical_Work);
				first_temp->age = second_temp->age;

				strcpy(second_temp->name, name);
				strcpy(second_temp->surname, surname);
				strcpy(second_temp->musical_Work, creation);
				second_temp->age = age;

				second_temp = second_temp->next;
			}
			// if their first letters is same, then check all the letters
			if(first_temp != NULL && second_temp != NULL && first_temp->name[0] == second_temp->name[0]) {
				if(strcmp(first_temp->name, second_temp->name) == 0) // if names are equal, than update below node
					second_temp = second_temp->next;
				else { // if there are not same word
					int i=0;
					char first_name[100], second_name[100];
					char first_surname[100], second_surname[100];
					char first_creation[100], second_creation[100];
					int first_age, second_age;

					strcpy(first_name, first_temp->name);
					strcpy(first_surname, first_temp->surname);
					strcpy(first_creation, first_temp->musical_Work);
					first_age = first_temp->age;

					strcpy(second_name, second_temp->name);
					strcpy(second_surname, second_temp->surname);
					strcpy(second_creation, second_temp->musical_Work);
					second_age = second_temp->age;
					while(first_temp->name[i] != '\0' && second_temp->name[i] != '\0' && first_temp->name[i] == second_temp->name[i]) {
						i++;
					}
					char name[100], surname[100], creation[100];
					int age;
					if(first_temp->name[i] != '\0' && second_temp->name[i] == '\0') { 
						// if first is short word by other, then the node will be the top which short word
						second_temp = second_temp->next;
					}
					else if(second_temp->name[i] != '\0' && first_temp->name[i] == '\0') { 
						// if second is short word by other, then the node will be the top which short word
						strcpy(name, second_temp->name);
						strcpy(surname, second_temp->surname);
						strcpy(creation, second_temp->musical_Work);
						age = second_temp->age;
						
						strcpy(second_temp->name, first_name);
						strcpy(second_temp->surname, first_surname);
						strcpy(second_temp->musical_Work, first_creation);
						second_temp->age = first_age;

						strcpy(first_temp->name, name);
						strcpy(first_temp->surname, surname);
						strcpy(first_temp->musical_Work, creation);
						first_temp->age = age;

						first_temp = first_temp->next;
					}
					else if(first_temp->name[i] > second_temp->name[i]) {
						// if first's letter is bigger than second's letter, change them 
						strcpy(name, second_temp->name);
						strcpy(surname, second_temp->surname);
						strcpy(creation, second_temp->musical_Work);
						age = second_temp->age;
						
						strcpy(second_temp->name, first_temp->name);
						strcpy(second_temp->surname, first_temp->surname);
						strcpy(second_temp->musical_Work, first_temp->musical_Work);
						second_temp->age = first_temp->age;

						strcpy(first_temp->name, name);
						strcpy(first_temp->surname, surname);
						strcpy(first_temp->musical_Work, creation);
						first_temp->age = age;

						first_temp = first_temp->next;
					}
					else if(first_temp->name[i] < second_temp->name[i]) {
						// if first's letter is smaller than second's letter, update second
						second_temp = second_temp->next;
					}
				}
			}
			if(second_temp == NULL) {
				// if second is null, then update first, its next and update second according to first's next
				first_temp = first_temp->next;
				second_temp = first_temp->next;
			}
			if(first_temp == NULL && second_temp != NULL) {
				// if first is null, then update first to top element and update second according to first's next
				first_temp = top_element;
				second_temp = first_temp->next;
			}
		}
		// then print the stack
		print_stack(top_element);
	}
}

// sorts all the person's age by increasing
void Sort_Increasingly() {
	if(top_point<0) {
		// stack is empty, print about it
		printf("There is no element in your stack.\n");
	}
	else {
		// set the keys
		first_temp = top_element;
		second_temp = first_temp->next;
		while(first_temp != NULL && second_temp != NULL) {
			while(first_temp != NULL && second_temp != NULL && first_temp->age < second_temp->age) {
				// if first element's age is smaller than second's age, it is true, update second
				second_temp = second_temp->next;
			}
			while(first_temp != NULL && second_temp != NULL && first_temp->age > second_temp->age) {
				// if first element's age is bigger than second's age, keep the this two people's values
				char name[100];
				char surname[100];
				char creation[100];
				strcpy(name, first_temp->name);
				strcpy(surname, first_temp->surname);
				strcpy(creation, first_temp->musical_Work);
				int age = first_temp->age;
				
				strcpy(first_temp->name, second_temp->name);
				strcpy(first_temp->surname, second_temp->surname);
				strcpy(first_temp->musical_Work, second_temp->musical_Work);
				first_temp->age = second_temp->age;

				strcpy(second_temp->name, name);
				strcpy(second_temp->surname, surname);
				strcpy(second_temp->musical_Work, creation);
				second_temp->age = age;

				second_temp = second_temp->next;
			}
			if(first_temp != NULL && second_temp != NULL && first_temp->age == second_temp->age) {
				// if their ages are equal, than it is true, update second
				second_temp = second_temp->next;
			}
			if(second_temp == NULL) {
				// if second is null, then update first to its next and update second according to first
				first_temp = first_temp->next;
				second_temp = first_temp->next;
			}
			if(first_temp == NULL && second_temp != NULL) {
				// if first is null, then update first to top element and update second according to first
				first_temp = top_element;
				second_temp = first_temp->next;
			}
		}
		// then print stack
		print_stack(top_element);
	}
}

// menu function, print this on the screen while user's choice is valid value for the menu
void menu() {
	int choice, age;
	top someone = NULL;
	char name[100], surname[100], creation[100];
	do {
		printf("****MENU****\n");
		printf("1- Add a Person to the Stack\n");
		printf("2- Pop a Person from the Stack\n");
		printf("3- Sort Alphabetical Order\n");
		printf("4- Sort Age in Increasing Order\n");
		printf("5- Exit menu\n");
		printf("*************\n");
		printf("Select your choice: ");
		scanf("%d", &choice);

		if(choice == 1) {
			addNode(name, surname, creation, age);
		}
		else if(choice == 2) {
			deleteNode();
		}
		else if(choice == 3) {
			Sort_Alphabetically();
		}
		else if(choice == 4) {
			Sort_Increasingly();
		}
		else if(choice != 5){
			printf("Your choice %d is not correct value for this menu..\n", choice);
			printf("Please try again.\n");
		}
	} while(choice != 5);
}

int main() {
	menu();
	return 0;
}