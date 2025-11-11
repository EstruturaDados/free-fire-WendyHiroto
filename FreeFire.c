#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da struct Item conforme os requisitos funcionais.
// A struct representa um item na mochila, com nome, tipo e quantidade.
typedef struct {
    char nome[30];    // Nome do item (até 29 caracteres + null terminator)
    char tipo[20];    // Tipo do item (ex: arma, munição, cura) (até 19 caracteres + null terminator)
    int quantidade;   // Quantidade do item
} Item;

// Função para inserir um item na mochila.
// Verifica se há espaço (máximo 10 itens), lê os dados do usuário e adiciona ao vetor.
// Após a inserção, lista os itens automaticamente.
void inserirItem(Item itens[], int *numItens) {
    if (*numItens >= 10) {
        printf("Erro: Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }
    
    Item novoItem;
    
    // Leitura do nome usando scanf para evitar problemas com espaços
    printf("Digite o nome do item (até 29 caracteres): ");
    scanf("%29s", novoItem.nome);  // Limita a 29 caracteres para evitar overflow
    
    // Leitura do tipo
    printf("Digite o tipo do item (ex: arma, municao, cura) (até 19 caracteres): ");
    scanf("%19s", novoItem.tipo);  // Limita a 19 caracteres
    
    // Leitura da quantidade
    printf("Digite a quantidade do item: ");
    scanf("%d", &novoItem.quantidade);
    
    // Adiciona o item ao vetor
    itens[*numItens] = novoItem;
    (*numItens)++;
    
    printf("Item adicionado com sucesso!\n");
    listarItens(itens, *numItens);  // Lista os itens após a operação
}

// Função para remover um item da mochila pelo nome.
// Busca sequencialmente o item, remove-o (shiftando o vetor) e decrementa o contador.
// Após a remoção, lista os itens automaticamente.
void removerItem(Item itens[], int *numItens) {
    if (*numItens == 0) {
        printf("Erro: Mochila vazia! Não há itens para remover.\n");
        return;
    }
    
    char nomeRemover[30];
    printf("Digite o nome do item a ser removido: ");
    scanf("%29s", nomeRemover);
    
    int encontrado = 0;
    for (int i = 0; i < *numItens; i++) {
        if (strcmp(itens[i].nome, nomeRemover) == 0) {
            // Remove o item shiftando os elementos seguintes
            for (int j = i; j < *numItens - 1; j++) {
                itens[j] = itens[j + 1];
            }
            (*numItens)--;
            encontrado = 1;
            printf("Item removido com sucesso!\n");
            break;
        }
    }
    
    if (!encontrado) {
        printf("Erro: Item não encontrado na mochila.\n");
    }
    
    listarItens(itens, *numItens);  // Lista os itens após a operação
}

// Função para listar todos os itens registrados na mochila.
// Exibe nome, tipo e quantidade de cada item.
void listarItens(Item itens[], int numItens) {
    if (numItens == 0) {
        printf("Mochila vazia.\n");
        return;
    }
    
    printf("\nItens na mochila:\n");
    for (int i = 0; i < numItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n", itens[i].nome, itens[i].tipo, itens[i].quantidade);
    }
    printf("\n");
}

// Função para buscar um item na mochila pelo nome usando busca sequencial.
// Percorre o vetor comparando nomes e exibe os dados se encontrado.
// Após a busca, lista os itens automaticamente.
void buscarItem(Item itens[], int numItens) {
    if (numItens == 0) {
        printf("Erro: Mochila vazia! Não há itens para buscar.\n");
        return;
    }
    
    char nomeBuscar[30];
    printf("Digite o nome do item a ser buscado: ");
    scanf("%29s", nomeBuscar);
    
    int encontrado = 0;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(itens[i].nome, nomeBuscar) == 0) {
            printf("Item encontrado:\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n", itens[i].nome, itens[i].tipo, itens[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("Erro: Item não encontrado na mochila.\n");
    }
    
    listarItens(itens, numItens);  // Lista os itens após a operação
}

// Função principal: gerencia o menu de opções e chama as funções apropriadas.
// O loop continua até o usuário escolher sair.
int main() {
    Item itens[10];  // Vetor para armazenar até 10 itens
    int numItens = 0;  // Contador de itens na mochila
    int opcao;
    
    printf("Sistema de Gerenciamento de Mochila\n");
    printf("===================================\n");
    
    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                inserirItem(itens, &numItens);
                break;
            case 2:
                removerItem(itens, &numItens);
                break;
            case 3:
                listarItens(itens, numItens);
                break;
            case 4:
                buscarItem(itens, numItens);
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);
    
    return 0;
}
