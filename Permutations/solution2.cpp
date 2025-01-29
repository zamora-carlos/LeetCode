class Solution {
public:
    vector<vector<int>> permute(const vector<int> &nums) {
        vector<int> factorials = {1};
        int sz = nums.size();

        for (int i = 1; i <= sz; i++) {
            factorials.push_back(factorials[i - 1] * i);
        }

        vector<vector<int>> permutations(factorials[sz], vector<int>(sz));

        for (int i = 0; i < factorials[sz]; i++) {
            set<int> remainingIndices;
            int permutationNumber = i;

            for (int idx = 0; idx < sz; idx++) {
                remainingIndices.insert(idx);
            }

            for (int j = 0; j < sz; j++) {
                int k = permutationNumber / factorials[sz - j - 1];
                auto it = remainingIndices.begin();
                advance(it, k);

                int idx = *it;
                permutations[i][j] = nums[idx];

                remainingIndices.erase(it);
                permutationNumber %= factorials[sz - j - 1];
            }
        }

        return permutations;
    }
};