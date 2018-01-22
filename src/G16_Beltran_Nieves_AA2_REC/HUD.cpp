#include "HUD.h"
#include <string>


// Constructor del HUD.
// Creem el rect del nostre HUD. - Fet.
// Carguem la font del HUD. - Fet.
HUD::HUD()
{

	Font fuenteHud = { "letraHud" , "../../res/ttf/game_over.ttf", 80 };
	Renderer::Instance()->LoadFont(fuenteHud);
	
	Color colorMoves = { 0, 0, 0 };
	Color colorSec = { 255, 255, 255 };

	Text textoPlMoves1 = { "PlMoves1", "Pl 1 moves: ", colorMoves,30,30 };
	Text textoPlMoves2 = { "PlMoves2", "Pl 2 moves: ", colorMoves,30,30 };
	Text textoSec = { "Sec", "sec. ", colorSec, 30, 30 };

	Renderer::Instance()->LoadTextureText("letraHud", textoPlMoves1);
	Renderer::Instance()->LoadTextureText("letraHud", textoPlMoves2);
	Renderer::Instance()->LoadTextureText("letraHud", textoSec);

	plMoves1Rect = { HUD_WIDTH / 5 - Renderer::Instance()->GetTextureSize(textoPlMoves1.id).x / 2 , HUD_HEIGHT / 3 - Renderer::Instance()->GetTextureSize(textoPlMoves1.id).y / 2, Renderer::Instance()->GetTextureSize(textoPlMoves1.id).x, Renderer::Instance()->GetTextureSize(textoPlMoves1.id).y };
	plMoves2Rect = { HUD_WIDTH / 5 - Renderer::Instance()->GetTextureSize(textoPlMoves2.id).x / 2 , 2* HUD_HEIGHT / 3 - Renderer::Instance()->GetTextureSize(textoPlMoves2.id).y / 2, Renderer::Instance()->GetTextureSize(textoPlMoves2.id).x, Renderer::Instance()->GetTextureSize(textoPlMoves2.id).y };
	secRect = { HUD_WIDTH - 100 - Renderer::Instance()->GetTextureSize(textoSec.id).x / 2 , HUD_HEIGHT / 2 - Renderer::Instance()->GetTextureSize(textoSec.id).y / 2, Renderer::Instance()->GetTextureSize(textoSec.id).x, Renderer::Instance()->GetTextureSize(textoSec.id).y };

}

// Imprimim les variables del HUD.
void HUD::draw()
{
	Renderer::Instance()->PushImage("PlMoves1", plMoves1Rect);
	Renderer::Instance()->PushImage("PlMoves2", plMoves2Rect);
	Renderer::Instance()->PushImage("Sec", secRect);

}

// Simplement actualitzem les variables
void HUD::update(int &t, std::vector<int> &movimientos)
{
	tiempoHud = t;
	movimientosHud = movimientos;
	Color textColor = { 255,0,0,0 }; // Color negre.
	//Text textHUD = { TEXT_HUD, "       Vides P1: " + std::to_string(hudLifes[PLAYER_1]) + "/ Score P1: " + std::to_string(hudScores[PLAYER_1]) + " TIME: " + std::to_string(hudTime) + " / Vides P2: " + std::to_string(hudLifes[PLAYER_2]) + "/  Score P2: " + std::to_string(hudScores[PLAYER_2]) + "" , textColor,120,120 };
	//Renderer::Instance()->LoadTextureText(GAME_OVER, textHUD);
}

HUD::~HUD()
{

}

//
//
//// Cargamos las fuentes para el texto
//Font fuenteBoton = { "LetraMenu", "../../res/ttf/saiyan.ttf", 80 };
//Renderer::Instance()->LoadFont(fuenteBoton);
//
//// Creamos las variables Text de todos los botones para poder cargar sus texturas
//Color buttonColor = { 255, 255, 255 }; 
//Text textoBotonLEVEL1 = { "TXT_LEVEL1", "LEVEL ONE", buttonColor,80,80 };
//Text textoBotonLEVEL2 = { "TXT_LEVEL2", "LEVEL TWO", buttonColor,80,80 };
//Text textButtonRANKING = { "TXT_RANKING", "RANKING", buttonColor,80,80 };
//Text textoBotonEXIT = { "TXT_EXIT", "EXIT", buttonColor,80,80 };
//Renderer::Instance()->LoadTextureText("LetraMenu", textoBotonLEVEL1);
//Renderer::Instance()->LoadTextureText("LetraMenu", textoBotonLEVEL2);
//Renderer::Instance()->LoadTextureText("LetraMenu", textoBotonEXIT);
//Renderer::Instance()->LoadTextureText("LetraMenu", textButtonRANKING);
//
//// Creamos los rectángulos para los botones
//SDL_Rect rectBotonLEVEL1{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonLEVEL1.id).x / 2 , SCREEN_HEIGHT / 2 - 150, Renderer::Instance()->GetTextureSize(textoBotonLEVEL1.id).x, Renderer::Instance()->GetTextureSize(textoBotonLEVEL1.id).y };
//SDL_Rect rectBotonLEVEL2{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonLEVEL2.id).x / 2,SCREEN_HEIGHT / 2 - 50, Renderer::Instance()->GetTextureSize(textoBotonLEVEL2.id).x, Renderer::Instance()->GetTextureSize(textoBotonLEVEL2.id).y };
//SDL_Rect rectButtonRANKING{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textButtonRANKING.id).x / 2,SCREEN_HEIGHT / 2 + 50, Renderer::Instance()->GetTextureSize(textButtonRANKING.id).x, Renderer::Instance()->GetTextureSize(textButtonRANKING.id).y };
//SDL_Rect rectBotonEXIT{ SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize(textoBotonEXIT.id).x / 2,SCREEN_HEIGHT / 2 + 150, Renderer::Instance()->GetTextureSize(textoBotonEXIT.id).x, Renderer::Instance()->GetTextureSize(textoBotonEXIT.id).y };
