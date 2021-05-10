#include <stdio.h>
#include <string.h>
#include "reserve.h"

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
    }
    printf("|");
    
}
void searchNop(Reserve *r[],int count) // 예약한 사람의 수를 입력받아 리스트를 뽑는 함수
{
}
void searchStid(Reserve *r[],int count) // 학번을 검색해서 그 사람의 예약 이력 확인
{

}
void saveFile(Reserve *r[], int count) // 파일 저장 함수
{

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
void loadFile(Reserve *r[],int count) // 파일 불러오기 함수
{
	
}
void updateReserve(Reserve *r) // 업데이트 함수
{

	printf("Insert student id: ");
	scanf("%s", r->stid);
	printf("Insert number of players: ");
	scanf("%d", &r->nop);
}

void deleteReserve(int num, Reserve *r[],int* count)
{
    int deleteok;
    printf("Are you sure you want to delete? (1: delete) ");
    scanf("%d",&deleteok);
    if(deleteok == 1)
    {
        if(r[num-1]) free(r[num-1]);
        r[num] = NULL;
        (*count)--;
        printf("==> DELETED\n");

    }
}

int chooseNo(Reserve *r[],int count) // 
{
	int no;
	// 예약 현황 확인
	printf("Select Number(Type 0 to cancel):  ");
	scanf("%d", &no);
	return no;

}
int loadMenu()
{
    int menu;
    printf("---------------------------------\n");
    printf("| Hiddink Field Reservation Service |\n");
    printf("---------------------------------\n");
    printf("1. View Calendar");
    printf("2. Add Reservation\n");
    printf("3. Search Student ID\n");
    printf("4. Search Number of People\n");
    printf("5. Check No Show\n");
    printf("6. Save File\n");
    printf("7. Cancel Reservation\n");
    printf("8. Change Reservation\n");
    printf("0. Exit\n");
    scanf("%d",&menu);
    return menu;
}
void checkNoshow(Reserve *r[],int count)
{



}
