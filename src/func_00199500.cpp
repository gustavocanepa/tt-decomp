// In-place partition sort of owning object pointers. Physical partial views.
// 001D2EA8 appends at most400 entries at34, then count is at674.
// Original helper typedef is unrecovered; reconstructed void agrees with
// in-place ownership protocol and the result-register/caller audit.
typedef unsigned long long Key;
struct Object;
struct Entry {short delta,index;void(*destroy)(void*,int);};
struct Object {char unknown[0x4c];Entry*table;};
struct Owner {
 Object*p;
 Owner(Owner&r):p(r.p){r.p=0;}
 Owner&operator=(Owner&r){if(&r!=this){reset();Object*q=r.p;r.p=0;p=q;}return *this;}
 ~Owner(){reset();}
 void reset(){if(p){Entry*e=p->table+1;e->destroy((char*)p+e->delta,3);}}
};
struct Collection {char unknown[0x34];Owner items[400];};
extern "C" Key func_00199468(Owner*);
extern "C" void func_00199500(Collection*self,int low,int high){
 if(high<0||high<low)return;
 int i=low,j=high;
 Key pivot=func_00199468(&self->items[(low+high)>>1]);
 Owner*right=(Owner*)((unsigned)(high*4)+(unsigned)self+0x34);
 do {
  while(func_00199468(&self->items[i])>pivot)++i;
  while(func_00199468(&self->items[j])<pivot){--right;--j;}
  if(i>=j)break;
  {Owner tmp(self->items[i]);self->items[i]=*right;*right=tmp;
  ++i;--right;--j;}
 }while(1);
 if(low<i-1)func_00199500(self,low,i-1);
 if(j+1<high)func_00199500(self,j+1,high);
}
