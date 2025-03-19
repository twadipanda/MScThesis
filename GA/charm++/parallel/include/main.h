#pragma once


class Main : public CBase_Main {

 public:

  /// Constructors ///
  Main(CkArgMsg* msg);
  Main(CkMigrateMessage* msg);

  /// Entry Methods ///
  void done(const std::vector<std::pair<int, double>>&);
  void recieve(const std::vector<std::vector<double>>&);
  void finished();

};
