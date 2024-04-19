#include "./headers/authentication.h"
#include "./headers/miscellaneous.h"
#include "./headers/librarySystem.h"
#include "./headers/admin.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student student;

void welcomePage();
void homePage();

void return_back()
{
    int temp;

    printf("\npress 1 to go back : ");
    scanf("%d",&temp);
    if(temp==1)
    {
        system("cls");
        homePage();
    }
}

void welcomePage()
{
    int choice;

    displayASCII("ascii-arts/header.txt");
    displayASCII("ascii-arts/welcome.txt");

    scanf("%d",&choice);

    if(choice==1)
    {
        registerUser();
        
        printf("\n\nRegistered Successfully!\nRedirecting to welcomepage\n");

        pause(2);//pauses the code execution for 2seconds   -->defined in header file mascillaneous
        system("cls");//clears the console

        welcomePage();
    }
    else if(choice==2)
    {
        student=loginUser();
        if(login)
        {
            printf("\n\nLogined Successfully\nRedirecting to Homepage\n");

            pause(2);
            system("cls");

            homePage();
        }
        else
        {
            printf("\n\nIncorrect password!\nRedirecting to Welcomepage\n");
            
            pause(2);
            

            welcomePage();
        }
    }
}

void homePage()
{

    if(ADMIN==0){
        int choice;
        displayASCII("./ascii-arts/header.txt");
        displayASCII("./ascii-arts/home.txt");
        scanf("%d",&choice);

        if(choice==1)
        {
            if(student.nBooks<6)
            {
                printf("The lists of book that you can issue are:-\n");
            }
            else
            {
                printf("You can't issue more than 5 books at a time.\nReturn a book before issuing another\n\n");
            }
            
            // initializeBooks();

            // struct Book bookIssued[11];
            // readLibraryFromFile(bookIssued,sizeof(bookIssued) / sizeof(bookIssued[0]));

            printBooks();

            int issuebook=0;
            printf("enter the book you want to be issued : ");

            scanf("%d",&issuebook);
            addToIssuedBook(issuebook);
            
            printf("\nbook issued succesfull\nRedirecting to Homepage\n");
            pause(2);
            system("cls");
            homePage();

        }
        else if(choice==2)
        {   int temp;
            printIssuedBooks(Email);
            
            return_back();
        }
        else if(choice==3)
        {   int temp;
            printIssuedBooks(Email);
            printf("\nEnter the book number to return:-\n");
            int book_number;
            scanf("%d",&book_number);

            return_book(book_number);

            printf("\nBook has been returned sucessefully\n");

            return_back();
        }
        else if(choice==4)
        {   int temp;
            printMessage(Email);

            return_back();
        }
        else
        {
            printf("Invalid Choice!\n");

            
            clear();
        
            
        }

    }


    if(ADMIN==1){
        int choice;
        
        displayASCII("./ascii-arts/header.txt");
        displayASCII("./ascii-arts/admin-features.txt");

        scanf("%d",&choice);

        if(choice==1)
        {
            addBook();
            int temp;
            
            return_back();
        }else if(choice==2){
            
            sendMail();

            printf("email sent sucessfully ");

            int temp;

            return_back();
        

        }else if(choice == 3){

            printBooks();

            int book_number;
            printf("Book number you want to delet : ");
            scanf("%d",&book_number);

            remove_book(book_number);

            printf("book has been removed successfully from the library.\n");

            return_back();
        }else if(choice==4){

            print_users();

            return_back();
        }else if(choice == 5){
            printBooks();

            int book_number;
            printf("Book number you want to modify : ");
            scanf("%d",&book_number);
            Modify_book(book_number);

            return_back();

        }else if(choice ==6){

            print_users();
            int user_number;

            printf("user number you want to delet : ");
            scanf("%d",&user_number);

            delete_user(user_number);

            return_back();

        }else if(choice==7){
            initializeBooks();
            printf("books initialised successfully\n");

            return_back();
        }

    }
}



int main()
{
    welcomePage();    
}
//aa_aa@iitp.ac.in
