#version 330

in vec2 vTexCoords;

uniform sampler2D uTexture;

out vec4 fFragColor;

void main() {

    fFragColor = vec4(0.0, 1.0, 0.0, 1.0);
    //fFragColor = texture(uTexture, vTexCoords);

    //gl_FragColor = texture2D(uTexture, vTexCoords);
}
