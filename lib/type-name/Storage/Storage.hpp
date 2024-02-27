#pragma once

#include <absl/container/flat_hash_set.h>

namespace tnl {
	using Char = char;
	using String = std::basic_string<Char>;
	using StringView = std::basic_string_view<Char>;
	
	template<typename T_>
	class Storage {
	public:
		using NamesContainer = absl::flat_hash_set<String>;
		
		/// @brief Gets the set of names associated with the type
		///
		/// @return Set of names.
		auto names() const -> NamesContainer const&;
		
		/// @brief Adds an additional name to the type.
		///
		/// @param name Additional name.
		auto add_name(String&& name) -> void;
		
		/// @brief Returns a reference to the only existing instance of the class
		static auto storage() -> Storage&;
	
	private:
		Storage() = default;
		
		Storage(Storage const&) = delete;
		
		Storage(Storage&&) = delete;
		
		auto operator=(Storage const&) -> Storage& = delete;
		
		auto operator=(Storage const&) const -> Storage const& = delete;
		
		NamesContainer names_;
	};
}

#include "Storage.inl"
