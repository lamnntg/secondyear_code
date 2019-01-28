//Ho va ten: Nguyen Viet Manh   MSSV: 20176816  Lop: Viet Nhat C - K62
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _thucdon{
    int stt;
    char name[255];
    int soluongton;
    double giatien;
    struct _thucdon *mnext;
} thucdon;

typedef struct _list2{
    thucdon *dau;
    thucdon *cuoi;
} list2;

typedef struct request{
    int ID;
    int order[7];
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

void initList2(list2 *mon){
    mon->dau = mon->cuoi = NULL;
}

thucdon *makeMon(thucdon temp){
    thucdon *p = (thucdon *)malloc(sizeof(thucdon));
    p->stt = temp.stt;
    strcpy(p->name, temp.name);
    p->soluongton = temp.soluongton;
    p->giatien = temp.giatien;
    p->mnext = NULL;
    return p;
}

void addMon(list2 *mon, thucdon *temp){
    if(mon->dau == NULL){
        mon->dau = mon->cuoi = temp;
        return;
    }else{
        mon->cuoi->mnext = temp;
        mon->cuoi = temp;
        return;
    }
}

Request *makeNode(Request temp){
    Request *p = (Request *)malloc(sizeof(Request));
    p->ID = temp.ID;
    for(int i = 0; i < 6; i++){
        p->order[i] = temp.order[i];
    }
    p->total = temp.total;
    p->next = NULL;
    return p;
}

void addHead(list *rq, Request *temp){
    if(rq->head == NULL){
        rq->head = rq->tail = temp;
        return;
    }else{
        temp->next = rq->head;
        rq->head = temp;
        return;
    }
}

void orderMon(list *rq){
    Request temp;
    printf("Nhap so luong cac mon muon order:\n");
    printf("Com_thit_kho: ");
    scanf("%d", &temp.order[0]);
    printf("Com_thit_rang: ");
    scanf("%d", &temp.order[1]);
    printf("Com_ca_ran: ");
    scanf("%d", &temp.order[2]);
    printf("Com_trung_ran: ");
    scanf("%d", &temp.order[3]);
    printf("Com_ca_kho_to: ");
    scanf("%d", &temp.order[4]);
    printf("Com_suon_sot: ");
    scanf("%d", &temp.order[5]);

    addHead(rq, makeNode(temp));
}

thucdon *findFood(list2 mon, int id){
    for(thucdon *q = mon.dau; q; q = q->mnext){
        if(q->stt == id) return q;
    }
}

void printOrder(list rq, list2 *mon){
    int count = 0;
    thucdon *q;
    for(Request *p = rq.head; p; p = p->next){
        printf("Don hang so %d\n", ++count);
        printf("Mon da chon\t\tSo luong\tThanh tien\n");
        for(int i = 0; i < 7; i++){
            if(p->order[i] > 0){
                q = findFood(*mon, i+1);
                printf("%-10s %-5d %d\n", q->name, p->order[i], p->order[i]*q->giatien);
                q->soluongton = p->order[i];
            }
        }
    }
}

void Menu()
{

	printf("_________________Menu_______________\n");
	printf("|1Danh sach mon hom nay.         \n");
	printf("|2.Nhan order.                    \n" );
	printf("|3.Thong tin tat ca order.        \n");
	printf("|4.Mon ua chuong nhat.            \n");
    printf("|5.Thoat chuong trinh.            \n");


}

int readFile(list2 *mon){
    FILE *fin = fopen("thucdontheongay.txt", "r");
    int size;
    thucdon temp;
    fscanf(fin, "%d", &size);
    for(int i = 0; i < size; i++){
        fscanf(fin, "%d", &temp.stt);
        fscanf(fin, "%s", &temp.name);
        fscanf(fin, "%d", &temp.soluongton);
        fscanf(fin, "%ld", &temp.giatien);
        addMon(mon, makeMon(temp));
    }
    return size;
}

void printMenu(list2 mon){
    printf("ID\tTen mon\t\tSo luong ton\tGia tien\n");
    for(thucdon *p = mon.dau; p; p = p->mnext){
        printf("%-7d %-20s %-11d %ld\n", p->stt, p->name, p->soluongton, p->giatien);
    }
}

int main(){
    list2 mon;  initList2(&mon);
    list rq;    initList(&rq);
    int nmon = readFile(&mon);
    int chucnang;
    do{
	    Menu();
        do{
            printf("Nhap chuc nang ban muon: ");
	        scanf("%d", &chucnang);
        }while(chucnang < 1|| chucnang > 5);
	    switch(chucnang)
	    {
		    case 1:
                printMenu(mon);
		        break;
		    case 2:
                orderMon(&rq);
		        break;
		    case 3:
                printOrder(rq, &mon);
		        break;
		    case 4:
		        break;
            case 5:
                return 0;
        }
        system("pause");
    }while(1);
}
