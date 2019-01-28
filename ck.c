#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define str_del_newline(str) ( (str)[strlen(str) - 1] == '\n') ? (str)[strlen(str) - 1] = '\0' : 0;

void del_newline(char str[]){
	if(str[strlen(str) - 1] == '\n'){
		str[strlen(str) - 1] = '\0';
	}
}
typedef struct node {
	int id;
	char name[30];
	int win, lose, point;
	struct node *next;
} NODE;

typedef struct {
	int x, y;
} couple;

typedef struct list {
	char vong[6];
	couple match[20];
	struct list *next;
} LIST;

NODE *head = NULL;
NODE *list = NULL;
int n_team;

void showMenu();
void readFile();
void chooseFunc();
void showInfor();
NODE *makeNode();
LIST *makeList();
void addHead();
void addList();
void showTimetable();
NODE *convertIdToNode();
void updateInfor();

int main(int argc, char const *argv[])
{
	readFile(&head);
	chooseFunc();
	return 0;
}
void showMenu(){
	printf("=========================================\n");
	printf("=\t       MENU FUNCTION \t\t=\n");
	printf("=\t 1. In thong tin cac doi bong \t=\n");
	printf("=\t 2. In thong tin lich thi dau \t=\n");
	printf("=\t 3. Cap nhat ket qua \t\t=\n");
	printf("=\t 4. Thong ke \t\t\t=\n");
	printf("=========================================\n");
	printf("Chon chuc nang ban muon thuc hien: ");
}
NODE *makeNode(NODE a){
	NODE *p = (NODE *)malloc(sizeof(NODE));
	p->id = a.id;
	strcpy(p->name, a.name);
	p->win = a.win;
	p->lose = a.lose;
	p->point = a.point;
	p->next = NULL;
	return p;
}
void chooseFunc(){
	char y_n = 'n';
	int choose;
	do {
		showMenu();
		scanf("%d", &choose);
		switch(choose){
			case 1 :
				showInfor();
				break;
			case 2 :
				showTimetable();
				break;
			case 3 :
				updateInfor();
				break;
			case 4 :

				break;
			default : printf("Lua chon cua ban chua phu hop !!!\n");
		}
		printf("Ban co muon tiep tuc chuong trinh ? [y/n] : ");
		fflush(stdin);
		y_n = getchar();
	} while (y_n == 'y' || y_n == 'Y');
}
void addHead(NODE **head1, NODE *q){				// add head
	if( *head1 == NULL) {
		*head1 = q;
	} else {
		q->next = *head1;
		*head1 = q;
	}
}
LIST *makeList(LIST q){
	LIST *p = (LIST *) malloc(sizeof(LIST));
	if(p == NULL) return NULL;
	strcpy(p->vong, q.vong);
	for(int i = 0; i < n_team / 2; i++){
		p->match[i].x = q.match[i].x;
		p->match[i].y = q.match[i].y;
	}
	p->next = NULL;
	return p;
}
void addList(LIST **list, LIST *q){						// add tail
	if( *list == NULL){
		*list = q;
	} else {
		LIST *x = *list;
		while(x->next != NULL) x = x->next;
		x->next = q;
	}
}
void readFile(){
	FILE *fi = fopen("input.txt", "r");
	if(fi != NULL){
		fscanf(fi, "%d", &n_team);
		for(int i = 0; i < n_team; i++){
			NODE p;
			fscanf(fi,"%d", &p.id);
			fgets(p.name, 30, fi);
			str_del_newline(p.name);
			p.win = 0;
			p.lose = 0;
			p.point = 0;
			addHead(&head, makeNode(p));
		}
		for(int i = 0; i < n_team - 1; i++){
			LIST p;
			fgets(p.vong, 10, fi);
			str_del_newline(p.vong);
			for(int j = 0; j < n_team / 2; j++){
				fscanf(fi, "%d-%d\n", &p.match[j].x, &p.match[j].y);
			}
			addList(&list, makeList(p));
		}
	}
}
NODE *convertIdToNode(int x){
	NODE *p = head;
	while(p != NULL){
		if(p->id == x) return p;
		else p = p->next;
	}
	return NULL;
}
void showTimetable(){
	LIST *p = list;
	while(p != NULL){
		printf("%s\n", p->vong);								// In vong dau thu may ra
		for(int i = 0; i < n_team / 2; i++){
			NODE *team_A = convertIdToNode(p->match[i].x);
			NODE *team_B = convertIdToNode(p->match[i].y);
			printf("%s\t-\t%s\n", team_A->name, team_B->name);
		}
		p = p->next;
	}
}

void showInfor(){
	NODE *p = head;
	printf("%3s%30s%10s%15s%15s\n","Id", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
	while(p != NULL){
		printf("%3d%30s%10d%15d%15d\n", p->id, p->name, p->point, p->win, p->lose);
		p = p->next;
	}
}
void updateInfor(){
	LIST *p = list;
	while(p != NULL){
		printf("Cap nhat ket qua vong dau: \n");
		printf("%s\n", p->vong);
		for(int i = 0; i < n_team / 2; i++){
			NODE *team_A = convertIdToNode(p->match[i].x);
			NODE *team_B = convertIdToNode(p->match[i].y);
			printf("%s\t-\t%s: ", team_A->name, team_B->name);
			int a, b;
			scanf("%d%d", &a, &b);
			team_A->win += a; team_A->lose += b;
			team_B->win += b; team_B->lose += a;
			if(a == b) {
				team_A->point += 1;
				team_B->point += 1;
			} else if ( a > b) {
				team_A->point += 3;
			} else {
				team_B->point += 3;
			}
		}
		showInfor(head);
		p = p->next;
	}
}
void delNode(NODE **head, NODE *x){
	if(*head != NULL){
		NODE *lam = *head;
		if(*head == x){
			*head = (*head)->next;
			free(lam);
		} else {
			while(lam->next != x) lam = lam->next;
			lam->next = lam->next->next;
			free(x);
		}
	}
}
int findLoseTeam(NODE *head){
	int min_point = head->point;
	int min_id = head->id;
	NODE *k = head->next;
	while(k != NULL){
		if(k->point < min_point){
			min_point = k->point;
			min_id = k->id;
		}
	}
	return min_id;
}
