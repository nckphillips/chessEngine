# chessEngine
Chess engine written in C for 181AB
## Interface
Our engine communicates with a gui using the Xboard protocol. Specifications were taken from [here](https://www.gnu.org/software/xboard/engine-intf.html#8).
Bitboards are used for internal representation. [Bitboard calculator](http://cinnamonchess.altervista.org/bitboard_calculator/Calc.html?type=2)

## Build Instructions
The engine relies purely on the C Standard Library and can be compiled with gcc. Simply clone the repository and
make.
## Using the Engine
Run Xboard. Click the "Engine" dropdown and select "load new first engine". Specify the nickname, directory of the binary
executable and for the "Engine Command" select the engine executable and click ok.
