#pragma once
#include "Renderer.h"
#include "Player.h"
#include <unordered_map>
#include <vector>

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &p) const
	{
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		// Mainly for demonstration purposes, i.e. works but is overly simple
		// In the real world, use sth. like boost.hash_combine
		return h1 ^ h2;
	}
};

class Map
{
private:

	// Unordered map en el que guardamos todas las posiciones del nivel
	std::unordered_map<std::pair<int, int>, std::string, pair_hash> tablaPosiciones;


	// Rect�ngulo del que partiremos para dibujar el mapa
	SDL_Rect rectItems;

	// Rect�ngulo de piedras que no se puede atravesar
	SDL_Rect muro;
	SDL_Rect solucionRoja;
	SDL_Rect solucionVerde;
	SDL_Rect hielo;

	// Vector que determina si una posici�n est� o no ocupado y si, por tanto, el jugador puede acceder a la misma
	std::vector<SDL_Rect> rectOcupado;

	// Vectores que determinan las posiciones x e y de las posiciones ocupadas
	std::vector<int> rectOcupadoX;
	std::vector<int> rectOcupadoY;

	//Coordenadas del cuadrado de meta rojo
	int ganadorRojoX;
	int ganadorRojoY;

	//Coordenadas del cuadrado de meta verde
	int ganadorVerdeX;
	int ganadorVerdeY;


public:
	Map();
	~Map();

	// Funci�n que devuelve las posiciones ocupadas
	std::vector<SDL_Rect> devolverRectOcupado();

	//  Funci�n que inicializa las posiciones ocupadas
	void inicializarRectOcupado();

	// Funci�n que devuelve el contenido de una posici�n
	std::string devolverContenidoPosicion(int &x, int &y);

	void a�adirPosicionOcupada(const SDL_Rect &r);

	void a�adirItem(const std::string &i, const int &k1, const int &k2);

	//Funciones para determinar la posici�n de las posiciones de meta roja y verde respectivamente
	void setGanadorRojo(int x, int y);
	void setGanadorVerde(int x, int y);

	//Funciones para obtener los valores X e Y de las posiciones de meta roja y verda respectivamente
	int getGanadorRojoX();
	int getGanadorRojoY();
	int getGanadorVerdeX();
	int getGanadorVerdeY();


	//Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	void update();

	// Funci�n encargada de dibujar la escena
	void draw();

};



