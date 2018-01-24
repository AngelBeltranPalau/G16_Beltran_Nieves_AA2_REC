#include "Button.h"


//Constructor botón
Button::Button()
{
}

//Destrustor botón
Button::~Button()
{
}

//Devuleve un booleano que indica si el ratón esta sobre el rectangulo del botón
bool Button::ratonSobreBoton(int &xRaton, int &yRaton)
{
	return (xRaton >= rectanguloBoton.x && yRaton >= rectanguloBoton.y && xRaton <= rectanguloBoton.x + rectanguloBoton.w && yRaton <= rectanguloBoton.y + rectanguloBoton.h);
}

//Devuelve el rectangulo del botón
SDL_Rect Button::devolverRectangulo()
{
	return rectanguloBoton;
}

//Da los valores al botón
Button Button::inicializarBoton(SDL_Rect &nuevoRectangulo)
{
	Button aux;
	aux.rectanguloBoton.w = nuevoRectangulo.w;
	aux.rectanguloBoton.h = nuevoRectangulo.h;
	aux.rectanguloBoton.x = nuevoRectangulo.x;
	aux.rectanguloBoton.y = nuevoRectangulo.y;
	return aux;
}
