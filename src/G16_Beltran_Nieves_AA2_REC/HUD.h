#pragma once
#include "Renderer.h"
#include "Constants.h"
class HUD
{
public:
	HUD();
	~HUD();

	// Draw HUD
	void draw();

	// Update HUD
	void update(int &t, std::vector<int> &movimientos);

private:

	// Rectángulo del HUD
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

};

