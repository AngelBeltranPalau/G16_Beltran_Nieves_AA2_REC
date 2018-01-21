#pragma once
#include "Scene.h"
class Level :
	public Scene
{
public:
	Level();
	~Level();

	// Función encargada de controlar los eventos
	void handleEvents() override;;

	// Función encargada de actualizar la escena en función de los eventos que sucedan y de los inputs del jugador
	void update() override;;

	// Función encargada de dibujar la escena
	void draw() override;;
};

