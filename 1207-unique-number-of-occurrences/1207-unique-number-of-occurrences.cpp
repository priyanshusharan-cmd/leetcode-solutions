class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> occurrences;

        // Check whether frequencies are unique
        for (auto& [num, count] : freq) {
            if (occurrences.find(count) != occurrences.end()) {
                return false;
            }

            occurrences.insert(count);
        }

        return true;
    }
};