#include <iostream>
#include <raylib.h>
#include "Simulation.hpp"
#include <sstream>

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
			sim.Objects[0].mass += 400;
			sim.Objects[1].mass += 400;
		}
		if (IsKeyDown(KEY_LEFT))
		{
			if (sim.Objects[0].mass > 0)
			{
				sim.Objects[0].mass -= 400;
				sim.Objects[1].mass -= 400;
			}
			else
			{
				sim.Objects[0].mass = 0;
			}
		}
		//Second follows mouse
		Vector2 MousePos = GetMousePosition();
		sim.Objects[1].Position.Convert(MousePos);
		std::cout << sim.Objects[1].Position.x << " : " << sim.Objects[1].Position.y << "\n";

		//Draw mass
		std::stringstream ss;
		ss << "Mass: " << sim.Objects[0].mass;
		DrawText(ss.str().c_str(), 400, 450, 30, BLACK);
	}
	CloseWindow();
}