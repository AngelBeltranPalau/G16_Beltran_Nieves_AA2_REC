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


void Player::setRectanguloSprite(SDL_Rect sprite) 
{
	RectanguloSprite = sprite;
}

void handleEvents() 
{

}

void draw() 
{

}