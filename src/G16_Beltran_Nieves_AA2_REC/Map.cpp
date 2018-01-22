#include "Map.h"
#include <iostream>



Map::Map()
{


	// Cargamos la imagen de los items
	Renderer::Instance()->LoadTexture("Items", "../../res/img/items.png");
	rectItems = { 0,0,TAMAÑO_SPRITE,TAMAÑO_SPRITE };

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
	for (int y = 0; y<8; y++)
	{
		for (int x = 0; x<6; x++)
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

std::string Map::devolverContenidoPosicion(const int & x, const int & y)
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
			// Actualitzem les variables per a així anar imprimint els obstacles/items quan fagi falta.
			rectItems.x = 0 + x*TAMAÑO_SPRITE;
			rectItems.y = TAMAÑO_SPRITE + y*TAMAÑO_SPRITE;
			// Si l'element x,y de table és buit, no imprimirem res.
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

