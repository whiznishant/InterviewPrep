/*

1865. Finding Pairs With a Certain Sum
Medium

101

44

Add to List

Share
You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
Implement the FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

*/


class FindSumPairs {
public:
    unordered_map<int,unordered_set<int>> nums2map; //keeps the indexes to duplicate values. nums2 elements are key here
    vector<int> secondNums;
    vector<int> firstnums;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        int sz = nums2.size();
        for(int idx = 0; idx < sz;idx++)
        {
           auto it = nums2map.find(nums2[idx]);
           if( it != nums2map.end())
           {
                (it->second).insert(idx);
           }
           else
           {
               nums2map.insert(std::pair<int,unordered_set<int>>(nums2[idx],{idx}));
           }
            
           secondNums.push_back(nums2[idx]);
        }
        std::copy(nums1.begin(),nums1.end(),std::back_inserter(firstnums));               
    }
    
    void add(int index, int val) { 
        if(val == 0)
            return       
        int currVal = secondNums[index];
        auto it = nums2map.find(currVal);
        //Remove the value from 
        it->second.erase(index);
        if(it->second.size() == 0)
            nums2map.erase(currVal);
        
        int newVal = currVal + val;
        it = nums2map.find(newVal);
        if(it != nums2map.end())
            it->second.insert(index);
        else
            nums2map.insert(std::pair<int,unordered_set<int>>(newVal,{index}));
      
    }
    
    int count(int tot) {
        int sz = firstnums.size();
        int numPairsFound = 0;
        for(int i = 0;i < sz; i++)
        {
            int target = tot - firstnums[i];
            auto it = nums2map.find(target);
            if( it != nums2map.end() )
            {
                numPairsFound += (it->second).size();
            }
        }
        return numPairsFound;        
    }
};



int main()
{
    FindSumPairs a({9,70,14,9,76},{26,26,58,23,74,68,68,78,58,26});
    a.add(6,10);
     a.add(5,6);

}

/*

["add","add","count","add","add","add","add","add","add","add","add","count","count","add","add","add","add","add","add","add","add","add","count","add","add","count","add","add","add","add","count","count","add","add","add","count","add","count","add","add","add","count","add","count","add","add","add","add","add","count","add","add","add","add","count","add","count","add","count","add","add","add","add","add","add","add","add","count","add","add","add","add","add","count","add","add","count","add","add","add","add","add","add","add","count","add","add","count","add","count","add","add","add","count","add","add","add","add","add","add","add","add","add","add","add","add","add","count","add","add","add","add","add","add","add","count","add","count","add","add","add","add","count","count","add","add","add","add","add","add","add","add","add","add","count","add","add","add","add","count","add","count","add","add","add","add","add","add","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count"]
[[6,10],[5,6],[32],[3,55],[9,32],[9,16],[1,48],[1,4],[0,52],[8,20],[9,4],[88],[154],[9,4501],[2,20],[2,4501],[8,4501],[5,4505],[4,4],[5,4241],[4,4501],[4,4241],[4588],[0,4501],[4,847],[8896],[1,9589],[5,847],[0,5088],[3,9589],[4649],[92],[6,4501],[6,5088],[7,9589],[4649],[7,9671],[9681],[6,9671],[8,5088],[2,5088],[19347],[9,5088],[9681],[9,9671],[2,9671],[2,7295],[9,7295],[8,9671],[19347],[3,9671],[0,9671],[5,9671],[1,9671],[9676],[4,9671],[19408],[4,7295],[26642],[1,7295],[5,7295],[5,3113],[1,3113],[0,7295],[3,7295],[8,7295],[6,7295],[29816],[7,7295],[7,3113],[7,2215],[6,3113],[8,3113],[29755],[3,3113],[0,5328],[32037],[4,3113],[9,5328],[2,3113],[2,2215],[4,2215],[4,6664],[3,2215],[38639],[4,3574],[8,2215],[29755],[6,2215],[29816],[4,4791],[4,8635],[4,2734],[29760],[1,2215],[5,2215],[4,9817],[4,4323],[4,7213],[4,6589],[4,1480],[4,9856],[4,8968],[4,8194],[4,4939],[4,7355],[4,8997],[31975],[4,6130],[4,9464],[4,7884],[4,9954],[4,2439],[4,4887],[4,7171],[184028],[4,1721],[32031],[4,9642],[4,3381],[4,2846],[4,3498],[205183],[205183],[4,6018],[4,762],[4,8810],[4,510],[4,6949],[4,949],[4,9201],[4,4371],[4,3002],[4,4107],[32037],[4,1863],[4,8839],[4,8822],[4,9054],[32031],[4,2630],[31970],[4,7110],[4,7373],[4,271],[4,5630],[4,3345],[4,1512],[306244],[306249],[31970],[32031],[306305],[306311],[31970],[31970],[306311],[306249],[306305],[306244],[306249],[306244],[32031],[306249],[31970],[32031],[31975],[31975],[306244],[31975],[306311],[32031],[306311],[306244],[306249],[31975],[306311],[32031],[306244],[306244],[306305],[306311],[32031],[31970],[31970],[306305],[306244],[31970],[306311]]

*/

