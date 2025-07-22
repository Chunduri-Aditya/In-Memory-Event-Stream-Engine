#ifndef EVENT_H
#define EVENT_H

// Structure definition for a stream event
typedef struct Event {
    int id;
    char source[50];       // e.g., "sensor-1", "camera-2"
    char payload[256];     // The event message/data
    struct Event* next;    // Pointer to the next event
} Event;

// Function declarations
Event* create_event(int id, char* source, char* payload);
void add_event(Event** head_ref, Event* new_event);
void delete_event_by_id(Event** head_ref, int id);
Event* search_event(Event* head, int id);
void reverse_stream(Event** head_ref);
void print_stream(Event* head);

#endif // EVENT_H