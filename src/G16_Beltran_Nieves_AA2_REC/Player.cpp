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

//Determina la posición destino del jugador
void Player::setPosicion(int x, int y)
{
	posicionX = x;
	posicionY = y;
}

//Determina la X de la posición actual del jugador
void Player::setPosicionRealX()
{
	posicionRealX = posicionX + 1;
}

//Determina la Y de la posición actual del jugador
void Player::setPosicionRealY()
{
	posicionRealY = posicionY + 1;
}

//Devuelve la X de la posición destino del jugador
int Player::getPosicionX()
{
	return posicionX;
}

//Devuelve la Y de la posición destino del jugador
int Player::getPosicionY()
{
	return posicionY;
}

//Devuelve la X de la posición actual del jugador
int Player::getPosicionRealX()
{
	return posicionRealX;
}
//Devuelve la Y de la posición actual del jugador
int Player::getPosicionRealY()
{
	return posicionRealY;
}

//Determina si el jugador se esta desplazando
void Player::setMoviendose()
{
	moviendose = true;
}

//Devuleve si el jugador se está desplazando
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
		RectanguloSprite.x = 0 + (posicionRealX)*TAMAÑO_SPRITE * 3 / 2 + 12;
		RectanguloSprite.y = 80 + (posicionRealY)*TAMAÑO_SPRITE * 3 / 2 + 12;

		Renderer::Instance()->PushSprite("Jugador1", spriteLEFTidle, RectanguloSprite);
	}
	if (numJugador == 2)
	{
		RectanguloSprite.x = 0 + (posicionRealX)*TAMAÑO_SPRITE * 3 / 2 + 12;
		RectanguloSprite.y = 80 + (posicionRealY)*TAMAÑO_SPRITE * 3 / 2 + 12;

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