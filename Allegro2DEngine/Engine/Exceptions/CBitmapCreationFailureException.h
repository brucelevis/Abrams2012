/**************************************************************************************************
// file:	Engine\Exceptions\CBitmapCreationFailureException.h
// Allegro2DEngine
// Copyright (c) 2012 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for support.
// summary:	Declares the bitmap creation failure exception class
 **************************************************************************************************/
#ifndef A2DE_CBITMAPCREATIONFAILUREEXCEPTION_H
#define A2DE_CBITMAPCREATIONFAILUREEXCEPTION_H

#include "../a2de_vals.h"
#include "CException.h"

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Exception for signalling bitmap creation failure errors. </summary>
 * <remarks>Casey Ugone, 6/12/2012.</remarks>
 * <seealso cref="Exception"/>
 **************************************************************************************************/
class BitmapCreationFailureException : public Exception {
public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 6/12/2012.</remarks>
     * <param name="name">The name of the bitmap that failed..</param>
     **************************************************************************************************/
    BitmapCreationFailureException(std::string name);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 6/12/2012.</remarks>
     **************************************************************************************************/
    virtual ~BitmapCreationFailureException();

    /**************************************************************************************************
     * <summary>Gets the message of the exception.</summary>
     * <remarks>Casey Ugone, 6/12/2012.</remarks>
     * <returns>The message.</returns>
     **************************************************************************************************/
    virtual std::string Message() const;
protected:
private:
    /// <summary> The name of the BITMAP </summary>
    std::string _name;

};

A2DE_END

#endif