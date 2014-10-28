/**************************************************************************************************
// file:	Engine\Exceptions\CException.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the exception class
 **************************************************************************************************/
#ifndef A2DE_CEXCEPTION_H
#define A2DE_CEXCEPTION_H

#include "../a2de_vals.h"
#include <string.h>
#include <stdexcept>

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Base a2de::Exception class.</summary>
 * <remarks>Casey Ugone, 7/30/2011.</remarks>
 * <seealso cref="std::exception"/>
 **************************************************************************************************/
class Exception : public std::exception {

public:

    /**************************************************************************************************
     * <summary>Initializes a new instance of the Exception class.</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     * <param name="message">The message.</param>
     **************************************************************************************************/
	Exception(std::string message);

    /**************************************************************************************************
     * <summary>Destructor</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     **************************************************************************************************/
	virtual ~Exception();

    /**************************************************************************************************
     * <summary>Gets the message.</summary>
     * <remarks>Casey Ugone, 6/24/2012.</remarks>
     * <returns>The message.</returns>
     **************************************************************************************************/
	virtual std::string Message() const;

    /**************************************************************************************************
     * <summary>Gets the low-level 'what' message of the std::exception.</summary>
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