#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Student
{
    char name[50];
    int ID, numberClasses;
} Student;

typedef struct Classes
{
    int classID;
    char className[20];
} Classes;

typedef struct Node
{
    Student student;
    struct Node* next;
} Node;

bool existFile(const char *filename){
    
    FILE *fp = fopen(filename, "r");
    bool exist = false;
    if (fp != NULL)
    {
        exist = true;
        fclose(fp); // close the file
    }
    return exist;
}

void creatFile(const char *filename){
    // Create a file
    FILE *fp = fopen(filename, "w"); 

    // Close the file
    fclose(fp);
}

void addStudent(struct Node **head, struct Student new_student_data){

    /* allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head;

    new_node->student = new_student_data;

    new_node->next = NULL;

    /*If the Linked List is empty, then make the new
    * node as head */
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void writeStudentsToFile(struct Node* head, const char* filename) {
    // Open the file in write mode.
    FILE* fp = fopen(filename, "a");

    // If the file could not be opened, print an error message and return.
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    // Write the student data for each node in the linked list.
    struct Node* temp = head;
    while (temp != NULL) {
        struct Student student = temp->student;

        // Write the student's name, ID, and number of classes to the file.
        fprintf(fp, "Name: %s, ID: %d, Classes: %d\n", student.name, student.ID, student.numberClasses);

        // Move on to the next student.
        temp = temp->next;
    }

    // Close the file after writing.
    fclose(fp);
}

void printStudents(const char* filename){

    int c;
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    while ((c = getc(fp)) != EOF)
    {
        printf("%c", c);
    }
    fclose(fp);
}
