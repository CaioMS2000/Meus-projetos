#include "Grafo.h"

void Grafo::caminho(int x, vector<string>& arr)
{
	vector<int> caminho;
	bool final = false;
	int u, v, cont = 0;
	caminho.push_back(x);
	while (father[x] != -1) {
		caminho.push_back(father[x]);
		x = father[x];
	}
	reverse(caminho.begin(), caminho.end());
	
	if(caminho.size() < 2)
		cout<<"\n\nTRAJETO IMPOSSÍVEL DE SER FEITO DENTRO DO ATUAL ESCOPO DE VÔOS\n";
	else{
		cout<<"caminho:\n";
		for(int i = 0; i < caminho.size(); i++){
			cout<<caminho[i]<<' ';
		}
		cout<<"\n\n";
		u = 0;   v = 1;
		while(final == false){
			cont = 0;
			while(lista[caminho[u]][cont].v != caminho[v])
				cont++;
				lista[caminho[u]][cont].print(arr);
				if(v == caminho.size() - 1)
					final = true;
				else{
					u +=2;
					v +=2;
					if(u >= caminho.size() or v >= caminho.size()){
						if(v >= caminho.size()){
							while(v >= caminho.size()){ v--; }
							u = v - 1;
						}
						//if(u >= caminho.size())
							//while(u >= caminho.size() and u >= v){ u--;}
					}
				}
		}
	}
	
	caminho.clear();
}

Grafo::~Grafo()
{
	for (int i = 0; i < nos; i++) {
		lista[i].clear();
	}
	delete[]lista;
	lista = nullptr;
	delete[]color;
	color = nullptr;
	delete[]father;
	father = nullptr;
	delete[]distance;
	distance = nullptr;
	delete[]open;
	open = nullptr;
	delete[]close;
	close = nullptr;
}

Grafo::Grafo(int n)
{
	nos = n;
	lista = new vector<aresta>[n];
	color = new char[n];
	father = new int[n];
	distance = new int[n];
	father[0] = INT_MAX;
	distance[0] = INT_MAX;
	open = new int[n];
	close = new int[n];
}

void Grafo::edge_insert(aresta a)
{
	setlocale(LC_ALL, "portuguese");
	if (!chek_edge(a)) {
		lista[a.u].push_back(a);
	}
	else
		printf("\naresta não inserida pois ja está na lista de adjacência\n");
}

bool Grafo::chek_edge(aresta a)
{
	
	int t = lista[a.u].size();
	for (int i =0; i < t; i++)
		if (lista[a.u][i] == a)
			return true;
	return false;
}
/*
int Grafo::grau(int u)
{
	return lista[u].size();
}

int Grafo::popular()
{
	int maior = lista[1].size();
	int pos = 1;
	for (int i = 2; i <= nos; i++) {
		if (lista[i].size() > maior) {
			maior = lista[i].size();
			pos = i;
		}
	}
	return pos;
}

void Grafo::BFS(int v)//normal
{
	for (int i = 1; i <= nos; i++) {
		distance[i] = INT_MAX;
		father[i] = -1;
		color[i] = 'w';
	}
	distance[v] = 0;
	queue<int>fila;
	list<pair<int, float>>::iterator i;
	color[v] = 'g';
	fila.push(v);
	int aux;
	while (!fila.empty()) {
		aux = fila.front();
		for (i = lista[aux].begin(); i != lista[aux].end(); i++) {
			if (color[(*i).first] == 'w') {
				fila.push((*i).first);
				color[(*i).first] = 'g';
				father[(*i).first] = aux;
				distance[(*i).first] = distance[aux] + 1;
			}
		}
		color[aux] = 'b';
		fila.pop();
	}
}

void Grafo::BFS(int v, int u, string* s)//alterado para o trabalho
{
	for (int i = 1; i <= nos; i++) {
		distance[i] = INT_MAX;
		father[i] = -1;
		color[i] = 'w';
	}
	distance[v] = 0;
	queue<int>fila;
	list<pair<int, float>>::iterator i;
	color[v] = 'g';
	fila.push(v);
	int aux;
	while (!fila.empty()) {
		aux = fila.front();
		for (i = lista[aux].begin(); i != lista[aux].end(); i++) {
			if (color[(*i).first] == 'w') {
				fila.push((*i).first);
				color[(*i).first] = 'g';
				father[(*i).first] = aux;
				distance[(*i).first] = distance[aux] + 1;
			}
		}
		color[aux] = 'b';
		fila.pop();
	}
	cout << '\n';
	//caminho(u, s);
	if (u == -1) {
		broadcast(s);
	}
	else
		caminho(u, s);
	cout << '\n';
}

void Grafo::show()
{
	setlocale(LC_ALL, "portuguese");
	cout << "Distancia de cada vertice à origem\n";
	for (int i = 1; i <= nos; i++) {
		cout << i << ": " << distance[i] << '\n';
	}
	cout << "\n\n";
}

void Grafo::DFS()
{
	for (int i = 0; i <= nos; i++) {
		color[i] = 'w';
		father[i] = -1;
	}
	int T = 0;

	for (int i = 1; i <= nos; i++) {
		if (color[i] == 'w') {
			DFS_visit(i, &T);
		}
	}
}

void Grafo::print_DFS()
{
	for (int i = 1; i <= nos; i++) {
		//printf("nó %d: %d || %d\n", i, open[i], close[i]);
		cout << "nó " << i << ": " << open[i] << " || " << close[i] << '\n';
	}
}

void Grafo::DFS_visit(int u, int* T)
{
	color[u] = 'g';
	open[u] = ++(*T);
	//for(auto v:lista[u]){
		//if (color[u] == 'w') {
			//father[v] = u;
			//DFS_visit(v, T);
		//}
	//}
	list<pair<int, float>>::iterator it;

	for (it = lista[u].begin(); it != lista[u].end(); it++) {
		if (color[(*it).first] == 'w') {
			father[(*it).first] = u;
			DFS_visit((*it).first, T);
		}
	}
	color[u] = 'b';
	close[u] = ++(*T);
}

void Grafo::relax(int u, int v, float w)
{
	if (distance[v] > distance[u] + w) {
		distance[v] = distance[u] + w;
		father[v] = u;
	}
}

void Grafo::Initialize_Single_Source(int s)
{
	for (int i = 0; i <= nos; i++) {
		distance[i] = INT_MAX - 10;
		father[i] = -1;
	}
	distance[s] = 0;
}

void Grafo::djikstra(int s)
{
	priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>> > Q;
	Initialize_Single_Source(s);

	for (int i = 1; i <= nos; i++) {
		Q.push(make_pair(distance[i], i));
	}
	int u;

	list<pair<int, float>>::iterator it;
	while (!Q.empty()) {
		u = Q.top().second;
		for (it = lista[u].begin(); it != lista[u].end(); it++) {
			relax(u, (*it).first, (*it).second);
		}
		Q.pop();
	}
}
*/

void Grafo::relax(int u, int v, float w, aresta& a, int m, priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<pair<float, pair<int, int>>> >* Q)
{
	if(a.saida >= m + 30){
		cout<<"tentando relaxar "<<u<<' '<<v<<'\n';
		cout<<"vai comparar "<<distance[v]<<" maior que "<<distance[u] + w<<'\n';
		if (distance[v] > distance[u] + w) {
			distance[v] = distance[u] + w;
			father[v] = u;
			cout<<"\nrealxou "<<u<<' '<<v<<'\n';
			Q->push(make_pair(distance[v], make_pair(v, distance[father[v]])));
		}
	}
}

void Grafo::djikstra(int s, int d, vector<string>& arr)
{
	//priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>> > Q;
	priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<pair<float, pair<int, int>>> > Q;
	Initialize_Single_Source(s);

	for (int i = 0; i < nos; i++) {
		//Q.push(make_pair(distance[i], i));
		Q.push(make_pair(distance[i], make_pair(i, distance[father[i]])));	
	}
	int u, t_back, aux;
	while (!Q.empty()) {
		u = Q.top().second.first;
		t_back = Q.top().second.second;
		for (int i = 0; i < lista[u].size(); i++) {
			aux = lista[u][i].w + (lista[u][i].saida - t_back);
			relax(u, lista[u][i].v, aux, lista[u][i], t_back, &Q);
			//void Grafo::relax(int u, int v, float w)
		}
		Q.pop();
	}
	caminho(d, arr);
}

void Grafo::Initialize_Single_Source(int s)
{
	for (int i = 0; i < nos; i++) {
		distance[i] = INT_MAX - 10;
		father[i] = -1;
	}
	distance[s] = 0;
}
