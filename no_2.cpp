#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int main()
{
	vector<string> input;
	unordered_map<string, set<string>> ans_set;
	string tmp;


	while (cin >> tmp)
	{
		string s = tmp;

		input.push_back(tmp);
		sort(tmp.begin(), tmp.end());
		
		if (ans_set.find(tmp) == ans_set.end())
		{
			set<string> a = {s};
			ans_set[tmp] = a;
		}
		else
		{
			ans_set[tmp].insert(s);
		}
	}

	for (auto item:ans_set)
	{
		if(item.second.size() != 1)
		{
			for(string a:item.second)
			{
				cout << a << ' ';
			}
			cout << endl;
		}
	}


	return 0;
}