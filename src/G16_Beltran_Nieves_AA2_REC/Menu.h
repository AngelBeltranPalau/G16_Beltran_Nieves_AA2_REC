#pragma once
#include "Scene.h"
#include "Button.h"

class Menu : public Scene
{
public:
	Menu();
	~Menu();

	// Función encargada de controlar los eventos
	void handleEvents() override;

	// Función encargada de actualizar la escena en función de los eventos que sucedan y de los inputs del jugador
	void update() override;

	// Función encargada de dibujar la escena
	void draw() override;


private:

	// Array de botones del menú. BOTONES_TOTALES es constante ya que siempre tenemos el mismo número de botones, 4
	Button botonesMenu[BOTONES_TOTALES];

	// Posiciones del ratón
	int xRaton, yRaton;

	// Booleano que indica si el ratón está o no pulsado
	bool ratonClicado;

	// Booleano que comprueban si el ratón está sobre cada botón
	bool ratonSobreBotonLevel1;
	bool ratonSobreBotonLevel2;
	bool ratonSobreBotonRanking;
	bool ratonSobreBotonExit;


};
