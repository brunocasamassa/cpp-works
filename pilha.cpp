#include <iostream>

using namespace std;

int adicionar(int vetpilha[], int quantidade, int n);
void imprimirVetor(int vetpilha[], int quantidade);


int main() {

int quantidade=10,n=0;
int vetpilha[10];

while(quantidade>0){
    cout<<"digite um valor a ser inserido a pilha: ";
    cin>>n;

    adicionar(vetpilha,quantidade,n);

    imprimirVetor(vetpilha,quantidade);


}


}

int adicionar(int vetpilha[], int quantidade, int n)
{
if (quantidade < 10)
{
    vetpilha[quantidade]=n;
    quantidade--;

}

 return quantidade;
}

void imprimirVetor(int vetpilha[], int quantidade){
int i = 10;

    while( i > quantidade){
        cout << "["<<vetpilha[i]<<"] ";
        i--;
    }
    cout <<"\n\n";
}
