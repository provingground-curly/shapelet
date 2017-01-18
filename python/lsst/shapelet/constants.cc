/*
 * LSST Data Management System
 *
 * This product includes software developed by the
 * LSST Project (http://www.lsst.org/).
 * See the COPYRIGHT file
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the LSST License Statement and
 * the GNU General Public License along with this program.  If not,
 * see <https://www.lsstcorp.org/LegalNotices/>.
 */
#include "pybind11/pybind11.h"

#include "lsst/shapelet/constants.h"

namespace py = pybind11;
using namespace pybind11::literals;

namespace lsst {
namespace shapelet {

PYBIND11_PLUGIN(_constants) {
    py::module mod("_constants");

    py::enum_<BasisTypeEnum>(mod, "BasisTypeEnum")
        .value("HERMITE", BasisTypeEnum::HERMITE)
        .value("LAGUERRE", BasisTypeEnum::LAGUERRE)
        .export_values();

    mod.def("computeOffset", computeOffset);
    mod.def("computeSize", computeSize);
    mod.def("computeOrder", computeOrder);
    mod.def("intSqrt", intSqrt);
    mod.def("rationalSqrt", rationalSqrt);

    return mod.ptr();
}
}
}  // lsst::shapelet