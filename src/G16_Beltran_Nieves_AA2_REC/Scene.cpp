#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

// Funci� que retornar� l'estat actual de l'escena.
estadoEscena Scene::getEstadoEscena()
{
	return estadoEscenaActual; // Retornem l'estat de l'escena.
}
