#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	ratonClicado = false;
	ratonSobreBotonLevel1 = false;
	ratonSobreBotonLevel2 = false;
	ratonSobreBotonRanking = false;
	ratonSobreBotonExit = false;
	xRaton = 0;
	yRaton = 0;

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

	Color buttonColoraux = { 0, 255, 0 }; // Color negre.
	Text textoBotonLEVEL1aux = { "TXT_LEVEL1aux", "LEVEL ONE", buttonColoraux,80,80 };
	Text textoBotonLEVEL2aux = { "TXT_LEVEL2aux", "LEVEL TWO", buttonColoraux,80,80 };
	Text textButtonRANKINGaux = { "TXT_RANKINGaux", "RANKING", buttonColoraux,80,80 };
	Text textoBotonEXITaux = { "TXT_EXITaux", "EXIT", buttonColoraux,80,80 };
	Renderer::Instance()->LoadTextureText("LetraMenu", textoBotonLEVEL1aux);
	Renderer::Instance()->LoadTextureText("LetraMenu", textoBotonLEVEL2aux);
	Renderer::Instance()->LoadTextureText("LetraMenu", textoBotonEXITaux);
	Renderer::Instance()->LoadTextureText("LetraMenu", textButtonRANKINGaux);

	// Creamos los rectángulos para los botones
	SDL_Rect rectBotonLEVEL1{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonLEVEL1.id).x / 2 , SCREEN_HEIGHT / 2 - 150, Renderer::Instance()->GetTextureSize(textoBotonLEVEL1.id).x, Renderer::Instance()->GetTextureSize(textoBotonLEVEL1.id).y };
	SDL_Rect rectBotonLEVEL2{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonLEVEL2.id).x / 2,SCREEN_HEIGHT / 2 - 50, Renderer::Instance()->GetTextureSize(textoBotonLEVEL2.id).x, Renderer::Instance()->GetTextureSize(textoBotonLEVEL2.id).y };
	SDL_Rect rectButtonRANKING{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textButtonRANKING.id).x / 2,SCREEN_HEIGHT / 2 + 50, Renderer::Instance()->GetTextureSize(textButtonRANKING.id).x, Renderer::Instance()->GetTextureSize(textButtonRANKING.id).y };
	SDL_Rect rectBotonEXIT{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonEXIT.id).x / 2,SCREEN_HEIGHT / 2 + 150, Renderer::Instance()->GetTextureSize(textoBotonEXIT.id).x, Renderer::Instance()->GetTextureSize(textoBotonEXIT.id).y };


	SDL_Rect rectBotonLEVEL1aux{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonLEVEL1aux.id).x / 2 , SCREEN_HEIGHT / 2 - 150, Renderer::Instance()->GetTextureSize(textoBotonLEVEL1aux.id).x, Renderer::Instance()->GetTextureSize(textoBotonLEVEL1aux.id).y };
	SDL_Rect rectBotonLEVEL2aux{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonLEVEL2aux.id).x / 2,SCREEN_HEIGHT / 2 - 50, Renderer::Instance()->GetTextureSize(textoBotonLEVEL2aux.id).x, Renderer::Instance()->GetTextureSize(textoBotonLEVEL2aux.id).y };
	SDL_Rect rectButtonRANKINGaux{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textButtonRANKINGaux.id).x / 2,SCREEN_HEIGHT / 2 + 50, Renderer::Instance()->GetTextureSize(textButtonRANKINGaux.id).x, Renderer::Instance()->GetTextureSize(textButtonRANKINGaux.id).y };
	SDL_Rect rectBotonEXITaux{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonEXITaux.id).x / 2,SCREEN_HEIGHT / 2 + 150, Renderer::Instance()->GetTextureSize(textoBotonEXITaux.id).x, Renderer::Instance()->GetTextureSize(textoBotonEXITaux.id).y };


	// Inicialitzem la array de botones
	botonesMenu[0] = botonesMenu[0].inicializarBoton(rectBotonLEVEL1);
	botonesMenu[1] = botonesMenu[1].inicializarBoton(rectBotonLEVEL2);
	botonesMenu[2] = botonesMenu[2].inicializarBoton(rectButtonRANKING);
	botonesMenu[3] = botonesMenu[3].inicializarBoton(rectBotonEXIT);
	botonesMenu[4] = botonesMenu[4].inicializarBoton(rectBotonLEVEL1aux);
	botonesMenu[5] = botonesMenu[5].inicializarBoton(rectBotonLEVEL2aux);
	botonesMenu[6] = botonesMenu[6].inicializarBoton(rectButtonRANKINGaux);
	botonesMenu[7] = botonesMenu[7].inicializarBoton(rectBotonEXITaux);

}

//Actua en funcion de imputs y enventos
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
	if (botonesMenu[0].ratonSobreBoton(xRaton, yRaton))
	{
		ratonSobreBotonLevel1 = true;
	}
	else
	{
		ratonSobreBotonLevel1 = false;
	}
	if (botonesMenu[1].ratonSobreBoton(xRaton, yRaton))
	{
		ratonSobreBotonLevel2 = true;
	}
	else
	{
		ratonSobreBotonLevel2 = false;
	}
	if (botonesMenu[2].ratonSobreBoton(xRaton, yRaton))
	{
		ratonSobreBotonRanking = true;
	}
	else
	{
		ratonSobreBotonRanking = false;
	}
	if (botonesMenu[3].ratonSobreBoton(xRaton, yRaton))
	{
		ratonSobreBotonExit = true;
	}
	else
	{
		ratonSobreBotonExit = false;
	}
}

//Actualiza la información
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

//Dibuja en pantalla
void Menu::draw()
{
	// Limpiamos toda la pantalla antes de dibujar
	Renderer::Instance()->Clear(); 

	// Dibujamos el background.
	Renderer::Instance()->PushImage("IMG_BACKGROUND", bgRect);

	// Dibujamos los botones
	if (ratonSobreBotonLevel1)
	{
		Renderer::Instance()->PushImage("TXT_LEVEL1aux", botonesMenu[4].devolverRectangulo());
	}
	else
	{
		Renderer::Instance()->PushImage("TXT_LEVEL1", botonesMenu[0].devolverRectangulo());
	}
	if (ratonSobreBotonLevel2)
	{
		Renderer::Instance()->PushImage("TXT_LEVEL2aux", botonesMenu[5].devolverRectangulo());
	}
	else
	{
		Renderer::Instance()->PushImage("TXT_LEVEL2", botonesMenu[1].devolverRectangulo());
	}
	if (ratonSobreBotonRanking)
	{
		Renderer::Instance()->PushImage("TXT_RANKINGaux", botonesMenu[6].devolverRectangulo());
	}
	else
	{
		Renderer::Instance()->PushImage("TXT_RANKING", botonesMenu[2].devolverRectangulo());
	}
	if (ratonSobreBotonExit)
	{
		Renderer::Instance()->PushImage("TXT_EXITaux", botonesMenu[7].devolverRectangulo());
	}
	else
	{
		Renderer::Instance()->PushImage("TXT_EXIT", botonesMenu[3].devolverRectangulo());
	}

	Renderer::Instance()->Render(); // Hacemos el Render después de dibujarlo todo
}

//Destructor del menu
Menu::~Menu()
{

}








