/*  Author: Will Rooney
*      Date Created: 04/05/2017
*      Last Modification Date: 04/05/2017
*      Program Description: Sandbox to test pathfinding algorithms. Refer to ../map.png to follow the computed path
*/
#include "dstar.h"

int main(int argc, char* argv[])
{
	/* Setup Section */
	std::cout << "Initializing...\n";
	DStar search;

	/* Set current position (x, y, neighbor1, neighbor2)
	* alternatively: createStartNode(node number) // if start is placed on existing node
	*/
	Node *start = search.createStartNode(2.5, 30.0, 1, 7); // create start/current inbetween node 1 and 7
	//Node *start = search.createStartNode(2); // create start/current on node 2
	

	/* Initialize goal (x, y, neighbor1, neighbor2), and get a copy of the goal node
	 * alternatively: initGoalNode(node number) // if goal is placed on existing node
	*/
	Node goal = search.initGoalNode(37.5, 5.0, 16, 22); // create goal inbetween node 16 and 22
	//Node goal = search.initGoalNode(21); // create goal on node 21

	Node last = *start;
	Node *next;

	// Compute intial shortest path
	std::cout << "Computing initial shortest path...\n\n";
	search.computeShortestPath();

	// rhs(start) check - solution #1
	bool INIT_START = true;

	int increment = 0, obstacle = 5; // when increment == obstacle calculate new path; obstacle is number of steps before path is blocked
	while (*start != goal) {
		/* Loop Section */
		increment++;

		// if rhs(start) == inf) then there is no known path
		// This will always be true on initial run
		// Two Solutions:
		//		1) Skip check on first while loop
		//		2) If Initial Start Node is not on the static node graph, add it.
		//			This will add the initial start node to all future searches and
		//			the rhs value will be thus updated. If the path must traverse back
		//			to the initial start node then one iteration will pass through this node
		//			where there are no branches/intersections
		if (start->rhs == std::numeric_limits<float>::infinity()) {
			if (INIT_START) {
				INIT_START = false;
			}
			else {
				std::cout << "Impossible to reach goal!\n";
				std::cin.get();
				return -1;
			}
		}

		// Next = minimum cost neighbor
		next = start->getNext();
		std::cout << "Current node:\t" << search.getNodeName(*start) << '\n';
		std::cout << "Next node:\t" << search.getNodeName(*next) << "\n\n";

		/* Move to next */

		/* Check for obstacles */

		// If path blocked
		if (increment == obstacle) {
			// Example: road blocked from 'start' to 'next'
			std::cout << "Path blocked! Updating edge cost between " << search.getNodeName(*start) << " and " << search.getNodeName(*next) << "\n\n";
			increment = 0;

			/* Return to 'start' if necessary */

			// Recalculate shortest path
			search.km = search.km + search.dist(last, *start);
			last = *start;
			if (!search.updateEdgeCost(start, next, std::numeric_limits<float>::infinity())) { // updateEdgeCost returns true if the goal can still be reached, false otherwise
				std::cout << "Impossible to reach goal!\n";
				std::cin.get();
				return -1;
			}
			search.computeShortestPath();


			std::cout << "New path calculated\n\n";

			// Reset next node from new path

			// Start loop over -> try to navigate to the new 'next' node
			continue;
		}

		// Arrived at next node
		std::cout << "Arrived at next node!\n\n";
		start = next;
		std::cin.get();
	}
	std::cout << "Reached the goal!\n";
	std::cin.get();
	return 0;
}