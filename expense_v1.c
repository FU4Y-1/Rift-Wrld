#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>

#define bold_on "\e[1m"
#define bold_off "\e[m"

int food=0,transport=0,medical=0,utilities=0;

void about(int *budget, int *add_budget);
int app(int *budgets, int *add_budget);
void exp_cal(int **dptrbudget, int *ptrexpense);

int main(void)
{
    int menu;
    int budget=0,add_budget=0;
    printf("Welcome to Expense Tracker\nPlease Enter your Name: ");
    char name[64];
    fgets(name, sizeof(name),stdin);
    printf("Welcome To The "bold_on"Menu "bold_off "\e[2m" "(Press Any other key to close App)\n" "\e[m");
    printf("1.Launch App\n2.About\n");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        printf("Please Enter your initial budget for the month: ");
        scanf("%d", &budget);
        app(&budget, &add_budget);
        break;
        case 2:
        about(&budget, &add_budget);
        break;
        default:
        printf("Invalid! Closing Program...\n");
        sleep(1);
        break;
    }    
}

void about(int *budget, int *add_budget)
{
    int cl;
    printf(bold_on"\nThis Program will ask for the initial budget and then ask the user to add expenses or aditional budget\n"
    "\t\tThe Program will then display the expenses in a tabular format\n" 
    "\n\t\tProject Created By: Muhammad Sufyan ... 23P-3004 and Farhan Ullah ... \n"
    "\n\nPress 1 to go back to Menu or press any other key to close the Program: "bold_off);
    sleep(3);
    scanf("%d", &cl);
    if(cl == 1)
    {
        app(budget,add_budget);
    }
    else
    {
        printf("Closing Program\n");
        sleep(1);
    }
}

int app(int *ptrbudgets,int *ptradd_budget)
{
    char exit;
    int choice;
    int initial = *ptrbudgets;
    do
    {
        printf("Select A Category: \n1. Add Budget: \n2.Add Expense: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter Aditional Budget that you want to Add: ");
                scanf("%d", ptradd_budget);
                *ptrbudgets = *ptrbudgets + *ptradd_budget;
                break;
            case 2:
                int cat;
                do  
                {
                    printf("Enter Category of Expenses: \n1.Utilites\n2.Food\n3.Transport\n4.Medical\n");
                    scanf("%d", &cat);
                    switch(cat)
                    {
                        case 1:
                            printf("Enter the amount you spent on Utilites: ");
                            scanf("%d", &utilities);
                            exp_cal(&ptrbudgets,&utilities);
                            break;
                        case 2:
                            printf("Enter the amount you spent on Food: ");
                            scanf("%d", &food);
                            exp_cal(&ptrbudgets,&food);
                            break;
                        case 3:
                            printf("Enter the amount you spent on Transport: ");
                            scanf("%d", &transport);
                            exp_cal(&ptrbudgets,&transport);
                            break;
                        case 4:
                            printf("Enter the amount you spent on Medicine: ");
                            scanf("%d", &medical);
                            exp_cal(&ptrbudgets,&medical);
                            break;
                        default:
                            printf("Inavlid Choice! Please Try Again\n\n");
                            sleep(1);
                    }
                } while (cat < 1 && cat > 4);
        }
    } while (choice < 1 && choice > 2); 
    
    printf("Do you want to continue or exit with a report?  ");
    scanf(" %c", &exit);
    do
    {
        if(exit == 'y' || exit == 'Y')
        {
            app(ptrbudgets, ptradd_budget);
            return 0;
        }
        else if(exit == 'n' || exit == 'N')
        {
            printf("\n%d", *ptrbudgets);
            return 1;
            
        }
    } while (exit != 'y' || exit != 'Y' || exit != 'n' || exit != 'N');
               
}

void exp_cal(int **dptrbudget, int *ptrexpense)
{
    **dptrbudget = **dptrbudget - *ptrexpense;

}
