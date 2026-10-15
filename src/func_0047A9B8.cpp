struct V{short delta,pad;void(*fn)(void*,int);};struct O{V*table;};struct S{O*owner;int id,value;~S() __asm__("func_0047A9B8");static void operator delete(void*) __asm__("func_0050E1A8");};
extern "C" void func_0050E1A8(void*);
S::~S(){S*self=this;int id=self->id;if(id!=-1){O*p=self->owner;V*e=p->table+5;e->fn((char*)p+e->delta,id);}self->id=-1;self->value=0;}
