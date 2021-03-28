/* from: https://source.android.com/devices/tech/debug/libfuzzer?hl=ja */

#include <stdint.h>
#include <stddef.h>

int FuzzMe(const char *Data, size_t DataSize) {
    return DataSize >= 3  &&
           Data[0] == 'F' &&
           Data[1] == 'U' &&
           Data[2] == 'Z' &&
           Data[3] == 'Z';  // ← Out of bounds access
}

int LLVMFuzzerTestOneInput(const char *data, size_t size) {
  // ...
  // Use the data to call the library you are fuzzing.
  // ...
  return FuzzMe(data, size);
}
