#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct calElement
{
    char *day;
    int date;
    char *activity;
};

/* Function to create calendar */
struct calElement* create()
{
    struct calElement *calendar;
    calendar = (struct calElement *)malloc(sizeof(struct calElement) * 7);
    return calendar;
}

/* Function to read calendar details */
void read(struct calElement *calendar)
{
    char day[10];
    char activity[50];
    int i, date;

    for (i = 0; i < 7; i++)
    {
        printf("Enter the day : ");
        scanf("%s", day);

        calendar[i].day = (char *)malloc(strlen(day) + 1);
        strcpy(calendar[i].day, day);

        printf("Enter the date : ");
        scanf("%d", &date);
        calendar[i].date = date;

        getchar(); // clear newline buffer

        printf("Enter description of the activity : ");
        scanf("%[^\n]", activity);

        calendar[i].activity = (char *)malloc(strlen(activity) + 1);
        strcpy(calendar[i].activity, activity);
    }
}

/* Function to display calendar */
void display(struct calElement *calendar)
{
    int i;
    printf("\nYour Calendar\n");
    printf("Day\tDate\tActivity\n");

    for (i = 0; i < 7; i++)
    {
        printf("%s\t%d\t%s\n",
               calendar[i].day,
               calendar[i].date,
               calendar[i].activity);
    }
}

/* Main function */
int main()
{
    struct calElement *calendar;

    calendar = create();
    read(calendar);
    display(calendar);

    free(calendar);
    return 0;
}
