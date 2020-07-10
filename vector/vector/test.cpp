#define  _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	int size = nums1.size();
	vector<int> a;
	int count = 1;
	int falge = 0;
	int x = 0;
	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < nums2.size(); j++)
		{
			if (nums1[i] == nums2[j])
			{
				x = j;
			}
			if (x + count < nums2.size())
			{
				if (nums1[i] < nums2[x + count])
				{
					a.push_back(nums2[x + count]);
					falge = 1;
					break;
				}
				count++;
			}
			else if (falge == 0)
			{
				a.push_back(-1);
				break;
			}
		}
		falge = 0;
		count = 1;
		x = 0;
	}
	return a;
}
int main()
{
	vector<int>a(;
	vector<int>b(1,3,4,2);
	
	return 0;
}