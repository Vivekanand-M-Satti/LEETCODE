/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode*new=malloc(sizeof(struct ListNode));
    struct ListNode*curr=malloc(sizeof(struct ListNode));
    new->next=NULL;
    curr=new;
    int carry=0;
    while(l1||l2||carry!=0)
    {
       int u=(l1!=NULL?l1->val:0);
       int l=(l2!=NULL?l2->val:0);

       int val=u+l+carry;
       carry=val/10;
       int mama=val%10;
        struct ListNode*plus=malloc(sizeof(struct ListNode));
        plus->val=mama;
        plus->next=NULL;

        curr->next=plus;
        curr=curr->next;
        if(l1!=NULL)
        l1=l1->next;
        if(l2!=NULL)
        l2=l2->next;

    }
    return new->next;
    
}