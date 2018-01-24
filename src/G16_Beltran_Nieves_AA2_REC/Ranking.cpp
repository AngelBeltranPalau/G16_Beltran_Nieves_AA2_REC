#include "Ranking.h"



Ranking::Ranking()
{
	estadoEscenaActual = estadoEscena::RUNNING;

	ratonSobreBoton = false;
	
	// Cargamos la fuente con la que imprimiremos las puntuaciones y el botón de volver al MENU
	Font buttonFont = { "LetraRanking" , "../../res/ttf/saiyan.ttf" ,40 };
	Renderer::Instance()->LoadFont(buttonFont);

	Font buttonFont2 = { "LetraRanking2" , "../../res/ttf/game_over.ttf" ,100 };
	Renderer::Instance()->LoadFont(buttonFont2);

	// Cargamos el texto del botón de volver al MENU
	Text textoBotonMenu = { "TextoRanking", "VOLVER AL MENU",{ 0,0,0,0 },10,10 };
	Renderer::Instance()->LoadTextureText("LetraRanking", textoBotonMenu);
	// Creamos el rectángulo del botón de volver al MENU
	SDL_Rect buttonMenuRect{ 150 - Renderer::Instance()->GetTextureSize(textoBotonMenu.id).x / 2 , SCREEN_HEIGHT - 75, Renderer::Instance()->GetTextureSize(textoBotonMenu.id).x, Renderer::Instance()->GetTextureSize(textoBotonMenu.id).y };
	// Inicializamos el botón con su rectángulo
	menuButton = menuButton.inicializarBoton(buttonMenuRect);

	// Cargamos el texto del botón de volver al MENU resaltado
	Text textoBotonMenu2 = { "TextoRanking2", "VOLVER AL MENU",{ 0,255,0,0 },10,10 };
	Renderer::Instance()->LoadTextureText("LetraRanking", textoBotonMenu2);
	// Creamos el rectángulo del botón de volver al MENU
	SDL_Rect buttonMenuRect2{ 150 - Renderer::Instance()->GetTextureSize(textoBotonMenu2.id).x / 2 , SCREEN_HEIGHT - 75, Renderer::Instance()->GetTextureSize(textoBotonMenu2.id).x, Renderer::Instance()->GetTextureSize(textoBotonMenu2.id).y };
	// Inicializamos el botón con su rectángulo
	menuButton2 = menuButton2.inicializarBoton(buttonMenuRect2);


	// Ahora debemos imprimir las mejores posiciones del ranking cargadas desde el .bin
	int i = 0;
	std::priority_queue<jugadorRanking> auxTop = topJugadores;
	while (i<NUM_JUGADORES_TOP && !auxTop.empty())
	{
		Text textPuntuacionJugador = { textScoreJugadores[i], "" + auxTop.top().name + ": " + std::to_string(auxTop.top().score) + "",{ 255,255,255 },120,120 };
		Renderer::Instance()->LoadTextureText("LetraRanking2" , textPuntuacionJugador);
		SDL_Rect aux = { SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textPuntuacionJugador.id).x / 2 ,  + i * 50,Renderer::Instance()->GetTextureSize(textPuntuacionJugador.id).x ,Renderer::Instance()->GetTextureSize(textPuntuacionJugador.id).y };
		rectScoreJugadores[i] = aux;
		auxTop.pop();
		i++;
	}

}


Ranking::~Ranking()
{
}

// Función encargada de controlar los eventos
void Ranking::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT: {estadoEscenaActual = estadoEscena::EXIT; break; } // Si se cierra la ventana se cierra el juego
		case SDL_MOUSEMOTION: // // Si se detecta que se mueve el ratón se cambian las variables xRaton y yRaton para que, en el Update, este se mueva
		{
			xRaton = event.motion.x;
			yRaton = event.motion.y;
			break;
		}
		case SDL_MOUSEBUTTONDOWN: // Si el ratón es clicado, se pone en true la variable ratonClicado
		{
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
	if (menuButton.ratonSobreBoton(xRaton, yRaton))
	{
		ratonSobreBoton = true;
	}
	else
	{
		ratonSobreBoton = false;
	}
}


// Función encargada de actualizar la escena en función de los eventos que sucedan y de los inputs del jugador
void Ranking::update()
{
	// Ir al MENU si se pulsa el botón
	if (ratonClicado && menuButton.ratonSobreBoton(xRaton, yRaton))
	{
		estadoEscenaActual = estadoEscena::GOMENU;
	}
}

// Función encargada de dibujar la escena
void Ranking::draw() 
{
	Renderer::Instance()->Clear(); // Limpiamos la pantalla
	Renderer::Instance()->PushImage("IMG_BACKGROUND", bgRect); // Dibujamos el Background

	if(ratonSobreBoton == false)
		Renderer::Instance()->PushImage("TextoRanking", menuButton.devolverRectangulo()); // Dibujamos el botón de volver al menú
	else
		Renderer::Instance()->PushImage("TextoRanking2", menuButton2.devolverRectangulo()); // Dibujamos el botón de volver al menú


	for (int i = 0; i < NUM_JUGADORES_TOP; i++)
	{
		Renderer::Instance()->PushImage(textScoreJugadores[i], rectScoreJugadores[i]); // Dibujamos el nombre y la punciación de los 5 primeros puestos del Ranking
	}


	Renderer::Instance()->Render(); // Hacemos Render al terminar el Draw
};