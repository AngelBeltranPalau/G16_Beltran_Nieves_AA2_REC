#include "Renderer.h"
#include "Constants.h"
#include <math.h>

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
	float posicionRealX, posicionRealY;

	// Rectangulo del sprite jugador.
	SDL_Rect RectanguloSprite;

	//Rectangulo para cada dirección del Sprite
	SDL_Rect spriteUPidle;
	SDL_Rect spriteDOWNidle;
	SDL_Rect spriteLEFTidle;
	SDL_Rect spriteRIGHTidle;

	SDL_Rect spriteUPwalk1;
	SDL_Rect spriteUPwalk2;

	SDL_Rect spriteDOWNwalk1;
	SDL_Rect spriteDOWNwalk2;

	SDL_Rect spriteLEFTwalk1;
	SDL_Rect spriteLEFTwalk2;

	SDL_Rect spriteRIGHTwalk1;
	SDL_Rect spriteRIGHTwalk2;


	//Determinar si se mueve
	bool moviendose;

	Direcciones direccion;




public:

	void setRectanguloSprite(SDL_Rect sprite);
	SDL_Rect getRectanguloSprite();
	void setRectangulo(SDL_Rect sprite);
	SDL_Rect getRectangulo();

	void setDireccion(Direcciones direccion);
	Direcciones getDireccion();

	void setPosicion(int x, int y);
	int getPosicionX();
	int getPosicionY();
	int getPosicionRealX();
	int getPosicionRealY();
	
	void setMoviendose();
	bool getMoviendose();

	void setPosicionRealX();
	void setPosicionRealY();

	int getMovimientos();
	void setMovimientos(int x);

	void reducirMovimiento();


	void update ();
	void draw();
	
	// Constructor de player.
	Player(const int &num);

	// Destructor de player.
	~Player();

};
