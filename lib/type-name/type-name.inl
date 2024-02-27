//included into type-name.hpp

#include <typeinfo>
#include <type_traits>
#include <iostream>

namespace tnl {
	template<typename T_>
	auto type_name() -> StringView {
		auto names{Storage<T_>::storage().names()};
		for(auto& item: names) {
			return {item};
		}
		if constexpr(has_type_name_v<T_>) {
			return TypeName<T_>::type_name();
		}
		return "unknown type";
	}
}
