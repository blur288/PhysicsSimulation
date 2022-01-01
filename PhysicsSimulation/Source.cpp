#include <iostream>
#include <raylib.h>
#include "Simulation.hpp"

int main()
{
	InitWindow(1000, 500, "Physics simulation");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		Simulation::Physics sim;
		sim.AddObject(10, { 0,0 }, { 0,0 }, 1, 0);
		sim.AddObject(10, { 0,0 }, { 0,0 }, 1, 0);
		std::cout << sim.Objects.size();

		EndDrawing();
	}
	CloseWindow();
}