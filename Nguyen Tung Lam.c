#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Menu()
{
	printf("-----------MENU-------------\n");
	printf("1.Danh sach mon an hom nay.\n");
	printf("2.Nhan order.\n" );
	printf("3.Thong tin order.\n");
	printf("4.Mon an ua chuom nhat.\n");
    printf("5.Exit.\n");
    printf("----------------------------\n");
}
typedef struct thucdon
{
    int id;
    char tenmon[255];
    int soluongton;
    int giatien;
}thucdon;
thucdon A[10];
thucdon C[10];
void printlist(int n)
{
    printf("id\t\tTen mon\t\tSo luong mon\t\tGiatien\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d\t\t%s\t\t%d\t\t%d\n",A[i].id,A[i].tenmon,A[i].soluongton,A[i].giatien);

    }
}
void Insert(int k,int x,char y[255],int z,double t)
{
    A[k].id=x;
    strcpy(A[k].tenmon,y);
    A[k].soluongton=z;
    A[k].giatien=t;
    C[k].id=x;
    strcpy(C[k].tenmon,y);
    C[k].soluongton=z;
    C[k].giatien=t;
}
/*int docfile()
{
    FILE*fi;
    int n,x,z,t,k=1;

    //double t;
    char y[255];
    fi=fopen("thucdontheongay.txt","r");
    fscanf(fi,"%d",&n);
    printf("%d\n",n );
    for(int i=1;i<=n;i++)
    {
        fscanf(fi,"%d%s%d%d",&x,y,&z,&t);
        Insert(k,x,y,z,t);
        k=k+1;

    }
    fclose(fi);
}*/
int kiemtra(int x,int y)
{
    if (A[x].soluongton>=y)
    {
        A[x].soluongton=A[x].soluongton-y;
        return 1;
    }
    else
        return 0;
}
void donhang(int k,int B[10],int n)
{
    printf("don hang thu %d:\n",k);
            printf("Mon da chon \t\t So luong\t\t Thanh tien\n");
    for (int i=1;i<=n;i++)
        if(B[i]!=0)
        {

            printf("%s\t\t%d\t\t%d\n",A[i].tenmon,B[i],B[i]*A[i].giatien );
        }
}
int order(int n)
{
    int B[10],tong;
    for(int i=1;i<=n;i++)
    {
        int q;
        printf("%s",A[i].tenmon);
        scanf("%d",&B[i]);
        if(B[i]<0||kiemtra(i,B[i])==0)
        {
            printf("moi nhap lai so luong mon an:");
            scanf("%d",&B[i]);
        }
    }
    for(int i=1;i<=n;i++)
        tong=tong+B[i]*A[i].giatien;
    printf("tong tien phai tra:%d\n",tong);

}
int monanuathichnhat(int n)
{
    int max=0,maxi;

    for(int i=1;i<=n;i++)
        if(C[i].soluongton-A[i].soluongton>max)
        {
            max=C[i].soluongton-A[i].soluongton;
            maxi=i;
        }
        printf("mon duoc uu thich nhat la:%s so luong goi:%d\n",A[maxi].tenmon,max);


}
int main(int argc, char const *argv[])
{
    FILE*fi;
    int n,x,z,t,k=1;
    int q;
    //double t;
    char y[255];
    fi=fopen("thucdontheongay.txt","r");
    fscanf(fi,"%d",&n);
    printf("%d\n",n );
    for(int i=1;i<=n;i++)
    {
        fscanf(fi,"%d%s%d%d",&x,y,&z,&t);
        Insert(k,x,y,z,t);
        k=k+1;

    }
    fclose(fi);
	int control;
	do{
        Menu();
        do{
            printf("Nhap chuc nang ban muon:");
            scanf("%d", &control);
        }while(control < 0 || control > 6);
        switch(control)
        {
            case 1:
            printlist(n);
            break;
            case 2:
            int B[10],tong;
            tong=0;
            for(int i=1;i<=n;i++)
           {

        printf("%s",A[i].tenmon);
        scanf("%d",&B[i]);
        if(B[i]<0||kiemtra(i,B[i])==0)
        {
            printf("moi nhap lai so luong mon an:");
            scanf("%d",&B[i]);
        }
    }
    for(int i=1;i<=n;i++)
        tong=tong+B[i]*A[i].giatien;
    printf("tong tien phai tra:%d\n",tong);
             q=q+1;

            //order(n);
            break;
            case 3:
            donhang(q,B,n);
            break;
            case 4:
            monanuathichnhat(n);
            break;
            case 5:
            return 0;
        }
    }while(1);
}
