class Solution {
public:
    vector<vector<int>> permute(const vector<int> &nums) {
        int sz = nums.size();
        vector<int> factorials = {1};
        vector<int> indexPerm(sz);

        for (int i = 1; i <= sz; i++) {
            factorials.push_back(factorials[i - 1] * i);
        }

        for (int i = 0; i < sz; i++) {
            indexPerm[i] = i;
        }

        vector<vector<int>> permutations(factorials[sz], vector<int>(sz));

        for (int i = 0; i < permutations.size(); i++) {
            for (int j = 0; j < sz; j++) {
                permutations[i][j] = nums[indexPerm[j]];
            }

            getNextIndexPerm(indexPerm);
        }

        return permutations;
    }

    void getNextIndexPerm(vector<int> &indexPerm) {
        int pivotIdx = -1;

        for (int i = indexPerm.size() - 1; i > 0; i--) {
            if (indexPerm[i] > indexPerm[i - 1]) {
                pivotIdx = i;
                break;
            }
        }

        if (pivotIdx == -1) {
            for (int i = 0; i < indexPerm.size(); i++) {
                indexPerm[i] = i;
            }
        } else {
            reverse(indexPerm.begin() + pivotIdx, indexPerm.end());

            int indexToSwap = upper_bound(
                indexPerm.begin() + pivotIdx,
                indexPerm.end(),
                indexPerm[pivotIdx - 1]
            ) - indexPerm.begin();

            swap(indexPerm[pivotIdx - 1], indexPerm[indexToSwap]);
        }
    }
};