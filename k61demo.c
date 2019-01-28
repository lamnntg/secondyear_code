// Nguyen Tung Lam
// MSSV 20176800
// Viet Nhat C K62
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct _thucdon {
    int stt;
    char name[50];
    int soluongton;
    double giatien;

    struct thucdon *next;
}thucdon;  // la mot node

typedef struct request{
    int ID;
    int order[30];
    long total;
    struct request *next;
} Request;

typedef struct _list{
    Request *head;
    Request *tail;
} list;
void khoitao(list*quanly){
quanly->head=quanly->tail= NULL;
}
// khai bao
int mon_n;
//-tao node
Request *makenode(Request  newdata)
   {
 Request  *p =(Request  *)malloc(sizeof(Request )); // cap phat bo nho
      p->stt=newdata.stt;
      strcpy(p->name,newdata.name);
      p->soluongton= newdata.soluongton;
      p->giatien=newdata.giatien;
      p->next=NULL;
      return p;
    }

    // add node
    void addtail(list *quanly, Request *td){
    if(quanly->head == NULL){
        quanly->head = quanly->tail = td;
        return;
    }else{
            td->next = quanly->head;
        quanly->head = td;
        return;
    }
}

    // docfile
   int readfile(list*quanly)
    {
        thucdon td;
        FILE *fin = fopen("thucdontheongay.txt","r");

            fscanf(fin,"%d",mon_n);

        for(int i =1; i =mon_n;i++)
        {
            fscanf(fin,"%d",&td.stt);
            fgets(td.name,50,fin);
            fscanf(fin,"%d",&td.soluongton);
            fscanf(fin,"%ld",&td.giatien);
            addtail(quanly,makenode(td));
        }
    }

// in thuc don
void inthucdon(list quanly){
   printf("%3s%35s%20s%15s\n","ID", "Ten Mon", "So Luong Ton",  "Gia Tien");
    for(thucdon*p = quanly.head; p; p = p->next){
        printf("%3d%35s%20d%15ld\n", p->stt, p->name, p->soluongton, p->giatien);
    }
}


int main() {

    list quanly;
    khoitao(&quanly);
    //readfile(&quanly);



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
                inthucdon(quanly);
                break;
            }
            case 2: {
                printf("------------------------------------\n");
                printf("2: NHAN ODER\n");


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
            case 5: return 0;
            default : printf("CHON SAI CHUC NANG. HAY CHON LAI\n");
            break;
        }
    }
    while (select != 5);
    return 0;
}
