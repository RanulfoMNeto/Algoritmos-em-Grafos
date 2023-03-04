# Bellman-Ford

O ***algoritmo de Bellman–Ford*** resolve o problema de caminhos mínimos de fonte única no caso geral no qual os pesos das arestas podem ser negativos. Dado um grafo dirigido ponderado $G = (V, E)$ com fonte $s$ e função peso $w:E \rightarrow \mathbb{R}$, o algoritmo de Bellman–Ford devolve um valor booleano que indica se existe ou não um ciclo de peso negativo que pode ser alcançado da fonte. Se tal ciclo existe, o algoritmo indica que não há nenhuma solução. Se tal ciclo não existe, o algoritmo produz os caminhos mínimos e seus pesos.
O algoritmo relaxa arestas diminuindo progressivamente uma estimativa $v.d$ do peso de um caminho mínimo da fonte $s$ a cada vértice $v \in V$ até chegar ao peso propriamente dito do caminho mínimo $\delta (s, v)$. O algoritmo retorna TRUE se e somente se o grafo não contém nenhum ciclo de peso negativo que possa ser alcançado da fonte.

```
BELLMAN-FORD(G, w, s)
    INITIALIZE-SINGLE-SOURCE(G, s)
    for i = 1 to |V[G]| – 1
        for cada aresta (u, v) ∈ E[G]
            RELAX(u, v, w)
    for cada aresta (u, v) ∈ E[G]
        if v.d > u.d + w(u, v)
            return FALSE
    return TRUE
```

*Cormen, T. H, Leiserson, C. E., Rivest, R. L., Stein, C. Algoritmos - Teoria e Prática (3rd edição). Grupo GEN, 2012.*