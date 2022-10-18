// Algoritmo Trabalho_2022;
// Bibliotecas da linguagem
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//tipos de dados
struct jogos{
    string id, data, dev, nome;
    float valor;
    };

//definicao de constantes
const int T = 1;

//definicao de variaveis globais
jogos lista[T], val, aux, aux2;
string buscNome;
int inicio=0, fim=-1, i, j, x;
char y, conf;

//prototipo de funcoes
void adcFim();
void insAnt();
void imprimir();

//programa principal
int main(){
    x = -1;
    while(x!= 0){
        system("cls");
        cout << "-----------------------Menu-----------------------\n\n";
        cout << "0- Sair\n";
        cout << "1- Imprimir\n";
        cout << "2- Adicionar No ao final da lista\n";
        cout << "3- Procurar No por descricao e inserir um novo anterior ao no encontrado\n";
        cout << "\nDigite uma opcao: ";
        cin >> x;
        switch(x) {
            case 0:
                cout << "\nSaindo...";
                break;

            case 1:
                imprimir();
                break;

            case 2:
                adcFim();
                break;

            case 3:
                insAnt();
                break;

            default:  // demais opcoes
                cout << "Opcao invalida.";
        }
        cout << endl;
        system("pause");  // pausar o sistema para vizualizacao
    }
}


//corpo das funcoes
void imprimir(){
    system("cls");
    if(fim != -1){
        for (i=inicio; i<=fim; i++){
            cout << "No " << i << "\n\n";
            cout << "Nome: " << lista[i].nome;
            cout << "\nid: " << lista[i].id;
            cout << "\nData de lancamento(DD/MM/AAAA): " << lista[i].data;
            cout << "\nDesenvolvedora: " << lista[i].dev;
            cout << "\nValor: R$" << lista[i].valor;
            cout << "\n\n\n";
        }
        cout << "\n\nInicio: " << inicio << "\nFim: " << fim << endl;
    }
    else
        cout << "Lista vazia.\n";
}


void adcFim(){
    system("cls");  // limpar tela
    if(fim < T-1){
        cout << "Adicionar no ao final da lista\n";
        cout << "\n\nNovo No " << fim + 1 << "\n\n";
        cout << "Nome: ";
        cin.ignore();  // getline() funcionar corretamente
        getline(cin, val.nome);  // pega a linha inteira e nao da problema caso tenha espa�os
        cout << "id: ";
        cin >> val.id;
        cout << "Data de lancamento(DD/MM/AAAA): ";
        cin >> val.data;
        cout << "Desenvolvedora: ";
        cin.ignore();
        getline(cin, val.dev);
        cout << "Valor: R$";
        cin >> val.valor;
        cout << "\nConfirma?[S][N] ";
        cin >> conf;
        if(conf == 'S'){
            fim++;
            lista[fim] = val;
        }
    }
    else
        cout << "Lista cheia\n";
}


void insAnt(){
    system("cls");
    if(fim < T-1){
        if(fim != -1){
            cout << "Procurar no por descricao e inserir um novo anterior ao no encontrado.\n\n";
            cout << "Nome: ";
            cin.ignore();
            getline(cin, buscNome);
            system("cls");
            for(i=0;i<T;i++){
                if(buscNome == lista[i].nome)
                    break;
                }
            if(i < T){
                cout << "Nome encontrado - No " << i;
                cout << "\n\nNovo No " << i << endl;
                cout << "Nome: ";
                getline(cin, val.nome);
                cout << "id: ";
                cin >> val.id;
                cout << "Data de lancamento(DD/MM/AAAA): ";
                cin >> val.data;
                cout << "Desenvolvedora: ";
                cin.ignore();
                getline(cin, val.dev);
                cout << "Valor: R$";
                cin >> val.valor;
                cout << "\nConfirma?[S][N] ";
                cin >> conf;
                if(conf == 'S'){
                    aux = lista[i];
                    lista[i] = val;
                    while(i<fim+1){
                        aux2 = lista[i+1];
                        lista[i+1] = aux;
                        aux = aux2;
                        i++;
                    }
                    fim++;
                }
                else
                    cout << "Dados nao confirmados.\n";
            }
            else
                cout << "No nao encontrado.\n";
            }
        else
            cout << "Lista vazia.\n";
        }
    else
        cout << "Lista cheia\n";
}







