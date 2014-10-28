/**************************************************************************************************
// file:	Engine\Exceptions\CAudioNotAvailableException.h
// Allegro2DEngine
// Copyright (c) 2012 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for support.
// summary:	Declares the audio not available exception class
 **************************************************************************************************/
#ifndef A2DE_CAUDIONOTAVAILABLEEXCEPTION_H
#define A2DE_CAUDIONOTAVAILABLEEXCEPTION_H

#include "../a2de_vals.h"
#include "CException.h"

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Exception for signaling audio not available errors. </summary>
 * <remarks>Casey Ugone, 3/30/2012.</remarks>
 * <seealso cref="Exception"/>
 **************************************************************************************************/
class AudioNotAvailableException : public Exception {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 3/30/2012.</remarks>
     **************************************************************************************************/
    AudioNotAvailableException();

    /**************************************************************************************************
     * <summary>Destructor</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     **************************************************************************************************/
    virtual ~AudioNotAvailableException();

    /**************************************************************************************************
     * <summary>Gets the message.</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     * <returns>The message.</returns>
     **************************************************************************************************/
    virtual std::string Message() const;
protected:
private:

};

A2DE_END

#endif