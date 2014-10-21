#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>
#include "Config.h"
#include "Sprite.h"

CGame::CGame()
{
	estado = Estado::ESTADO_INICIANDO;
	atexit(SDL_Quit);
<<<<<<< HEAD
}
void CGame::Iniciando(){


	if (SDL_Init(SDL_INIT_AUDIO)){
		printf("Error %s ", SDL_GetError());
=======
	//ACT3: Mal, este codigo no va aqui.
	////ACT3: Mal, la inicializacion de abajo, debe estar en metodo llamado iniciando.
	//SDL_Surface * screen;
	//if (SDL_Init(SDL_INIT_VIDEO)<0)
	//{
	//	printf("Error: %s", SDL_GetError());
	//	exit(EXIT_FAILURE);
	//}
	//screen = SDL_SetVideoMode(640, 480,24, SDL_HWACCEL);
	//if (screen == NULL)
	//{
	//	printf("Error: %s", SDL_GetError());
	//	exit(EXIT_FAILURE);		
	//}
	//SDL_Flip(screen);
	//SDL_WM_SetCaption("Mi Primer juego", NULL);
}

//ACT3: Mal, falto el metodo "iniciando()"
void CGame::Iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf("Error: %s", SDL_GetError());
>>>>>>> 8a03039870a065c0b2cef2974dc9d3a5a13e5543
		exit(EXIT_FAILURE);

	}
<<<<<<< HEAD

	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);

	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip(screen);
	SDL_WM_SetCaption("Mi primer Juego", NULL);
	nave = new Nave(screen, "../Data/minave.bmp");
	//nave->CargarImagen("../Data/minave.bmp");
=======
	screen = SDL_SetVideoMode(640, 480, 24, SDL_HWACCEL);
	if (screen == NULL)
	{
		printf("Error: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	SDL_WM_SetCaption("Mi Primer juego", NULL);
>>>>>>> 8a03039870a065c0b2cef2974dc9d3a5a13e5543
}
void CGame::Finalize()
{
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false; char menu;
	int b = 0;
	while (salirJuego == false)
	{
		//Maquina de estados
<<<<<<< HEAD
		switch (estado)
=======
		switch (estado){
		case Estado::ESTADO_INICIANDO:
			Iniciando();//ACT3: Falto mandar a llamar este metodo.
			estado = ESTADO_MENU;
			break;//ACT2: Mal, falto este break.
		case Estado::ESTADO_MENU:
>>>>>>> 8a03039870a065c0b2cef2974dc9d3a5a13e5543
		{
		case Estado::ESTADO_INICIANDO:
			printf("\nEstado Iniciado.....[1] ");
			Iniciando();
			estado = ESTADO_MENU;
			break;

<<<<<<< HEAD
		case Estado::ESTADO_MENU:
			printf("\nEstado Menu.........[2] ");
			
				SDL_FillRect(screen, NULL, 0x005500);
				keys = SDL_GetKeyState(NULL);
				if (keys[SDLK_RIGHT]){
					nave->Mover(10);
				}
				nave->Pintar();
				if (b == 0)
				{
					estado = ESTADO_JUGANDO;
					b = 1;
				}
				else
				{
					estado = ESTADO_FINALIZADO;
				}
=======
			SDL_FreeSurface(nave);
		}
>>>>>>> 8a03039870a065c0b2cef2974dc9d3a5a13e5543
			break;
		case Estado::ESTADO_JUGANDO:
			printf("\nEstado Jugando......[3] ");
			estado = ESTADO_TERMINANDO;
			break;
		case Estado::ESTADO_FINALIZADO:
			printf("\nEstado Finalizado...[4] ");
			getchar();
			salirJuego = true;
			break;
		case Estado::ESTADO_TERMINANDO:
			printf("\nEstado Terminado....[5] ");
			estado = ESTADO_MENU;

			break;
		};
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT){ salirJuego = true; }
			if (event.type == SDL_KEYDOWN){}
		}
		SDL_Flip(screen);// imprimir en pantalla la variable screen
	}
	return true;
}
