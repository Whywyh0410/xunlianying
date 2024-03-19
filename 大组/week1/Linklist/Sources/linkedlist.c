#include <stdio.h>
#include <stdlib.h>
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#define OVERFLOW -1

typedef int ElemType;//����һ��int����

typedef enum Status {
	ERROR,
	SUCCESS
} Status;//����һ��ö������status����ʱerror=0��success=1

typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;//����ָ��lnode������͵�ָ��;

Status InitList(LinkedList *L);
Status InitList(LinkedList *L)//��ʼ��������
{
   // LNode* L=(LNode*)malloc(sizeof(LNode));
    (*L)->data = 0;//����һ������ָ��,ע�������и����ȼ���֮ǰû��ע�⵽�Ƕ���ָ�룬��������ʦ�ַ����Ƕ���ָ������*���ǲ��У�û��ע�⵽���ȼ�������
    (*L)->next = NULL;

    return SUCCESS;
}

void DestroyList(LinkedList *L);
void DestroyList(LinkedList *L)
{
     LNode* p;
     while(*L!=NULL)//�ж�L�Ƿ�������ȫ
     {
       p=*L;
       *L=(*L)->next;
       free (p);
     }
}

Status InsertList(LNode *p, LNode *q);
Status InsertList(LNode *p, LNode *q)
{   
    if(p==NULL)
        return ERROR;//�ж�p�Ƿ��ǿսڵ�
    
    q->next=p->next;//�Ȱ�p��ָ����洢��q��ָ��������
    p->next=q;//��q���ӵ�p֮��
   
}

Status DeleteList(LNode *p, ElemType *e);
Status DeleteList(LNode *p, ElemType *e)
{
        LNode *q=p->next;//��q�ڵ�洢p��ĵ�һ���ڵ�
       // p->next=e;��ֵ��e,����warning��ŷ����������ת����ʱ���ǲ�ͬ����
        p->data = (*e);
        p->next=q->next;//�Ͽ�q�ڵ�
        free(q);//�ͷ�q�ڵ�


}

void TraverseList(LinkedList L, void (*visit)(ElemType e));
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
     while(L->next!=NULL){
          printf("%d",L->data);
          L=L->next;
     }
        printf("%d",L->next);//��������
}

Status SearchList(LinkedList L, ElemType e);
Status SearchList(LinkedList L, ElemType e)
{
       LNode *p=L->next;//�ӵ�һ����㿪ʼ����
       while(p!=NULL&& p->data!=e){
            p=p->next;//Ѱ��eֵ
       }
       return SUCCESS;
}

Status ReverseList(LinkedList *L);
Status ReverseList(LinkedList *L)
{
       
       LNode *beg,*end;;
       beg=(*L)->next;//ָ���һ�����
       end=beg->next;//ʼ�ձ�����beg���֮��
       while(beg->next!=NULL)
       {
          beg->next=end->next;//begָ��end����Ľ��
          end->next=(*L)->next;//��endָ��beg���
          (*L)->next=end;//��end������ͷ����ĵ�һ�����
          end=beg->next;//��end���ʼ��ָ��beg��ĵ�һ�����,��beg�Ѿ�ָ��β�ڵ�ʱ����ʱΪNULL
          
       }

}

Status IsLoopList(LinkedList L);
Status IsLoopList(LinkedList L)
{     //����ָ�뷨
      LNode *fast = L;
      LNode *slow = L;

      while(fast&&slow)
      {
          if(fast->next&&fast->next->next)
             fast = fast->next->next;
          else
             break;
          if(slow->next)
             slow = slow->next;
          else
             break;
          if (fast==slow)

             return SUCCESS;
      }

      return 0;

}

LNode* ReverseEvenList(LinkedList *L);
LNode* ReverseEvenList(LinkedList *L)
{
     LNode *beg,*end,*front;//�洢begǰһ�����
     //front = L;����Ҳ��warning����������û��ע�⵽�����Ǹ�����ָ��
     front = (*L);
     beg = (*L)->next;
     end = beg->next;//��ʼ���������
     while(beg->next)//end,���ﲻֱ��Ϊ��ָ��,����end��ԭ���Ƿ�ת��ʱ���Ϊ����
     {
      if(beg->next->data%2==0)//��end����������ż��
         { 
           end = beg->next;
           beg = end->next;//�Ͽ�end������
           front->next = end;//��end����beg��ǰ��
           end->next = beg;//����beg
           
           
         }

      beg = beg->next;
      front = front->next;
      
      //return L;warning�������Ƿ��ص����ͺͺ������Ͳ�ͬ�����ص���һ������ָ��
      return (*L);
     }
}

LNode* FindMidNode(LinkedList *L);
LNode* FindMidNode(LinkedList *L)
{
   //���ʼ���뷨�Ƕ���һ��int���͵�һά���飬��ʼ��Ϊ0��Ȼ�����ű�������ÿһ�μ�1������ٱ���һ�����������˲�֪����ô�������Ĵ�С
   //���淢�ֿ����ÿ���ָ���㷨
   
   LNode *fast,*slow;
   fast = (*L)->next;
   slow = (*L)->next;
   while (fast!=NULL&&fast->next!=NULL)
   {
        fast = fast->next->next;
        slow = slow->next;

   }

   return slow;

}
#endif