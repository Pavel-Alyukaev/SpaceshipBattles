// ****************************************************************************
//  MoveObj.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once
#include <ICommand.h>
#include <tuple>

class IMovable;
class IGameObject;

class MoveObj : public common::ICommand
{
public:
	MoveObj(IGameObject*);
	~MoveObj();

	MoveObj* SetVelocity(std::tuple<double, double, double>&);
	void Execute() override;

private:
	IGameObject* m_object;
	IMovable* m_movableObject;
};
