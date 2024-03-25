ListNode* temp1 = l1;
ListNode* temp2 = l2; 

ListNode* dummyhead = new ListNode(0);
//ListNode* l3 = head;
ListNode* temp3 = dummyhead;  //*head

int carry = 0;

while(temp1 || temp2 != NULL)
{
    int sum = carry;
    
    if(temp1 != NULL)
    {
        sum = temp1 -> val + carry;
    }
    if(temp2 != NULL)
    {
        sum = temp2 -> val + carry;
    }
    temp3 -> next = new ListNode(sum % 10);
    carry = sum/10;

    if(temp1 != NULL)
    {
        temp1 = temp1 -> next;
    }
    if(temp2 != NULL)
    {
        temp2 = temp2 -> next;
    }
}

if(carry != NULL)
{
    ListNode *CarryNode = new ListNode(carry);
    temp3 -> next = CarryNode;
}

return dummyhead -> next;