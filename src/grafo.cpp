#include "../include/grafo.hpp"
#include "../include/funcoes_fornecidas.hpp"
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>

bool ComparadorVertice(SVertice s1, SVertice s2)
{
    return (strcmp(s1.nome, s2.nome) < 0);
}

bool ComparadorLista(const noListaAdj &s1, const noListaAdj &s2)
{
    return (strcmp(s1.alimento, s2.alimento) < 0);
}

bool ComparadorIgualdade(SVertice s1, SVertice s2)
{
    return converteNome(s1.nome) == converteNome(s2.nome);
}

void Grafo::JuntaElementos()
{
    std::vector<SVertice>::iterator i;
    std::vector<SVertice>::iterator j;
    int cnt;
    bool saiu = false;
    for (i = _v.begin(); i != _v.end(); i++)
    {
        cnt = 1;
        for (j = i + 1; j != _v.end(); j++)
        {
            if (converteNome(i->nome) == converteNome(j->nome))
            {
                // cout << i->nome << endl;
                if (strcmp(j->lista.back().alimento, "\0") != 0)
                    i->lista.push_back(j->lista.back());
                cnt++;
                i->grauSaida = cnt;
                saiu = true;
                //  cout << "grau de saida:" << i->grauSaida << endl;
            }
            else
            {
                i->grauSaida = cnt;
                if (saiu)
                    i += cnt - 1;
                saiu = false;
                break;
            }

            i->lista.sort(ComparadorLista);
        }
    }
}

void Grafo::ImprimeGrafo()
{

    // ofstream MyFile("saida1.txt");

    auto lastIt = std::prev(_v[_v.size() - 1].lista.end()); //

    for (int i = 0; i < _v.size(); i++)
    {
        for (auto it = _v[i].lista.begin(); it != _v[i].lista.end(); ++it)
        {
            noListaAdj &no = *it;
            if (strcmp(no.alimento, "\0") != 0)
            {
                cout << _v[i].nome << " " << _v[i].especie
                     << " " << _v[i].habitat << " " << _v[i].dieta
                     << " " << _v[i].tipo << " " << _v[i].grauEntrada
                     << " " << _v[i].grauSaida << " " << _v[i].grauEntrada + _v[i].grauSaida << " " << no.alimento << " " << no.populacao;

                if (it != lastIt)
                {
                    cout << endl;
                }
            }
        }
    }

    // MyFile.close();
}

SVertice Grafo::CriaVertice(int RRN)
{
    /* Esta função cria um novo vértice a partir de um único
    registro do binário de entrada, conectando apenas o ali-
    mento do registro especificado por RRN (começando em 0)*/

    SVertice vertice;
    char *temp = (char *)malloc(50 * sizeof(char));
    noListaAdj listaAdj;

    fseek(_binario, TAM_DISCO + 5 + RRN * T_REG_DADOS, SEEK_SET);
    fread(&(listaAdj.populacao), 1, sizeof(int), _binario);

    fseek(_binario, TAM_DISCO + TAM_DADOS_FIXOS + RRN * T_REG_DADOS, SEEK_SET);

    leitura_variavel(vertice.nome, _binario);
    // vertice.nome = temp;
    // cout << "nome: " << vertice.nome << endl;

    leitura_variavel(temp, _binario);
    vertice.especie = temp;
    // cout << "especie: "<< vertice.especie << endl;

    leitura_variavel(temp, _binario);
    vertice.habitat = temp;
    // cout << "habitat: " << vertice.habitat << endl;

    leitura_variavel(temp, _binario);
    vertice.tipo = temp;
    // cout << "tipo: " << vertice.tipo << endl;

    leitura_variavel(temp, _binario);
    vertice.dieta = temp;
    // cout << "dieta: " << vertice.dieta << endl;

    leitura_variavel(listaAdj.alimento, _binario);
    // listaAdj.alimento = temp;
    // cout << "alimento: " << temp <<endl;

    if (strcmp(listaAdj.alimento, "\0") != 0)
    {
        CriaVerticeAlimento(listaAdj.alimento);
    }

    vertice.cor = branco;

    vertice.lista.push_front(listaAdj);
    _v.push_back(vertice);

    free(temp);
    return vertice;
}

void Grafo::CriaVerticeAlimento(char *nome)
{
    SVertice vertice;
    vertice.cor = vermelho;
    vertice.dieta = "\0";
    vertice.especie = "\0";
    strcpy(vertice.nome, nome);
    _v.push_back(vertice);
    noListaAdj listaAdj;
    strcpy(listaAdj.alimento, "\0");
    vertice.lista.push_front(listaAdj);
}

void Grafo::CriaGrafo()
{

    std::vector<SVertice>::iterator resize;
    int end = -1;
    int cnt = 0;

    while (end = !feof(_binario))
    {
        CriaVertice(cnt);
        // cout << "i = " << i;
        cnt++;
        fseek(_binario, TAM_DISCO + cnt * T_REG_DADOS, SEEK_SET);
        fgetc(_binario);
    }

    // cout << "\n" << end << endl;

    sort(_v.begin(), _v.end(), ComparadorVertice);
    JuntaElementos();
    std::vector<SVertice>::iterator i;
    resize = unique(_v.begin(), _v.end(), ComparadorIgualdade);
    _v.resize(distance(_v.begin(), resize));
    AtualizaDegrauEntrada();
}

void Grafo::AtualizaDegrauEntrada()
{
    std::vector<SVertice>::iterator i;
    std::vector<SVertice>::iterator k;
    std::list<noListaAdj>::iterator j;
    // int nomeVertice;
    for (i = _v.begin(); i != _v.end(); i++)
    {
        i->grauEntrada = 0;
        for (k = _v.begin(); k != _v.end(); k++)
        {
            for (j = k->lista.begin(); j != k->lista.end(); j++)
            {
                if (strcmp(j->alimento, i->nome) == 0 && strcmp(j->alimento, "\0") != 0)
                {
                    i->grauEntrada++;
                    break;
                }
            }
        }
    }
}

void Grafo::BuscaPredadores()
{

    int numPresas;

    cin >> numPresas;
    // printf("%d", numPresas)

    char **presas = (char **)malloc(numPresas * sizeof(char *));

    for (int i = 0; i < numPresas; i++)
    {
        presas[i] = (char *)malloc(T_MAX * sizeof(char));
        scan_quote_string(presas[i]);
        // printf("(%s)", presas[i]);
    }

    std::vector<SVertice>::iterator j;
    std::list<noListaAdj>::iterator k;

    char nomePredador[T_MAX];

    for (j = _v.begin(); j != _v.end(); j++)
    {
        strcpy(nomePredador, j->nome);
        for (k = j->lista.begin(); k != j->lista.end(); k++)
        {
            if (strcmp(nomePredador, k->alimento) == 0)
            {
                cout << nomePredador;
            }
        }
    }

    for (int i = 0; i < numPresas; i++)
    {
        free(presas[i]);
    };

    free(presas);

    return;
}

void Grafo::CiclosSimples()
{

    int cntCiclos = 0;
    std::list<int> path;

    for (int vInicial = 0; vInicial < _v.size(); ++vInicial)
    {
        if (!_v[vInicial].lista.empty())
        {
            EncontraCiclos(vInicial, vInicial, &cntCiclos, path);
        }
    }

    cout << "Quantidade de ciclos: " << cntCiclos;
}

void Grafo::EncontraCiclos(int vInicial, int vAtual, int *cntCiclos, std::list<int> &path)
{

    path.push_back(vAtual);
    _v[vAtual].cor = cinza;
    char *nomeInicial = (char *)_v[vInicial].nome;

    for (noListaAdj vizinho : _v[vAtual].lista)
    {
        if (!FoiVizitado(vizinho))
        {
            EncontraCiclos(vInicial, VerticeVizinho(vizinho), cntCiclos, path);
        }
        else if (strcmp(vizinho.alimento, nomeInicial) == 0)
        {
            (*cntCiclos)++;
            /* cout << vizinho.alimento << " " << nomeInicial << ":";
                 for (int node : path) {
                     std::cout << node << " (" << _v[node].nome << ") ";
                 }
                 std::cout << vInicial << " (" << _v[vInicial].nome << ") " << std::endl;*/
        }
    }

    _v[vAtual].cor = branco;
    if (vAtual == vInicial)
    {
        _v[vAtual].cor = vermelho;
    }
    path.pop_back();
}

bool Grafo::FoiVizitado(noListaAdj vizinho)
{

    for (int i = 0; i < _v.size(); i++)
    {
        if (strcmp(_v[i].nome, vizinho.alimento) == 0)
        {
            if (_v[i].cor == cinza || _v[i].cor == vermelho)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

int Grafo::VerticeVizinho(noListaAdj vizinho)
{

    for (int i = 0; i < _v.size(); i++)
    {
        if (strcmp(_v[i].nome, vizinho.alimento) == 0)
        {
            return i;
        }
    }

    // printf("O vizinho não tem vértice\n");
    return -1;
}

int Grafo::BuscaPredadorPresa(char *predador, char *presa)
{

    int menorCaminho[_v.size()];
    int phi[_v.size()];
    int predecessor[_v.size()];
    int custoMinimo = 0;

    int v = NomeParaVertice(presa);
    int w = NomeParaVertice(predador);

    if (w == -1 || v == -1)
    {
        // cout << "Nomes de vértices inválidos" << endl;
        return -1;
    }

    for (int i = 0; i < _v.size(); i++)
    {
        menorCaminho[i] = INF;
        phi[i] = 0;
        predecessor[i] = -1;
    }

    int numPredador = w;
    menorCaminho[w] = 0;

    int r, nr;
    int pred, suc;

    do
    {

        for (auto iter = _v[w].lista.begin(); iter != _v[w].lista.end(); ++iter)
        {
            r = NomeParaVertice(iter->alimento);
            if (phi[NomeParaVertice(iter->alimento)] == 0)
            {
                if (menorCaminho[r] > menorCaminho[w] + iter->populacao)
                {
                    menorCaminho[r] = menorCaminho[w] + iter->populacao;
                    predecessor[r] = w;
                }
            }
        }

        nr = INF;

        for (int i = 0; i < _v.size(); i++)
        {
            if (menorCaminho[i] < nr && phi[i] == 0)
            {
                nr = menorCaminho[i];
                w = i;
            }
        }

        phi[w] = 1;

        pred = predecessor[v];
        suc = v;

        if (w == v)
        {

            custoMinimo += Custo(pred, suc);

            while (pred != numPredador)
            {
                suc = pred;
                pred = predecessor[pred];
                custoMinimo += Custo(pred, suc);
            }

            // cout << pred <<" " << suc << endl;
            // custoMinimo += Custo(pred,suc);

            return custoMinimo;
        }

    }

    while (nr != INF);

    return -1;
}

int Grafo::NomeParaVertice(char *nome)
{

    for (int i = 0; i < _v.size(); i++)
    {
        if (strcmp(_v[i].nome, nome) == 0)
        {
            return i;
        }
    }

    // cout << "O (" << nome << ") " <<  "não tem vertice" << endl;
    // printf("O vizinho não tem vértice\n");
    return -1;
}

int Grafo::Custo(int pred, int suc)
{
    for (auto no : _v[pred].lista)
    {
        if (strcmp(no.alimento, _v[suc].nome) == 0)
        {
            return no.populacao;
        }
    }

    printf("Não encontrado\n");
    return -1;
}
