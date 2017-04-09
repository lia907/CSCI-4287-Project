/*
* node.h
*
* Author: Will Rooney
* Date Created: 03/24/2017
* Date Modified: 04/05/2017
*
* Description:
*  Defines class Node with  (x,y) coordinates,
*  came from node (parent), neighboring nodes,
*  and traversal costs
*/

#ifndef NODE_H_DSTAR
#define NODE_H_DSTAR

#include <limits>
#include <vector>

#define NODE_MAX_NEIGHBORS 	4	// Maximum number of paths that can be taken from a particular node 4
#define NUM_NODES			23	// Graph size = 22 Nodes + Goal Node
#define GOAL_NODE			0	// Goal Node nMap Index 

class Node {
public:
	Node();
	Node(float x, float y, Node *n1, Node *n2, Node *n3, Node *n4);

	bool addNeighbor(Node *n);
	bool deleteNeighbor(Node *n);
	void setNeighborNodes(Node *n1, Node *n2, Node *n3, Node *n4);
	void calcNeighborCosts();

	Node *getNext(); // Get minium neighbor traversal cost

	void setPos(float x, float y) { this->x = x; this->y = y; }

	float dist(Node n);

	void swap(Node& n) {
		std::swap(this->x, n.x);
		std::swap(this->y, n.y);
		std::swap(this->rhs, n.rhs);
		std::swap(this->g, n.g);
		std::swap(this->neighbors, n.neighbors);
		/*std::swap(this->neighbors[0].first, n.neighbors[0].first);
		std::swap(this->neighbors[0].second, n.neighbors[0].second);
		std::swap(this->neighbors[1].first, n.neighbors[1].first);
		std::swap(this->neighbors[1].second, n.neighbors[1].second);
		std::swap(this->neighbors[2].first, n.neighbors[2].first);
		std::swap(this->neighbors[2].second, n.neighbors[2].second);
		std::swap(this->neighbors[3].first, n.neighbors[3].first);
		std::swap(this->neighbors[3].second, n.neighbors[3].second);*/
	}
	Node& operator=(Node n) {
		n.swap(*this);
		return *this;
	}

	bool operator == (const Node& rhs) const { return (this->x == rhs.x && this->y == rhs.y); }
	bool operator != (const Node& rhs) const { return !(*this == rhs); }

	// Each neighbor has an edge cost associated with it ( e.g., c(this, neighbor) )
	std::pair<Node*, float> neighbors[NODE_MAX_NEIGHBORS];
	float x, y, g, rhs;
};

#endif