//test.shader

float lerp( float x, float y, float s ) 
{
	if ( s <= 0.0f ) {
		return x;
	}
	else if ( s >= 1.0f ) {
		return y;
	}

	return x + s * (y - x);
}


vec4 lerp( vec4 x, vec4 y, float s ) 
{
	if ( s <= 0.0f ) {
		return x;
	}
	else if ( s >= 1.0f ) {
		return y;
	}

	vec4 result = vec4(0.0f,0.0f,0.0f,0.0f);
	result.r = x.r + s * (y.r - x.r);
	result.g = x.g + s * (y.g - x.g);
	result.b = x.b + s * (y.b - x.b);
	result.a = x.a + s * (y.a - x.a);

	return result;
}

float saturate( float val ) 
{
	float result = clamp(val, 0.0, 1.0);
	return result;
}

vec2 saturate( vec2 val ) 
{
	vec2 result = clamp(val, 0.0, 1.0);
	return result;
}


vec3 saturate( vec3 val ) 
{
	vec3 result = clamp(val, 0.0, 1.0);
	return result;
}


vec4 saturate( vec4 val ) 
{
	vec4 result = clamp(val, 0.0, 1.0);
	return result;
}


vec4 Pixelate( sampler2D inImage )
{
	float progress = 0.2;

	vec2 uv = gl_TexCoord[0].xy;
	float pixels;
	float segment_progress;
	if (progress < 0.5)
	{
		segment_progress = 1.0 - progress * 2.0;
	}
	else
	{		
		segment_progress = (progress - 0.5) * 2.0;

	}
    
    pixels = 5.0 + 1000.0 * segment_progress * segment_progress;
	vec2 newUV = round(uv * pixels) / pixels;
	
    vec4 c1 = texture2D(inImage, newUV);
    vec4 c2 = texture2D(inImage, newUV); //this would be a secondary image here

	float lerp_progress = saturate((progress - 0.4) / 0.2);
	return lerp(c1,c1, lerp_progress);	
}


vec4 LightStreak( sampler2D inImage ) 
{
	float BrightThreshold  = 0.2;
	float Scale = 0.3;
	float Attenuation = 1.0;


	vec2 uv = gl_TexCoord[0].xy;

	vec2 Direction = vec2(1.0f, 1.0f);
    vec2 PixelSize = vec2(0.0009766f, 0.0013021f);
    int numSamples = 2;
    int Iteration = 1;

    vec4 pixelColor = texture2D(inImage, uv);
    vec4 bright = saturate((pixelColor - BrightThreshold) / (1.0 - BrightThreshold));

    pixelColor += bright;

    float weightIter = pow(numSamples, Iteration);
    
    for(int sample=0; sample<numSamples; sample++)
    {
        float weight = pow(Attenuation, weightIter * float(sample));
        vec2 texCoord = uv + (Direction * weightIter * vec2(float(sample), float(sample)) * PixelSize);
        pixelColor += saturate(weight) * texture2D(inImage,  texCoord);
    }
      
    return pixelColor * Scale;	
}


vec4 Ripple( sampler2D inImage )
{
	vec2 center  = vec2(0.5, 0.5);

	float amplitude  = 0.5;
	float frequency = 50.0;
	float phase = 0.0;

	vec2 uv = gl_TexCoord[0].xy;
	vec2 dir = uv - center;
   
	vec2 toPixel = uv - center; // vector from center to pixel
	float distance = length(toPixel);
	vec2 direction = toPixel/distance;
	float angle = atan(direction.x, direction.y);
	vec2 wave = vec2(sin(frequency * distance + phase),cos(frequency * distance + phase));
		
	float falloff = saturate(1.0-distance);
	falloff *= falloff;
		
	distance += amplitude * wave.x * falloff;
	direction.y = sin(angle);
	direction.x = cos(angle);
   vec2 uv2 = center + distance * direction;
   
   float lighting = saturate(wave.y * falloff) * 0.2 + 0.8;
   
   vec4 color = texture2D( inImage, uv2 );
   color.rgb *= lighting;
   
   return color;
}


vec4 Swirl( sampler2D inImage ) 
{
	vec2 center  = vec2(0.5, 0.5);
	float spiralStrength = 1.150;
	vec2 angleFrequency = vec2(1);

	vec2 uv = gl_TexCoord[0].xy;

	vec2 dir = uv - center;
   float l = length(dir);
   float angle = atan(dir.x,dir.y);
   
   float newAng = angle + spiralStrength * l;
   float xAmt = cos(angleFrequency.x * newAng) * l;
   float yAmt = sin(angleFrequency.y * newAng) * l;
   
   vec2 newCoord = center + vec2(xAmt, yAmt);
   
   return texture2D( inImage, newCoord );
}


vec4 Pinch( sampler2D inImage )
{
	float CenterX = 0.15;
	float CenterY = 0.15;
	float Radius = 0.525;
	float Amount = 5.0;

	vec2 uv = gl_TexCoord[0].xy;

	vec2 center = vec2( CenterX, CenterY );
    vec2 displace = center - uv;
    float range = saturate(1.0 - (length(displace) / (abs(-sin(Radius * 8.0) * Radius) + 0.00000001F)));
    return texture2D(inImage, uv + displace * range * Amount);
}

vec4 shaderMain( sampler2D inImage )
{
	
	return Pinch(inImage);	
}
