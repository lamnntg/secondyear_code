// Quan ly doi bong de k61
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
//------- xoa dau enter

void xoa_enter(char str[])
{
   if (str[strlen(str)-1]  == '\n'){
       str[strlen(str)-1]  ='\0';
   }
}

//-----------------------------------------------------

typedef struct {
    int id;
    char name[50];
    int poin;
    int banthang;
    int banthua;
    struct bongda *next;
}bongda;  // la mot node

typedef struct
{
    int x,y;
}capdau;
typedef struct list {
       char vong[10];
       int doi1,doi2;
       capdau tran[20];
       struct list*next;
}vongdau;


bongda*head= NULL;
bongda*list=NULL;
//khaibao lai
int team_n; // so team




//-------------------------------------------------------------
//tao node cho struct bong da

 bongda*makenode(bongda newdata)
   {
 bongda *p =(bongda *)malloc(sizeof(bongda)); // cap phat bo nho
      p->id=newdata.id;
      strcpy(p->name,newdata.name);
      p->banthang= newdata.banthang;
      p->banthua= newdata.banthua;
      p->poin=newdata.poin;
      p->next=NULL;
      return p;
    }

 //-------------------------------------------------------------
void addHead(bongda**head,bongda*q)
{
    if (*head==NULL){
         *head=q;
         }
    else
    {
        q->next=*head;
        *head =q;
    }
}
//----------------------------------------------------------------------

//tao list
vongdau*makeList(vongdau q)
{
    vongdau*p=(vongdau*)malloc(sizeof(vongdau));
    if(p=NULL)return NULL;
    strcpy(p->vong , q.vong);
    for(int i=0; i<team_n /2; i++)
    {
        p->tran[i].x= q.tran[i].x;
        p->tran[i].y= q.tran[i].y;
    }
    p->next=NULL;
    return p;
}

//------------------------------------------------------------
void addList(vongdau **list, vongdau *q){						// add tail
	if( *list == NULL){
		*list = q;
	} else {
		vongdau *x = *list;
		while(x->next != NULL) x = x->next;
		x->next = q;
	}
}
// doc file ------------------------------------------------------



int readFile()
{
     FILE *fin= fopen("bongda.txt","r");
     fscanf(fin,"%d",team_n);
    for(int i=1;i=team_n; i++)
    {
         bongda team;   // node ten team co kieu bong da
         fscanf(fin,"%d",team.id);
         fgets(team.name,MAX,fin);
         xoa_enter(team.name);
         team.banthang=0;
         team.banthua=0;
         team.poin=0;

        addHead(&head, makenode(team));
    }
    for(int i=1; i=team_n/2; i++)
    {
        vongdau vd;
        fgets(vd.vong,10,fin);
        xoa_enter(vd.vong);
        for(int j=1;j=team_n/2;i++){
        fscanf(fin,"%d\t%d",vd.doi1,vd.doi2);
        fscanf(fin,"%d-%d\n",&vd.tran[j].x,&vd.tran[j].y);
    }
    addList(&list,makeList(vd));
}
}

//--------------------------------------
//-chuyen tu ID sang NODE
bongda*convertID(int x)
{
    bongda*p=head;
    while (p!=NULL)
    {
        if(p->id==x)return p;
        else p=p->next;
    }
    return NULL;
}
// in file
//-------in thong tin
void inthontin()
{
    bongda*p=head;
    printf("%3s%30s%10s%15s%15s\n","Id", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
	while(p != NULL){
    printf("%3d%30s%10d%15d%15d\n", p->id, p->name, p->poin, p->banthang, p->banthua);
    p = p->next;
	}
}

void inlichdau()
{
    vongdau*p=list;
    while (p!=NULL)
    {
        printf("%s",p->vong);
        for(int i=0;i<team_n/2;i++)
        {
            bongda*team_A=convertID(p->tran[i].x);
            bongda*team_B=convertID(p->tran[i].y);
            printf("%s\t-\t%s",team_A->name,team_B->name);
        }
        p=p->next;
    }

}

//----------------------------------------------------


//---------------------------------------------------

int main() {

    int n;
    int select;

    do {
        printf("Truong trinh demo k61:\n-----------------\n");
        printf("1: IN THONG TIN \n2: IN THONG TIN LICH DAU \n3: CAP NHAT KET QUA\n4: THONG KE\n5: EXIT\n");
        printf("CHON CHUC NANG : ");
        scanf("%d", &select);
        switch(select){
            case 1: {
                printf("1: IN THONG TIN\n");
                inthontin();
                break;
            }
            case 2: {
                printf("2: IN THONG TIN LICH DAU\n");
                inlichdau();

                break;
            }
            case 3: {
                printf("3: CAP NHAT KET QUA\n");

                break;
            }
            case 4: {
                printf("4: THONG KE");
                break;

            }
            case 5: return 0;
            default : printf("CHON SAI CHUC NANG. HAY CHON LAI \n"); break;
        }
    }
    while (select != 5);
    return 0;
}
