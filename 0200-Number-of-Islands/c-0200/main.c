/// Source : https://leetcode.com/problems/number-of-islands/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

#include <stdio.h>
#include <stdbool.h>


/// Floodfill - DFS
/// Recursion implementation
///
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)

bool visit(void *grid0, int gridRowSize, int gridColSize, int x, int y){

    char (*grid)[gridRowSize] = grid0;
    printf(" in visit, i, j, c = (%d, %d, %c) \n", x, y, grid[0][0]);
    if(x < 0 || x >= gridRowSize || y < 0 || y >= gridColSize || grid[x][y] != '1')
    //if(x < 0 || x >= gridRowSize || y < 0 || y >= gridColSize)
	   return false;
    printf(" in visit after bound check, i, j = (%d, %d) \n", x, y);
	grid[x][y] = 'v';   
	visit(grid, gridRowSize, gridColSize, x+1, y);
	visit(grid, gridRowSize, gridColSize, x-1, y);
	visit(grid, gridRowSize, gridColSize, x, y+1);
	visit(grid, gridRowSize, gridColSize, x, y-1);
	return true;
}

int numIslands(void* grid0, int gridRowSize, int gridColSize) {
//int numIslands(char** grid, int gridRowSize, int gridColSize) {
        char (*grid)[gridRowSize] = grid0;
        int res = 0;
        for(int i = 0 ; i < gridRowSize ; i ++)
            for(int j = 0 ; j < gridColSize; j ++){
			   printf(" i,j,c = (%d, %d, %c) \n", i, j, grid[i][j]); 
			   res += visit((char**)grid, gridRowSize, gridColSize, i, j)? 1 : 0;
			}
        return res;
}


int main() {

    char g1[4][5] = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };

	printf(" %c \n", g1[0][0]);
	//printf(" %d \n", numIslands((void*)g1, 4, 5));
	printf(" %d \n", numIslands(g1, 4, 5));
    // 1

    // ---

    char g2[4][5] = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };

	printf(" %d \n", numIslands((char**)g2, 4, 5));
    // 2

    return 0;
}
