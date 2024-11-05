#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst_id.h"
typedef struct _patient 
{
    unsigned int id;
    char name[20];
    int age;
    char medical_condition[30];    
    struct _patient *left;
    struct _patient *right;
} PatientNodeId;

PatientNodeId *createNodeById(const unsigned int id, const char *name, const unsigned int age, const char *medical_condition)
{
    PatientNodeId *node = (PatientNodeId*)malloc(sizeof(PatientNodeId));

    if (!node){
        printf("Failed to create a new patient.\n");
        return NULL;
    }
    
    node->id = id;
    strcpy(node->name, name);
    node->age = age;
    strcpy(node->medical_condition, medical_condition);
    node->left = node->right = NULL;
    
    return node;
}

PatientNodeId *insertNodeById(PatientNodeId *root, const unsigned int id, const char *name, const unsigned int age, const char *medical_condition)
{
    if (root == NULL){
        root = createNodeById(id, name, age, medical_condition);

    } else if (id <= root->id){
        root->left = insertNodeById(root->left, id, name, age, medical_condition);

    } else {
        root->right = insertNodeById(root->right, id, name, age, medical_condition);
    }
    
    return root;
}

PatientNodeId *searchNodeById(PatientNodeId *root, const unsigned int id)
{
    if (root == NULL || root->id == id){
        return root;

    } else if (id < root->id){
        return searchNodeById(root->left, id);

    } else {
        return searchNodeById(root->right, id);
    }
}

PatientNodeId *findMinID(PatientNodeId *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

PatientNodeId *deleteNodeById(PatientNodeId *root, const unsigned int id)
{
    // Case 1: the node is a leaf
    if (root == NULL ) return root;

    // Case 2: the node has only one son
    if (id < root->id){
        root->left = deleteNodeById(root->left, id);

    } else if (id > root->id){
        root->right = deleteNodeById(root->right, id);

    } else { // Case 3: the node has two sons
        if (root->left == NULL) {
            PatientNodeId *temp = root->right;
            free(root);
            return temp;

        } else if (root->right == NULL) {
            PatientNodeId *temp = root->left;
            free(root);
            return temp;
        }

        // Finds the minimum value in the right subtree
        PatientNodeId *temp = findMinID(root->right);
        
        // Copy the minimum node's values to the current node
        root->id = temp->id;
        strcpy(root->name, temp->name);
        root->age = temp->age;
        strcpy(root->medical_condition, temp->medical_condition);

        // Delete the duplicate node in the right subtree
        root->right = deleteNodeById(root->right, temp->id);
    }
    return root;
}

void traverseId(const PatientNodeId *root)
{
    if (root != NULL)
    {
        traverseId(root->left);
        printf("%d ", root->id);
        traverseId(root->right);
    }
} 

void deallocateById(PatientNodeId **root)
{
    if (*root == NULL)
        return;

    deallocateById(&((*root)->left)); 
    deallocateById(&((*root)->right));  
    free(*root);                       
    *root = NULL;                      
}

void generate_output_file_from_id_tree(PatientNodeId *root)
{
    if (root != NULL)
    {
        // Primeiro, percorre o lado esquerdo da árvore
        generate_output_file_from_id_tree(root->left);

        // Em seguida, processa o nó raiz (atual)
        FILE *arq_log = fopen("./output/log_root_id.txt", "a");
        if (arq_log == NULL){
            perror("Error opening the file.");
            return;
        }
        
        fprintf(arq_log, "%d %s %d %s\n", root->id, root->name, root->age, root->medical_condition);

        fclose(arq_log);

        // Finalmente, percorre o lado direito da árvore
        generate_output_file_from_id_tree(root->right);
    }
}