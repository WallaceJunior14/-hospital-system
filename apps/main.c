#include <stdio.h>
#include <stdlib.h>
#include "bst_id.h"
#include "bst_name.h"

int main()
{
    PatientNodeId *root_id = NULL; 
    PatientNodeName *root_name = NULL;

    int line_id, line_age, option;
    char line_name[20], line_medical_condition[30], line_file[100];

    // Reading the user's necessity
    while(1)
    {
        printf("Do you want to order the patients by ID or by Name? Type 0 for ID and 1 for Name: ");

        if (scanf("%d", &option) != 1)
        {
            // Caso de erro na leitura
            printf("Invalid input. Please enter 0 or 1.\n");
            // Limpar o buffer do stdin
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        if (option == 0 || option == 1) break;
        else
            printf("Invalid option. Please enter 0 or 1.\n");
    }


    // Opening the input file
    FILE *file = fopen("./input/first_input.txt", "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Reading each line separate
    while(fgets(line_file, sizeof(line_file), file) != NULL)
    {
        sscanf(line_file, "%d %s %d %s", &line_id, line_name, &line_age, line_medical_condition);

        if (!option) {
            insertNodeById(root_id, line_id, line_name, line_age, line_medical_condition);
        } else {
            insertNodeByName(root_name, line_id, line_name, line_age, line_medical_condition);
        }

        printf("%d, %s, %d, %s\n", line_id, line_name, line_age, line_medical_condition);
    }

    // Closing the file
    fclose(file);

    return 0;
}
