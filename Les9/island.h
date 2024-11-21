// island.h
#ifndef ISLAND_H
#define ISLAND_H

#include <vector>
using namespace std;

constexpr int width = 5;
constexpr int height = 5;

extern int grid[height][width];
extern int biggest;
extern pair<int, int> directions[8];

void checkNeighbour(int i, int j, vector<vector<bool>> &visited, int &temporary);
void island();

#endif // ISLAND_H
