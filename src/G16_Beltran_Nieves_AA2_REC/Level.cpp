#include "Level.h"



Level::Level(const int &nLevel)
{

	estadoEscenaActual = estadoEscena::RUNNING;

	miMap.inicializarRectOcupado();


	jugadores[0] = new Player(1);
	jugadores[1] = new Player(2);


	rapidxml::xml_document<> doc;
	std::ifstream file("../../res/files/config.xml");

	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);
	rapidxml::xml_node<> *pRaiz = doc.first_node();
	rapidxml::xml_node<> *pLevel = pRaiz->first_node();


	if (nLevel == 1)
	{
		// Busquem fins que pLevel apunti al nivell 1.
		while ((std::string)pLevel->first_attribute("id")->value() != "1")
		{
			pLevel = pLevel->next_sibling();
		}

		// Accedim al node time i n'agafem la informació.
		timeDown = atoi(pLevel->first_attribute("time")->value());

		rapidxml::xml_node<> *soluciones = pLevel->first_node("characters")->first_node("character"); // Apunta al primer node casella Destructible.
		
		movimientos.push_back(atoi(soluciones->first_attribute("mov")->value()));
		jugadores[0]->setPosicion(atoi(soluciones->first_attribute("posj")->value()), atoi(soluciones->first_attribute("posi")->value()));
		miMap.añadirItem("SOLUCION_VERDE", atoi(soluciones->first_attribute("objj")->value()) + 1, atoi(soluciones->first_attribute("obji")->value()) + 1); // Ara guardem a myMap el valor de la casella actual.
		soluciones = soluciones->next_sibling();
		jugadores[1]->setPosicion(atoi(soluciones->first_attribute("posj")->value()), atoi(soluciones->first_attribute("posi")->value()));
		movimientos.push_back(atoi(soluciones->first_attribute("mov")->value()));
		miMap.añadirItem("SOLUCION_ROJO", atoi(soluciones->first_attribute("objj")->value()) + 1, atoi(soluciones->first_attribute("obji")->value()) + 1); // Ara guardem a myMap el valor de la casella actual.
		soluciones = soluciones->next_sibling();
			
		
		//// Accedim al node time i n'agafem la informació.
		//timeDown = atoi(pLevel->first_attribute("time")->value());

		// Ara guardarem la informació sobre les diferents caselles.
		rapidxml::xml_node<> *muros = pLevel->first_node("Walls")->first_node("Wall"); // Apunta al primer node casella Destructible.

		for (int i = 0; i < Y_MAPA; i++)
		{
			miMap.añadirItem("MURO", 0, i);
		}
		for (int i = 0; i < X_MAPA; i++)
		{
			miMap.añadirItem("MURO", i, 0);
		}
		for (int i = 0; i < Y_MAPA; i++)
		{
			miMap.añadirItem("MURO", X_MAPA-1, i);
		}
		for (int i = 0; i < X_MAPA; i++)
		{
			miMap.añadirItem("MURO", i, Y_MAPA-1);
		}
		while (muros != nullptr)
		{
			miMap.añadirItem("MURO", atoi(muros->first_attribute("j")->value()) + 1, atoi(muros->first_attribute("i")->value())+ 1); // Ara guardem a myMap el valor de la casella actual.
			muros = muros->next_sibling();
		}
		for (int y = 0; y<Y_MAPA; y++)
		{
			for (int x = 0; x<X_MAPA; x++)
			{
				if (miMap.devolverContenidoPosicion(x, y) != "MURO" && miMap.devolverContenidoPosicion(x, y) != "SOLUCION_VERDE" && miMap.devolverContenidoPosicion(x, y) != "SOLUCION_ROJO")
				{
					miMap.añadirItem("HIELO", x, y);
				}
			}
		}
		for (int i = 0; i < X_MAPA; i++)
		{
			miMap.añadirItem("MURO", 0, i);
		}
	}
	else if (nLevel == 2)
	{
		while ((std::string)pLevel->first_attribute("id")->value() != "2")
		{
			pLevel = pLevel->next_sibling();
		}

		// Accedim al node time i n'agafem la informació.
		timeDown = atoi(pLevel->first_attribute("time")->value());

		rapidxml::xml_node<> *soluciones = pLevel->first_node("characters")->first_node("character"); // Apunta al primer node casella Destructible.

		movimientos.push_back(atoi(soluciones->first_attribute("mov")->value()));
		jugadores[0]->setPosicion(atoi(soluciones->first_attribute("posj")->value()), atoi(soluciones->first_attribute("posi")->value()));
		miMap.añadirItem("SOLUCION_VERDE", atoi(soluciones->first_attribute("objj")->value()) + 1, atoi(soluciones->first_attribute("obji")->value()) + 1); // Ara guardem a myMap el valor de la casella actual.
		soluciones = soluciones->next_sibling();
		movimientos.push_back(atoi(soluciones->first_attribute("mov")->value()));
		jugadores[1]->setPosicion(atoi(soluciones->first_attribute("posj")->value()), atoi(soluciones->first_attribute("posi")->value()));
		miMap.añadirItem("SOLUCION_ROJO", atoi(soluciones->first_attribute("objj")->value()) + 1, atoi(soluciones->first_attribute("obji")->value()) + 1); // Ara guardem a myMap el valor de la casella actual.
		soluciones = soluciones->next_sibling();



		for (int i = 0; i < Y_MAPA; i++)
		{
			miMap.añadirItem("MURO", 0, i);
		}
		for (int i = 0; i < X_MAPA; i++)
		{
			miMap.añadirItem("MURO", i, 0);
		}
		for (int i = 0; i < Y_MAPA; i++)
		{
			miMap.añadirItem("MURO", X_MAPA - 1, i);
		}
		for (int i = 0; i < X_MAPA; i++)
		{
			miMap.añadirItem("MURO", i, Y_MAPA - 1);
		}
		// Busquem fins que pLevel apunti al nivell 1.
		while ((std::string)pLevel->first_attribute("id")->value() != "2")
		{
			pLevel = pLevel->next_sibling();
		}

		// Accedim al node time i n'agafem la informació.
		timeDown = atoi(pLevel->first_attribute("time")->value());

		//// Accedim al node playerHealth i n'agafem la informació.
		//for (int i = 0; i<JUGADORES_TOTALES; i++)
		//{
		//	players[i].setHealth(atoi(pLevel->first_attribute("lives")->value()));
		//}
		//// Accedim al node time i n'agafem la informació.
		//timeDown = atoi(pLevel->first_attribute("time")->value());

		// Ara guardarem la informació sobre les diferents caselles.
		rapidxml::xml_node<> *muros = pLevel->first_node("Walls")->first_node("Wall"); // Apunta al primer node casella Destructible.

		while (muros != nullptr)
		{
			miMap.añadirItem("MURO", atoi(muros->first_attribute("j")->value()) + 1, atoi(muros->first_attribute("i")->value()) + 1); // Ara guardem a myMap el valor de la casella actual.
			muros = muros->next_sibling();
		}
		for (int y = 0; y<Y_MAPA; y++)
		{
			for (int x = 0; x<X_MAPA; x++)
			{
				if (miMap.devolverContenidoPosicion(x, y) != "MURO" && miMap.devolverContenidoPosicion(x, y) != "SOLUCION_VERDE" && miMap.devolverContenidoPosicion(x, y) != "SOLUCION_ROJO")
				{
					miMap.añadirItem("HIELO", x, y);
				}
			}
		}
	}

	miMap.inicializarRectOcupado();


	//// Cargamos todos los sprites de los jugadores

	//Renderer::Instance()->LoadTexture("SpriteJugador1", "../../res/img/player.png"); // Sprites jugador 1.
	//Renderer::Instance()->LoadTexture("SpriteJugador2", "../../res/img/player2.png"); // Sprites jugador 2.

	//// Creamos y guardamos los rectangulos.
	//
	//SDL_Rect rectJugador1 = { 0, 0, TAMAÑO_SPRITE * 3/2, TAMAÑO_SPRITE * 3/2 };
	//jugadores[0].setRectangulo(rectJugador1);
	//SDL_Rect rectSpriteJugador1 = { 0,0,TAMAÑO_SPRITE,TAMAÑO_SPRITE };
	//jugadores[0].setRectanguloSprite(rectSpriteJugador1);

	//SDL_Rect rectJugador2 = { 0,0,TAMAÑO_SPRITE * 3/2, TAMAÑO_SPRITE * 3/2 };
	//jugadores[1].setRectangulo(rectJugador2);
	//SDL_Rect rectSpriteJugador2 = { 0,0,TAMAÑO_SPRITE,TAMAÑO_SPRITE };
	//jugadores[0].setRectanguloSprite(rectSpriteJugador2);


	//RectJugadores[0] = jugadores[0].getRectangulo();
	//RectJugadores[1] = jugadores[1].getRectangulo();
}


Level::~Level()
{
}

void Level::setDestino(Direcciones dir)
{
	if(dir == UP)
	{
		for(int i; i<JUGADORES_TOTALES; i++)
		{
			while ( Map::devolverContenidoPosicion(jugadores[i]->getPosicionX, jugadores[i]->getPosicionY + 1) != 'Muro')
			{
				jugadores[i]->setPosicion(jugadores[i]->getPosicionX, jugadores[i]->getPosicionY + 1);				
			}
		}
		
	}

	if (dir == DOWN)
	{
		for (int i; i<JUGADORES_TOTALES; i++)
		{
			while (Map::devolverContenidoPosicion(jugadores[i]->getPosicionX, jugadores[i]->getPosicionY - 1) != 'Muro')
			{
				jugadores[i]->setPosicion(jugadores[i]->getPosicionX, jugadores[i]->getPosicionY - 1);
			}
		}

	}

	if (dir == RIGHT)
	{
		for (int i; i<JUGADORES_TOTALES; i++)
		{
			while (miMap.devolverContenidoPosicion(jugadores[i]->getPosicionX + 1, jugadores[i]->getPosicionY) != "Muro")
			{
				jugadores[i]->setPosicion(jugadores[i]->getPosicionX + 1, jugadores[i]->getPosicionY);
			}
		}

	}

	if (dir == LEFT)
	{
		for (int i; i<JUGADORES_TOTALES; i++)
		{
			while (Map::devolverContenidoPosicion(jugadores[i]->getPosicionX - 1, jugadores[i]->getPosicionY) != 'Muro')
			{
				jugadores[i]->setPosicion(jugadores[i]->getPosicionX - 1, jugadores[i]->getPosicionY);
			}
		}

	}
}

// Función encargada de controlar los eventos
void Level::handleEvents() 
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case(SDL_KEYDOWN):
			{
				if (event.key.keysym.sym == SDLK_w)
				{
					for(int i = 0; i<JUGADORES_TOTALES; i++)
					{
						if (jugadores[i]->getDireccion() == Direcciones::NONE)
							jugadores[i]->setDireccion(Direcciones::UP);
					}
				}
				else if (event.key.keysym.sym == SDLK_a)
				{
					for (int i = 0; i<JUGADORES_TOTALES; i++)
					{
						if (jugadores[i]->getDireccion() == Direcciones::NONE)
							jugadores[i]->setDireccion(Direcciones::LEFT);
					}
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					for (int i = 0; i<JUGADORES_TOTALES; i++)
					{
						if (jugadores[i]->getDireccion() == Direcciones::NONE)
							jugadores[i]->setDireccion(Direcciones::DOWN);
					}
				}
				else if (event.key.keysym.sym == SDLK_d)
				{
					for (int i = 0; i<JUGADORES_TOTALES; i++)
					{
						if (jugadores[i]->getDireccion() == Direcciones::NONE)
							jugadores[i]->setDireccion(Direcciones::RIGHT);
					}
				}			
			}		
		}	
	}
};

// Función encargada de actualizar la escena en función de los eventos que sucedan y de los inputs del jugador
void Level::update() 
{
	deltaTime = (clock() - lastTime);
	lastTime = clock();
	deltaTime /= CLOCKS_PER_SEC;
	timeDown -= deltaTime;
	int time = (int)timeDown;

	miHUD.update(time, movimientos);

};


// Función encargada de dibujar la escena
void Level::draw()
{
	Renderer::Instance()->Clear(); // Fem el clear per a començar el draw.

	Renderer::Instance()->PushImage("IMG_BACKGROUND", bgRect); // Dibuixem el background.

	// Dibuixem el mapa.
	miMap.draw();

	miHUD.draw();

	for (int i = 0; i < JUGADORES_TOTALES; i++)
	{
		jugadores[i]->draw();
	}

	Renderer::Instance()->Render(); // Fem el render al final del draw.
}
