## 问题
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* getMin() -- Retrieve the minimum element in the stack.

Example:
```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```

## 代码1,数组和set实现，速度较慢，且数组大小不好定
```C++
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        top1 = -1;
    }
    
    void push(int x) {
        top1 ++;
        s[top1] = x;
        iset.insert(x);
    }
    
    void pop() {
        if(top1 >= 0)
        {
            iset.erase(iset.find(s[top1]));
            top1 --;
        }
        else
            top1 = -1;
    }
    
    int top() {
        return s[top1];
    }
    
    int getMin() {
        return *iset.begin();
    }

private:
    int top1;
    int s[30000];
    multiset<int> iset;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```

## 代码2：参照别人的实现，使用两个stack来实现stack，可以说很狡猾
```C++
class MinStack {
public:
    /** initialize your data structure here. */    
private:
    stack<int> s1;
    stack<int> s2;

public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x<= s2.top())
            s2.push(x);
    }
    
    void pop() {
        if(s2.top() == s1.top())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```
