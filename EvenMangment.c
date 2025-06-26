#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user{
    char fullName[50];
    char emaill[50];
    char password[50];
    char username[50];
    char phone[50];
};

void takeuserName()
{

}
int main(){
    int choice;
    printf("\t \t \t \t--------Welcome to Even Mangment System--------\t \t \t \t \n"); 
    printf("Main Menu");
    printf("\n1.Register");
    printf("\n2.Login");
    printf("\n3.Exict");


    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    fgetc(stdin);

    switch(choice){
        case 1:
            printf("Enter your full name: ");
            takeinput(user.fullName);
            printf("Enter your Emaill: ");
            takeinput(user.email);
            printf("Enter your contact: ");
            takeinput(user.phone);
            break;

    }



}