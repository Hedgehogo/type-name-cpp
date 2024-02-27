#pragma once

#include <type_traits>
#include <string>
#include "Storage/Storage.hpp"

namespace tnl {
	template<typename T_>
	struct TypeName {
	};
	
	namespace detail {
		template<typename T_, typename = StringView>
		struct HasTypeName : std::false_type {
		};
		
		template<typename T_>
		struct HasTypeName<T_, decltype(T_::type_name())> : std::true_type {
		};
	}
	
	template<typename T_>
	struct HasTypeName : detail::HasTypeName<TypeName<T_> > {
	};
	
	template<typename T_>
	constexpr auto has_type_name_v = HasTypeName<T_>::value;
	
	/// @brief Gets the name associated with the type
	///
	/// @return Name.
	template<typename T_>
	auto type_name() -> StringView;
}

#include "type-name.inl"
