#include "../include/common.h"
#include <iostream>
#include "../include/ex10.h"
#include <algorithm>
#include <string.h>

/* bool ComparadorVertice (SVertice s1, SVertice s2){
    return converteNome(s1.nome) < converteNome(s2.nome);
} */

bool ComparadorVertice (SVertice s1, SVertice s2){
    return (strcmp(s1.nome , s2.nome) < 0);
}

/* bool ComparadorLista (noListaAdj s1, noListaAdj s2){
    return converteNome(s1.alimento) < converteNome(s2.alimento);
} */

bool ComparadorLista (noListaAdj s1, noListaAdj s2){
    return (strcmp(s1.alimento,s2.alimento) < 0);
}

bool ComparadorIgualdade (SVertice s1, SVertice s2){
    return converteNome(s1.nome) == converteNome(s2.nome);
}

class Grafo {

private:
    vector<SVertice> _v;
    FILE* _binario;

public:
    Grafo(FILE* binario): _binario(binario){}
    SVertice CriaVertice(int RRN);
    void CriaGrafo();
    void JuntaElementos();
    void AtualizaDegrauEntrada();
    void ImprimeGrafo();
};

void Grafo::JuntaElementos(){
    std::vector<SVertice>::iterator i;
    std::vector<SVertice>::iterator j;
    int cnt;
    bool saiu = false;
    for (i = _v.begin(); i != _v.end(); i++){
        cnt = 1;
        for (j = i+1; j != _v.end(); j++){
            if (converteNome(i->nome) == converteNome(j->nome)){
                //cout << i->nome << endl;
                i->lista.push_back(j->lista.back());
                cnt++;
                i->grauSaida = cnt;
                saiu = true;
              //  cout << "grau de saida:" << i->grauSaida << endl;
            } else {
                i->grauSaida = cnt;
                if (saiu)
                    i += cnt-1;
                saiu = false;
                break;}
            
            i->lista.sort(ComparadorLista);

        }
    }
}

void Grafo::ImprimeGrafo(){

    for (int i = 0; i < _v.size(); i++){
        for (noListaAdj no : _v[i].lista){
            cout <<" "<< _v[i].nome  <<" "<< _v[i].especie 
            <<" "<< _v[i].habitat  <<" "<< _v[i].dieta  
            <<" "<< _v[i].tipo  <<" "<< _v[i].grauEntrada 
            <<" "<< _v[i].grauSaida  <<" "<< _v[i].grauEntrada + 
            _v[i].grauSaida  <<" "<< no.alimento <<" "<<
            no.populacao << endl;
        }
    }
}

SVertice Grafo::CriaVertice(int RRN){
/* Esta função cria um novo vértice a partir de um único
registro do binário de entrada, conectando apenas o ali-
mento do registro especificado por RRN (começando em 0)*/

    SVertice vertice;
    char* temp = (char*) malloc(50 * sizeof(char));
    noListaAdj listaAdj;

    fseek(_binario, TAM_DISCO + 5 +RRN*T_REG_DADOS, SEEK_SET); 
    fread(&(listaAdj.populacao), 1, sizeof(int), _binario);

    fseek(_binario, TAM_DISCO + TAM_DADOS_FIXOS +RRN*T_REG_DADOS, SEEK_SET);  

    leitura_variavel(vertice.nome, _binario);
   // vertice.nome = temp;
    //cout << "nome: " << vertice.nome << endl;

    leitura_variavel(temp, _binario);
    vertice.especie = temp;
    //cout << "especie: "<< vertice.especie << endl;

    leitura_variavel(temp, _binario);
    vertice.habitat = temp;
    //cout << "habitat: " << vertice.habitat << endl;

    leitura_variavel(temp, _binario);
    vertice.tipo = temp;
    //cout << "tipo: " << vertice.tipo << endl;

    leitura_variavel(temp, _binario);
    vertice.dieta = temp;
    //cout << "dieta: " << vertice.dieta << endl;

    leitura_variavel(listaAdj.alimento, _binario);
    //listaAdj.alimento = temp;
    //cout << "alimento: " << temp <<endl;

    vertice.lista.push_front(listaAdj);
    _v.push_back(vertice);

    free(temp);
    return vertice;
}

void Grafo::CriaGrafo( ){

std::vector<SVertice>::iterator resize; 
int end = -1;
int cnt = 0;

while (end = !feof(_binario)){
    CriaVertice(cnt);
   // cout << "i = " << i;
    cnt++;
    fseek(_binario, TAM_DISCO + cnt*T_REG_DADOS, SEEK_SET);
    fgetc(_binario);
}

//cout << "\n" << end << endl;

sort(_v.begin(), _v.end(), ComparadorVertice);
JuntaElementos();
std::vector<SVertice>::iterator i;
resize = unique(_v.begin(),_v.end(),ComparadorIgualdade);
_v.resize(distance(_v.begin(),resize));
AtualizaDegrauEntrada();

}


void Grafo::AtualizaDegrauEntrada(){
    std::vector<SVertice>::iterator i;
    std::vector<SVertice>::iterator k;
    std::list<noListaAdj>::iterator j;
    int nomeVertice;
    for (i = _v.begin(); i != _v.end(); i++){
        i->grauEntrada = 0;
        nomeVertice = converteNome(i->nome);
        for (k = _v.begin(); k != _v.end(); k++){
            for (j = k->lista.begin(); j != k->lista.end(); j++){
                if (converteNome(j->alimento) == nomeVertice){
                    i->grauEntrada++;
                    break;
                }
            }
        }
    }
}

void ex10(FILE* binario){
    Grafo g(binario);
    g.CriaGrafo();
    g.ImprimeGrafo();
}
