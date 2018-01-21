#pragma once
#include "Scene.h"
#include "Button.h"

class Menu : public Scene
{
public:
	Menu();
	~Menu();

	// Funci�n encargada de controlar los eventos
	virtual void handleEvents() = 0;

	// Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	virtual void update() = 0;

	// Funci�n encargada de dibujar la escena
	virtual void draw() = 0;


private:

	// Array de botones del men�. BOTONES_TOTALES es constante ya que siempre tenemos el mismo n�mero de botones, 4
	Button botonesMenu[BOTONES_TOTALES];

	// Posiciones del rat�n
	int xRaton, yRaton;

	// Booleano que indica si el rat�n est� o no pulsado
	bool ratonClicado;

};
