# Breadth-first search


Dado um grafo $G = (V, E)$ e um vértice fonte $s$, a busca em largura (breadth-first search) explora sistematicamente as arestas de $G$ para “descobrir” cada vértice que pode ser alcançado a partir de $s$. O algoritmo calcula a distância (menor número de arestas) de $s$ até cada vértice que pode ser alcançado. Produz também uma “árvore de busca em largura” com raiz $s$ que contém todos os vértices que podem ser alcançados. Para qualquer vértice $v$ que pode ser alcançado de $s$, o caminho simples na árvore de busca em largura de $s$ até $v$ corresponde a um “caminho mínimo” de $s$ a $v$ em $G$, isto é, um caminho que contém o menor número de arestas. O algoritmo funciona em grafos dirigidos, bem como em grafos não dirigidos.

```
BFS(G, s)
    for cada vértice u ∈ V[G] – {s}
        u.cor = BRANCO
        u.d = ∞
        u.π = NIL
    s.cor = CINZENTO
    s.d = 0
    s.π = NIL
    Q = ∅
    ENQUEUE(Q, s)
    while Q ≠ ∅
        u = DEQUEUE(Q)
        for cada v = Adj[u]
            if v.cor == BRANCO
                v.cor == CINZENTO
                v.d = u.d + 1
                v.π = u
                ENQUEUE(Q, v)
        u.cor = PRETO
```

*Cormen, T. H, Leiserson, C. E., Rivest, R. L., Stein, C. Algoritmos - Teoria e Prática (3rd edição). Grupo GEN, 2012.*