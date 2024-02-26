#pragma once
#include <ICommand.h>
#include <tuple>

class IMovable;
class IGameObject;

class RotateObjXY : public common::ICommand
{
public:
	RotateObjXY(IGameObject*);
	~RotateObjXY();

	RotateObjXY* SetAngle(double);
	void Execute() override;

private:
	IGameObject* m_object;
	IMovable* m_movableObject;
	double m_angle;
};
