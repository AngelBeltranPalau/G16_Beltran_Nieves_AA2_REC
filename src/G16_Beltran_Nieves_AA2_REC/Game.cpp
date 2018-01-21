#include <iostream>
#include "Game.h"



Game::Game()
{
	//Al iniciar el juego lo hacemos en la escena MENU
	estadoActual = estadoJuego::MENU;
	escenaActual = new Menu;

	while (escenaActual->getSceneState != estadoEscena::EXIT)
	{
		if (escenaActual->getSceneState == RUNNING)
		{
			escenaActual->
		}
	}

}


Game::~Game()
{
}




#include "Game.h"
#include <iostream>

Game::Game()
{
	// Iniciem el joc al men�.
	myScene->initTopPlayers();
	myScene->startMusicOn();
	myScene = new Menu;
	gameState = GameStates::MENU;
	// Inicialitzem topPlayers.

	// Loop del nostre joc.
	while (myScene->getSceneState() != SceneStates::EXIT)
	{
		// Si la nostra scene actual est� en RUNNING cridarem les seves funcions de control de joc.
		if (myScene->getSceneState() == SceneStates::RUNNING)
		{
			myScene->handleEvents();
			myScene->update();
			myScene->draw();
		}
		// Si la nostra scene actual est� en GOLEVEL1 es far� el canvi d'escena.
		if (myScene->getSceneState() == SceneStates::GOLEVEL1)
		{
			delete myScene;
			gameState = GameStates::LEVEL;
			myScene = new Level(1);
		}
		// Si la nostra scene actual est� en GOLEVEL2 es far� el canvi d'escena.
		if (myScene->getSceneState() == SceneStates::GOLEVEL2)
		{
			delete myScene;
			gameState = GameStates::LEVEL;
			myScene = new Level(2);
		}
		// Si la nostra scene actual est� en GOMENU es far� el canvi d'escena.
		if (myScene->getSceneState() == SceneStates::GOMENU)
		{
			delete myScene;
			gameState = GameStates::MENU;
			myScene = new Menu;
		}
		// Si la nostra scene actual est� en GORANK es far� el canvi d'escena.
		if (myScene->getSceneState() == SceneStates::GORANK)
		{
			delete myScene;
			gameState = GameStates::RANKING;
			myScene = new Ranking;
		}
	}
}

Game::~Game()
{

}

