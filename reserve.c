#include <stdio.h>
#include <string.h>
#include "reserve.h"

void printCalendar(Reserve *r[], int count, int month)
{
    int dates[31];
    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
    {
        printf("--------------%d--------------\n",month);
        printf("|SUN|MON|TUE|WED|THU|FRI|SAT|\n");
        for(int i=0;i<31;i++)
            dates[i]=i+1;
        for(int i=0;i<31;i++){
            if(i!=0 && i%7==0)
                printf("|\n");
            printf("| %2d",dates[i]);
        }
    }
    printf("|");
    
}
void searchNop(Reserve *r[],int count)
{

}
void searchStid(Reserve *r[],int count)
{

}
void saveFile(Reserve *r[], int count)
{

}
void addReserve(Reserve *r[], int count)
{

}
void loadFile(Reserve *r[],int count)
{

}
void updateReserve(Reserve *r[],int count)
{

}
int chooseNo(Reserve *r[],int count)
{

}
void loadMenu()
{

}
void checkNoshow(Reserve *r[],int count)
{
    
}