## 问题
You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:
```
Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.
```
You need to return the sum of the points you could get in all the rounds.

Example 1:
```
Input: ["5","2","C","D","+"]
Output: 15
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
```
Example 2:
```
Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.  
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.
```
* Note:
  * The size of the input list will be between 1 and 1000.
  * Every integer represented in the list will be between -30000 and 30000.


## 代码
```C++
class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> iv;
		stringstream ss;
		int score;
		for (int i = 0; i<ops.size(); i++)
		{
			if (ops[i] == "C") iv.pop_back();
			else if (ops[i] == "D") iv.push_back(2 * iv[iv.size() - 1]);
			else if (ops[i] == "+") iv.push_back(iv[iv.size() - 1] + iv[iv.size() - 2]);
			else
			{
				ss << ops[i];
				ss >> score;
				ss.clear();       //使用stringstream时务必清空状态和重置值
				iv.push_back(score);
			}
		}

		int sum = 0;
		for (int i = 0; i<iv.size(); i++)
			sum += iv[i];
		return sum;
	}
};

```

## 总结
* 这题就是string转int时，有需要注意的地方。可以使用atoi（）函数来转，不过需要先把string转为char*；

* 也可以使用stringstream对象来完成各种转换，不过重新给stringstream对象赋值时，需要先清空这个流。关于清空stringstream，是有陷阱的，一开始我没有增加 **ss.clear()**这一行，导致程序最终结果没算对。后来加了clear就好了。但是上网查的时候，大家都说stringstream清空应该使用**ss.str("")**这种形式来清空，说clear（）只是清空状态，但是我改成那样之后，没对。 可参考：

* [C++中stringstream类如何清除缓存](http://blog.csdn.net/u012954083/article/details/23483619)
