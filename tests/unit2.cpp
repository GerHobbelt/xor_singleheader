#include "fusefilter.h"
#include "xorfilter.h"
#include <assert.h>
#include <inttypes.h>


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
  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
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
  filter.populateBuffered(big_set, size);
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
  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
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
  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
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
  filter.populateBuffered(big_set, size);
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
  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
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
  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
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
  filter.populateBuffered(big_set, size);
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
  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
  free(big_set);
  return true;
}

bool testbufferedxor32big() {
  printf("testing buffered xor32 (big - this will take a long time)\n");

  size_t size = 100000000;
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
  filter.populateBuffered(big_set, size);
  for (size_t i = 0; i < size; i++) {
    if (!filter.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }
  printf("filter size in bytes: %"PRId64" bytes\n", filter.sizeInBytes());

  uint64_t random_matches = 0;
  uint64_t trials = 100;
  for (uint64_t i = size; i < (trials + 1) * size; i++) {
    if (filter.contain(i)) {
      random_matches++;
    }
  }

  printf("fpp %3.15f (estimated - %"PRId64" false positives out of %"PRId64" entries) \n",
         random_matches * 1.0 / (trials * size), random_matches, trials * size);
  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
  free(big_set);
  return true;
}

bool testLoadWithData() {
  printf("testing load with data\n");

  // we need some set of values
  size_t size = 10000;
  uint64_t *big_set = (uint64_t *)malloc(sizeof(uint64_t) * size);
  for (size_t i = 0; i < size; i++) {
    big_set[i] = i; // we use contiguous values
  }

  // construct and populate the filter
  XorFilter<uint8_t> filter8_1(size);
  if (!filter8_1.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  filter8_1.populate(big_set, size);
  // true positive tests
  for (size_t i = 0; i < size; i++) {
    if (!filter8_1.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }

  XorFilter<uint8_t> filter8_2(filter8_1.data(), filter8_1.sizeInBytes(), filter8_1.keyCount(), filter8_1.blockLength(), filter8_1.seed());
  if (!filter8_2.valid()) {
    printf("failed to load filter\n");
    return false;
  }
  // true positive tests
  for (size_t i = 0; i < size; i++) {
    if (!filter8_2.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }


  // construct and populate the filter
  XorFilter<uint16_t> filter16_1(size);
  if (!filter16_1.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  filter16_1.populate(big_set, size);
  // true positive tests
  for (size_t i = 0; i < size; i++) {
    if (!filter16_1.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }
  // load the filter data into a new filter
  XorFilter<uint16_t> filter16_2(filter16_1.data(), filter16_1.sizeInBytes(), filter16_1.keyCount(), filter16_1.blockLength(), filter16_1.seed());
  if (!filter16_2.valid()) {
    printf("failed to load filter\n");
    return false;
  }
  // true positive tests
  for (size_t i = 0; i < size; i++) {
    if (!filter16_2.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }


  // construct and populate the filter
  XorFilter<uint32_t> filter32_1(size);
  if (!filter32_1.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  filter32_1.populate(big_set, size);
  // true positive tests
  for (size_t i = 0; i < size; i++) {
    if (!filter32_1.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }
  // load the filter data into a new filter
  XorFilter<uint32_t> filter32_2(filter32_1.data(), filter32_1.sizeInBytes(), filter32_1.keyCount(), filter32_1.blockLength(), filter32_1.seed());
  if (!filter32_2.valid()) {
    printf("failed to load filter\n");
    return false;
  }
  // true positive tests
  for (size_t i = 0; i < size; i++) {
    if (!filter32_2.contain(big_set[i])) {
      printf("bug!\n");
      return false;
    }
  }


  printf("load data tests succeeded\n");
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
  testLoadWithData();
  // Uncomment to run large test that should result in some
  // false positives at 32 bits
  //testbufferedxor32big();
}
