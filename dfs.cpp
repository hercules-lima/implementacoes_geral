#include<bits/stdc++.h>

using namespace std;

vector< vector<int> > grafo;
int vis[50], d[50], f[50];
int tempo;


void Vis(int u){
    vis[u] = 1;
    tempo++;
    d[u] = tempo;
    for(int i=0; i<grafo[u].size(); i++){
        if(!vis[grafo[u][i]])
            Vis(grafo[u][i]);
    }
    vis[u] = 2;
    f[u] = tempo+1;
    tempo++;
}

void dfs(){
    memset(vis, 0, sizeof vis);
    tempo = 0;

    for(int i=0 ;i<grafo.size(); i++){
        if(!vis[i])
            Vis(i);
    }
}


int main(){
    freopen("in.txt","r", stdin);
    int n;
    //numero de vertices
    scanf("%d",&n);


    grafo.assign(n,vector<int>());
    memset(d,0, sizeof d);
    memset(f, 0, sizeof f);

    int a, b;
    // insira todos os caminhos no arquivo in.txt
    while(scanf("%d%d",&a,&b)!=EOF){
        grafo[a].push_back(b);
        //printf("%d%d",a,b);
    }

    dfs();

    /*queue<int> fila;
    fila.push(2);
    fila.push(0);
    fila.push(1);
    fila.push(3);
    fila.push(4);
    fila.push(5);
    fila.push(6);
    fila.push(7);
    memset(vis, 0, sizeof vis);
    tempo = 0;

    while(!fila.empty()){
        if(!vis[fila.front()]){
            Vis(fila.front());
        }
        fila.pop();
    }*/

    printf("Vertices: \n");
    for(int i=0 ;i<n; i++){
        printf("%4d",i);
    }
    putchar('\n');
    printf("Vetor d: \n");
    for(int i=0 ;i<n; i++){
        printf("%4d",d[i]);
    }
    putchar('\n');
    printf("Vetor f: \n");
    for(int i=0 ;i<n; i++){
        printf("%4d",f[i]);
    }
    putchar('\n');



    printf("\nTempo final = %d\n", tempo);




    return 0;
}
