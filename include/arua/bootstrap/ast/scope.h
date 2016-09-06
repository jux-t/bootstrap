#ifndef ARUA_BOOTSTRAP_AST_SCOPE_H__
#define ARUA_BOOTSTRAP_AST_SCOPE_H__
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

#include <map>
#include <string>

#include "arua/bootstrap/ast/node.h"
#include "arua/bootstrap/ast/type-derived.h"
#include "arua/bootstrap/ptr.h"

namespace arua {
namespace bootstrap {
namespace ast {

class Scope : public Node {
public:
	virtual std::string getTypeString() const;
	virtual std::string getValueString() const;

	/**
		Resolves a derived name to its type

		Throws if a type isn't found.

		NOTE: This does not resolve anything /except/ derived types.
		      This means `i32` and `[str]` will not resolve. This is
		      up to the parser.
	*/
	virtual Ptr<DerivedType> resolve(std::string name) const;

	/**
		Returns true if the type is available for resolution in the scope

		Does not throw.

		See NOTE on resolve() for important information.
	*/
	virtual bool canResolve(std::string name) const;

	/**
		Adds a new derived type to the scope

		Throws if there is a conflicting type.

		NOTE: Do not add `i32` or any such types here, as they are primitives.
		      These are for typedef'd (derived) types as per RFC #3.
	*/
	void addType(Ptr<DerivedType> type);

protected:
	std::map<std::string, Ptr<DerivedType>> types;

private:
	void validateAllTypes(Ptr<Type> type, Ptr<Type> top) const;
};

}
}
}

#endif
