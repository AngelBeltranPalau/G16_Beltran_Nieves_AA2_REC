#pragma once
#include "Types.h"
class Button
{
private:

	// Rectangulo que contiene la altura y la anchura de un botón así como su X e Y
	SDL_Rect rectanguloBoton;

public:
	Button();
	~Button();

	// Función que devuelve si el ratón está o no sobre el botón
	bool ratonSobreBoton(int &xRaton, int &yRaton);

	// Función que devuelve el rectanguloBoton del botón
	SDL_Rect devolverRectangulo();

	//Funcio que inicialitzara el boto quan creem l'objecte boto des de menu.
	Button inicializarBoton(SDL_Rect &nuevoRectangulo);

};







