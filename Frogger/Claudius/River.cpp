#include "River.h"
#include <ctime>

River::River()
{

}

void River::Initialize(Image& spritesheetImage_in)
{
	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < row1Q; i++)
	{
		int x = (rand() % 100) + (400 / row1Q * i);
		row1[i].Initialize(spritesheetImage_in, LogType::Long, row1D, static_cast<float>(x), 160); // creating a copy of local log and sending it to row1
	}
	for (int i = 0; i < row2Q; i++)
	{
		int x = (rand() % 100) + (400 / row2Q * i);
		row2[i].Initialize(spritesheetImage_in, LogType::Medium, row2D, static_cast<float>(x), 140);
	}
	for (int i = 0; i < row3Q; i++)
	{
		int x = (rand() % 100) + (400 / row3Q * i); 
		row3[i].Initialize(spritesheetImage_in, LogType::Short, row3D, static_cast<float>(x), 120);
	}
	for (int i = 0; i < row4Q; i++)
	{
		int x = (rand() % 100) + (400 / row4Q * i);
		row4[i].Initialize(spritesheetImage_in, LogType::Long, row4D, static_cast<float>(x), 100);
	}
	for (int i = 0; i < row5Q; i++)
	{
		int x = (rand() % 100) + (400 / row5Q * i);
		row5[i].Initialize(spritesheetImage_in, LogType::Medium, row5D, static_cast<float>(x), 80);
	}
	for (int i = 0; i < row6Q; i++)
	{
		int x = (rand() % 100) + (400 / row6Q * i);
		row6[i].Initialize(spritesheetImage_in, LogType::Short, row6D, static_cast<float>(x), 60);
	}

	for (int i = 0; i < rowTotalQ; i++)
	{
		for (int j = 0; j < row1Q; j++)
		{
			rowTotal[j] = row1[j];
		}
		for (int j = 0; j < row2Q; j++)
		{
			rowTotal[row1Q + j] = row2[j];
		}
		for (int j = 0; j < row3Q; j++)
		{
			rowTotal[row1Q + row2Q + j] = row3[j];
		}
		for (int j = 0; j < row4Q; j++)
		{
			rowTotal[row1Q + row2Q + row3Q + j] = row4[j];
		}
		for (int j = 0; j < row5Q; j++)
		{
			rowTotal[row1Q + row2Q + row3Q + row4Q + j] = row5[j];
		}
		for (int j = 0; j < row6Q; j++)
		{
			rowTotal[row1Q + row2Q + row3Q + row4Q + row5Q + j] = row6[j];
		}
	}
}

void River::Render(RenderManager& renderManager)
{
	for (int i = 0; i < rowTotalQ; i++)
	{
		rowTotal[i].Render(renderManager);
	}
}

void River::Update(float dt)
{
	for (int i = 0; i < rowTotalQ; i++)
	{
		rowTotal[i].Update(dt);
	}
}

/*
log1, x 0-100 (assume x = 80)	: rand() % 100 
	x + length (assume l = 80 => x = 160) 
	x 160-260 

*/