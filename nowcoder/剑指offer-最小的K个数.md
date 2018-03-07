## [最小的K个数](https://www.nowcoder.com/questionTerminal/6a296eb82cf844ca8539b57c23e6e9bf)
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

## 代码
```C++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int n = input.size();
        if(n < k)
            return {};
        if(n == k)
            return input;
        int index = partition(input, 0, n-1);
        int low = 0, high = n-1;
        while(index != k-1)
        {
            if(index < k-1) {
                low = index + 1;
                index = partition(input, low, high);
            }
            else {
                high = index - 1;
                index = partition(input, low, high);
            }
        }
        vector<int> res(k);
        copy(input.begin(), input.begin()+k, res.begin());
        return res;
    }
    
    int partition(vector<int>& input, int low, int high) {
        if(low > high) return -1;
        int index = rand() % (high - low) + low;
        int key = input[index];
        std::swap(input[index], input[high]);
        int small = low - 1;
        while(low < high) {
            if(input[low] < key) {
                ++ small;
                std::swap(input[small], input[low]);
            }
            low ++;
        }
        ++small;
        std::swap(input[small], input[high]);
        return small;
    }
};
```
