#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * @brief Sorts an array of doubles in ascending order.
 *
 * This function takes an array of doubles and sorts it in ascending order using
 * the merge sort algorithm.
 *
 * @param arr The array of doubles to be sorted.
 * @param length The length of the array.
 *
 * @return A pointer to the sorted array of doubles.
 *
 * @note It is the caller's responsibility to free the memory allocated for the
 * array.
 */

double *sort(const double *arr, size_t length);

#endif /* SORT_H */
