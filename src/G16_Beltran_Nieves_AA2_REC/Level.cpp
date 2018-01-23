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

	jugadores[0]->setPosicionRealX();
	jugadores[0]->setPosicionRealY();
	
	jugadores[1]->setPosicionRealX();
	jugadores[1]->setPosicionRealY();

	jugadores[0]->setPosicion(jugadores[0]->getPosicionX()+1, jugadores[0]->getPosicionY() + 1);
	jugadores[1]->setPosicion(jugadores[1]->getPosicionX() + 1, jugadores[1]->getPosicionY() + 1);


	jugadores[0]->setMovimientos(movimientos[0]);
	jugadores[1]->setMovimientos(movimientos[1]);

	movimientos[0] = jugadores[0]->getMovimientos();
	movimientos[1] = jugadores[1]->getMovimientos();

	miMap.inicializarRectOcupado();


}


Level::~Level()
{
}

void Level::setDestino(Direcciones dir)
{
	int x = 0;
	if(dir == UP)
	{
		for (int i = 0; i<JUGADORES_TOTALES; i++)
		{
			int auxX = jugadores[i]->getPosicionX();
			int auxY = jugadores[i]->getPosicionY();
			auxY--;
			while (miMap.devolverContenidoPosicion(auxX, auxY) != "MURO")
			{
				jugadores[i]->setPosicion(auxX, auxY);
				auxY--;
			}
		}
	}

	if (dir == DOWN)
	{
		for (int i = 0; i<JUGADORES_TOTALES; i++)
		{
			int auxX = jugadores[i]->getPosicionX();
			int auxY = jugadores[i]->getPosicionY();
			auxY++;
			while (miMap.devolverContenidoPosicion(auxX, auxY) != "MURO")
			{
				jugadores[i]->setPosicion(auxX, auxY);
				auxY++;
			}
		}
		
	}

	if (dir == RIGHT)
	{
		for (int i = 0; i<JUGADORES_TOTALES; i++)
		{
			int auxX = jugadores[i]->getPosicionX();
			int auxY = jugadores[i]->getPosicionY();
			auxX++;
			auxY;
			while (miMap.devolverContenidoPosicion(auxX, auxY) != "MURO")
			{
				jugadores[i]->setPosicion(auxX, auxY);
				auxX++;
			}
		}

	}

	if (dir == LEFT)
	{
		for (int i = 0; i<JUGADORES_TOTALES; i++)
		{
			int auxX = jugadores[i]->getPosicionX();
			int auxY = jugadores[i]->getPosicionY();
			auxX--;
			while (miMap.devolverContenidoPosicion(auxX, auxY) != "MURO")
			{
				jugadores[i]->setPosicion(auxX, auxY);
				auxX--;
			}
		}

	}

	//if (jugadores[0]->getPosicionX() != jugadores[0]->getPosicionRealX() || jugadores[0]->getPosicionY() != jugadores[0]->getPosicionRealY())
	//{
	//	jugadores[0]->reducirMovimiento();
	//}
	//if (jugadores[1]->getPosicionX() != jugadores[1]->getPosicionRealX() || jugadores[1]->getPosicionY() != jugadores[1]->getPosicionRealY())
	//{
	//	jugadores[1]->reducirMovimiento();
	//}

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
						{
							std::cout << "HOLA";
							jugadores[i]->setDireccion(Direcciones::UP);
						}
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

	movimientos[0] = jugadores[0]->getMovimientos();
	movimientos[1] = jugadores[1]->getMovimientos();


	miHUD.update(time, movimientos);

	if(jugadores[0]->getPosicionX() == jugadores[0]->getPosicionRealX() || jugadores[0]->getPosicionY() == jugadores[0]->getPosicionRealY() || jugadores[1]->getPosicionX() == jugadores[1]->getPosicionRealX() || jugadores[1]->getPosicionY() == jugadores[1]->getPosicionRealY())
	{ 
		if (jugadores[0]->getDireccion() != Direcciones::NONE || jugadores[1]->getDireccion() != Direcciones::NONE)
		{
			setDestino(jugadores[0]->getDireccion());
		}
	}

	if (jugadores[0]->getDireccion() != Direcciones::NONE || jugadores[1]->getDireccion() != Direcciones::NONE)
	{
		for (int i = 0; i < JUGADORES_TOTALES; i++)
		{
			jugadores[i]->update();
		}
	}
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
