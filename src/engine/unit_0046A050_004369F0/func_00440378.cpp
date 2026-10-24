/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cursor { char pad[6]; short index; };
struct Node { char pad[0x14]; short index; char tail[0x34-0x16]; };
struct Value { char data[0x18]; };
struct Context { char pad[0x50]; Value *values; char gap[0xC]; Node *nodes; };
struct Self { Context *context; Cursor *cursor; };
extern "C" int func_004404F8(Value *);
extern "C" int func_00440378(Self *self) {
 int index=self->cursor->index;
 Context *ctx=self->context;
 Node *node=ctx->nodes+index;
 Value *values=ctx->values;
 return func_004404F8(values+node->index);
}
