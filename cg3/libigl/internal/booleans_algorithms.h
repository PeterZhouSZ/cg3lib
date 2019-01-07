#ifndef CG3_BOOLEAN_ALGORITHMS_H
#define CG3_BOOLEAN_ALGORITHMS_H

#ifdef CG3_CGAL_DEFINED

#ifdef __GNUC__
#ifndef __clang__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnon-template-friend"
#include <igl/copyleft/cgal/CSGTree.h>
#pragma GCC diagnostic pop
#else //__clang__
#include <igl/copyleft/cgal/CSGTree.h>
#endif //__clang__
#else //__GNUC__
#include <igl/copyleft/cgal/CSGTree.h>
#endif //__GNUC__

namespace cg3 {
namespace libigl {
namespace internal {
extern std::vector<uint> dummyVector;

/* CSGTree typedefs */
typedef igl::copyleft::cgal::CSGTree CSGTree;

igl::copyleft::cgal::CSGTree intersection(
        const igl::copyleft::cgal::CSGTree& c1,
        const igl::copyleft::cgal::CSGTree& c2);

igl::copyleft::cgal::CSGTree difference(
        const igl::copyleft::cgal::CSGTree& c1,
        const igl::copyleft::cgal::CSGTree& c2);

igl::copyleft::cgal::CSGTree union_(
        const igl::copyleft::cgal::CSGTree& c1,
        const igl::copyleft::cgal::CSGTree& c2);

} //namespace cg3::libigl::internal
} //namespace cg3::libigl
} //namespace cg3

#endif // CGAL_DEFINED
#endif // CG3_BOOLEAN_ALGORITHMS_H
