#include "Map.h"
#include <iostream>



Map::Map()
{


	// Cargamos la imagen de los items
	Renderer::Instance()->LoadTexture("Items", "../../res/img/items.png");
	rectItems = { 0,0,TAMA�O_SPRITE,TAMA�O_SPRITE };

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
	for (int y = 0; y<8; y++)
	{
		for (int x = 0; x<6; x++)
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

std::string Map::devolverContenidoPosicion(const int & x, const int & y)
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


void Map::update()
{
}

void Map::draw()
{
	// Recorrem l'unordered map table en la seva totalitat.
	for (int y = 0; y<8; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			// Actualitzem les variables per a aix� anar imprimint els obstacles/items quan fagi falta.
			rectItems.x = 0 + x*TAMA�O_SPRITE;
			rectItems.y = TAMA�O_SPRITE + y*TAMA�O_SPRITE;
			// Si l'element x,y de table �s buit, no imprimirem res.
			// Pels altres casos, imprimirem el que toqui.
			if (tablaPosiciones[{x, y}] == "MURO")
			{
				Renderer::Instance()->PushSprite("items", muro, rectItems);
			}
			else if (tablaPosiciones[{x, y}] == "HIELO")
			{
				Renderer::Instance()->PushSprite("items", hielo, rectItems);
			}
			else if (tablaPosiciones[{x, y}] == "SOLUCION_VERDE")
			{
				Renderer::Instance()->PushSprite("items", solucionVerde, rectItems);
			}
			else if (tablaPosiciones[{x, y}] == "SOLUCION_ROJO")
			{
				Renderer::Instance()->PushSprite("items", solucionRoja, rectItems);
			}
		}
	}
}

