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

template<class T>
struct tag_t { using type=T; constexpr tag_t() {}; };
template<class T>
constexpr tag_t<T> tag{};

template<class T, class U>
constexpr std::is_same<T, U>  operator==( tag_t<T>, tag_t<U> ) { return {}; }
template<class T, class U>
constexpr std::integral_constant<bool, !(tag<T> ==tag<U>)> operator!=( tag_t<T>, tag_t<U> ) { return {}; }

#define SKR_ASSERT(statement, message) assert(statement && message);

#endif //_BASE_H
