Uma rede de fluxo $G = (V, E)$ é um grafo dirigido no qual cada aresta $(u, v) \in E$ (não antiparalelas) tem uma capacidade não negativa $c(u, v) \geq 0$. 

Distinguimos dois vértices em uma rede de fluxo: uma fonte $s$ e um sorvedouro $t$.

Um fluxo em $G$ é uma função de valor real $f : V \times V \rightarrow \mathbb{R}$ que satisfaz as propriedades seguintes:
- **Restrição de capacidade:** Para todo $u, v \in V$, exigimos $0 \leq f(u, v) \leq c(u, v)$.
- **Conservação de fluxo:** Para todo $u \in V – \{ s, t \} $, impomos $$\sum_{v \in V} f(v,u) = \sum_{v \in V} f(u,v).$$
Quando $(u, v) \not\in E$, não pode haver nenhum fluxo de $u$ a $v$, e $f(u,v) = 0$.

## Caminhos Aumentadores

Dados uma rede de fluxo $G = (V, E)$ e um fluxo $f$, um Caminho Aumentador $p$ é um caminho simples de $s$ a $t$ na rede residual $G_f$.
A quantidade máxima possível de aumento para o fluxo em cada aresta de $p$ é denominada *Capacidade Residual* de $p$ e é dada por 
$$c_f(p) = min \{ c_f(u, v) : (u, v) \text{ está em } p \}.$$

# Ford-Fulkerson

O método Ford-Fulkerson aumenta iterativamente o valor do fluxo. Começamos com $f(u,v) = 0$ para todo $u, v \in V$, que da um fluxo inicial de valor 0. A cada iteração, aumentamos o valor do fluxo em $G$ determinando um *Caminho Aumentador* em uma *Rede Residual* $G_f$.

```
FORD-FULKERSON(G, s, t)

  for cada aresta (u, v) ∈ G.E
    (u, v).f = 0
    
  while existir um caminho p de s a t na rede residual Gf
    cf(p) = min{cf(u, v) : (u, v) está em p}
    
    for cada aresta (u, v) em p
      if(u,v) ∈ E
        (u, v).f = (u, v).f + cf(p)
      else(v, u).f = (v, u).f – cf(p)
```
*Observação:* A expressão $c_f(p)$ no código serve apenas como uma variável temporária que armazena a *Capacidade Residual* do caminho $p$.

*Cormen, T. H, Leiserson, C. E., Rivest, R. L., Stein, C. Algoritmos - Teoria e Prática (3rd edição). Grupo GEN, 2012.*