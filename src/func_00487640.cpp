struct Interface{
 virtual void dummy();
 virtual int query();
 virtual int operation(int,int,int,void*);
};
struct S{Interface* interface;char pad[0x1c];int base,shift;};
union Item{struct {unsigned short flags,pad;int index,size;};Interface* pointer;int words[3];};
extern "C" int func_00487640(S* self,Item* item,void* argument){
 int position=(item->index<<self->shift)+self->base;
 int capacity=self->interface->query();
 int scaled=capacity<<self->shift;
 item->flags&=0xfffe;
 return self->interface->operation(position,item->size,scaled,argument)==0;
}
