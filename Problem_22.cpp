#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

void gen(int left, int right, string cur, vector<string> &ans)
{
    if (left > right || left < 0 || right < 0) return;
    if (left == 0 && right == 0){
        ans.push_back(cur);
        return;
    }

	vector<string> rnt = vector<string>();
    gen(left - 1, right, cur + "(", ans);
    gen(left, right - 1, cur + ")", ans);
}

vector<string> generateParenthesis(int n) {
    vector<string> ans = vector<string>();
    gen(n, n, "", ans);
    return ans;
}

int main(){
	vector<string> ans = generateParenthesis(3);
	for (string s:ans)
	{
		cout << s << endl;
	}
	return 0;
}
