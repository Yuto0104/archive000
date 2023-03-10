xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 34;
 1.90876;0.02018;-0.53749;,
 3.41678;0.02018;-0.91875;,
 3.41680;-0.89362;-0.00495;,
 1.90876;-0.51236;-0.00495;,
 3.41678;0.02018;0.90885;,
 1.90876;0.02018;0.52759;,
 3.41680;0.93398;-0.00495;,
 1.90876;0.55272;-0.00495;,
 3.41678;0.02018;-0.91875;,
 1.90876;0.02018;-0.53749;,
 4.97096;0.02018;-1.36221;,
 4.97095;-1.33708;-0.00495;,
 4.97096;0.02018;1.35232;,
 4.97096;1.37744;-0.00495;,
 4.97096;0.02018;-1.36221;,
 6.78991;0.02018;-0.90979;,
 6.78991;-0.88466;-0.00495;,
 6.78991;0.02018;0.89989;,
 6.78991;0.92502;-0.00495;,
 6.78991;0.02018;-0.90979;,
 8.60886;0.02018;-0.45737;,
 8.60886;-0.43224;-0.00495;,
 8.60886;0.02018;0.44747;,
 8.60886;0.47260;-0.00495;,
 8.60886;0.02018;-0.45737;,
 10.42782;0.02018;-0.00495;,
 10.42782;0.02018;-0.00495;,
 10.42782;0.02018;-0.00495;,
 10.42782;0.02018;-0.00495;,
 0.01644;0.02018;-0.00495;,
 1.90876;0.02018;-0.53749;,
 1.90876;-0.51236;-0.00495;,
 1.90876;0.02018;0.52759;,
 1.90876;0.55272;-0.00495;;
 
 24;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;1,10,11,2;,
 4;2,11,12,4;,
 4;4,12,13,6;,
 4;6,13,14,8;,
 4;10,15,16,11;,
 4;11,16,17,12;,
 4;12,17,18,13;,
 4;13,18,19,14;,
 4;15,20,21,16;,
 4;16,21,22,17;,
 4;17,22,23,18;,
 4;18,23,24,19;,
 3;20,25,21;,
 3;21,26,22;,
 3;22,27,23;,
 3;23,28,24;,
 3;29,30,31;,
 3;29,31,32;,
 3;29,32,33;,
 3;29,33,30;;
 
 MeshMaterialList {
  3;
  24;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.558431;0.558431;0.558431;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.310588;0.310588;0.310588;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  28;
  -0.185583;-0.694824;-0.694823;,
  -0.185583;-0.694824;0.694823;,
  -0.185583;0.694824;0.694823;,
  -0.186891;-0.694649;-0.694647;,
  -0.186892;-0.694649;0.694646;,
  -0.186892;0.694650;0.694646;,
  -0.012498;-0.707052;-0.707051;,
  -0.012498;-0.707053;0.707050;,
  -0.012497;0.707053;0.707050;,
  0.173217;-0.696418;-0.696418;,
  0.173218;-0.696419;0.696417;,
  0.173218;0.696418;0.696417;,
  0.173217;-0.696418;-0.696418;,
  0.173217;-0.696418;0.696418;,
  0.173217;0.696418;0.696418;,
  0.173216;-0.696418;-0.696418;,
  -0.195168;-0.693509;-0.693509;,
  -0.185583;0.694824;-0.694823;,
  -0.186891;0.694649;-0.694647;,
  -0.012497;0.707052;-0.707051;,
  0.173217;0.696418;-0.696418;,
  0.173217;0.696418;-0.696418;,
  0.173216;-0.696418;0.696418;,
  0.173216;0.696418;0.696418;,
  0.173216;0.696418;-0.696418;,
  -0.195168;-0.693509;0.693509;,
  -0.195168;0.693509;0.693509;,
  -0.195168;0.693509;-0.693509;;
  24;
  4;0,3,3,0;,
  4;1,4,4,1;,
  4;2,5,5,2;,
  4;17,18,18,17;,
  4;3,6,6,3;,
  4;4,7,7,4;,
  4;5,8,8,5;,
  4;18,19,19,18;,
  4;6,9,9,6;,
  4;7,10,10,7;,
  4;8,11,11,8;,
  4;19,20,20,19;,
  4;9,12,12,9;,
  4;10,13,13,10;,
  4;11,14,14,11;,
  4;20,21,21,20;,
  3;12,15,12;,
  3;13,22,13;,
  3;14,23,14;,
  3;21,24,21;,
  3;16,0,0;,
  3;25,1,1;,
  3;26,2,2;,
  3;27,17,17;;
 }
 MeshTextureCoords {
  34;
  0.000000;1.000000;,
  0.000000;0.800000;,
  0.250000;0.800000;,
  0.250000;1.000000;,
  0.500000;0.800000;,
  0.500000;1.000000;,
  0.750000;0.800000;,
  0.750000;1.000000;,
  1.000000;0.800000;,
  1.000000;1.000000;,
  0.000000;0.600000;,
  0.250000;0.600000;,
  0.500000;0.600000;,
  0.750000;0.600000;,
  1.000000;0.600000;,
  0.000000;0.400000;,
  0.250000;0.400000;,
  0.500000;0.400000;,
  0.750000;0.400000;,
  1.000000;0.400000;,
  0.000000;0.200000;,
  0.250000;0.200000;,
  0.500000;0.200000;,
  0.750000;0.200000;,
  1.000000;0.200000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}
