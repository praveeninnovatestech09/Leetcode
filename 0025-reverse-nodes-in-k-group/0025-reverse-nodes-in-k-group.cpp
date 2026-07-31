/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* reverseList(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

ListNode* findkthNode(ListNode* temp , int k){
   k--;
    while(temp!=NULL && k>0){
temp=temp->next;
 k--;
    }
    return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        
ListNode* temp= head;
ListNode* prevNode=NULL;
while(temp!=NULL){
ListNode* kthNode=findkthNode(temp , k);
if(kthNode==NULL){
    if(prevNode!=NULL){
        prevNode->next=temp;
    }
break;
}  
ListNode* nextNode= kthNode->next;
kthNode->next=NULL;
ListNode* newHead= reverseList(temp);
if(temp==head){
    head=newHead;
}
else{
    prevNode->next=newHead;
}
prevNode=temp;
temp=nextNode;
}
return head;
    }
};