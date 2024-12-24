class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        stable_sort(arr.begin(), arr.end());
        unordered_set<int> possibles;

        for (int i : arr) {
            if ((possibles.find(i/2) != possibles.end() && i%2 == 0) || possibles.find(i*2) != possibles.end()) return true;
            possibles.insert(i);
        }
        return false;
    }
};
