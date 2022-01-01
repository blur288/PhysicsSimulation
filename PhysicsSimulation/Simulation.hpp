#pragma once
#include <vector>
#include <cmath>

namespace Simulation
{
#define G 0.0000000000667

	struct Vec2
	{
		float x, y;

		Vec2 operator +(Vec2 Vector)
		{
			return { this->x + Vector.x, this->y + Vector.y };
		}

		Vec2 operator -(Vec2 Vector)
		{
			return { this->x - Vector.x, this->y - Vector.y };
		}
	};

	class Object
	{
	public:
		Vec2 Position;
		float mass; //kg
		float rad;
		Vec2 VelocityVector;
		float Force;

		Object(float mass, Vec2 Position, Vec2 VelocityVector, float rad, float Force)
		{
			this->mass = mass;
			this->Position = Position;
			this->rad = rad;
			this->VelocityVector = VelocityVector;
		}
		//Distance Forumla / Pythagoren Therom
		static float DistanceBetweenObjects(Object Ob1, Object Ob2)
		{
			return sqrt(
				(Ob1.Position.x - Ob2.Position.x) * (Ob1.Position.x - Ob2.Position.x) +
				(Ob1.Position.y - Ob2.Position.y) * (Ob1.Position.y - Ob2.Position.y)
			);
		}
	};

	class Physics
	{
	public:
		std::vector<Object> Objects;
		
		int PhyscisMain()
		{
			for (int i = 0; i < Objects.size(); i++)
			{
				for (int j = 0; j < Objects.size(); j++)
				{
					if (i == j)
						continue;
					//Force of gravity
					Objects[i].Force = (G * Objects[j].mass * Objects[i].mass) / Object::DistanceBetweenObjects(Objects[i], Objects[j]);
					//
					Objects[i].VelocityVector = { Objects[i].Position.x - Objects[j].Position.x, Objects[i].Position.y - Objects[j].Position.y };

					Objects[i].Position.x = Objects[i].Force * (Objects[i].Position.x);
					Objects[i].Position.y = Objects[i].Force * (Objects[i].Position.y);
				}
			}
		}

		void AddObject(float mass, Vec2 Position, Vec2 VelocityVector, float rad, float Force)
		{
			Object newObject(mass, Position, VelocityVector, rad, Force);
			Objects.push_back(newObject);
		}
	};

	void DrawObjects(Physics sim)
	{
		for (int i = 0; i < sim.Objects.size(); i++)
		{
			DrawCircle(sim.Objects[i].Position.x, sim.Objects[i].Position.y, sim.Objects[i].rad, BLACK);
		}
	}
};