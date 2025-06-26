#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8




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

void takepassword(char pwd[50])
{
    int i =0;
    char ch;
    while (1)
    {
        ch = getch(); // Use getch() to read a character without echoing it

        if(ch == ENTER || ch == TAB){
            pwd[i] = '\0';
            break;
        }
        else if(ch == BCKSPC){
            if(i>0){
                i--;
                printf("\b \b");

            }
        }
        else{
            pwd[i++] = ch;
            printf("*");
        }
    }

}
void generateusername(char *username, char *email)
{
    int i, j = 0;
    for(i = 0; email[i] != '@'; i++) {
        username[j++] = email[i];
    }
    username[j] = '\0';
}

int main()
{
    int choice;
    struct user user;
    printf("\t \t \t--------Welcome to Even Mangment System--------\t \t \t \t \n");
    printf("Main Menu");
    printf("\n1.Register");
    printf("\n2.Login");
    printf("\n3.Exit");


    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    fgetc(stdin);

    switch(choice){
        case 1:
        printf("Enter your full name:\t");
        takeinput(user.fullName);
        printf("Enter your Email:\t");
        takeinput(user.email);
        printf("Enter your contact:\t");
        takeinput(user.phone);
        printf("Enter your password:\t");
        takepassword(user.password);
        break;


    }
}
