#include <stdlib.h>
#include <check.h>

#include "ring_buffer.h"

START_TEST(check_ring_buffer)
{
  ring_buffer_t *rb;

  rb = ring_buffer_create(5);

  ck_assert_int_eq(ring_buffer_length(rb), 0);

  ring_buffer_push(rb, 1);
  ck_assert_int_eq(ring_buffer_length(rb), 1);
  ring_buffer_push(rb, 2);
  ck_assert_int_eq(ring_buffer_length(rb), 2);
  ring_buffer_push(rb, 3);
  ck_assert_int_eq(ring_buffer_length(rb), 3);
  ring_buffer_push(rb, 4);
  ck_assert_int_eq(ring_buffer_length(rb), 4);
  ring_buffer_push(rb, 5);
  ck_assert_int_eq(ring_buffer_length(rb), 5);

  /* override 1 */
  ring_buffer_push(rb, 6);
  ck_assert_int_eq(ring_buffer_length(rb), 5);

  /* override 2 */
  ring_buffer_push(rb, 7);
  ck_assert_int_eq(ring_buffer_length(rb), 5);

  /* override 3 */
  ring_buffer_push(rb, 8);
  ck_assert_int_eq(ring_buffer_length(rb), 5);

  ck_assert_int_eq(ring_buffer_pop(rb), 4);
  ck_assert_int_eq(ring_buffer_length(rb), 4);

  ck_assert_int_eq(ring_buffer_pop(rb), 5);
  ck_assert_int_eq(ring_buffer_length(rb), 3);

  ck_assert_int_eq(ring_buffer_pop(rb), 6);
  ck_assert_int_eq(ring_buffer_length(rb), 2);

  ck_assert_int_eq(ring_buffer_pop(rb), 7);
  ck_assert_int_eq(ring_buffer_length(rb), 1);

  ck_assert_int_eq(ring_buffer_pop(rb), 8);
  ck_assert_int_eq(ring_buffer_length(rb), 0);

  ck_assert_int_eq(ring_buffer_pop(rb), -1);

  ring_buffer_destroy(rb);
}
END_TEST

START_TEST(check_ring_buffer_failure)
{
  ring_buffer_t *rb;

  rb = ring_buffer_create(0);

  ring_buffer_push(rb, 0);
  ck_assert_int_eq(ring_buffer_pop(rb), -1);
  ck_assert_int_eq(ring_buffer_length(rb), -1);
  ring_buffer_destroy(rb);
}

Suite *
ring_buffer_suite(void)
{
  Suite *s = suite_create("Ring Buffer Suite");
  TCase *tcase = tcase_create("Ring Buffer test cases");
  tcase_add_test(tcase, check_ring_buffer);
  tcase_add_test(tcase, check_ring_buffer_failure);
  suite_add_tcase(s, tcase);

  return s;
}

int
main(void)
{
  int n = 0;

  SRunner *sr = srunner_create(NULL);
  srunner_add_suite(sr, ring_buffer_suite());
  srunner_run_all(sr, CK_ENV);
  n = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (n == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
