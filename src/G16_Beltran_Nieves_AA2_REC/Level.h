#pragma once
#include "Scene.h"
class Level :
	public Scene
{
public:
	Level();
	~Level();

	// Funci�n encargada de controlar los eventos
	void handleEvents() override;;

	// Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	void update() override;;

	// Funci�n encargada de dibujar la escena
	void draw() override;;
};

