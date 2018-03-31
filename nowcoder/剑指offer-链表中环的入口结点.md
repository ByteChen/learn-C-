## [链表中环的入口结点](https://www.nowcoder.com/questionTerminal/253d2c59ec3e4bc68da16833f79a38e4)
一个链表中包含环，请找出该链表的环的入口结点。

## 代码
* 思路：假设环的长度是n，那么一快一慢两个指针相隔n，然后一起向前移动，定会在入口处相遇。因此问题转化为求环的长度。要求环的长度，只需要从环内的一点出发，
再回到这个点，就可以得出环的长度。所以问题转化为求环内的一点，只需要一快一慢两个指针从头开始移动，定会在环内相遇。
```C++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL) return pHead;
        ListNode *slow, *fast;
        slow = pHead;
        fast = pHead->next;
        while(slow != fast && fast && fast->next)         // slow == fast 时，就得到环内的一个节点
            slow = slow->next, fast = fast->next->next;
        if(fast==NULL || fast->next == NULL)  
            return NULL;                                  //说明没有环
        int circleLen = 1;
        while(fast->next != slow)                         //求环的长度
            fast = fast->next, circleLen ++;
        slow = pHead, fast = pHead;
        while(circleLen > 0) {                            //令fast领先slow环的长度
            fast = fast->next;
            circleLen --;
        }
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;

    }
};
```
