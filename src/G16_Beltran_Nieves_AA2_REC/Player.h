#include "Renderer.h"
#include "Constants.h"

#pragma once
class Player
{
public:
	Player();
	~Player();
};


// Enum de moviment.
enum Direcciones { UP, LEFT, DOWN, RIGHT, NONE };


class Player
{
private:

	//Determinar se es el jugador 1 o 2
	int numJugador;

	// Movimientos restantes del jugador.
	int movimientos;

	// Posición del jugador
	int posicionX, posicionY;

	// Rectangulo del sprite jugador.
	SDL_Rect RectanguloSprite;

	//Rectangulo del jugador
	SDL_Rect Rectangulo;

	

public:

	void setRectanguloSprite(SDL_Rect sprite);
	SDL_Rect getRectanguloSprite();
	void setRectangulo(SDL_Rect sprite);
	SDL_Rect getRectangulo();

	void update ();
	void draw();
	void handleEvents();
	// Constructor de player.
	Player();

	// Destructor de player.
	~Player();

};
