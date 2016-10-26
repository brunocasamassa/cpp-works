
#include <SDL2/SDL.h>
#include <iostream> // inclui cin, cout endl

using namespace std;

SDL_Rect r1;

// declaracao de funcoes
void desenha(SDL_Surface *screen, SDL_Window *window, SDL_Surface *img );

int main(int argc, char *argv[]){

    /*INICIO
     *preparar o ambiente para jogo (Inicializações, carregar conteúdo do jogo, etc); */


    //window que serah usada para renderizar
    SDL_Window* window = NULL;
    SDL_Event evento;
    int contEvento = 0;
    int teclaPressionada=0;

    int JogoAtivo = 1;

    //Surface contida no na janela (window)
    SDL_Surface* screenSurface = NULL, *imagem;


    //- Inicializa a SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout <<"Nao foi possivel inicializar a SDL!  SDL_Error: "<<SDL_GetError() << endl;
        //printf("Nao foi possivel inicializar a SDL!  SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    //Create window
    window = SDL_CreateWindow("Ola Mundo - Minha primeira janela",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              700,
                              400,
                              SDL_WINDOW_SHOWN);


    if( window == NULL )
    {
        cout <<"Janela nao pode ser criada!  SDL_Error: "<< SDL_GetError() << endl;
        SDL_Quit();
        return 2;
    }
    //obtema surface da janela
    screenSurface= SDL_GetWindowSurface( window );

    // carrega a imagem do arquivo
    // e se imagem estiver em outra pasta ?
    imagem = SDL_LoadBMP("smiley.bmp");

    // tornando fundo transparente de uma imagem
    // R=0xFF G=0x0 B=0xFF
    SDL_SetColorKey(imagem,SDL_TRUE,0xff00FF);

    if( imagem == NULL )
    {
        cout <<"Imagem nao carregada !  SDL_Error: "<< SDL_GetError() << endl;
        cin >> contEvento;
        SDL_Quit();
        return 3;
    }

    r1.x = (screenSurface->w / 2)-(imagem->w/2);
    r1.y = 10;


    /*FIM
     *preparar o ambiente para jogo (Inicializações, carregar conteúdo do jogo, etc); */

    /*INICIO
     *GAMELOOP*/
    while( JogoAtivo ==1 ){


        //Ler a entrada de dados do usuário
        //Enquanto houver eventos na fila
        while( SDL_PollEvent(&evento) ) {
                contEvento++;
                    if( evento.type == SDL_KEYDOWN ){
                    // Verificar se eh seta para baixo
                    if(evento.key.keysym.sym == SDLK_DOWN){
                        cout << contEvento<<" - pressionei SETA PARA BAIXO !\n";
                        teclaPressionada = 1;
                    }

                    cout << contEvento<<" - pressionei uma tecla  !\n";

                }
                if( evento.type == SDL_KEYUP ){
                    cout << contEvento<<" - liberei uma tecla  !\n";
                    teclaPressionada = 0;
                }

                // trato o evento
                if( evento.type == SDL_QUIT){

                    JogoAtivo = 0;
                }

        }

        //Realizar os cálculos (IA, movimentos, detecção de colisão, etc)]
        if( teclaPressionada ==1 && r1.y + r1.h < screenSurface->h)
            r1.y+=10;


        //Desenhar a tela, gerar sons, etc...
        desenha(screenSurface, window, imagem);



        // Espera 15 segundos antes de fechar (O que acontece se tirarmos essa linha ?)
        SDL_Delay(50);

    }
    /*INCIO
     *liberar o ambiente, desfazendo o  que foi realizado quando o jogo começou.*/

    // liberar a memoria da imagem carregada
    SDL_FreeSurface(imagem);

    //Destroi window
    SDL_DestroyWindow( window );

    // desliga todos os subsistemas da SDL e libera recursos alocados a eles.
    // Esta função sempre deve ser chamada antes de você sair.
    SDL_Quit();

    /*FIM
     *liberar o ambiente, desfazendo o  que foi realizado quando o jogo começou.*/

    return 0;
}
// desenha na janela
void desenha(SDL_Surface *screen, SDL_Window *window, SDL_Surface *img )
{




    //Limpa o fundo da janela com a cor branca
    SDL_FillRect( screen, NULL, 0xFFFFFF );

    SDL_BlitSurface(img, NULL, screen, &r1);

    //atualiza a surface na janela da aplicação
    SDL_UpdateWindowSurface(window);

}
