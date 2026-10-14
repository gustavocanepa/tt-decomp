/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Obj { char pad[4]; void *model; char pad2[0x78-8]; void *bill; };
extern "C" void func_00418FD0(void *);
extern "C" void BillboardSet__end(void *);
extern "C" void BillboardSet__render(void *,int);
extern "C" void BillboardSet__render_2(void *);
extern "C" void ModelSet2__begin(void *,void *);
extern "C" void ModelSet2__end(void *);
extern "C" void ModelSet2__render(void *);
extern "C" void ModelSet2___render(void *,int,void *);
extern "C" void CourseData__render_course_2(Obj *p,u16 *list,int flags) {
 if(list) {
  int n=*list++;
  if(p->model) {
   ModelSet2__begin(p->model,0);
   if(n) { u16 *it=list; int remaining=n;
   while(remaining) { ModelSet2___render(p->model,*it++,0); remaining--; } }
   ModelSet2__end(p->model);
  }
  if(p->bill && (flags&1)) {
   func_00418FD0(p->bill);
   for(int j=0;j<n;j++) { BillboardSet__render(p->bill,list[j]); }
   return BillboardSet__end(p->bill);
  }
 } else {
  if(p->model) ModelSet2__render(p->model);
  if(p->bill) BillboardSet__render_2(p->bill);
 }
}
