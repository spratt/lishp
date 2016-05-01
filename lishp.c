#include <stdlib.h>
#include <stdio.h>

#include "rootish_stack.h"

int main(void) {
  RootishStack* rs;
  create_rootish_stack(&rs);
  push_rootish_stack(rs, 42);
  push_rootish_stack(rs, 69);
  push_rootish_stack(rs, 0xDEADBEEF);
  uint64_t* temp = malloc(sizeof(uint64_t));
  while(0 < size_rootish_stack(rs)) {
    pop_rootish_stack(rs, temp);
    printf("Popped: %llu\n", *temp);
  }
  return 0;
}
