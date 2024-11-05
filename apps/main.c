#include <stdio.h>
#include <stdlib.h>
#include "bst_id.h"
#include "bst_name.h"

int main()
{
    PatientNodeId *root = NULL; 

    int line_id, line_age, option = -1;
    char line_name[20], line_medical_condition[30], line_file[30];

    // Reading the user's necessity
    while(option != 0 || option != 1)
    {
        printf("Do you want to order the patients by ID or by Name? Type 0 for ID and 1 for Name: ");
        scanf("%d", &option);
    }

    // Opening the input file
    FILE *file = fopen("./input/first_input.txt", "r");

    // Reading each line separate
    while(fgets(line_file, sizeof(line_file), file) != NULL)
    {
        sscanf(line_file, "%d %s %d %s", line_id, line_name, line_age, line_medical_condition);

        if (!option){
            insertNodeById(root, line_id, line_name, line_age, line_medical_condition);
        } else {
            // insert by name
        }
    }



    return 0;
}