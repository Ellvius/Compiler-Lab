#include "label.h"

lnode* head = NULL;

lnode* createLabel(char* label, int addr){
    lnode* node = (lnode*)malloc(sizeof(lnode));

    node->label = label;
    node->address = addr;

    node->next = head;
    head = node;
    return node;
}

int getLabelAddr(char* label){
    lnode* temp = head;

    while(temp != NULL){
        if(strcmp(temp->label, label) == 0){
            return temp->address;
        }
        temp = temp->next;
    }
    return -1;
}