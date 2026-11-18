/* compiler: ee-gcc2.96-no-strict-aliasing */
struct ENCODING {char pad[0x44]; int minBytesPerChar;};
extern "C" int func_004A2C28(const ENCODING *,const char *,const char *) throw();
extern "C" int func_004A2C70(int) throw() __attribute__((const));
int
func_004A2CC0(const ENCODING *enc,
                     const char *ptr,
                     const char *end,
                     const char **namePtr,
                     const char **nameEndPtr,
                     const char **valPtr,
                     const char **nextTokPtr)
{
  int c;
  char func_005AE360;
  if (ptr == end) {
    *namePtr = 0;
    return 1;
  }
  if (!func_004A2C70(func_004A2C28(enc, ptr, end))) {
    *nextTokPtr = ptr;
    return 0;
  }
  do {
    ptr += enc->minBytesPerChar;
  } while (func_004A2C70(func_004A2C28(enc, ptr, end)));
  if (ptr == end) {
    *namePtr = 0;
    return 1;
  }
  *namePtr = ptr;
  for (;;) {
    c = func_004A2C28(enc, ptr, end);
    if (c == -1) {
      *nextTokPtr = ptr;
      return 0;
    }
    if (c == 61) {
      *nameEndPtr = ptr;
      break;
    }
    if (func_004A2C70(c)) {
      *nameEndPtr = ptr;
      do {
        ptr += enc->minBytesPerChar;
      } while (func_004A2C70(c = func_004A2C28(enc, ptr, end)));
      if (c != 61) {
        *nextTokPtr = ptr;
        return 0;
      }
      break;
    }
    ptr += enc->minBytesPerChar;
  }
  if (ptr == *namePtr) {
    *nextTokPtr = ptr;
    return 0;
  }
  ptr += enc->minBytesPerChar;
  c = func_004A2C28(enc, ptr, end);
  while (func_004A2C70(c)) {
    ptr += enc->minBytesPerChar;
    c = func_004A2C28(enc, ptr, end);
  }
  if (c != 34 && c != 39) {
    *nextTokPtr = ptr;
    return 0;
  }
  func_005AE360 = (char)c;
  ptr += enc->minBytesPerChar;
  *valPtr = ptr;
  for (;; ptr += enc->minBytesPerChar) {
    c = func_004A2C28(enc, ptr, end);
    if (c == func_005AE360)
      break;
    if (!(97 <= c && c <= 122)
        && !(65 <= c && c <= 90)
        && !(48 <= c && c <= 57)
        && c != 46
        && c != 45
        && c != 95) {
      *nextTokPtr = ptr;
      return 0;
    }
  }
  *nextTokPtr = ptr + enc->minBytesPerChar;
  return 1;
}
