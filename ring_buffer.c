#include "ring_buffer.h"

ring_buffer_t *
ring_buffer_create(guint length)
{
  struct ring_buffer *rb;

  g_return_val_if_fail(length > 0, NULL);

  rb = (ring_buffer_t *) g_malloc0(
          sizeof(struct ring_buffer) + sizeof(guint) * length);

  rb->size = length;

  return rb;
}

void
ring_buffer_push(ring_buffer_t *rb, guint data)
{
  g_return_if_fail(rb != NULL);

  if (rb->length == rb->size) {
    rb->head = (rb->head + 1) % rb->size; // Move head to the next element
  } else {
    rb->length++;
  }

  rb->buffer[rb->tail] = data;
  rb->tail = (rb->tail + 1) % rb->size;

  return;
}

gint
ring_buffer_pop(ring_buffer_t *rb)
{
  gint v;

  g_return_val_if_fail(rb != NULL, -1);

  if (rb->length == 0) {
    return -1; // Return an error value
  }

  v = rb->buffer[rb->head];
  rb->head = (rb->head + 1) % rb->size;
  rb->length--;

  return v;
}

gint
ring_buffer_length(ring_buffer_t *rb)
{
  g_return_val_if_fail(rb != NULL, -1);

  return rb->length;
}

void
ring_buffer_destroy(ring_buffer_t *rb)
{
  g_return_if_fail(rb != NULL);

  g_free(rb);

  return;
}
