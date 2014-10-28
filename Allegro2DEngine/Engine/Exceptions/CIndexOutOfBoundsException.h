/**************************************************************************************************
// file:	Engine\Exceptions\CIndexOutOfBoundsException.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the index out of bounds exception class
 **************************************************************************************************/
#ifndef A2DE_CINDEXOUTOFBOUNDSEXCEPTION_H
#define A2DE_CINDEXOUTOFBOUNDSEXCEPTION_H

#include "../a2de_vals.h"
#include "CException.h"

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Exception for signaling index out of bounds errors.</summary>
 * <remarks>Casey Ugone, 7/30/2011.</remarks>
 * <seealso cref="Exception"/>
 **************************************************************************************************/
class IndexOutOfBoundsException : public Exception {

public:

    /**************************************************************************************************
     * <summary>Initializes a new instance of the IndexOutOfBoundsException class.</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     * <param name="argument">  The argument.</param>
     * <param name="lowerBound">The lower bound inclusive argument.</param>
     * <param name="upperBound">The upper bound inclusive argument.</param>
     **************************************************************************************************/
	IndexOutOfBoundsException(std::string argument, std::string lowerBound, std::string upperBound);

    /**************************************************************************************************
     * <summary>Destructor</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     **************************************************************************************************/
	virtual ~IndexOutOfBoundsException();

    /**************************************************************************************************
     * <summary>Gets the message.</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     * <returns>The message.</returns>
     **************************************************************************************************/
    virtual std::string Message() const;
private:
    /// <summary> The lower bound </summary>
    std::string _lower;
    /// <summary> The upper bound </summary>
    std::string _upper;
    /// <summary> The argument name </summary>
    std::string _argument;
};

A2DE_END

#endif