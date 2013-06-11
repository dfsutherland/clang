// RUN: %clang_cc1 %s -fsyntax-only -thrd-role-analysis -fcxx-attributes -verify

[[cert::thrd_role_decl("GUI")]]
void func( void ) {

}

[[cert::thrd_role_decl()]] int b;  // expected-error {{expected expression}} // expected-error {{attribute takes one argument}}
