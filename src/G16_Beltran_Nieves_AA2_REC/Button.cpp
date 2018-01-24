#include "Button.h"


//Constructor bot�n
Button::Button()
{
}

//Destrustor bot�n
Button::~Button()
{
}

//Devuleve un booleano que indica si el rat�n esta sobre el rectangulo del bot�n
bool Button::ratonSobreBoton(int &xRaton, int &yRaton)
{
	return (xRaton >= rectanguloBoton.x && yRaton >= rectanguloBoton.y && xRaton <= rectanguloBoton.x + rectanguloBoton.w && yRaton <= rectanguloBoton.y + rectanguloBoton.h);
}

//Devuelve el rectangulo del bot�n
SDL_Rect Button::devolverRectangulo()
{
	return rectanguloBoton;
}

//Da los valores al bot�n
Button Button::inicializarBoton(SDL_Rect &nuevoRectangulo)
{
	Button aux;
	aux.rectanguloBoton.w = nuevoRectangulo.w;
	aux.rectanguloBoton.h = nuevoRectangulo.h;
	aux.rectanguloBoton.x = nuevoRectangulo.x;
	aux.rectanguloBoton.y = nuevoRectangulo.y;
	return aux;
}
