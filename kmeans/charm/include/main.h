#pragma once


class Main : public CBase_Main {

 public:

  /// Constructors ///
  Main(CkArgMsg* msg);
  Main(CkMigrateMessage* msg);

  /// Entry Methods ///
  void done();
  void finished(std::vector<double>&, int index, int);

};
