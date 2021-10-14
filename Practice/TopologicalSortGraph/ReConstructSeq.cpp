/*Reconstructing a Sequence (hard) #
Given a sequence originalSeq and an array of sequences, write a method to find if originalSeq can be uniquely reconstructed from the array of sequences.

Unique reconstruction means that we need to find if originalSeq is the only sequence such that all sequences in the array are subsequences of it.

Example 1:

Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [3, 4]]
Output: true
Explanation: The sequences [1, 2], [2, 3], and [3, 4] can uniquely reconstruct   
[1, 2, 3, 4], in other words, all the given sequences uniquely define the order of numbers 
in the 'originalSeq'. 
Example 2:

Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [2, 4]]
Output: false
Explanation: The sequences [1, 2], [2, 3], and [2, 4] cannot uniquely reconstruct 
[1, 2, 3, 4]. There are two possible sequences we can construct from the given sequences:
1) [1, 2, 3, 4]
2) [1, 2, 4, 3]
Example 3:

Input: originalSeq: [3, 1, 4, 2, 5], seqs: [[3, 1, 5], [1, 4, 2, 5]]
Output: true
Explanation: The sequences [3, 1, 5] and [1, 4, 2, 5] can uniquely reconstruct 
[3, 1, 4, 2, 5]. 
*/


using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

class SequenceReconstruction {
 public:
  static bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &sequences) {
    // TODO: Write your code here
    unordered_map<int,vector<int>> adjMat;
    vector<int> inDegrees(originalSeq.size(),0);

    //Build the graph  // we will assume our node sequence starts with 0 , instead of as in problem 1 .
    for(auto x: sequences)
    {
        for(int i=0;i < x.size()-1;i++)
        {
            if(find(adjMat[x[i]-1].begin(),adjMat[x[i]-1].end(),x[i+1]-1) == 
                adjMat[x[i]-1].end())
            {
                adjMat[x[i]-1].push_back(x[i+1]-1);
                inDegrees[x[i+1]-1] ++; 
            }
        }
    }
    //Get all sources
    queue<int> zeroDegNodes;
    for(int i=0;i<originalSeq.size();i++)
    {
        if(inDegrees[i] == 0)
            zeroDegNodes.push(i);
    }

    if(zeroDegNodes.size() > 1)
        return false;
    
    vector<int> seq; 
    while(!zeroDegNodes.empty())
    {
        int curr = zeroDegNodes.front();
        zeroDegNodes.pop();
        seq.push_back(curr);

        for(auto x:adjMat[curr])
        {
            inDegrees[x]--;
            if(inDegrees[x] == 0)
                zeroDegNodes.push(x);
        }

        if(zeroDegNodes.size() > 1)
            return false;
    }

    if(seq.size() != originalSeq.size())
        return false;
    
    for(int i=0;i< originalSeq.size();i++)
    {
        if(originalSeq[i]-1 != seq[i])
            return false;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  bool result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{2, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{3, 1, 4, 2, 5},
      vector<vector<int>>{vector<int>{3, 1, 5}, vector<int>{1, 4, 2, 5}});
  cout << "Can we uniquely construct the sequence: " << result << endl;
}
