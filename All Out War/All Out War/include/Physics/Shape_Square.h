#ifndef SHAPE_SQUARE_H
#define SHAPE_SQUARE_H

#include "Physics\Basic_Body.h"

class Square : public Base_Shape
{
private:
	/// <value>Size of the Entity</value>
	Physics::Vector			mSize;
	/// <value>Array of Points that Are the Entities corner Points</value>
	Physics::Vector			mVertices[8];
protected:
	///<summary> 
	///Rotate the body so the up direction of the Entity is the same as the normal
	///</summary>
	///<param name="Normal">Normal of the Plane we rotate too</param>
	virtual void RotatetoNormal(Physics::Vector Normal);
public:
	///<summary> 
	///Constructor
	///</summary>
	///<param name="pos">Starting position</param>
	///<param name="size">Size of the Entity</param>
	///<param name="Entity_Type">Type of Entity</param>
	///<param name="entnumber">Unique number for the Entity</param>
	Square(Physics::Vector pos, Physics::Vector size, Entity_Name Entity_Type, int entnumber);
	///<summary> 
	///Destructor
	///</summary>
	virtual ~Square();
	///<summary> 
	///Get the size of the Entity 
	///</summary>
	///<returns>Entities size</returns>
	Physics::Vector GetSize();
	///<summary> 
	///Get one of the vertexs of this Entity by passing the index to the array 
	///</summary>
	/// <param name="index">The number in the array that holds this vertice</param>
	///<returns>Position of Vertice</returns>
	Physics::Vector GetVertex(int index);
	///<summary> 
	///Set position for this Entity and translate all Vertices by change in Position
	///</summary>
	///<param name="Pos">New position</param>
	virtual void SetPosition(Physics::Vector Pos);
	///<summary> 
	///Change Size of Entity and Move all vertices away from center by Scale
	///</summary>
	///<param name="size">New Size</param>
	virtual void Scale(Physics::Vector size);
	///<summary> 
	///Translate position and vertices for this Entity
	///</summary>
	///<param name="Pos">The distance to the new position</param>
	virtual void Translate(Physics::Vector Pos);	
	///<summary> 
	///Rotates Entity to new rotation given an angle and the axis of rotation
	///</summary>
	///<param name="axis">Axis that the Entity will rotate around</param>
	///<param name="angle">The angle that the Entity will rotate to</param>
	///<param name="IsLocal">If local roation or global rotation (Default : true)</param>
	virtual void Rotate(Physics::Vector axis, float angle,bool IsLocal = true);
	///<summary> 
	///Rotates Entity to new rotation given a Matrix
	///</summary>
	///<param name="matrix">Matrix used to rotate</param>
	virtual void Rotate(Physics::Matrix);
	///<summary> 
	///Rotates Entity to face a direction
	///</summary>
	///<param name="Target_Direction">Entity will rotate to this vector</param>
	///<param name="IsLocal">If local roation or global rotation (Default : true)</param>
	virtual void Rotate_To_Direction(Physics::Vector Target_Direction,bool IsLocal = true);
	///<summary> 
	///Get the point on the hull of the shape. 
	///The point is the farthest point in a given direction.
	///</summary>
	///<param name="Dir">Direction of Ray</param>
	///<returns>The farthest point on the hull of the shape</returns>
	virtual Physics::Vector Farthest_Point_In_Direction(Physics::Vector Dir);
	///<summary> 
	///Get the point on the hull of the shape. 
	///The point will be on a edge of the shape in a given direction 
	///</summary>
	///<param name="Dir">Direction of Ray</param>
	///<returns>The farthest point on the hull of the shape</returns>
	virtual Physics::Vector Farthest_Point(Physics::Vector Dir);
	///<summary> 
	///Find normal of closest plane to the point in the Square
	///</summary>
	///<param name="Dir">Point near Square</param>
	///<returns>Normal of Plane</returns>
	Physics::Vector FindNormal(Physics::Vector point);
	///<summary> 
	///Method called on each frame of the Programe.
	///</summary>
	///<param name="timesincelastframe">Time since last called</param>
	virtual void Update(float timesincelastframe);
	///<summary> 
	///Check if a point is inside the Entity
	///</summary>
	///<param name="point">The position of the point that is being checked</param>
	///<returns>If the point is inside the Entity</returns>
	virtual bool CheckPoint(Physics::Vector point);
	///<summary> 
	///Check if the Ray hits this Entity
	///</summary>
	///<param name="ray">Ray details</param>
	///<returns>New distance of the Ray</returns>
	virtual float CheckRay(Ray ray);
};

#endif