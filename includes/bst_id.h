#ifndef H_BST_ID
#define H_BST_ID

/**
 * @brief node;
 * @typedef PatientNodeId
 */
typedef struct _patient PatientNodeId;

/**
 * @brief Create a node in the treee;
 * @param id, *name, age, *medical_condition;
 * @return PatientNodeId;
*/
PatientNodeId *createNodeById(const unsigned int id, const char *name, const unsigned int age, const char *medical_condition);

/**
 * @brief Insert a node in the treee;
 * @param *root, id, *name, age, *medical_condition;
 * @return PatientNodeId;
*/
PatientNodeId *insertNodeById(PatientNodeId *root, const unsigned int id, const char *name, const unsigned int age, const char *medical_condition);

/**
 * @brief Search for a node in the tree by its id;
 * @param *root, id;
 * @return PatientNodeId;
*/
PatientNodeId *searchNodeById(PatientNodeId *root, const unsigned int id);

/**
 * @brief Search for the smallest value within the tree;
 * @param *root;
 * @return PatientNodeId;
*/
PatientNodeId *findMinID(PatientNodeId *root);

/**
 * @brief Delete a node in the tree by its id;
 * @param *root, id;
 * @return PatientNodeId;
*/
PatientNodeId *deleteNodeById(PatientNodeId *root, const unsigned int id);

/**
 * @brief Cross the tree in order;
 * @param *root;
 * @return void;
*/
void traverseId(const PatientNodeId *root); 

/**
 * @brief Deallocate the tree;
 * @param *root;
 * @return void;
*/
void deallocateById(PatientNodeId **root);

#endif