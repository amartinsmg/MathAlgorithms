#include "utils/set.h"
#include <stdlib.h>
#include <string.h>

Set set_init(size_t data_size) {
  Set s = {0};
  s.data_size = data_size;
  return s;
}

bool set_contains(Set *s, void *value) {
  size_t i;

  for (i = 0; i < s->length; i++) {
    if (!memcmp(s->data + (i * s->data_size), value, s->data_size))
      return true;
  }

  return false;
}

int set_add_value(Set *set, void *value) {
  if (set_contains(set, value))
    return 0;

  if (set->length == set->capacity) {
    size_t new_capacity = set->capacity ? set->capacity * 2 : 4;

    char *tmp = (char *)realloc(set->data, new_capacity * set->data_size);
    if (!tmp)
      return -1;

    set->capacity = new_capacity;
    set->data = tmp;
  }

  memcpy(set->data + (set->length * set->data_size), value, set->data_size);

  set->length++;

  return 1;
}

void set_free(Set *set) {
  free(set->data);
  set->length = 0;
  set->capacity = 0;
}

void *set_get_values(Set *s) {
  char *values = (char *)malloc(s->data_size * s->length);

  memcpy(values, s->data, s->length * s->data_size);

  return values;
}
