class Solution {
public:
    vector<vector<int>> findMatrix(const vector<int> &nums) {
        unordered_map<int, int> counts;
        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
            maxCount = max(maxCount, counts[nums[i]]);
        }

        vector<vector<int>> matrix(maxCount, vector<int>());

        for (const pair<int, int> &pair : counts) {
            for (int i = 0; i < pair.second; i++) {
                matrix[i].push_back(pair.first);
            }
        }

        return matrix;
    }
};