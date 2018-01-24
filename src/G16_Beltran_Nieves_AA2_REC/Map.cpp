#include "Map.h"
#include <iostream>


//Constructor del mapa
Map::Map()
{


	// Cargamos la imagen de los items
	Renderer::Instance()->LoadTexture("Items", "../../res/img/items.png");
	rectItems = { 0,0,TAMA�O_SPRITE* 3 / 2,TAMA�O_SPRITE* 3 / 2 };

	hielo = { 0, 0, TAMA�O_SPRITE, TAMA�O_SPRITE };
	muro = { TAMA�O_SPRITE, 0, TAMA�O_SPRITE, TAMA�O_SPRITE, };
	solucionVerde = { 0, TAMA�O_SPRITE, TAMA�O_SPRITE, TAMA�O_SPRITE };
	solucionRoja = { TAMA�O_SPRITE, TAMA�O_SPRITE, TAMA�O_SPRITE, TAMA�O_SPRITE };



}

//Destructor del mapa
Map::~Map()
{
}

//Devuelve el vector con los rectangulos ocupados
std::vector<SDL_Rect> Map::devolverRectOcupado()
{
	return rectOcupado;
}

//Inicializa el vector con los rectangulos ocupados
void Map::inicializarRectOcupado()
{
	for (int y = 0; y<Y_MAPA; y++)
	{
		for (int x = 0; x<X_MAPA; x++)
		{
			rectItems.x = 0 + x*TAMA�O_SPRITE;
			rectItems.y = TAMA�O_SPRITE + y*TAMA�O_SPRITE;

			if (tablaPosiciones[{x, y}] == "MURO")
			{
				rectOcupado.push_back(rectItems);
				rectOcupadoX.push_back(x);
				rectOcupadoY.push_back(y);
			}
		}
	}
}

//Devuelve el contenido de las coordenadas dadads
std::string Map::devolverContenidoPosicion( int & x,  int & y)
{
	return tablaPosiciones[{x, y}];
}

//A�ade posicion ocupada
void Map::a�adirPosicionOcupada(const SDL_Rect & r)
{
	rectOcupado.push_back(r);
}

//A�ade item
void Map::a�adirItem(const std::string & i, const int & k1, const int & k2)
{
	tablaPosiciones[{k1, k2}] = i;
}

//Determina cuadrado de meta rojo
void Map::setGanadorRojo(int x, int y)
{
	ganadorRojoX = x;
	ganadorRojoY = y;
}

//Determina cuadrado de meta verde
void Map::setGanadorVerde(int x, int y)
{
	ganadorVerdeX = x;
	ganadorVerdeY = y;
}

//Devuelve la X del cuadrado de meta rojo
int Map::getGanadorRojoX()
{
	return ganadorRojoX;
}

//Devuelve la Y del cuadrado de meta rojo
int Map::getGanadorRojoY()
{
	return ganadorRojoY;
}

//Devuelve la X del cuadrado de meta verde
int Map::getGanadorVerdeX()
{
	return ganadorVerdeX;
}

//Devuelve la Y del cuadrado de meta verde
int Map::getGanadorVerdeY()
{
	return ganadorVerdeY;
}



void Map::update()
{
}

//Dibuja el mapa en pantalla
void Map::draw()
{

	for (int y = 0; y<Y_MAPA; y++)
	{
		for (int x = 0; x < X_MAPA; x++)
		{
			rectItems.x = 0 + x*TAMA�O_SPRITE* 3 / 2;
			rectItems.y = 80 + y*TAMA�O_SPRITE* 3 / 2;
			
			if (tablaPosiciones[{x, y}] == "MURO")
			{
				Renderer::Instance()->PushSprite("Items", muro, rectItems);
			}
			else if (tablaPosiciones[{x, y}] == "HIELO")
			{
				Renderer::Instance()->PushSprite("Items", hielo, rectItems);
			}
			else if (tablaPosiciones[{x, y}] == "SOLUCION_VERDE")
			{
				Renderer::Instance()->PushSprite("Items", solucionVerde, rectItems);
			}
			else if (tablaPosiciones[{x, y}] == "SOLUCION_ROJO")
			{
				Renderer::Instance()->PushSprite("Items", solucionRoja, rectItems);
			}
		}
	}



}

