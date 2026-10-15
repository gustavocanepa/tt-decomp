/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
struct Block { int a,b,c,d; };
struct __attribute__((packed)) Header { char pad[28]; unsigned size; };
struct Data { int active; void *buf; Header *payload; int file; unsigned pos; Block block; };
struct Value { const unsigned first; Data *second; };
struct NodeBase { int color; NodeBase *parent,*left,*right; };
struct Node : NodeBase { Value value; };
struct IteratorBase { NodeBase *node; };
template <class Ref,class Ptr> struct Iter : IteratorBase {
 typedef Iter<Value&,Value*> iterator;
 Iter() {}
 Iter(Node *p) { node=p; }
 Iter(const iterator &it) { node=it.node; }
 Ref operator*() const { return ((Node*)node)->value; }
 Ptr operator->() const { return &(operator*()); }
};
inline bool operator==(const IteratorBase &a,const IteratorBase &b) { return a.node==b.node; }
struct Tree;
extern "C" Iter<Value&,Value*> func_0056FA40(Tree*,const unsigned&);
struct Tree {
 int allocator; Node *header; unsigned count; int compare;
 typedef Iter<Value&,Value*> iterator;
 iterator find(const unsigned &key) { return func_0056FA40(this,key); }
 iterator end() { return header; }
};
struct Map {
 Tree t;
 typedef Iter<Value&,Value*> iterator;
 typedef Iter<const Value&,const Value*> const_iterator;
 iterator find(const unsigned &key) { return t.find(key); }
 iterator end() { return t.end(); }
};
extern "C" int func_00488A60(void*,int,unsigned,Block*) throw();
extern "C" void func_004A4D68(void*);
extern "C" void func_004A4DD8(void*);
struct Guard {
 void *p;
 Guard(void *v):p(v) {func_004A4D68(p);}
 ~Guard() {func_004A4DD8(p);}
};
struct Owner { void *vtable; void *list; Map map; int unused; char mutex[48]; };
extern "C" long func_0048A148(Owner *s,int key,long offset,int whence) {
 Guard guard(s->mutex);
 Map::const_iterator it=s->map.find(key);
 if(it==s->map.end()) return -9;
 Data *data=it->second;
 unsigned size=data->payload->size;
 unsigned base;
 switch(whence) {
 case 0: base=0; break;
 case 1: base=data->pos; break;
 case 2: base=size; break;
 default: return -22;
 }
 unsigned pos=base+(int)offset;
 if((offset<0 && base<pos) || (offset>0 && pos<base) || size<pos) return -22;
 Block block;
 int r=func_00488A60(s,data->file,pos,&block);
 if(r<0) return r;
 data->pos=pos;
 data->block=block;
 return pos;
}
