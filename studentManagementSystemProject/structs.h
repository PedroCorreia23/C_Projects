#include <stdio.h>
#include <stdbool.h>

struct Student
{
    char name[50];
    int ID, numberClasses;

};

struct Classes
{
    int classID;
    char className[20];
};

//Each node will represent a student and will contain a Student struct
struct Node {
    struct Student student;
    struct Node* next;
};

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
