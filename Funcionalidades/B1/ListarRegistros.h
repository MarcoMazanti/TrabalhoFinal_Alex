#ifndef LISTARREGISTROS_H
#define LISTARREGISTROS_H

typedef struct {
    char date[50];
    char domain[50];
    char location[50];
    int value;
    int transaction_count;
} Record;

void listarRegistros();

#endif