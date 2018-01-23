#include "Renderer.h"
#include "Constants.h"

#pragma once


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

	Direcciones direccion;

	//Determinar si se mueve
	bool moviendose;

public:

	void setRectanguloSprite(SDL_Rect sprite);
	SDL_Rect getRectanguloSprite();
	void setRectangulo(SDL_Rect sprite);
	SDL_Rect getRectangulo();

	void setDireccion(Direcciones direccion);
	Direcciones getDireccion();
	
	void setMoviendose( bool mov);
	bool getMoviendose();

	void update ();
	void draw();
	
	// Constructor de player.
	Player();

	// Destructor de player.
	~Player();

};
