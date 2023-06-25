#include "structs.h"

int main(){

    int option;
    char *filename = "students.txt";

    if (existFile(filename) == false) //if file doesnt exist
    {
        creatFile(filename);
    }
    
    printf("\n=== MENU ===\n");
    printf("1. Add Student\n2. Display All Students\n3. Search Student\n");
    printf("4. Update Stundent Information\n5. Delete a student\n6. Calculate Grades\n");
    printf("7. Attendance Management\n8. Exit");

}
