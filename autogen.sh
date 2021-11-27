#!/bin/bash

cd $(dirname $0)

install_dir=$PWD/install

echo "Clearing build data"
rm -rf build
mkdir build
cd build

echo "Passing $@"

cmake ../  \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DCMAKE_INSTALL_PREFIX=$install_dir
    "$@"

