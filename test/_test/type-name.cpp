#include <gtest/gtest.h>
#include <_test/_init/init.hpp>

static_assert(tnl::has_type_name_v<A>);
static_assert(tnl::has_type_name_v<B>);
static_assert(!tnl::has_type_name_v<C>);
static_assert(!tnl::has_type_name_v<D>);

TEST(type_name, general) {
	init();
	
	ASSERT_EQ(tnl::type_name<A>(), "A");
	ASSERT_EQ(tnl::type_name<B>(), "B_");
	ASSERT_EQ(tnl::type_name<C>(), "C");
	ASSERT_EQ(tnl::type_name<D>(), "unknown type");
}
