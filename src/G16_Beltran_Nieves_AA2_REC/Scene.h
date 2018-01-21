#pragma once
#include "Game.h"

enum estadoEscena { RUNNING, GOLEVEL1, GOLEVEL2, GORANK, GOMENU, EXIT };

class Scene
{
public:
	Scene();
	~Scene();

	// Funci�n encargada de controlar los eventos
	virtual void handleEvents() = 0;

	// Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	virtual void update() = 0;

	// Funci�n encargada de dibujar la escena.
	virtual void draw() = 0;

	estadoEscena getSceneState();
};





//#pragma once
//#include "Renderer.h"
//#include "Constants.h"
//#include <unordered_map>
//#include <queue>
//#include <iostream>
//#include <sstream>
//#include <SDL_mixer.h>
//#include "../../dep/inc/XML/rapidxml.hpp"
//#include "../../dep/inc/XML/rapidxml_utils.hpp"
//#include "../../dep/inc/XML/rapidxml_iterators.hpp"
//#include "../../dep/inc/XML/rapidxml_print.hpp"
//#ifndef SCENE_H
//#define SCENE_H
//// Classe que far� de superclasse a Level,Menu i Ranking, permeten aix� que aprofitem el polimorfisme.
//
//// Enum amb el que sabrem en quin estat es troba la nostra escena.
//enum SceneStates { RUNNING, GORANK, GOLEVEL1, GOLEVEL2, GOMENU, EXIT };
//
//struct playerRank
//{
//	int score;
//	std::string name;
//	bool operator<(const playerRank& rhs) const
//	{
//		return score < rhs.score;
//	}
//};
//
//class Scene
//{
//protected:
//
//	// Variable amb la que controlarem l'estat actual de l'escena.
//	SceneStates currentSceneState;
//
//	//// Priority queue en que guardarem el ranking de jugadors.
//	static std::priority_queue<playerRank> topPlayers;
//
//	// Variable en la que guardarem el rect del BG. La guardarem com a static, ja que hi accedirem en cada una de les escenes i aix� no l'haurem de canviar.
//	const SDL_Rect bgRect{ 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
//
//	// Variable amb la que sabrem si s'ha d'activar o no la m�sica.
//	static bool musicOn;
//
//public:
//
//	// Constructor.
//	Scene();
//
//	// Destructor.
//	~Scene();
//
//	// Funci� per a modificar musicOn.
//	static void startMusicOn();
//
//	// Func�o encarregada del control d'events. �s una funci� virtual pura, de manera que no farem el seu cos.
//	virtual void handleEvents() = 0;
//
//	// Funci� encarregada d'actualitzar l'escena segons els inputs del jugador / events que passin. �s una funci� virtual pura, de manera que no farem el seu cos.
//	virtual void update() = 0;
//
//	// Funci� encarregada de dibuixar l'escena en pantalla. �s una funci� virtual pura, de manera que no farem el seu cos.
//	virtual void draw() = 0;
//
//	// Funci� que retornar� l'estat actual de l'escena.
//	SceneStates getSceneState();
//
//	// Funci� per a inicialitzar topPlayers.
//	void initTopPlayers();
//};
//#endif
