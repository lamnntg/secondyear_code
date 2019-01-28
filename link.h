#include <stdio.h>
#include <stdlib.h>

//Data type
typedef struct
{
  int id;
  char name[30];
  int grade;
  int win;
  int lose;
} elementtype;

//list of data type, by nodes
struct list{
  elementtype elementtype;
  struct list* next;
};
typedef struct list node;

node *root, *cur, *prev;
//Read
/* elementtype readData() */
/* { */
/* 	elementtype res; */
/* 	printf("Name:");scanf(" %[^\n]s",res.name); */
/*     printf("Memory:");scanf("%d",&res.memory); */
/*     printf("Size:");scanf("%f",&res.size); */
/*     printf("Money:");scanf("%ld",&res.money); */
/*   return res; */
/* } */
//Write
void printData(elementtype res)
{
  printf("%d\t%s\t%d\t%d\t%d\n",res.id,res.name,res.grade,res.win,res.lose);
}

//New node generic
node* makeNewNode(elementtype e)
{
	node *new = (node*)malloc(sizeof(node));
	new->elementtype = e;
	new->next =NULL;
	return new;
}
//Insert at head
void insertAtHead(elementtype e)
{
	node* new = makeNewNode(e);
	new->next = root;
	root = new;
	cur = root;
}
//Insert after current generic
void insertAfterCurrent(elementtype e)
 {
   if(cur == NULL) return;
   node* new = makeNewNode(e);
   if ( root == NULL )
     {
       /* if there is no element */
       root = new;
       cur = root;
     }
   else
     {
       new->next=cur->next;
       cur->next = new;
       // prev=cur;
       cur = cur->next;
     }
 }
//Insert before current generic
void insertBeforeCurrent(elementtype e)
{
  if(cur == NULL) return;
  node* new = makeNewNode(e);
  if ( root == NULL )
    {
      /* if there is no element */
      root = new;
      cur = root;
      prev = NULL;
	}
  else
    {
      new->next=cur;
      /* if cur pointed to first element */
      if (cur==root)
        {
          root = new; /* nut moi them vao tro thanh dau danh sach */
		}
      else prev->next = new;
      cur = new;
	}
}
//Traverse
void traverseList()
{
  node* p;
  for (p = root; p != NULL; p = p->next )
    {
      printData(p->elementtype);
    }
}
//Move <n> position
void move(int n, node* p)
{
  int i=0;
  while(i < n && ((p->next)!=NULL))
    {
      p=p->next;
    }

}
//Reverse
node* list_reverse (node* root)
{
	node *cur, *prev;
	cur = prev = NULL;
	while (root != NULL)
      {
		cur = root;
		root = root->next;
		cur->next = prev;
		prev = cur;
      }
	return prev;
}
//Delete first element
void deleteFirstElement()
{
  node* del = root;
  root = del->next;
  free(del);
  cur = root; /* prev = NULL; */
}
// Delete current element
void deleteCurrentElement()
{
  if (cur==NULL) return;
  if (cur==root) deleteFirstElement();
  else
    {
      prev->next = cur->next;
      free(cur);
      cur = prev->next;
    }
}
//Free a líst (all nodes of a list)
void freelist()
{
  node* to_free = root;
  while (to_free != NULL)
    {
      root = root->next;
      free(to_free);
      to_free = root;
    }
}
node* insertAtPosition(elementtype e, int n)
{
  node *new, *p = root;
  int i=0;
  new = makeNewNode(e);
  if(n == 0 || root == NULL)
    {
      new->next = root; // Tro den phan tu root dang tro
      root = new;
      return new;
    }
  else
    {
      while(i < n && (p->next != NULL))
        {
          prev=p;
          p = p->next;
          ++i;
        }
      new->next = prev->next; // Phan tu chen vao dan toi phan tu 'le ra' tiep theo
      prev->next = new; // Chen vao vi tri can chen
      cur = new; // ??
      return new;
    }
}
node* deleteAtPosition(int n)
{
  node *del, *p=root;
  int i = 0;
  if(n == 0 || root == NULL)
    {
      deleteFirstElement();
      return root;
    }
  else
    {
      while(i < n && (p->next != NULL))
        {
          prev=p;
          p = p->next;
        }
      prev->next = p->next; // Giu list khong bi ngat quang
      free(p); // Xoa vi tri can xoa
      cur = root; // ??
      return root;
    }
}
