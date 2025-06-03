// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "vector"
#include "stack"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeGenerator.generated.h"

using cell = std::pair<int, int>;

UCLASS()
class MAZE_SOLVER_API AMazeGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeGenerator();

	void dfs(std::vector<std::vector<int>>& maze, const size_t maze_width, const size_t maze_height, bool exitAndEntrance=false);
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
