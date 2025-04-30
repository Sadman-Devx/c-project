#include<stdio.h>
struct contact
{
    char name[50];
    char phone[50];
    char email[50];
};
void addcontact()
{
    struct contact contact;

    fflush(stdin);
    FILE *file;
    file = fopen("contact managment.txt","a");
    if(file==NULL){
        printf("file doesn't existed");
    }
    else
    {


        printf("Enter a name: ");
        fgets(contact.name,sizeof contact.name,stdin);

        printf("Enter a phone: ");
        fgets(contact.phone,sizeof contact.phone,stdin);

        printf("Enter a email: ");
        fgets(contact.email,sizeof contact.email,stdin);

        fprintf(file,"%s%s%s\n",contact.name,contact.phone,contact.email);

        fclose(file);

        printf("Added to contact managment system\n");
    }
}
void displaycontact()
{
    struct contact contact;

    FILE *file;
    file = fopen("contact managment.txt","r");
    if(file==NULL){
        printf("file doesn't existed");
    }
    else
    {
        printf("Contacts.\n");

        while(fscanf(file," %[^\n] %[^\n] %[^\n]",contact.name,contact.phone,contact.email)!=EOF)
        {
            printf("Name: %s\nphone: %s\nemail: %s\n\n",contact.name,contact.phone,contact.email);
            //printf("\n");
        }

        fclose(file);

    }
}
int main()
{
    int choice;
    do{
        printf("\nContact Managment System\n");
        printf("1. Added Contact\n");
        printf("2. Display Contact\n");
        printf("3. Exist\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
    case 1:
        addcontact();
        break;
    case 2:
        displaycontact();
        break;
    case 3:
        printf("Exiting...\n");
        break;
    default:
        printf("Invalid choice. please try again\n");

        }
    } while(choice!=3);
    return 0;

}
