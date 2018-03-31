## [合并两个排序的链表](https://www.nowcoder.com/questionTerminal/d8b6b4358f774294a89de2a6ac4d9337)

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

## 代码
#### 非递归的方法
```C++
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        ListNode* head = NULL, *tail;
        while(pHead1 && pHead2) {
            if(pHead1->val <= pHead2->val) {
                if(head == NULL)
                    head = tail = pHead1;
                else
                    tail = tail->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                if(head == NULL)
                    head = tail = pHead2;
                else
                    tail = tail->next = pHead2;
                pHead2 = pHead2->next;
            }
        }
        if(pHead1 == NULL) tail->next = pHead2;
        if(pHead2 == NULL) tail->next = pHead1;
        return head;
    }
```

#### 递归法
```C++
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        ListNode* head = NULL;
        if(pHead1->val <= pHead2->val) {
            head = pHead1;
            head->next = Merge(pHead1->next, pHead2);
        } else {
            head = pHead2;
            head->next = Merge(pHead1, pHead2->next);
        }
        return head;
    }
```
