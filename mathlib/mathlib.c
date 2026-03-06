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
int modulo(int a, int b) { return 0; }
double power(double base, int exponent) { return 0.0; }
double root(double value, int n) { return 0.0; }
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