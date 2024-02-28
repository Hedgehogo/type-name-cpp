#pragma once

#include <type-name/type-name.hpp>

class A {
};

template<>
struct tnl::TypeName<A> {
	static auto type_name() -> tnl::StringView;
};

class B {
};

template<>
struct tnl::TypeName<B> {
	constexpr static auto type_name = tnl::StringView{"B_"};
};

class C {
};

class D {
};

auto init() -> void;
