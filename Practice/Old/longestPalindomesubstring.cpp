#include<iostream>
#include<string>

using namespace std;

bool checkPalindromeSubString(string &str,int start,int end)
{
	while(start<=end)
	{
		if(str[start] != str[end])
			return false;
        start++;end--;
	}
	return true;
}

string longestPalindromicSubstring(string str) {
  // Write your code here.
	int len = str.length();
	int max = 1,maxStart = 0, maxEnd = 0;
	for(int i = 0; i< len-1;i++ )
	{
		int start = i;
		int end = len -1;
		while(end >= i )
		{
			if(str[start] == str[end])
			{
				if(checkPalindromeSubString(str,start,end))
				{
					int palLen = end - start + 1;
					if(palLen > max)
					{
							maxStart = start;
							maxEnd = end;
							max = palLen;
					 }
					 break;
				}				
			}
		  end --;			  
		}
  } 
  return str.substr(maxStart,maxEnd-maxStart+1);
}


int main()
{
    string str = "abaxyzzyxf";
    string out = longestPalindromicSubstring(str);
    cout << out;
}