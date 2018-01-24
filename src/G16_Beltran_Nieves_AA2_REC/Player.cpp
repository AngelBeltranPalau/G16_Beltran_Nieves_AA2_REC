#include "Player.h"
#include <iostream>

//Constructor del player
Player::Player(const int &num)
{
	numJugador = num;

	posicionRealX = posicionX;
	posicionRealY = posicionY;

	moviendose = false;

	direccion = Direcciones::NONE;

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

//Determina la direccion del jugador 
void Player::setDireccion(Direcciones dir)
{
	direccion = dir;
}

//Devuelve la direccion del jugador
Direcciones Player::getDireccion()
{
	return direccion;
}

//Determina la posici�n destino del jugador
void Player::setPosicion(int x, int y)
{
	posicionX = x;
	posicionY = y;
}

//Determina la X de la posici�n actual del jugador
void Player::setPosicionRealX()
{
	posicionRealX = posicionX + 1;
}

//Determina la Y de la posici�n actual del jugador
void Player::setPosicionRealY()
{
	posicionRealY = posicionY + 1;
}

//Devuelve la X de la posici�n destino del jugador
int Player::getPosicionX()
{
	return posicionX;
}

//Devuelve la Y de la posici�n destino del jugador
int Player::getPosicionY()
{
	return posicionY;
}

//Devuelve la X de la posici�n actual del jugador
int Player::getPosicionRealX()
{
	return posicionRealX;
}
//Devuelve la Y de la posici�n actual del jugador
int Player::getPosicionRealY()
{
	return posicionRealY;
}

//Determina si el jugador se esta desplazando
void Player::setMoviendose()
{
	moviendose = true;
}

//Devuleve si el jugador se est� desplazando
bool Player::getMoviendose()
{
	return moviendose;
}

//Determina los movimientos restantes del jugador
void Player::setMovimientos(int x)
{
	movimientos = x;
}

//Devuelve los movimientos restantes del jugador
int Player::getMovimientos()
{
	return movimientos;
}

//Reduce los movimietnos restantes del jugador
void Player::reducirMovimiento()
{
	movimientos--;
}


//Determina el rectandulo de sprite del jugador
void Player::setRectanguloSprite(SDL_Rect rect) 
{
	RectanguloSprite = rect;
}


//Dibuja por pantalla el jugador
void Player::draw() 
{
	if (numJugador == 1)
	{
		RectanguloSprite.x = 0 + (posicionRealX)*TAMA�O_SPRITE * 3 / 2 + 12;
		RectanguloSprite.y = 80 + (posicionRealY)*TAMA�O_SPRITE * 3 / 2 + 12;

		Renderer::Instance()->PushSprite("Jugador1", spriteLEFTidle, RectanguloSprite);
	}
	if (numJugador == 2)
	{
		RectanguloSprite.x = 0 + (posicionRealX)*TAMA�O_SPRITE * 3 / 2 + 12;
		RectanguloSprite.y = 80 + (posicionRealY)*TAMA�O_SPRITE * 3 / 2 + 12;

		Renderer::Instance()->PushSprite("Jugador2", spriteLEFTidle, RectanguloSprite);
	}
}


//Actualiza las variables del jugador
void Player::update()
{
		float auxX = posicionX - (posicionRealX);
		float auxY = (posicionY)-(posicionRealY);


		if (direccion == Direcciones::UP)
		{
			if (auxY < -0.05)
				posicionRealY -= 0.05;
			else
			{
				direccion = Direcciones::NONE;
				posicionRealY = posicionY;
				moviendose = false;
			}
		}

		if (direccion == Direcciones::DOWN)
		{
			if (auxY > 0.05)
				posicionRealY += 0.05;
			else
			{
				direccion = Direcciones::NONE;
				posicionRealY = posicionY;
				moviendose = false;
			}
		}


		if (direccion == Direcciones::RIGHT)
		{
			if (auxX > 0.05)
				posicionRealX += 0.05;
			else
			{
				direccion = Direcciones::NONE;
				posicionRealX = posicionX;
				moviendose = false;
			}
		}

		if (direccion == Direcciones::LEFT)
		{
			if (auxX < -0.05)
				posicionRealX -= 0.05;
			else
			{
				direccion = Direcciones::NONE;
				posicionRealX = posicionX;
				moviendose = false;
			}
		}

}