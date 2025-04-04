#include<stdio.h>

int main(){
    int day;
    printf("Enter Day of the Week (1-7) : ");
    scanf("%d", &day);

    switch(day){
        case 1 : printf("Today is Sunday!");
                 break;
        case 2 : printf("Today is Monday!");
                 break;
        case 3 : printf("Today is Tueday!");
                 break;
        case 4 : printf("Today is Wednesday!");
                 break;
        case 5 : printf("Today is Thursday!");
                 break;
        case 6 : printf("Today is Friday!");
                 break;
        case 7 : printf("Today is Saturday!");
                 break;
        default : printf("Wrong Input!");
    }
}