// Source : https://leetcode.com/problems/number-of-islands/description/
/// Author : bssrdf
/// Time   : 2019-01-20

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"


/// Floodfill - BFS
///
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)

typedef struct Node Node;

struct Node{
    int i;
	int j;
	QueueNode node;
};

bool visit(char **grid, int gridRowSize, int gridColSize, int x, int y){
    int incx[4] = {-1, 1, 0, 0};
    int incy[4] = {0,  0, -1,1};
    if(grid[x][y] != '1')
	   return false;
    Queue q;
	queue_init(&q);
    grid[x][y] = 'v';  
	Node a; a.i = x; a.j = y;
	queue_push(&q, &a.node);
	while(!queue_empty(&q)){
	  int i=queue_entry(queue_peek(&q), Node, node)->i;
	  int j=queue_entry(queue_peek(&q), Node, node)->j;
	  printf(" (i,j, qsize) = (%d, %d, %u) \n", i,j,queue_size(&q));
	  for (int k=0; k<4; ++k){
	     int ii = i+incx[k]; int jj = j+incy[k];
         if(ii>=0 && ii<gridRowSize && jj>=0 && jj<gridColSize && grid[ii][jj] == '1'){
	         printf(" (k,i,j, qsize) = (%d, %d, %d, %u) \n", k, i,j,queue_size(&q));
		     grid[ii][jj] = 'v';
		     Node b; b.i = ii; b.j = jj;
	         queue_push(&q, &b.node);
		}
	  }
	  queue_pop(&q);
	  printf(" (qsize) = (%u) \n", queue_size(&q));
	}
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
