#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bankEmployee {
    char name[20];
    int salary;
    struct bankEmployee *next;
};

typedef struct bankEmployee BANKEmployee;
typedef BANKEmployee *BANKEmployeePtr;

int main() {

    BANKEmployeePtr startPtr=NULL;
    BANKEmployeePtr newPtr;
    BANKEmployeePtr currentPtr;
    BANKEmployeePtr previousPtr;
    BANKEmployeePtr tempPtr;

    newPtr = (BANKEmployee*) malloc(sizeof(BANKEmployee));
    strcpy(newPtr->name, "Justin");
    newPtr->salary = 1000;
    newPtr->next = NULL;

    startPtr = newPtr; //Start the list with Justin

    newPtr = (BANKEmployee*) malloc(sizeof(BANKEmployee));
    strcpy(newPtr->name, "Sam");
    newPtr->salary = 999;
    newPtr->next = NULL;

    startPtr->next = newPtr; //Sam is next in the list

    newPtr = (BANKEmployee*) malloc(sizeof(BANKEmployee));
    strcpy(newPtr->name, "Antony");
    newPtr->salary = 200;
    newPtr->next = startPtr;//Point to the start of the list

    startPtr = newPtr;//Now the list starts with Antony

    currentPtr = startPtr->next->next; //Point to Sam

    newPtr = (BANKEmployee*) malloc(sizeof(BANKEmployee));
    strcpy(newPtr->name, "Tony");
    newPtr->salary = 300;
    newPtr->next = NULL;

    currentPtr->next = newPtr;//Sam now points to Tony

    previousPtr = startPtr->next; //Point to Justin

    newPtr = (BANKEmployee*) malloc(sizeof(BANKEmployee));
    strcpy(newPtr->name, "Peter");
    newPtr->salary = 400;
    previousPtr->next = newPtr; //Justin now points to Peter and breaks connection to Sam
    newPtr->next = currentPtr; //Peter now points to Sam

    currentPtr=startPtr;
    
    while(currentPtr!=NULL) {
        printf("Name: %s\n", currentPtr->name);
        printf("Salary: %d\n", currentPtr->salary);
        currentPtr=currentPtr->next;
    }

    currentPtr=startPtr;

    while(currentPtr!=NULL) {
        currentPtr = tempPtr;
        currentPtr = currentPtr->next;
        free(tempPtr);
    }

    return 0;
}