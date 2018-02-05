rm -rf build_release/
mkdir build_release/
cd build_release/
cmake ../ -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=Release -DTLOC_DETAILED_LOGS=ON
make

cd ../include/
rm -rf build_release/
mkdir build_release/
cd build_release/
cmake ../ -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=Release -DTLOC_DETAILED_LOGS=ON
make install
