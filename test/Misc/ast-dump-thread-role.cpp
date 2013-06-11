// RUN: %clang_cc1 -std=c++11 -thrd-role-analysis -ast-dump %s | FileCheck -strict-whitespace %s

void func2() {
  if (true) [[cert::thrd_role_grant("Worker")]] {
  // CHECK:       AttributedStmt{{.*}}
  // CHECK-NEXT:  ThrdRoleGrantAttr{{.*}} "Worker"
  // CHECK-NEXT:  CompoundStmt{{.*}}
  } else [[cert::thrd_role_grant("GUI")]] {
  // CHECK:       AttributedStmt{{.*}}
  // CHECK-NEXT:  ThrdRoleGrantAttr{{.*}} "GUI"
  // CHECK-NEXT:  CompoundStmt{{.*}}
  }
}
