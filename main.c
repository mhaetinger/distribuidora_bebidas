#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_ElementosCarrinho 50
#define MAX_ElementosModificados 100
#define MAX_ElementosLista 50

//Structs----------------------------------------------------------------------

//Produto
struct Produto {

    int id;
    char nome[50];
    double preco;
    int quantidade;
};

//Relat�rio
struct Modificacao {

    char tipo[20];
    int idProduto;
    char detalhes[100];
    char usuario[20];


};


//Prot�tipos das Fun��es-------------------------------------------------------

                                //Int
int usuario();
int estoqueEstaVazio(struct Produto estoque[], int tamanho);

                                //Void
void printLine(char caractere, int comprimento);
void imprimirTabela(struct Produto estoque[], int tamanho);
void zerarEstoque(struct Produto estoque[], int tamanho);
void bubbleSort(struct Produto array[], int tamanho);

//Relat�rio
void registrarModificacao(struct Modificacao lista[], int *numModificacoes, const char *tipo, int idProduto,
                          double precoAntigo, double precoNovo, const char *nomeAntigo, const char *nomeNovo,
                          int quantidadeAntiga, int quantidadeNova);

void exibirRelatorioModificacoes(const struct Modificacao listaModificacoes[], int numModificacoes);

//Principais
void adicionarProdutoAoEstoque(struct Produto estoque[], int tamanhoMaximo);
void editarProduto(struct Produto estoque[], int tamanho, struct Modificacao listaModificacoes[], int *numModificacoes, const char *usuario);
void preencherEstoqueComValores(struct Produto estoque[], int tamanho);
void verificarERemoverProduto(struct Produto estoque[], int tamanho);


//Carrinho
void exibirItensComprados(struct Produto itensComprados[], int tamanho);
void adicionarAoCarrinho(struct Produto estoque[], struct Produto carrinho[], int tamanhoEstoque);
void consultarCarrinho(struct Produto carrinho[], int tamanho);
void finalizarCompra(struct Produto carrinho[], struct Produto estoque[], struct Produto ItensComprados[], int *tamanhoMaxCarrinho);





//Main-------------------------------------------------------------------------
int main(){
    setlocale(LC_ALL, "Portuguese");

    int tamanhoMaxCarrinho = MAX_ElementosCarrinho;

    // Crie um array de structs para o estoque da loja
    struct Produto estoque[MAX_ElementosLista];
    struct Produto ItensComprados[MAX_ElementosLista];

    //Zerar Estoque(limpa o que havia nos espa�os da memoria)
    zerarEstoque(estoque, MAX_ElementosLista);


    // Crie um array de structs para representar o carrinho de compras
    struct Produto carrinho[MAX_ElementosCarrinho];

    //Zerar Carrinho(limpa o que havia nos espa�os da memoria)
    zerarEstoque(carrinho, MAX_ElementosCarrinho);

    //Modifica��es - Relat�rio
    struct Modificacao listaModificacoes[100];


    // Variaveis:

    int op, x;
    int numModificacoes = 0;



    while (1) // Loop infinito para sele��o de conta
    {
        system("cls");

        int user_switch = usuario(); // Obt�m o tipo de usu�rio da fun��o usuario

        switch (user_switch)
        {

            case 1: // ADMIN

                do
                {
                    printf("\n--------------------GERENCIAMENTO DE ESTOQUE--------------------");
                    printf("\n1 - ADICIONAR PRODUTO");
                    printf("\n2 - REMOVER PRODUTO POR ID");
                    printf("\n3 - MOSTRAR ESTOQUE");
                    printf("\n4 - EDITAR PRODUTO POR ID");
                    printf("\n5 - PREENCHER ESTOQUE (Cuidado, essa op��o ir� substituir os valores dos primeiros 24 itens)");
                    printf("\n6 - RELAT�RIO DE MODIFICA��ES");
                    printf("\n0 - SAIR DO USU�RIO\n");
                    printf("Selecione uma opera��o que deseja fazer: ");
                    scanf("%d", &op);

                    switch (op)
                    {
                        case 1:
                            adicionarProdutoAoEstoque(estoque, MAX_ElementosLista);
                            // fun��o para adicionar um produto
                            break;

                        case 2:
                            verificarERemoverProduto(estoque, MAX_ElementosLista);
                            // fun��o para remover um produto por ID
                            break;

                        case 3:
                            system("cls");
                            bubbleSort(estoque, MAX_ElementosLista);
                            imprimirTabela(estoque, sizeof(estoque) / sizeof(estoque[MAX_ElementosLista]));
                            // fun��o para mostrar o estoque
                            break;

                        case 4:
                            editarProduto(estoque, MAX_ElementosLista, listaModificacoes, &numModificacoes, "Admin");
                            // fun��o para editar um produto por ID
                            break;

                        case 5:
                            preencherEstoqueComValores(estoque, MAX_ElementosLista);
                            // fun��o para preencher o estoque com produtos aleat�rios
                            break;

                        case 6:
                            exibirRelatorioModificacoes(listaModificacoes, numModificacoes);
                            //Relat�rio de Modifica��es
                            break;

                        case 0:
                            printf("\nSaindo...\n");
                            break;
                        default:
                            printf("Op��o inv�lida");
                            break;
                    }

                } while (op != 0);

            break; // Sai do loop switch

            case 2: // Cliente

                do
                {
                    printf("\n--------------------TELA DE VENDA--------------------");
                    printf("\n1 - EXIBIR ITENS COMPRADOS");
                    printf("\n2 - CONSULTAR ESTOQUE");
                    printf("\n3 - ADICIONAR AO CARRINHO");
                    printf("\n4 - CONSULTAR CARRINHO");
                    printf("\n5 - FINALIZAR COMPRA");
                    printf("\n0 - SAIR DO USU�RIO\n");
                    printf("Selecione uma opera��o que deseja fazer: ");
                    scanf("%d", &op);

                    switch (op)
                    {
                        case 1:
                            exibirItensComprados(ItensComprados, MAX_ElementosLista);
                            // fun��o para adicionar um produto por ID ao carrinho de compras
                            break;

                        case 2:
                            imprimirTabela(estoque, sizeof(estoque) / sizeof(estoque[MAX_ElementosLista]));
                            // fun��o para verificar o estoque
                            break;

                        case 3:
                            adicionarAoCarrinho(estoque, carrinho, sizeof(estoque) / sizeof(estoque[0]));
                            // fun��o para adicionar um item ao carrinho
                            break;

                        case 4:
                            consultarCarrinho(carrinho, MAX_ElementosCarrinho);
                            // fun��o para consultar o carrinho
                            break;

                        case 5:
                            finalizarCompra(carrinho, estoque, ItensComprados, &tamanhoMaxCarrinho);
                            // fun��o para finalizar a(s) compra(s)
                            break;

                        case 0:
                            printf("\nSaindo...\n");
                            break;

                        default:
                            printf("Op��o inv�lida");
                            break;
                    }
                }while (op != 0);

                break; // Sai do loop switch

            case 3:
                puts("\nSaindo. . .");
                return 0;
                break; // Sai do loop switch
        }
    }

    return 0;
}

// FUN��ES---------------------------------------------------------------------

//Linhas
void printLine(char caractere, int comprimento) {
    for (int i = 0; i < comprimento; i++) {
        putchar(caractere);
    }
    putchar('\n');
}

//Usuario
int usuario(){
    int user;

    while (1)
    {

        printf("\n----ESCOLHA COM QUAL OPCAO DESEJA ENTRAR NO PROGRAMA----\n");
        printf("\n1 - Estoque");
        printf("\n2 - Venda");
        printf("\n3 - Sair");

        printf("\n\nEscolha uma opcao:\n");
        scanf("%d", &user);

        if (user > 0 && user < 4)
        {
            return user;
        }
        else
        {
            printf("\nOp��o inv�lida. Tente novamente.\n");
        }
    }
}

//Zerar Estoque
void zerarEstoque(struct Produto estoque[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        estoque[i].id = 0;
        strcpy(estoque[i].nome, ""); //  strcpy para copiar uma string vazia
        estoque[i].preco = 0.0;
        estoque[i].quantidade = 0;
    }
}

//Preencher Lista Exemplo
void preencherEstoqueComValores(struct Produto estoque[], int tamanho) {
    int i;

    // Defina os valores dos produtos do outro projeto
    int ids_exemplo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

    char nomes_exemplo[][50] = {"Vinho Tinto Suave 750ml", "Vinho Tinto Seco 750mL", "Whisky Jack Daniel's 1L", "Whisky Red Label 1L", "Whisky Black Label 1L",
                        "Whisky Blue label 750mL", "Cerveja Kaiser 473mL", "Cerveja Polar 473mL", "Cerveja Budweiser 473mL", "Cerveja Heineken 473mL",
                        "Gin Gordons 750mL", "Chopp", "Vodka Smirnoff Ice 275mL", "Vodka Smirnoff 998mL", "Vodka Natasha 900mL", "Vodka Absolut 1L",
                        "Vodka Askov 900mL", "Cacha�a Velho Barreiro 910mL", "Cacha�a Corote 500mL", "Cacha�a Pitu 350mL",
                        "Coca-Cola 2L", "Pepsi 2L", "Guarana Antarctica 2L", "�gua mineral C/S"};

    double precos_exemplo[] = {15.90, 17.00, 125.00, 85.00, 175.00, 1800.00, 4.00, 4.50, 5.00, 6.00,
                       80.00, 7.00, 9.50, 45.00, 20.00, 115.00, 20.50, 16.50, 6.50, 5.90, 11.00, 8.00, 8.50, 1.50};

    int quantidades_exemplo = 20;

    // Preencha o estoque com os valores definidos
    for (i = 0; i < tamanho && i < sizeof(ids_exemplo) / sizeof(ids_exemplo[0]); i++) {
        estoque[i].id = ids_exemplo[i];
        strcpy(estoque[i].nome, nomes_exemplo[i]);
        estoque[i].preco = precos_exemplo[i];
        estoque[i].quantidade = quantidades_exemplo;
    }
}

//Estoque Vazio ou N�o - Verifica��o para ser usado em outras fun��es
int estoqueEstaVazio(struct Produto estoque[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (estoque[i].id != 0) {
            return 0; // O estoque n�o est� vazio
        }
    }
    return 1; // O estoque est� vazio
}


//BubbleSort
void bubbleSort(struct Produto arr[], int tamanho) {
    int i, flag=1;
    struct Produto temp;
    while (flag) {
        flag=0;
        for (i = 0; i < tamanho - 1; i++) {
                if (arr[i].id > arr[i + 1].id) {
                    // Troca os elementos se estiverem fora de ordem
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    flag=1;
                }

        }
    }
}


//                                 Relat�rio


// Fun��o para registrar uma modifica��o
void registrarModificacao(struct Modificacao lista[], int *numModificacoes, const char *tipo, int idProduto,
                          double precoAntigo, double precoNovo, const char *nomeAntigo, const char *nomeNovo,
                          int quantidadeAntiga, int quantidadeNova) {

    //Verifica se a lista de modifica��es est� cheia
    if (*numModificacoes < 100) {
        struct Modificacao modificacao;
        strcpy(modificacao.tipo, tipo);
        modificacao.idProduto = idProduto;
        //Verifica se o ID foi alterado
        if (strcmp(tipo, "Edi��o de ID") == 0) {
            sprintf(modificacao.detalhes, "ID alterado para %d", idProduto);
        } else {
            // Comparar os valores antigos e novos e registrar as altera��es
            char detalhes[100] = "";
            //Verifica a troca de pre�o
            if (precoAntigo != precoNovo) {
                sprintf(detalhes, "Pre�o alterado de %.2lf para %.2lf", precoAntigo, precoNovo);
            }
            //Verifica a troca de nome
            if (strcmp(nomeAntigo, nomeNovo) != 0) {
                if (detalhes[0] != '\0') {
                    strcat(detalhes, "\n");
                }
                strcat(detalhes, "Nome alterado de ");
                strcat(detalhes, nomeAntigo);
                strcat(detalhes, " para ");
                strcat(detalhes, nomeNovo);
            }
            //Verifica a troca de quantidade
            if (quantidadeAntiga != quantidadeNova) {
                if (detalhes[0] != '\0') {
                    strcat(detalhes, "\n");
                }
                sprintf(detalhes + strlen(detalhes), "Quantidade alterada de %d para %d", quantidadeAntiga, quantidadeNova);
            }

            if (detalhes[0] != '\0') {
                strcpy(modificacao.detalhes, detalhes);
            } else {
                strcpy(modificacao.detalhes, "Sem altera��es");
            }
        }

        lista[*numModificacoes] = modificacao;
        (*numModificacoes)++;
    }
}


// Fun��o para exibir o relat�rio de modifica��es
void exibirRelatorioModificacoes(const struct Modificacao listaModificacoes[], int numModificacoes) {
    printf("\n\nRelat�rio de Modifica��es:\n\n\n");
    for (int i = 0; i < numModificacoes; i++) {
        printf("Tipo: %s\n", listaModificacoes[i].tipo);
        printf("ID do Produto: %d\n", listaModificacoes[i].idProduto);
        printf("Detalhes: %s\n", listaModificacoes[i].detalhes);
        printf("\n");
    }
    printf("Total de modifica��es feitas: %d\n", numModificacoes);
}


// FUN��ES PRINCIPAIS----------------------------------------------------------

//Inserir Produto - Estoque
void adicionarProdutoAoEstoque(struct Produto estoque[], int tamanhoMaximo) {

    // Verifique o estoque
    int numeroProdutos = 0;
    for (int i = 0; i < tamanhoMaximo; i++) {
        if (estoque[i].id != 0) {
            numeroProdutos++;
        }
    }
    //Verifica se o estoque est� cheio
    if (numeroProdutos >= tamanhoMaximo) {
        printf("O estoque est� cheio. N�o � poss�vel adicionar mais produtos.\n");
        return;
    }

    // Pergunte ao usu�rio o ID
    struct Produto novoProduto;
    printf("Informe os detalhes do novo produto:\n");
    printf("ID: ");
    scanf("%d", &novoProduto.id);

    // Verifique se o ID � �nico
    for (int i = 0; i < tamanhoMaximo; i++) {
        if (estoque[i].id == novoProduto.id) {
            printf("ID j� em uso. Por favor, escolha um ID diferente.\n");
            return;
        }
    }

    // Nome
    printf("Nome: ");
    scanf(" %[^\n]", novoProduto.nome);
    fflush(stdin);

    // Pre�o
    printf("Pre�o: ");
    scanf("%lf", &novoProduto.preco);

    // Quantidade
    printf("Quantidade: ");
    scanf("%d", &novoProduto.quantidade);

    // Adicione novoProduto ao estoque na pr�xima posi��o dispon�vel
    for (int i = 0; i < tamanhoMaximo; i++) {
        if (estoque[i].id == 0) {
            estoque[i] = novoProduto;
            printf("Produto adicionado com sucesso ao estoque.\n");
            return;
        }
    }
}


//Remover Produto - Estoque
void verificarERemoverProduto(struct Produto estoque[], int tamanho) {
    int encontrado = 0;
    int id;

    printf("\nQual ID deseja remover?\n: ");
    scanf("%d", &id);

    for (int i = 0; i < tamanho; i++) {
        if (estoque[i].id == id) {
            // Encontra o produto com o ID especificado

            // Move todos os prox�mos elementos para uma posi��o anterior
            for (int j = i; j < tamanho - 1; j++) {
                estoque[j] = estoque[j + 1];
            }
            // Definimos o �ltimo elemento como vazio
            estoque[tamanho - 1].id = 0;
            strcpy(estoque[tamanho - 1].nome, "");
            estoque[tamanho - 1].preco = 0.0;
            estoque[tamanho - 1].quantidade = 0;
            printf("Produto com ID %d removido com sucesso!\n", id);
            encontrado = 1;
            break; // Terminamos a fun��o ap�s a remo��o
        }
    }

    if (!encontrado) {
        printf("Produto com ID %d n�o encontrado no estoque.\n", id);
    }
}

//Exibir Produto - Estoque
void imprimirTabela(struct Produto estoque[], int tamanho) {
    printf("| %-4s | %-30s | %-15s | %-10s |\n", "ID", "Nome", "Pre�o", "Quantidade");
    printf("|------|--------------------------------|-----------------|------------|\n");

    for (int i = 0; i < tamanho; i++) {
        if (estoque[i].id != 0) { // Exibe apenas os elementos difentes de ID ZERO
           printf("| %4d | %-30s | %-12.2f R$ | %10d |\n",
               estoque[i].id, estoque[i].nome, estoque[i].preco, estoque[i].quantidade);
        }

    }
    printLine('-', 72);
}

//Editar Produto - Estoque
void editarProduto(struct Produto estoque[], int tamanho, struct Modificacao listaModificacoes[], int *numModificacoes, const char *usuario) {
    int id;
    printf("\nQual ID deseja editar?\n: ");
    scanf("%d", &id);

    for (int i = 0; i < tamanho; i++) {
        if (estoque[i].id == id) {
            // Encontra o produto com o ID correspondente
            printf("Editando o produto com ID %d:\n", id);

            // Obter os valores antigos do produto
            double precoAntigo = estoque[i].preco;
            char nomeAntigo[50];
            strcpy(nomeAntigo, estoque[i].nome);
            int quantidadeAntiga = estoque[i].quantidade;

            // Solicitar as informa��es atualizadas ao usu�rio
            printf("Novo Nome: ");
            scanf(" %[^\n]", estoque[i].nome);

            printf("Novo Pre�o: ");
            scanf("%lf", &estoque[i].preco);

            printf("Nova Quantidade: ");
            scanf("%d", &estoque[i].quantidade);

            // Registrar a modifica��o ap�s as altera��es
            registrarModificacao(listaModificacoes, numModificacoes, "Edi��o de Produto",
                                 id, precoAntigo, estoque[i].preco, nomeAntigo, estoque[i].nome,
                                 quantidadeAntiga, estoque[i].quantidade);

            printf("Produto atualizado com sucesso.\n");
            return;
        }
    }

    // Se chegou aqui, significa que nenhum produto com o ID correspondente foi encontrado
    printf("Produto com ID %d n�o encontrado no estoque.\n", id);
}










//                                Carrinho

//Itens Comprados
void exibirItensComprados(struct Produto itensComprados[], int tamanho) {
    double total = 0;

    printf("| %-4s | %-30s | %-15s | %-10s |\n", "ID", "Nome", "Pre�o", "Quantidade");
    printf("|------|--------------------------------|-----------------|------------|\n");

    for (int i = 0; i < tamanho; i++) {
        if (itensComprados[i].id == 0) {
            break; // Sai do loop quando encontrar um elemento n�o preenchido
        }
        printf("| %4d | %-30s | %-12.2f R$ | %10d |\n",
               itensComprados[i].id, itensComprados[i].nome, itensComprados[i].preco, itensComprados[i].quantidade);

        total += itensComprados[i].preco * itensComprados[i].quantidade;
    }
    printLine('-', 72);
    printf("\nTotal gasto: %.2lf", total);
    printf("\n");
}

//Inserir Produto - Carrinho
void adicionarAoCarrinho(struct Produto estoque[], struct Produto carrinho[], int tamanhoEstoque) {

    int id, quantidade;

    printf("Informe o ID do produto que deseja inserir: ");
    scanf("%d", &id);

    // Encontre o produto com base no ID no estoque
    int indiceProduto = -1;
    for (int i = 0; i < tamanhoEstoque; i++) {
        if (estoque[i].id == id) {
            indiceProduto = i;
            break;
        }
    }
    //Verifica se foi encontrado o item pelo ID
    if (indiceProduto == -1) {
        printf("Produto com ID %d n�o encontrado no estoque.\n", id);
        return;
    }

    // Pergunte a quantidade desejada
    printf("Informe a quantidade desejada: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade inv�lida. Por favor, informe uma quantidade maior que zero.\n");
        return;
    }

    if (quantidade > estoque[indiceProduto].quantidade) {
        printf("Quantidade desejada maior do que a dispon�vel no estoque.\n");
        return;
    }

    // Verifique se h� espa�o no carrinho
    int numeroProdutos = 0;
    for (int i = 0; i < MAX_ElementosCarrinho; i++) {
        if (carrinho[i].id != 0) {
            numeroProdutos++;
        }
    }

    if (numeroProdutos >= MAX_ElementosCarrinho) {
        printf("O carrinho est� cheio. N�o � poss�vel adicionar mais produtos.\n");
        return;
    }

    // Adicione o produto ao carrinho
    carrinho[numeroProdutos] = estoque[indiceProduto];
    carrinho[numeroProdutos].quantidade = quantidade;
    printf("Produto \"%s\" (%d unidades) adicionado ao carrinho.\n", estoque[indiceProduto].nome, quantidade);
}

//Exibir Carrinho
void consultarCarrinho(struct Produto carrinho[], int tamanho) {
    printf("| %-4s | %-30s | %-15s | %-10s |\n", "ID", "Nome", "Pre�o", "Quantidade");
    printf("|------|--------------------------------|-----------------|------------|\n");

    for (int i = 0; i < tamanho; i++) {
        if (carrinho[i].id != 0) {
            printf("| %4d | %-30s | %-12.2f R$ | %10d |\n",
               carrinho[i].id, carrinho[i].nome, carrinho[i].preco, carrinho[i].quantidade);
        }

    }

    printLine('-', 72);
}

//Finalizar Compra - Carrinho
void finalizarCompra(struct Produto carrinho[], struct Produto estoque[], struct Produto ItensComprados[], int *tamanhoMaxCarrinho) {
    if (*tamanhoMaxCarrinho == 0) {
        printf("O carrinho est� vazio. Nada a comprar.\n");
        return;
    }

    double totalAPagar = 0.0;

    for (int i = 0; i < *tamanhoMaxCarrinho; i++) {
        if (carrinho[i].id == 0) {
            break;
        }

        // Verifique se h� quantidade suficiente no estoque
        if (carrinho[i].quantidade > estoque[i].quantidade) {
            printf("Quantidade do produto \"%s\" no carrinho � maior do que a dispon�vel no estoque. Compra cancelada.\n", carrinho[i].nome);
            return;
        }

        totalAPagar += carrinho[i].preco * carrinho[i].quantidade;

        // Diminua a quantidade no estoque
        for (int j = 0; j < MAX_ElementosLista; j++) {
            if (estoque[j].id == carrinho[i].id) {
                estoque[j].quantidade -= carrinho[i].quantidade;
                break;
            }
        }

        // Adicione os produtos comprados � lista ItensComprados
        for (int k = 0; k < MAX_ElementosLista; k++) {
            if (ItensComprados[k].id == 0) {
                ItensComprados[k] = carrinho[i];
                ItensComprados[k].quantidade = carrinho[i].quantidade;
                break;
            }
        }

        // Limpe o produto do carrinho
        carrinho[i].id = 0;
        strcpy(carrinho[i].nome, "");
        carrinho[i].preco = 0.0;
        carrinho[i].quantidade = 0;
    }


    printf("Compra finalizada com sucesso! Total a pagar: %.2f R$\n", totalAPagar);
}

//------------------------------------------------------------------------------
