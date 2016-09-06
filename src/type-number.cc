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

#include "arua/bootstrap/ast/exception.h"
#include "arua/bootstrap/ast/type-number.h"

using namespace arua::bootstrap::ast;
using namespace std;

static const unsigned int MAX_WIDTH = 4096; //> RFC #14

NumberType::NumberType(NumberClassification numberClassification, unsigned int width)
		: numberClassification(numberClassification)
		, width(width) {
	if (width == 0) {
		throw ast::error << "numeric bit-widths must be at least 1";
	}

	if (width > MAX_WIDTH) {
		throw ast::error << "numeric bit-widths cannot be larger than " << MAX_WIDTH;
	}

	if (numberClassification == NumberClassification::FLOAT) {
		switch (width) {
		case 16:
		case 32:
		case 64:
		case 128:
			break;
		default:
			throw ast::error << "floating point widths must be one of: 16, 32, 64, 128";
		}
	}
}

string NumberType::getTypeString() const {
	return "type:number";
}

string NumberType::getValueString() const {
	string type = "";
	switch (this->numberClassification) {
	case NumberClassification::INT:
		type = "i";
		break;
	case NumberClassification::UINT:
		type = "u";
		break;
	case NumberClassification::FLOAT:
		type = "f";
		break;
	default:
		throw ast::error << "unknown numeric classification: " << (int) this->numberClassification;
	}

	return type + to_string(this->width);
}

TypeClassification NumberType::getTypeClassification() const {
	return TypeClassification::NUMBER;
}

NumberClassification NumberType::getNumberClassification() const {
	return this->numberClassification;
}

unsigned int NumberType::getWidth() const {
	return this->width;
}