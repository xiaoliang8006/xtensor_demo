### cmake ###
# ./build.sh
# export PYTHONPATH=/data/ericoliang/cmake_demo/build:$PYTHONPATH
# python3 examples/xtensor_test.py


### bazel ###
# bazel build //:basic_test && ./bazel-bin/basic_test
bazel build //:xtensor_test && ./bazel-bin/xtensor_test