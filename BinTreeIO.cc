#include "BinTreeIO.hh"


BinTree<Nodo> Generate_random_tree(int Valor, int& numNodo, int Profundidad, int& Ramas_Matadas, const int Numero_Maximo_De_Nodos, int& Valor_de_Un_Nodo, const int& Pos_Nodo_random, int& Profudidad_Maxima) {

    if (numNodo > Numero_Maximo_De_Nodos) { 
        return BinTree<Nodo>();
    }
    else {
        Nodo res;
        res.Valor = Valor;
        res.Numero_de_nodo = numNodo;
        res.Profundidad = Profundidad;
        if (Profudidad_Maxima < Profundidad) Profudidad_Maxima = Profundidad;

        if (Pos_Nodo_random == numNodo) Valor_de_Un_Nodo = Valor;

        BinTree<Nodo> l;
        BinTree<Nodo> r;

        if (rand() % 11 != 0 && Ramas_Matadas < numNodo - 1) {
            ++Ramas_Matadas;
            --numNodo;
            return BinTree<Nodo>();
        }
        l = Generate_random_tree((rand() % unsigned (1 << 31)), ++numNodo, ++Profundidad, Ramas_Matadas, Numero_Maximo_De_Nodos, Valor_de_Un_Nodo, Pos_Nodo_random, Profudidad_Maxima);
        r = Generate_random_tree((rand() % unsigned (1 << 31)), ++numNodo, Profundidad, Ramas_Matadas, Numero_Maximo_De_Nodos, Valor_de_Un_Nodo, Pos_Nodo_random, Profudidad_Maxima);
        return BinTree<Nodo>(res,l,r);
    }
}


BinTree<Nodo> Generate_random_tree(const int Numero_Maximo_De_Nodos, int& Valor_de_Un_Nodo, int& Profudidad_Maxima) {
    int num = 1;
    Valor_de_Un_Nodo = -1;
    int Pos_nodo = rand() % Numero_Maximo_De_Nodos + 1;
    int Ramas_Matadas = 0;
    Profudidad_Maxima = 0;

    return Generate_random_tree((rand() % unsigned (1 << 31)), num, 0, Ramas_Matadas, Numero_Maximo_De_Nodos, Valor_de_Un_Nodo, Pos_nodo, Profudidad_Maxima);

}

Nodo BFS (BinTree<Nodo>& Arbol, int Valor) {
    Nodo res;
    res.Valor = -1;
    res.Profundidad = -1;
    res.Numero_de_nodo = -1;

    breadth_first_traversal(Arbol,res,Valor);
    return res;
}

void breadth_first_traversal(const BinTree<Nodo>& a, Nodo& res, const int& Valor)
/* Pre: cert */
/* Post: l conté els nodes d’a en ordre creixent respecte al nivell on es troben,
i els de cada nivell en ordre d’esquerra a dreta */
{
    if(not a.empty()){
        queue <BinTree<Nodo> > c;
        c.push(a);
        while(not c.empty()){
            BinTree<Nodo> aux(c.front());
            if (c.front().value().Valor == Valor) {
                res = c.front().value();
                return;
            }
            if (not aux.left().empty()) c.push(aux.left());
            if (not aux.right().empty()) c.push(aux.right());
        c.pop();
        }
    }
}


void DFS (BinTree<Nodo> Arbol, Nodo& result ,int& Valor) {
    if (Arbol.empty()) return;
    else if (Arbol.value().Valor == -1) {
        result = Arbol.value();
        return;
    }
    else {
        DFS(Arbol.left(),result,Valor);
        DFS(Arbol.right(),result,Valor);
        return;
    }
}


Nodo DFS (BinTree<Nodo>& Arbol, int Valor) {
    Nodo res;
    res.Valor = -1;
    res.Profundidad = -1;
    res.Numero_de_nodo = -1;
    DFS(Arbol,res,Valor);
    return res;
}


void read_bintree(BinTree<Nodo>& a, int& numNodo, int Profundidad, int Numero_Maximo_De_Nodos, int marca)
{
    if (numNodo > Numero_Maximo_De_Nodos) { 
        return;
    }
    int x;
    cin >> x;
    if(x == marca) {
        numNodo--;
        return;
    }
    if(x != marca) {
        Nodo res;
        res.Valor = x;
        res.Numero_de_nodo = numNodo;
        res.Profundidad = Profundidad;
	    BinTree<Nodo> l;
	    read_bintree(l,++numNodo,++Profundidad,Numero_Maximo_De_Nodos,marca);
	    BinTree<Nodo> r;
	    read_bintree(r,++numNodo,Profundidad,Numero_Maximo_De_Nodos,marca);
	    a = BinTree<Nodo>(res,l,r);
    }
}


void read_bintree(BinTree<Nodo>& a, int Numero_Maximo_De_Nodos, int marca)
{
    int num = 1;
    read_bintree(a,num,0,Numero_Maximo_De_Nodos, marca);
}


void write_bintree(const BinTree<Nodo> &a)
{
	if (not a.empty()) {
		cout << " Valor: " << a.value().Valor << " Numero del nodo: " << a.value().Numero_de_nodo << " Profundidad: " << a.value().Profundidad << endl;
        write_bintree(a.left()); 
		write_bintree(a.right());
    }
}
