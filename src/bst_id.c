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
    PatientNodeId *node = (PatientNodeId*) malloc(sizeof(PatientNodeId));

    if (node)
    {
        node->id = id;
        strcpy(node->name, name);
        node->age = age;
        strcpy(node->medical_condition, medical_condition);
        node->left = node->right = NULL;
    }
    return node;
}

PatientNodeId *insertNodeById(PatientNodeId *root, const unsigned int id, const char *name, const unsigned int age, const char *medical_condition)
{
    if (root == NULL)
    {
        root = createNodeById(id, name, age, medical_condition);
    } else if (id <= root->id)
    {
        root->left = insertNodeById(root->left, id, name, age, medical_condition);
    } else 
    {
        root->right = insertNodeById(root->right, id, name, age, medical_condition);
    }
    
    return root;
}

PatientNodeId *searchNodeById(PatientNodeId *root, const unsigned int id)
{
    if (root == NULL || root->id == id)
    {
        return root;
    } else if (id < root->id)
    {
        return searchNodeById(root->left, id);
    } else 
    {
        return searchNodeById(root->right, id);
    }
}

PatientNodeId *findMin(PatientNodeId *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

PatientNodeId *deleteNodeById(PatientNodeId *root, const unsigned int id)
{
    // Caso 1: o nó é uma folha
    if (root == NULL ) return root;

    // Caso 2: o nó tem apenas um folho
    if (id < root->id) {
        root->left = deleteNodeById(root->left, id);
    } else if (id > root->id)
    {
        root->right = deleteNodeById(root->right, id);
    } 
    // Caso 3: o nó tem 2 filhos
    else {
        if (root->left == NULL) {
            PatientNodeId *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            PatientNodeId *temp = root->left;
            free(root);
            return temp;
        }

        // Encontra o menos valor da subárvore direita
        PatientNodeId *temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        root->age = temp->age;
        strcpy(root->medical_condition, temp->medical_condition);
    }
    return root;
}

void preOrderById(const PatientNodeId *root)
{
    if (root != NULL)
    {
        printf("%d ", root->id);
        preOrderById(root->left);
        preOrderById(root->right);
    }
} 

