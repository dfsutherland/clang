// RUN: %clang_cc1 %s -std=c++11 -fsyntax-only -thrd-role-analysis -verify
// expected-no-diagnostics

[[cert::thrd_role_decl("GUI")]]
void func() {
  [[cert::thrd_role_revoke("Worker")]] [[cert::thrd_role_grant("Worker")]] {
  }
}

void func2() {
  if (true) [[cert::thrd_role_grant("Worker")]] {
  } else [[cert::thrd_role_grant("GUI")]] {
  }
}
