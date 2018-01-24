#pragma once
#include "Scene.h"
#include "Button.h"
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"

class Ranking:
	public Scene
{
public:
	Ranking();
	~Ranking();

	// Función encargada de controlar los eventos
	void handleEvents() override;

	// Función encargada de actualizar la escena en función de los eventos que sucedan y de los inputs del jugador
	void update() override;

	// Función encargada de dibujar la escena
	void draw() override;

private:
	// Botón para volver al MENU
	Button menuButton, menuButton2;

	// Variables de la posición del ratón
	int xRaton, yRaton;

	// Booleano para controlar si el ratón está o no clicado
	bool ratonClicado;

	// Booleano que comprueban si el ratón está sobre el botón de volver al MENU
	bool ratonSobreBoton;

	// Array que almacena los rectángulos de las puntuaciones de los jugadores del Ranking
	SDL_Rect rectScoreJugadores[NUM_JUGADORES_TOP];

	// Array que almacena los textos de los jugadores del Ranking
	std::string textScoreJugadores[NUM_JUGADORES_TOP] = { "nombre1" ,"nombre2","nombre3" ,"nombre4","nombre5" };

};

