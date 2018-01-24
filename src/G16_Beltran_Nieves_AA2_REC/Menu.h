#pragma once
#include "Scene.h"
#include "Button.h"

class Menu : public Scene
{
public:
	Menu();
	~Menu();

	// Funci�n encargada de controlar los eventos
	void handleEvents() override;

	// Funci�n encargada de actualizar la escena en funci�n de los eventos que sucedan y de los inputs del jugador
	void update() override;

	// Funci�n encargada de dibujar la escena
	void draw() override;


private:

	// Array de botones del men�. BOTONES_TOTALES es constante ya que siempre tenemos el mismo n�mero de botones, 4
	Button botonesMenu[BOTONES_TOTALES];

	// Posiciones del rat�n
	int xRaton, yRaton;

	// Booleano que indica si el rat�n est� o no pulsado
	bool ratonClicado;

	// Booleano que comprueban si el rat�n est� sobre cada bot�n
	bool ratonSobreBotonLevel1;
	bool ratonSobreBotonLevel2;
	bool ratonSobreBotonRanking;
	bool ratonSobreBotonExit;


};
