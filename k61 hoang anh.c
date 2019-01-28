#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
int MAX_LEN=81;
void menu()
{
  printf("1.Thong tin\n2.Lich dau\n3.Ket qua\n4.Thong ke\n");
}

int main()
{
  FILE *fptr;
  char dump;
  char tmp[20][200];
  int N,n=0,i=0;
  char buff[MAX_LEN];
  int ok;
  fptr = fopen("bongda.txt","r");
  fgets(buff, MAX_LEN,fptr);
  sscanf(buff,"%d",&N);
  //printf("%d\n",N);
  int sotran = N/2;
  int sovong = N-1;
  int ketqua[2][sovong+1];
  int a,b;
  int dangdau;
  // printf("%d\n",sovong);
  elementtype team[N+1];
  rewind(fptr);
  fclose(fptr);
  char choice;
  for(i=1;i<sovong+1;++i)
    {
      ketqua[0][i]=-1;
      ketqua[1][i]=-1;
    }
  menu();
  do
    {
      printf("Lua chon?:");
      scanf(" %c",&choice);
      switch(choice)
        {
        case '\n':
          printf("Chon lai\n.");
          break;
        default:
          printf("Chon lai\n.");
          break;
        case '1':
          fptr = fopen("bongda.txt","r");
          while (fgets(buff, MAX_LEN,fptr) != NULL)
            {
              strcpy(tmp[n],buff);
              ++n;
            }
          fclose(fptr);
          for(i=1;i<N+1;++i)
            {
              team[i].grade = 0;
              team[i].win = 0;
              team[i].lose = 0;
              sscanf(tmp[i],"%d\t%[^\n]s",&team[i].id,team[i].name);
              insertAtHead(team[i]);
            }
          printf("Id\tTen doi bong\tDiem\tBan thang\tBan thua\n");
          traverseList();
          menu();
          break;
        case '2':
          printf("Lich thi dau:\n");
          for(i=N+1; i < n; ++i)
            {
              if(tmp[i][0]=='V')
                printf("%s\n",tmp[i]);
              else
                {
                  sscanf(tmp[i],"%d\t%d",&a,&b);
                  printf("%s - %s\n",team[a].name,team[b].name);
                }
            }
          menu();
          break;
        case '3':
          for(i=N+1;i<n;++i)
            {
              if(tmp[i][0]=='V')
                {
                  dangdau=tmp[i][5]-'\0';
                  printf("Cap nhat ket qua Vong %d:\n",dangdau);
                  printf("Vong %d\n",ok);
                  sscanf(tmp[i],"%d\t%d",&a,&b);
                  printf("%s - %s:",team[a].name,team[b].name);
                  scanf(" %[^\n]s",buff);
                  sscanf(buff,"%d%c%d",&ketqua[0][dangdau],&dump,&ketqua[1][dangdau]);
                  printf("%d %d\n",ketqua[0][dangdau],ketqua[1][dangdau]);
                  team[a].win = team[a].win+ketqua[0][dangdau];
                  team[a].lose += ketqua[1][dangdau];
                  team[b].win += ketqua[1][dangdau];
                  team[b].lose += ketqua[0][dangdau];
                  if(ketqua[0][dangdau]<ketqua[1][dangdau])
                    team[b].grade +=3;
                  else if(ketqua[0][dangdau]>ketqua[1][dangdau])
                    team[a].grade +=3;
                  else
                    {
                      team[a].grade+=1;
                      team[b].grade+=1;
                    }
                }
            }
          printf("Id\tTen doi bong\tDiem\tBan thang\tBan thua\n");
          for(i=1;i < N+1;++i)
            {
              printf("%d\t%s\t%d\t%d\t%d\n",team[i].id,team[i].name,team[i].grade,team[i].win,team[i].lose);
            }
          break;
        while(choice != '5');
        }
}
