#include <stdio.h>
#include <stdlib.h>
#include "bst_id.h"

int main() {
    PatientNodeId *root = NULL; 

    root = insertNodeById(root, 50, "wallace", 21, "renite");
    root = insertNodeById(root, 21, "wallace", 21, "renite");
    root = insertNodeById(root, 55, "wallace", 21, "renite");
    root = insertNodeById(root, 18, "wallace", 21, "renite");
    root = insertNodeById(root, 24, "wallace", 21, "renite");
    root = insertNodeById(root, 65, "wallace", 21, "renite");

    printf("Exibição em Pré-Ordem: ");
    preOrderById(root);
    printf("\n");

    puts("Busca na arvore:");
    PatientNodeId *elem = searchNodeById(root, 24);
    printf("Endereco : %p\n", elem);

    root = deleteNodeById(root, 18);
    printf("Árvore após a remoção de %d:\n", 18);

    puts("Exibição em In-Ordem após remoção: ");
    preOrderById(root);

    puts("");
    root = deleteNodeById(root, 55);
    printf("Árvore após a remoção de %d:\n", 55);

    puts("Exibição em In-Ordem após remoção: ");
    preOrderById(root);
    printf("\n");

    return 0;
}