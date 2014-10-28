/**************************************************************************************************
// file:	Engine\Exceptions\CFileNotFoundException.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the file not found exception class
 **************************************************************************************************/
#ifndef A2DE_CFILENOTFOUNDEXCEPTION_H
#define A2DE_CFILENOTFOUNDEXCEPTION_H

#include "../a2de_vals.h"
#include "CException.h"

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Exception for signaling file not found errors.</summary>
 * <remarks>Casey Ugone, 7/30/2011.</remarks>
 * <seealso cref="Exception"/>
 **************************************************************************************************/
class FileNotFoundException : public Exception {
public:

    /**************************************************************************************************
     * <summary>Initializes a new instance of the FileNotFoundException class.</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     * <param name="file">The file.</param>
     **************************************************************************************************/
	FileNotFoundException(std::string file);

    /**************************************************************************************************
     * <summary>Destructor</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
     **************************************************************************************************/
	virtual ~FileNotFoundException();

    /**************************************************************************************************
     * <summary>Gets the message.</summary>
     * <remarks>Casey Ugone, 7/30/2011.</remarks>
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