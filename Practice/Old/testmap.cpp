#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    // We declare our unordered map (int, string)
    // Here, the key is an int, and the value is a string
    std::unordered_map<int, int> my_map;
 
    // Direct array-like access!
    my_map[10] = 1;
    my_map[20] = 2;    
    my_map[20] = 3;
    
    std::cout << my_map[10] << std::endl;
    std::cout << my_map[20] << std::endl;
    std::cout << my_map[245] << std::endl;

    unordered_set<char> my_set;
    my_set.insert('a');
    my_set.insert('a');
    my_set.insert('a');
    my_set.insert('a');
    my_set.insert('a');
    cout<<my_set.count('a');

 
    return 0;
}