//Thien An Tran - U85205230
/*
    Implementation of the storage data structure and its associated 
    functions defined in storage.h.
    See header file for documentation on each of the following functions.
*/

#include "storage.h"

Storage* storage_create(void){
    Storage *storage = (Storage *)malloc(sizeof(Storage));
    if (!storage) {
        return NULL;
    }
    storage->functions_array = NULL;
    storage->functions_array_size = 0;
    return storage;
}


void storage_destroy(Storage *storage){
    if (!storage) {
        return;
    }
    if (storage->functions_array) {
        free(storage->functions_array);
    }
    free(storage);
}


int storage_add_function(Storage *storage, function_pointer_t function){
    if (!storage || !function) {
        return -1;
    }
    if (storage->functions_array == NULL) {
        storage->functions_array = (function_pointer_t *)malloc(sizeof(function_pointer_t));
        if (!storage->functions_array) {
            return -1;
        }
        storage->functions_array[0] = function;
        storage->functions_array_size = 1;
    } else {
        function_pointer_t *tmp = (function_pointer_t *)realloc(
            storage->functions_array,
            (storage->functions_array_size + 1) * sizeof(function_pointer_t));
        if (!tmp) {
            return -1;
        }
        storage->functions_array = tmp;
        storage->functions_array[storage->functions_array_size] = function;
        storage->functions_array_size++;
    }
    return 0;
}


char *(*storage_get_function(Storage *storage, size_t index))(const char *){
    if (!storage || index >= storage->functions_array_size) {
        return NULL;
    }
    return storage->functions_array[index];
}


size_t storage_get_size(Storage *storage){
    if (!storage) {
        return 0;
    }
    return storage->functions_array_size;
}


char **storage_execute_all(Storage *storage, const char *input){
    if (!storage || !input) {
        return NULL;
    }
    size_t size = storage->functions_array_size;
    char **results = (char **)malloc(size * sizeof(char *));
    if (!results) {
        return NULL;
    }
    const char *current = input;
    for (size_t i = 0; i < size; i++) {
        results[i] = storage->functions_array[i](current);
        if (results[i]) {
            current = results[i];
        }
    }
    return results;
}

