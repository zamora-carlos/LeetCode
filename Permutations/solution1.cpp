class Solution {
public:
    vector<vector<int>> permute(const vector<int> &nums, int ignoreLast = 0) {
        if (ignoreLast == nums.size() - 1) {
            return vector<vector<int>> {{nums[0]}};
        }

        vector<vector<int>> partialPermutations = permute(nums, ignoreLast + 1);
        vector<vector<int>> permutations;
        int numToBeInserted = nums[nums.size() - ignoreLast - 1];

        for (int i = 0; i < partialPermutations.size(); i++) {
            vector<int> currPartialPermutation = partialPermutations[i];

            for (int pos = 0; pos <= currPartialPermutation.size(); pos++) {
                vector<int> newPermutation = currPartialPermutation;
                newPermutation.insert(newPermutation.begin() + pos, numToBeInserted);
                permutations.push_back(newPermutation);
            }
        }

        return permutations;
    }
};