#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;
//Declarando a estrutura do ranking
typedef struct{
    int score;
    char nome[50];
}jogador;
//Declarando funções
int buscalinear(jogador v[],char rem,int cont,int *qntd);
void inserir(jogador v[],int *qntd,int *n);
void remover(jogador v[],int *qntd,int *n);
int buscar(jogador v[],int *qntd);
int soma(jogador v[],int *qntd,int cont);

//Inicio programa

int main(){
    int n,indice=0;
    char escolha;
    jogador *ranking;
    //Entrada da quantidade maxima do ranking e alocacao para uso no ranking
    cout << "Digite a quantidade de elementos : ";
    cin >> n;
    ranking = new jogador[n];
    ranking[0].nome[0] = '0';
    ranking[0].score = 0;

    while (escolha != 'F') {
        //entrada de dados
        cout << "Escolha uma das opcoes abaixo." << endl;
        cout << "(I)nserir" << endl << "(R)emover" << endl << "(B)uscar" << endl << "(S)omar" << endl << "(F)echar" << endl;
        cin >> escolha;
        escolha = toupper(escolha);
        //definindo açao
        if(escolha == 'I')
            inserir(ranking,&indice,&n);
        if(escolha == 'R')
            remover(ranking,&indice,&n);
        if(escolha == 'B')
            cout << "Posicao #" << buscar(ranking,&indice) << " no ranking." << endl;
        //impressao do ranking completo
        cout << "        -Ranking-" << endl;
        for(int cont=0; cont < indice; cont++)
            cout << "#" << cont+1 << "  ->  " << ranking[cont].nome << " == " << ranking[cont].score << endl;
         if(escolha == 'S')
            cout << "Soma das pontuacoes : " << soma(ranking,&indice,0) << endl;

    }


}
//Função da busca linear
int buscalinear(jogador v[],char rem[],int cont,int *qntd){
    if(strcmp(v[cont].nome,rem) == 0 || cont == *qntd)
        return cont;
    else
        return buscalinear(v,rem,cont+1,qntd);
}
//Funçao para inserçao de jogador no ranking
void inserir(jogador v[],int *qntd,int *n){
    //declarando variaveis
    jogador add;
    int i;
    //Entrada de dados
    cout << "Digite o nome : ";
    cin >> add.nome;
    cout << "Digite a pontuacao : ";
    cin >> add.score;
    //Impedindo que ultrapasse o maximo alocado para o vetor
    if(*qntd < *n) *qntd = *qntd + 1;
    //Algoritimo para verificar e adicionar novo jogador desejado
    for(i=*qntd-1; i >= 0 && add.score > v[i].score; i--){
        strcpy(v[i+1].nome,v[i].nome);
        v[i+1].score = v[i].score;
        strcpy(v[i].nome,add.nome);
        v[i].score = add.score;
    }
}
//funçao para remover jogador do ranking
void remover(jogador v[],int *qntd,int *n){
    //declarando variaveis
    char rem[50];
    int cont;
    //Entrada de dados
    cout << "Digite o nome : ";
    cin >> rem;
    //algoritimo para retirar buraco do vetor
    for(cont=buscalinear(v,rem,0,qntd); cont<*qntd-1; cont++){
        strcpy(v[cont].nome,v[cont+1].nome);
        v[cont].score = v[cont+1].score;
    }
    if(cont < *qntd)
        *qntd = *qntd - 1;
}
//funçao para buscar determinada pontuaçao
int buscar(jogador v[],int *qntd){
    //declarando variaveis
    int pontos,m,i=0,f=*qntd-1;
    //entrada de dados
    cout << "Digite uma pontuacao : ";
    cin >> pontos;
    //busca binaria
    while(i <= f){
        m =(i+f)/2;
        if(pontos == v[m].score)
            return m+1;
        if(pontos < v[m].score)
            i = m+1;
        else
            f = m-1;
    }
    return -1;
}
//funçao para somar todas as pontuaçoes no ranking
int soma(jogador v[],int *qntd,int cont){
    if(cont == *qntd)
        return 0;
    return v[cont].score+soma(v,qntd,cont+1);
}
