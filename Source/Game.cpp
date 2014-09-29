#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_video.h>
#include <SDL_image.h>
#include <SDL.h>


CGame::CGame(){
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);

	//SDL_Surface * screen;
	if (SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf("Error: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode(640, 480,24, SDL_HWACCEL);
	if (screen == NULL)
	{
		printf("Error: %s", SDL_GetError());
		exit(EXIT_FAILURE);		
	}
	SDL_Flip(screen);
	SDL_WM_SetCaption("Mi Primer juego", NULL);
	
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch (estado){
		case Estado::ESTADO_INICIANDO:
		{
			nave = SDL_LoadBMP("../Data/MiNave.bmp");

			SDL_Rect Fuente;
			Fuente.x = 90;
			Fuente.y = 152;
			Fuente.w = 242;
			Fuente.h = 76;
			SDL_Rect destino;
			destino.x = 100;
			destino.y = 100;
			destino.w = 100;
			destino.h = 100;

			SDL_BlitSurface(nave, &Fuente, screen, &destino);

			SDL_BlitSurface(nave, NULL, screen, NULL);

			SDL_FreeSurface(nave);
		}
		case Estado::ESTADO_MENU:
			break;
		case Estado::ESTADO_JUGANDO:
			break;
		case Estado::ESTADO_TERMINANDO:
			salirJuego = true;
			break;
		case Estado::ESTADO_FINALIZANDO:
			break;
		};
    }
	SDL_Flip(screen);
	return true;
}
