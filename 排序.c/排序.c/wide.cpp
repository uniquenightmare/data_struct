#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int MoreThanHalfNum_Solution(vector<int> numbers) {
	std::sort(numbers.begin(), numbers.end());
	int i = numbers.size() / 2;
	return numbers[i];
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> a;
		a.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << MoreThanHalfNum_Solution(a) << endl;
	}
	return 0;
}