#include "init.hpp"

auto tnl::TypeName<A>::type_name() -> tnl::StringView {
	return "A_";
}

auto tnl::TypeName<B>::type_name() -> tnl::StringView {
	return "B_";
}

auto init() -> void {
	[[maybe_unused]] static auto _{[] {
		tnl::Storage<A>::storage().add_name("A");
		tnl::Storage<C>::storage().add_name("C");
		return true;
	}()};
}
