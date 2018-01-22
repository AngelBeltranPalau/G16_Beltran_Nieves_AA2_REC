#include "Level.h"



Level::Level(const int &nLevel)
{

	estadoEscenaActual = estadoEscena::RUNNING;

	miMap.inicializarRectOcupado();

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

		//// Accedim al node playerHealth i n'agafem la informació.
		//for (int i = 0; i<JUGADORES_TOTALES; i++)
		//{
		//	players[i].setHealth(atoi(pLevel->first_attribute("lives")->value()));
		//}
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

}


Level::~Level()
{
}

// Función encargada de controlar los eventos
void Level::handleEvents() {};

// Función encargada de actualizar la escena en función de los eventos que sucedan y de los inputs del jugador
void Level::update() {};

// Función encargada de dibujar la escena
void Level::draw()
{
	Renderer::Instance()->Clear(); // Fem el clear per a començar el draw.

	Renderer::Instance()->PushImage("IMG_BACKGROUND", bgRect); // Dibuixem el background.

	// Dibuixem el mapa.
	miMap.draw();


	Renderer::Instance()->Render(); // Fem el render al final del draw.
}
