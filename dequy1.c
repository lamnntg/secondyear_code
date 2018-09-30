#include "stdio.h"
long m[100],n;
void khoitao()
{
    for(int i=0;i < 100; i++)
    {
        m[i]=0;     //gán để kiếm tra giá trị m[n] đc tính hay chưa 
    }

}
int f(int n){                      // KHỞI TẠO HÀM ĐỆ QUY f theo cú pháp 
    if(n <=1 ) m[n]=1 ;
    else
    {
        if (m[n]==0)      // nếu m[n] chưa đc tính thì chạy đệ quy 
        {
            m[n]=f(n-1)+f(n-2);
        }
    }
    return m[n];
}
    

int main(int argc, char const *argv[])
{
    khoitao();
    for(int n=0; n<100; n++)
    {
        printf("%d\n",f(n));
    }
    
}
