#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user
{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

FILE *file;

void takeinput(char *str)
{
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

        if(ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }
        else if(ch == BCKSPC)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");

            }
        }
        else
        {
            pwd[i++] = ch;
            printf("*");
        }
    }

}
char generateusername(char *username, char *email)
{
    int i, j = 0;
    for(i = 0; email[i] != '@'; i++)
    {
        username[j++] = email[i];
    }
    username[j] = '\0';
}


int main()
{
    int choice;
    int usrFound =0;
    struct user user;
    char password2[50];
    printf("\t \t \t--------Welcome to Even Mangment System--------\t \t \t \t \n");
    printf("Main Menu");
    printf("\n1.Register");
    printf("\n2.Login");
    printf("\n3.Exit\n");


    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    fgetc(stdin);

    switch(choice)
    {
    case 1:
        printf("Enter your full name:\t");
        takeinput(user.fullName);
        printf("Enter your Email:\t");
        takeinput(user.email);
        printf("Enter your contact:\t");
        takeinput(user.phone);
        printf("Enter your password\t");
        takepassword(user.password);
        printf("\nConfirm password\t");
        takepassword(password2);
        
        if(!strcmp(user.password,password2))
        {
            generateusername(user.username,user.email);
            printf("\nPassword matched");
            file = fopen("users.data", "a");
                fwrite(&user, sizeof(struct user), 1, file);
                if (fwrite!=0)
                {
                    printf("\nUser registered successfully!");
                    printf("\nYour user name is %s", user.username);
                    fclose(file);
                }
                else
                {
                    printf("\nError in registering user.\n");
                }


        }
        else
        {
            printf("\nPassword do not matched\nPlease try again.");
            Beep(600,200);
            printf("\nEnter your password\t");
            takepassword(user.password);
            printf("\nConfirm password\t");
            takepassword(password2);
            if(!strcmp(user.password,password2))
            {
                generateusername(user.username,user.email);
                printf("\nPassword matched");
                fwrite(&user, sizeof(struct user), 1, file);
                if (fwrite!=0)
                {
                    printf("\nUser registered successfully!");
                    printf("\nYour user name is %s", user.username);
                    fclose(file);
                }
                else
                {
                    printf("\nError in registering user.\n");
                }


            }

            break;

        }

       case 2:
            char username[50],pass[50];
            struct user usr;

            printf("\nEnter your username\t");
            takeinput(username);
            printf("\nEnter your password:\t");
            takepassword(pass)

            file = fopen("users.data","r");
            while (fread(&usr,sizeof(struct user),1,file)) {
                if(!strcmp(usr.username,username)){
                    if(!strcmp(usr.password,pass)){
                        printf("\n\t\t\t\tWelcome %s",usr.fullName);
                    }
                }
                else{
                    printf("Invalid Password");
                    beep(600,200)
                }
                usrFound = 1;
            }
            if(!usrFound){
                printf("\n\nUser is not registered!");
                Beep(600,200);
            }
            fclose(file)
            break;    
             
    }
}