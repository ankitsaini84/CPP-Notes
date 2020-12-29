/**
 * NOTE: Using a conditional statement to detect an invalid parameter
 * (or to validate some other kind of assumption), along with printing 
 * an error message and terminating the program, is such a common 
 * response to problems that C++ provides a shortcut method for doing this.
 * 
 * An ASSERTION is an expression that will be true unless there is a bug 
 * in the program. If the expression evaluates to true, the assertion 
 * statement does nothing. If the conditional expression evaluates to 
 * false, an error message is displayed and the program is terminated (via 
 * std::abort). This error message typically contains the expression that 
 * failed as text, along with the name of the code file and the line 
 * number of the assertion. This makes it very easy to tell not only what 
 * the problem was, but where in the code the problem occurred. This can 
 * help with debugging efforts immensely.
 */

/**
 * NOTE: NDEBUG macro -
 * Since, asserts should (idealy) be used for debugging purposes and
 * thus, should never land in production code.
 * To disable asserts - define macro NDEBUG.
 * NDEBUG is set in VS by default. Thus, to make it work in VS,
 * disable this flag for asserts to work.
 */

#include <cassert>
#include <cmath>
#include <iostream>

/**
 * STATIC ASSERTS - 
 * A static_assert is an assertion  that is checked at compile-time rather
 * than at runtime, with failing static_assert causing a compile error.
 * Format : static_assert(condition, diagnostinc_message)
 * static_assert(sizeof(long) == 8, "Long should be 8 bytes");
 * static_assert(sizeof(int) == 4, "Int should be 4 bytes");
 * IMP: Because static_assert is evauated by the compiler, the condition
 * must be able to be evaluated at compile time (Unlike 'assert', which
 * is evalued at runtime.)
 */
static_assert(sizeof(long) == 8, "long must be 8 bytes");
// NOTE: Above static_assert will throw following compile time error - 
// assert.cpp:42:28: error: static assertion failed: long must be 8 bytes

double calculateTimeUntilObjectHitsGround(  double initialHeight, 
                                            double gravity) {
  assert(gravity > 0.0);    // The object won't reach the ground unless
                            //  there is positive gravity.
 
  if (initialHeight <= 0.0 && "Gravity should be positive.") {
    // TIP: &&ed statement provides a neat way for putting description with assert statements.
    // How it works ? : A string literal always returns 'true'.
    // Thus, it does not impact the assert triggering statement.
    // And, when assert triggers, the string literal will be included in the assert message.
    return 0.0;
  }

  return std::sqrt((2.0 * initialHeight) / gravity);
}

int main() {
std::cout << sizeof(long);

  std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";

  return 0;
}

// When the program calls calculateTimeUntilObjectHitsGround(100.0, -9.8), 
// assert(gravity > 0.0) will evaluate to false, which will trigger the 
// assert. That will print a message similar to this:

// dropsimulator: src/main.cpp:6: double calculateTimeUntilObjectHitsGround(double, d

// TIP: Use ASSERTIONS to document cases that'd be logically impossible.