/// Source : https://leetcode.com/problems/number-of-islands/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/// Floodfill - DFS
/// Recursion implementation
///
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)

bool visit(char **grid, int gridRowSize, int gridColSize, int x, int y){
    if(x < 0 || x >= gridRowSize || y < 0 || y >= gridColSize || grid[x][y] != '1')
	   return false;
    grid[x][y] = 'v';   
    visit(grid, gridRowSize, gridColSize, x+1, y);
    visit(grid, gridRowSize, gridColSize, x-1, y);
    visit(grid, gridRowSize, gridColSize, x, y+1);
    visit(grid, gridRowSize, gridColSize, x, y-1);
    return true;
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
        int res = 0;
        for(int i = 0 ; i < gridRowSize ; i ++)
            for(int j = 0 ; j < gridColSize; j ++)
		 res += visit(grid, gridRowSize, gridColSize, i, j)? 1 : 0;
        return res;
}


int main() {

    char g1[4][5] = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };

    char** grid;
    grid = (char**)malloc(4*sizeof(char*));
    for(int i = 0; i < 4; ++i)
        grid[i] = g1[i];

    printf(" %d \n", numIslands(grid, 4, 5));
    // 1

    // ---

    char g2[4][5] = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };
    for(int i = 0; i < 4; ++i)
        grid[i] = g2[i];

	printf(" %d \n", numIslands(grid, 4, 5));
    // 2

     free(grid);
    return 0;
}
