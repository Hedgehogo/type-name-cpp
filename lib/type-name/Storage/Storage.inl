//included into TypeNameStorage.hpp

namespace tnl {
	template<typename T_>
	auto Storage<T_>::names() const -> NamesContainer const& {
		return names_;
	}
	
	template<typename T_>
	auto Storage<T_>::add_name(String&& name) -> void {
		names_.insert(name);
	}
	
	template<typename T_>
	auto Storage<T_>::storage() -> Storage& {
		static auto object{Storage{}};
		return object;
	}
}
