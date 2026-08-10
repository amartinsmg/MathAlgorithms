#include "utils/sort.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

double *sort(const double *arr, size_t length) {
  if (length == 0)
    return NULL;

  double *buffer_1 = (double *)malloc(sizeof(*buffer_1) * length);
  double *buffer_2 = (double *)malloc(sizeof(*buffer_2) * length);
  double *src;
  double *target;
  double *left;
  double *right;
  double *result;
  double *unused;
  size_t log2_length = (size_t)ceil(log2((double)length));
  size_t i;
  size_t j;
  size_t k;
  size_t half;
  size_t target_i;
  size_t left_i;
  size_t right_i;
  size_t pow_2_i;

  for (i = 0; i < length; i++)
    buffer_1[i] = arr[i];

  for (i = 1; i <= log2_length; i++) {
    src = i % 2 ? buffer_1 : buffer_2, target = !(i % 2) ? buffer_1 : buffer_2;
    target_i = 0;
    pow_2_i = 1 << i;
    half = pow_2_i / 2;
    for (j = 0; j < length; j += pow_2_i) {
      left = (double *)(src + j);
      right = (double *)(left + half);
      left_i = right_i = 0;
      for (k = 0; k < pow_2_i && target_i < length; k++)
        if (left_i >= half)
          target[target_i++] = right[right_i++];
        else if (right_i >= half || j + half + right_i >= length)
          target[target_i++] = left[left_i++];
        else
          target[target_i++] =
              left[left_i] < right[right_i] ? left[left_i++] : right[right_i++];
    }
  }

  result = log2_length % 2 ? buffer_2 : buffer_1;
  unused = log2_length % 2 ? buffer_1 : buffer_2;

  free(unused);

  return result;
}