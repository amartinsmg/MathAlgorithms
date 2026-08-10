#include "internal/mathlib_c.h"
#include "utils/sort.h"
#include "utils/vector.h"
#include <stdlib.h>

double mean(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result;
  double sum = 0;
  size_t i;

  for (i = 0; i < length; i++)
    sum += arr[i];

  result = sum / length;
  return result;
}

double trimmedMean(const double *arr, size_t length, double percentage) {
  if (length == 0 || arr == NULL)
    return NAN;

  size_t n_el_to_trim = (size_t)round(nPercentOfX(length, percentage));

  if (2 * n_el_to_trim >= length)
    return NAN;

  double result;
  double *sortedArr = sort(arr, length);
  arr += n_el_to_trim;
  length -= 2 * n_el_to_trim;

  result = mean(arr, length);
  free(sortedArr);

  return result;
}

double geometricMean(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result;
  double product = 1;
  size_t i;

  for (i = 0; i < length; i++) {
    if (arr[i] <= 0)
      return NAN;
    product *= arr[i];
  }

  result = nthRoot(product, length);
  return result;
}

double harmonicMean(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result;
  double sum = 0;
  size_t i;

  for (i = 0; i < length; i++) {
    if (arr[i] <= 0)
      return NAN;
    sum += 1 / arr[i];
  }

  result = length / sum;
  return result;
}

double median(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result;
  double *sorted_arr = sort(arr, length);

  if (length % 2)
    result = sorted_arr[length / 2];
  else
    result = (sorted_arr[(length / 2) - 1] + sorted_arr[length / 2]) / 2;
  free(sorted_arr);

  return result;
}

/**
 * @brief Structure representing a value and its frequency.
 */

typedef struct {
  double value;
  size_t frequency;
} Freq;

double *mode(const double *arr, size_t length, size_t *size) {

  if (length == 0 || arr == NULL)
    return NULL;

  Vector modes = vector_init(sizeof(double));

  double *result = NULL;

  double *sorted_arr = sort(arr, length);
  Freq *frequencies = (Freq *)malloc(sizeof(*frequencies) * length);
  size_t i;
  size_t min_freq = __UINT32_MAX__;
  size_t max_freq = 0;
  size_t freq_len = 0;

  frequencies[0].value = sorted_arr[0];
  frequencies[0].frequency = 1;
  freq_len++;

  for (i = 1; i < length; i++)
    if (sorted_arr[i] == frequencies[freq_len - 1].value)
      frequencies[freq_len - 1].frequency++;
    else {
      frequencies[freq_len].value = sorted_arr[i];
      frequencies[freq_len++].frequency = 1;
    }
  free(sorted_arr);

  for (i = 0; i < freq_len; i++) {
    min_freq = frequencies[i].frequency < min_freq ? frequencies[i].frequency
                                                   : min_freq;
    max_freq = frequencies[i].frequency > max_freq ? frequencies[i].frequency
                                                   : max_freq;
  }

  if (max_freq > min_freq)
    for (i = 0; i < freq_len; i++)
      if (frequencies[i].frequency == max_freq)
        vector_append(&modes, &frequencies[i].value);

  free(frequencies);

  result = vector_get_values(&modes);
  *size = modes.length;
  vector_free(&modes);

  return result;
}

double min(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;
  double result = __DBL_MAX__;
  size_t i;
  for (i = 0; i < length; i++)
    result = arr[i] < result ? arr[i] : result;
  return result;
}

double max(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result = -__DBL_MAX__;
  size_t i;

  for (i = 0; i < length; i++)
    result = arr[i] > result ? arr[i] : result;

  return result;
}

double range(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double minValue = min(arr, length);
  double maxValue = max(arr, length);
  double result = maxValue - minValue;
  return result;
}

double midrange(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double minValue = min(arr, length);
  double maxValue = max(arr, length);
  double result = (maxValue + minValue) / 2;
  return result;
}

double variance(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double mu = mean(arr, length);
  double sum = 0;
  double result;
  size_t i;

  for (i = 0; i < length; i++)
    sum += pow((arr[i] - mu), 2);

  result = sum / length;
  return result;
}

double stdDev(const double *arr, size_t length) {
  if (length == 0 || arr == NULL)
    return NAN;

  double result = sqrt(variance(arr, length));
  return result;
}

double sampleVariance(const double *arr, size_t length) {
  if (length <= 1)
    return NAN;

  double mu = mean(arr, length);
  double sum = 0;
  double result;
  size_t i;

  for (i = 0; i < length; i++)
    sum += pow((arr[i] - mu), 2);

  result = sum / (length - 1);
  return result;
}

double sampleStdDev(const double *arr, size_t length) {
  if (length <= 1)
    return NAN;

  double result = sqrt(sampleVariance(arr, length));
  return result;
}
