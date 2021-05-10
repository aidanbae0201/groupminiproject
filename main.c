#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reserve.h"

int main()
{
    int count=0;
    int index=0;
    Reserve *r[100];
    int menu = loadMenu();
    while(1)
    {
        if(menu==0)
            break;
        if(menu==3 || menu==4 || menu==5 || menu==6)
        {
            if(count==0) continue;
        }
        if(menu==2)
        {
            r[index] = (Reserve*)malloc(sizeof(Reserve));
            count += addReserve(r[index++]);
        }
        if(menu==1)
        {
            printCalendar(r,index);
        }
        if(menu==3)
        {
            searchStid(r,index);
        }
        if(menu==4)
        {
            searchNop(r,index);
        }
        if(menu==5)
        {

        }
        if(menu==6)
        {

        }
       if (menu == 7)
       {
		int no;
		no = chooseNo(r, index);
		if(no == 0) 
			printf("Update canceled.");
		else 
			updateReserve(r[no-1]);
       }
	if(menu == 8)
	{ 
		int no;
		no = chooseNo(r, index);
		if(no == 0) 
			printf("Cancellation Denied.");
		else 
			deleteReserve(no,r,&count);
       }

    return 0;
}
