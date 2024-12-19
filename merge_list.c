#include<stdio.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};
struct ListNode *prev1=NULL,*prev2=NULL;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode *temp1=list1;
    struct ListNode *temp2=list2;
    struct ListNode *list3;
    list3->next=NULL;
    list3->val=list1->val;
    while(list3!=NULL)
    {
        while(temp2!=NULL)
        {
            if(temp1->val==temp2->val)
            {
                //struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
                struct ListNode *temp=temp2;
                temp2->next=temp1->next;
                temp1->next=temp2;
                prev2=temp2;
                temp2=temp2->next;
                break;
            }
            else if(temp1->val>temp2->val)
            {
                //struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
                struct ListNode *temp=temp2;
                temp->next=temp1;
                prev1->next=temp;
                prev2=temp2;
                temp2=temp2->next;
                break;
            }
            else if(temp1->val<temp2->val)
            {
                ///struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
                struct ListNode *temp=temp2;
                temp->next=temp1->next;
                temp1->next=temp;
                prev2=temp2;
                temp2=temp2->next;
                break;
            }
        }
        prev1=temp1;
        temp1=temp1->next;
    }
    return list1;
}