#include <gtest/gtest.h>
#include <FGCore/FG.h>
#include "../src/FG.cc"

FG_NS_USING;

TEST(FGCoreTest,Version){
 	EXPECT_EQ(1,get_version_code());
 	// FAIL();
}