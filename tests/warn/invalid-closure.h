#include "common.h"

typedef GCallback TestCallback;

/**
 * test_invalid_closure:
 * @callback: (closure a b):
 * @user_data:
 */
void test_invalid_closure(TestCallback callback, gpointer user_data);

// EXPECT:7: Warning: Test: "closure" annotation takes at most one option, 2 given

/**
 * test_invalid_closure2:
 * @callback:
 * @user_data: (closure callback):
 */
void test_invalid_closure2(TestCallback callback, gpointer user_data);

// EXPECT:17: Warning: Test: invalid "closure" annotation: only valid on callback parameters

/**
 * test_invalid_closure3:
 * @callback: (closure user_data):
 * @user_data:
 */
void test_invalid_closure3(TestCallback callback, gint user_data);

// EXPECT:25: Warning: Test: invalid "closure" annotation: only valid with gpointer parameters

/**
 * TestInvalidClosureCallback:
 * @foo:
 * @user_data: (closure a):
 */
typedef void (*TestInvalidClosureCallback) (int foo, gpointer user_data);

// EXPECT:35: Warning: Test: "closure" annotation takes no options, 1 given

/**
 * TestInvalidClosureCallback2:
 * @foo: (closure):
 * @user_data:
 */
typedef void (*TestInvalidClosureCallback2) (int foo, gpointer user_data);

// EXPECT:43: Warning: Test: invalid "closure" annotation: only valid on gpointer parameters

// EXPECT:5: Warning: Test: test_invalid_closure: argument callback: Missing (scope) annotation for callback without GDestroyNotify (valid: call, async)
// EXPECT:14: Warning: Test: test_invalid_closure2: argument callback: Missing (scope) annotation for callback without GDestroyNotify (valid: call, async)
// EXPECT:23: Warning: Test: test_invalid_closure3: argument callback: Missing (scope) annotation for callback without GDestroyNotify (valid: call, async)
