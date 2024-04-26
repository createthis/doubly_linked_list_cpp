# Getting Started
## Install Google Test
### Mac OSX
```bash
brew install googletest
```

### other
```bash
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ..
make
sudo make install
```

## Compile
```bash
g++ -std=c++14 -pthread test.cpp -o test -lgtest -lgtest_main
```

## Run Tests
```bash
./test
```
