#ifndef BIN_AST_TYPE_H__
#define BIN_AST_TYPE_H__
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

#include "ast/struct-members.h"
#include "ptr.h"

namespace arua {
namespace ast {

class Type {
protected:
	Type() = default;
public:
	virtual ~Type() = default;

	virtual bool isNumber() const;
	virtual bool isSigned() const;
	virtual bool isUnsigned() const;
	virtual bool isFloating() const;
	virtual bool isStruct() const;
	virtual bool isArray() const;
	virtual unsigned int getWidth() const;
	virtual Ptr<Type> getBase() const;
	virtual Ptr<StructMembers> getStructMembers() const;
	virtual std::string getStructName() const;

private:
	friend std::ostream & operator <<(std::ostream &stream, const Type &value);
};


}
}

#endif
