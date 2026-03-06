/**
 * @file mathlib.c
 * @author Andrea Drahovská (xdrahoa00@stud.fit.vutbr.cz)
 * @brief Implementace knihovny pro základní matematické operace
 * @date 2026-03-05
 */

#include "mathlib.h"
#include <math.h>

double addition(double a, double b) { return a + b; }

double subtraction(double a, double b) { return a - b; }

double multiplication(double a, double b) { return a * b; }

double division(double a, double b) {
  if (b == 0.0)
    return NAN;
  return a / b;
}

int modulo(int a, int b) {
  if (b == 0)
    return 0;
  return a % b;
}

double power(double base, int exponent) {
  if (base == 0.0 && exponent < 0)
    return NAN;
  return pow(base, (double)exponent);
}

double root(double value, int n) {
  if (n <= 0)
    return NAN;
  if (value < 0 && n % 2 == 0)
    return NAN;
  if (value == 0)
    return 0.0;
  if (value < 0) {
    return -pow(-value, 1.0 / (double)n);
  }
  return pow(value, 1.0 / (double)n);
}

double factorial(int n) {
  if (n < 0)
    return NAN;
  if (n == 0)
    return 1.0;
  double result = 1.0;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}