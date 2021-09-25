
#include<iostream>
#include<vector>

using namespace std;

bool interWeavingHelper(string &one, string &two, string &three,int idx1, int idx2 ,
												int **memoize )
{

	
	int len1 = one.length();
	int len2 = two.length();
	cout<<endl<<idx1<<" "<<idx2<<" "<<len1<<" "<<len2;
	if(idx1 + idx2 == three.size())
		return true;	

    int preCalc = memoize[idx1][idx2];
	if( preCalc != -1)
	{
		return preCalc;
	}
	if( idx1 < len1 && three[idx1+idx2] == one[idx1])
	{
	   bool res = interWeavingHelper(one,two,three,idx1+1,idx2,memoize);			
		 if ( res )
		 {
			memoize[idx1][idx2] = 1; 
			 return true;
		 }
	}
	if(idx2 < len2 && three[idx1+idx2] == two[idx2])
	{
		 bool res = interWeavingHelper(one,two,three,idx1,idx2+1,memoize);			
		 if ( res )
		 {
			memoize[idx1][idx2] = 1;
			 return true;
		 }
	}
	memoize[idx1][idx2] = 0;
	return false;
}

bool interweavingStrings(string one, string two, string three) {
  // Write your code here.
	int len1 = one.length();
	int len2 = two.length();
	if(len1 + len2 != three.length())
  	return false;
	int **memoize = new int*[len1+1];
	for(int i=0;i< len1+1;i++)
	{
		memoize[i] = new int[len2+1];
		std::fill(memoize[i],memoize[i]+len2+1,-1);
	}	
	bool out = interWeavingHelper(one, two,three,0, 0,memoize);
	
	return out;
}




int main()
{
    string one = "algoexpert";
    string two =  "your-dream-job";
    string three = "your-algodream-expertjob";
    if( interweavingStrings(one,two,three) )
        cout<<endl<<"Result is true";
    else
        cout<<endl<<"Result is false";
    

    return 0;
}