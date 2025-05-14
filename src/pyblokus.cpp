#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 
#include <match.h> 

namespace py = pybind11;

PYBIND11_MODULE(pyblokus, m) {
    // Expose the BlokusMatch class
    py::class_<BlokusMatch>(m, "BlokusMatch")
        .def(py::init<int>())  // Constructor that takes nPlayers
        .def("newGame", &BlokusMatch::newGame)
        .def("playMove", &BlokusMatch::playMove)
        .def("removeMove", &BlokusMatch::removeMove)
        .def("getMovesFromPos", &BlokusMatch::getMovesFromPos)
        .def("getCornersFromPos", &BlokusMatch::getCornersFromPos)
        .def("getTurn", &BlokusMatch::getTurn)
        .def("getPlayerPieces", &BlokusMatch::getPlayerPieces)
        .def("getFirstTurns", &BlokusMatch::getFirstTurns)
        .def("getPlayersPassed", &BlokusMatch::getPlayersPassed)
        .def("resign", &BlokusMatch::resign)
        .def("getState", &BlokusMatch::getState, "Returns the state of the board as a list of integers");
        
    // Expose the BlokusMove as a tuple (shape, row, col, rotation)
    m.def("BlokusMove", [](blokusShapeType shape, int row, int col, uint8_t rotation) {
        return std::make_tuple(shape, row, col, rotation);
    });
}