#ifndef EX13_HPP
#define EX13_HPP

#include <vector>
#include <stack>
#include "../include/common.hpp"
#include "../include/grafo.hpp"

void dfs(const std::vector<SVertice> &, int, std::vector<bool> &, std::stack<int> &);
std::vector<SVertice> transporGrafo(const std::vector<SVertice> &);
void dfsComponente(const std::vector<SVertice> &, int, std::vector<bool> &);
void ex13(const Grafo &);

#endif // EX13_HPP