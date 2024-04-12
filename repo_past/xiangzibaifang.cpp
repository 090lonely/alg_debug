#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

long long int n=2021041820210418;
long long int cnt;
vector<long long int> a;

int main()
{
	for(int i=1;i<sqrt(n);i++)
	{
		if(n%i==0)
		{
			a.push_back(i);
			a.push_back(n/i);
		}
	}
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a.size();j++)
		{
			if(n%(a[i]*a[j])==0) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}