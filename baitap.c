#include<stdio.h>
#include <string.h>
enum {SUCCESS, FAIL, MAX_LEN = 80};
int main(int argc, char const *argv[])
{
char filename[]="lab1.txt";
int reval = SUCCESS;
int n;
char c[100];
FILE *f1;
f1 = fopen(filename,"w+");
if (f1=NULL) {
   printf("Can not open file\n");
   reval = FAIL;
}
printf("Chon vi tri muon sua \n");
scanf("%d",&n);// tính từ kí tự từ đầu 
fseek(f1,n,SEEK_SET);
printf("chon noi dung muon nhap\n");
while(getchar()!='\n');
gets(c);
fputs(c,f1);

fclose(f1);

    return reval;
}
