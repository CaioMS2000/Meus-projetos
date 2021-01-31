#pragma once
#include <list>
#include <locale.h>
#include <locale>
#include <queue>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
struct aresta{
public:
	int u, v, w, saida, chegada;
	string agencia, s_saida, s_chegada;
	
	aresta(string ag, int a, int b, int c, string sh1, string sh2, int h1, int h2){
		agencia = ag;   u = a;   v = b;   w = c;
		s_saida = sh1;   s_chegada = sh2;   saida = h1;   chegada = h2;
	}
	
	void print(vector<string>& arr){
		cout<<agencia<<' '<<arr[u]<<" "+s_saida<<' '<<arr[v]<<" "+s_chegada<<'\n';
	}
	
	bool operator == (aresta a){ return (u == a.u and v == a.v and w == a.w); }
	bool operator != (aresta a){ return ( u != a.u or v != a.v or w != a.w); }
};
class Grafo
{
private:
public:
	int nos;
	vector<aresta>* lista;
	//list<pair<string, pair<pair<int, float>, pair<string, string>>>>* lista;
	//          agencia            v      w         tempo-s   tempo-c
	queue<int> fila;
	int* open;
	int* close;
	int* distance;
	int* father;
	char* color;
	void caminho(int x, vector<string>& arr);
	void DFS_visit(int u, int* T);
	void relax(int u, int v, float w, aresta& a, int m, priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<pair<float, pair<int, int>>> >* Q);
	void Initialize_Single_Source(int s);
//public:
	~Grafo();
	Grafo(int n);
	void edge_insert(aresta a);
	bool chek_edge(aresta a);
	//int grau(int u);
	//int popular();
	//void BFS(int v);//normal
	//void BFS(int v, int u, string* s);//alterado para o trabalho
	void show();
	//void DFS();
	//void print_DFS();
	void djikstra(int s, int d, vector<string>& arr);
};

