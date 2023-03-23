# Breadth-first search



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