#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	// Se inicializa el Menú en estado RUNNING
	estadoEscenaActual = estadoEscena::RUNNING;

	// Cargamos la imagen del Background
	Renderer::Instance()->LoadTexture("IMG_BACKGROUND", "../../res/img/Background_TopoBar.png");

	// Cargamos las fuentes para el texto
	Font fuenteBoton = { "LetraMenu", "../../res/ttf/saiyan.ttf", 80 };
	Renderer::Instance()->LoadFont(fuenteBoton);

	// Creamos las variables Text de todos los botones para poder cargar sus texturas
	Color buttonColor = { 255, 255, 255 }; // Color negre.
	Text textoBotonLEVEL1 = { "TXT_LEVEL1", "LEVEL ONE", buttonColor,80,80 };
	Text textoBotonLEVEL2 = { "TXT_LEVEL2", "LEVEL TWO", buttonColor,80,80 };
	Text textButtonRANKING = { "TXT_RANKING", "RANKING", buttonColor,80,80 };
	Text textoBotonEXIT = { "TXT_EXIT", "EXIT", buttonColor,80,80 };
	Renderer::Instance()->LoadTextureText("LetraMenu", textoBotonLEVEL1);
	Renderer::Instance()->LoadTextureText("LetraMenu", textoBotonLEVEL2);
	Renderer::Instance()->LoadTextureText("LetraMenu", textoBotonEXIT);
	Renderer::Instance()->LoadTextureText("LetraMenu", textButtonRANKING);

	// Creamos los rectángulos para los botones
	SDL_Rect rectBotonLEVEL1{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonLEVEL1.id).x / 2 , SCREEN_HEIGHT / 2 - 150, Renderer::Instance()->GetTextureSize(textoBotonLEVEL1.id).x, Renderer::Instance()->GetTextureSize(textoBotonLEVEL1.id).y };
	SDL_Rect rectBotonLEVEL2{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonLEVEL2.id).x / 2,SCREEN_HEIGHT / 2 - 50, Renderer::Instance()->GetTextureSize(textoBotonLEVEL2.id).x, Renderer::Instance()->GetTextureSize(textoBotonLEVEL2.id).y };
	SDL_Rect rectButtonRANKING{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textButtonRANKING.id).x / 2,SCREEN_HEIGHT / 2 + 50, Renderer::Instance()->GetTextureSize(textButtonRANKING.id).x, Renderer::Instance()->GetTextureSize(textButtonRANKING.id).y };
	SDL_Rect rectBotonEXIT{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonEXIT.id).x / 2,SCREEN_HEIGHT / 2 + 150, Renderer::Instance()->GetTextureSize(textoBotonEXIT.id).x, Renderer::Instance()->GetTextureSize(textoBotonEXIT.id).y };

	// Inicialitzem la array de botones
	botonesMenu[0] = botonesMenu[0].inicializarBoton(rectBotonLEVEL1);
	botonesMenu[1] = botonesMenu[1].inicializarBoton(rectBotonLEVEL2);
	botonesMenu[2] = botonesMenu[2].inicializarBoton(rectButtonRANKING);
	botonesMenu[3] = botonesMenu[3].inicializarBoton(rectBotonEXIT);

}

void Menu::handleEvents()
{
	SDL_Event evento;
	while (SDL_PollEvent(&evento))
	{
		switch (evento.type)
		{
		case SDL_QUIT: {estadoEscenaActual = estadoEscena::EXIT; break; } // Se termina el juego si se sale del menú
		case SDL_MOUSEMOTION: // Si se detecta que se mueve el ratón se cambian las variables xRaton y yRaton para que, en el Update, este se mueva
		{
			xRaton = evento.motion.x;
			yRaton = evento.motion.y;
			break;
		}
		case SDL_MOUSEBUTTONDOWN: // Si el ratón es clicado, se pone en true la variable ratonClicado
		{
			std::cout << "HOLA";
			ratonClicado = true;
			break;
		}
		case SDL_MOUSEBUTTONUP: // Si el ratón es des-clicado, se pone en false la variable ratonClicado
		{
			ratonClicado = false;
			break;
		}
		default:;
		}
	}
}

void Menu::update()
{
	// Si se pulsa el boton Level 1, se cambia el estado de la escena a GOLEVEL1
	if (ratonClicado && botonesMenu[0].ratonSobreBoton(xRaton, yRaton))
	{
		estadoEscenaActual = estadoEscena::GOLEVEL1;
	}
	// Si se pulsa el boton Level 2, se cambia el estado de la escena a GOLEVEL2
	else if (ratonClicado && botonesMenu[1].ratonSobreBoton(xRaton, yRaton))
	{
		estadoEscenaActual = estadoEscena::GOLEVEL2;
	}
	// Si se pulsa el boton Ranking, se cambia el estado de la escena a GORANK
	else if (ratonClicado && botonesMenu[2].ratonSobreBoton(xRaton, yRaton))
	{
		estadoEscenaActual = estadoEscena::GORANK;
	}
	// Si se pulsa el boton EXIT, se cambia el estado de la escena a EXIT
	else if (ratonClicado && botonesMenu[3].ratonSobreBoton(xRaton, yRaton))
	{
		estadoEscenaActual = estadoEscena::EXIT;
	}

};

void Menu::draw()
{
	// Limpiamos toda la pantalla antes de dibujar
	Renderer::Instance()->Clear(); 

	// Dibujamos el background.
	Renderer::Instance()->PushImage("IMG_BACKGROUND", bgRect);

	// Dibujamos los botones
	Renderer::Instance()->PushImage("TXT_LEVEL1", botonesMenu[0].devolverRectangulo());
	Renderer::Instance()->PushImage("TXT_LEVEL2", botonesMenu[1].devolverRectangulo());
	Renderer::Instance()->PushImage("TXT_RANKING", botonesMenu[2].devolverRectangulo());
	Renderer::Instance()->PushImage("TXT_EXIT", botonesMenu[3].devolverRectangulo());

	Renderer::Instance()->Render(); // Hacemos el Render después de dibujarlo todo
}


Menu::~Menu()
{

}








