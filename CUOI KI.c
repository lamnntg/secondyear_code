#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _thucdon{
    int stt;
    char name[255];
    int soluongton;
    double giatien;
} thucdon;

typedef struct request{
    thucdon data;
    int soluong;
    int ID;
    int order[30];
    long total;
    struct request *next;
} Request;

typedef struct _list{
    Request *head;
    Request *tail;
} list;

void initList(list *goimon){
    goimon->head = goimon->tail = NULL;
}

Request *makeNode(thucdon td){
    Request *p = (Request *)malloc(sizeof(Request));
    p->data.stt = td.stt;
    p->data.soluongton = td.soluongton;
    p->data.giatien = td.giatien;
    strcpy(p->data.name, td.name);
    p->next = NULL;
    return p;
}

void addTail(list *rq, Request *td){
    if(rq->head == NULL){
        rq->head = rq->tail = td;
        return;
    }else{
        td->next = rq->head;
        rq->head = td;
        return;
    }
}
int size;
////////////
void orderMon(list *rq, thucdon thucdon[]){
    Request td;
    printf("CHON SO LUONG MON\n");
    scanf("%d ", &td.soluong);
    printf("CHON MON CAN GOI (STT)\n");
    scanf("%d",&td.ID);


}

int readFile(thucdon thucdon[]){
    FILE *fin = fopen("thucdontheongay.txt", "r");
    fscanf(fin, "%d", &size);
    for(int i = 0; i < size; i++){
        fscanf(fin, "%d", &thucdon[i].stt);
        fscanf(fin, "%s", thucdon[i].name);
        fscanf(fin, "%d", &thucdon[i].soluongton);
        fscanf(fin, "%ld", &thucdon[i].giatien);
    }
    return size;
}

void inMenu(thucdon thucdon[]){
    printf("%10s %30s %30s %20s \n","ID","Ten mon","So luong ton","Gia tien");
    for(int i = 0; i < size; i++){
        printf("%10d %30s %30d %20ld\n", thucdon[i].stt, thucdon[i].name, thucdon[i].soluongton, thucdon[i].giatien);
    }
}


int main(){
    thucdon thucdon[8];

    readFile(thucdon);
     int select;
    do {
        printf("-----------------------------------\n");
        printf("|1: DANH SACH MON HOM NAY \n|2: NHAN ODER \n|3: THONG TIN TAT CA ODER\n|4: MON AN DUOC UA CHUONG NHAT\n|5: EXIT\n");
        printf("------------------------------------\n");
        printf("CHON CHUC NANG : ");
        scanf("%d", &select);
        switch(select){
            case 1: {
                printf("------------------------------------\n");
                printf("1: DANH SACH MON HOM NAY\n");
               inMenu(thucdon);
                break;
            }
            case 2: {
                printf("------------------------------------\n");
                printf("2: NHAN ODER\n");
                orderMon(thucdon,thucdon);

                break;
            }
            case 3: {
                printf("------------------------------------\n");
                printf("3: THONG TIN TAT CA ODER \n");

                break;
            }
            case 4: {
                printf("------------------------------------\n");
                printf("4:MON AN DUOC UA CHUONG NHAT \n");
                break;

            }
            case 5:
                {
                    return 0;}
            default : printf("CHON SAI CHUC NANG. HAY CHON LAI\n");
            break;
        }
    }
    while (select != 5);
    return 0;

}
