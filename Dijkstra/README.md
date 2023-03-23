# Dijkstra

O algoritmo de Dijkstra, baseado na busca em largura ([Breadth-First Search](https://github.com/RanulfoMNeto/Algoritmos-em-Grafos/tree/main/Breadth-First%20Search)), resolve o problema de caminhos mínimos de fonte única em um grafo dirigido ponderado $G = (V, E)$ para o caso no qual todos os pesos de arestas são não negativos. Então, suporemos que $w(u, v) \geq 0$ para cada aresta $(u, v) \in E$.
O algoritmo de Dijkstra mantém um conjunto $S$ de vértices cujos pesos finais de caminhos mínimos que partem da fonte $s$ já foram determinados. O algoritmo seleciona repetidamente o vértice $u \in V - S$ que tem a mínima estimativa do caminho mínimo, adiciona $u$ a $S$ e relaxa todas as arestas que saem de $u$. Na implementação a seguir, usamos uma fila de prioridades mínimas $Q$ de vértices cujas chaves são os valores de $d$.

Em cada passagem pelo laço `while` extraímos um vértice $u$ de $Q$, utilizando `EXTRACT_MIN`, que tem a menor estimativa de caminhos mínimos em comparação com qualquer vértice em $V – S$ e o adicionamos ao conjunto $S$, mantendo assim o invariante $Q = V – S$.

```
INITIALIZE-SINGLE-SOURCE(G, s)
    for cada vértice v ∈ V[G]
        v.d = ∞
        v.π = NIL
    s.d = 0
```
```
RELAX(u, v, w)
    if v.d > u.d + w(u, v)
        v.d = u.d + w(u, v)
        v.π = u
```
```
DIJKSTRA(G, w, s)
    INITIALIZE-SINGLE-SOURCE(G, s)
    S = ∅
    Q = V[G]
    while Q ≠ ∅
        u = EXTRACT-MIN(Q)
        S = S ∪ {u}
        for cada vértice v ∈ G.Adj[u]
            RELAX(u, v, w)
```

*Cormen, T. H, Leiserson, C. E., Rivest, R. L., Stein, C. Algoritmos - Teoria e Prática (3rd edição). Grupo GEN, 2012.*