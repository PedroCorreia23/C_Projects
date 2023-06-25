#include "structs.h"


int main(){

    int option;
    char *filename = "students.txt";

    if (!existFile(filename)) //if file doesnt exist
    {
        creatFile(filename);
    }

    Node* head = NULL;

    while(1) {
        printf("\n=== MENU ===\n");
        printf("1. Add Student\n2. Display All Students\n3. Search Student\n");
        printf("4. Update Stundent Information\n5. Delete a student\n6. Calculate Grades\n");
        printf("7. Attendance Management\n8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        if(option == 1) {
            Student new_student;
            printf("Enter student name: ");
            scanf("%s", new_student.name);
            printf("Enter student ID: ");
            scanf("%d", &new_student.ID);
            printf("Enter number of classes: ");
            scanf("%d", &new_student.numberClasses);

            addStudent(&head, new_student);
        } else if (option == 8) {
            break;
        } else {
            printf("Option not implemented yet!\n");
        }
    }

    writeStudentsToFile(head, "students.txt");

    return 0;
}
