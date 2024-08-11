struct Point {
    int x, y;
};

void floodFillBFS(char matrix[][COLS], int startX, int startY, char targetChar, char replacementChar) {
    queue<Point> q;
    q.push({startX, startY});
    matrix[startX][startY] = replacementChar;

    int rowDirections[] = {-1, 1, 0, 0};
    int colDirections[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = p.x + rowDirections[i];
            int newY = p.y + colDirections[i];

            if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && matrix[newX][newY] == targetChar) {
                matrix[newX][newY] = replacementChar;
                q.push({newX, newY});
            }
        }
    }
}

void replaceSurrounded(char matrix[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 'O') {
                matrix[i][j] = 'K';
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        if (matrix[i][0] == 'K')
            floodFillBFS(matrix, i, 0, 'K', 'O');
        if (matrix[i][COLS - 1] == 'K')
            floodFillBFS(matrix, i, COLS - 1, 'K', 'O');
    }

    for (int j = 0; j < COLS; j++) {
        if (matrix[0][j] == 'K')
            floodFillBFS(matrix, 0, j, 'K', 'O');
        if (matrix[ROWS - 1][j] == 'K')
            floodFillBFS(matrix, ROWS - 1, j, 'K', 'O');
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 'K') {
                matrix[i][j] = 'X';
            }
        }
    }
}
