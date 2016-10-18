#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

//Definindo tamanho da tela
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc,char* args[]){
    //Janela que usara para renderizar
    SDL_Window* window = NULL;
    //Surface contida na janela
    SDL_Surface* screenSurface = NULL;
    //Declarando variaveis
    SDL_Rect r1;
    //- Inicializa a SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout <<"Nao foi possivel inicializar a SDL!  SDL_Error: "<<SDL_GetError() << endl;
        //printf("Nao foi possivel inicializar a SDL!  SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }
    else{
        //Criar janela
        window = SDL_CreateWindow("Meu Mundo",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if( window == NULL ){
            cout <<"Nao foi possivel criar a janela!  SDL_Error: "<<SDL_GetError() << endl;
            //printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else{
            //Surface da janela
            screenSurface = SDL_GetWindowSurface( window );
            //Preencher janela de branco
            SDL_FillRect( screenSurface, NULL, 0xFFFFFF );
            //Criando triangulo
            r1.h=400;
            r1.w=800;
            r1.x=SCREEN_WIDTH-r1.w;
            r1.y=SCREEN_HEIGHT-r1.h;
            SDL_FillRect(screenSurface, &r1, 0x000000);
            //Atualizar surface
            SDL_UpdateWindowSurface( window );
            //Esperar x segundos
            SDL_Delay( 2000 );
        }
    }
    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
