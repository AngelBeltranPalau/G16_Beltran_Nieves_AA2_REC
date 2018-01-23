#include "Player.h"



Player::Player()
{
	if(numJugador == 1)
		Renderer::Instance()->LoadTexture("Jugador", "../../res/img/player.png");
	else if(numJugador == 2)
		Renderer::Instance()->LoadTexture("Jugador", "../../res/img/player2.png");
	RectanguloSprite = { 0,0, posicionX, posicionY};

}


Player::~Player()
{

}

SDL_Rect Player::getRectanguloSprite()
{
	return RectanguloSprite;
}

SDL_Rect Player::getRectangulo()
{
	return Rectangulo;
}

void Player::setDireccion(Direcciones dir)
{
	direccion = dir;
}
Direcciones Player::getDireccion()
{
	return direccion;
}


void Player::setRectanguloSprite(SDL_Rect rect) 
{
	RectanguloSprite = rect;
}

void Player::setRectangulo(SDL_Rect rect)
{
	Rectangulo = rect;
}

void Player::draw() 
{

}