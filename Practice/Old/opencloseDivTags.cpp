#include <vector>
#include <iostream>
using namespace std;


void generateDivTagsHelper(string prefix,int numOpen, int numClose,vector<string>& out)
{
	if(numClose == 0)
    {
		out.push_back(prefix);
		return;
    }
	if(numOpen > 0)
		generateDivTagsHelper(prefix+"<div>",numOpen-1,numClose,out);
	
    if(numOpen<numClose)
		generateDivTagsHelper(prefix + "</div>" , numOpen,numClose-1,out);

}


vector<string> generateDivTags(int numberOfTags) {
  // Write your code here.
	vector<string> out;
	generateDivTagsHelper("",numberOfTags,numberOfTags,out);
  return out;
}


int main()
{
    vector<string> out;
    out = generateDivTags(10);
    for(auto x:out)
        cout<<endl<<x;
}