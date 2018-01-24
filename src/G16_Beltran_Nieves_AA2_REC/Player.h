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

	//Coordenadas de la posici�n hacia la que va el jugador
	int posicionX, posicionY;

	//Coordenadas de la posici�n actual del jugador
	float posicionRealX, posicionRealY;

	//Rectangulo del sprite jugador
	SDL_Rect RectanguloSprite;

	//Rectangulo para cada direcci�n del Sprite
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

	// Rect�ngulo que se iguala al Sprite que se imprime
	SDL_Rect spriteImpreso;


	//Determinar si se mueve
	bool moviendose;

	//Direcci�n actual del jugador
	Direcciones direccion;

	// Contador de tiempo para los sprites y booleano de cambio de sprite
	int contadorSprite;
	bool cambioSprite;


public:

	// Determinar el sprite que debe imprimirse al llegar a la posici�n objetivo
	void setSpriteImpreso(Direcciones dir);

	// Va actualizando el sprite del jugador conforme camina en funci�n de la direcci�n
	void setSpriteMovimiento(Direcciones dir);

	//Determinar y obtener la direcci�n hacia la que se desplaza el jugador
	void setDireccion(Direcciones direccion);
	Direcciones getDireccion();

	//Determinar y obtener la posici�n hacia la que se desplaza el jugador
	void setPosicion(int x, int y);
	int getPosicionX();
	int getPosicionY();

	//Determinar y obtener la posici�n actual del jugador
	void setPosicionRealX();
	void setPosicionRealY();
	int getPosicionRealX();
	int getPosicionRealY();
	
	//Determinar y obtener si el jugador se est� desplazando o no
	void setMoviendose();
	bool getMoviendose();
	
	//Determinar y obtenerlos movimientos del jugador
	int getMovimientos();
	void setMovimientos(int x);

	//Reducir los movimientos restantes del jugadors si este se ha desplazado
	void reducirMovimiento();

	// Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	void update();

	// Funci�n encargada de dibujar la escena
	void draw();
	
	// Constructor de player.
	Player(const int &num);

	// Destructor de player.
	~Player();

};
