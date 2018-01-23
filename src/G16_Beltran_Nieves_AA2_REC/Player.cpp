#include "Player.h"



Player::Player(const int &num)
{
	numJugador = num;

	if (numJugador == 1)
		Renderer::Instance()->LoadTexture("Jugador1", "../../res/img/player.png");
	else if(numJugador == 2)
		Renderer::Instance()->LoadTexture("Jugador2", "../../res/img/player2.png");
	
	RectanguloSprite = { 0,0,TAMA�O_SPRITE ,TAMA�O_SPRITE };

	spriteUPidle = { TAMA�O_SPRITE, 0, TAMA�O_SPRITE, TAMA�O_SPRITE };
	spriteUPwalk1 = { 0, 0, TAMA�O_SPRITE, TAMA�O_SPRITE };
	spriteUPwalk2 = { TAMA�O_SPRITE * 2, 0, TAMA�O_SPRITE, TAMA�O_SPRITE };

	spriteDOWNidle = { TAMA�O_SPRITE, TAMA�O_SPRITE * 2, TAMA�O_SPRITE, TAMA�O_SPRITE};
	spriteDOWNwalk1 = { 0, TAMA�O_SPRITE * 2, TAMA�O_SPRITE, TAMA�O_SPRITE };
	spriteDOWNwalk2 = { TAMA�O_SPRITE * 2, TAMA�O_SPRITE * 2, TAMA�O_SPRITE, TAMA�O_SPRITE };

	spriteLEFTidle = { 0, TAMA�O_SPRITE, TAMA�O_SPRITE, TAMA�O_SPRITE };
	spriteLEFTwalk1 = { TAMA�O_SPRITE, TAMA�O_SPRITE, TAMA�O_SPRITE, TAMA�O_SPRITE };
	spriteLEFTwalk2 = { TAMA�O_SPRITE * 2, TAMA�O_SPRITE, TAMA�O_SPRITE, TAMA�O_SPRITE };

	spriteRIGHTidle = { 0, TAMA�O_SPRITE * 3, TAMA�O_SPRITE, TAMA�O_SPRITE };
	spriteRIGHTwalk1 = { TAMA�O_SPRITE , TAMA�O_SPRITE * 3, TAMA�O_SPRITE, TAMA�O_SPRITE };
	spriteRIGHTwalk2 = { TAMA�O_SPRITE * 2, TAMA�O_SPRITE * 3, TAMA�O_SPRITE, TAMA�O_SPRITE };


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
		RectanguloSprite.x = 0 + (posicionRealX + 1)*TAMA�O_SPRITE * 3 / 2 + 12;
		RectanguloSprite.y = 80 + (posicionRealY + 1)*TAMA�O_SPRITE * 3 / 2 + 12;

		Renderer::Instance()->PushSprite("Jugador1", spriteLEFTidle, RectanguloSprite);
	}
	if (numJugador == 2)
	{
		RectanguloSprite.x = 0 + (posicionRealX + 1)*TAMA�O_SPRITE * 3 / 2 + 12;
		RectanguloSprite.y = 80 + (posicionRealY + 1)*TAMA�O_SPRITE * 3 / 2 + 12;

		Renderer::Instance()->PushSprite("Jugador2", spriteLEFTidle, RectanguloSprite);
	}
}