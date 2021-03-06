#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

//Funci�n ques nos devuelve el estado en el que est� la escena actualmente
estadoEscena Scene::getEstadoEscena()
{
	return estadoEscenaActual; 
}

std::priority_queue<jugadorRanking> Scene::topJugadores;

void Scene::iniciarTopPlayer()
{
	int score;
	std::string nombre;
	std::ifstream fentrada("../../res/files/ranking.bin", std::ios::in | std::ios::binary);

	while (fentrada.peek() != std::ifstream::traits_type::eof())
	{
		size_t len;
		fentrada.read(reinterpret_cast<char *>(&len), sizeof(size_t));
		char* temp = new char[len + 1];
		fentrada.read(temp, len);
		temp[len] = '\0';
		nombre = temp;
		delete[]temp;
		fentrada.read(reinterpret_cast<char *>(&score), sizeof(score));
		topJugadores.push({ score,nombre });
	}

	// Cerramos el fichero
	fentrada.close();
}