// RUN: %clang_cc1 %s -fsyntax-only -thread-role-analysis -fcxx-attributes -verify

[[cert::thread_role_decl("GUI, Compute")]] int a;
[[cert::thread_role_decl(12)]] int c;	// expected-error {{'thread_role_decl' attribute requires parameter 1 to be a string}}
