//==================================================================================================
//  File Name:
//      rgba.hpp
//
//  Product:
//      BerlinUhr
//
//  Interface Header:
//
//
//  Authors:
//
//
//  Copyright Notice:
//
//==================================================================================================
//
#ifndef RGBA_HPP_DEFINED
#define RGBA_HPP_DEFINED

//--------------------------------------------------------------------------------------------------
//  Class:
//      Rgba
//
//  Summary:
//      Represents an RGBA color value.
//
//
//  Remarks:
//      This class represents a 32-bit RGBA color value, where each channel is represented by an
//      unsigned 8-bt integer.
//
//  See Also:
//--------------------------------------------------------------------------------------------------
//
class Rgba
{
  public:
    union
    {
        unsigned int      mColor;

        struct
        {
            unsigned char  mBlue;
            unsigned char  mGreen;
            unsigned char  mRed;
            unsigned char  mAlpha;
        };
    };

  public:
    Rgba();
    Rgba(Rgba const& vSrc);
    Rgba(unsigned int vAlpha);
    Rgba(unsigned int vRed, unsigned int vGreen, unsigned int vBlue, unsigned int vAlpha);

    Rgba&  operator =(Rgba const& vRhs);
    bool   operator ==(Rgba const& vRhs) const;

    int   Alpha() const;
    int   Blue() const;
    unsigned int  Color() const;
    int   Green() const;
    int   Red() const;

    void    SetAlpha(unsigned int vAlpha);
    void    SetBlue(unsigned int vBlue);
    void    SetColor(unsigned int vColor);
    void    SetColor(unsigned int vRed, unsigned int vGreen, unsigned int vBlue, unsigned int vAlpha);
    void    SetGreen(unsigned int vGreen);
    void    SetRed(unsigned int vRed);
};


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      Rgba()
//
//  Summary:
//      Public constructors.
//
//
//  Parameters:
//      vSrc -
//          [in] Another Rgba object from which the target will be copy-constructed.
//      vColor -
//          [in] A 32-bit color value that specifies all 4 channels in one integer.
//      vRed -
//          [in] An 8-bit color value for the red channel.
//      vGreen -
//          [in] An 8-bit color value for the green channel.
//      vBlue -
//          [in] An 8-bit color value for the blue channel.
//      vAlpha -
//          [in] An 8-bit color value for the alpha channel.
//
//  Remarks:
//      The first two forms implement canonical default-construction and copy-construction.  The
//      third form implements contruction from a single overall color value.  The fourth form
//      provides for the individual specification of each color channel.
//
//  See Also:
//      operator=
//--------------------------------------------------------------------------------------------------
//
inline
Rgba::Rgba()
  : mColor(0)
{}


inline
Rgba::Rgba(Rgba const& vSrc)
  : mColor(vSrc.mColor)
{}


inline
Rgba::Rgba(unsigned int vColor)
  : mColor(vColor)
{}


inline
Rgba::Rgba(unsigned int vRed, unsigned int vGreen, unsigned int vBlue, unsigned int vAlpha = 255)
  : mBlue((unsigned char) vBlue),
    mGreen((unsigned char) vGreen),
    mRed((unsigned char) vRed),
    mAlpha((unsigned char) vAlpha)
{}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      operator =()
//
//  Summary:
//      Public assignment operator.
//
//
//  Parameters:
//      vRhs -
//          [in] Another Rgba from which the target will be copy-assigned.
//
//  Remarks:
//      This form implements canonical copy-assignment semantics.
//
//--------------------------------------------------------------------------------------------------
//
inline Rgba&
Rgba::operator =(Rgba const& vRhs)
{
    mColor = vRhs.mColor;
    return *this;
}


inline bool
Rgba::operator ==(Rgba const& vRhs) const
{
    return (mBlue == vRhs.mBlue && mGreen == vRhs.mGreen && mRed == vRhs.mRed &&
                mAlpha == vRhs.mAlpha);
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      Alpha()
//
//  Summary:
//      Returns the intensity of the Alpha channel.
//
//
//  Returns:
//      The value of the Alpha channel, as a signed integer whose value can be from 0 to 255,
//      inclusive.
//
//  See Also:
//      Blue, Color, Green, Red
//--------------------------------------------------------------------------------------------------
//
inline int
Rgba::Alpha() const
{
    return mAlpha;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      Blue()
//
//  Summary:
//      Returns the intensity of the Blue channel.
//
//
//  Returns:
//      The value of the Blue channel, as a signed integer whose value can be from 0 to 255,
//      inclusive.
//
//--------------------------------------------------------------------------------------------------
//
inline int
Rgba::Blue() const
{
    return mBlue;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      Color()
//
//  Summary:
//      Returns the combined color value.
//
//  Returns:
//      The combined color value represented by the target, as a 32-bit unsigned integer.
//
//  See Also:
//      Alpha, Blue, Green, Red
//--------------------------------------------------------------------------------------------------
//
inline unsigned int
Rgba::Color() const
{
    return mColor;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      Green()
//
//  Summary:
//      Returns the intensity of the Green channel.
//
//  Returns:
//      The value of the Green channel, as a signed integer whose value can be from 0 to 255,
//      inclusive.
//
//--------------------------------------------------------------------------------------------------
//
inline int
Rgba::Green() const
{
    return mGreen;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      Red()
//
//  Summary:
//      Returns the intensity of the Red channel.
//
//
//  Returns:
//      The value of the Red channel, as a signed integer whose value can be from 0 to 255,
//      inclusive.
//
//--------------------------------------------------------------------------------------------------
//
inline int
Rgba::Red() const
{
    return mRed;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      SetAlpha()
//
//  Summary:
//      Sets the intensity of the Alpha channel.
//
//
//  Parameters:
//      vAlpha -
//          [i] The new value for the Alpha channel; values greater than 255 will be trucated
//
//--------------------------------------------------------------------------------------------------
//
inline void
Rgba::SetAlpha(unsigned int vAlpha)
{
    mAlpha = (unsigned char) vAlpha;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      SetBlue()
//
//  Summary:
//      Sets the intensity of the Blue channel.
//
//
//  Parameters:
//      vBlue -
//          [i] The new value for the Blue channel; values greater than 255 will be trucated
//
//--------------------------------------------------------------------------------------------------
//
inline void
Rgba::SetBlue(unsigned int vBlue)
{
    mBlue = (unsigned char) vBlue;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      SetColor()
//
//  Summary:
//      Sets the overall color value.
//
//
//  Parameters:
//      vColor -
//          [in] A 32-bit color value that specifies all 4 channels in one integer.
//      vRed -
//          [in] An 8-bit color value for the red channel.
//      vGreen -
//          [in] An 8-bit color value for the green channel.
//      vBlue -
//          [in] An 8-bit color value for the blue channel.
//      vAlpha -
//          [in] An 8-bit color value for the alpha channel.
//
//--------------------------------------------------------------------------------------------------
//
inline void
Rgba::SetColor(unsigned int vColor)
{
    mColor = vColor;
}


inline void
Rgba::SetColor(unsigned int vRed, unsigned int vGreen, unsigned int vBlue, unsigned int vAlpha)
{
    mBlue  = (unsigned char) vBlue;
    mGreen = (unsigned char) vGreen;
    mRed   = (unsigned char) vRed;
    mAlpha = (unsigned char) vAlpha;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      SetGreen()
//
//  Summary:
//      Sets the intensity of the Green channel.
//
//
//  Parameters:
//      vGreen -
//          [i] The new value for the Green channel; values greater than 255 will be trucated
//
//--------------------------------------------------------------------------------------------------
//
inline void
Rgba::SetGreen(unsigned int vGreen)
{
    mGreen = (unsigned char) vGreen;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      SetRed()
//
//  Summary:
//      Sets the intensity of the Red channel.
//
//
//  Parameters:
//      vRed -
//          [i] The new value for the Red channel; values greater than 255 will be trucated
//
//--------------------------------------------------------------------------------------------------
//
inline void
Rgba::SetRed(unsigned int vRed)
{
    mRed = (unsigned char) vRed;
}


#endif  //- RGBA_HPP_DEFINED
