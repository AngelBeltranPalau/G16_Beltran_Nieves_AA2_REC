#pragma once
#include "Game.h"
#include "Renderer.h"
#include "Constants.h"
#include <iostream>


enum estadoEscena { RUNNING, GOLEVEL1, GOLEVEL2, GORANK, GOMENU, EXIT };

class Scene
{
protected:

	//Variable que se refiere al estado actual de la escena
	estadoEscena estadoEscenaActual;

	//Rect�ngulo del background. Lo creamos constante porque es igual en todas las escenas
	const SDL_Rect bgRect{ 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };


public:
	Scene();
	~Scene();

	// Funci�n encargada de controlar los eventos
	virtual void handleEvents() = 0;

	// Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	virtual void update() = 0;

	// Funci�n encargada de dibujar la escena.
	virtual void draw() = 0;

	// Funci�n que devuelve el estado actual de la escena
	estadoEscena getEstadoEscena();
};


