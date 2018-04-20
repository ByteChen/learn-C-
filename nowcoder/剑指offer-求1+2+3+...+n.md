## [求1+2+3+...+n](https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1)
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

## 代码
#### 方法1
```C++
int Sum_Solution(int n) {
        bool a[n][n+1];
        return sizeof(a) >> 1;
    }
```

#### 方法2
```C++
int Sum_Solution(int n) {
        int sum = n;
        n && (sum += Sum_Solution(n-1));
        return sum;
    }
```
