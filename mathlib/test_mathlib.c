/**
 * @file test_math.c
 * @author Andrea Drahovská (xdrahoa00@stud.fit.vutbr.cz)
 * @brief Testy pro knihovnu mathlib
 * @date 2026-03-05
 */

#include "mathlib.h"
#include <check.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief Testuje funkci addition pro sčítání reálných čísel.
 * * Test zahrnuje:
 * - sčítání celých čísel předaných jako double
 * - sčítání kladných desetinných čísel
 * - sčítání záporných desetinných čísel
 * - sčítání velmi malých hodnot (ověření přesnosti)
 */
START_TEST(test_addition) {
  // Celá čísla jako double
  ck_assert_double_eq_tol(addition(1.0, 2.0), 3.0, 0.001);
  ck_assert_double_eq_tol(addition(-100.0, 1.0), -99.0, 0.001);

  // Desetinná čísla
  ck_assert_double_eq_tol(addition(1.5, 0.2), 1.7, 0.001);
  ck_assert_double_eq_tol(addition(100.1, 9.9), 110.0, 0.001);

  // Záporná desetinná čísla
  ck_assert_double_eq_tol(addition(-1.5, -2.5), -4.0, 0.001);
  ck_assert_double_eq_tol(addition(-10.5, 5.2), -5.3, 0.001);

  // Velmi malá čísla
  ck_assert_double_eq_tol(addition(0.0001, 0.0002), 0.0003, 0.00001);
}
END_TEST

/**
 * @brief Testuje funkci subtraction pro odčítání reálných čísel.
 * * Test zahrnuje:
 * - základní rozdíly celých čísel
 * - odečítání desetinných čísel
 * - odečítání záporných čísel (ověření znaménkových pravidel)
 */
START_TEST(test_subtraction) {
  // Základní
  ck_assert_double_eq_tol(subtraction(10.0, 4.0), 6.0, 0.001);
  ck_assert_double_eq_tol(subtraction(0.0, 5.0), -5.0, 0.001);

  // Desetinná
  ck_assert_double_eq_tol(subtraction(5.5, 2.1), 3.4, 0.001);
  ck_assert_double_eq_tol(subtraction(1.1, 1.1), 0.0, 0.001);

  // Odčítání záporného čísla
  ck_assert_double_eq_tol(subtraction(5.0, -2.5), 7.5, 0.001);
  ck_assert_double_eq_tol(subtraction(-10.2, -1.2), -9.0, 0.001);
}
END_TEST

/**
 * @brief Testuje násobení reálných čísel.
 */
START_TEST(test_multiplication) {
  ck_assert_double_eq_tol(multiplication(1.0, 2.0), 2.0, 0.001);
  ck_assert_double_eq_tol(multiplication(-2.0, 5.0), -10.0, 0.001);
  ck_assert_double_eq_tol(multiplication(1.5, 2.0), 3.0, 0.001);
  ck_assert_double_eq_tol(multiplication(0.0, 50.5), 0.0, 0.001);
  ck_assert_double_eq_tol(multiplication(0.2, 0.2), 0.04, 0.001);
}
END_TEST

/**
 * @brief Testuje dělení reálných čísel včetně dělení nulou.
 */
START_TEST(test_division) {
  ck_assert_double_eq_tol(division(10.0, 2.0), 5.0, 0.001);
  ck_assert_double_eq_tol(division(5.0, 4.0), 1.25, 0.001);
  ck_assert_double_eq_tol(division(-10.0, 4.0), -2.5, 0.001);

  // Test dělení nulou - očekáváme not a number
  double result = division(5.0, 0.0);
  ck_assert_msg(isnan(result), "Dělení nulou musí vrátit NAN");
}
END_TEST

/**
 * @brief Testuje funkci factorial.
 * Testuje základní hodnoty, nulu a záporný vstup.
 */
START_TEST(test_factorial) {
  ck_assert_int_eq(factorial(0), 1);        // 0! = 1
  ck_assert_int_eq(factorial(1), 1);        // 1! = 1
  ck_assert_int_eq(factorial(5), 120);      // 5! = 120
  ck_assert_int_eq(factorial(10), 3628800); // Větší číslo

  double res = factorial(-5);
  ck_assert_msg(isnan(res), "Faktoriál záporného čísla musí vrátit NAN");
}
END_TEST

/**
 * @brief Testuje funkci mocniny (power).
 */
START_TEST(test_power) {
  // Celá čísla
  ck_assert_double_eq_tol(power(2.0, 3), 8.0, 0.001); // 2^3 = 8
  ck_assert_double_eq_tol(power(3.0, 2), 9.0, 0.001); // 3^2 = 9

  // Desetinný základ
  ck_assert_double_eq_tol(power(2.5, 2), 6.25, 0.001); // 2.5^2 = 6.25

  // Nultá mocnina (vždy 1, i pro 0^0 se v C definuje 1)
  ck_assert_double_eq_tol(power(5.0, 0), 1.0, 0.001);
  ck_assert_double_eq_tol(power(0.0, 0), 1.0, 0.001);

  // Záporný exponent (1 / base^exponent)
  ck_assert_double_eq_tol(power(2.0, -2), 0.25, 0.001); // 2^-2 = 1/4 = 0.25

  // Základ nula a záporný exponent (dělení nulou -> NAN)
  double res = power(0.0, -1);
  ck_assert_msg(isnan(res), "Mocnina 0^-1 musi vratit NAN (deleni nulou)");
}
END_TEST

/**
 * @brief Testuje funkci odmocniny (root).
 */
START_TEST(test_root) {
  // Cela čísla
  ck_assert_double_eq_tol(root(4.0, 2), 2.0, 0.001);  // sqrt(4) = 2
  ck_assert_double_eq_tol(root(27.0, 3), 3.0, 0.001); // cubert(27) = 3
  ck_assert_double_eq_tol(root(0.0, 2), 0.0, 0.001);  // sqrt(0) = 0

  // Desetinné výsledky
  ck_assert_double_eq_tol(root(2.0, 2), 1.414, 0.001); // sqrt(2) cca 1.414

  // Neplatné vstupy -> NAN
  // Sudá odmocnina ze záporného čísla
  double result_neg = root(-4.0, 2);
  ck_assert_msg(isnan(result_neg), "Suda odmocnina ze zaporneho cisla = NAN");

  // Nultá odmocnina
  double result_zero = root(10.0, 0);
  ck_assert_msg(isnan(result_zero), "Nulta odmocnina = NAN");
}
END_TEST

// sada testu
Suite *math_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("MathLib_Tests");
  tc_core = tcase_create("Core_Operations");

  tcase_add_test(tc_core, test_addition);
  tcase_add_test(tc_core, test_subtraction);
  tcase_add_test(tc_core, test_multiplication);
  tcase_add_test(tc_core, test_division);
  tcase_add_test(tc_core, test_factorial);
  tcase_add_test(tc_core, test_power);
  tcase_add_test(tc_core, test_root);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = math_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}