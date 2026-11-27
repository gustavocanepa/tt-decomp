/* compiler: ee-gcc2.9-991111 */
struct Blk { struct Blk *next; unsigned used:1; unsigned key:31; unsigned flag:1; unsigned size:31; };
extern struct { char pad[12]; char *head; int count; } D_0077A008;
#define INSERT() { while ((int)carry.size > 0) { old = *p; *p = carry; p->next = old.next; carry = old; p = p->next; } }
#define PREFIX() { if (p->key < key) { unsigned size; D_0077A008.count++; size = p->key + p->size - key; p->size -= size; carry.key = p->key + p->size; carry.size = size; carry.used = 0; carry.flag = 0; p = p->next; found = p; INSERT(); p = found; } }
#define ALLOC() { if (p->size == size) { p->used = 1; return p->key << 8; } D_0077A008.count++; result = p->key << 8; carry = *p; p->used = 1; p->size = size; carry.key += size; carry.size -= size; p = p->next; break; }
unsigned func_004D3170(unsigned mode, unsigned bytes, unsigned arg) {
 struct Blk *p, *found; struct Blk carry, old; unsigned size = (bytes + 255) >> 8; unsigned key, align, result;
 if (size == 0) return 0;
 switch (mode) {
 case 0:
  for (p = (struct Blk *)(D_0077A008.head + 4); p; p = p->next) { if (!p->used && p->size >= size) break; }
  if (p) ALLOC();
  return 0;
 case 1:
  found = 0;
  for (p = (struct Blk *)(D_0077A008.head + 4); p; p = p->next) { if (!p->used && p->size >= size) found = p; }
  p = found; if (!p) return 0;
  if (p->size == size) { p->used = 1; return p->key << 8; }
  D_0077A008.count++; p->size -= size; carry.key = p->key + p->size; carry.size = size; carry.used = 1; result = carry.key << 8; p = p->next; break;
 case 2:
  if (arg & 255) return 0;
  key = arg >> 8;
  for (p = (struct Blk *)(D_0077A008.head + 4); ; p = p->next) { if (!p || p->key > key) return 0; if (p->used) continue; if (p->key + p->size >= key + size) break; }
  PREFIX(); ALLOC();
 case 4:
  if (arg & (arg - 1)) return 0;
  align = arg < 256 ? 1 : arg >> 8;
  for (p = (struct Blk *)(D_0077A008.head + 4); p; p = p->next) { if (p->used) continue; key = (p->key + align - 1) & -align; if (p->size - (key - p->key) >= size) break; }
  if (p) { if (p->key == key && p->size == size) { p->used = 1; return p->key << 8; } PREFIX(); ALLOC(); }
  return 0;
 case 5:
  found = 0;
  if (arg & (arg - 1)) return 0;
  align = arg < 256 ? 1 : arg >> 8; key = 0;
  for (p = (struct Blk *)(D_0077A008.head + 4); p; p = p->next) { if (p->used) continue; key = (p->key + align - 1) & -align; if (p->size - (key - p->key) >= size) { found = p; break; } }
  p = found; if (!p) return 0;
  if (p->key == key && p->size == size) { p->used = 1; return p->key << 8; }
  { if (p->key < key) { unsigned size; D_0077A008.count++; size = found->key + found->size - key; found->size -= size; carry.key = found->key + found->size; carry.size = size; carry.used = 0; carry.flag = 0; p = found->next; found = p; INSERT(); p = found; } } { if (found->size == size) { found->used = 1; return found->key << 8; } D_0077A008.count++; result = found->key << 8; carry = *p; found->used = 1; found->size = size; carry.key += size; carry.size -= size; p = found->next; break; }
 default: return 0;
 }
 INSERT(); return result;
}
