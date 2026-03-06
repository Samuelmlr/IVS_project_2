/**
 * @file mathlib.h
 * @author Andrea Drahovská (xdrahoa00@stud.fit.vutbr.cz)
 * @brief Knihovna pro matematické operace
 * @date 2026-03-05
 */

#ifndef MATHLIB_H
#define MATHLIB_H

/**
 * @brief Funkce sečte dvě celá čísla typu int a vrátí výsledek.
 * @param a První sčítanec.
 * @param b Druhý sčítanec.
 * @return int výsledný součet parametrů a a b.
 */
int addition(int a, int b);

/** @brief Rozdíl dvou čísel
 * @param a Menšenec.
 * @param b Menšitel.
 * @return int výsledný rozdíl parametrů a a b.
 */
int subtraction(int a, int b);

/** @brief Součin dvou čísel
 * @param a První činitel.
 * @param b Druhý činitel.
 * @return int výsledný součin parametrů a a b.
 */
int multiplication(int a, int b);

/** @brief Podíl dvou čísel
 * @param a Dělenec.
 * @param b Dělitel.
 * @return double výsledný podíl parametrů a a b.
 */
double division(double a, double b);

/** @brief Modulo (zbytek po celočíselném dělení)
 * @param a Dělenec.
 * @param b Dělitel.
 * @return int výsledný zbytek po celočíselném dělení
 */
int modulo(int a, int b);

/** @brief n-tá mocnina čísla(a^n)
 * @param base Základ mocniny(číslo, které umocňujeme).
 * @param exponent Mocnitel (exponent).
 * @return double Výsledná mocnina.
 *
 */
double power(double base, int exponent);

/** @brief n-tá odmocnina
 * @param value Odmocněnec (číslo, které odmocňujeme).
 * @param n Odmocnitel (stupeň odmocniny).
 * @return double Výsledná odmocnina.
 */
double root(double value, int n);

/** @brief Faktoriál čísla n
 * @param n Číslo, pro které se faktoriál počítá.
 * @return long long Výsledný faktoriál.
 */
long long factorial(int n);

#endif /* MATHLIB_H */