#include <stdio.h>
#include <assert.h>
#include <stdint.h>

#include "../src/rootish_stack.h"

int main(void) {
  uint64_t test_ints[4] = { 42, 8, 69, 0xDEADBEEF };
  size_t nints = (sizeof(test_ints) / sizeof(test_ints[0]));

  fputs("Testing rootish_stack...", stdout);
  RootishStack* rs;
  create_rootish_stack(&rs);
  for(size_t i = 0; i < nints; ++i) {
    push_rootish_stack(rs, test_ints[i]);
  }
  for(int i = nints - 1; i >= 0; --i) {
    uint64_t temp;
    pop_rootish_stack(rs, &temp);
    assert(temp == test_ints[i]);
  }
  cleanup_rootish_stack(&rs);
  puts("done.\n");
  return 0;
}
