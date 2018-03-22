## [和为S的连续正数序列](https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe)

小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! 
输出描述:
> 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

## 代码
```C++
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum <= 0) return {};
        int i=1;
        int j=2;
        vector<vector<int>> res;
        while(i < sum/2 && j< sum && i < j) {
            if(getSum(i,j) < sum)
                j++;
            else if(getSum(i, j) == sum) {    //这种累加的方法计算连续数列的和，很傻，等差数组求和法 都比这个好
                vector<int> v;
                for(int k=i; k<=j; k++)
                    v.push_back(k);
                res.push_back(v);
                i++; j++;
            }
            else
                i++;
        }
        return res;
    }
    
    int getSum(int a, int b) {      //low
        if(a >= b)
            return -1;
        int sum=0;
        for(int i=a; i<=b; i++) {
            sum += i;
        }
        return sum;
    }
 }
```

#### 方法二：一些优化
```C++
vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum < 3)
            return {};
        int slow = 1;
        int fast = 2;
        int cursum = 3;    //current sum  //采用这种求和方法，比上面那种每次重复计算数列的和，要好得多。也可以用等差数列的求和公式
        vector<vector<int>> res;
        while(slow <= sum/2) {
            if(cursum == sum) {
                vector<int> v;
                for(int k=slow; k<=fast; k++)
                    v.push_back(k);
                res.push_back(v);
                fast++;
                cursum += fast;
                cursum -= slow;
                slow++;
                
                cursum -= slow;   //因为上面加了一个大数，再减去一个小一点的数，肯定还比sum大，不妨再多一次
                slow++;
            }
            else if(cursum < sum) {
                fast ++;
                cursum += fast;
            }
            else {
                cursum -= slow;
                slow ++;
            }
        }
        return res;
    }
```
