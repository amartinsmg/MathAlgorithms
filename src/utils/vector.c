#include "utils/vector.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

Vector vector_init(size_t data_size) {
  Vector v = {0};
  v.data_size = data_size;
  return v;
}

int vector_append(Vector *v, void *value) {
  if (v->length == v->capacity) {
    size_t new_capacity = v->capacity ? v->capacity * 2 : 4;

    char *tmp = (char *)realloc(v->data, new_capacity * v->data_size);
    if (!tmp)
      return -1;

    v->capacity = new_capacity;
    v->data = tmp;
  }

  memcpy(v->data + (v->length * v->data_size), value, v->data_size);

  v->length++;

  return 0;
}

void vector_free(Vector *v) {
  free(v->data);
  v->length = 0;
  v->capacity = 0;
}

void *vector_get_values(Vector *v) {
  char *values = (char *)malloc(v->data_size * v->length);

  memcpy(values, v->data, v->length * v->data_size);

  return values;
}
