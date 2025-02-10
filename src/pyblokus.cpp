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
        .def("getState", &BlokusMatch::getState, "Returns the state of the board as a list of integers");

        py::enum_<blokusShapeType>(m, "blokusShapeType")
        .value("iShapeType", blokusShapeType::iShapeType)
        .value("bigCornerShapeType", blokusShapeType::bigCornerShapeType)
        .value("crossShapeType", blokusShapeType::crossShapeType)
        .value("snakeShapeType", blokusShapeType::snakeShapeType)
        .value("dinoShapeType", blokusShapeType::dinoShapeType)
        .value("submarineShapeType", blokusShapeType::submarineShapeType)
        .value("zigzagShapeType", blokusShapeType::zigzagShapeType)
        .value("bigtShapeType", blokusShapeType::bigtShapeType)
        .value("uShapeType", blokusShapeType::uShapeType)
        .value("longlShapeType", blokusShapeType::longlShapeType)
        .value("diggerShapeType", blokusShapeType::diggerShapeType)
        .value("sixShapeType", blokusShapeType::sixShapeType)
        .value("zShapeType", blokusShapeType::zShapeType)
        .value("oShapeType", blokusShapeType::oShapeType)
        .value("tShapeType", blokusShapeType::tShapeType)
        .value("mediumlShapeType", blokusShapeType::mediumlShapeType)
        .value("threeShapeType", blokusShapeType::threeShapeType)
        .value("smallCornerShapeType", blokusShapeType::smallCornerShapeType)
        .value("twoShapeType", blokusShapeType::twoShapeType)
        .value("singleShapeType", blokusShapeType::singleShapeType)
        .value("passShapeType", blokusShapeType::passShapeType)
        .export_values(); // Allow the values to be used in Python

    // Expose the BlokusMove as a tuple (shape, row, col, rotation)
    m.def("BlokusMove", [](blokusShapeType shape, int row, int col, uint8_t rotation) {
        return std::make_tuple(shape, row, col, rotation);
    });
}