#include <stdio.h>

#include "rootish_stack.h"

int main(void) {
  RootishStack* rs;
  create_rootish_stack(&rs);
  push_rootish_stack(rs, 42);
  push_rootish_stack(rs, 69);
  push_rootish_stack(rs, 0xDEADBEEF);
  while(0 < size_rootish_stack(rs)) {
    uint64_t temp;
    pop_rootish_stack(rs, &temp);
    printf("Popped: %llu\n", temp);
  }
  return 0;
}
