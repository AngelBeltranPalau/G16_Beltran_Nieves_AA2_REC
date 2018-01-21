#pragma once
#include "Scene.h"
#include "Menu.h"
#include "Ranking.h"
#include "Level.h"

//Enum con las tres escenas del juego
enum estadoJuego { LEVEL, MENU, RANKING};

class Game
{
public:
	Game();
	~Game();

private:

	//Esta variable nos servirá para sabber en que escena estamos actualmente
	estadoJuego estadoActual;

	//Este puntero apuntará a la instancia de la escena actual
	Scene *escenaActual;

};