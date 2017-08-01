## 一、问题
Merge two sorted linked lists and return it as a new list. 
**The new list should be made by splicing together the nodes of the first two lists.**

## 二、代码
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head=NULL, *rear;  //定义一个尾指针，会便捷很多
        while(l1 && l2)
        {
            if(head == NULL)
            {
                if(l1->val <= l2->val)
                {
                    head = rear = l1;
                    l1 = l1->next;
                }
                else
                {
                    head = rear = l2;
                    l2 = l2->next;
                }
            }
            else
            {
                if(l1->val <= l2->val)
                    {
                        rear = rear->next = l1;
                        l1 = l1->next;
                    }
                else
                    {
                        rear = rear->next = l2;
                        l2 = l2->next;
                    }
            }
        }
        if(l1) rear->next = l1;
        if(l2) rear->next = l2;
        return head;
    }
    */
    
    /*  //搞个伪根，就不用判断head == NULL了，更简洁
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode dummy(INT_MIN);  //构造一个伪根
        ListNode *rear = &dummy;  //定义一个尾指针，会便捷很多
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
                {
                    rear = rear->next = l1;
                    l1 = l1->next;
                }
            else
                {
                    rear = rear->next = l2;
                    l2 = l2->next;
                }
            
        }
        if(l1) rear->next = l1;
        if(l2) rear->next = l2;
        return dummy.next;      //不能dummy->next，因为dummy不是指针，是一个对象
                                //若想使用->，可以这样：ListNode* head = new ListNode(INT_MIN); rear = head...如下一种方法
    }
    */
    
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head, *rear;  //定义一个尾指针，会便捷很多
        rear = head = new ListNode(INT_MIN);
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
                {
                    rear = rear->next = l1;
                    l1 = l1->next;
                }
            else
                {
                    rear = rear->next = l2;
                    l2 = l2->next;
                }
            
        }
        if(l1) rear->next = l1;
        if(l2) rear->next = l2;
        
        ListNode *result = head->next;
        delete head;                      //使用new的缺点就是要delete，不如上一种方法省事
        return result;
    }
};

  //另外摘录别人的递归方法，很潮，但是当链表稍微大时，容易栈溢出
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
```
