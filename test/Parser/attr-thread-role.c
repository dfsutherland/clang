// RUN: %clang_cc1 %s -fsyntax-only -thread-role-analysis -fcxx-attributes -verify

[[cert::thread_role_decl("GUI")]]
void func( void ) {
  [[cert::thread_role_grant()]]{} // expected-error {{'cert::thread_role_grant' attribute requires parameter 1 to be a string}}
  [[cert::thread_role_revoke()]]{} // expected-error {{'cert::thread_role_revoke' attribute requires parameter 1 to be a string}}
}

[[cert::thread_role_decl()]] int b;  // expected-error {{expected expression}} // expected-error {{attribute takes one argument}}
