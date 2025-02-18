#pragma once

class Kmeans : public CBase_Kmeans {

 public:

  /// Constructors ///
  Kmeans();
  Kmeans(CkMigrateMessage *msg);

  /// Entry Methods ///
  void sayHi(int from);

};
