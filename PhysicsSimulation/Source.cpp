#include <iostream>
#include <raylib.h>
#include "Simulation.hpp"

int main()
{
	InitWindow(1000, 500, "Physics simulation");

	Simulation::Physics sim;
	sim.AddObject(100000, { 100,100 }, { 0,0 }, 10, 0);
	sim.AddObject(100000, { 300,30 }, { 0,0 }, 10, 0);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);
		
		Simulation::DrawObjects(sim);

		sim.DrawVectorLines();
		sim.PhyscisMain();

		EndDrawing();

		//Input
		if (IsKeyDown(KEY_RIGHT))
		{
			sim.Objects[0].mass += 40000;
			sim.Objects[1].mass += 40000;
		}
		if (IsKeyDown(KEY_LEFT))
		{
			sim.Objects[0].mass -= 40000;
			sim.Objects[1].mass -= 40000;
		}
		//Second follows mouse
		Vector2 MousePos = GetMousePosition();
		sim.Objects[1].Position.Convert(MousePos);
		std::cout << sim.Objects[1].Position.x << " : " << sim.Objects[1].Position.y << "\n";
	}
	CloseWindow();
}