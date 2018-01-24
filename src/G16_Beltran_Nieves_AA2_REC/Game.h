#pragma once
#include "Scene.h"
#include "Menu.h"
#include "Ranking.h"
#include "Level.h"

//ESTA CLASE GESTIONA EL ESTADO DEL JUEGO Y SE ENCARGA DE CAMBIAR ENTRE ESCENAS

//Enum con las tres escenas del juego
enum estadoJuego { LEVEL, MENU, RANKING};

class Game
{
public:
	Game();
	~Game();

private:

	//Esta variable nos servirá para saber en que escena estamos actualmente
	estadoJuego estadoActual;

	//Este puntero apuntará a la instancia de la escena actual
	Scene *escenaActual;

};