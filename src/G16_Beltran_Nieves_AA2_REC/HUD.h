#pragma once
#include "Renderer.h"
#include "Constants.h"
class HUD
{
private:

	// Rect�ngulo del HUD
	SDL_Rect plMoves1Rect;
	SDL_Rect plMoves2Rect;
	SDL_Rect secRect;
	SDL_Rect realMoves1Rect;
	SDL_Rect realMoves2Rect;
	SDL_Rect realSecRect;


	// Variable tiempo del HUD
	int tiempoHud;

	// Movimientos HUD
	std::vector<int> movimientosHud;

public:

	HUD();
	~HUD();

	//Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	void update(int &t, std::vector<int> &movimientos);

	// Funci�n encargada de dibujar la escena
	void draw();

};

