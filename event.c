#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // required for strcpy
#include "event.h"

Event* create_event(int id, char* source, char* payload)
{
    Event* new_event = (Event*)malloc(sizeof(Event));
    if (!new_event) {
        return NULL;
    }

    new_event->id = id;
    strcpy(new_event->source, source);
    strcpy(new_event->payload, payload);
    new_event->next = NULL;

    return new_event;
}

void add_event(Event** head_ref, Event* new_event)
{
    if (*head_ref == NULL) {
        *head_ref = new_event;
    } else {
        Event* temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_event;
    }
}

void print_stream(Event* head)
{
    Event* temp = head;
    while (temp != NULL) {
        printf("Event ID: %d, Source: %s, Payload: %s\n", temp->id, temp->source, temp->payload);
        temp = temp->next;
    }
}

void delete_event_by_id(Event** head_ref, int id)
{
    Event* temp = *head_ref, *prev = NULL;

    // If head holds the key
    if (temp != NULL && temp->id == id) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // If not found
    if (temp == NULL)
        return;

    // Unlink and free
    prev->next = temp->next;
    free(temp);
}

Event* search_event(Event* head, int id)
{
    Event* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void reverse_stream(Event** head_ref)
{
    Event* prev = NULL;
    Event* current = *head_ref;
    Event* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev; 
}
