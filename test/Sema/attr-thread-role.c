// RUN: %clang_cc1 %s -fsyntax-only -thread-role-analysis -fcxx-attributes -verify

[[cert::thread_role_decl("GUI, Compute")]] int a;
[[cert::thread_role_decl(12)]] int c;	// expected-error {{'thread_role_decl' attribute requires parameter 1 to be a string}}
[[cert::thread_role_decl("")]] int d;     // expected-error {{cert::'thread_role_decl' requires a non-empty list of thread roles}}
[[cert::thread_role_decl("GUI, Compute, GUI, Compute")]] int e; // expected-error {{duplicate name 'GUI' found in cert::'thread_role_decl'}} expected-error {{duplicate name 'Compute' found in cert::'thread_role_decl'}}
