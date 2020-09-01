#include "fusefilter.h"
#include "xorfilter.h"
#include <assert.h>
#include <inttypes.h>

using namespace xorfilter;

bool testPopulate(BaseXorFilter &filter, uint64_t *big_set, uint64_t size) {
  // Populate the filter
  if (!filter.populate(big_set, size)) {
    printf("populate failed\n");
    return false;
  }

  // Test for true positives
  for (uint64_t i = 0; i < size; i++) {
    if (!filter.contain(big_set[i])) {
      printf("expected value not found\n");
      return false;
    }
  }

  return true;
}

bool testPopulate(BaseXorFilter &filter, std::vector<uint64_t> &big_set) {
  // Populate the filter
  if (!filter.populate(big_set)) {
    printf("populate failed\n");
    return false;
  }

  // Test for true positives
  for (auto &key : big_set) {
    if (!filter.contain(key)) {
      printf("expected value not found\n");
      return false;
    }
  }

  return true;
}

bool testPopulateBuffered(BaseXorFilter &filter, uint64_t *big_set, uint64_t size) {
  // Populate the filter
  if (!filter.populateBuffered(big_set, size)) {
    printf("populate failed\n");
    return false;
  }

  // Test for true positives
  for (uint64_t i = 0; i < size; i++) {
    if (!filter.contain(big_set[i])) {
      printf("expected value not found\n");
      return false;
    }
  }

  return true;
}

bool testPopulateBuffered(BaseXorFilter &filter, std::vector<uint64_t> &big_set) {
  // Populate the filter
  if (!filter.populateBuffered(big_set)) {
    printf("populate failed\n");
    return false;
  }

  // Test for true positives
  for (auto &key : big_set) {
    if (!filter.contain(key)) {
      printf("expected value not found\n");
      return false;
    }
  }

  return true;
}

bool testContain(BaseXorFilter &filter, uint64_t size, size_t multiplier, uint64_t &falsePositives, double &falsePositiveProbability) {
  falsePositives = 0;
  falsePositiveProbability = 0.0;
  uint64_t trials = multiplier * size;
  for (uint64_t i = size; i < trials + size; i++) {
    if (filter.contain(i)) {
      falsePositives++;
    }
  }
  falsePositiveProbability = falsePositives * 1.0 / trials;
  printf("%" PRId64 " false positives in %" PRId64 " trials, fpp %3.10f (estimated) \n",
         falsePositives, trials, falsePositives * 1.0 / trials);
  return true;
}

uint64_t *createBigSet(uint64_t size) {
  // allocate the set
  uint64_t *big_set = (uint64_t *)malloc(sizeof(uint64_t) * size);
  if (!big_set) {
    return NULL;
  }

  // Fill in the set
  for (uint64_t i = 0; i < size; i++) {
    big_set[i] = i; // we use contiguous values
  }

  return big_set;
}

bool createBigSet(uint64_t size, std::vector<uint64_t> &big_set) {
  // Fill in the set
  big_set.clear();
  for (uint64_t i = 0; i < size; i++) {
    big_set.push_back(i); // we use contiguous values
  }

  return big_set.size() == size;
}

bool testxor8(bool use_array = true) {
  printf("\ntesting xor8\n");

  uint64_t size = 10000;

  // create the filter
  XorFilter<uint8_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }

  // test populate
  if (use_array) {
    // we need some set of values
    uint64_t *big_set = createBigSet(size);
    if (!big_set) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulate(filter, big_set, size)) {
      free(big_set);
      return false;
    }
    free(big_set);
  } else {
    // we need some set of values
    std::vector<uint64_t> big_set;
    if (!createBigSet(size, big_set)) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulate(filter, big_set)) {
      return false;
    }
  }

  // test contain
  uint64_t falsePositives;
  double falsePositiveProbability;
  if (!testContain(filter, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }

  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
  return true;
}

bool testbufferedxor8(bool use_array = true) {
  printf("\ntesting buffered xor8\n");

  uint64_t size = 10000;

  // create the filter
  XorFilter<uint8_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }

  // test populate
  if (use_array) {
    // we need some set of values
    uint64_t *big_set = createBigSet(size);
    if (!big_set) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulateBuffered(filter, big_set, size)) {
      free(big_set);
      return false;
    }
    free(big_set);
  } else {
    // we need some set of values
    std::vector<uint64_t> big_set;
    if (!createBigSet(size, big_set)) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulateBuffered(filter, big_set)) {
      return false;
    }
  }

  // test contain
  uint64_t falsePositives;
  double falsePositiveProbability;
  if (!testContain(filter, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }

  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
  return true;
}

bool testxor16(bool use_array = true) {
  printf("\ntesting xor16\n");

  uint64_t size = 10000;

  // create the filter
  XorFilter<uint16_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }

  // test populate
  if (use_array) {
    // we need some set of values
    uint64_t *big_set = createBigSet(size);
    if (!big_set) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulate(filter, big_set, size)) {
      free(big_set);
      return false;
    }
    free(big_set);
  } else {
    // we need some set of values
    std::vector<uint64_t> big_set;
    if (!createBigSet(size, big_set)) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulate(filter, big_set)) {
      return false;
    }
  }

  // test contain
  uint64_t falsePositives;
  double falsePositiveProbability;
  if (!testContain(filter, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }

  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
  return true;
}


bool testbufferedxor16(bool use_array = true) {
  printf("\ntesting buffered xor16\n");

  uint64_t size = 10000;

  // create the filter
  XorFilter<uint16_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }

  // test populate
  if (use_array) {
    // we need some set of values
    uint64_t *big_set = createBigSet(size);
    if (!big_set) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulateBuffered(filter, big_set, size)) {
      free(big_set);
      return false;
    }
    free(big_set);
  } else {
    // we need some set of values
    std::vector<uint64_t> big_set;
    if (!createBigSet(size, big_set)) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulateBuffered(filter, big_set)) {
      return false;
    }
  }

  // test contain
  uint64_t falsePositives;
  double falsePositiveProbability;
  if (!testContain(filter, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }

  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
  return true;
}

bool testxor32(bool use_array = true) {
  printf("\ntesting xor32\n");

  uint64_t size = 10000;

  // create the filter
  XorFilter<uint32_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }

  // test populate
  if (use_array) {
    // we need some set of values
    uint64_t *big_set = createBigSet(size);
    if (!big_set) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulate(filter, big_set, size)) {
      free(big_set);
      return false;
    }
    free(big_set);
  } else {
    // we need some set of values
    std::vector<uint64_t> big_set;
    if (!createBigSet(size, big_set)) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulate(filter, big_set)) {
      return false;
    }
  }

  // test contain
  uint64_t falsePositives;
  double falsePositiveProbability;
  if (!testContain(filter, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }

  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
  return true;
}

bool testbufferedxor32(bool use_array = true) {
  printf("\ntesting buffered xor32\n");

  uint64_t size = 10000;

  // create the filter
  XorFilter<uint32_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }

  // test populate
  if (use_array) {
    // we need some set of values
    uint64_t *big_set = createBigSet(size);
    if (!big_set) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulateBuffered(filter, big_set, size)) {
      free(big_set);
      return false;
    }
    free(big_set);
  } else {
    // we need some set of values
    std::vector<uint64_t> big_set;
    if (!createBigSet(size, big_set)) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulateBuffered(filter, big_set)) {
      return false;
    }
  }

  // test contain
  uint64_t falsePositives;
  double falsePositiveProbability;
  if (!testContain(filter, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }

  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
  return true;
}

bool testbufferedxor32big(bool use_array = true) {
  printf("\ntesting buffered xor32 (big - this will take a long time)\n");

  uint64_t size = 100000000;

  // create the filter
  XorFilter<uint32_t> filter(size);
  if (!filter.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }

  // test populate
  if (use_array) {
    // we need some set of values
    uint64_t *big_set = createBigSet(size);
    if (!big_set) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulateBuffered(filter, big_set, size)) {
      free(big_set);
      return false;
    }
    free(big_set);
  } else {
    // we need some set of values
    std::vector<uint64_t> big_set;
    if (!createBigSet(size, big_set)) {
      printf("failed to create big set\n");
      return false;
    }
    if (!testPopulateBuffered(filter, big_set)) {
      return false;
    }
  }

  // test contain
  uint64_t falsePositives;
  double falsePositiveProbability;
  if (!testContain(filter, size, 100, falsePositives, falsePositiveProbability)) {
    return false;
  }

  printf("bits per entry %3.1f\n", filter.sizeInBytes() * 8.0 / size);
  return true;
}

bool testLoadWithData() {
  printf("\ntesting load with data\n");

  uint64_t size = 10000;

  // we need some set of values
  uint64_t *big_set = createBigSet(size);
  if (!big_set) {
    printf("failed to create big set\n");
    return false;
  }


  // construct and populate the 8-bit filter
  XorFilter<uint8_t> filter8_1(size);
  if (!filter8_1.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  // test populate
  if (!testPopulate(filter8_1, big_set, size)) {
    return false;
  }
  // test contain
  uint64_t falsePositives;
  double falsePositiveProbability;
  if (!testContain(filter8_1, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }

  // load the filter data into a new filter
  XorFilter<uint8_t> filter8_2(filter8_1.data(), filter8_1.sizeInBytes(),
                               filter8_1.bitsPerKey(), filter8_1.keyCount(),
                               filter8_1.blockLength(), filter8_1.seed());
  if (!filter8_2.valid()) {
    printf("failed to load filter\n");
    return false;
  }
  // test contain
  if (!testContain(filter8_2, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }


  // construct and populate the 16-bit filter
  XorFilter<uint16_t> filter16_1(size);
  if (!filter16_1.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  // test populate
  if (!testPopulate(filter16_1, big_set, size)) {
    return false;
  }
  // test contain
  if (!testContain(filter16_1, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }

  // load the filter data into a new filter
  XorFilter<uint16_t> filter16_2(filter16_1.data(), filter16_1.sizeInBytes(),
                                 filter16_1.bitsPerKey(), filter16_1.keyCount(),
                                 filter16_1.blockLength(), filter16_1.seed());
  if (!filter16_2.valid()) {
    printf("failed to load filter\n");
    return false;
  }
  // test contain
  if (!testContain(filter16_2, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }


  // construct and populate the 32-bit filter
  XorFilter<uint32_t> filter32_1(size);
  if (!filter32_1.valid()) {
    printf("failed to allocate filter\n");
    return false;
  }
  // test populate
  if (!testPopulate(filter32_1, big_set, size)) {
    return false;
  }
  // test contain
  if (!testContain(filter32_1, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }

  // load the filter data into a new filter
  XorFilter<uint32_t> filter32_2(filter32_1.data(), filter32_1.sizeInBytes(),
                                 filter32_1.bitsPerKey(), filter32_1.keyCount(),
                                 filter32_1.blockLength(), filter32_1.seed());
  if (!filter32_2.valid()) {
    printf("failed to load filter\n");
    return false;
  }
  // test contain
  if (!testContain(filter32_2, size, 1000, falsePositives, falsePositiveProbability)) {
    return false;
  }


  printf("load data tests succeeded\n");
  return true;
}

bool testfuse8() {
  printf("\ntesting fuse8\n");

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
  // Set to true to test with uint64_t *arrays,
  // and false to test with std::vector<uint64_t>
  bool use_array = false;
  testfuse8();
  testbufferedxor8(use_array);
  testbufferedxor16(use_array);
  testbufferedxor32(use_array);
  testxor8(use_array);
  testxor16(use_array);
  testxor32(use_array);
  testLoadWithData();
  // Uncomment to run large test that should result in some
  // false positives at 32 bits
  //testbufferedxor32big(use_array);
}
