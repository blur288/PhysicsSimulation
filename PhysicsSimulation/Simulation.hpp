#pragma once
#include <vector>
#include <cmath>

namespace Simulation
{
#define G 0.0000000000667

	struct Vec2
	{
		double x, y;

		Vec2 operator +(Vec2 Vector)
		{
			return { this->x + Vector.x, this->y + Vector.y };
		}

		Vec2 operator -(Vec2 Vector)
		{
			return { this->x - Vector.x, this->y - Vector.y };
		}

		Vec2 operator *(double Scalar)
		{
			return { this->x * Scalar, this->y * Scalar };
		}

		void Convert(Vector2 Converter)
		{
			this->x = Converter.x;
			this->y = Converter.y;
		}

		Vector2 ToVector2()
		{
			return { (float)this->x, (float)this->y };
		}
	};

	class Object
	{
	public:
		Vec2 Position;
		double mass; //kg
		double rad;
		Vec2 VelocityVector;
		double Force;

		Object(double mass, Vec2 Position, Vec2 VelocityVector, double rad, double Force)
		{
			this->mass = mass;
			this->Position = Position;
			this->rad = rad;
			this->VelocityVector = VelocityVector;
		}
		//Distance Forumla / Pythagoren Therom
		static double DistanceBetweenObjects(Object Ob1, Object Ob2)
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
			Object ObjectOne = Objects[0];
			Object ObjectTwo = Objects[1];

			double Force = (G * ObjectOne.mass * ObjectTwo.mass / pow(Object::DistanceBetweenObjects(ObjectOne, ObjectTwo), 2));

			Vec2 VectorBetweenPoints = ObjectOne.Position - ObjectTwo.Position;
			//Objects[0].Position 
			Vec2 NewPosition = ObjectOne.Position - VectorBetweenPoints * Force;
			if (CheckCollisionCircles(NewPosition.ToVector2(), Objects[0].rad, Objects[1].Position.ToVector2(), Objects[1].rad))
				return 1;
			else
			{
				Objects[0].Position = NewPosition;
			}

			return 1;
		}

		void DrawVectorLines()
		{
			Object ObjectOne = Objects[0];
			Object ObjectTwo = Objects[1];

			double Force =   (G * ObjectOne.mass * ObjectTwo.mass / pow(Object::DistanceBetweenObjects(ObjectOne, ObjectTwo), 2) );
			
			Vec2 VectorBetweenPoints = ObjectOne.Position - ObjectTwo.Position;
			Vec2 EndPoint = ObjectOne.Position - VectorBetweenPoints * Force * 1000;
			DrawLine(ObjectOne.Position.x, ObjectOne.Position.y, EndPoint.x, EndPoint.y, BLUE);
		}

		void AddObject(double mass, Vec2 Position, Vec2 VelocityVector, double rad, double Force)
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