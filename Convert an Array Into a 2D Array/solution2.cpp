class Solution {
public:
    vector<vector<int>> findMatrix(const vector<int> &nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<vector<int>> matrix(1);
        int countCurrNum;

        for (int i = 0; i < sortedNums.size(); i++) {
            if (i == 0 || sortedNums[i - 1] != sortedNums[i]) {
                countCurrNum = 1;
            } else {
                countCurrNum++;
            }

            if (countCurrNum > matrix.size()) {
                matrix.emplace_back(vector<int> {sortedNums[i]});
            } else {
                matrix[countCurrNum - 1].push_back(sortedNums[i]);
            }
        }

        return matrix;
    }
};