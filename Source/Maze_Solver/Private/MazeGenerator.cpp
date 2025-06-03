// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGenerator.h"

// Sets default values
AMazeGenerator::AMazeGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMazeGenerator::dfs(std::vector<std::vector<int>>& maze, const size_t maze_width, const size_t maze_height, bool exitAndEntrance)
{

	size_t width = maze[0].size();
	size_t height = maze.size();

	size_t x = rand() % (width - 1);
	if (x % 2 == 0)x++;

	size_t y = rand() % (height - 1);
	if (y % 2 == 0)y++;

	maze[y][x] = 0;

	std::stack<cell> path;

	int cells_visited = 1, target_num = maze_width * maze_height;

	cell dirs[] = { {-1,0}, {1,0}, {0,-1} ,{ 0,1 } };
	while (cells_visited < target_num)
	{

		std::vector<cell> possible_dirs;

		for (auto d : dirs)
		{
			int nx = x + d.first * 2;
			int ny = y + d.second * 2;

			if (nx > -1 && nx < width - 1 && ny > -1 && ny < height - 1 && maze[ny][nx] == 1)
				possible_dirs.push_back(d);
		}

		cell taken_dir;

		size_t possdirs_size = possible_dirs.size();
		if (possdirs_size == 0)
		{
			taken_dir = path.top();
			x -= taken_dir.first * 2;
			y -= taken_dir.second * 2;
			path.pop();
		}
		else
		{
			taken_dir = possible_dirs[0 + (rand() % possdirs_size) * (possdirs_size > 1)];
			int nx = taken_dir.first, ny = taken_dir.second;

			maze[y + ny][x + nx] = 0;
			maze[y + ny * 2][x + nx * 2] = 0;

			cells_visited++;
			y += ny * 2;
			x += nx * 2;
			path.push(taken_dir);
		}

	}

	if (exitAndEntrance)
	{

		int entrance_x = rand() % width;
		while (maze[1][entrance_x] != 0)
			entrance_x = rand() % width;
		maze[0][entrance_x] = 0;

		int exit_x = rand() % width;
		while (maze[height - 2][exit_x] != 0)
			exit_x = rand() % width;
		maze[height - 1][exit_x] = 0;

	}

}


// Called when the game starts or when spawned
void AMazeGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMazeGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

