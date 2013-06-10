// RUN: %clang_cc1 %s -fsyntax-only -thrd-role-analysis -triple=i686-linux-gnu -verify

int a __attribute__((thrd_role_decl("GUI, Compute")));
int b __attribute__((thrd_role_decl()));  // expected-error {{attribute takes one argument}}
int c __attribute__((thrd_role_decl(12)));	// expected-error {{'thrd_role_decl' attribute requires parameters 1 to be a string}}
