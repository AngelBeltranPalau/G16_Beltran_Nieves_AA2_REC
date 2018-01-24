#pragma once
#include "Renderer.h"
#include "Constants.h"
#include <unordered_map>
#include <queue>
#include <iostream>
#include <sstream>
#include <SDL_mixer.h>
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"

//Enum con los diferentes estados en los que puede estar el juego
enum estadoEscena { RUNNING, GOLEVEL1, GOLEVEL2, GORANK, GOMENU, EXIT };

//Struct de jugadores en el ranking con valores como el nombre y la puntuaci�n
struct jugadorRanking
{
	int score;
	std::string name;
	bool operator<(const jugadorRanking& rhs) const
	{
		return score < rhs.score;
	}
};

class Scene
{
protected:

	//Variable que se refiere al estado actual de la escena
	estadoEscena estadoEscenaActual;

	//Rect�ngulo del background. Lo creamos constante porque es igual en todas las escenas
	const SDL_Rect bgRect{ 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	//Lista con la lista de los cinco mejores jugadores
	static std::priority_queue<jugadorRanking> topJugadores;



public:
	Scene();
	~Scene();

	//Funci�n encargada de actualizar el ranking
	void iniciarTopPlayer();

	// Funci�n encargada de controlar los eventos
	virtual void handleEvents() = 0;

	// Funci�n que devuelve el estado actual de la escena
	estadoEscena getEstadoEscena();

	// Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	virtual void update() = 0;

	// Funci�n encargada de dibujar la escena.
	virtual void draw() = 0;

};

