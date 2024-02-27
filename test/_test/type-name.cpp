#include <gtest/gtest.h>
#include <_test/_init/init.hpp>

static_assert(tnl::has_type_name_v<A>);
static_assert(tnl::has_type_name_v<B>);
static_assert(!tnl::has_type_name_v<C>);
static_assert(!tnl::has_type_name_v<D>);

TEST(type_name, general) {
	init();
	
	ASSERT_STREQ(tnl::type_name<A>().data(), "A");
	ASSERT_STREQ(tnl::type_name<B>().data(), "B_");
	ASSERT_STREQ(tnl::type_name<C>().data(), "C");
	ASSERT_STREQ(tnl::type_name<D>().data(), "unknown type");
}
