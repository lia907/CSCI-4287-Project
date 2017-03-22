/*
 * streetmap.h
 *
 * Author: Will Rooney
 * Date Created: 03/18/2017
 * Date Modified: 03/21/2017
 *
 * Description: Contains definition for an array of structs of type node that represent
 *				branches in the path with an addtion to start and end goal nodes
 */

#ifndef STREET_MAP_H
#define STREET_MAP_H
#include <float.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NEIGHBORS 	4	// Maximum number of paths that can be taken from a particular node
#define NUM_NODES 		24	// Graph size
#define S_NODE_I 		22	// Initial start node index
#define G_NODE_I 		23	// Goal node index


typedef struct point {
	float x;
	float y;
} point;

typedef struct node {
	struct point pos;
	float f;
	float g;
	float h;
	bool isOpen;
	bool isClosed;
	struct node *parent; // To record cameFrom for path
	struct node *neighbors[MAX_NEIGHBORS]; // contains nMap node pointers
} node;

extern node nMap[NUM_NODES]; // Graph containing all nodes

#endif