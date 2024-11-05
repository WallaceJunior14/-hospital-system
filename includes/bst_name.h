#ifndef H_BST_NAME
#define H_BST_NAME

/**
 * @brief node;
 * @typedef PatientNodeName
 */
typedef struct _patient PatientNodeName;

/**
 * @brief Create a node in the treee;
 * @param id, *name, age, *medical_condition;
 * @return PatientNodeName;
*/
PatientNodeName *createNodeByName(const unsigned int id, const char *name, const unsigned int age, const char *medical_condition);

/**
 * @brief Insert a node in the treee;
 * @param *root, id, *name, age, *medical_condition;
 * @return PatientNodeName;
*/
PatientNodeName *insertNodeByName(PatientNodeName *root, const unsigned int id, const char *name, const unsigned int age, const char *medical_condition);

/**
 * @brief Search for a node in the trees by its name;
 * @param *root, *name;
 * @return PatientNodeName;
*/
PatientNodeName *searchNodeByName(PatientNodeName *root, const char *name);

/**
 * @brief Search for the smallest value within the tree;
 * @param *root;
 * @return PatientNodeName;
*/
PatientNodeName *findMinName(PatientNodeName *root);

/**
 * @brief Delete a node in the tree by its name;
 * @param *root, *name;
 * @return PatientNodeName;
*/
PatientNodeName *deleteNodeByName(PatientNodeName *root, const char *name);

/**
 * @brief Cross the tree in order;
 * @param *root;
 * @return void;
*/
void traverseName(const PatientNodeName *root); 

/**
 * @brief Deallocate the tree;
 * @param *root;
 * @return void;
*/
void deallocateByName(PatientNodeName **root);

#endif