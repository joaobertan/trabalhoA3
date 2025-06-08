# 🧮 Ordenação com e sem Ponteiros

Este projeto em C demonstra dois métodos de ordenação aplicados em vetores de inteiros, utilizando tanto **acesso por índice** quanto **ponteiros**. O objetivo é comparar diferentes formas de implementação e explorar os algoritmos de ordenação clássicos.

---

## 📂 Estrutura dos Arquivos

- `main.c` — Ponto de entrada da aplicação.
- `alg.h` — Declarações das funções utilizadas.
- `ordenacao-normal.c` — Implementa os algoritmos de ordenação com uso tradicional de índices.
- `ordenacao-ponteiros.c` — Implementa os algoritmos utilizando ponteiros.
- `CMakeLists.txt` — Script para compilar com CMake.
- `.idea/` — Arquivos de configuração do projeto (gerado pela IDE).

---

## 📌 Algoritmos de Ordenação Utilizados

### 🔹 Bubble Sort

O algoritmo **Bubble Sort** compara elementos adjacentes e os troca de posição se estiverem fora da ordem desejada. É um método simples, porém ineficiente para grandes conjuntos de dados.

- **Vantagens:** Fácil de entender e implementar.
- **Desvantagens:** Lento para grandes vetores (complexidade O(n²)).

**Implementações disponíveis:**

- Bubble Sort **Crescente**
- Bubble Sort **Decrescente**

### 🔹 Quick Sort

O **Quick Sort** é um algoritmo eficiente que utiliza o conceito de divisão e conquista. Ele escolhe um pivô e organiza os elementos menores à esquerda e os maiores à direita, aplicando-se recursivamente.

- **Vantagens:** Muito eficiente para grandes conjuntos de dados (complexidade média O(n log n)).
- **Desvantagens:** Menos intuitivo, sensível à escolha do pivô.

**Implementações disponíveis:**

- Quick Sort **Crescente**
- Quick Sort **Decrescente**

