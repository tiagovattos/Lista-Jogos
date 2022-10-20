// Algoritmo Trabalho_2022;
// Bibliotecas da linguagem
#include <iostream>
#include <iomanip>
using namespace std;

//tipos de dados
struct jogos{
    string nome, id, data, dev;  // troquei descricao por nome
    float valor;
    };

//definicao de constantes
const int T = 10;

//definicao de variaveis globais
jogos lista[T], val;
int fim=-1, i, aux, x;
char conf;

//prototipo de funcoes
void preencher();
void imprimir();
void adcNoFim();
void insPorNomeAnt();
void remPorData();
void altNoX();

//programa principal
int main(){
    preencher();
    x = -1;
    while(x!= 0){
        system("cls");
        cout << "-----------------------Menu-----------------------\n\n";
        cout << "0- Sair\n";
        cout << "1- Imprimir\n";
        cout << "2- Adicionar No ao final da lista\n";
        cout << "3- Procurar No por descricao e inserir um novo anterior ao no encontrado\n";
        cout << "4- Procurar um No por data de lancamento e remover\n";
        cout << "5- Alterar No com codigo igual a X";
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
                adcNoFim();
                break;

            case 3:
                insPorNomeAnt();
                break;

            case 4:
                remPorData();
                break;

            case 5:
                altNoX();
                break;

            default:  // demais opcoes
                cout << "Opcao invalida.";
                break;
        }
        cout << endl;
        system("pause");  // pausar o sistema para vizualizacao
    }
}


//corpo das funcoes
void preencher(){
    //lista[n] = {"Nome", "Id", "Data", "Desenvolvedor", valor};fim++;
    lista[0] = {"God Of War", "19", "29/09/2024", "Santa Monica Studio", 230};fim++;
    lista[1] = {"Mario", "5", "09/08/2023", "Nintendo", 50};fim++;
    lista[2] = {"Valorant", "8", "02/06/2021", "Riot Games", 0};fim++;
    lista[3] = {"Until Down", "17", "29/02/2018", "Supermassive Games", 130};fim++;
    lista[4] = {"The Last Of Us", "23", "09/04/2018", "Naughty Dog", 300};fim++;
}
void imprimir(){
    system("cls");
    if(fim != -1){
        for (i=0; i<=fim; i++){
            cout << "No " << i << "\n\n";
            cout << "Nome: " << lista[i].nome;
            cout << "\nid: " << lista[i].id;
            cout << "\nData de lancamento(DD/MM/AAAA): " << lista[i].data;
            cout << "\nDesenvolvedora: " << lista[i].dev;
            cout << "\nValor: R$" << lista[i].valor;
            cout << "\n\n\n";
        }
        cout << "\nFim: " << fim << endl;
    }
    else
        cout << "Lista vazia.\n";
}


void adcNoFim(){
    system("cls");  // limpar tela
    if(fim != T-1){
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
        else
            cout << "Dados nao confirmados\n";
    }
    else
        cout << "Lista cheia\n";
}


void insPorNomeAnt(){
    string buscNome;
    system("cls");
    if(fim != T-1){
        if(fim != -1){
            cout << "Procurar No por nome e inserir um novo anterior ao no encontrado.\n\n";
            cout << "Nome: ";
            cin.ignore();
            getline(cin, buscNome);
            i = 0;
            while((i<fim) && (lista[i].nome != buscNome))
                i++;
            if(lista[i].nome == buscNome){
                system("cls");
                cout << "Nome encontrado - No " << i;
                cout << "\n\nNovo No " << i << endl;
                cout << "Nome: ";
                getline(cin, val.nome);  // cin.ignore() comendo primeiro caractere
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
                    aux = fim;
                    while(aux > i){
                        lista[aux] = lista[aux - 1];
                        aux--;
                    }
                    lista[i] = val;
                }
                else
                    cout << "Dados nao confirmados.\n";
            }
            else
                cout << "Nome nao encontrado\n";
        }
        else
            cout << "Lista vazia.\n";
            }
    else
        cout << "Lista cheia\n";
    }

void remPorData(){
    string buscData;
    system("cls");
    if(fim != -1){
        cout << "Procurar No por data de lancamento e remover\n\n";
        cout << "Data de lancamento[DD/MM/AAAA]: ";
        cin >> buscData;
        i = 0;
        while((i<fim) && (lista[i].data != buscData))
            i++;
        if(lista[i].data == buscData){
            system("cls");
            cout << "Data encontrada\n\n";
            cout << "Confirma remocao?[S][N] ";
            cin >> conf;
            if(conf == 'S'){
                while(i<fim){
                    lista[i] = lista[i+1];
                    i++;
                }
                fim--;
            }
            else
                cout << "Dados nao confirmados\n";
        }
        else
            cout << "Data nao encontrada\n";
    }
    else
        cout << "Lista vazia\n";
}

void altNoX(){
    system("cls");
    int x;
    if(fim != -1){
        cout << "Remover na posicao X\n\n";
        cout << "Digite o valor de X: ";
        cin >> x;
        if((x >= 0) && (x <= fim)){
            cout << "Alterar no " << x;
            cout << "\n\nNome: ";
            cin.ignore();
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
            if(conf == 'S')
                lista[x] = val;
            else
                cout << "Dados nao confirmados\n";
        }
        else
            cout << "Nao ha No de posicao " << x << endl;
    }
    else
        cout << "Lista vazia\n";
}










