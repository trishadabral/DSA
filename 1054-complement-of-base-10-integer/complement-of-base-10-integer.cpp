class Solution {
public:
    int bitwiseComplement(int num) {
        if(num==0)return 1;
        int k = log2(num) + 1;
        int mask = (1 << k) - 1;
        return mask - num;
    }
};