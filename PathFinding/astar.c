/*
 * astar.c
 *
 * Author: Will Rooney
 * Date Created: 03/18/2017
 * Date Modified: 03/21/2017
 *
 * Description: Implementation of astar.h
 */

#include <math.h>
#include "astar.h"

void initAStar() {
	/* Set initial start position and update graph */
	updateNodePos(&nMap[S_NODE_I], 2.5, 30.0);
	removeEdge(0, 6);
	createEdge(0, S_NODE_I);
	createEdge(6, S_NODE_I);

	/* Set goal position and update graph */
	updateNodePos(&nMap[G_NODE_I], 37.5, 5.0);
	removeEdge(15, 21);
	createEdge(15, G_NODE_I);
	createEdge(21, G_NODE_I);
}

void AStar(int start, struct node **path) {
	// OPEN set := start
	// Create a start/goal node and define neighboring nodes
	nMap[start].g = 0;
	nMap[start].h = euclidDist(nMap[start].pos, nMap[G_NODE_I].pos);
	nMap[start].f = nMap[start].h;
	nMap[start].isOpen = true;

	// Counter to keep track of how many nodes are OPEN
	int openCount = 1;
	int minIndex = -1;
	int i;
	float minF;

	while(openCount > 0) {
		/* current := the node in OPEN set having the lowest f value */
		minIndex = -1;
		minF = FLT_MAX;
		// Search for lowest f() value or implement priority queue? Efficieny?
		for (i = 0; i < NUM_NODES; ++i) {
			if (nMap[i].isOpen && nMap[i].f < minF) {
				minF = nMap[i].f;
				minIndex = i;
			}
		}
		if (minIndex == -1) {
			printf("A* search failed! OPEN set is empty\n");
			return;
		}
		node *current = &nMap[minIndex];
		current->isOpen = false;
		--openCount;
		current->isClosed = true;

		/* if current = goal return path */
		if (minIndex == G_NODE_I) {
			// Reconstruct path: TODO - clean up so that path is not at tail end of array
			path[NUM_NODES-1] = current;
			for (i = NUM_NODES-2; i >= 0; --i) {
				if (current == NULL) {
					path[i] = NULL;
					continue;
				}
				current = current->parent;
				path[i] = current;
			}
			// Clear OPEN/CLOSED sets and reset costs - necessary for multiple A* calls
			resetMap();
			return;
		}

		/* For each neighbor of current */ 
		for (i = 0; i < MAX_NEIGHBORS; ++i) {
			// if neihbor in CLOSED set continue
			if (current->neighbors[i] != NULL && !current->neighbors[i]->isClosed) {
				// Distance from start to a neighbor
				float temp_g = current->g + euclidDist(current->pos, current->neighbors[i]->pos);
				if (!current->neighbors[i]->isOpen) {
					// Discovered a new node
					current->neighbors[i]->isOpen = true;
					++openCount;
				}
				else if (temp_g >= current->neighbors[i]->g)
					continue; // Not a better path
				// This path is the best until now
				current->neighbors[i]->parent = current;
				current->neighbors[i]->g = temp_g;
				current->neighbors[i]->h = euclidDist(current->neighbors[i]->pos, nMap[G_NODE_I].pos);
				current->neighbors[i]->f = current->neighbors[i]->g + current->neighbors[i]->h;
			}
		}
	}
	printf("A* search failed! OPEN set is empty\n");
	// Return failure
}

float euclidDist(point p1, point p2) { /* Calculate Euclidiean distance between two points */
	float x = p2.x - p1.x;
	float y = p2.y - p1.y;
	float dist = pow(x,2)+pow(y,2);
	dist = sqrt(dist);
	return dist;
}

void removeEdge(int n1, int n2) { /* Obstacle detected: Nodes n1 and n2 can no longer be considered neighbors */
	int i;
	for (i = 0; i < MAX_NEIGHBORS; ++i) {
		if (nMap[n2].neighbors[i] == &nMap[n1]) {
			nMap[n2].neighbors[i] = NULL;
		}
		if (nMap[n1].neighbors[i] == &nMap[n2]) {
			nMap[n1].neighbors[i] = NULL;
		}
	}
}

void createEdge(int n1, int n2) { /* Obstacle detected: Nodes n1 and n2 can no longer be considered neighbors */
	int i;
	for (i = 0; i < MAX_NEIGHBORS; ++i) {
		if (nMap[n2].neighbors[i] == NULL) {
			nMap[n2].neighbors[i] = &nMap[n1];
			break;
		} 
	}
	for (i = 0; i < MAX_NEIGHBORS; ++i) {
		if (nMap[n1].neighbors[i] == NULL) {
			nMap[n1].neighbors[i] = &nMap[n2];
			break;
		} 
	}
}

void updateNodePos(node *n, float x, float y) {
	n->pos.x = x;
	n->pos.y = y;
}

void resetMap() {
	int i;
	for (i = 0; i < NUM_NODES; ++i) {
		nMap[i].isOpen = false;
		nMap[i].isClosed = false;
		nMap[i].f = FLT_MAX;
		nMap[i].g = FLT_MAX;
		nMap[i].h = 0;
		nMap[i].parent = NULL;
	}
}