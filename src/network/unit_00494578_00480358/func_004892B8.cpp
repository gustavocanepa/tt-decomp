/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cursor { int key, x; unsigned block, pos; };
struct State { char pad[0x10]; unsigned total; Cursor cur; };
struct Buf { char pad[8]; char *data; };
struct Stream { char pad[4]; void *list; char pad8[0x48]; unsigned size; };
extern "C" int func_00488918(Stream *, int) throw();
extern "C" Buf *func_00487850(void *, unsigned) throw();
extern "C" void func_00487968(void *, Buf *) throw();
extern "C" void func_00487A00(void *, Buf *) throw();
extern "C" int func_004889F8(Stream *, Cursor *, unsigned) throw();
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" long func_004892B8(Stream *s, State *st, void *data, unsigned count, int mode) {
 Cursor *c = &st->cur;
 int key = func_00488918(s, c->key);
 key += c->block;
 unsigned size = s->size;
 unsigned n = size - c->pos;
 if (count < n) n = count;
 Buf *b = func_00487850(s->list, key);
 if (!b) return -5;
 {
  if (mode) {
   func_004F64C4(data, b->data + c->pos, n);
   func_00487968(s->list,b);
  } else {
   func_004F64C4(b->data+c->pos,data,n);
   func_00487A00(s->list,b);
  }
  int v = func_004889F8(s,c,n);
  if(v<0) return v;
  st->total += n;
 }
 return n;
}
