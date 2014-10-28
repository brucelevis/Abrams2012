/**************************************************************************************************
// file:	Engine\Physics\IUpdatable.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the IUpdatable interface
 **************************************************************************************************/
#ifndef A2DE_IUPDATABLE_H
#define A2DE_IUPDATABLE_H


#include "../a2de_vals.h"

A2DE_BEGIN

class IUpdatable {
public:

    /**************************************************************************************************
     * <summary>Updates class given the deltaTime.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="deltaTime">Time since the last frame.</param>
     **************************************************************************************************/
    virtual void Update(double deltaTime)=0;
    virtual ~IUpdatable(){ /* DO NOTHING */ }
protected:
private:
    
};

A2DE_END

#endif // IUPDATABLE_H