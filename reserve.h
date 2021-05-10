typedef struct Reserve{
    int nop; // 인원수
    char stid[10]; // 학번
    int date; // 날짜
    int month; // 달
    int inith; // 시작시간
    int endh; // 마치는 시간
}Reserve;
void printCalendar(Reserve *r[], int count);
void searchNop(Reserve *r[],int count);
void searchStid(Reserve *r[],int count);
void saveFile(Reserve *r[], int count);
int addReserve(Reserve *r);
void loadFile(Reserve *r[],int count);
void updateReserve(Reserve *r);
int chooseNo(Reserve *r[],int count);
int loadMenu();
void checkNoshow(Reserve *r[],int count);
void deleteReserve(int num,Reserve *r[],int* count);