#include <iostream>
#include <string.h>
using namespace std;
typedef struct{
        char nome[50];
        int pontos;
}TJogador;
int insere (TJogador *vetjogador, TJogador novo, int qtd);
int imprimir (TJogador *vetjogador, int qtd);
int remover (TJogador *vetjogador, char nomerem[], int qtd, int cont);
int buscar(TJogador *vetjogador, char nomerem[] , int cont);
int buscarscore (TJogador *vetjogador, int qtd, int ponto);
int soma(TJogador *vetjogador,int aux,int qtd);

int main ()
{

    int n, nmax, qtdjogador=0, rem=0,valor=0,aux=0,ponto;
    char nomerem[50];
    TJogador *vetjogador, novo;
    cout<<"digite quantos jogadores possiveis entrarao no ranking: ";
    cin>>nmax;

     vetjogador = new TJogador[nmax];

    while(n!=5)
    {
        cout<<"Digite uma das opcoes abaixo: "<<endl;
        cout<<"1- adicionar usuario no ranking"<<endl;
        cout<<"2- remover usuario no ranking"<<endl;
        cout<<"3- buscar usuario no ranking"<<endl;
        cout<<"4- soma das pontuacoes"<<endl;
        cout<<"5- SAIR"<<endl;
        cin>>n;
        if(n==1)
        {
            cout<<"Digite o nome do jogador a ser inserido: ";
            cin>>novo.nome;
            cout<<"Digite a pontuacao do jogador a ser inserido: ";
            cin>>novo.pontos;
            qtdjogador = insere(vetjogador, novo, qtdjogador);
            imprimir (vetjogador , qtdjogador);
         }
        if(n==2)
        {
            cout<<"digite o nome do jogador que deseja remover: ";
            cin>>nomerem;
            qtdjogador=remover(vetjogador,nomerem,qtdjogador,0);
            imprimir (vetjogador , qtdjogador);
       }
        if(n==3)
        {
            cout<<"digite a pontuacao do jogador que deseja encontrar: ";
            cin>>ponto;
            //qtdjogador=remover(vetjogador,nomerem, qtdjogador);
            cout<<endl<<"Encontrado na posicao "<<buscarscore(vetjogador,qtdjogador,ponto)<<endl<<endl;
       }
       if(n==4)
        {
          cout<<soma(vetjogador,aux,qtdjogador);

       }

     }


}

int insere(TJogador *vetjogador, TJogador novo , int qtd)
{

        int i=qtd;

       while(i >= 0 && novo.pontos > vetjogador[i].pontos){
        vetjogador[i+1] = vetjogador[i];
        i--;
       }

       vetjogador[i] = novo;
       return qtd;

}
int imprimir(TJogador *vetjogador, int qtd){
   for(int i=0; i<qtd; i++){
     cout<<endl<<"posicao: "<<i+1<<" Jogador: "<<vetjogador[i].nome<<" - Pontuacao: "<<vetjogador[i].pontos<<endl<<endl;
   }
}
int remover (TJogador *vetjogador, char nomerem[] , int qtd, int cont){
        cont=buscar(vetjogador,nomerem,cont);
        while(cont<qtd)
        {
        vetjogador[cont]=vetjogador[cont+1];
        cont++;
        }
        return qtd-1;
    }


int buscar(TJogador *vetjogador, char nomerem[] , int cont)
{
    if (strcmp (nomerem,vetjogador[cont].nome)==0)
    {
            return cont;
    }
    else return buscar(vetjogador, nomerem , cont+1);
}

int buscarscore (TJogador *vetjogador, int qtd, int ponto)
{
     int i, m, f;
    i = 0; f = qtd-1;
    while (i <= f)
        {
      m = (i+f)/2;
      if (ponto == vetjogador[m].pontos)
        return m+1;
      if (ponto < vetjogador[m].pontos) i = m + 1;
      else f = m - 1;
         }

}



int soma(TJogador *vetjogador,int aux,int qtd)
{
     if (aux==qtd) return 0;
       return vetjogador[aux].pontos+soma(vetjogador,aux+1,qtd);

}





