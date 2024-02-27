#include <gtest/gtest.h>
#include <_test/_init/init.hpp>

TEST(Storage, names) {
	init();
	
	auto& a_names{tnl::Storage<A>::storage().names()};
	ASSERT_EQ(a_names.size(), 1);
	ASSERT_TRUE(a_names.contains("A"));
	
	auto& b_names{tnl::Storage<B>::storage().names()};
	ASSERT_EQ(b_names.size(), 0);
	
	auto& c_names{tnl::Storage<C>::storage().names()};
	ASSERT_EQ(c_names.size(), 1);
	ASSERT_TRUE(c_names.contains("C"));
	
	auto& d_names{tnl::Storage<D>::storage().names()};
	ASSERT_EQ(d_names.size(), 0);
}
