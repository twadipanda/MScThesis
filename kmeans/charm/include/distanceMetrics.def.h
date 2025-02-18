/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_DistanceMetrics::euclideanDistance_2_closure : public SDAG::Closure {
            std::vector<double> impl_noname_0;
            std::vector<double> impl_noname_1;


      euclideanDistance_2_closure() {
        init();
      }
      euclideanDistance_2_closure(CkMigrateMessage*) {
        init();
      }
            std::vector<double> & getP0() { return impl_noname_0;}
            std::vector<double> & getP1() { return impl_noname_1;}
      void pup(PUP::er& __p) {
        __p | impl_noname_0;
        __p | impl_noname_1;
        packClosure(__p);
      }
      virtual ~euclideanDistance_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(euclideanDistance_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: array DistanceMetrics: ArrayElement{
DistanceMetrics();
void euclideanDistance(const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1);
DistanceMetrics(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_DistanceMetrics::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_DistanceMetrics::contribute(CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, userData, fragSize);
}

void CProxySection_DistanceMetrics::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

template <typename T>
void CProxySection_DistanceMetrics::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, userData, fragSize);
}

void CProxySection_DistanceMetrics::contribute(CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, cb, userData, fragSize);
}

void CProxySection_DistanceMetrics::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

template <typename T>
void CProxySection_DistanceMetrics::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: DistanceMetrics();
 */
void CProxyElement_DistanceMetrics::insert(int onPE, const CkEntryOptions *impl_e_opts)
{ 
   void *impl_msg = CkAllocSysMsg(impl_e_opts);
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_DistanceMetrics::idx_DistanceMetrics_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void euclideanDistance(const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1);
 */
void CProxyElement_DistanceMetrics::euclideanDistance(const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_0;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_1;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_0;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_1;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_DistanceMetrics::idx_euclideanDistance_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: DistanceMetrics(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: DistanceMetrics();
 */
CkArrayID CProxy_DistanceMetrics::ckNew(const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_DistanceMetrics::idx_DistanceMetrics_void(), opts);
  return gId;
}
void CProxy_DistanceMetrics::ckNew(const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_DistanceMetrics::idx_DistanceMetrics_void(), _ck_array_creation_cb, opts, impl_msg);
}
CkArrayID CProxy_DistanceMetrics::ckNew(const int s1, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_DistanceMetrics::idx_DistanceMetrics_void(), opts);
  return gId;
}
void CProxy_DistanceMetrics::ckNew(const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_DistanceMetrics::idx_DistanceMetrics_void(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function
int CkIndex_DistanceMetrics::reg_DistanceMetrics_void() {
  int epidx = CkRegisterEp("DistanceMetrics()",
      reinterpret_cast<CkCallFnPtr>(_call_DistanceMetrics_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_DistanceMetrics::_call_DistanceMetrics_void(void* impl_msg, void* impl_obj_void)
{
  DistanceMetrics* impl_obj = static_cast<DistanceMetrics*>(impl_obj_void);
  new (impl_obj_void) DistanceMetrics();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void euclideanDistance(const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1);
 */
void CProxy_DistanceMetrics::euclideanDistance(const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_0;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_1;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_0;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_1;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_DistanceMetrics::idx_euclideanDistance_marshall2(),0);
}

// Entry point registration function
int CkIndex_DistanceMetrics::reg_euclideanDistance_marshall2() {
  int epidx = CkRegisterEp("euclideanDistance(const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1)",
      reinterpret_cast<CkCallFnPtr>(_call_euclideanDistance_marshall2), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_euclideanDistance_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_euclideanDistance_marshall2);

  return epidx;
}

void CkIndex_DistanceMetrics::_call_euclideanDistance_marshall2(void* impl_msg, void* impl_obj_void)
{
  DistanceMetrics* impl_obj = static_cast<DistanceMetrics*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::vector<double>> impl_noname_0;
  implP|impl_noname_0;
  PUP::detail::TemporaryObjectHolder<std::vector<double>> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->euclideanDistance(std::move(impl_noname_0.t), std::move(impl_noname_1.t));
}
int CkIndex_DistanceMetrics::_callmarshall_euclideanDistance_marshall2(char* impl_buf, void* impl_obj_void) {
  DistanceMetrics* impl_obj = static_cast<DistanceMetrics*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::vector<double>> impl_noname_0;
  implP|impl_noname_0;
  PUP::detail::TemporaryObjectHolder<std::vector<double>> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->euclideanDistance(std::move(impl_noname_0.t), std::move(impl_noname_1.t));
  return implP.size();
}
void CkIndex_DistanceMetrics::_marshallmessagepup_euclideanDistance_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::vector<double>> impl_noname_0;
  implP|impl_noname_0;
  PUP::detail::TemporaryObjectHolder<std::vector<double>> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("impl_noname_0");
  implDestP|impl_noname_0;
  if (implDestP.hasComments()) implDestP.comment("impl_noname_1");
  implDestP|impl_noname_1;
}
PUPable_def(SINGLE_ARG(Closure_DistanceMetrics::euclideanDistance_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: DistanceMetrics(CkMigrateMessage* impl_msg);
 */

// Entry point registration function
int CkIndex_DistanceMetrics::reg_DistanceMetrics_CkMigrateMessage() {
  int epidx = CkRegisterEp("DistanceMetrics(CkMigrateMessage* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_DistanceMetrics_CkMigrateMessage), 0, __idx, 0);
  return epidx;
}

void CkIndex_DistanceMetrics::_call_DistanceMetrics_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<DistanceMetrics> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: DistanceMetrics();
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void euclideanDistance(const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1);
 */
void CProxySection_DistanceMetrics::euclideanDistance(const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_0;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_1;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_0;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<double>>::type>::type &)impl_noname_1;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_DistanceMetrics::idx_euclideanDistance_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: DistanceMetrics(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_DistanceMetrics::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterArrayDimensions(__idx, 1);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: DistanceMetrics();
  idx_DistanceMetrics_void();
  CkRegisterDefaultCtor(__idx, idx_DistanceMetrics_void());

  // REG: void euclideanDistance(const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1);
  idx_euclideanDistance_marshall2();

  // REG: DistanceMetrics(CkMigrateMessage* impl_msg);
  idx_DistanceMetrics_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_DistanceMetrics_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerdistanceMetrics(void)
{
  static int _done = 0; if(_done) return; _done = 1;
/* REG: array DistanceMetrics: ArrayElement{
DistanceMetrics();
void euclideanDistance(const std::vector<double> &impl_noname_0, const std::vector<double> &impl_noname_1);
DistanceMetrics(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_DistanceMetrics::__register("DistanceMetrics", sizeof(DistanceMetrics));

}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_DistanceMetrics::virtual_pup(PUP::er &p) {
    recursive_pup<DistanceMetrics>(dynamic_cast<DistanceMetrics*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
