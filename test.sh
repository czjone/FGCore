rm -rf build
sh build.sh
./build/FGCoreGTest
val=$?
# if [[ ${val}= = 0 ]]; then
# 	echo "gtest test sucess."
# else
# 	echo "gtest test fail."
# fi
exit ${val}
