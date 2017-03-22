/*
 * pathTest.c
 *
 * Author: Will Rooney
 * Date Created: 03/21/2017
 * Date Modified: 03/21/2017
 *
 * Description: Sandbox to test the pathfinding algorithm
 */

#include <stdio.h>
#include "astar.h"

int main(void) {
	initAStar();			// Settings for goal position and initial start position
	node *path[NUM_NODES];
	AStar(S_NODE_I, path);	// Starting from initial start node calculate path

	/* Print each coordinate step to reach goal */
	int i;
	for (i = 0; i < NUM_NODES; ++i)
		if (path[i] != NULL) // If path array is not full empty slots start at the beginning of the array (to be changed)
			printf("Step: %d | Coordinates: (%f, %f)\n", i, path[i]->pos.x, path[i]->pos.y);

	/* OBSTACLE DETECTED: between node 21 and 22 */
	printf("Obstacle detected between nodes 21 and 22! Recalculating path\n");
	removeEdge(20, 21);
	AStar(20, path); // Starting from node 21 calculate the new path

	/* Print each coordinate step to reach goal */
	for (i = 0; i < NUM_NODES; ++i)
		if (path[i] != NULL) // If path array is not full empty slots start at the beginning of the array (to be changed)
			printf("Step: %d | Coordinates: (%f, %f)\n", i, path[i]->pos.x, path[i]->pos.y);

	return 0;
}