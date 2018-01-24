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

	// Funci�n encargada de controlar los eventos
	void handleEvents() override;

	// Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	void update() override;

	// Funci�n encargada de dibujar la escena
	void draw() override;

private:
	// Bot�n para volver al MENU
	Button menuButton, menuButton2;

	// Variables de la posici�n del rat�n
	int xRaton, yRaton;

	// Booleano para controlar si el rat�n est� o no clicado
	bool ratonClicado;

	// Booleano que comprueban si el rat�n est� sobre el bot�n de volver al MENU
	bool ratonSobreBoton;

	// Array que almacena los rect�ngulos de las puntuaciones de los jugadores del Ranking
	SDL_Rect rectScoreJugadores[NUM_JUGADORES_TOP];

	// Array que almacena los textos de los jugadores del Ranking
	std::string textScoreJugadores[NUM_JUGADORES_TOP] = { "nombre1" ,"nombre2","nombre3" ,"nombre4","nombre5" };

};

