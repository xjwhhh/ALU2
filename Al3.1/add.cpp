
#include <iostream>
#include<malloc.h>

using namespace std;
// 结构化定义
 struct LNode{
    double coef;          // 系数
    int exp;              //指数
    struct LNode *next;
};

//初始化链表
LNode *Init()
{
    LNode *head = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;
    return head;
}

//增加节点
void AddNode(LNode *head, double coef, int exp)
{
    LNode *pre = head->next;
    LNode *temp;
    temp = (LNode*)malloc(sizeof(LNode));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;

    if(pre == NULL)
    {
        head->next = temp;
        return;
    }

    for(; pre->next!=NULL; pre=pre->next);

    pre->next = temp;
}


//链表长度
int Size(LNode *head)
{
    int len = 0;
    LNode *curr;
    for(curr=head->next; curr!=NULL; curr=curr->next){
    	len++;
    }

    return len;
}


//输出链表
void List(LNode *head)
{
    LNode *curr;
    cout<<"The result is : ";
    int i=0;
    for(curr=head->next; i<Size(curr); curr=curr->next)
    {
    	cout<<curr->coef<<"*X的"<<curr->exp<<"次方+";
    }
    cout<<curr->coef<<"*X的"<<curr->exp<<"次方";
}



//链表相加
LNode *Add(LNode *headA, LNode *headB)
{
    LNode *currA, *currB, *headC;
    double sum;
    currA = headA->next;
    currB = headB->next;
    headC = Init();
    //指数不同，指数大的节点被加入结果链表，前进
    while(currA!=NULL && currB!=NULL)
    {
        if(currA->exp > currB->exp)
        {
            AddNode(headC, currA->coef, currA->exp);
            currA = currA->next;
        }
        else if(currA->exp < currB->exp)
        {
            AddNode(headC, currB->coef, currB->exp);
            currB = currB->next;
        }
        //指数相同，系数相加，前进
        else
        {
           sum = currA->coef + currB->coef;
           if(sum != 0)
           {
               AddNode(headC, sum, currA->exp);
           }
           currA = currA->next;
           currB = currB->next;
        }
    }
    //非空链表加入结果链表
    while(currA != NULL)
    {
        AddNode(headC, currA->coef, currA->exp);
        currA = currA->next;
    }
    while(currB != NULL)
    {
        AddNode(headC, currB->coef, currB->exp);
        currB = currB->next;
    }

    return headC;
}

int main()
{
    LNode *headA, *headB, *headC;
    headA = Init();
    headB = Init();
    AddNode(headA, 1.5, 5);
    AddNode(headA, -1.0, 3);
    AddNode(headA, 1, 0);
    AddNode(headB, 0.5, 5);
    AddNode(headB, 1.0, 4);
    AddNode(headB, 1.0, 3);
    AddNode(headB,1.5,2);

    headC = Add(headA, headB);
    List(headC);

}
