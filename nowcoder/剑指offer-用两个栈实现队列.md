## 问题
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

## 代码1
* 我的方法：push（）时两个栈之间来回倒腾。
一开始stack1是空的，先把stack2内所有数据转移到stack1，
然后新元素push如stack2，最后把stack1中的数据转移回stack2，stack1再次变为空。
每次pop（）数据时，只需要从stack2里pop进行了，所以pop简单。

* 缺点：要先把旧数据从stack2转移到stack1，push新元素后又要把旧数据从stack1转移回stack2，相当于进行了两次数据搬移，浪费时间啊。
```C++
class Solution
{
public:
    void push(int node) {
        if(stack1.empty())
        {
            while(!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
            stack2.push(node);
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

    int pop() {
        if(!stack2.empty())
        {
            int temp = stack2.top();
            stack2.pop();
            return temp;
        }
        throw "POP ERROR：queue empty!\n";
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

## 代码2
* 参考了高分答案，和我的思路相反，这是把pop（）写复杂，push（）很简单。
push直接将新数据放入stack1，pop（）的话，如果stack2为空，则先把stack1数据转移到stack2再pop。
* 优点：不像我的方法需要大量转移，效率高！
```C++
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(!stack2.empty())
        {
            int temp = stack2.top();
            stack2.pop();
            return temp;
        }
        throw "POP ERROR: queue is empty!\n";
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```
