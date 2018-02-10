## [复杂链表的复制](https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba)
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

## 代码
#### 我的代码1： 使用unordered_map
* 时间复杂度和空间复杂度都是 O(n)
* 想法很简单，对于原链表中每一个节点，新链表在创建新节点时，都用原链表的指针作为key， 新链表的指针作为value，
这样在设置random指针时，先找map中是否已经存在该节点，是则直接查找出来就好。
* 一开始，有个困惑，就是不知道unordered_map能否对```RandomListNode*```这样的指针变量做**hash**运算，不知是否要自定义一个hash函数，如果要，就麻烦了。
为了避免麻烦，我把```RandomListNode*```强制转换为unsigned int型（报错，存在数据损失，所以换乘long型就ok），这样的基本类型，无疑能够使用默认hash函数。
就是转换过程中麻烦了些。用到了 ```interpret_cast<Template> ()``` 这样的函数。
```C++
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    unordered_map<long, RandomListNode*> m;
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        m.clear();
        RandomListNode* head = NULL, *tail = NULL;
        unordered_map<long, RandomListNode*>::iterator iter;
        
        head = tail = new RandomListNode(pHead->label);
        push(pHead, tail);	//将两个指针放入map中
        
        while(pHead)
        {
            if(pHead->random){
                iter = find(pHead->random);
                if(iter != m.end()) {
                    tail->random = iter->second;
                } else { //创建一个
                    tail->random = create(pHead->random);
                }
            }
            
            if(pHead->next) {
                iter = find(pHead->next);
                if(iter != m.end()) {
                    tail->next = iter->second;
                } else { //创建一个
                    tail->next = create(pHead->next);
                }
            }
            
            pHead = pHead->next;
            tail = tail->next;
        }
        return head;
    }
    
    unordered_map<long, RandomListNode*>::iterator find(RandomListNode* p){
        if(m.empty())
            return m.end();
        long pt_value = reinterpret_cast<long> (p);           //强制类型转换，指针转为long整形
        return m.find(pt_value);
    }
    
    RandomListNode* create(RandomListNode* p) {
        int val = p->label;
        RandomListNode* temp = new RandomListNode(val);
        push(p, temp);
        return temp;
    }
    
    void push(RandomListNode* p, RandomListNode* q) {
        long pt_value = reinterpret_cast<long> (p);         //强制类型转换，指针转为long整形
        m[pt_value] = q;
    }
};
```

#### 我的代码2：
* 上面的方法，把指针转为long型，是多余的。**如果没有给予特殊的hash函数，默认的hash函数是hash<>，这是< functional >提供的一个function object，可以对付常见类型：包括所有整数类型、所有浮点数类型、pointer、std::string，以及若干特殊类型。这些之外的类型，就必须提供你自己的hash函数。**
* 参考文章1：[std::unordered_map（提供自己的Hash函数和等价准则）](http://blog.csdn.net/HappyKocola/article/details/74188452)
* 参考文章2：[STL: unordered_map 自定义键值类型的使用（C++）](http://blog.csdn.net/zhangpiu/article/details/49837387)
* 简化掉类型转换之后，代码如下：
```C++
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    unordered_map<RandomListNode*, RandomListNode*> m;
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        m.clear();
        RandomListNode* head = NULL, *tail = NULL;
        unordered_map<RandomListNode*, RandomListNode*>::iterator iter;
        
        head = tail = new RandomListNode(pHead->label);
        push(pHead, tail);	//将两个指针放入map中
        
        while(pHead)
        {
            if(pHead->random){
                iter = find(pHead->random);
                if(iter != m.end()) {
                    tail->random = iter->second;
                } else { //创建一个
                    tail->random = create(pHead->random);
                }
            }
            
            if(pHead->next) {
                iter = find(pHead->next);
                if(iter != m.end()) {
                    tail->next = iter->second;
                } else { //创建一个
                    tail->next = create(pHead->next);
                }
            }
            
            pHead = pHead->next;
            tail = tail->next;
        }
        return head;
    }
    
    unordered_map<RandomListNode*, RandomListNode*>::iterator find(RandomListNode* p){
        if(m.empty())
            return m.end();
        return m.find(p);
    }
    
    RandomListNode* create(RandomListNode* p) {
        int val = p->label;
        RandomListNode* temp = new RandomListNode(val);
        push(p, temp);
        return temp;
    }
    
    void push(RandomListNode* p, RandomListNode* q) {
        m[p] = q;
    }
};
```

#### 参考剑指offer书上的方法
* 时间复杂度 O(n)， 空间复杂度 O(1)，因为不用 map 了。
```C++
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        RandomListNode* root = pHead;
        
        while(root) {
            RandomListNode* temp = root->next;
            root->next = new RandomListNode(root->label);
            root = root->next->next = temp;
            //root = temp;
        }
        
        root = pHead;
        while(root) {
            if(root->random)
                root->next->random = root->random->next;
            root = root->next->next;
        }
        
        root = pHead;
        RandomListNode* result, *tail;
        tail = pHead->next;
        result = pHead->next;
        root = root->next = tail->next; // neccessary //务必把pHead那一个链表也恢复原样，不然报错
        while(root) {
            tail->next = root->next;
            tail = tail->next;
            root = root->next = tail->next;
            //root = tail->next;
        }
        return result;
    }
};
```




