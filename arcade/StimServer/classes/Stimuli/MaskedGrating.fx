
//-------------------------------------------------------------------------
// File: MaskedGrating.fx
// -- Pixel Shader --
// grating -> sine or squarewave
// mask    -> circle or ellipse
// color   -> bw or full rgb
//-------------------------------------------------------------------------


cbuffer PS_ANIMATION : register (b1)
{
    float  numCycles : packoffset(c0.x); // pixels per frame -> nFrames * pixelsPerFrame
};

cbuffer PS_CONSTANT_BUFFER : register (b0)
{
    // position
    float2 center       : packoffset(c0.x); // (x,y) [pixels]
    float  width         : packoffset(c0.z);
    float  height        : packoffset(c0.w);   

    // mask parameters 
    float  mskWidth     : packoffset(c1.x); // param 1  radius (circle), width (ellipse) [pixels]
    float  mskHight     : packoffset(c1.y); // param 2, height (ellipse)                 [pixels]         
    float  mskAngle     : packoffset(c1.z); // param 3, angle  (ellipse)                 [degrees]

    // grating parameters
    float  cycle        : packoffset(c1.w); // param 4  spatial hz                       [pixels per cycle]
    float  direction    : packoffset(c2.x); // param 5  direction                        [degrees] 
    float  smoothR      : packoffset(c2.y); // param 6  smoothing parameter (squarewave) [r > 2] 
    float  phaseOffset  : packoffset(c2.z); // param 7  phase offset                     [degrees]
    
    // empty
    float dummy        : packoffset(c2.w); 
 
};

cbuffer PS_COLOR_BUFFER : register (b2)
{
    float4 color0	: packoffset(c0.x); // color 1
    float4 color1	: packoffset(c1.x); // color 2
    float4 color2	: packoffset(c2.x); // color 3 
    float4 color3	: packoffset(c3.x); // color 4
};


float4 PSmain( float4 Pos : SV_POSITION ) : SV_Target
{
    // define values 
    static const float pi = 3.141592654;

    float radix      = (mskWidth ? mskWidth: 100.0f);
    float radiy      = (mskHight ? mskHight: radix);
    float radius     = radix;

    // force to a minimum 2.0f = sinewave, values < 2.0f produce artifact
    float R = (smoothR ? smoothR: 2.0f);

    // determine mask 
    if (radix != radiy) 
    {
        // calculate the pixel angle instead of rotating object, rotate pixel 
        float pPhi = atan2((center.y-Pos.y)*-1.0f, center.x-Pos.x) - radians(mskAngle);
        // calculate the radius of the ellipse boundary for this angle 
        radius = (radix*radiy)/sqrt(pow(radiy*cos(pPhi),2) + pow(radix*sin(pPhi),2));
    }

    // discard pixel
    if (distance(center, Pos.xy) > radius) discard;
    
    // grating direction 
    float2 p;
    sincos(radians(-1.0f*direction), p.y, p.x);

    float pixelsPerCycle = (cycle ? cycle : 20.0f);

    
    // calculate sinewave 
    float sineWave = sin( radians(phaseOffset) + numCycles*2.0f*pi + dot(center-Pos.xy, p)*(2.0f*pi)/pixelsPerCycle );
    float bright   = (pow(abs(sineWave), 2.0f/R) * sign(sineWave) + 1.0f) / 2.0f;

    // if colored, implement color via alpha blending  
    return color0*(float4)(1.0f-bright) + color1*(float4)bright;
}
