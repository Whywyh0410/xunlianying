#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

typedef enum Status {
	ERROR,
	SUCCESS,
} Status;

Status InitList_DuL(DuLinkedList *L);
Status InitList_DuL(DuLinkedList *L)
{
  //DuLNode* L = (DuLNode*)malloc(sizeof(DuLNode));师兄这里是不是可以不用分配内存空间
  (*L)->data = 0;
  (*L)->next = NULL;
  (*L)->prior = NULL;

  return SUCCESS;

}

void DestroyList_DuL(DuLinkedList *L);
void DestroyList_DuL(DuLinkedList *L)
{
     DuLNode *pre,*temp;
     temp = (*L)->next; 
     while(temp!=NULL)
     {  
        pre = temp;
        free (pre);
        temp = temp->next;
     }

     free (L);

}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
    q->prior = p->prior;//把q接在p的前面
    q->next = p;//把q的尾部接在p的前面
   // p->prior = q->next;这里犯了很严重的一个错误，忘记了q->next实际上指的就是p
    p->prior = q;
    q->prior->next = q;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
      q->next = p->next;//把p的尾指针域指向q的下一个结点
      p->next = q;
      q->next->prior = q;
      q->prior = p;
}

Status DeleteList_DuL(DuLNode *p, ElemType *e);
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
  if (p->next)
      return ERROR;
  DuLNode *new = p->next;//存储p后面第一个结点的地址
  p->next = p->next->next;//断开后面的第一个结点
  p->next->prior = p;
  free (new);
  
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
    DuLNode *new = L->next;
    while(new)
    {
      new = new->next;
    }
}


#endif