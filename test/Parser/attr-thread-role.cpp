// RUN: %clang_cc1 %s -std=c++11 -fsyntax-only -thrd-role-analysis -verify
// expected-no-diagnostics

[[cert::thrd_role_decl("GUI, Worker")]]
[[cert::thrd_role_incompatible("GUI, Worker")]]
[[cert::thrd_role("GUI | Worker")]]
void func() {
  [[cert::thrd_role_revoke("GUI")]] [[cert::thrd_role_grant("Worker")]] {
  }
}

[[cert::thrd_role("GUI | Worker")]]
void func2() {
  if (true) [[cert::thrd_role_revoke("GUI")]] 
	    [[cert::thrd_role_grant("Worker")]] {
  } else [[cert::thrd_role_revoke("Worker")]] 
         [[cert::thrd_role_grant("GUI")]] {
  }
}
