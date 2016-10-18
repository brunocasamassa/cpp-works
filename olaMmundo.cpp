/**
  Autor: Fabio Lubacheski
  Objetivo: Desenha uma janela utilizando a biblioteca SDL 2.0
*/
#include <SDL2/SDL.h>
#include <iostream> // inclui cin, cout endl

using namespace std;

int main(int argc, char *argv[]){

    //window que sera usada para renderizar
    SDL_Window *window = NULL;

    //Surface contida no na janela (window)
    SDL_Surface *screenSurface = NULL;

    SDL_FillRect( screenSurface, NULL, 0xFF0000 );

    //- Inicializa a SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout <<"Nao foi possivel inicializar a SDL!  SDL_Error: "<<SDL_GetError() << endl;
        //printf("Nao foi possivel inicializar a SDL!  SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    //Create window>
   window=SDL_CreateWindow("OlaMundo-Minhaprimeirajanela",600,200,800,600,SDL_WINDOW_SHOWN); //x(esq,dir),y(cima,baixo),w,h
    if(window==NULL)
    {
    cout<<"Janelanaopodesercriada!"<<
    "SDL_Error:"<<SDL_GetError()<<endl;
    SDL_Quit();
    return 2;
    }

    // Espera 15 segundos antes de fechar (O que acontece se tirarmos essa linha ?)
    SDL_Delay(1500);

    //Destroi window
    SDL_DestroyWindow( window );

    // desliga todos os subsistemas da SDL e libera recursos alocados a eles.
    // Esta função sempre deve ser chamada antes de você sair.
    SDL_Quit();


    return 0;
}
