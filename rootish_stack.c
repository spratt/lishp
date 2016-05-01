#include <stdlib.h>

#include "rootish_stack.h"

int create_rootish_stack(RootishStack** rs) {
  *rs = malloc(sizeof(RootishStack));
  (*rs)->last = NULL;
  return 0;
}

int push_rootish_stack(RootishStack* rs, uint64_t pos) {
  if(rs->last == NULL || rs->last->size == rs->last->capacity) {
    ListNode* next = malloc(sizeof(ListNode));
    next->size = 0;
    if(rs->last == NULL) {
      next->capacity = 1;
    } else {
      next->capacity = rs->last->size + 1;
    }
    next->pos = malloc(sizeof(uint64_t) * next->size);
    next->prev = rs->last;
    rs->last = next;
  }
  rs->last->pos[rs->last->size++] = pos;
  ++(rs->size);
  return 0;
}

int pop_rootish_stack(RootishStack* rs, uint64_t* pos) {
  if(rs->last == NULL) return -1;
  *pos = rs->last->pos[--(rs->last->size)];
  if(rs->last->size == 0) {
    ListNode* prev = rs->last->prev;
    free(rs->last->pos);
    free(rs->last);
    rs->last = prev;
  }
  --(rs->size);
  return 0;
}

int size_rootish_stack(RootishStack* rs) {
  return rs->size;
}
