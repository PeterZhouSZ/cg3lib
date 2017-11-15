/**
    @author Stefano Nuvoli
*/
#ifndef CG3_AABBHELPERS_H
#define CG3_AABBHELPERS_H

#include "treecommon.h"

#include "nodes/aabb.h"

#include <vector>

namespace cg3 {


/* Types */

enum AABBValueType { MIN, MAX };

template <class K>
using KeyOverlapCheckerType = bool (*)(const K& key1, const K& key2);

template <class K>
using AABBValueExtractorType = double (*)(const K& key, const AABBValueType& valueType, const int& dim);



/* AABB helpers */

template <int D, class K, class Node>
void aabbOverlapQueryHelper(
        Node* node,
        const K& key,
        const AABB<D>& aabb,
        std::vector<Node*> &out,
        KeyOverlapCheckerType<K> keyOverlapChecker);

template <int D, class K, class Node>
bool aabbOverlapCheckHelper(
        Node* node,
        const K& key,
        const AABB<D>& aabb,
        KeyOverlapCheckerType<K> keyOverlapChecker);

template <int D, class K, class Node>
void updateAABBHelper(Node* node, AABBValueExtractorType<K> aabbValueExtractor);


/* AVL helpers for AABB */

template <int D, class K, class Node>
void rebalanceAABBHelper(Node* node, Node*& rootNode, AABBValueExtractorType<K> aabbValueExtractor);

template <int D, class K, class Node>
void updateHeightAndRebalanceAABBHelper(Node* node, Node*& rootNode, AABBValueExtractorType<K> aabbValueExtractor);

template <int D, class K, class Node>
Node* leftRotateAABBHelper(Node* a, AABBValueExtractorType<K> aabbValueExtractor);

template <int D, class K, class Node>
Node* rightRotateAABBHelper(Node* a, AABBValueExtractorType<K> aabbValueExtractor);



/* AABB utilities */

template <int D>
inline bool aabbOverlapsHelper(const AABB<D>& a, const AABB<D>& b);

template <int D, class K>
inline void setAABBFromKeyHelper(const K& k, AABB<D>& aabb, AABBValueExtractorType<K> aabbValueExtractor);

}

#include "aabbhelpers.tpp"

#endif // CG3_AABBHELPERS_H
