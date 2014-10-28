/**************************************************************************************************
// file:	Engine\Exceptions\CInputNotAvailableException.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the input not available exception class
 **************************************************************************************************/
#ifndef A2DE_CINPUTNOTAVAILABLEEXCEPTION_H
#define A2DE_CINPUTNOTAVAILABLEEXCEPTION_H

#include "../a2de_vals.h"
#include "CException.h"

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Exception for signaling input not available errors.</summary>
 * <remarks>Casey Ugone, 7/30/2011.</remarks>
 * <seealso cref="Exception"/>
 **************************************************************************************************/
class InputNotAvailableException : public Exception {
public:

    /**************************************************************************************************
     * <summary>Initializes a new instance of the InputNotAvailableException class.</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     * <param name="inputType">Type of the input.</param>
     **************************************************************************************************/
    InputNotAvailableException(std::string inputType);

    /**************************************************************************************************
     * <summary>Destructor</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     **************************************************************************************************/
    virtual ~InputNotAvailableException();

    /**************************************************************************************************
     * <summary>Gets the message.</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     * <returns>The message.</returns>
     **************************************************************************************************/
    virtual std::string Message() const;
protected:
private:
    /// <summary> The input type </summary>
    std::string _input;
};

A2DE_END

#endif