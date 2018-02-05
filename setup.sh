rm -rf build/
mkdir build/
cd build/
cmake ../ -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=Debug -DTLOC_DETAILED_LOGS=ON
make

cd ../include/
rm -rf build/
mkdir build/
cd build/
cmake ../ -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=Debug -DTLOC_DETAILED_LOGS=ON
make install
