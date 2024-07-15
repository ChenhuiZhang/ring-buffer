#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include <glib.h>

typedef struct ring_buffer {
  gint head;
  gint tail;
  gint size;
  gint length;
  guint buffer[0];
} ring_buffer_t;

ring_buffer_t *
ring_buffer_create(guint length);
void
ring_buffer_push(ring_buffer_t *rb, guint data);
gint
ring_buffer_pop(ring_buffer_t *rb);
gint
ring_buffer_length(ring_buffer_t *rb);
void
ring_buffer_destroy(ring_buffer_t *rb);

#endif /* _RING_BUFFER_H_ */
