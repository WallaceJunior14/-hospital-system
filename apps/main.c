#include <stdio.h>
#include <stdlib.h>
#include "bst_id.h"
#include "bst_name.h"

int main() {
    PatientNodeId *root_id = NULL; 
    PatientNodeName *root_name = NULL;

    int line_id, line_age, choice;
    char line_name[20], line_medical_condition[30], line_file[100];

    // Opening the register of existing patients
    FILE *file = fopen("./input/first_input.txt", "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Reading each patient and adding it to the BST
    while (fgets(line_file, sizeof(line_file), file) != NULL) {
        sscanf(line_file, "%d %s %d %s", &line_id, line_name, &line_age, line_medical_condition);

        if (searchNodeById(root_id, line_id) == NULL) {
            root_id = insertNodeById(root_id, line_id, line_name, line_age, line_medical_condition);
        }

        if (searchNodeByName(root_name, line_name) == NULL) {
            root_name = insertNodeByName(root_name, line_id, line_name, line_age, line_medical_condition);
        }
    }

    // Closing the file
    fclose(file);

    // Menu
    while (1) {
        puts("---- HOSPITAL-SYSTEM ----\n");
        puts("1. Register a new patient\n");
        puts("2. Delete a patient\n");
        puts("3. Search for a patient by Id\n");
        puts("4. Search for a patient by Name\n");
        puts("5. List all patients by Id\n");
        puts("6. List all patients by Name\n");
        puts("7. Exit and generate report\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            puts("  Enter id, name, age and medical condition: ");
            scanf("%d %s %d %s", &line_id, line_name, &line_age, line_medical_condition);

            root_id = insertNodeById(root_id, line_id, line_name, line_age, line_medical_condition);
            root_name = insertNodeByName(root_name, line_id, line_name, line_age, line_medical_condition);

            puts("  Patient registered successfully!\n");
            break;

        case 2:
            puts("  Enter id and name: ");
            scanf("%d %s", &line_id, line_name);

            if (searchNodeById(root_id, line_id) == NULL || searchNodeByName(root_name, line_name) == NULL) {
                puts("  Patient not found.\n");
            } else {
                root_id = deleteNodeById(root_id, line_id);
                root_name = deleteNodeByName(root_name, line_name);
                puts("  Patient deleted successfully!\n");
            }
            break;

        case 3:
            puts("  Enter id: ");
            scanf("%d", &line_id);

            if (searchNodeById(root_id, line_id) == NULL) {
                puts("  Patient not found.\n");
            } else {
                printf("    Patient with id '%d' found.\n", line_id);
            }
            break;

        case 4:
            puts("  Enter name: ");
            scanf("%s", line_name);

            if (searchNodeByName(root_name, line_name) == NULL) {
                puts("  Patient not found.\n");
            } else {
                printf("    Patient with name '%s' found.\n", line_name);
            }
            break;
        
        case 5:
            puts("Traversing BST by Id: ");
            traverseId(root_id);
            puts("\n");
            break;

        case 6:
            puts("Traversing BST by Name: ");
            traverseName(root_name);
            puts("\n");
            break;

        case 7:
            puts("Deallocating BST and generating report of patients.\n");
            // TODO: Add code to generate report here
            deallocateById(&root_id);
            deallocateByName(&root_name);
            return 0;

        default:
            printf("Please choose a valid option.\n");
            break;
        }
    }
}
