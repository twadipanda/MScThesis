


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::done_2_closure : public SDAG::Closure {
      

      done_2_closure() {
        init();
      }
      done_2_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~done_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(done_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::finished_3_closure : public SDAG::Closure {
            std::vector<double> impl_noname_0;
            int impl_noname_1;


      finished_3_closure() {
        init();
      }
      finished_3_closure(CkMigrateMessage*) {
        init();
      }
            std::vector<double> & getP0() { return impl_noname_0;}
            int & getP1() { return impl_noname_1;}
      void pup(PUP::er& __p) {
        __p | impl_noname_0;
        __p | impl_noname_1;
        packClosure(__p);
      }
      virtual ~finished_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(finished_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: readonly CProxy_Main mainProxy;
 */
extern CProxy_Main mainProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int numElements;
 */
extern int numElements;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_numElements(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|numElements;
}
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done();
void finished(const std::vector<double> &impl_noname_0, int impl_noname_1);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */
CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Main_CkArgMsg), CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  new (impl_obj_void) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void done();
 */
void CProxy_Main::done(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_done_void() {
  int epidx = CkRegisterEp("done()",
      reinterpret_cast<CkCallFnPtr>(_call_done_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Main::_call_done_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->done();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_Main::done_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void finished(const std::vector<double> &impl_noname_0, int impl_noname_1);
 */
void CProxy_Main::finished(const std::vector<double> &impl_noname_0, int impl_noname_1, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const std::vector<double> &impl_noname_0, int impl_noname_1
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_0;
    implP|impl_noname_1;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_0;
    implP|impl_noname_1;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_finished_marshall3(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_finished_marshall3(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_finished_marshall3(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_finished_marshall3() {
  int epidx = CkRegisterEp("finished(const std::vector<double> &impl_noname_0, int impl_noname_1)",
      reinterpret_cast<CkCallFnPtr>(_call_finished_marshall3), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_finished_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_finished_marshall3);

  return epidx;
}

void CkIndex_Main::_call_finished_marshall3(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::vector<double> &impl_noname_0, int impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::vector<double>> impl_noname_0;
  implP|impl_noname_0;
  PUP::detail::TemporaryObjectHolder<int> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->finished(std::move(impl_noname_0.t), std::move(impl_noname_1.t));
}
int CkIndex_Main::_callmarshall_finished_marshall3(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: const std::vector<double> &impl_noname_0, int impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::vector<double>> impl_noname_0;
  implP|impl_noname_0;
  PUP::detail::TemporaryObjectHolder<int> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->finished(std::move(impl_noname_0.t), std::move(impl_noname_1.t));
  return implP.size();
}
void CkIndex_Main::_marshallmessagepup_finished_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::vector<double> &impl_noname_0, int impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::vector<double>> impl_noname_0;
  implP|impl_noname_0;
  PUP::detail::TemporaryObjectHolder<int> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("impl_noname_0");
  implDestP|impl_noname_0;
  if (implDestP.hasComments()) implDestP.comment("impl_noname_1");
  implDestP|impl_noname_1;
}
PUPable_def(SINGLE_ARG(Closure_Main::finished_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void done();
  idx_done_void();

  // REG: void finished(const std::vector<double> &impl_noname_0, int impl_noname_1);
  idx_finished_marshall3();

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registermain(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  CkRegisterReadonly("mainProxy","CProxy_Main",sizeof(mainProxy),(void *) &mainProxy,__xlater_roPup_mainProxy);

  CkRegisterReadonly("numElements","int",sizeof(numElements),(void *) &numElements,__xlater_roPup_numElements);

  _registerkmeans();

/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done();
void finished(const std::vector<double> &impl_noname_0, int impl_noname_1);
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

}
extern "C" void CkRegisterMainModule(void) {
  _registermain();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Main::virtual_pup(PUP::er &p) {
    recursive_pup<Main>(dynamic_cast<Main*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
