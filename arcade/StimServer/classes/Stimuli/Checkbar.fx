//-------------------------------------------------------------------------
// File: Checkbar.fx
// Pixel Shader
//-------------------------------------------------------------------------

cbuffer PS_ANIMATION : register (b1)
{
    float  numCycles : packoffset(c0.x);
};


cbuffer PS_CONSTANT_BUFFER : register (b0)
{
    float2  center        : packoffset(c0.x);
    float   width         : packoffset(c0.z);
    float   height        : packoffset(c0.w);    

    // Checkbar parameters
    float   barWidth   : packoffset(c1.x);  //para 1  pixels
    float   barHeight  : packoffset(c1.y);  //para 2  pixels  
    float   barAngle   : packoffset(c1.z);  //para 3  angle
    float   smoothR    : packoffset(c2.y);  //para 6  smoothing para    
};

cbuffer PS_COLOR_BUFFER : register (b2)
{
    float4 color0   : packoffset(c0.x); 
    float4 color1   : packoffset(c1.x);
    float4 color2   : packoffset(c2.x); // dummy color 3 
    float4 color3   : packoffset(c3.x); // dummy color 4 

};


float4 PSmain( float4 Pos : SV_POSITION ) : SV_Target
{   
    static const float pi = 3.141592654;
    //Bar direction
    float2 xp;  //x positive unit vector after rotation
    float2 yp;  //y positive unit vector after rotation
    sincos(radians(-1.0*barAngle), xp.y, xp.x);
    sincos(radians(-1.0*barAngle-90.0f),yp.y,yp.x);
    
    // Calculate checkbar
    float pixWidth  = dot(Pos.xy-center, xp);  //width of current pix
    float pixHeight = dot(Pos.xy-center, yp);  //height of current pix
    float4 color;

    if (pixWidth> 0) {
        if (sin(numCycles*2.0f*pi)>0) {
        color = color0;
        } else {
        color = color1;
        }
    } else {
        if (sin(numCycles*2.0f*pi)>0) {
        color = color1;
        } else {
        color = color0;
        }
    }

    if (abs(pixWidth) > barWidth/2.0f || abs(pixHeight) > barHeight/2.0f ) {
        color = float4(0,0,0,0);
    }
    
    return color;
}