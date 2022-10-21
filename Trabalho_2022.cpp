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
const int T = 10;

//definicao de variaveis globais
jogos lista[T], val;
int fim=-1, i, aux, x;
char conf;

//prototipo de funcoes
void preencher();
void imprimir();
void insNoFim();
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
        cout << "\t1  - Imprimir lista\n";
        cout << "\t2  - Inserir No ao final da lista\n";
        cout << "\t3  - Procurar No por nome e inserir um novo anterior ao no encontrado\n";
        cout << "\t4  - Procurar um No por data de lancamento e remover\n";
        cout << "\t5  - Alterar No com codigo igual a X\n";
        cout << "\t6  - Remover No com codigo igual a K\n";
        cout << "\t7  - Consultar No pelo nome do desenvolvedor\n";
        cout << "\t8  - Procurar um No por id e remover o anterior\n";
        cout << "\t9  - Imprimir a quantidade de Nos impares com valor maior ou igual a R$200.00\n";
        cout << "\t10 - Procurar um No por nome e alterar o seu conteudo\n";
        cout << "\n\tDigite uma opcao: ";
        cin >> x;
        switch(x){
            case 0: cout << "\n\tSaindo..."; break;

            case 1: imprimir(); break;

            case 2: insNoFim(); break;

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
    cout << "\t\tImprimir lista de Jogos\n\n";
    if(fim != -1){
        for(i=0; i<=fim; i++){
            cout << "No " << i << "\n";
            cout << setw(28) << "Nome: " << lista[i].nome << endl;
            cout << setw(28) << "id: " << lista[i].id << endl;
            cout << setw(28) << "Data de lancamento: " << lista[i].data << endl;
            cout << setw(28) << "Desenvolvedor: " << lista[i].dev << endl;
            cout << setw(31) << "Valor: R$ " << setw(6) << lista[i].valor << endl;
            cout << endl;
        }
    }
    else cout << "\tLista vazia\n";
}

void insNoFim(){
    system("cls");  // limpar tela
    cout << "\t\tInserir No ao final da lista\n";
    if(fim != T-1){
        cout << "\nNovo No " << fim + 1 << "\n";
        cout << setw(28) << "Nome: ";
        cin.ignore();  // getline() funcionar corretamente
        getline(cin, val.nome);  // pega a linha inteira e nao da problema caso tenha espaços
        cout << setw(28) << "id: ";
        cin >> val.id;
        cout << setw(28) << "Data de lancamento: ";
        cin >> val.data;
        cout << setw(28) << "Desenvolvedor: ";
        cin.ignore();
        getline(cin, val.dev);
        cout << setw(31) << "Valor: R$ ";
        cin >> val.valor;
        cout << "\n\tConfirma insercao?[S][N] ";
        cin >> conf;
        if(conf == 'S'){
            fim++;
            lista[fim] = val;
        }
        else cout << "\tDados nao confirmados\n";
    }
    else cout << "\n\tLista cheia\n";
}

void insPorNomeAnt(){
    string buscNome;
    system("cls");
    cout << "\t\tProcurar No por nome e inserir um novo anterior ao no encontrado\n\n";
    if(fim != T-1){
        if(fim != -1){
            cout << "\tNome: ";
            cin.ignore();
            getline(cin, buscNome);
            i = 0;
            while((i<fim) && (lista[i].nome != buscNome))
                i++;
            if(lista[i].nome == buscNome){
                cout << "\tNome encontrado - No " << i;
                cout << "\n\nNovo No " << i << endl;
                cout << setw(28) << "Nome: ";
                getline(cin, val.nome);
                cout << setw(28) << "id: ";
                cin >> val.id;
                cout << setw(28) << "Data de lancamento: ";
                cin >> val.data;
                cout << setw(28) << "Desenvolvedor: ";
                cin.ignore();
                getline(cin, val.dev);
                cout << setw(31) << "Valor: R$ ";
                cin >> val.valor;
                cout << "\n\tConfirma insercao?[S][N] ";
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
                else cout << "\tDados nao confirmados\n";
            }
            else cout << "\tNome nao encontrado\n";
        }
        else cout << "\tLista vazia\n";
    }
    else cout << "\tLista cheia\n";
}

void remPorData(){
    string buscData;
    system("cls");
    cout << fixed << setprecision(2);
    cout << "\t\tProcurar No por data de lancamento e remover\n\n";
    if(fim != -1){
        cout << "\tData de lancamento: ";
        cin >> buscData;
        i = 0;
        while((i<fim) && (lista[i].data != buscData))
            i++;
        if(lista[i].data == buscData){
            cout << "\tData encontrada\n\n";
            cout << "No " << i << "\n";
            cout << setw(28) << "Nome: " << lista[i].nome << endl;
            cout << setw(28) << "id: " << lista[i].id << endl;
            cout << setw(28) << "Data de lancamento: " << lista[i].data << endl;
            cout << setw(28) << "Desenvolvedor: " << lista[i].dev << endl;
            cout << setw(31) << "Valor: R$ " << setw(6) << lista[i].valor << endl;
            cout << endl;
            cout << "\tConfirma remocao?[S][N] ";
            cin >> conf;
            if(conf == 'S'){
                while(i<fim){
                    lista[i] = lista[i+1];
                    i++;
                }
                fim--;
            }
            else cout << "\tDados nao confirmados\n";
        }
        else cout << "\tData nao encontrada\n";
    }
    else cout << "\tLista vazia\n";
}

void altNoX(){
    int X;
    system("cls");
    cout << "\t\tAlterar na posicao X\n\n";
    cout << fixed << setprecision(2);
    if(fim != -1){
        cout << "\tDigite o valor de X: ";
        cin >> X;
        if((X >= 0) && (X <= fim)){
            cout << "\nNo " << X << "\n";
            cout << setw(28) << "Nome: " << lista[X].nome << endl;
            cout << setw(28) << "id: " << lista[X].id << endl;
            cout << setw(28) << "Data de lancamento: " << lista[X].data << endl;
            cout << setw(28) << "Desenvolvedor: " << lista[X].dev << endl;
            cout << setw(31) << "Valor: R$ " << setw(6) << lista[X].valor << endl;
            cout << "\nAlterar No " << X << endl;
            cout << setw(28) << "Nome: ";
            cin.ignore();
            getline(cin, val.nome);
            cout << setw(28) << "id: ";
            cin >> val.id;
            cout << setw(28) << "Data de lancamento: ";
            cin >> val.data;
            cout << setw(28) << "Desenvolvedor: ";
            cin.ignore();
            getline(cin, val.dev);
            cout << setw(31) << "Valor: R$ ";
            cin >> val.valor;
            cout << "\n\tConfirma alteracao?[S][N] ";
            cin >> conf;
            if(conf == 'S')
                lista[X] = val;
            else cout << "\tDados nao confirmados\n";
        }
        else cout << "\tNao ha No de posicao " << X << endl;
    }
    else cout << "\tLista vazia\n";
}

void remNoK(){
    int K;
    system("cls");
    cout << "\t\tRemover na posicao K\n\n";
    cout << fixed << setprecision(2);
    if(fim != -1){
        cout << "\tDigite o valor de K: ";
        cin >> K;
        if((K >= 0) && (K <= fim)){
            cout << "\nNo " << K << "\n";
            cout << setw(28) << "Nome: " << lista[K].nome << endl;
            cout << setw(28) << "id: " << lista[K].id << endl;
            cout << setw(28) << "Data de lancamento: " << lista[K].data << endl;
            cout << setw(28) << "Desenvolvedor: " << lista[K].dev << endl;
            cout << setw(31) << "Valor: R$ " << setw(6) << lista[K].valor << endl;
            cout << "\n\tConfirma remocao?[S][N] ";
            cin >> conf;
            if(conf == 'S'){
                while(K < fim){
                    lista[K] = lista[K+1];
                    K = K + 1;
                }
                fim--;
            }
            else cout << "\tDados nao confirmados\n";
        }
        else cout << "\tNao ha No de posicao " << K << endl;
    }
    else cout << "\tLista vazia\n";
}

void impNoDes(){
    string buscDev;
    int cont=0;
    system("cls");
    cout << "\t\tConsultar No pelo nome do desenvolvedor\n\n";
    cout << fixed << setprecision(2);
    if(fim != -1){
        cout << "\tDesenvolvedor: ";
        cin.ignore();
        getline(cin, buscDev);
        for(i=0; i<=fim; i++){
            if(buscDev == lista[i].dev){
                cout << "\nNo " << i << "\n";
                cout << setw(28) << "Nome: " << lista[i].nome << endl;
                cout << setw(28) << "id: " << lista[i].id << endl;
                cout << setw(28) << "Data de lancamento: " << lista[i].data << endl;
                cout << setw(28) << "Desenvolvedor: " << lista[i].dev << endl;
                cout << setw(31) << "Valor: R$ " << setw(6) << lista[i].valor << endl;
                cont++;
            }
        }
        if(cont == 0)
            cout << "\tNao ha jogos desse desenvolvedor cadastrados\n";
    }
    else cout << "\tLista vazia\n";
}

void remPorIdAnt(){
    string buscId;
    system("cls");
    cout << "\t\tProcurar um No por id e remover o anterior\n\n";
    cout << fixed << setprecision(2);
    if(fim != -1){
        cout << "\tId: ";
        cin >> buscId;
        i = 0;
        while((i < fim) && (buscId!=lista[i].id))
            i++;
        if((buscId == lista[i].id)){
            if(i != 0){
                cout << "\tId encontrado - No " << i << endl;
                i = i - 1;
                cout << "\nRemocao do No " << i << endl;
                cout << setw(28) << "Nome: " << lista[i].nome << endl;
                cout << setw(28) << "id: " << lista[i].id << endl;
                cout << setw(28) << "Data de lancamento: " << lista[i].data << endl;
                cout << setw(28) << "Desenvolvedor: " << lista[i].dev << endl;
                cout << setw(31) << "Valor: R$ " << setw(6) << lista[i].valor << endl;
                cout << "\n\tConfirma remocao?[S][N] ";
                cin >> conf;
                if(conf == 'S'){
                    while(i < fim){
                        lista[i] = lista[i+1];
                        i++;
                    }
                    fim--;
                }
                else cout << "\tDados nao confirmados\n";
            }
            else cout << "\tId encontrado - No " << i << "\n\n\tNao e possivel remover o anterior, pois o No esta no inicio\n";
        }
        else cout << "\tId nao encontrado\n";
    }
    else cout << "\tLista vazia\n";
}

void impVal200(){
    int cont=0;
    system("cls");
    cout << fixed << setprecision(2);
    cout << "\t\tImprimir a quantidade de Nos impares com valor maior ou igual a R$200.00\n\n";
    if(fim != -1){
        for(i=0; i<=fim; i++)
            if(i%2 == 1)
                if(lista[i].valor >= 200){
                    cont++;
                    cout << "No " << i << "\n";
                    cout << setw(28) << "Nome: " << lista[i].nome << endl;
                    cout << setw(28) << "id: " << lista[i].id << endl;
                    cout << setw(28) << "Data de lancamento: " << lista[i].data << endl;
                    cout << setw(28) << "Desenvolvedor: " << lista[i].dev << endl;
                    cout << setw(31) << "Valor: R$ " << setw(6) << lista[i].valor << "\n\n";
                }
        cout << "\tQuantidade de Nos impares com valor maior ou igual a R$200.00: " << cont << endl;
    }
    else cout << "\tLista vazia\n";
}

void altNoNome(){
    string buscNome;
    system("cls");
    cout << "\t\tProcurar um No por nome e alterar o seu conteudo\n";
    cout << fixed << setprecision(2);
    if(fim != -1){
        cout << "\n\tNome: ";
        cin.ignore();
        getline(cin, buscNome);
        i = 0;
        while((i < fim) && (buscNome != lista[i].nome))
            i++;
        if(buscNome == lista[i].nome){
            cout << "\nNo " << i << "\n";
            cout << setw(28) << "Nome: " << lista[i].nome << endl;
            cout << setw(28) << "id: " << lista[i].id << endl;
            cout << setw(28) << "Data de lancamento: " << lista[i].data << endl;
            cout << setw(28) << "Desenvolvedor: " << lista[i].dev << endl;
            cout << setw(31) << "Valor: R$ " << setw(6) << lista[i].valor << endl;
            cout << endl;
            cout << "Alterar No " << i << endl;
            cout << setw(28) << "Nome: ";
            getline(cin, val.nome);
            cout << setw(28) << "id: ";
            cin >> val.id;
            cout << setw(28) << "Data de lancamento: ";
            cin >> val.data;
            cout << setw(28) << "Desenvolvedor: ";
            cin.ignore();
            getline(cin, val.dev);
            cout << setw(31) << "Valor: R$ ";
            cin >> val.valor;
            cout << "\n\tConfirma alteracao?[S][N] ";
            cin >> conf;
            if(conf == 'S')
                lista[i] = val;
            else cout << "\tDados nao confirmados\n";
        }
        else cout << "\tNome nao encontrado\n";
    }
    else cout << "\n\tLista vazia\n";
}
