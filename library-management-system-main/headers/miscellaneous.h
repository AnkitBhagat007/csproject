#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#include <stdlib.h>
#else
#include <unistd.h>
#include <stdio.h>
#endif

void displayASCII(char [50]);
void pause(int);
void clear();
void toLower(char *);

void displayASCII(char fileName[50])
{
    FILE *file = fopen(fileName, "r");

    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    fclose(file);

    printf("\n\n\n");
}

void pause(int seconds)
{
    #ifdef _WIN32
        Sleep(seconds*1000); // Windows: Sleep for 3000 milliseconds (3 seconds)
    #else
        sleep(seconds);    // Unix-like systems: Sleep for 3 seconds
    #endif
}

void clear()
{
    #ifdef _WIN32
       
       
    #else
        printf("\033[2J\033[1;1H"); // Unix-like systems (ANSI escape codes)
    #endif
}

char *formatIssueDate()
{
    char *date = malloc(10 * sizeof(char));
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(date,"%02d/%02d/%d", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);


    return date;
}

char *formatDueDate(int issue_time)
{
    char *date = malloc(10 * sizeof(char));
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(date,"%02d/%02d/%d", tm->tm_mday, tm->tm_mon + 1+issue_time, tm->tm_year + 1900);


    return date;
}
void toLower(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
}

