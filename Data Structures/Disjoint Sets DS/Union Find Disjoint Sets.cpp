#include <bits/stdc++.h>

using namespace std;

/** 
 * Atenção: Essa implementação toma os elementos de 
 * 1 até n;
**/
struct DisjointSets {
  //Faça o ajuste caso seja necessário
  const static int MAXN = 112345; 
  
  //Número de elementos
  int n;
  //Número de conjuntos
  int numberOfSets;
  //Array que armazena os parents de cada elemento
  int parent[MAXN];
  //Número de elementos de cada parent, ou seja, de cada conjunto
  int numberOfElements[MAXN];

  //Construtor Default
  DisjointSets() {}

  //Construtor e inicializador O(n)
  DisjointSets(int _n) {
    //Inicialmente existem n conjuntos unitários distintos
    n = numberOfSets = _n;
    //Para cada conjunto unitário
    for (int i = 1; i <= n; i++) {
      //Seu parent será o próprio elemento
      parent[i] = i;
      //O número de elemento que ele possui será igual a 1
      numberOfElements[i] = 1;
    }
  }
  
  /**
   * Essa função recebe um elemento x e retorna o
   * parent do conjunto em que x se encontra 
   * O(α(n)), onde α(n) ≤ 5, para mais detalhes
   * https://en.wikipedia.org/wiki/Disjoint-set_data_structure
   **/
  int findSet(int x) { 
    //Caso base, encontramos o parent
    if (parent[x] == x) {
      return x;
    } else {
      //Path compression
      return parent[x] = findSet(parent[x]);
    }
  }
  
  /**
   * Essa função realiza a união de dois conjuntos,
   * os dois conjuntos são representados por dois 
   * elementos que neles estão contidos
   * O(2α(n))
   **/
  bool unionSet(int x, int y) {
    //Encontramos o parent do conjunto de x
    x = findSet(x);
    //Encontramos o parent do conjunto de y
    y = findSet(y);
  
    //Caso os dois elemento estejam em conjuntos diferentes, ou seja,
    //caso seus parent sejam diferentes
    if (x != y) {
      //Caso o número de elementos do conjunto de parent x seja maior
      if (numberOfElements[x] > numberOfElements[y]) { 
        //O parent de y torna-se x
        parent[y] = x;
        //O número de elementos do conjunto de parent x incrementa com a
        //quantidade de elemetos do conjunto de parent y
        numberOfElements[x] += numberOfElements[y];
      } else { //Caso o número de elementos do conjunto de parent y seja maior
        //O parent de x torna-se y
        parent[x] = y;
        //O número de elementos do conjunto de parent y incrementa com a
        //quantidade de elemetos do conjunto de parent x
        numberOfElements[y] += numberOfElements[x];
      }
      //Decrementamos o número de conjuntos distintos
      numberOfSets--;
      //Retornamos true, os conjuntos foram unidos
      return true;
    }
    //Retornamos false, os conjuntos não foram unidos
    return false;
  }
};

int main(){
  return 0;
}
