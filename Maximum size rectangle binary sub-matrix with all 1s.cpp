#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int numRows = matrix.size();
    int numCols = matrix[0].size();
    vector<int> leftBoundaries(numCols, 0);
    vector<int> rightBoundaries(numCols, numCols);
    vector<int> heights(numCols, 0);
    int maxRectangleArea = 0;

    for (const auto& row : matrix) {
        int currentLeft = 0, currentRight = numCols;

        for (int j = 0; j < numCols; j++) {
            heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
        }

        for (int j = 0; j < numCols; j++) {
            if (row[j] == '1') {
                leftBoundaries[j] = max(leftBoundaries[j], currentLeft);
            } else {
                leftBoundaries[j] = 0;
                currentLeft = j + 1;
            }
        }

        for (int j = numCols - 1; j >= 0; j--) {
            if (row[j] == '1') {
                rightBoundaries[j] = min(rightBoundaries[j], currentRight);
            } else {
                rightBoundaries[j] = numCols;
                currentRight = j;
            }
        }

        for (int j = 0; j < numCols; j++) {
            int width = rightBoundaries[j] - leftBoundaries[j];
            int area = width * heights[j];
            maxRectangleArea = max(maxRectangleArea, area);
        }
    }

    return maxRectangleArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'0', '1', '1', '0'},
        {'1', '1', '1', '1'},
        {'1', '1', '1', '1'},
        {'1', '1', '0', '0'}
    };

    cout << maximalRectangle(matrix) << endl;

    return 0;
}
