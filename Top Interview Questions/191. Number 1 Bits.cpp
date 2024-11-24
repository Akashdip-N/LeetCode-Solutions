/*
    https://leetcode.com/problems/number-of-1-bits/ 
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        string binary = bitset<32>(n).to_string();
        binary.erase(0, binary.find('1'));
        return count(binary.begin(), binary.end(), '1');
    }
};