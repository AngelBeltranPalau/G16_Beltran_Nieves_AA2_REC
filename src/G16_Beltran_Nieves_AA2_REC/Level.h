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


class Level : public Scene
{
public:
	Level(const int &nLevel);
	~Level();

	// Funci�n encargada de controlar los eventos
	void handleEvents() override;;

	// Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	void update() override;;

	// Funci�n encargada de dibujar la escena
	void draw() override;;

private:

	// Array de jugadores
	Player jugadores[JUGADORES_TOTALES];

	// HUD del nivel
	HUD miHUD;

	// Map del nivel
	Map miMap;

	// TTiempo de partida
	clock_t lastTime = clock();
	float timeDown;
	float deltaTime = 0;

};



//
//#pragma once
//#include "Player.h"
//#include <math.h>
//#include "Scene.h"
//#include "HUD.h"
//#include "Map.h"
//#include <iostream>
//#include <sstream>
//#include <unordered_map>
//#include <functional>
//#include <utility>
//#include <time.h>
//
//#include "Renderer.h"
//#ifndef LEVEL_H
//#define LEVEL_H
//
//class Level : public Scene
//{
//private:
//
//	int frameWidth;
//	int frameTime;
//
//	// Array de players.
//	Player players[PLAYER_TOTAL];
//
//	// Hud de level.
//	HUD myHUD;
//
//	// Map de level
//	Map myMap;
//
//	// Temps de partida.
//	clock_t lastTime = clock();
//	float timeDown;
//	float deltaTime = 0;
//
//	// Arrays que guardaran la posici� a la que s'ha de moure el player.
//	int newPlayerX[PLAYER_TOTAL] = { 0 }, newPlayerY[PLAYER_TOTAL] = { 0 };
//
//	// Utilitzarem aquests rects per a saber si el personatge ja s'ha mogut.
//	SDL_Rect playerRects[PLAYER_TOTAL];
//
//	// Variable amb la que sabrem quin powerUp spawnejar�.
//	Powerups spawningPowerUp = Powerups::NOPOWERUP;
//
//	// Vectors en els que guardarem les posicions dels diferents powerups.
//	std::vector<std::pair<int, int>> shieldPositions;
//	std::vector<std::pair<int, int>> speedPositions;
//
//public:
//
//	// Constructor de level.
//	Level(const int &nLevel);
//
//	// Destructor de level.
//	~Level();
//
//	// Funci� amb la que podrem comparar si dos rects s'interposen.
//	bool rectsSuperImposed(const SDL_Rect &r1, const SDL_Rect &r2);
//
//	// Func�o encarregada del control d'events.
//	void handleEvents() override;
//
//	// Funci� encarregada d'actualitzar l'escena segons els inputs del jugador / events que passin.
//	void update() override;
//
//	// Funci� encarregada de dibuixar l'escena en pantalla.
//	void draw() override;
//
//	// Funci� encarregada del control de les bombes.
//	void bombControl();
//
//	// Funci� encarregada de la detonaci� de bombes.
//	void bombDetonator(const int &i);
//
//	// Funci� encarregada de control�lar les col�lisions a partir dels valors donats per Map.
//	void collisionControl(const int &i);
//
//	// Funci� encarregada de control�lar el temps dels powerUps.
//	void powerUpControl(const int &i);
//};
//#endif
