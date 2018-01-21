#pragma once
#include "Types.h"
class Button
{
private:

	// Rectangulo que contiene la altura y la anchura de un bot�n as� como su X e Y
	SDL_Rect rectanguloBoton;

public:
	Button();
	~Button();

	// Funci�n que devuelve si el rat�n est� o no sobre el bot�n
	bool ratonSobreBoton(int &xRaton, int &yRaton);

	// Funci�n que devuelve el rectanguloBoton del bot�n
	SDL_Rect devolverRectangulo();

	//Funcio que inicialitzara el boto quan creem l'objecte boto des de menu.
	Button inicializarBoton(SDL_Rect &nuevoRectangulo);

};







