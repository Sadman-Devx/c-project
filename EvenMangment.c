#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};
void takeinput(char *str){
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = 0; // Remove trailing newline character
}

void generateusername(char *username, char *emai)
{
    int i, j = 0;
    for(i = 0; emai[i] != '@'; i++) {
        username[j++] = emai[i];
    }
    username[j] = '\0';
}

int main()
{
    int choice;
    struct user user;
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
        printf("Enter your Email: ");
        takeinput(user.email);
        printf("Enter your contact: ");
        takeinput(user.phone);
        break;
        

    }
}