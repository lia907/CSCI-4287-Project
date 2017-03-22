/*
 * astar.h
 *
 * Author: Will Rooney
 * Date Created: 03/18/2017
 * Date Modified: 03/21/2017
 *
 * Description: A* Search algorithm modfied to support multiple searches and keeps track of obstructions detected for search path
 */

#ifndef ASTAR_H
#define ASTAR_H

#include <stdio.h>
#include "streetmap.h"

// returns an array of pointers to each consecutive node in path with the last element being NULL
// path returned is of size NUM_NODES definition
void AStar(int start, struct node **path);
void initAStar();
float euclidDist(point p1, point p2);
void removeEdge(int n1, int n2);
void createEdge(int n1, int n2);
void updateNodePos(node *n, float x, float y);
void resetMap();

#endif