/*
 * streetmap.c
 *
 * Author: Will Rooney
 * Date Created: 03/18/2017
 * Date Modified: 03/21/2017
 *
 * Description: Initialization of a Node's coordinates and neighbors 
 */

#include "streetmap.h"

node nMap[] = {
	{	/* Node #1 */
		.pos.x = 2.5, .pos.y = 35.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0, 
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[1],
		.neighbors[1] = &nMap[6],
		.neighbors[2] = NULL,
		.neighbors[3] = NULL
	},
	{	/* Node #2 */
		.pos.x = 17.5, .pos.y = 37.5,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[0],
		.neighbors[1] = &nMap[2],
		.neighbors[2] = &nMap[3],
		.neighbors[3] = NULL
	},
	{	/* Node #3 */
		.pos.x = 40.0, .pos.y = 40.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[1],
		.neighbors[1] = &nMap[10],
		.neighbors[2] = NULL,
		.neighbors[3] = NULL
	},
	{	/* Node #4 */
		.pos.x = 12.5, .pos.y = 32.5, 
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[1],
		.neighbors[1] = &nMap[4],
		.neighbors[2] = &nMap[7],
		.neighbors[3] = NULL
	},
	{	/* Node #5 */
		.pos.x = 22.5, .pos.y = 32.5,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[3],
		.neighbors[1] = &nMap[8],
		.neighbors[2] = NULL,
		.neighbors[3] = NULL
	},
	{	/* Node #6 */
		.pos.x = 30.0, .pos.y = 37.5,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[9],
		.neighbors[1] = NULL,
		.neighbors[2] = NULL,
		.neighbors[3] = NULL
	},
	{	/* Node #7 */
		.pos.x = 2.5, .pos.y = 25.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[0],
		.neighbors[1] = &nMap[7],
		.neighbors[2] = &nMap[11],
		.neighbors[3] = NULL
	},
	{	/* Node #8 */
		.pos.x = 12.5, .pos.y = 25.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[3],
		.neighbors[1] = &nMap[6],
		.neighbors[2] = &nMap[8],
		.neighbors[3] = NULL
	},
	{	/* Node #9 */
		.pos.x = 22.5, .pos.y = 25.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[4],
		.neighbors[1] = &nMap[7],
		.neighbors[2] = &nMap[9],
		.neighbors[3] = &nMap[13]
	},
	{	/* Node #10 */
		.pos.x = 30.0, .pos.y = 25.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[5],
		.neighbors[1] = &nMap[8],
		.neighbors[2] = &nMap[10],
		.neighbors[3] = &nMap[14]
	},
	{	/* Node #11 */
		.pos.x = 40.0, .pos.y = 25.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0, 
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[2],
		.neighbors[1] = &nMap[9],
		.neighbors[2] = &nMap[15],
		.neighbors[3] = NULL
	},
	{	/* Node #12 */
		.pos.x = 3.0, .pos.y = 15.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[6],
		.neighbors[1] = &nMap[12],
		.neighbors[2] = &nMap[19],
		.neighbors[3] = NULL
	},
	{	/* Node #13 */
		.pos.x = 15.0, .pos.y = 16.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[7],
		.neighbors[1] = &nMap[11],
		.neighbors[2] = &nMap[13],
		.neighbors[3] = &nMap[16]
	},
	{	/* Node #14 */
		.pos.x = 22.5, .pos.y = 16.5,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[8],
		.neighbors[1] = &nMap[12],
		.neighbors[2] = &nMap[14],
		.neighbors[3] = &nMap[17]
	},
	{	/* Node #15 */
		.pos.x = 30.0, .pos.y = 17.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[9],
		.neighbors[1] = &nMap[13],
		.neighbors[2] = &nMap[15],
		.neighbors[3] = &nMap[20]
	},
	{	/* Node #16 */
		.pos.x = 40.0, .pos.y = 17.5,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[10],
		.neighbors[1] = &nMap[14],
		.neighbors[2] = &nMap[21],
		.neighbors[3] = NULL
	},
	{	/* Node #17 */
		.pos.x = 15.0, .pos.y = 10.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[12],
		.neighbors[1] = &nMap[17],
		.neighbors[2] = NULL,
		.neighbors[3] = NULL
	},
	{	/* Node #18 */
		.pos.x = 22.5, .pos.y = 10.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[13],
		.neighbors[1] = &nMap[16],
		.neighbors[2] = &nMap[18],
		.neighbors[3] = NULL
	},
	{	/* Node #19 */
		.pos.x = 22.5, .pos.y = 7.0,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[17],
		.neighbors[1] = NULL,
		.neighbors[2] = NULL,
		.neighbors[3] = NULL
	},
	{	/* Node #20 */
		.pos.x = 9.0, .pos.y = 2.5, 
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[11],
		.neighbors[1] = &nMap[20],
		.neighbors[2] = NULL,
		.neighbors[3] = NULL
	},
	{	/* Node #21 */
		.pos.x = 30.0, .pos.y = 2.5,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[14],
		.neighbors[1] = &nMap[19],
		.neighbors[2] = &nMap[21],
		.neighbors[3] = NULL
	},
	{	/* Node #22 */
		.pos.x = 37.5, .pos.y = 2.5,
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false, 
		.parent = NULL, 
		.neighbors[0] = &nMap[15],
		.neighbors[1] = &nMap[20],
		.neighbors[2] = NULL,
		.neighbors[3] = NULL
	},
	{	/* Start Node */
		.pos.x = 2.5, .pos.y = 30.0, 
		.g = 0, .f = 0, .h = FLT_MAX, 
		.isOpen = true, .isClosed = false,  
		.parent = NULL, 
		.neighbors[0] = NULL,
		.neighbors[1] = NULL,
		.neighbors[2] = NULL,
		.neighbors[3] = NULL
	},
	{	/* Goal Node */
		.pos.x = 37.5, .pos.y = 5.0, 
		.f = FLT_MAX, .g = FLT_MAX, .h = 0,  
		.isOpen = false, .isClosed = false,  
		.parent = NULL, 
		.neighbors[0] = NULL,
		.neighbors[1] = NULL,
		.neighbors[2] = NULL,
		.neighbors[3] = NULL
	}
};