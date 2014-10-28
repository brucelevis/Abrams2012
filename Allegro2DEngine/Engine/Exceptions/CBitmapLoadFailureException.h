/**************************************************************************************************
// file:	Engine\Exceptions\CBitmapLoadFailureException.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the bitmap load failure exception class
 **************************************************************************************************/
#ifndef A2DE_CBITMAPLOADFAILUREEXCEPTION_H
#define A2DE_CBITMAPLOADFAILUREEXCEPTION_H

#include "../a2de_vals.h"
#include "CException.h"

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Exception for signalling bitmap load failure errors. </summary>
 * <remarks>Casey Ugone, 6/12/2012.</remarks>
 * <seealso cref="Exception"/>
 **************************************************************************************************/
class BitmapLoadFailureException : public Exception {
public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 6/12/2012.</remarks>
     * <param name="file">The file that failed to load.</param>
     **************************************************************************************************/
    BitmapLoadFailureException(std::string file);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 6/12/2012.</remarks>
     **************************************************************************************************/
    virtual ~BitmapLoadFailureException();

    /**************************************************************************************************
     * <summary>Gets the message of the exception.</summary>
     * <remarks>Casey Ugone, 6/12/2012.</remarks>
     * <returns>The message.</returns>
     **************************************************************************************************/
    virtual std::string Message() const;
protected:
private:
    /// <summary> The file path and name </summary>
    std::string _file;
};

A2DE_END

#endif