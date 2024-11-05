#ifndef H_BST_ID
#define H_BST_ID

/**
 * @brief 
 */
typedef struct _patient PatientNodeId;

PatientNodeId *createNodeById(const unsigned int id, const char *name, const unsigned int age, const char *medical_condition);

PatientNodeId *insertNodeById(PatientNodeId *root, const unsigned int id, const char *name, const unsigned int age, const char *medical_condition);

PatientNodeId *searchNodeById(PatientNodeId *root, const unsigned int id);

PatientNodeId *findMinID(PatientNodeId *root);

PatientNodeId *deleteNodeById(PatientNodeId *root, const unsigned int id);

void traverseId(const PatientNodeId *root); 

void deallocateById(PatientNodeId **root);

#endif