#include <stdio.h>
#include <string.h>
#include "reserve.h"
#include <stdlib.h>

void printCalendar(Reserve *r[], int count) // Parameter로 Reserve *r[]을 받긴 했는데 이걸 어디에서 사용하면 될지 생각
{
    int month;
    printf("Please input month to view ");
    scanf("%d",&month);
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
    printf("|");
    }
    else if(month == 2)
    {
        printf("--------------%d--------------\n",month);
        printf("|SUN|MON|TUE|WED|THU|FRI|SAT|\n");
        for(int i=0;i<28;i++)
            dates[i]=i+1;
        for(int i=0;i<28;i++){
            if(i!=0 && i%7==0)
                printf("|\n");
            printf("| %2d",dates[i]);
        }
    printf("|");
    }
    else
    {
        printf("--------------%d--------------\n",month);
        printf("|SUN|MON|TUE|WED|THU|FRI|SAT|\n");
        for(int i=0;i<30;i++)
            dates[i]=i+1;
        for(int i=0;i<30;i++){
            if(i!=0 && i%7==0)
                printf("|\n");
            printf("| %2d",dates[i]);
        }
    printf("|");
    }
    printf("\n");
    
}
void searchNop(Reserve *r[],int count) // 예약한 사람의 수를 입력받아 리스트를 뽑는 함수
{
    chooseNo(r,count);
}
void searchStid(Reserve *r[],int count) // 학번을 검색해서 그 사람의 예약 이력 확인
{
    chooseNo(r,count);
}
void saveFile(Reserve *r[], int count) // 파일 저장 함수
{
	FILE *fp;
	fp = fopen("reserve.txt", "wt");

	for(int i = 0; i < count; i++)
	{
		if(r[i] == NULL)
			continue;
		fprintf(fp, "%s %d %d %d %d %d\n", r[i]->stid, r[i]->nop, r[i]->month, r[i]->date, r[i]->inith, r[i]->endh);
	}

	fclose(fp);
	printf("Reservation saved to file\n");
}

int addReserve(Reserve *r) // 예약자 생성
{
    printf("Insert student id: ");
    scanf("%s",r->stid);
    printf("Insert number of players: ");
    scanf("%d",&r->nop);
    printf("Insert month of reservation: ");
    scanf("%d", &r->month);
    printf("Insert date of reservation (Month: %d) : ",r->month);
    scanf("%d",&r->date);
    printf("Insert start time and end time of reservation (Ex: 14-16): ");
    scanf("%d-%d",&r->inith,&r->endh);
    return 1;
}
int  loadFile(Reserve *r[]) // 파일 불러오기 함수
{
	int cnt = 0;
	int i = 0;
	FILE *fp;
	fp = fopen("reserve.txt", "rt");
	for(; i < 100; i++)
	{
		fscanf(fp, "%s", r[i]->stid);
		if(feof(fp))
			break;
		fscanf(fp, "%d", &r[i]->nop);
		fscanf(fp, "%d", &r[i]->month);
		fscanf(fp, "%d", &r[i]->date);
		fscanf(fp, "%d", &r[i]->inith);
		fscanf(fp, "%d", &r[i]->endh);
	}
	fclose(fp);
	printf("=> File loaded\n");
	return i; // return count (number of reservation)
}
void updateReserve(Reserve *r) // 업데이트 함수
{

	printf("Insert student id: ");
	scanf("%s", r->stid);
	printf("Insert number of players: ");
	scanf("%d", &r->nop);
	printf("Insert month of reservation:");
	scanf("%d", &r->month);
	printf("Insert date of reservation (Month: %d)", r->month);
	scanf("%d", &r->date);
	printf("Insert start time and end time of reservation (Ex: 14-16): ");
	scanf("%d-%d", &r->inith, &r->endh);

}

void deleteReserve(int num, Reserve *r[],int* count)
{
    int deleteok;
    printf("Are you sure you want to delete? (1: delete) ");
    scanf("%d",&deleteok);
    if(deleteok == 1)
    {
        if(r[num-1]) free(r[num-1]);
        r[num-1] = NULL;
        (*count)--;
        printf("==> DELETED\n");

    }
}

int chooseNo(Reserve *r[],int count) // 
{
    listReserve(r,count);
	int no;
	// 예약 현황 확인
	printf("Select Number(Type 0 to go back):  ");
	scanf("%d", &no);
	return no;

}
int loadMenu()
{
    int menu;
    printf("---------------------------------\n");
    printf("| Hiddink Field Reservation Service |\n");
    printf("---------------------------------\n");
    printf("1. View Calendar\n");
    printf("2. Add Reservation\n");
    printf("3. Search Student ID\n");
    printf("4. Search Number of People\n");
    printf("5. Check No Show\n");
    printf("6. Save File\n");
    printf("7. Cancel Reservation\n");
    printf("8. Change Reservation\n");
    printf("0. Exit\n");
    printf("CHOOSE MENU: ");
    scanf("%d",&menu);
    return menu;
}
void checkNoshow(Reserve *r[],int count)
{



}
void readReserve(Reserve r)
{
    printf("%s %d %d %d %d-%d\n",r.stid,r.nop,r.month,r.date,r.inith,r.endh);
}
void listReserve(Reserve *r[],int count)
{
 printf("\nNo studentID noPlayers month day startAt endAt\n");
 printf("=============================================\n");
 for(int i = 0; i < count; i++)
 {
	 if(r[i] == NULL)
		 continue;
	 printf("%-2d", i+1);
	 readReserve(*r[i]);
 }
 printf("\n");

 
}
