/*
 * project.c
 *
 *  Created on: Aug 12, 2024
 *      Author: Sameh Fawzy
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	int id;
	char name[50];
	float gpa;
	int age;
}std;//object fpr the structure
struct node {
	struct student data;
	struct node *next;
};
struct node *head=NULL;
void addStudent(const struct student *const ptr){
	struct node *current;
	current=head;
	while(current!=NULL){ //loop to see if the id is taken before even making a new node
		if(current->data.id==ptr->id){
			printf("ID is already taken\n");
			return;
		}
		current=current->next;
	}
	current=head;
	struct node *newstudent=(struct node *)malloc(sizeof(struct node));
	newstudent->data.id=ptr->id;
	newstudent->data.age=ptr->age;
	newstudent->data.gpa=ptr->gpa;
	strcpy(newstudent->data.name,ptr->name);
	newstudent->next=NULL;
	if(head==NULL){
		head=newstudent;
	}
	else{
		while(current->next !=NULL){
			current=current->next;
		}
		current->next=newstudent;
	}
	return;
}
void displayStudents(void){
	if(head==NULL){
		printf("The list is Empty");
		return;
	}
	struct node *current;
	current=head;
	while(current!=NULL){
		printf("ID: %d, Name: %s, Age: %d, GPA: %.2f \n", current->data.id , current->data.name, current->data.age , current->data.gpa);
		current=current->next;
	}
	return;

}
void searchStudentByID(int ID){
	struct node *current;
	current=head;
	while(current!=NULL){
		if(current->data.id==ID){
			printf("ID: %d, Name: %s, Age: %d, GPA: %.2f \n", current->data.id , current->data.name, current->data.age , current->data.gpa);
			return;
		}
		current=current->next;
	}
	printf("Student not found");
	return;


}
void updateStudent(int ID){
	struct node *current;
	current=head;
	while(current!=NULL){
		if(current->data.id==ID){
			printf("Enter the student new name: ");
			scanf("%s",current->data.name);
			printf("Enter the student new age: ");
			scanf("%d",&current->data.age);
			printf("Enter the student new GPA: ");
			scanf("%f",&current->data.gpa);
			return;
		}
	}
	printf("Student not found");
	return;
}
float calculateAverageGPA(void){
	float avg;
	float sum=0; //sum of gpa
	int i=0; //number of students
	if(head==NULL){
		return 0.0;
	}
	struct node *current;
	current=head;
	while(current!=NULL){
		sum=sum+current->data.gpa;
		current=current->next;
		i++;
	}
	avg=sum/i;
	return avg;
}
void searchHighestGPA(void){
	if(head==NULL){
		printf("The list is empty");
		return;
	}
	float maxgpa=0.0;
	struct node *current;
	struct node *ptr; //this pointer will point to the node with the highest gpa
	current=head;
	ptr=head;
	while(current!=NULL){
		if(current->data.gpa > maxgpa){
			maxgpa=current->data.gpa;
			ptr=current;
		}
		current=current->next;
	}
	printf("The details of the student with the highest GPA\nID: %d, Name: %s, Age: %d, GPA: %.2f \n", ptr->data.id , ptr->data.name, ptr->data.age , ptr->data.gpa);
	return;
}
void deleteStudent(int ID) {
	if (head == NULL) {
		printf("The list is empty\n");
		return;
	}
	struct node *current = head;
	struct node *ptr = NULL; //ptr to point to the node just before the current
	if (head->data.id == ID) {
		head = head->next;
		free(current);
		printf("Student with ID %d has been deleted\n", ID);
		return;
	}
	while (current != NULL && current->data.id != ID) {
		ptr = current;
		current = current->next;
	}
	if (current == NULL) {
		printf("Student with ID %d not found\n", ID);
		return;
	}
	ptr->next = current->next;
	free(current);
	printf("Student with ID %d has been deleted\n", ID);
}



int main(void){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int x;//this is the variable which we will use in the switch case
	int ID; //ID variable to use in case 3 and 4 and 5
	do{printf("---------------------------------------------\n");
		printf("1. Add Student \n"
				"2. Display all Students\n"
				"3. Search Student by ID\n"
				"4. Update Student Information\n"
				"5. Delete Student\n"
				"6. Average GPA\n"
				"7. Search For Student With Highest GPA\n"
				"8. Exit\n");
		printf("Enter Choice:");
		scanf("%d",&x);
		printf("---------------------------------------------\n");
		switch(x){
		case 1:
			printf("Enter the student id: ");
			scanf("%d",&std.id);
			printf("Enter the student name: ");

			scanf("%s",std.name);
			printf("Enter the student age: ");
			scanf("%d",&std.age);
			printf("Enter the student GPA: ");
			scanf("%f",&std.gpa);
			addStudent(&std);
			break;

		case 2:
			displayStudents();
			break;

		case 3:
			printf("Enter the Student ID you want to search for: ");
			scanf("%d",& ID);
			searchStudentByID(ID);
			break;

		case 4:
			printf("Enter the Student ID you want to update information of");
			scanf("%d",& ID);
			updateStudent(ID);
			break;


		case 5:
			printf("Enter the ID of The student you want to delete");
			scanf("%d",&ID);
			deleteStudent(ID);
			break;


		case 6:
			printf("Average gpa=  %.2f\n " , calculateAverageGPA());
			break;

		case 7: searchHighestGPA();
		break;

		case 8: printf("Application will be terminated, Thank You");
		return 0;

		default: printf("Incorrect entry please try again");
		break;

		}
	}while(1);
}


