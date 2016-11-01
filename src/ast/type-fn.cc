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

#include <sstream>
#include <string>

#include "ast/exception.h"
#include "ast/type-fn.h"
#include "ast/type-number.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

static const Ptr<Type> RET_VOID = Ptr<NumberType>::make(NumberClassification::INT, 1).as<Type>();

FnType::FnType()
		: returnType(RET_VOID) {
}

FnType::FnType(Ptr<Type> returnType)
		: returnType(returnType) {
}

FnType::FnType(vector<Ptr<Type>> argTypes)
		: returnType(RET_VOID)
		, argTypes(argTypes) {
}

FnType::FnType(Ptr<Type> returnType, vector<Ptr<Type>> argTypes)
		: returnType(returnType)
		, argTypes(argTypes) {
}

string FnType::getTypeString() const {
	return "type:fn";
}

string FnType::getValueString() const {
	stringstream ss;

	ss << "(";

	string delim = "";
	for (const Ptr<Type> &argType : this->argTypes) {
		ss << delim << argType;
		delim = ", ";
	}

	ss << ")";

	if (!this->isVoid()) {
		ss << " " << this->returnType;
	}

	return ss.str();
}

TypeClassification FnType::getTypeClassification() const {
	return TypeClassification::ARRAY;
}

void FnType::assertValidForScope(const Scope &scope) const {
	if (!this->isVoid()) {
		try {
			this->returnType->assertValidForScope(scope);
		} catch (AstException &e) {
			e << " (return type)";
			throw;
		}
	}

	for (const Ptr<Type> &argType : this->argTypes) {
		argType->assertValidForScope(scope);
	}
}

bool FnType::isVoid() const {
	// Yes, a direct raw pointer comparison /will/ work since RET_VOID
	// is static to this class. Believe it.
	return this->returnType.operator->() == RET_VOID.operator->();
}

Ptr<Type> FnType::getReturnType() const {
	// make sure to read the documentation on this method.
	// it throws if isVoid() is true, like literally on the next line.
	if (this->isVoid()) {
		// I warned you!
		throw ast::error << "cannot retrieve return type of void function: " << *this;
	}

	return this->returnType;
}

const vector<Ptr<Type>> FnType::getArgumentTypes() const {
	return this->argTypes;
}
