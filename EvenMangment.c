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

struct admin
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
void generateusername(char *username, char *email)
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
    //you can use both
    //for user
    int user_choice;
    int usrFound;
    struct user user;
    char password2[50];
    char username[50],pass[50];
    struct user usr;
    //for admin
    int admin_choice;
    int admin_found;
    struct admin admin;
    struct admin admin_;
    char admin_name[50],admin_pass[50],password1[50];
    int choice;
    printf("Select user type:\n");
    printf("1. Admin\n");
    printf("2. User\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    fgetc(stdin);

    do{

        switch(choice)
    {
        case 1:

        do{
            printf("Admin Menu\n");
            printf("1. Register\n");
            printf("2. Login\n");
            printf("3. Exit\n");

            printf("Enter your choice: ");
            scanf("%d",&admin_choice);
            fgetc(stdin);

            switch(admin_choice)
            {
                case 1:
                printf("Enter your full name:\t");
                takeinput(admin.fullName);
                printf("Enter your emaill:\t");
                takeinput(admin.email);
                printf("Enter your contact:\t");
                takeinput(admin.phone);
                while (1)
                {
                    printf("Enter your password:\t");
                    takepassword(admin.password);
                    printf("\nConfirm your password:\t");
                    takepassword(password1);

                    if(!strcmp(admin.password,password1))
                    {
                        generateusername(admin.username,admin.email);
                        printf("\nPassword matched\n");

                        file = fopen("admin.data","ab");//admin data store file open
                        if(file != NULL)
                        {
                            if(fwrite(&admin,sizeof(struct admin),1,file)==1)
                            {
                                printf("Admin registered successfully!\n");
                                printf("user name is: %s\n",admin.username);
                            }
                            else
                            {
                                printf("Erron writing to file!\n");
                            }
                            fclose(file);
                        }
                        else
                        {
                            printf("could not open file for writing!\n");
                        }
                        break;//otherwise loop doesn't end.
                    }
                    else
                    {
                        printf("\nPassword do not match. Please try again.\n");
                        Beep(600,200);
                    }                    
                }
                break;

                case 2:

                printf("\n\t\t\t-------- Login --------\n");
                printf("\nEnter your username:\t");
                takeinput(username);
                printf("Enter your password:\t");
                takepassword(admin_pass);
                admin_found = 0;

                //system("cls"); // Clear the console for better user experience

                file = fopen("admin.data", "rb");
                if (file != NULL)
                {
                    while (fread(&admin, sizeof(struct admin), 1, file))
                    {
                        if (!strcmp(admin.username, username))
                        {
                            admin_found = 1;  // Moved here
                            if (!strcmp(admin.password, admin_pass))
                            {
                                printf("\nWelcome %s!\n", admin.fullName);
                            }
                            else
                            {
                                printf("\nInvalid password.\n");
                                Beep(600, 200);
                            }
                            break;
                        }   
                    }
                    fclose(file);

                    if (!admin_found)
                    {
                        printf("\nUser not found!\n");
                        Beep(600, 200);
                    }
                }
                break ;

                case 3:
                printf("Exiting....\n");
                exit(0);
                break;
                
                default:
                printf("Invalid choice \n"); 
            }

        }while(admin_choice != 3);
         break;

        case 2:
        

        do
        {
        printf("\n\t \t \t--------Welcome to Even Mangment System--------\t \t \t \t \n");
        printf("Main Menu");
        printf("\n1.Register");
        printf("\n2.Login");
        printf("\n3.Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&user_choice);
        fgetc(stdin);

        switch(user_choice)
        {
        case 1:
            printf("Enter your full name:\t");
            takeinput(user.fullName);
            printf("Enter your Email:\t");
            takeinput(user.email);
            printf("Enter your contact:\t");
            takeinput(user.phone);
            while (1)
            {
                printf("Enter your password:\t");
                takepassword(user.password);
                printf("\nConfirm password:\t");
                takepassword(password2);

                if (!strcmp(user.password, password2))
                {
                    generateusername(user.username, user.email);
                    printf("\nPassword matched\n");

                    file = fopen("users.data", "ab");
                    if (file != NULL)
                    {
                        if (fwrite(&user, sizeof(struct user), 1, file) == 1)
                        {
                            printf("User registered successfully!\n");
                            printf("Your username is: %s\n", user.username);
                        }
                        else
                        {
                            printf("Error writing to file!\n");
                        }
                        fclose(file);
                    }
                    else
                    {
                        printf("Could not open file for writing!\n");
                    }
                    break;
                }
                else
                {
                    printf("\nPasswords do not match. Please try again.\n");
                    Beep(600, 200);
                }
            }
            break;

        case 2:
            printf("\n\t\t\t-------- Login --------\n");
            printf("\nEnter your username:\t");
            takeinput(username);
            printf("Enter your password:\t");
            takepassword(pass);
            usrFound = 0;

            system("cls"); // Clear the console for better user experience

            file = fopen("users.data", "rb");
            if (file != NULL)
            {
                while (fread(&usr, sizeof(struct user), 1, file))
                {
                    if (!strcmp(usr.username, username))
                    {
                        usrFound = 1;  // Moved here
                        if (!strcmp(usr.password, pass))
                        {
                            printf("\nWelcome %s!\n", usr.fullName);
                        }
                        else
                        {
                            printf("\nInvalid password.\n");
                            Beep(600, 200);
                        }
                        break;
                    }
                }
                fclose(file);

                if (!usrFound)
                {
                    printf("\nUser not found!\n");
                    Beep(600, 200);
                }
            }
            break ;

        case 3:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }

    }
    while(user_choice != 3);
        break;

        case 3:
        printf("Exiting......");
        break;
        default:
        printf("Invalid choice");   
    }
    }while(choice != 3);

    return 0;
}