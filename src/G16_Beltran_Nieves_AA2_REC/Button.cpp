#include "Button.h"



Button::Button()
{
}


Button::~Button()
{
}

bool Button::ratonSobreBoton(int &xRaton, int &yRaton)
{
	return (xRaton >= rectanguloBoton.x && yRaton >= rectanguloBoton.y && xRaton <= rectanguloBoton.x + rectanguloBoton.w && yRaton <= rectanguloBoton.y + rectanguloBoton.h);
}

SDL_Rect Button::devolverRectangulo()
{
	return rectanguloBoton;
}

Button Button::inicializarBoton(SDL_Rect &nuevoRectangulo)
{
	Button aux;
	aux.rectanguloBoton.w = nuevoRectangulo.w;
	aux.rectanguloBoton.h = nuevoRectangulo.h;
	aux.rectanguloBoton.x = nuevoRectangulo.x;
	aux.rectanguloBoton.y = nuevoRectangulo.y;
	return aux;
}
