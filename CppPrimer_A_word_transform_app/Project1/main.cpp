#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
	string line, key, value;
	
	ifstream dict("1.txt");
	map<string, string> map;

	//不完善！比如当字典对应关系 brb 对应 be right back时，由于ss >> key >> value的赋值方式，会使得value仅仅等于be，而不是be right back
	/*while (getline(dict, line))
	{
		istringstream ss(line);
		ss >> key >> value;
		map[key] = value;
	}*/
	
	//修改如下：
	while (dict >> key && getline(dict, line))
	{
		if (line.size() > 1)
			value = line.substr(1);
		else
			throw runtime_error("No map value for " + key);
		map[key] = value;
	}

	// test if "brb" map to "be right back"
	cout << map["brb"] << endl;


	string word, line2;
	string result;
	ifstream text("2.txt");
	/*while (text >> word)
	{
		if (map.find(word) != map.end())
			word = map[word];
		result += word;
		result += ' ';
	}*/

	//return to new line when a line ends.
	while (getline(text, line2))
	{
		istringstream ss(line2);
		while (ss >> word)
		{
			if (map.find(word) != map.end())
				word = map[word];
			result += word;
			result += ' ';
		}
		result += "\n";
	}

	cout << result << endl;

	system("pause");
	return 0;

}