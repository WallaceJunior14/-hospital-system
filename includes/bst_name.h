#ifndef H_BST_NAME
#define H_BST_NAME

/**
 * @brief 
 */
typedef struct _patient PatientNodeName;

PatientNodeName *createNodeByName(const unsigned int id, const char *name, const unsigned int age, const char *medical_condition);

PatientNodeName *insertNodeByName(PatientNodeName *root, const unsigned int id, const char *name, const unsigned int age, const char *medical_condition);

PatientNodeName *searchNodeByName(PatientNodeName *root, const char *name);

PatientNodeName *findMinName(PatientNodeName *root);

PatientNodeName *deleteNodeByName(PatientNodeName *root, const char *name);

void preOrderByName(const PatientNodeName *root); 

#endif