#include "Player.h"



Player::Player(const int &num)
{
	numJugador = num;

	if (numJugador == 1)
		Renderer::Instance()->LoadTexture("Jugador1", "../../res/img/player.png");
	else if(numJugador == 2)
		Renderer::Instance()->LoadTexture("Jugador2", "../../res/img/player2.png");
	
	RectanguloSprite = { 0,0,TAMAÑO_SPRITE ,TAMAÑO_SPRITE };

	spriteUPidle = { TAMAÑO_SPRITE, 0, TAMAÑO_SPRITE, TAMAÑO_SPRITE };
	spriteUPwalk1 = { 0, 0, TAMAÑO_SPRITE, TAMAÑO_SPRITE };
	spriteUPwalk2 = { TAMAÑO_SPRITE * 2, 0, TAMAÑO_SPRITE, TAMAÑO_SPRITE };

	spriteDOWNidle = { TAMAÑO_SPRITE, TAMAÑO_SPRITE * 2, TAMAÑO_SPRITE, TAMAÑO_SPRITE};
	spriteDOWNwalk1 = { 0, TAMAÑO_SPRITE * 2, TAMAÑO_SPRITE, TAMAÑO_SPRITE };
	spriteDOWNwalk2 = { TAMAÑO_SPRITE * 2, TAMAÑO_SPRITE * 2, TAMAÑO_SPRITE, TAMAÑO_SPRITE };

	spriteLEFTidle = { 0, TAMAÑO_SPRITE, TAMAÑO_SPRITE, TAMAÑO_SPRITE };
	spriteLEFTwalk1 = { TAMAÑO_SPRITE, TAMAÑO_SPRITE, TAMAÑO_SPRITE, TAMAÑO_SPRITE };
	spriteLEFTwalk2 = { TAMAÑO_SPRITE * 2, TAMAÑO_SPRITE, TAMAÑO_SPRITE, TAMAÑO_SPRITE };

	spriteRIGHTidle = { 0, TAMAÑO_SPRITE * 3, TAMAÑO_SPRITE, TAMAÑO_SPRITE };
	spriteRIGHTwalk1 = { TAMAÑO_SPRITE , TAMAÑO_SPRITE * 3, TAMAÑO_SPRITE, TAMAÑO_SPRITE };
	spriteRIGHTwalk2 = { TAMAÑO_SPRITE * 2, TAMAÑO_SPRITE * 3, TAMAÑO_SPRITE, TAMAÑO_SPRITE };


}


Player::~Player()
{

}

//SDL_Rect Player::getRectanguloSprite()
//{
//	return RectanguloSprite;
//}
//
//SDL_Rect Player::getRectangulo()
//{
//	return Rectangulo;
//}

void Player::setDireccion(Direcciones dir)
{
	direccion = dir;
}
Direcciones Player::getDireccion()
{
	return direccion;
}

void Player::setPosicion(int x, int y)
{
	posicionX = x;
	posicionY = y;
}

int Player::getPosicionX()
{
	return posicionX;
}

int Player::getPosicionY()
{
	return posicionY;
}

void Player::setMoviendose(bool mov)
{
}

bool Player::getMoviendose()
{
	return false;
}


void Player::setRectanguloSprite(SDL_Rect rect) 
{
	RectanguloSprite = rect;
}

//void Player::setRectangulo(SDL_Rect rect)
//{
//	Rectangulo = rect;
//}

void Player::draw() 
{
	if (numJugador == 1)
	{
		RectanguloSprite.x = 0 + (posicionRealX + 1)*TAMAÑO_SPRITE * 3 / 2 + 12;
		RectanguloSprite.y = 80 + (posicionRealY + 1)*TAMAÑO_SPRITE * 3 / 2 + 12;

		Renderer::Instance()->PushSprite("Jugador1", spriteLEFTidle, RectanguloSprite);
	}
	if (numJugador == 2)
	{
		RectanguloSprite.x = 0 + (posicionRealX + 1)*TAMAÑO_SPRITE * 3 / 2 + 12;
		RectanguloSprite.y = 80 + (posicionRealY + 1)*TAMAÑO_SPRITE * 3 / 2 + 12;

		Renderer::Instance()->PushSprite("Jugador2", spriteLEFTidle, RectanguloSprite);
	}
}