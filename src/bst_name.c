#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst_name.h"

typedef struct _patient 
{
    unsigned int id;
    char name[20];
    int age;
    char medical_condition[30];
    
    struct _patient *left;
    struct _patient *right;
} PatientNodeName;

PatientNodeName *createNodeByName(const unsigned int id, const char *name, const unsigned int age, const char *medical_condition)
{
    PatientNodeName *node = (PatientNodeName*) malloc(sizeof(PatientNodeName));

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

PatientNodeName *insertNodeByName(PatientNodeName *root, const unsigned int id, const char *name, const unsigned int age, const char *medical_condition)
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

PatientNodeName *searchNodeByName(PatientNodeName *root, const unsigned int id)
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

PatientNodeName *findMin(PatientNodeName *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

PatientNodeName *deleteNodeById(PatientNodeName *root, const unsigned int id)
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
            PatientNodeName *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            PatientNodeName *temp = root->left;
            free(root);
            return temp;
        }

        // Encontra o menos valor da subárvore direita
        PatientNodeName *temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        root->age = temp->age;
        strcpy(root->medical_condition, temp->medical_condition);
    }
    return root;
}

void preOrderById(const PatientNodeName *root)
{
    if (root != NULL)
    {
        printf("%d ", root->id);
        preOrderById(root->left);
        preOrderById(root->right);
    }
} 

