#include "structs.h"

int main(){

    int option, c;
    char *filename = "students.txt";
    char studentName[50];

    if (!existFile(filename)) //if file doesnt exist
    {
        creatFile(filename);
    }

    Node* head = NULL;
    Student new_student;

    while(1) {

        printf("\n=== MENU ===\n");
        printf("1. Add Student\n2. Display All Students\n3. Search Student\n");
        printf("4. Update Stundent Information\n5. Delete a student\n6. Calculate Grades\n");
        printf("7. Attendance Management\n8. Save\n9. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        while ((c = getchar()) != '\n' && c != EOF);

        switch (option)
        {
        case 1:
            
            printf("Enter student name: ");
            fgets(new_student.name, 50, stdin);
            new_student.name[strcspn(new_student.name, "\n")] = 0;
            printf("Enter student ID: ");
            scanf("%d", &new_student.ID);
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Enter number of classes: ");
            scanf("%d", &new_student.numberClasses);
            while ((c = getchar()) != '\n' && c != EOF);

            addStudent(&head, new_student);
            break;
        case 2:
            printf("\n====Students====\n");
            printStudents(filename);
            break;
        case 3:
            printf("Insert student name: ");
            scanf(" %[^\n]s", new_student.name);

            searchStudent(filename, new_student.name);
            break;

        case 8:
            writeStudentsToFile(head, "students.txt");
            printf("Data saved successfully.\n");
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid Option!");
            break;
        }
    }

    return 0;
}
