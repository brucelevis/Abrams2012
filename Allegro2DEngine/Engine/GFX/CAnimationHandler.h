/**************************************************************************************************
// file:	Engine\GFX\CAnimationHandler.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the animation handler class
 **************************************************************************************************/
#ifndef A2DE_CANIMATIONHANDLER_H
#define A2DE_CANIMATIONHANDLER_H

#include "../a2de_vals.h"
#include <map>
#include <utility>
#include <string>
#include <vector>

#include "CAnimationFrame.h"
#include "CAnimationFrameSet.h"

A2DE_BEGIN

class Sprite;
class AnimatedSprite;

class AnimationHandler {
public:

    /**************************************************************************************************
     * <summary>Defines an alias representing the animation map.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    typedef std::map<std::string, AnimationFrameSet> AnimMap;

    /**************************************************************************************************
     * <summary>Defines an alias representing the animation map iterator. .</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    typedef AnimMap::iterator AnimMapIter;

    /**************************************************************************************************
     * <summary>Defines an alias representing the animation map constant iterator. .</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    typedef AnimMap::const_iterator AnimMapConstIter;

    /**************************************************************************************************
     * <summary>Values that represent the playing direction of the animation. </summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    enum DIRECTION {
        /// <summary>Play forward with no looping, stopping at the last frame.</summary>
        DIR_FORWARD_NONLOOPING,
        /// <summary>Play forward with looping.</summary>
        DIR_FORWARD_LOOPING,
        /// <summary>Play in reverse with no looping, stoping at the last frame.</summary>
        DIR_REVERSE_NONLOOPING,
        /// <summary>Play in reverse with with looping.</summary>
        DIR_REVERSE_LOOPING,
    };

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="source">Source for the.</param>
     **************************************************************************************************/
    AnimationHandler(const Sprite& source);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    AnimationHandler(const AnimationHandler& other);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    ~AnimationHandler();

    /**************************************************************************************************
     * <summary>Adds an animation. </summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="name">The name.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool AddAnimation(const std::string& name);

    /**************************************************************************************************
     * <summary>Adds an animation to 'frames'.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="name">  The name.</param>
     * <param name="frames">The frames.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool AddAnimation(const std::string& name, const AnimationFrameSet& frames);

    /**************************************************************************************************
     * <summary>Removes the animation described by name.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="name">The name.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool RemoveAnimation(const std::string& name);
    
    /**************************************************************************************************
     * <summary>Gets an iterator that points to the first animation set.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <returns>A valid iterator or an iterator pointing one past the end of the set.</returns>
     **************************************************************************************************/
    AnimMapIter Begin();

    /**************************************************************************************************
     * <summary>Gets an iterator that points one past the end of the set.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <returns>An iterator pointing one past the end of the set.</returns>
     **************************************************************************************************/
    AnimMapIter End();

    /**************************************************************************************************
     * <summary>Gets a frame set.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="name">The name.</param>
     * <returns>The frame set.</returns>
     **************************************************************************************************/
    const a2de::AnimationFrameSet& GetFrameSetByName(const std::string& name) const;

    /**************************************************************************************************
     * <summary>Gets a frame set.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="name">The name.</param>
     * <returns>The frame set.</returns>
     **************************************************************************************************/
    a2de::AnimationFrameSet& GetFrameSetByName(const std::string& name);

    /**************************************************************************************************
     * <summary>Sizes.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="name">The name.</param>
     * <returns>.</returns>
     **************************************************************************************************/
    std::size_t Size(const std::string& name) const;

    /**************************************************************************************************
     * <summary>Sizes.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="name">The name.</param>
     * <returns>.</returns>
     **************************************************************************************************/
    std::size_t Size(const std::string& name);

    /**************************************************************************************************
     * <summary>Gets the size.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>.</returns>
     **************************************************************************************************/
    std::size_t Size() const;

    /**************************************************************************************************
     * <summary>Gets the size.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>.</returns>
     **************************************************************************************************/
    std::size_t Size();

    /**************************************************************************************************
     * <summary>Query if this object is empty.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>true if empty, false if not.</returns>
     **************************************************************************************************/
    bool IsEmpty() const;

    /**************************************************************************************************
     * <summary>Query if this object is empty.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>true if empty, false if not.</returns>
     **************************************************************************************************/
    bool IsEmpty();

    /**************************************************************************************************
     * <summary>Plays.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="name">              The name.</param>
     * <param name="rewindOnCompletion">true to rewind on completion.</param>
     **************************************************************************************************/
    void Play(const std::string& name, bool rewindOnCompletion);

    /**************************************************************************************************
     * <summary>Reverses.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="name">              The name.</param>
     * <param name="rewindOnCompletion">true to rewind on completion.</param>
     **************************************************************************************************/
    void Reverse(const std::string& name, bool rewindOnCompletion);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    AnimationHandler& operator=(const AnimationHandler& rhs);
    
protected:

    /**************************************************************************************************
     * <summary>Animates.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="name">The name.</param>
     * <param name="dir"> The dir.</param>
     **************************************************************************************************/
    void Animate(const std::string& name, AnimationHandler::DIRECTION dir);

    void CopyCurrentFrameToImageFrame(AnimMapIter _iter);

private:
    /// <summary> The animations </summary>
    std::map<std::string, AnimationFrameSet> _animations;
    /// <summary> The current set </summary>
    std::map<std::string, AnimationFrameSet>::iterator _curSet;
    /// <summary> The observed </summary>
    Sprite* _observed;
    /// <summary> The current name </summary>
    std::string _curName;
};

A2DE_END

#endif