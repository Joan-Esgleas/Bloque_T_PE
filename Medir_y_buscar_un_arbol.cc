#include "BinTreeIO.hh"
#include <bits/stdc++.h>
#include <list>
#include <cmath>

using namespace std;
int main() {
    srand(time(NULL));
    
    double read_value;
    int length;
    //cout << "Introduce la cantidad de nodos que quieres que tenga el arbol ";
    list<int> T_BFS;
    list<int> T_DFS;
    list<int> Z_COMPLX;
    T_BFS.clear();
    T_DFS.clear();
    while(cin >> read_value) {
        length = read_value;
        length = abs(length);
        //cout << length << endl;
        int valor;
        int Profundidad_Max;
        BinTree<Nodo> GR = Generate_random_tree(length, valor, Profundidad_Max);
        //write_bintree(GR);

        //cout << "///////////////////////////"<< endl;
        //cout << "Valor a buscar: " << valor << endl;
        //cout << "///////////////////////////"<< endl;

        auto begin_BFS = chrono::steady_clock::now();
        Nodo res_BFS = BFS(GR, valor);
        auto end_BFS = chrono::steady_clock::now();
        auto begin_DFS = chrono::steady_clock::now();
        Nodo res_DFS = DFS(GR, valor);
        auto end_DFS = chrono::steady_clock::now();

        //cout << "NODO: " << res_BFS.Valor << " NUMERO DEL NODO: " << res_BFS.Numero_de_nodo << " PROFUNDIDAD: " << res_BFS.Profundidad << endl;
        //cout << "PROFUNDIDAD MAXIMA: " << Profundidad_Max << endl;
        //cout << "TIEMPO BFS = " << chrono::duration_cast<chrono::microseconds>(end_BFS - begin_BFS).count() << "μs" << endl;
        int t = chrono::duration_cast<chrono::microseconds>(end_BFS - begin_BFS).count();
        if(t <= 0) T_BFS.push_back(1);
        else T_BFS.push_back(t);
        //cout << "TIEMPO DFS = " << chrono::duration_cast<chrono::microseconds>(end_DFS - begin_DFS).count() << "μs" << endl;
        t = chrono::duration_cast<chrono::microseconds>(end_DFS - begin_DFS).count();
        if(t <= 0) T_DFS.push_back(1);
        else T_DFS.push_back(t);
        Z_COMPLX.push_back(length);
        //cout << endl;
        //cout << "Introduce la cantidad de nodos que quieres que tenga el arbol: ";
    }
    //cout << endl;
    //cout << endl;
    //cout << "Comandas en R (Se hace el logaritmo natural del tiempo para poder asumir la normalidad):" << endl;
    //cout << endl;
    cout << "Y_BFS <- c(";
    list<int>::iterator it = T_BFS.begin();
    while (it != (T_BFS.end())) {
        cout << (*(it));
        if (it != (--T_BFS.end())) cout << ',';
        ++it;
    }
    cout << ')'<< endl;
    cout << "Y_DFS <- c(";
    it = T_DFS.begin();
    while (it != (T_DFS.end())) {
        cout << (*(it));
        if (it != (--T_DFS.end())) cout << ',';
        ++it;
    }
    cout << ')'<< endl;
    cout << "Z <- c(";
    it = Z_COMPLX.begin();
    while (it != (Z_COMPLX.end())) {
        cout << *(it);
        if (it != (--Z_COMPLX.end())) cout << ',';
        ++it;
    }
    cout << ')'<< endl;
    
    cout << endl;
    cout << "Y_DIFF <- Y_BFS - Y_DFS"<< endl;
    cout << "qqnorm(Y_DIFF)"<< endl;
    cout << "qqline(Y_DIFF)"<< endl;
    cout << "TEST_RESULT <- t.test(Y_BFS,Y_DFS,paired = FALSE)" << endl;
    
}
