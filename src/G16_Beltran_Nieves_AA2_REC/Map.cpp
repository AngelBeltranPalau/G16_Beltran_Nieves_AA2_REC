#include "Map.h"
#include <iostream>



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

std::string Map::devolverContenidoPosicion(/*const*/ int & x, /*const*/ int & y)
{
	return tablaPosiciones[{x, y}];
}

void Map::a�adirPosicionOcupada(const SDL_Rect & r)
{
	rectOcupado.push_back(r);
}

void Map::a�adirItem(const std::string & i, const int & k1, const int & k2)
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
			// Actualitzem les variables per a aix� anar imprimint els obstacles/items quan fagi falta.
			rectItems.x = 0 + x*TAMA�O_SPRITE* 3 / 2;
			rectItems.y = 80 + y*TAMA�O_SPRITE* 3 / 2;
			// Si l'element x,y de table �s buit, no imprimirem res.
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

