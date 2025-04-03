# Sistema de Gerenciamento de Estoque e Carrinho de Compras

## Descrição

Este é um sistema funcional desenvolvido em **C** para o gerenciamento de estoque e carrinho de compras. O programa foi criado como projeto final da disciplina de Estruturas de Dados, utilizando conceitos aprendidos ao longo do curso. A aplicação permite que o administrador gerencie o estoque de produtos e que os clientes façam compras simuladas em um sistema de carrinho de compras.

## Funcionalidades

O sistema possui as seguintes funcionalidades:

### **Para o Administrador:**
- **Adicionar Produto**: Permite adicionar novos produtos ao estoque.
- **Remover Produto por ID**: Permite remover um produto do estoque usando seu ID.
- **Mostrar Estoque**: Exibe todos os produtos presentes no estoque.
- **Editar Produto por ID**: Permite editar as informações de um produto existente.
- **Preencher Estoque**: Preenche o estoque com produtos de exemplo, substituindo os primeiros 24 itens.
- **Relatório de Modificações**: Exibe um relatório de todas as alterações feitas no estoque.

### **Para o Cliente:**
- **Exibir Itens Comprados**: Exibe os produtos que foram comprados no carrinho de compras.
- **Consultar Estoque**: Permite consultar os produtos disponíveis no estoque.
- **Adicionar ao Carrinho**: Permite adicionar um produto do estoque ao carrinho de compras.
- **Consultar Carrinho**: Exibe os produtos presentes no carrinho de compras.
- **Finalizar Compra**: Finaliza a compra, diminuindo a quantidade dos produtos no estoque e adicionando-os à lista de itens comprados.

## Tecnologias Utilizadas

- **Linguagem**: C
- **Estruturas de Dados**: Arrays, Estruturas (Structs)
- **Funções**: Funções para manipulação de dados, relatórios e exibição no console
- **Algoritmos**: Bubble Sort (para ordenar o estoque de produtos por ID)

## Como Rodar

1. Certifique-se de que o compilador **GCC** (ou qualquer outro compilador C) está instalado em seu sistema.
2. Compile o código com o seguinte comando:
   ```bash
   gcc -o sistema_estoque sistema_estoque.c
