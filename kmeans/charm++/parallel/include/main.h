#pragma once

class Main : public CBase_Main {
 public:
  /// Constructors ///
  Main(CkArgMsg* msg);
  Main(CkMigrateMessage* msg);

  /// Entry Methods ///
  void done();
  void finished(const std::vector<double>&, int index);
};