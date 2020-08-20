//
// Created by General on 14.08.2020.
//

#include "rational.h"

void TestAll() {
    TestRunner tr;
    RUN_TEST(tr, TestConstructor);
    RUN_TEST(tr, TestZeroNumerator);
    RUN_TEST(tr, TestReduction);
    RUN_TEST(tr, TestPositivity);
    RUN_TEST(tr, TestNegativity);
}

void TestConstructor() {
    Rational r;
    ASSERT_EQUAL(r.Numerator(), 0);
    ASSERT_EQUAL(r.Denominator(), 1);
}

void TestReduction() {
    Rational r(-15, -12);
    ASSERT_EQUAL(r.Numerator(), 5);
    ASSERT_EQUAL( r.Denominator(), 4);
    Rational r1(12, 128);
    ASSERT_EQUAL(r1.Numerator(), 3);
    ASSERT_EQUAL( r1.Denominator(), 32);
    Rational r2(12,-9);
    ASSERT_EQUAL(r2.Numerator(), -4);
    ASSERT_EQUAL( r2.Denominator(), 3);
    Rational r3(-21,49);
    ASSERT_EQUAL(r3.Numerator(), -3);
    ASSERT_EQUAL(r3.Denominator(), 7);
}

void TestPositivity() {
    Rational r(-2, -3);
    ASSERT_EQUAL(r.Numerator(), 2);
    ASSERT_EQUAL(r.Denominator(), 3);
    Rational r1(2, 3);
    ASSERT_EQUAL(r1.Numerator(), 2);
    ASSERT_EQUAL(r1.Denominator(), 3);
}

void TestNegativity() {
    Rational r(4, -5);
    ASSERT_EQUAL(r.Numerator(), -4);
    ASSERT_EQUAL(r.Denominator(), 5);
    Rational r1(-4, 5);
    ASSERT_EQUAL(r1.Numerator(), -4);
    ASSERT_EQUAL( r1.Denominator(), 5);
}

void TestZeroNumerator() {
    Rational r(0,5);
    ASSERT_EQUAL(r.Numerator(), 0);
    ASSERT_EQUAL(r.Denominator(), 1);
    Rational r1(0, -1);
    ASSERT_EQUAL(r1.Numerator(), 0);
    ASSERT_EQUAL(r1.Denominator(), 1);
}
