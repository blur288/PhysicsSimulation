#include <iostream>
#include <raylib.h>
#include "Simulation.hpp"

int main()
{
	InitWindow(1000, 500, "Physics simulation");

	Simulation::Physics sim;
	sim.AddObject(10, { 100,100 }, { 0,0 }, 10, 0);
	sim.AddObject(10, { 30,30 }, { 0,0 }, 10, 0);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);
		
		Simulation::DrawObjects(sim);

		EndDrawing();
	}
	CloseWindow();
}