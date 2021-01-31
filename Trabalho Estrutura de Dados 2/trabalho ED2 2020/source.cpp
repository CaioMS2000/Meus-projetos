#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include "Grafo.h"
#include "Grafo.cpp"
#include <string>
#include <utility>
//#include <bits/stdc++.h>
using namespace std;

vector<string>* split(string st, string p = " ");
vector<string> vertices;
bool find(string& s, int& x);//ao final da funcao o x tera a posicao do elemento em "vertices"
void set_de_vertices(string& s);
int time(string p1, string p2);
void funcao(string& stg);
bool is_time(string& s);
vector<aresta> voo;

//======================================================================
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "portuguese");
	
	string ler;
	ifstream read("entrada.txt");
	//ifstream read("entrada2.txt");

	if (read.good()) {
		getline(read, ler);
		while (!read.eof()) {
			funcao(ler);
			getline(read, ler);
		}
	}
	else {
		cout << "DEU RUIM\n";
	}
	read.close();
	
	int i;
	for(i = 0; i < voo.size(); i++){
		voo[i].print(vertices);
	}
	cout<<"\n\nvertices: "<<vertices.size()<<"\n\n";
	
	Grafo g(vertices.size());
	for(i = 0; i < voo.size(); i++){
		g.edge_insert(voo[i]);
	}
	int j;
	for(i = 0; i < g.nos; i++){
		for(j = 0; j < g.lista[i].size(); j++){
			g.lista[i][j].print(vertices);
		}
	}
	cout<<"\n\n";
	
	for(i = 0; i < 5; i++){
		cout<<i<<" - "<<vertices[i]<<'\n';
	}
	cout<<"\n\n";
	cout<<"escolha origem e o destino [0, 4]\n";
	cin>>i>>j;
	cout<<'\n';
	g.djikstra(i, j, vertices);
	cout<<'\n';
	for(i = 0; i < g.nos; i++){
		cout<<"pai de "<<i<<" eh "<<g.father[i]<<'\n';
	}
	return 0;
}
//======================================================================

vector<string>* split(string st, string p) {
	vector<string>* retorno = new vector<string>;
	string aux;
	for (int i = 0; i < st.size(); i++) {
		if (st[i] != p[0]) {
			aux += st[i];
		}
		else {
			if (aux.size() > 0) {
				retorno->push_back(aux);
				aux.clear();
			}
			else aux.clear();
		}
	}
	retorno->push_back(aux);
	return retorno;
}

bool find(string& s, int& x) {
	x = -1;
	int t = vertices.size();
	for (int i = 0; i < t; i++) {
		if (s == vertices[i]) {
			x = i;
			return true;
		}
	}
	return false;
}

void set_de_vertices(string& s) {
	int pos = 0;

	if(!is_time(s)){
		if (!find(s, pos)) {
			vertices.push_back(s);
		}
	}
}

int time(string o, string d){
	vector<string> v1 = *(split(o,":"));
	vector<string> v2 = *(split(d,":"));
	int um = (stoi(v1[0])*60) + stoi(v1[1]);
	int dois = (stoi(v2[0])*60) + stoi(v2[1]);
	
	return dois - um;
}

bool is_time(string& s) {
	int t = s.size();
	if (s[2] == ':'){
		return true;
	}
	return false;
}

void funcao(string& stg){
	vector<string> vec = *(split(stg));
	int tam = vec.size();
	string comp = vec[0];
	cout<<"vec 0 - "<<comp<<'\n';
	int i;
	cout<<"set_de_vertices\n";
	for(i = 1; i < tam; i++){
		cout<<vec[i]<<'\n';
		set_de_vertices(vec[i]);
	}
	
	i = 3;
	while(i < tam){
		int u, v, aux = i - 2;
		float w;
		while(is_time(vec[aux])){ aux--; }
		find(vec[aux], u);
		cout<<"u - "<<u<<'\n';
		find(vec[i], v);
		cout<<"v - "<<v<<'\n';
		w = time(vec[i-1], vec[i+1]);
		
		cout<<"aqui "<<comp<<' '<< u<<' '<< v<<' '<< w<<' '<< vec[i-1]<<' '<< vec[i+1]<<' '<< time("00:00", vec[i-1])<<' '<< time("00:00", vec[i+1])<<"\n\n";
		
		voo.push_back(aresta(comp, u, v, w, vec[i-1], vec[i+1], time("00:00", vec[i-1]), time("00:00", vec[i+1])));
		//vector<pair<pair<int, float>>> voo;
		i = i + 3;
	}
}
//======================================================================
