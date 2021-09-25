#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int single_number(int arr[], int sz)  //finding a non paired number.
{
    if(sz == 0)
    {
        return 0;
    }
    
    int result = arr[0];
    for(int i=1 ;i <= sz-1 ;i++)
    {
        result = result ^ arr[i];
    }
    return result;
}

int fib(int n)
{
    
    if(n < 2)
        return n;
    
    return  fib(n-1)+fib(n-2);
}


bool allUnique(string &str)
{
	int len = str.length();
	vector<char> x;
	for(int i=0;i<len;i++)
	{
		if(find(x.begin(),x.end(),str.at(i)) != x.end())
		{
			return false;
		}
		x.push_back(str.at(i));
	}
	return true;
}

bool allUnique1(string &str)
{
		if(unique(str.begin(),str.end()) != str.end())
			return false;
	return true;
}


bool allUnique2(string &str)
{
	char map[256]={};
	for(auto x: str)
	{
		if(map[x] != 0)
			return false;
		map[x] = 1;
	}
	return true;
}




int main()
{
//fibonacci
  //cout<<fib(0)<<endl<<fib(2)<<endl<<fib(10);

//pairs ..find the unpaired
  /*int a[8] = {-1,-1,3,3,0,0,-1};
  cout<<single_number(a,8);*/

//find if the string contains all unique
  /*string inp = "abcdefghijklmnopqrstuvwxyz";
  cout << (allUnique2(inp) ? "true": "false") ;*/


	

}



