// Algoritmo Trabalho_2022;
// Bibliotecas da linguagem
#include <iostream>
#include <iomanip>
using namespace std;

//tipos de dados
struct jogos{
    string nome, id, data, dev;  // descricao foi trocado por nome
    float valor;
    };

//definicao de constantes
const int T = 6;

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
void remNoK();
void impNoDes();
void remPorIdAnt();
void impVal200();
void altNoNome();

//programa principal
int main(){
    preencher();
    x = -1;
    while(x!= 0){
        system("cls");
        cout << "\t\tLista de Jogos\n\n";
        cout << "\t0  - Sair\n";
        cout << "\t1  - Imprimir\n";
        cout << "\t2  - Adicionar No ao final da lista\n";
        cout << "\t3  - Procurar No por descricao e inserir um novo anterior ao no encontrado\n";
        cout << "\t4  - Procurar um No por data de lancamento e remover\n";
        cout << "\t5  - Alterar No com codigo igual a X\n";
        cout << "\t6  - Remover No com codigo igual a K\n";
        cout << "\t7  - Consultar No pelo nome do desenvolvedor\n";
        cout << "\t8  - Procurar um No por id e remover o anterior\n";
        cout << "\t9  - Imprimir a quantidade de Nos impares com valor maior ou igual a R$200,00\n";
        cout << "\t10 - Procurar um No por nome e alterar o seu conteudo\n";
        cout << "\n\tDigite uma opcao: ";
        cin >> x;
        switch(x){
            case 0: cout << "\n\tSaindo..."; break;

            case 1: imprimir(); break;

            case 2: adcNoFim(); break;

            case 3: insPorNomeAnt(); break;

            case 4: remPorData(); break;

            case 5: altNoX(); break;

            case 6: remNoK(); break;

            case 7: impNoDes(); break;

            case 8: remPorIdAnt(); break;

            case 9: impVal200(); break;

            case 10: altNoNome(); break;

            default: cout << "Opcao invalida."; break; // demais opcoes
        }
        cout << endl << "\t";
        system("pause");  // pausar o sistema para vizualizacao
    }
}


//corpo das funcoes
void preencher(){
    //lista[n] = {"Nome", "Id", "Data", "Desenvolvedor", valor};fim++;
    lista[0] = {"God Of War", "19", "29/09/2024", "Santa Monica Studio", 230};fim++;
    lista[1] = {"Mario", "5", "09/08/2023", "Nintendo", 250};fim++;
    lista[2] = {"Valorant", "8", "02/06/2021", "Riot Games", 0};fim++;
    lista[3] = {"Until Down", "17", "29/02/2018", "Supermassive Games", 130};fim++;
    lista[4] = {"The Last Of Us", "23", "09/04/2018", "Naughty Dog", 300};fim++;
    lista[5] = {"League Of Legends", "7", "17/09/2010", "Riot Games", 200};fim++;
}

void imprimir(){
    system("cls");
    cout << fixed << setprecision(2);
    if(fim != -1){
        for(i=0; i<=fim; i++){
            cout << "No " << i << "\n\n";
            cout << setw(28) << "Nome: " << lista[i].nome << endl;
            cout << setw(28) << "id: " << lista[i].id << endl;
            cout << setw(28) << "Data de lancamento: " << lista[i].data << endl;
            cout << setw(28) << "Desenvolvedora: " << lista[i].dev << endl;
            cout << setw(31) << "Valor: R$ " << setw(6) << lista[i].valor << endl;
            cout << endl;
        }
    }
    else cout << "Lista vazia.\n";
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
        else cout << "Dados nao confirmados\n";
    }
    else cout << "Lista cheia\n";
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
                else cout << "Dados nao confirmados.\n";
            }
            else cout << "Nome nao encontrado\n";
        }
        else cout << "Lista vazia.\n";
    }
    else cout << "Lista cheia\n";
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
            else cout << "Dados nao confirmados\n";
        }
        else cout << "Data nao pertence a lista\n";
    }
    else cout << "Lista vazia\n";
}

void altNoX(){
    int X;
    system("cls");
    if(fim != -1){
        cout << "Alterar na posicao X\n\n";
        cout << "Digite o valor de X: ";
        cin >> X;
        if((X >= 0) && (X <= fim)){
            cout << "Alterar no " << X;
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
                lista[X] = val;
            else cout << "Dados nao confirmados\n";
        }
        else cout << "Nao ha No de posicao " << X << endl;
    }
    else cout << "Lista vazia\n";
}

void remNoK(){
    int K;
    system("cls");
    if(fim != -1){
        cout << "Remover na posicao K\n";
        cout << "Digite o valor de K: ";
        cin >> K;
        if((K >= 0) && (K <= fim)){
            cout << "\nConfirma?[S][N] ";
            cin >> conf;
            if(conf == 'S'){
                while(K < fim){
                    lista[K] = lista[K+1];
                    K = K + 1;
                }
                fim--;
            }
            else cout << "Dados nao confirmados\n";
        }
        else cout << "Nao ha No de posicao " << K << endl;
    }
    else cout << "Lista vazia\n";
}

void impNoDes(){
    string buscDev;
    int cont=0;
    system("cls");
    if(fim != -1){
        cout << "Consultar No pelo nome do desenvolvedor\n\n";
        cout << "Desenvolvedor: ";
        cin.ignore();
        getline(cin, buscDev);
        for(i=0; i<=fim; i++){
            if(buscDev == lista[i].dev){
                cout << "\nNo " << i << "\n\n";
                cout << "Nome: " << lista[i].nome;
                cout << "\nid: " << lista[i].id;
                cout << "\nData de lancamento(DD/MM/AAAA): " << lista[i].data;
                cout << "\nDesenvolvedora: " << lista[i].dev;
                cout << "\nValor: R$" << lista[i].valor;
                cout << "\n\n\n";
                cont++;
            }
        }
        if(cont == 0)
            cout << "Nao ha jogos desse desenvolvedor cadastrados\n";
    }
    else cout << "Lista vazia\n";
}

void remPorIdAnt(){
    string buscId;
    system("cls");
    if(fim != -1){
        cout << "Procurar um No por id e remover o anterior\n\n";
        cout << "Id: ";
        cin >> buscId;
        i = 0;
        while((i < fim) && (buscId!=lista[i].id))
            i++;
        if((buscId == lista[i].id)){
            if(i != 0){
                cout << "Id encontrado - No " << i << endl;
                cout << "Remocao do No " << i-1 << endl;
                cout << "Confirma?[S][N] ";
                cin >> conf;
                if(conf == 'S'){
                    i = i - 1;
                    while(i < fim){
                        lista[i] = lista[i+1];
                        i++;
                    }
                    fim--;
                }
                else cout << "Dados nao confirmados";
            }
            else cout << "Id encontrado - No " << i << "\nNao e possivel remover o anterior, pois o No esta no inicio\n";
        }
        else cout << "Id nao pertence a lista";
    }
    else cout << "Lista vazia";
}

void impVal200(){
    int cont;
    system("cls");
    if(fim != -1){
        for(i=0; i<=fim; i++)
            if(i%2 == 1)
                if(lista[i].valor >= 200)
                    cont++;
        cout << "Quantidade de Nos impares com valor maior ou igual a R$200,00: " << cont << endl;
    }
    else cout << "Lista vazia\n";
}

void altNoNome(){
    string buscNome;
    system("cls");
    if(fim != -1){
        cout << "Procurar um No por nome e alterar o seu conteudo\n";
        cout << "Nome: ";
        cin.ignore();
        getline(cin, buscNome);
        while((i < fim) && (buscNome != lista[i].nome))
            i++;
        if(buscNome == lista[i].nome){
            cout << "Alterar no " << i;
            cout << "\n\nNome: ";
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
                lista[i] = val;
            else cout << "Dados nao confirmados\n";
        }
        else cout << "Nome nao pertence a lista\n";
    }
    else cout << "Lista vazia\n";
}



