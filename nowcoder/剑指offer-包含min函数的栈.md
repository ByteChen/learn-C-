## [问题](https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

## 代码
#### 我的方法：使用动态数组实现栈，使用multiset实现min（）函数的功能
```C++
class Solution {
public:
    Solution():s_top(-1), p(new int[100]), capacity(100){}
    ~Solution(){delete []p;}
    
    void push(int value) {
        if(s_top + 1 == capacity) //full
        {
            int* temp = new int[capacity*2];
            
            copy(p,p+capacity-1, temp);
            delete []p;
            p = temp;
            capacity *= 2;
        }
        s_top++;
        p[s_top] = value;
        s.insert(value);
    }
    void pop() {
        if(s_top == -1)
            throw "no data!\n";
        //s.erase(p[s_top]);    //不能直接这样，会把multiset中所有相同元素都删掉
        auto pos = s.find(p[s_top]);
        s.erase(pos);
        s_top --;
    }
    int top() {
        return p[s_top];
    }
    int min() {
        return *s.begin();
    }
private:
    int s_top;
    int* p;
    int capacity;
    multiset<int> s;
};
```


#### 别人的方法1：使用两个栈，其中一个是辅助栈
```C++
class Solution {
public:
    stack<int> datastack,minstack;  //定义一个数据栈，一个辅助栈
    void push(int value) {
        datastack.push(value);
        if(minstack.size()==0||value<minstack.top())
            minstack.push(value);
        else
            minstack.push(minstack.top());        //有多个最小值的备份，所以能够每次都pop
    }
    void pop() {
        datastack.pop();
        minstack.pop();
    }
    int top() {
        return datastack.top();
    }
    int min() {
        return minstack.top();
    }
};
```


#### 别人的方法2：类似的，使用两个栈，其中一个是辅助栈，只不过minstack不是每次都push
```C++
class Solution {
public:
     
    stack<int> stack1,stack2;
     
    void push(int value) {
        stack1.push(value);
        if(stack2.empty())
            stack2.push(value);
        else if(value<=stack2.top())
        {
            stack2.push(value);
        }
    }
     
    void pop() {
        if(stack1.top()==stack2.top())
            stack2.pop();
        stack1.pop();
         
    }
     
    int top() {
        return stack1.top();       
    }
     
    int min() {
        return stack2.top();
    }     
};
```
