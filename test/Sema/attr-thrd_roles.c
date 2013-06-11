// RUN: %clang_cc1 %s -fsyntax-only -thrd-role-analysis -fcxx-attributes -verify

[[cert::thrd_role_decl("GUI, Compute")]] int a;
[[cert::thrd_role_decl(12)]] int c;	// expected-error {{'thrd_role_decl' attribute requires parameter 1 to be a string}}
