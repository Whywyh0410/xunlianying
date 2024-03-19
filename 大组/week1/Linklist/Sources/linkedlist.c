#include <stdio.h>
#include <stdlib.h>
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#define OVERFLOW -1

typedef int ElemType;//定义一个int类型

typedef enum Status {
	ERROR,
	SUCCESS
} Status;//定义一个枚举类型status，此时error=0，success=1

typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;//定义指向lnode这个类型的指针;

Status InitList(LinkedList *L);
Status InitList(LinkedList *L)//初始化空链表
{
   // LNode* L=(LNode*)malloc(sizeof(LNode));
    (*L)->data = 0;//它是一个二级指针,注意这里有个优先级，之前没有注意到是二级指针，后面问了师兄发现是二级指针后加了*还是不行，没有注意到优先级的问题
    (*L)->next = NULL;

    return SUCCESS;
}

void DestroyList(LinkedList *L);
void DestroyList(LinkedList *L)
{
     LNode* p;
     while(*L!=NULL)//判断L是否被销毁完全
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
        return ERROR;//判断p是否是空节点
    
    q->next=p->next;//先把p的指针域存储到q的指针域里面
    p->next=q;//把q连接到p之后
   
}

Status DeleteList(LNode *p, ElemType *e);
Status DeleteList(LNode *p, ElemType *e)
{
        LNode *q=p->next;//用q节点存储p后的第一个节点
       // p->next=e;赋值给e,看到warning后才发现这个错误，转换的时候是不同类型
        p->data = (*e);
        p->next=q->next;//断开q节点
        free(q);//释放q节点


}

void TraverseList(LinkedList L, void (*visit)(ElemType e));
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
     while(L->next!=NULL){
          printf("%d",L->data);
          L=L->next;
     }
        printf("%d",L->next);//遍历链表
}

Status SearchList(LinkedList L, ElemType e);
Status SearchList(LinkedList L, ElemType e)
{
       LNode *p=L->next;//从第一个结点开始查找
       while(p!=NULL&& p->data!=e){
            p=p->next;//寻找e值
       }
       return SUCCESS;
}

Status ReverseList(LinkedList *L);
Status ReverseList(LinkedList *L)
{
       
       LNode *beg,*end;;
       beg=(*L)->next;//指向第一个结点
       end=beg->next;//始终保持在beg结点之后
       while(beg->next!=NULL)
       {
          beg->next=end->next;//beg指向end后面的结点
          end->next=(*L)->next;//把end指向beg结点
          (*L)->next=end;//把end结点接上头结点后的第一个结点
          end=beg->next;//让end结点始终指向beg后的第一个结点,当beg已经指向尾节点时，此时为NULL
          
       }

}

Status IsLoopList(LinkedList L);
Status IsLoopList(LinkedList L)
{     //快慢指针法
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
     LNode *beg,*end,*front;//存储beg前一个结点
     //front = L;这里也是warning，问题在于没有注意到这里是个二级指针
     front = (*L);
     beg = (*L)->next;
     end = beg->next;//初始化两个结点
     while(beg->next)//end,这里不直接为空指针,不用end的原因是反转的时候较为容易
     {
      if(beg->next->data%2==0)//即end的数据域是偶数
         { 
           end = beg->next;
           beg = end->next;//断开end的连接
           front->next = end;//把end插入beg的前面
           end->next = beg;//接入beg
           
           
         }

      beg = beg->next;
      front = front->next;
      
      //return L;warning，问题是返回的类型和函数类型不同，返回的是一个二级指针
      return (*L);
     }
}

LNode* FindMidNode(LinkedList *L);
LNode* FindMidNode(LinkedList *L)
{
   //我最开始的想法是定义一个int类型的一维数组，初始化为0，然后随着遍历链表，每一次加1，最后再遍历一次链表，卡在了不知道怎么搞出数组的大小
   //后面发现可以用快慢指针算法
   
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