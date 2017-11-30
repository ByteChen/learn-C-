## 问题
You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
```
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
```
Example 2:
```
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
```
Example 3:
```
Input: [1,2,3,4,4,5]
Output: False
```
Note:
* The length of the input is in range of [1, 10000]

## 代码
```C++
class Solution {
public:
   //方法一：别人的方法：
    bool isPossible(vector<int>& nums) {
        vector<vector<int> > D;
        
        if(nums.empty()){
            return false;
        }
           
        for(int i = 0; i < nums.size(); ++i){
            bool inserted = false;
            
            for(int j = D.size() - 1; j >= 0; j--){
                
                if(D[j].back() + 1 == nums[i]){
                    D[j].push_back(nums[i]);
                    inserted = true;
                    break;
                }
            }
            
            if(!inserted){
                vector<int> n;
                n.push_back(nums[i]);
                D.push_back(n);
            }
            inserted = false;
        }
        
        for(int i = D.size() - 1; i >= 0; i--){
            if(D[i].size() < 3){
                return false;
            }
        }
   
        return true;
    }
    
    
    ////方法二：根据上面对别人方法的理解，自己默写...
    bool isPossible(vector<int>& nums) {
        if(nums.size() < 3) 
            return false;
        vector<vector<int> > vec;
        
        for(int i=0; i<nums.size(); i++)
        {
            bool insert = false;
            for(int j = vec.size()-1; j>=0; j--)    //int 若改成 auto，会runtime error
            {                                       //因为初始vec.size() == 0, size_type是unsigned，0-1=一个好大的整数4294967295，就是32位的全1
                if(vec[j].back()+1 == nums[i])
                {
                    vec[j].push_back(nums[i]);
                    insert = true;
                    break;
                }
            }
            
            if(!insert)
            {
                vector<int> new_vec;
                new_vec.push_back(nums[i]);
                vec.push_back(new_vec);
            }
            
        }
        
        for(auto i : vec)
            if(i.size()<3)
                return false;
        return true;
        
    }
};
```
