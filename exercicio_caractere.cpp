#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

void kill_letter(char x[], char y){
    int cont=0;
    while(cont < 20){

        if(x[cont] ==  y){
            for(int i =cont; i< 20;i++){
            x[i] = x[i+1];
            }

            }

        else cont++;
    }

}
int main() {

    char name[20];
    char letra;
    cout<<"Write a name: ";
    cin>>name;

    cout<<"letter of name you want remove: ";
    cin>>letra;

    kill_letter(name,letra);
    cout<<"name without the letter: "<<name;
}





