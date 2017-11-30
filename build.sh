# mkdir -p build
# cd build
# cmake ..
# make

workpath=$(pwd)
basepath=$(cd `dirname $0`; pwd)

buildWithCmak() {
	pfolder=$1
	proj=${basepath}/${pfolder}
	mkdir -p build
	cd build
	cmake ..
	ret=$(make)
	if [[ $ret == 0 ]]; then
		echo "compile success!"
	else
		echo "compile faile!"
		exit -1
	fi
}


buildWithOther() {
	exit 1
}

build() {
	buildType=$1
	pfolder=$2

	if [[ $buildType == 1 ]]; then
		buildWithCmak $pfolder
	elif [[ $buildType == 2 ]]; then
		buildWithOther $pfolder
	fi
}

echo "FG Core compler start work...."
build 1 "external/clsocket/"

# checkArgs() {
# 	allargs=$@
# 	for i in allargs; do 
# 		echo $i; 
# 	done  
# }

# shellAllArgs=$@
# checkExistArgs() {
# 	firstArg=$1
# 	val=false
# 	for i in ${shellAllArgs}; do
# 		if [[ i==${firstArg} ]]; then
# 			val=true;
# 			break;
# 		fi
# 	done
# 	return ${val}
# }

# checkExistArgs
# echo ${$?}
# if [[ $?==1 ]]; then
# 	echo "aaaaaa"
# fi

# checkExistArgs "-a"
# if [[ ret==1 ]]; then
# 	echo "bbb"
# fi

# build 1 "external/clsocket/"
