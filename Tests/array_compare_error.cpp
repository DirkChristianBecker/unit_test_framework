#include "../Source/unit_test_framework.h"

TEST(foo) {
  int c[] = { 1, 2 };
  int d[] = { 1, 2 };
  ASSERT_EQUAL(c, d);
  ASSERT_EQUAL(c, &*d);
  ASSERT_EQUAL(&*c, d);
  ASSERT_EQUAL(&*c, &*d);
}

TEST_MAIN()
