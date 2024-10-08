#!/bin/bash
#!/bin/bash
g++ -std=c++17 "$1" -o "${1%.*}" && ./"${1%.*}"

