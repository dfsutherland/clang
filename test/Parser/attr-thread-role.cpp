// RUN: %clang_cc1 %s -std=c++11 -fsyntax-only -thrd-role-analysis -verify
// expected-no-diagnostics

// The thread_role_decl should attach to the function declaration,
// while the thread_role_revoke and thread_role_grant should attach
// to the function's lexical block.
void func() __attribute__((thrd_role_decl("GUI")));

void func() [[cert::thrd_role_revoke("Worker")]] {

} __attribute__((thrd_role_grant("GUI")))

void func2() {
  if (true) [[cert::thrd_role_grant("Worker")]] {
  } else {
  } __attribute__((thrd_role_grant("GUI")))
}
