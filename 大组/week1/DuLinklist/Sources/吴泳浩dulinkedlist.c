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
  //DuLNode* L = (DuLNode*)malloc(sizeof(DuLNode));ʦ�������ǲ��ǿ��Բ��÷����ڴ�ռ�
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
    q->prior = p->prior;//��q����p��ǰ��
    q->next = p;//��q��β������p��ǰ��
   // p->prior = q->next;���ﷸ�˺����ص�һ������������q->nextʵ����ָ�ľ���p
    p->prior = q;
    q->prior->next = q;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
      q->next = p->next;//��p��βָ����ָ��q����һ�����
      p->next = q;
      q->next->prior = q;
      q->prior = p;
}

Status DeleteList_DuL(DuLNode *p, ElemType *e);
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
  if (p->next)
      return ERROR;
  DuLNode *new = p->next;//�洢p�����һ�����ĵ�ַ
  p->next = p->next->next;//�Ͽ�����ĵ�һ�����
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