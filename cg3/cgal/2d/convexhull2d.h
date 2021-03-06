/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Stefano Nuvoli (stefano.nuvoli@gmail.com)
 */

#ifndef CG3_CGAL_CONVEXHULL2D_H
#define CG3_CGAL_CONVEXHULL2D_H

#include <vector>
#include <cg3/geometry/2d/point2d.h>

namespace cg3 {
namespace cgal {

template <class T = double, class InputContainer, class OutputContainer>
void convexHull2D(
        const InputContainer& points,
        OutputContainer& outputContainer);

template <class T = double, class InputIterator, class OutputIterator>
void convexHull2D(
        InputIterator first,
        InputIterator end,
        OutputIterator outIt);

#ifdef CG3_OLD_NAMES_COMPATIBILITY
template <class T = double, class InputContainer, class OutputContainer>
inline void getCGALConvexHull2D(
        const InputContainer& points,
        OutputContainer& outputContainer)
{
    return convexHull2D(points, outputContainer);
}

template <class T = double, class InputIterator, class OutputIterator>
inline void getCGALConvexHull2D(
        InputIterator first,
        InputIterator end,
        OutputIterator outIt)
{
    return convexHull2D(first, end, outIT);
}
#endif

} //namespace cg3::cgal
} //namespace cg3

#include "convexhull2d.tpp"

#endif // CG3_CGAL_CONVEXHULL2D_H
