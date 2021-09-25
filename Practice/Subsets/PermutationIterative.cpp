#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;


/*1

This problem follows the Subsets pattern and we can follow a similar Breadth First Search (BFS) approach. However, unlike Subsets, every permutation must contain all the numbers.
Let’s take the example-1 mentioned above to generate all the permutations. Following a BFS approach, we will consider one number at a time:
If the given set is empty then we have only an empty permutation set: []
Let’s add the first element (1), the permutations will be: [1]
Let’s add the second element (3), the permutations will be: [3,1], [1,3]
Let’s add the third element (5), the permutations will be: [5,3,1], [3,5,1], [3,1,5], [5,1,3], [1,5,3], [1,3,5]
Let’s analyze the permutations in the 3rd and 4th step. How can we generate permutations in the 4th step from the permutations of the 3rd step?
If we look closely, we will realize that when we add a new number (5), we take each permutation of the previous step and insert the new number in every position to generate the new permutations. For example, inserting ‘5’ in different positions of [3,1] will give us the following permutations:
Inserting ‘5’ before ‘3’: [5,3,1]
Inserting ‘5’ between ‘3’ and ‘1’: [3,5,1]
Inserting ‘5’ after ‘1’: [3,1,5]
Here is the visual representation of this algorithm:

    []   
    []   
    [1]   
    [5]   
    [1,5]   
    [3]   
    [1,3]   
    [5,3]   
    [1,5,3]   
 Given set:  
    1   
    3   
    5   
    [1]   
 Given set:  
    [3,1]   
    [1,3]   
    [5,3,1]   
    [3,5,1]   
    [3,1,5]   
    [5,1,3]   
    [1,5,3]   
    [1,3,5]  

*/

void swap(int i,int j , string &inp)
{
    char temp = inp[i];
    inp[i] = inp[j];
    inp[j] = temp;
}

void permutateHelper(string &inp, vector<string> &out )
{
    out.push_back({});

    for(int i=0;i < inp.size();i++)
    {
        char currChar = inp[i];  // now insert this char to all the positions in existing permutations strings.
        int numPerm = out.size();
        for(int j=0; j < numPerm;j++ )
        {
            int sz = out[j].length();
            out[j] = out[j] + currChar;
            // Just like generating subset , keep pushing the digit to all positions in the existing sets in  out 
            for(int k=0;k<sz;k++)
            {
                swap(k,sz,out[j]);
                out.push_back(out[j]);
                swap(k,sz,out[j]);
            }
        }   
    }
}

void permutate(string &inp, vector<string> &out)
{    
    permutateHelper(inp,out);    
}

int main()
{
    string inp = "nishant";
    vector<string> out;
    permutate( inp,out);
    for(auto x: out)
    {
        cout<<endl<<x;
    }

    cout<<endl<<out.size()<<endl;
}