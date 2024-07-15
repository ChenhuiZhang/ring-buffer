#include <glib.h>

#include "ring_buffer.h"

int
main(void)
{
  struct ring_buffer *rb = ring_buffer_create(10);
  gint size = 0;

  ring_buffer_push(rb, 1);
  ring_buffer_push(rb, 2);
  ring_buffer_push(rb, 3);
  ring_buffer_push(rb, 4);

  size = ring_buffer_size(rb);

  g_print("Got size: %d\n", size);

  return 0;
}
