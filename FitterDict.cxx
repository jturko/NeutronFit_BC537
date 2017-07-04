// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME FitterDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "NeutronFit_BC537.hh"
#include "Fitter.hh"
#include "vec.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *NeutronFit_BC537_Dictionary();
   static void NeutronFit_BC537_TClassManip(TClass*);
   static void *new_NeutronFit_BC537(void *p = 0);
   static void *newArray_NeutronFit_BC537(Long_t size, void *p);
   static void delete_NeutronFit_BC537(void *p);
   static void deleteArray_NeutronFit_BC537(void *p);
   static void destruct_NeutronFit_BC537(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::NeutronFit_BC537*)
   {
      ::NeutronFit_BC537 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::NeutronFit_BC537));
      static ::ROOT::TGenericClassInfo 
         instance("NeutronFit_BC537", "NeutronFit_BC537.hh", 30,
                  typeid(::NeutronFit_BC537), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &NeutronFit_BC537_Dictionary, isa_proxy, 4,
                  sizeof(::NeutronFit_BC537) );
      instance.SetNew(&new_NeutronFit_BC537);
      instance.SetNewArray(&newArray_NeutronFit_BC537);
      instance.SetDelete(&delete_NeutronFit_BC537);
      instance.SetDeleteArray(&deleteArray_NeutronFit_BC537);
      instance.SetDestructor(&destruct_NeutronFit_BC537);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::NeutronFit_BC537*)
   {
      return GenerateInitInstanceLocal((::NeutronFit_BC537*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::NeutronFit_BC537*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *NeutronFit_BC537_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::NeutronFit_BC537*)0x0)->GetClass();
      NeutronFit_BC537_TClassManip(theClass);
   return theClass;
   }

   static void NeutronFit_BC537_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *Fitter_Dictionary();
   static void Fitter_TClassManip(TClass*);
   static void *new_Fitter(void *p = 0);
   static void *newArray_Fitter(Long_t size, void *p);
   static void delete_Fitter(void *p);
   static void deleteArray_Fitter(void *p);
   static void destruct_Fitter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Fitter*)
   {
      ::Fitter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Fitter));
      static ::ROOT::TGenericClassInfo 
         instance("Fitter", "Fitter.hh", 36,
                  typeid(::Fitter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Fitter_Dictionary, isa_proxy, 4,
                  sizeof(::Fitter) );
      instance.SetNew(&new_Fitter);
      instance.SetNewArray(&newArray_Fitter);
      instance.SetDelete(&delete_Fitter);
      instance.SetDeleteArray(&deleteArray_Fitter);
      instance.SetDestructor(&destruct_Fitter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Fitter*)
   {
      return GenerateInitInstanceLocal((::Fitter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Fitter*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Fitter_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Fitter*)0x0)->GetClass();
      Fitter_TClassManip(theClass);
   return theClass;
   }

   static void Fitter_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *MT_args_Dictionary();
   static void MT_args_TClassManip(TClass*);
   static void delete_MT_args(void *p);
   static void deleteArray_MT_args(void *p);
   static void destruct_MT_args(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MT_args*)
   {
      ::MT_args *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MT_args));
      static ::ROOT::TGenericClassInfo 
         instance("MT_args", "Fitter.hh", 23,
                  typeid(::MT_args), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MT_args_Dictionary, isa_proxy, 4,
                  sizeof(::MT_args) );
      instance.SetDelete(&delete_MT_args);
      instance.SetDeleteArray(&deleteArray_MT_args);
      instance.SetDestructor(&destruct_MT_args);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MT_args*)
   {
      return GenerateInitInstanceLocal((::MT_args*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MT_args*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MT_args_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MT_args*)0x0)->GetClass();
      MT_args_TClassManip(theClass);
   return theClass;
   }

   static void MT_args_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("file_name","Fitter.hh");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *vec_Dictionary();
   static void vec_TClassManip(TClass*);
   static void *new_vec(void *p = 0);
   static void *newArray_vec(Long_t size, void *p);
   static void delete_vec(void *p);
   static void deleteArray_vec(void *p);
   static void destruct_vec(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::vec*)
   {
      ::vec *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::vec));
      static ::ROOT::TGenericClassInfo 
         instance("vec", "vec.hh", 12,
                  typeid(::vec), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vec_Dictionary, isa_proxy, 4,
                  sizeof(::vec) );
      instance.SetNew(&new_vec);
      instance.SetNewArray(&newArray_vec);
      instance.SetDelete(&delete_vec);
      instance.SetDeleteArray(&deleteArray_vec);
      instance.SetDestructor(&destruct_vec);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::vec*)
   {
      return GenerateInitInstanceLocal((::vec*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::vec*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vec_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::vec*)0x0)->GetClass();
      vec_TClassManip(theClass);
   return theClass;
   }

   static void vec_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("file_name","vec.hh");
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_NeutronFit_BC537(void *p) {
      return  p ? new(p) ::NeutronFit_BC537 : new ::NeutronFit_BC537;
   }
   static void *newArray_NeutronFit_BC537(Long_t nElements, void *p) {
      return p ? new(p) ::NeutronFit_BC537[nElements] : new ::NeutronFit_BC537[nElements];
   }
   // Wrapper around operator delete
   static void delete_NeutronFit_BC537(void *p) {
      delete ((::NeutronFit_BC537*)p);
   }
   static void deleteArray_NeutronFit_BC537(void *p) {
      delete [] ((::NeutronFit_BC537*)p);
   }
   static void destruct_NeutronFit_BC537(void *p) {
      typedef ::NeutronFit_BC537 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::NeutronFit_BC537

namespace ROOT {
   // Wrappers around operator new
   static void *new_Fitter(void *p) {
      return  p ? new(p) ::Fitter : new ::Fitter;
   }
   static void *newArray_Fitter(Long_t nElements, void *p) {
      return p ? new(p) ::Fitter[nElements] : new ::Fitter[nElements];
   }
   // Wrapper around operator delete
   static void delete_Fitter(void *p) {
      delete ((::Fitter*)p);
   }
   static void deleteArray_Fitter(void *p) {
      delete [] ((::Fitter*)p);
   }
   static void destruct_Fitter(void *p) {
      typedef ::Fitter current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Fitter

namespace ROOT {
   // Wrapper around operator delete
   static void delete_MT_args(void *p) {
      delete ((::MT_args*)p);
   }
   static void deleteArray_MT_args(void *p) {
      delete [] ((::MT_args*)p);
   }
   static void destruct_MT_args(void *p) {
      typedef ::MT_args current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MT_args

namespace ROOT {
   // Wrappers around operator new
   static void *new_vec(void *p) {
      return  p ? new(p) ::vec : new ::vec;
   }
   static void *newArray_vec(Long_t nElements, void *p) {
      return p ? new(p) ::vec[nElements] : new ::vec[nElements];
   }
   // Wrapper around operator delete
   static void delete_vec(void *p) {
      delete ((::vec*)p);
   }
   static void deleteArray_vec(void *p) {
      delete [] ((::vec*)p);
   }
   static void destruct_vec(void *p) {
      typedef ::vec current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::vec

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 214,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 214,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlETThreadmUgR_Dictionary();
   static void vectorlETThreadmUgR_TClassManip(TClass*);
   static void *new_vectorlETThreadmUgR(void *p = 0);
   static void *newArray_vectorlETThreadmUgR(Long_t size, void *p);
   static void delete_vectorlETThreadmUgR(void *p);
   static void deleteArray_vectorlETThreadmUgR(void *p);
   static void destruct_vectorlETThreadmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TThread*>*)
   {
      vector<TThread*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TThread*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TThread*>", -2, "vector", 214,
                  typeid(vector<TThread*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETThreadmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TThread*>) );
      instance.SetNew(&new_vectorlETThreadmUgR);
      instance.SetNewArray(&newArray_vectorlETThreadmUgR);
      instance.SetDelete(&delete_vectorlETThreadmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETThreadmUgR);
      instance.SetDestructor(&destruct_vectorlETThreadmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TThread*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<TThread*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETThreadmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TThread*>*)0x0)->GetClass();
      vectorlETThreadmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETThreadmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETThreadmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TThread*> : new vector<TThread*>;
   }
   static void *newArray_vectorlETThreadmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TThread*>[nElements] : new vector<TThread*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETThreadmUgR(void *p) {
      delete ((vector<TThread*>*)p);
   }
   static void deleteArray_vectorlETThreadmUgR(void *p) {
      delete [] ((vector<TThread*>*)p);
   }
   static void destruct_vectorlETThreadmUgR(void *p) {
      typedef vector<TThread*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TThread*>

namespace ROOT {
   static TClass *vectorlENeutronFit_BC537gR_Dictionary();
   static void vectorlENeutronFit_BC537gR_TClassManip(TClass*);
   static void *new_vectorlENeutronFit_BC537gR(void *p = 0);
   static void *newArray_vectorlENeutronFit_BC537gR(Long_t size, void *p);
   static void delete_vectorlENeutronFit_BC537gR(void *p);
   static void deleteArray_vectorlENeutronFit_BC537gR(void *p);
   static void destruct_vectorlENeutronFit_BC537gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<NeutronFit_BC537>*)
   {
      vector<NeutronFit_BC537> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<NeutronFit_BC537>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<NeutronFit_BC537>", -2, "vector", 214,
                  typeid(vector<NeutronFit_BC537>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlENeutronFit_BC537gR_Dictionary, isa_proxy, 0,
                  sizeof(vector<NeutronFit_BC537>) );
      instance.SetNew(&new_vectorlENeutronFit_BC537gR);
      instance.SetNewArray(&newArray_vectorlENeutronFit_BC537gR);
      instance.SetDelete(&delete_vectorlENeutronFit_BC537gR);
      instance.SetDeleteArray(&deleteArray_vectorlENeutronFit_BC537gR);
      instance.SetDestructor(&destruct_vectorlENeutronFit_BC537gR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<NeutronFit_BC537> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<NeutronFit_BC537>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlENeutronFit_BC537gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<NeutronFit_BC537>*)0x0)->GetClass();
      vectorlENeutronFit_BC537gR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlENeutronFit_BC537gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlENeutronFit_BC537gR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<NeutronFit_BC537> : new vector<NeutronFit_BC537>;
   }
   static void *newArray_vectorlENeutronFit_BC537gR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<NeutronFit_BC537>[nElements] : new vector<NeutronFit_BC537>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlENeutronFit_BC537gR(void *p) {
      delete ((vector<NeutronFit_BC537>*)p);
   }
   static void deleteArray_vectorlENeutronFit_BC537gR(void *p) {
      delete [] ((vector<NeutronFit_BC537>*)p);
   }
   static void destruct_vectorlENeutronFit_BC537gR(void *p) {
      typedef vector<NeutronFit_BC537> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<NeutronFit_BC537>

namespace {
  void TriggerDictionaryInitialization_FitterDict_Impl() {
    static const char* headers[] = {
"NeutronFit_BC537.hh",
"Fitter.hh",
"vec.hh",
0
    };
    static const char* includePaths[] = {
"/opt/cern/root/root_v6.06.04/include",
"/nessa/geant4/joey/data/smearing/deuteron/NeutronFit_BC537/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "FitterDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$NeutronFit_BC537.hh")))  NeutronFit_BC537;
class __attribute__((annotate("$clingAutoload$Fitter.hh")))  Fitter;
struct __attribute__((annotate(R"ATTRDUMP(file_name@@@Fitter.hh)ATTRDUMP"))) __attribute__((annotate(R"ATTRDUMP(pattern@@@*)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$Fitter.hh")))  MT_args;
class __attribute__((annotate(R"ATTRDUMP(file_name@@@vec.hh)ATTRDUMP"))) __attribute__((annotate(R"ATTRDUMP(pattern@@@*)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$Fitter.hh")))  vec;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "FitterDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "NeutronFit_BC537.hh"
#include "Fitter.hh"
#include "vec.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"", payloadCode, "@",
"Fitter", payloadCode, "@",
"MT_args", payloadCode, "@",
"NeutronFit_BC537", payloadCode, "@",
"vec", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("FitterDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_FitterDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_FitterDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_FitterDict() {
  TriggerDictionaryInitialization_FitterDict_Impl();
}
