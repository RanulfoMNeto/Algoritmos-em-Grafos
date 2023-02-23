# Depth-First Search

Dado um grafo $G = (V, E)$, a busca em profundidade explora arestas partindo do vértice $v$ mais recentemente descoberto do qual ainda saem arestas inexploradas. Depois que todas as arestas de $v$ foram exploradas, a busca “regressa pelo mesmo caminho” para explorar as arestas que partem do vértice do qual $v$ foi descoberto. Esse processo continua até descobrirmos todos os vértices que podem ser visitados a partir do vértice fonte inicial. Se restarem quaisquer vértices não descobertos, a busca em profundidade seleciona um deles como fonte e repete a busca partindo dessa fonte. O algoritmo repete esse processo inteiro até descobrir todos os vértices.

```
DFS(G)
    for cada vértice u ∈ V[G]
        u.cor = BRANCO
        u.π = NIL
    tempo = 0
    for cada vértice u ∈ V[G]
        if u.cor == BRANCO
            DFS-VISIT(G, u)
```

```
DFS-VISIT(G, u)
    tempo = tempo + 1 // vértice branco u acabou de ser descoberto
    u.d = tempo
    u.cor = CINZENTO
    for cada v ∈ G.Adj[u] // explorar aresta (u, v)
        if v.cor == BRANCO
            v.π = u
            DFS-VISIT(G, v)
    u.cor = PRETO // pintar u de preto; está terminado
    tempo = tempo + 1
    u.f = tempo
```

*Cormen, T. H, Leiserson, C. E., Rivest, R. L., Stein, C. Algoritmos - Teoria e Prática (3rd edição). Grupo GEN, 2012.*