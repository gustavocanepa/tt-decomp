/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Expat 1.95.7, Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd. MIT license, see THIRD_PARTY.md. */
#define NULL 0
#define ASCII_a 97
#define ASCII_z 122
#define ASCII_A 65
#define ASCII_Z 90
typedef struct encoding ENCODING;
struct encoding {
 char pad[0x1c];
 int (*nameMatchesAscii)(const ENCODING *, const char *, const char *, const char *);
 char pad20[0x24];
 int minBytesPerChar;
};
int func_004A2C28(const ENCODING *,const char *,const char *);
int func_004A2C70(int) __attribute__((const));
int func_004A2CC0(const ENCODING *,const char *,const char *,const char **,const char **,const char **,const char **);
extern const char D_0060BDD8[], D_0060BDE0[], D_0060BDF0[], D_0060BE00[], D_0060BE08[];
#define KW_version D_0060BDD8
#define KW_encoding D_0060BDE0
#define KW_standalone D_0060BDF0
#define KW_yes D_0060BE00
#define KW_no D_0060BE08
#define XmlNameMatchesAscii(enc,name,end,kw) ((enc)->nameMatchesAscii(enc,name,end,kw))
#define parsePseudoAttribute func_004A2CC0
#define toAscii func_004A2C28
#define isSpace func_004A2C70
int
func_004A2F20(const ENCODING *(*encodingFinder)(const ENCODING *,
                                                 const char *,
                                                 const char *),
               int isGeneralTextEntity,
               const ENCODING *enc,
               const char *ptr,
               const char *end,
               const char **badPtr,
               const char **versionPtr,
               const char **versionEndPtr,
               const char **encodingName,
               const ENCODING **encoding,
               int *standalone)
{
  const char *val = NULL;
  const char *name = NULL;
  const char *nameEnd = NULL;
  ptr += 5 * enc->minBytesPerChar;
  end -= 2 * enc->minBytesPerChar;
  if (!parsePseudoAttribute(enc, ptr, end, &name, &nameEnd, &val, &ptr)
      || !name) {
    *badPtr = ptr;
    return 0;
  }
  if (!XmlNameMatchesAscii(enc, name, nameEnd, KW_version)) {
    if (!isGeneralTextEntity) {
      *badPtr = name;
      return 0;
    }
  }
  else {
    if (versionPtr)
      *versionPtr = val;
    if (versionEndPtr)
      *versionEndPtr = ptr;
    if (!parsePseudoAttribute(enc, ptr, end, &name, &nameEnd, &val, &ptr)) {
      *badPtr = ptr;
      return 0;
    }
    if (!name) {
      if (isGeneralTextEntity) {
        /* a TextDecl must have an EncodingDecl */
        *badPtr = ptr;
        return 0;
      }
      return 1;
    }
  }
  if (XmlNameMatchesAscii(enc, name, nameEnd, KW_encoding)) {
    int c = toAscii(enc, val, end);
    if (!(ASCII_a <= c && c <= ASCII_z) && !(ASCII_A <= c && c <= ASCII_Z)) {
      *badPtr = val;
      return 0;
    }
    if (encodingName)
      *encodingName = val;
    if (encoding)
      *encoding = encodingFinder(enc, val, ptr - enc->minBytesPerChar);
    if (!parsePseudoAttribute(enc, ptr, end, &name, &nameEnd, &val, &ptr)) {
      *badPtr = ptr;
      return 0;
    }
    if (!name)
      return 1;
  }
  if (!XmlNameMatchesAscii(enc, name, nameEnd, KW_standalone)
      || isGeneralTextEntity) {
    *badPtr = name;
    return 0;
  }
  if (XmlNameMatchesAscii(enc, val, ptr - enc->minBytesPerChar, KW_yes)) {
    if (standalone)
      *standalone = 1;
  }
  else if (XmlNameMatchesAscii(enc, val, ptr - enc->minBytesPerChar, KW_no)) {
    if (standalone)
      *standalone = 0;
  }
  else {
    *badPtr = val;
    return 0;
  }
  while (isSpace(toAscii(enc, ptr, end)))
    ptr += enc->minBytesPerChar;
  if (ptr != end) {
    *badPtr = ptr;
    return 0;
  }
  return 1;
}
