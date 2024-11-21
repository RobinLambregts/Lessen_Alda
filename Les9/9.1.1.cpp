#include "island.h"
#include <iostream>
using namespace std;

int grid[height][width] = {
    {1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0}
};

int biggest = 0;
pair<int, int> directions[] = {
    {-1, -1}, {1, 1}, {-1, 0}, {0, -1},
    {-1, 1}, {1, -1}, {0, 1}, {1, 0}
};

void checkNeighbour(int i, int j, vector<vector<bool>> &visited, int &temporary) {
    if (i < 0 || i >= height || j < 0 || j >= width || visited[i][j] || grid[i][j] == 0)
        return;

    visited[i][j] = true;
    temporary++;

    for (auto dir : directions) {
        checkNeighbour(i + dir.first, j + dir.second, visited, temporary);
    }
}

void island() {
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    int numberOfIslands = 0;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (!visited[i][j] && grid[i][j] == 1) {
                int temporary = 0;
                checkNeighbour(i, j, visited, temporary);

                biggest = max(biggest, temporary);
                numberOfIslands++;
            }
        }
    }

    cout << "Biggest island: " << biggest << endl;
    cout << "Number of islands: " << numberOfIslands << endl;
}
