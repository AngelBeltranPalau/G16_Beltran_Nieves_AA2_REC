#include "Renderer.h"
#include "Constants.h"
#include <math.h>

#pragma once


// Enum con todas las direcciones que puede tomar el jugador.
enum Direcciones { UP, LEFT, DOWN, RIGHT, NONE };


class Player
{
private:

	//Determinar se es el jugador 1 o 2
	int numJugador;

	//Movimientos restantes del jugador
	int movimientos;

	//Coordenadas de la posición hacia la que va el jugador
	int posicionX, posicionY;

	//Coordenadas de la posición actual del jugador
	float posicionRealX, posicionRealY;

	//Rectangulo del sprite jugador
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

	// Rectángulo que se iguala al Sprite que se imprime
	SDL_Rect spriteImpreso;


	//Determinar si se mueve
	bool moviendose;

	//Dirección actual del jugador
	Direcciones direccion;

	// Contador de tiempo para los sprites y booleano de cambio de sprite
	int contadorSprite;
	bool cambioSprite;


public:

	// Determinar el sprite que debe imprimirse al llegar a la posición objetivo
	void setSpriteImpreso(Direcciones dir);

	// Va actualizando el sprite del jugador conforme camina en función de la dirección
	void setSpriteMovimiento(Direcciones dir);

	//Determinar y obtener la dirección hacia la que se desplaza el jugador
	void setDireccion(Direcciones direccion);
	Direcciones getDireccion();

	//Determinar y obtener la posición hacia la que se desplaza el jugador
	void setPosicion(int x, int y);
	int getPosicionX();
	int getPosicionY();

	//Determinar y obtener la posición actual del jugador
	void setPosicionRealX();
	void setPosicionRealY();
	int getPosicionRealX();
	int getPosicionRealY();
	
	//Determinar y obtener si el jugador se está desplazando o no
	void setMoviendose();
	bool getMoviendose();
	
	//Determinar y obtenerlos movimientos del jugador
	int getMovimientos();
	void setMovimientos(int x);

	//Reducir los movimientos restantes del jugadors si este se ha desplazado
	void reducirMovimiento();

	// Función encargada de actualizar la escena en función de los eventos que sucedan y de los inputs del jugador
	void update();

	// Función encargada de dibujar la escena
	void draw();
	
	// Constructor de player.
	Player(const int &num);

	// Destructor de player.
	~Player();

};
