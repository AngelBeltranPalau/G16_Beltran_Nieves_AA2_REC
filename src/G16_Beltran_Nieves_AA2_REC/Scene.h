#pragma once
#include "Renderer.h"
#include "Constants.h"
#include <unordered_map>
#include <queue>
#include <iostream>
#include <sstream>
#include <SDL_mixer.h>
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#ifndef SCENE_H
#define SCENE_H

enum estadoEscena { RUNNING, GOLEVEL1, GOLEVEL2, GORANK, GOMENU, EXIT };

struct jugadorRanking
{
	int score;
	std::string name;
	bool operator<(const jugadorRanking& rhs) const
	{
		return score < rhs.score;
	}
};

class Scene
{
protected:

	//Variable que se refiere al estado actual de la escena
	estadoEscena estadoEscenaActual;

	//Rectángulo del background. Lo creamos constante porque es igual en todas las escenas
	const SDL_Rect bgRect{ 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	static std::priority_queue<jugadorRanking> topJugadores;



public:
	Scene();
	~Scene();

	void iniciarTopPlayer();

	// Función encargada de controlar los eventos
	virtual void handleEvents() = 0;

	// Función encargada de actualizar la escena en función de los eventos que sucedan y de los inputs del jugador
	virtual void update() = 0;

	// Función encargada de dibujar la escena.
	virtual void draw() = 0;

	// Función que devuelve el estado actual de la escena
	estadoEscena getEstadoEscena();
};


#endif