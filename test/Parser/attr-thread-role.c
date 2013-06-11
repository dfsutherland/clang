// RUN: %clang_cc1 %s -fsyntax-only -thrd-role-analysis -fcxx-attributes -verify
// expected-no-diagnostics

void func(void) __attribute__((thrd_role_decl("GUI")));

void func( void ) {

}
