/*
* dstar.h
*
* Author: Will Rooney
* Date Created: 03/24/2017
* Date Modified: 04/05/2017
*
* Description: Sven Koenig and Maxim Likhachev's D* Lite Search algorithm.
*	The paper can be found here: http://idm-lab.org/bib/abstracts/papers/aaai02b.pdf
*/

#ifndef DSTAR_H
#define DSTAR_H

#include <stack>
#include <string>
#include "node_pqueue.h"

class DStar {
public:
	DStar();

	Key calculateKey(Node s);
	void updateNode(Node *n);
	bool updateEdgeCost(Node *u, Node *v, float cost);
	void computeShortestPath();

	float cost(Node *u, Node *v);
	float dist(Node n1, Node n2);

	Node initGoalNode(int n); // Goal is placed on an existing node
	Node initGoalNode(float x, float y, int n1, int n2); // Goal is placed inbetween existing nodes
	Node *createStartNode(int n);
	Node *createStartNode(float x, float y, int n1, int n2);

	std::string getNodeName(Node n); // For debugging/testing

	float km;
	Node start;
private:
	void initStaticNodes();

	NodePQueue U;
	std::vector<Node> nMap;
};
#endif