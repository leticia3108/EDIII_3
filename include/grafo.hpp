#ifndef GRAFO_HPP
#define GRAFO_HPP

class Grafo
{
private:
    vector<SVertice> _v;
    FILE *_binario;

public:
    Grafo(FILE *binario) : _binario(binario) {}
    SVertice CriaVertice(int RRN);
    void CriaGrafo();
    void JuntaElementos();
    void AtualizaDegrauEntrada();
    void ImprimeGrafo();
    const std::vector<SVertice> &getVertices() const { return _v; }
};

#endif // GRAFO_HPP