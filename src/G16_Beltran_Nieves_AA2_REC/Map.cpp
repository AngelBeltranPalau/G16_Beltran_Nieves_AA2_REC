#include "Map.h"
#include <iostream>



Map::Map()
{


	// Cargamos la imagen de los items
	Renderer::Instance()->LoadTexture("Items", "../../res/img/items.png");
	rectItems = { 0,0,TAMAÑO_SPRITE* 3 / 2,TAMAÑO_SPRITE* 3 / 2 };

	hielo = { 0, 0, TAMAÑO_SPRITE, TAMAÑO_SPRITE };
	muro = { TAMAÑO_SPRITE, 0, TAMAÑO_SPRITE, TAMAÑO_SPRITE, };
	solucionVerde = { 0, TAMAÑO_SPRITE, TAMAÑO_SPRITE, TAMAÑO_SPRITE };
	solucionRoja = { TAMAÑO_SPRITE, TAMAÑO_SPRITE, TAMAÑO_SPRITE, TAMAÑO_SPRITE };



}


Map::~Map()
{
}

std::vector<SDL_Rect> Map::devolverRectOcupado()
{
	return rectOcupado;
}

void Map::inicializarRectOcupado()
{
	for (int y = 0; y<Y_MAPA; y++)
	{
		for (int x = 0; x<X_MAPA; x++)
		{
			rectItems.x = 0 + x*TAMAÑO_SPRITE;
			rectItems.y = TAMAÑO_SPRITE + y*TAMAÑO_SPRITE;

			if (tablaPosiciones[{x, y}] == "MURO")
			{
				rectOcupado.push_back(rectItems);
				rectOcupadoX.push_back(x);
				rectOcupadoY.push_back(y);
			}
		}
	}
}

std::string Map::devolverContenidoPosicion(/*const*/ int & x, /*const*/ int & y)
{
	return tablaPosiciones[{x, y}];
}

void Map::añadirPosicionOcupada(const SDL_Rect & r)
{
	rectOcupado.push_back(r);
}

void Map::añadirItem(const std::string & i, const int & k1, const int & k2)
{
	tablaPosiciones[{k1, k2}] = i;
}

void Map::setGanadorRojo(int x, int y)
{
	ganadorRojoX = x;
	ganadorRojoY = y;
}

void Map::setGanadorVerde(int x, int y)
{
	ganadorVerdeX = x;
	ganadorVerdeY = y;
}

int Map::getGanadorRojoX()
{
	return ganadorRojoX;
}

int Map::getGanadorRojoY()
{
	return ganadorRojoY;
}

int Map::getGanadorVerdeX()
{
	return ganadorVerdeX;
}

int Map::getGanadorVerdeY()
{
	return ganadorVerdeY;
}


void Map::update()
{
}

void Map::draw()
{
	// Recorrem l'unordered map table en la seva totalitat.
	for (int y = 0; y<Y_MAPA; y++)
	{
		for (int x = 0; x < X_MAPA; x++)
		{
			// Actualitzem les variables per a així anar imprimint els obstacles/items quan fagi falta.
			rectItems.x = 0 + x*TAMAÑO_SPRITE* 3 / 2;
			rectItems.y = 80 + y*TAMAÑO_SPRITE* 3 / 2;
			// Si l'element x,y de table és buit, no imprimirem res.
			// Pels altres casos, imprimirem el que toqui.
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

