#version 330

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords_vs;

uniform sampler2D uTexture;

uniform vec3 uKs;
uniform float uShininess;
uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;


out vec3 fFragColor;

vec3 blinnPhong(){
    vec3 wi = normalize(uLightDir_vs);
    vec3 w0 = (normalize(-1*vPosition_vs));
    vec3 halfVector = normalize((w0 + wi)/2.0);
    vec3 Li = uLightIntensity;
    vec3 N = normalize(vNormal_vs);

    float prod = dot(wi, N);
    if(prod < 0){
        prod = 0;
    }

    float prod2 = dot(halfVector, N);
    if(prod2 < 0){
        prod2 = 0;
    }

    return Li*((abs(vec3(texture(uTexture, vTexCoords_vs)))*prod)  + abs(uKs)*pow(prod2, uShininess));
}

void main() {
    fFragColor = blinnPhong();
}