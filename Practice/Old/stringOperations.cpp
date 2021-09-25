#include<iostream>
#include<string>
using namespace std;

using namespace std;
//Inplace Reversal .. same as previous but first reverse the words then 
//reverse the string

void reverseWord(string &str,int start,int end)
{
	 while(start<=end)
	 {
		 char temp = str[start];
		 str[start] = str[end];
		 str[end] = temp;
		 start++;end--;
	 }
}

string reverseWordsInString(string &str) {
  // Write your code here.
	int len = str.length();
	for(int i=0;i < len; i++)
	{
		if(str[i] != ' ')
		{
			int start = i;
			int end = i;
			while(end < len -1 && str[end+1] != ' ')
			{
				end++;
			}
			cout<<start<<" "<<end<<endl;
			end = end > len - 1 ? len -1:end;
			i = end + 1;
			reverseWord(str,start,end);
		}
	}
	cout<<endl<<endl<<"---:"<<str<<endl;
	//Reverse the string
	reverseWord(str,0,len-1);
	cout<<endl<<endl<<"--->"<<str<<endl;
  return str;
}



int main()
{
    string s="Hello how are you";

    reverseWordsInString(s);
    cout<<endl<<"Final  "<<s<<endl<<endl;

  /*  s = s + " how";
    cout<<s;
    s= s.substr(0,s.length()-1);
    cout<<endl<<s;*/
}