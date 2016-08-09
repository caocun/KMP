#include<iostream>
using namespace std;

//求next值
void CalNext(const char *sub, int n, int *next)
{
	int i=0,j=-1;
	next[0] = -1;

	while(i<n-1) //注意是n-1，否则会越界
	{
		if(j==-1||sub[i] == sub[j])
		{
			next[++i] = ++j;
		}
		else
		{
			j = next[j];
		}
	}
	for(int i=0; i<n; i++)
	{
		cout<<next[i]<<" ";
	}
	cout<<endl;
}
int KMP(const char *str, const char *sub)
{
	if(str == NULL || sub == NULL) return -1;

	int i=0,j=0;
	int len1 = strlen(str);
	int len2 = strlen(sub);
	////////////////////////////
	int *next = new int[len2];
	CalNext(sub, len2, next);
	///////////////////////////
	while(i<len1&&j<len2)
	{
		if(j==-1 || str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	//////////////////////////
	delete [] next;
	if(j == len2) return i-j;
}
int main()
{
	char *str = "aaaaaaaaaaaaabbb";
	char *sub = "aaaaabb";
	int index = KMP(str, sub);
	cout<<index<<endl;
	return 0;
}
