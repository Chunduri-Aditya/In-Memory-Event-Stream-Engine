#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "event.h"

int main() {
    Event* stream = NULL;
    int choice;

    do {
        printf("\n--- Event Stream Menu ---\n");
        printf("1. Add Event\n");
        printf("2. Print Stream\n");
        printf("3. Search Event by ID\n");
        printf("4. Delete Event by ID\n");
        printf("5. Reverse Stream\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
            int id;
            char source[50];
            char payload[256];

            printf("Enter Event ID: ");
            scanf("%d", &id);
            getchar();

            printf("Enter Source: ");
            fgets(source, sizeof(source), stdin);
            source[strcspn(source, "\n")] = '\0';

            printf("Enter Payload: ");
            fgets(payload, sizeof(payload), stdin);
            payload[strcspn(payload, "\n")] = '\0';

            Event* new_event = create_event(id, source, payload);
            add_event(&stream, new_event);
            printf("Event added.\n");
        } 
        else if (choice == 2) {
            printf("\nEvent Stream:\n");
            print_stream(stream);
        } 
        else if (choice == 3) {
            int search_id;
            printf("Enter Event ID to search: ");
            scanf("%d", &search_id);
            Event* found = search_event(stream, search_id);
            if (found) {
                printf("Found Event ID %d: Source: %s, Payload: %s\n", found->id, found->source, found->payload);
            } else {
                printf("Event ID %d not found.\n", search_id);
            }
        } 
        else if (choice == 4) {
            int delete_id;
            printf("Enter Event ID to delete: ");
            scanf("%d", &delete_id);
            delete_event_by_id(&stream, delete_id);
            printf("Event ID %d deleted (if it existed).\n", delete_id);
        } 
        else if (choice == 5) {
            reverse_stream(&stream);
            printf("Stream reversed.\n");
        } 
        else if (choice == 6) {
            printf("Exiting and freeing memory...\n");
        } 
        else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    // Free memory
    while (stream != NULL) {
        Event* temp = stream;
        stream = stream->next;
        free(temp);
    }

    return 0;
}
