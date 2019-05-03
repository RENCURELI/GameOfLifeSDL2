// GameOfLife.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SDL.h>
#include "Const.h"
using namespace std;

//BUT : Tracer une ligne diagonale en travers de la fenêtre
//ENTREE : Utilisateur lance l'application
//SORTIE : Une ligne rouge est tracé

void Setup();
int nbPoints;


int main(int argc, char* argv[])
{
	Setup();

	SDL_Event event;
	SDL_Renderer* renderer;
	SDL_Window* window;
	int i;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//SDL_RenderDrawPoints(renderer, , nbPoints);
	for (i = 0; i < WINDOW_WIDTH; ++i) //Set coordinates of points
		SDL_RenderDrawPoint(renderer, i, i);
	SDL_RenderPresent(renderer);
	while (1) {
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}


void Setup() 
{
	cout << "ENTER NUMBER OF POINTS : " << endl;
	cin >> nbPoints;
}