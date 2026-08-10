#ifndef SET_H
#define SET_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Structure representing a set of unique values.
 */

typedef struct {
  char *data;       /**< Pointer to the allocated memory buffer. */
  size_t data_size; /**< Size of each element in bytes. */
  size_t length;    /**< Number of elements currently in the set. */
  size_t capacity;  /**< Total number of elements the set can hold before
                       reallocating. */
} Set;

/**
 * @brief Initializes a new set.
 *
 * @param data_size The size of each element in bytes.
 *
 * @return An initialized Set structure with zero length.
 */

Set set_init(size_t data_size);

/**
 * @brief Checks if a value is present in the set.
 *
 * @param s Pointer to the Set structure.
 * @param value Pointer to the value to check for.
 *
 * @return True if the value is found, false otherwise.
 */

bool set_contains(Set *s, void *value);

/**
 * @brief Adds a value to the set.
 *
 * Checks if the value already exists in the set. If not, grows the internal
 * buffer if necessary and appends the new value.
 *
 * @param set Pointer to the Set structure.
 * @param value Pointer to the value to add.
 *
 * @return 1 if the value was added, 0 if it already exists, or -1 if memory
 * allocation failed.
 */

int set_add_value(Set *set, void *value);

/**
 * @brief Frees the memory allocated for the set.
 *
 * @param set Pointer to the Set structure to be cleared.
 */

void set_free(Set *set);

/**
 * @brief Retrieves the values stored in the set as an array.
 *
 * @param s Pointer to the Set structure.
 *
 * @return A dynamically allocated array containing the values in the set.
 *
 * @note It is the caller's responsibility to free the allocated memory.
 */

void *set_get_values(Set *s);

#endif /* SET_H */