#ifndef BINIOINT_HPP
#define BINIOINT_HPP

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <queue>
#include <chrono>
#include "BinTree.hh"

using namespace std;

typedef struct Nodo
{
    int Valor;
    int Numero_de_nodo;
    int Profundidad;
}Nodo;

//PreOrden
BinTree<Nodo> Generate_random_tree(int Valor, int& numNodo, int Profundidad, int& Ramas_Matadas, const int Numero_Maximo_De_Nodos, int& Valor_de_Un_Nodo, const int& Pos_Nodo_random, int& Profudidad_Maxima);
BinTree<Nodo> Generate_random_tree(const int Numero_Maximo_De_Nodos, int& Valor_de_Un_Nodo, int& Profudidad_Maxima);


void breadth_first_traversal(const BinTree<Nodo>& a, Nodo& res, const int& Valor);
Nodo BFS (BinTree<Nodo>& Arbol, int Valor);

void DFS (BinTree<Nodo> Arbol, Nodo& result ,int& Valor);
Nodo DFS (BinTree<Nodo>& Arbol, int Valor);

void read_bintree(BinTree<Nodo>& a, int& numNodo, int Profundidad, int Numero_Maximo_De_Nodos, int marca);
void read_bintree(BinTree<Nodo>& a, int Numero_Maximo_De_Nodos,int marca);

//PreOrden
void write_bintree(const BinTree<Nodo> &a); 

#endif
