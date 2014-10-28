/**************************************************************************************************
// file:	Engine\Exceptions\CInvalidArgumentException.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the invalid argument exception class
 **************************************************************************************************/
#ifndef A2DE_CINVALIDARGUMENTEXCEPTION_H
#define A2DE_CINVALIDARGUMENTEXCEPTION_H

#include "../a2de_vals.h"
#include "CException.h"

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Exception for signalling invalid arguments.</summary>
 * <remarks>Casey Ugone, 7/30/2011.</remarks>
 * <seealso cref="std::invalid_argument"/>
 **************************************************************************************************/
class InvalidArgumentException : public std::invalid_argument {

public:

    /**************************************************************************************************
     * <summary>Initializes a new instance of the InvalidArgumentException class.</summary>
     * <remarks>Casey Ugone, 3/10/2012.</remarks>
     * <param name="message">The message.</param>
     **************************************************************************************************/
	InvalidArgumentException(std::string message);

    /**************************************************************************************************
     * <summary>Initializes a new instance of the InvalidArgumentException class.</summary>
     * <remarks>Casey Ugone, 6/24/2012.</remarks>
     * <param name="message">The message.</param>
     **************************************************************************************************/
    InvalidArgumentException(const char* message);

    /**************************************************************************************************
     * <summary>Destructor</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     **************************************************************************************************/
	virtual ~InvalidArgumentException();

    /**************************************************************************************************
     * <summary>Gets the message of the exception as a std::string.</summary>
     * <remarks>Casey Ugone, 6/24/2012.</remarks>
     * <returns>The message.</returns>
     **************************************************************************************************/
	virtual std::string GetMessage() const;

    /**************************************************************************************************
     * <summary>Gets the low-level 'what' message of the std::invalid_argument.</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     * <returns>null if it fails, else the message.</returns>
     **************************************************************************************************/
    virtual const char* what() const;
protected:
	/// <summary> The message </summary>
	std::string _message;

};

A2DE_END

#endif