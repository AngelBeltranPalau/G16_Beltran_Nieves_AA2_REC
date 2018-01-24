#include <iostream>
#include "Game.h"

Game::Game()
{
	//Al iniciar el juego lo hacemos en la escena MENU
	estadoActual = estadoJuego::MENU;
	escenaActual = new Menu;
	escenaActual->iniciarTopPlayer();

	while (escenaActual->getEstadoEscena() != estadoEscena::EXIT)
	{
		// Si el estado de la escena actual es Running, se llaman las funciones HandleEvent, Update y Draw
		if (escenaActual->getEstadoEscena() == RUNNING)
		{
			escenaActual->handleEvents();
			escenaActual->update();
			escenaActual->draw();
		}
		// Si el estado de la escena actual es GOTOLEVEL1, se cambia la escena actual a Level(1)
		if (escenaActual->getEstadoEscena() == estadoEscena::GOLEVEL1)
		{
			delete escenaActual;
			estadoActual = estadoJuego::LEVEL;
			escenaActual = new Level(1);
		}
		// Si el estado de la escena actual es GOTOLEVEL2, se cambia la escena actual a Level(2)
		if (escenaActual->getEstadoEscena() == estadoEscena::GOLEVEL2)
		{
			delete escenaActual;
			estadoActual = estadoJuego::LEVEL;
			escenaActual = new Level(2);
		}
		// Si el estado de la escena actual es GOMENU, se cambia la escena actual a Menu
		if (escenaActual->getEstadoEscena() == estadoEscena::GOMENU)
		{
			delete escenaActual;
			estadoActual = estadoJuego::MENU;
			escenaActual = new Menu;
		}
		// Si el estado de la escena actual es GORANK, se cambia la escena actual a Ranking
		if (escenaActual->getEstadoEscena() == estadoEscena::GORANK)
		{
			delete escenaActual;
			estadoActual = estadoJuego::RANKING;
			escenaActual = new Ranking;
		}
	}
}



Game::~Game()
{
}


