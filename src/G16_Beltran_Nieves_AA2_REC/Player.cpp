#include "Player.h"
#include <iostream>

//Constructor del player
Player::Player(const int &num)
{
	numJugador = num;
	contadorSprite = 0;
	cambioSprite = false;

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

	spriteImpreso = spriteDOWNidle;

}


Player::~Player()
{

}

void Player::setSpriteImpreso(Direcciones dir)
{

	if (dir == Direcciones::DOWN)
	{
		spriteImpreso = spriteDOWNidle;
	}
	else if (dir == Direcciones::UP)
	{
		spriteImpreso = spriteUPidle;
	}
	else if (dir == Direcciones::LEFT)
	{
		spriteImpreso = spriteLEFTidle;
	}
	else if (dir == Direcciones::RIGHT)
	{
		spriteImpreso = spriteRIGHTidle;
	}
}

void Player::setSpriteMovimiento(Direcciones dir)
{
	if (contadorSprite < VELOCIDAD_SPRITE)
	{
		contadorSprite++;
	}
	else
	{
		cambioSprite = !cambioSprite;
		contadorSprite = 0;
	}


	if (dir == Direcciones::DOWN)
	{
		if(cambioSprite == false)
			spriteImpreso = spriteDOWNwalk1;
		else
			spriteImpreso = spriteDOWNwalk2;
	}
	else if (dir == Direcciones::UP)
	{
		if (cambioSprite == false)
			spriteImpreso = spriteUPwalk1;
		else
			spriteImpreso = spriteUPwalk2;
	}
	else if (dir == Direcciones::LEFT)
	{
		if (cambioSprite == false)
			spriteImpreso = spriteLEFTwalk1;
		else
			spriteImpreso = spriteLEFTwalk2;
	}
	else if (dir == Direcciones::RIGHT)
	{
		if (cambioSprite == false)
			spriteImpreso = spriteRIGHTwalk1;
		else
			spriteImpreso = spriteRIGHTwalk2;
	}

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


//Actualiza las variables del jugador
void Player::update()
{
		float auxX = posicionX - (posicionRealX);
		float auxY = (posicionY)-(posicionRealY);


			if (direccion == Direcciones::UP)
			{
				if (auxY < -0.05)
				{
					posicionRealY -= 0.05;
					setSpriteMovimiento(Direcciones::UP);
				}
				else
				{
					direccion = Direcciones::NONE;
					setSpriteImpreso(Direcciones::UP);
					posicionRealY = posicionY;
					moviendose = false;
				}
			}

			if (direccion == Direcciones::DOWN)
			{
				if (auxY > 0.05)
				{
					posicionRealY += 0.05;
					setSpriteMovimiento(Direcciones::DOWN);
				}
				else
				{
					direccion = Direcciones::NONE;
					setSpriteImpreso(Direcciones::DOWN);
					posicionRealY = posicionY;
					moviendose = false;
				}
			}


			if (direccion == Direcciones::RIGHT)
			{
				if (auxX > 0.05)
				{
					posicionRealX += 0.05;
					setSpriteMovimiento(Direcciones::RIGHT);
				}
				else
				{
					direccion = Direcciones::NONE;
					setSpriteImpreso(Direcciones::RIGHT);
					posicionRealX = posicionX;
					moviendose = false;
				}
			}

			if (direccion == Direcciones::LEFT)
			{
				if (auxX < -0.05)
				{
					posicionRealX -= 0.05;
					setSpriteMovimiento(Direcciones::LEFT);
				}
				else
				{
					direccion = Direcciones::NONE;
					setSpriteImpreso(Direcciones::LEFT);
					posicionRealX = posicionX;
					moviendose = false;
				}
			}
}


//Dibuja por pantalla el jugador
void Player::draw()
{
	if (numJugador == 1)
	{
		RectanguloSprite.x = 0 + (posicionRealX)*TAMA�O_SPRITE * 3 / 2 + 12;
		RectanguloSprite.y = 80 + (posicionRealY)*TAMA�O_SPRITE * 3 / 2 + 12;

		Renderer::Instance()->PushSprite("Jugador1", spriteImpreso, RectanguloSprite);
	}
	if (numJugador == 2)
	{
		RectanguloSprite.x = 0 + (posicionRealX)*TAMA�O_SPRITE * 3 / 2 + 12;
		RectanguloSprite.y = 80 + (posicionRealY)*TAMA�O_SPRITE * 3 / 2 + 12;

		Renderer::Instance()->PushSprite("Jugador2", spriteImpreso, RectanguloSprite);
	}
}