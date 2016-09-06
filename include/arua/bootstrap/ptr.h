#ifndef ARUA_BOOTSTRAP_PTR_H__
#define ARUA_BOOTSTRAP_PTR_H__
#pragma once
/*
	      ____    _____   __   _  ____
	     |    \  |     | |  | | ||    \
	     |     \ |     \ |  |_| ||     \
	     |__|\__\|__|\__\|______||__|\__\

	            arua bootstrap ast
	      copyright (c) 2016, josh junon
	    github.com/arua-lang/bootstrap-ast
	               mit license
*/

#include <ostream>

namespace arua {
namespace bootstrap {

/*
	Where's the support for the dereference operator?

	If you haven't already noticed, this class is pretty
	forceful in terms of the kinds of operations you are allowed to
	do, in order to promote good pointer etiquette. Forcing you to use
	operator->() to get the raw pointer is simlar methodology as
	using unsafe{} in Rust, as it makes you think about what you're
	doing and give you a reason to properly implement the API that
	will be consuming the raw pointer.

	As well, it's still pretty self-documenting and easily grepped.

	So please don't submit a PR with a dereference operator implementation
	as it will be closed on the spot. :)
*/
template <typename T, typename Friend = T>
class Ptr {
	friend class Ptr<Friend>;

	Ptr(T *ptr)
			: count(new unsigned int(1))
			, ptr(ptr) {
	}

	Ptr(T *ptr, unsigned int *count)
			: count(count)
			, ptr(ptr) {
		++*this->count;
	}

public:
	Ptr(const Ptr<T> &other)
			: count(other.count)
			, ptr(other.ptr) {
		++*this->count;
	}

	~Ptr() {
		--*this->count;
		if (this->count == 0) {
			delete this->count;
			delete this->ptr;
		}
	}

	template <typename... Args>
	static Ptr<T> make(Args... args) {
		return Ptr(new T(args...));
	}

	T * operator->() {
		return this->ptr;
	}

	const T * operator->() const {
		return this->ptr;
	}

	template <typename R>
	Ptr<R> as() {
		// I know this isn't pretty but it's the only way to keep the API
		// clean. It should be completely optimized out by the compiler.
		auto nptr = Ptr<R, T>((R *) this->ptr, this->count);
		return *reinterpret_cast<Ptr<R> *>(&nptr);
	}

private:
	unsigned int *count;
	T *ptr;
};

template <typename T>
std::ostream & operator<<(std::ostream &stream, const Ptr<T> &ptr) {
	stream << *ptr.operator->();
	return stream;
}

}
}

#endif
