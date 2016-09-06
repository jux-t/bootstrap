#ifndef ARUA_BOOTSTRAP_AST_SCOPE_NESTED_H__
#define ARUA_BOOTSTRAP_AST_SCOPE_NESTED_H__
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

#include "arua/bootstrap/ast/scope.h"
#include "arua/bootstrap/ptr.h"

namespace arua {
namespace bootstrap {
namespace ast {

class NestedScope : public Scope {
public:
	NestedScope(Ptr<Scope> parent);

	virtual std::string getTypeString() const;
	virtual std::string getValueString() const;

	virtual Ptr<DerivedType> resolve(std::string name) const;
	virtual bool canResolve(std::string name) const;

private:
	const Ptr<Scope> parent;
};

}
}
}

#endif
