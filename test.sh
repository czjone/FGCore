rm -rf build
sh build.sh
val=$?
if [[ ${val} == 0 ]]; then
	./build/FGCoreGTest #run test
	exit 0
else
	exit ${val}
fi

