#version 330

uniform struct LightInfo {
    vec4 position;
    vec3 intensity;
} light;

struct MaterialInfo
{
    vec3 ka;            // Ambient reflectivity
    vec3 kd;            // Diffuse reflectivity
    vec3 ks;            // Specular reflectivity
    float shininess;    // Specular shininess factor
};
uniform MaterialInfo material;

in vec3 position;
in vec3 normal;

layout (location = 0) out vec4 fragColor;


vec3 adsModel( const in vec3 pos, const in vec3 norm )
{
    // Calculate the vector from the light to the fragment
    vec3 s = normalize( vec3( light.position ) - vec3(0,0,0) );

    float fator = max( (dot(norm,s))/(length(s)) ,0.0);


    // Calculate the vector from the fragment to the eye position
    // (origin since this is in "eye" or "camera" space)
    vec3 v = normalize( -position.xyz );

    // Reflect the light beam using the normal at this fragment
    vec3 r = reflect( -s, norm );

    // Calculate the diffuse component
    float diffuse = fator;//max( dot( s, norm ), 0.0 );

    // Calculate the specular component
    float specular = 0.0;

 //calculo da contribuicao especular
    s = normalize(s);
    r = norm*(2*dot(s,norm)) - s;
    v = (v-pos)/length(v-pos);
    r = (r+v)/length(r+v);

    //float fator2 = fmax(pow((r*v),m->shininess*128),0);
    //if(r*n<0) fator2 = 0;
    //Vec4 especular;




    if ( dot( r, norm ) > 0.0 )
        specular = pow( max( dot( r, v ), 0.0 ), material.shininess );
    return 0.8 * ( material.ka + material.kd * diffuse + material.ks * specular );
}

void main()
{
    fragColor = vec4( adsModel( position, normalize( normal ) ), 1.0 );
}
