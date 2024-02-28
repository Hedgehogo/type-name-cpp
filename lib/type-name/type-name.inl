//included into type-name.hpp

#include <typeinfo>
#include <type_traits>

namespace tnl {
	template<typename T_>
	auto type_name() -> StringView {
		auto& names{Storage<T_>::storage().names()};
		if(!names.empty()) {
			return {*names.cbegin()};
		}
		if constexpr(has_type_name_v<T_>) {
			using Return = std::remove_cv_t<decltype(TypeName<T_>::type_name)>;
			if constexpr(std::is_same_v<Return, StringView>) {
				return TypeName<T_>::type_name;
			} else {
				return TypeName<T_>::type_name();
			}
		}
		return {"unknown type"};
	}
}
