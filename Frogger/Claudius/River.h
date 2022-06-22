#pragma once
#include "Log.h"

//Struct-collection of logs that also handles them

struct River
{
	River();

	//Q stands for Quantity, D stands for Directions, River's rows are numbered from bottom to top
	static const unsigned int row1Q = 2;
	static const unsigned int row2Q = 4;
	static const unsigned int row3Q = 3;
	static const unsigned int row4Q = 1;
	static const unsigned int row5Q = 3;
	static const unsigned int row6Q = 4;
	static const unsigned int rowTotalQ = row1Q + row2Q + row3Q + row4Q + row5Q + row6Q;

	static const int row1D = 1;
	static const int row2D = -1;
	static const int row3D = 1;
	static const int row4D = -1;
	static const int row5D = 1;
	static const int row6D = -1;

	Log row1[row1Q];
	Log row2[row2Q];
	Log row3[row3Q];
	Log row4[row4Q];
	Log row5[row5Q];
	Log row6[row6Q];
	Log rowTotal[rowTotalQ];

	void Initialize(Image& spritesheetImage_in);
	void Render(RenderManager& renderManager);
	void Update(float dt);
};