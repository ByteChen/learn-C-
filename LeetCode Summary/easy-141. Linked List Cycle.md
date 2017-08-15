## 问题
Given a linked list, determine if it has a cycle in it.

Follow up:

Can you solve it without using extra space?

## 思考
* 此题初看简单，实则容易走歪。
* 使用 **哈希表 unordered_set** 来实现的话，就是将指针存进去，每次存之前看set里有没有这个指针，有则说明有cycle。时间复杂度和空间复杂度皆为O(n).
* 链表的问题，时常可以使用**两个指针**的方法来解决。有时候是一前一后，从两边包夹；有时候则是一快一慢，比如这题。想象成两个人赛跑，如果有cycle，则跑得快的人肯定会追上跑得慢的人。

# 代码
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
    bool hasCycle(ListNode *head) {
        //方法一：使用hash table，空间复杂度为O(n)
        unordered_set<ListNode*> s;
        ListNode *p = head;
        while(p)
        {
            if(s.find(p) != s.end())
                return true;
            s.insert(p);
            p = p->next;
        }
        return false;
        
        
         //方法二：想象两个人赛跑，一快一慢，若有回环，必会相遇。不需要额外空间
        if(head == NULL) return false;
        ListNode*p, *q;
        p = head;
        if(head->next == NULL)
            return false;
        q = head->next->next;
        
        while(p && q)
        {
            if(p == q)
                return true;
            if(q->next == NULL)
                return false;
            q = q->next->next;
            p = p->next;
        }
        return false;
        
        
        //方法三：方法二的简化加速版
        if(head == NULL || head->next == NULL)
            return false;
        ListNode *fast, *slow;
        slow = head;
        fast = head->next;
        
        while(slow != fast)
        {
            if(fast == NULL || fast->next == NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
```

## 方法二三的复杂度分析
* [Complexity analysis](https://leetcode.com/problems/linked-list-cycle/solution/#approach-2-two-pointers-accepted)

  * Time complexity : O(n)

  * Space complexity : O(1)


