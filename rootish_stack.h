#ifndef __ROOTISH_STACK_H__
#define __ROOTISH_STACK_H__

#include <stdint.h>

typedef struct ListNode_struct {
  uint64_t* pos;
  struct ListNode_struct* prev;
  uint64_t size;
  uint64_t capacity;
} ListNode;

typedef struct {
  ListNode* last;
  uint64_t size;
} RootishStack;

int create_rootish_stack(RootishStack** rs);

int push_rootish_stack(RootishStack* rs, uint64_t pos);

int pop_rootish_stack(RootishStack* rs, uint64_t* pos);

int size_rootish_stack(RootishStack* rs);

int cleanup_rootish_stack(RootishStack** rsp);

#endif
