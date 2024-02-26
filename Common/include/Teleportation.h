// ****************************************************************************
//  Teleportation.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once
#include <ICommand.h>

#include "IGameObject.h"

class Teleportation :  public common::ICommand
{
public:
	Teleportation();
	Teleportation(IGameObject*);
	~Teleportation();

	Teleportation* SetObject(IGameObject*);
	Teleportation* SetPosition(std::tuple<double, double, double>&);
	void Execute() override;

private:
	IGameObject* m_object;
	std::tuple<double, double, double> m_position;
};
