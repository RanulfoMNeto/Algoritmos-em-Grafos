# Heurística de Coloração Ingênua Melhorada

```
procedure IngenuaMelhorada(G)
    Seja L uma lista de vértices ordenada de forma descendente pelo grau;
    c ← 1;
    while L ≠ ∅ do
        for all v ∈ L tal que v não é colorido do
            if nenhum vértice adjacente a v foi colorido com c then
                Colora v com a cor c;
        c ← c + 1;
```

*Mayron César O. Moreira. Algoritmos para coloração de vértices (Notas de Aula). Universidade Federal de Lavras, Algoritmos em Grafos - GCC218 (2023).*