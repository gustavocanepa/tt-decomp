/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Val;
struct Str { char *p; };
struct Entry { int type,v,x; };
struct Stack { Entry entries[8]; int top; };
struct Obj { char pad[0x14]; void *node; };
extern "C" int func_0043D3B8(Val *, const Val *);
extern "C" void *func_0043D3E0(Val *, const Val *) throw();
extern "C" void func_0043D510(Val *);
struct Val {
 int type,v;
 Val() { type=1; }
 Val(const Val &o) { func_0043D3B8(this,&o); }
 ~Val() { func_0043D510(this); }
 Val &operator=(const Val &o) { func_0043D3E0(this,&o); return *this; }
 int valid() const { return type ^ 1; }
};
extern "C" Val func_0043D2E8(Str *, char *) throw();
extern "C" Val func_0043E148(void *, Str *);
extern "C" Val func_00442440(void *, Str *) throw();
extern "C" Val func_004476D0(void *, Str *) throw();
extern "C" Val *func_00447FB0(void *, Str *) throw();
static inline Stack *active(Stack *s) { if (s->top < 0) return 0; return s; }
static inline Val lookup(Stack *stack, Str *name) {
 Val result;
 for (int i=stack->top; i>=0; --i) {
  { Val tmp=func_0043E148(&stack->entries[i],name); result=tmp; }
  if (result.valid()) return result;
 }
 return result;
}
extern "C" Val func_0044B2B0(Obj *self, Str *name, void *table, Stack *stack, char *base) {
 if (active(stack)) {
  Val result=lookup(stack,name);
  if (result.valid()) return result;
 }
 Val *found=func_00447FB0(table,name);
 if (found) return *found;
 Val result;
 result=func_00442440(self->node,name);
 if (result.valid()) return result;
 result=func_004476D0(self->node,name);
 if (result.valid()) return result;
 return func_0043D2E8(name,base);
}
