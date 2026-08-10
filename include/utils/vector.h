#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Structure representing a dynamic vector.
 */

typedef struct {
  char *data;       /**< Pointer to the allocated memory buffer. */
  size_t data_size; /**< Size of each individual element in bytes. */
  size_t length;    /**< Current number of elements stored in the vector. */
  size_t capacity;  /**< Total number of elements the buffer can hold before
                       reallocating. */
} Vector;

/**
 * @brief Initializes a new vector.
 *
 * @param data_size Size of each element in bytes.
 *
 * @return An initialized Vector structure with zero length.
 */
Vector vector_init(size_t data_size);

/**
 * @brief Appends a value to the vector.
 *
 * Grows the internal buffer if necessary and copies the provided value to the
 * end of the vector.
 *
 * @param v Pointer to the Vector structure.
 * @param value Pointer to the data to be appended to the vector.
 *
 * @return 0 if the value was successfully added, or -1 if memory reallocation
 * failed.
 */
int vector_append(Vector *v, void *value);

/**
 * @brief Frees the memory allocated for the vector.
 *
 * Releases the memory buffer used by the vector and resets its length.
 *
 * @param v Pointer to the Vector structure.
 */
void vector_free(Vector *v);

/**
 * @brief Retrieves the values stored in the vector as an array.
 *
 * @param v Pointer to the Vector structure.
 *
 * @return A pointer to a dynamically allocated array containing the values.
 *
 * @note It is the caller's responsibility to free the allocated memory.
 */
void *vector_get_values(Vector *v);

#endif /* VECTOR_H */