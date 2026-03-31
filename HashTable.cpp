#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int count = 0;

struct node {
	char id[6];
	char name[31];
	char phone[16];
	int age;
	char room[8];
	int duration;
	
	node *next;
} *hashTable[SIZE];

node *createNode(node x) {
	node *curr = (node *)(malloc(sizeof(node)));
	
	strcpy(curr->id, x.id);
	strcpy(curr->name, x.name);
	strcpy(curr->phone, x.phone);
	curr->age = x.age;
	strcpy(curr->room, x.room);
	curr->duration = x.duration;
	curr->next = NULL;
	
	return curr;
}

int hash(char id[]) {
	int sum = 0;
	
	for(int i = 2; i < strlen(id); i++){
		sum += id[i];
	}
	
	return (sum - 1) % SIZE;
}

void generateID(char id[], char room[]){
	char a = room[0];
	char b = room[1] - 32;
	
	int n = rand() % 1000;
	
	sprintf(id, "%c%c%03d", a, b, n);
	printf("%s\n", id);
}

void hapus(){
	//belom
}

void insert(node x){
	//belom
}

//validasi
void bookinghotel(){
	//struct sementara
	node validation;
	
	//name
	while(1){
		printf("input your name [3-30]: ");
		scanf("%[^\n]", &validation.name); getchar();
		
		if(strlen(validation.name) >= 3 && strlen(validation.name) <= 30) {
			break;
		}
		
		puts("Name must be between 3-30");
	}
	
	//phone
	while(1){
		printf("input your phone number: ");
		scanf("%[^\n]", &validation.phone); getchar();
		
		int flag = 0;
		
		//validation +62
		char contain(4);
		strncpy(contain, validation.phone, 3);
		
		if(strcmp(contain, "+62") == 0){
			flag++;
		}
		
		//validation space
		for(int i = 0; i < strlen(validation.phone); i++){
			if(validation.phone[i] == ' '){
				flag++;
				break;
			}
		}
		
		//validation leght
		if(strlen(validation.phone) == 15){
			flag++;
		}
		
		if(flag == 3){
			break;
		}
		
		puts("Phone number must begin with '+62', contain with at least 1 space and the leght must be 11 (exclude '+62' and space)");
	}
	
	//age
	while(1){
		printf("input your age: ");
		scanf("%d", &validation.age); getchar();
		
		if(strlen(validation.age) >= 18) {
			break;
		}
		
		puts("You are not legal");
	}
	
	//room
	while(1){
		printf("input your room type: ");
		scanf("%s", &validation.room); getchar();
		
		if(strcmp(validation.room, "Regular") == 0 || strcmp(validation.room, "Deluxe") == 0 || strcmp(validation.room, "Suite") == 0) {
			break;
		}
		
		puts("Please enter the correct room type");
	}
	
	//duration
	while(1){
		printf("input your duration: ");
		scanf("%s", &validation.duration); getchar();
		
		if(validation.duration >= 1 && validation.duration <= 30) {
			break;
		}
		
		puts("Please enter the correct duration");
	}
	
	//insert
	insert(validation);
}

int main()
{
	while(1){
		puts("hotel gransylvania\n\n");
		
		puts("1. Booking Hotel\n");
		puts("2. View Booking\n");
		puts("3. Delete Booking\n");
		puts("4. Exit\n\n");
		
		printf(">> ");
		int input;
		scanf("%d", &input); getchar();
		
		puts("");
		
		switch(input) {
			case 1:
				//booking hotel
				break;
			case 2:
				//view booking
				break;
			case 3:
				//delete booking
				break;
			case 4:
				//exit
				return 0;
			default:
				puts("input must be 1-4\n");
		}
	}
}
