#pragma once
#include "Scene.h"
#include "Player.h"
#include "HUD.h"
#include "Map.h"
#include <iostream>
#include <sstream>
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include "Renderer.h"
#include <time.h>
#include <math.h>
#include <unordered_map>
#include <functional>
#include <utility>


class Level : public Scene
{
public:

	Level(const int &nLevel);
	~Level();

	// Función encargada de controlar los eventos
	void handleEvents() override;;

	// Función encargada de actualizar la escena en función de los eventos que sucedan y de los inputs del jugador
	void update() override;;

	// Función encargada de dibujar la escena
	void draw() override;;

private:

	//// Array de jugadores
	Player *jugadores[JUGADORES_TOTALES];
	

	// HUD del nivel
	HUD miHUD;

	// Map del nivel
	Map miMap;

	// Tiempo de partida
	clock_t lastTime = clock();
	float timeDown;
	float deltaTime = 0;

	// Vector que guarda los movimientos de los jugadores
	std::vector<int>movimientos;

};


