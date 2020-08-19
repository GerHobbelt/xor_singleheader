#include "fusefilter.h"
#include "xorfilter.h"
#include <assert.h>


bool testxor8() {
  printf("testing xor8\n");

  size_t size = 10000;
  XorFilter<uint8_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  // we need some set of values
  uint64_t *big_set = (uint64_t *)malloc(sizeof(uint64_t) * size);
  for (size_t i = 0; i < size; i++) {
    big_set[i] = i; // we use contiguous values
  }
  // we construct the filter
  filter.populate(big_set, size);
  for (size_t i = 0; i < size; i++) {
    if (!filter.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }

  size_t random_matches = 0;
  size_t trials = 10000000; //(uint64_t)rand() << 32 + rand()
  for (size_t i = 0; i < trials; i++) {
    uint64_t random_key = ((uint64_t)rand() << 32) + rand();
    if (filter.contain(random_key)) {
      if (random_key >= size) {
        random_matches++;
      }
    }
  }
  printf("fpp %3.10f (estimated) \n", random_matches * 1.0 / trials);
  printf("bits per entry %3.1f\n", filter.size_in_bytes() * 8.0 / size);
  free(big_set);
  return true;
}

bool testbufferedxor8() {
  printf("testing buffered xor8\n");

  size_t size = 10000;
  XorFilter<uint8_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  // we need some set of values
  uint64_t *big_set = (uint64_t *)malloc(sizeof(uint64_t) * size);
  for (size_t i = 0; i < size; i++) {
    big_set[i] = i; // we use contiguous values
  }
  // we construct the filter
  filter.buffered_populate(big_set, size);
  for (size_t i = 0; i < size; i++) {
    if (!filter.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }

  size_t random_matches = 0;
  size_t trials = 10000000; //(uint64_t)rand() << 32 + rand()
  for (size_t i = 0; i < trials; i++) {
    uint64_t random_key = ((uint64_t)rand() << 32) + rand();
    if (filter.contain(random_key)) {
      if (random_key >= size) {
        random_matches++;
      }
    }
  }
  printf("fpp %3.10f (estimated) \n", random_matches * 1.0 / trials);
  printf("bits per entry %3.1f\n", filter.size_in_bytes() * 8.0 / size);
  free(big_set);
  return true;
}

bool testxor16() {
  printf("testing xor16\n");

  size_t size = 10000;
  XorFilter<uint16_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  // we need some set of values
  uint64_t *big_set = (uint64_t *)malloc(sizeof(uint64_t) * size);
  for (size_t i = 0; i < size; i++) {
    big_set[i] = i; // we use contiguous values
  }
  // we construct the filter
  filter.populate(big_set, size);
  for (size_t i = 0; i < size; i++) {
    if (!filter.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }

  size_t random_matches = 0;
  size_t trials = 10000000; //(uint64_t)rand() << 32 + rand()
  for (size_t i = 0; i < trials; i++) {
    uint64_t random_key = ((uint64_t)rand() << 32) + rand();
    if (filter.contain(random_key)) {
      if (random_key >= size) {
        random_matches++;
      }
    }
  }
  printf("fpp %3.10f (estimated) \n", random_matches * 1.0 / trials);
  printf("bits per entry %3.1f\n", filter.size_in_bytes() * 8.0 / size);
  free(big_set);
  return true;
}


bool testbufferedxor16() {
  printf("testing buffered xor16\n");

  size_t size = 10000;
  XorFilter<uint16_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  // we need some set of values
  uint64_t *big_set = (uint64_t *)malloc(sizeof(uint64_t) * size);
  for (size_t i = 0; i < size; i++) {
    big_set[i] = i; // we use contiguous values
  }
  // we construct the filter
  filter.buffered_populate(big_set, size);
  for (size_t i = 0; i < size; i++) {
    if (!filter.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }

  size_t random_matches = 0;
  size_t trials = 10000000; //(uint64_t)rand() << 32 + rand()
  for (size_t i = 0; i < trials; i++) {
    uint64_t random_key = ((uint64_t)rand() << 32) + rand();
    if (filter.contain(random_key)) {
      if (random_key >= size) {
        random_matches++;
      }
    }
  }
  printf("fpp %3.10f (estimated) \n", random_matches * 1.0 / trials);
  printf("bits per entry %3.1f\n", filter.size_in_bytes() * 8.0 / size);
  free(big_set);
  return true;
}

bool testxor32() {
  printf("testing xor32\n");

  size_t size = 10000;
  XorFilter<uint32_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  // we need some set of values
  uint64_t *big_set = (uint64_t *)malloc(sizeof(uint64_t) * size);
  for (size_t i = 0; i < size; i++) {
    big_set[i] = i; // we use contiguous values
  }
  // we construct the filter
  filter.populate(big_set, size);
  for (size_t i = 0; i < size; i++) {
    if (!filter.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }

  size_t random_matches = 0;
  size_t trials = 10000000; //(uint64_t)rand() << 32 + rand()
  for (size_t i = 0; i < trials; i++) {
    uint64_t random_key = ((uint64_t)rand() << 32) + rand();
    if (filter.contain(random_key)) {
      if (random_key >= size) {
        random_matches++;
      }
    }
  }
  printf("fpp %3.15f (estimated) \n", random_matches * 1.0 / trials);
  printf("bits per entry %3.1f\n", filter.size_in_bytes() * 8.0 / size);
  free(big_set);
  return true;
}

bool testbufferedxor32() {
  printf("testing buffered xor32\n");

  size_t size = 10000;
  XorFilter<uint32_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  // we need some set of values
  uint64_t *big_set = (uint64_t *)malloc(sizeof(uint64_t) * size);
  for (size_t i = 0; i < size; i++) {
    big_set[i] = i; // we use contiguous values
  }
  // we construct the filter
  filter.buffered_populate(big_set, size);
  for (size_t i = 0; i < size; i++) {
    if (!filter.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }

  size_t random_matches = 0;
  size_t trials = 10000000; //(uint64_t)rand() << 32 + rand()
  for (size_t i = 0; i < trials; i++) {
    uint64_t random_key = ((uint64_t)rand() << 32) + rand();
    if (filter.contain(random_key)) {
      if (random_key >= size) {
        random_matches++;
      }
    }
  }
  printf("fpp %3.15f (estimated) \n", random_matches * 1.0 / trials);
  printf("bits per entry %3.1f\n", filter.size_in_bytes() * 8.0 / size);
  free(big_set);
  return true;
}

bool testbufferedxor32big() {
  printf("testing buffered xor32 (big - this will take a long time)\n");

  size_t size = 60000000;
  XorFilter<uint32_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  // we need some set of values
  uint64_t *big_set = (uint64_t *)malloc(sizeof(uint64_t) * size);
  for (size_t i = 0; i < size; i++) {
    big_set[i] = i; // we use contiguous values
  }
  // we construct the filter
  filter.buffered_populate(big_set, size);
  for (size_t i = 0; i < size; i++) {
    if (!filter.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }
  printf("filter size in bytes: %llu bytes\n", filter.size_in_bytes());

  uint64_t random_matches = 0;
  uint64_t trials = 100;
  for (uint64_t i = size; i < (trials + 1) * size; i++) {
    if (filter.contain(i)) {
      random_matches++;
    }
  }

  printf("fpp %3.15f (estimated - %llu false positives out of %llu entries) \n",
         random_matches * 1.0 / (trials * size), random_matches, trials * size);
  printf("bits per entry %3.1f\n", filter.size_in_bytes() * 8.0 / size);
  free(big_set);
  return true;
}

bool testfuse8() {
  printf("testing fuse8\n");

  fuse8_t filter;
  size_t size = 1000000;
  fuse8_allocate(size, &filter);
  // we need some set of values
  uint64_t *big_set = (uint64_t *)malloc(sizeof(uint64_t) * size);
  for (size_t i = 0; i < size; i++) {
    big_set[i] = i; // we use contiguous values
  }
  // we construct the filter
  fuse8_populate(big_set, size, &filter);
  for (size_t i = 0; i < size; i++) {
    if (!fuse8_contain(big_set[i], &filter)) {
      printf("bug!\n");
      return false;
    }
  }

  size_t random_matches = 0;
  size_t trials = 10000000; //(uint64_t)rand() << 32 + rand()
  for (size_t i = 0; i < trials; i++) {
    uint64_t random_key = ((uint64_t)rand() << 32) + rand();
    if (fuse8_contain(random_key, &filter)) {
      if (random_key >= size) {
        random_matches++;
      }
    }
  }
  printf("fpp %3.10f (estimated) \n", random_matches * 1.0 / trials);
  printf("bits per entry %3.1f\n", fuse8_size_in_bytes(&filter) * 8.0 / size);
  fuse8_free(&filter);
  free(big_set);
  return true;
}

int main() {
  testfuse8();
  testbufferedxor8();
  testbufferedxor16();
  testbufferedxor32();
  testxor8();
  testxor16();
  testxor32();

  testbufferedxor32big();
}
