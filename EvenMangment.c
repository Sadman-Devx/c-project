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
struct event
{
    char eventName[50];
    char eventDate[20];
    char eventTime[10];
    char eventLocation[100];
};

FILE *file;
FILE *event;

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

void booking_event()
{
    FILE *event = fopen("event.txt", "r");
    if (event == NULL)
    {
        printf("No events found.\n");
        return;
    }

    char line[256];
    char events[20][256]; // Supports up to 20 events
    int count = 0;
    struct user user;
    
    printf("\n\t\t\t-------- Booking Event --------\n");
    printf("\nPlease select an event to book:\n"); 

    printf("Available Events:\n");
    while (fgets(line, sizeof(line), event))
    {
        if (strstr(line, "Event Name:") != NULL)
        {
            strcpy(events[count], line);
            printf("%d. %s", count + 1, line);
            count++;
        }
    }
    fclose(event);

    if (count == 0)
    {
        printf("No events available for booking.\n");
        return;
    }

    int choice;
    printf("Enter the number of the event you want to book: ");
    scanf("%d", &choice);
    fgetc(stdin);

    if (choice < 1 || choice > count)
    {
        printf("Invalid selection.\n");
        return;
    }
    FILE *fp = fopen("booking.txt","a");
    if (fp == NULL)
    {
        printf("Error opening booking file.\n");
        return;
    }
    else{
        printf("You selected: %s\n", events[choice - 1]);
    
        printf("Enter your full name:\t");
        takeinput(user.fullName);
        printf("Enter your Email:\t");
        takeinput(user.email);
        printf("Enter your contact:\t");
        takeinput(user.phone);
        printf("Booking confirmed for event: %s\n", events[choice - 1]);
        fprintf(fp, "%s,%s,%s,%s\n", user.fullName, user.email, user.phone, events[choice - 1]);
        fclose(fp);
    }
    
    printf("Thank you for booking!\n\n");

    // Here you can add booking logic, e.g., save booking info to a file
}

void cancel_booking()
{
    char email[50], event_name[256], line[512];
    int found = 0;

    FILE *fp = fopen("booking.txt", "r");
    if (fp == NULL)
    {
        printf("No bookings found.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("Error opening temp file.\n");
        fclose(fp);
        return;
    }

    printf("\n\t\t\t-------- Cancel Booking --------\n");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); //  clear buffer once before next input
    
    printf("Enter your email: ");
    takeinput(email);

    printf("Enter the event name to cancel: ");
    takeinput(event_name);

    while (fgets(line, sizeof(line), fp))
    {
        char name[100], mail[100], phone[100], event[256];
        // Tokenize the line assuming format: name,email,phone,Event Name:
        sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", name, mail, phone, event);
        // Remove trailing newline from event if present
        event[strcspn(event, "\n")] = 0;
        // debugging output
        // printf("Checking booking: %s, %s, %s, %s\n", name, mail, phone, event);
        if (strcmp(mail, email) == 0 && strstr(event, event_name) != NULL)
        {
            found = 1; // Skip this line (i.e., cancel this booking)
            continue;
        }

        fputs(line, temp); // Keep this booking
    }

    fclose(fp);
    fclose(temp);

    remove("booking.txt");
    rename("temp.txt", "booking.txt");

    if (found)
        printf("Booking cancelled successfully.\n");
    else
        printf("Booking not found.\n");
}

void booking_history()
{
    FILE *fp = fopen("booking.txt", "r");
    if (fp == NULL)
    {
        printf("No bookings found.\n");
        return;
    }

    char line[512];
    printf("\n\t\t\t-------- Booking History --------\n");
    printf("Your Booking History:\n");

    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);
}

// edit event function
void edit_event()
{
    char search_name[100], line[256];
    int found = 0;
    printf("Enter the event name to edit: ");
    takeinput(search_name);

    FILE *fp = fopen("event.txt", "r");
    FILE *temp = fopen("temp_event.txt", "w");
    if (fp == NULL || temp == NULL) {
        printf("Error opening file.\n");
        if(fp) fclose(fp);
        if(temp) fclose(temp);
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Event Name:") != NULL && strstr(line, search_name) != NULL) {
            found = 1;
            struct event ev;
            printf("\n\t\t\t-------- Edit Event --------\n");
            printf("Editing event: %s", line);
            printf("Enter new event name: ");
            takeinput(ev.eventName);
            printf("Enter new event date (DD/MM/YYYY): ");
            takeinput(ev.eventDate);
            printf("Enter new event time (HH:MM): ");
            takeinput(ev.eventTime);
            printf("Enter new event location: ");
            takeinput(ev.eventLocation);

            fprintf(temp, "Event Name: %s\n", ev.eventName);
            fprintf(temp, "Event Date: %s\n", ev.eventDate);
            fprintf(temp, "Event Time: %s\n", ev.eventTime);
            fprintf(temp, "Event Location: %s\n", ev.eventLocation);
            fprintf(temp, "-----------------------------\n");

            // Skip the next 4 lines (old event details)
            for(int i=0; i<4; i++) fgets(line, sizeof(line), fp);
        } else {
            fputs(line, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("event.txt");
    rename("temp_event.txt", "event.txt");

    if (found)
        printf("Event updated successfully!\n");
    else
        printf("Event not found.\n");
}

void Feedback()
{
    char feedback[500];
    printf("\n\t\t\t-------- Feedback --------\n");
    printf("Please provide your feedback:\n");
    takeinput(feedback);

    FILE *fp = fopen("feedback.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening feedback file.\n");
        return;
    }
    
    fprintf(fp, "%s\n", feedback);
    fclose(fp);
    
    printf("Thank you for your feedback!\n");
}

void view_feedback()
{
    FILE *fp = fopen("feedback.txt", "r");
    if (fp == NULL)
    {
        printf("No feedback found.\n");
        return;
    }

    char line[500];
    printf("\n\t\t\t-------- Feedback --------\n");
    printf("Feedback from users:\n");

    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);
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

    //
    //for event
    struct event ev;
    char event_name[50], event_date[20], event_time[10], event_location[100];
    int i;

    //select option
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
        case 1://for admin
        system("cls"); // Clear the console for better user experience 

        do{
            printf("\n\t \t \t--------Welcome to Even Mangment System--------\t \t \t \t \n");
            printf("Admin Menu\n");
            printf("1. Register\n");
            printf("2. Login\n");
            printf("3. Exit\n");

            printf("Enter your choice: ");
            scanf("%d",&admin_choice);
            fgetc(stdin);

            switch(admin_choice)
            {
                case 1://admin register
                system("cls"); // Clear the console for better user experience 
                printf("\n\t\t\t-------- Admin Registration --------\n");
                printf("\nEnter your full name:\t");
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

                case 2://admin login
                system("cls"); // Clear the console for better user experience
                printf("\n\t\t\t-------- Login --------\n");
                printf("\nEnter your username:\t");
                takeinput(username);
                printf("Enter your password:\t");
                takepassword(admin_pass);
                admin_found = 0;

                system("cls"); // Clear the console for better user experience

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
                                printf("\n\t\t\t-------- Admin Dashboard --------\n");
                                printf("\n\t\t\tWelcome %s!\n", admin.fullName);
                                // add event
                                int event_choice;
                                do
                                {
                                printf("1. Adding an event...\n");
                                printf("2. View events\n");
                                printf("3. Edit event\n");
                                printf("4. View booking history\n");
                                printf("5. View feedback\n");
                                printf("6. Log out\n");
                                printf("Enter your choice: ");

                                scanf("%d", &event_choice);
                                while (getchar() != '\n'); // Clear the newline character from the input buffer
                                switch(event_choice)
                                {
                                    case 1:
                                        // Add event
                                        system("cls"); // Clear the console for better user experience
                                        printf("\n\t\t\t-------- Add Event --------\n");
                                        event = fopen("event.txt","a");
                                        if(event == NULL){
                                            printf("list is empty");
                                        }
                                        else{
                                            printf("\nEnter event name: ");
                                            takeinput(ev.eventName);
                                            printf("Enter event date (DD/MM/YYYY): ");
                                            takeinput(ev.eventDate);
                                            printf("Enter event time (HH:MM): ");
                                            takeinput(ev.eventTime);
                                            printf("Enter event location: ");
                                            takeinput(ev.eventLocation);

                                            fprintf(event, "Event Name: %s\n", ev.eventName);
                                            fprintf(event, "Event Date: %s\n", ev.eventDate);
                                            fprintf(event, "Event Time: %s\n", ev.eventTime);
                                            fprintf(event, "Event Location: %s\n", ev.eventLocation);
                                            fprintf(event, "-----------------------------\n");
                                            
                                            fclose(event);
                                            printf("Event added successfully!\n");  

                                        }
                                        break;

                                    case 2:
                                        // View events
                                        system("cls"); // Clear the console for better user experience
                                        printf("\n\t\t\t-------- View Events --------\n");
                                        event = fopen("event.txt","r");
                                        if(event == NULL){
                                            printf("No events found.\n");
                                        }
                                        else{
                                            char line[256];
                                            while(fgets(line, sizeof(line), event)){
                                                printf("%s", line);
                                            }
                                            fclose(event);
                                        }
                                        break;
                                    case 3:
                                        // Edit event
                                        system("cls"); // Clear the console for better user experience
                                        edit_event();
                                        break;
                                    
                                    case 4:
                                        // View booking history
                                        system("cls"); // Clear the console for better user experience
                                        booking_history();
                                        break;

                                    case 5:
                                        // View feedback
                                        system("cls"); // Clear the console for better user experience
                                        view_feedback();
                                        break;

                                    case 6:
                                        printf("Log out\n");
                                        exit(0);

                                    default:
                                        printf("Invalid choice!\n");
                                }
                              } while(event_choice != 6);
                                
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

        case 2://for user
        
        system("cls"); // Clear the console for better user experience
        do
        {
        printf("\n\t \t \t--------Welcome to Even Mangment System--------\t \t \t \t \n");
        printf("User Menu");
        printf("\n1.Register");
        printf("\n2.Login");
        printf("\n3.Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&user_choice);
        fgetc(stdin);

        switch(user_choice)
        {
        case 1://user register
            system("cls"); // Clear the console for better user experience
            printf("\n\t\t\t-------- User Registration --------\n");
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

        case 2://user login
            system("cls"); // Clear the console for better user experience
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
                            printf("\n\t\t\t-------- User Dashboard --------\n");
                            printf("\n\t\t\tWelcome %s!\n", usr.fullName);
                            //selectted choice
                            
                            int user_choice;
                            do {
                            printf("1. View events\n");
                            printf("2. Book an event\n");
                            printf("3. Cancel a booking\n");
                            printf("4. Booking history\n");
                            printf("5. Feedback\n");
                            printf("6. Log out\n");
                            printf("Enter your choice: ");
                            int event_choice;
                            scanf("%d", &event_choice); 

                            switch(event_choice)
                            {
                                //user freature
                                case 1:
                                system("cls"); // Clear the console for better user experience
                                printf("\n\t\t\t-------- View Events --------\n");
                                event = fopen("event.txt","r");
                                        if(event == NULL){
                                            printf("No events found.\n");
                                        }
                                        else{
                                            char line[256];
                                            while(fgets(line, sizeof(line), event)){
                                                printf("%s", line);
                                            }
                                            fclose(event);

                                        }
                                break;

                                case 2:
                                system("cls"); // Clear the console for better user experience
                                booking_event();

                                break;

                                case 3:
                                system("cls"); // Clear the console for better user experience
                                cancel_booking();
                                break;

                                case 4:
                                system("cls"); // Clear the console for better user experience
                                booking_history();
                                break;

                                case 5:
                                system("cls"); // Clear the console for better user experience
                                Feedback();
                                break;

                                case 6:
                                printf("Logging out...\n");
                                exit(0);
                                break;

                                default:
                                printf("Invalid choice!\n");

                            }

                            }while(user_choice != 6);
                            
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