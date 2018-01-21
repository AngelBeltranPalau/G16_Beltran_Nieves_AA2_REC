#pragma once
#include "Scene.h"

//Enum con las tres escenas del juego
enum estadoJuego { LEVEL, MENU, RANKING};

class Game
{
public:
	Game();
	~Game();

private:

	//Esta variable nos servir� para sabber en que escena estamos actualmente
	estadoJuego estadoActual;

	//Este puntero apuntar� a la instancia de la escena actual
	Scene *escenaActual;

};