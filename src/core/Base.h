/* date = August 5th 2023 0:21 am */

#ifndef _BASE_H
#define _BASE_H

#include <memory>
#include <vector>
#include <iostream>

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T>
using WeakRef = std::weak_ptr<T>;

template <typename T>
using List = std::vector<T>;

#define SKR_ASSERT(statement, message) assert(statement && message);

#endif //_BASE_H
