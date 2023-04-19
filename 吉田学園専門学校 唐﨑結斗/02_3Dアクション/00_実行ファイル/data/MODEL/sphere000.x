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
 54;
 0.00000;1.00000;0.00000;,
 0.43301;0.86603;-0.25000;,
 0.00000;0.86603;-0.50000;,
 0.00000;1.00000;0.00000;,
 0.43301;0.86603;0.25000;,
 0.00000;1.00000;0.00000;,
 -0.00000;0.86603;0.50000;,
 0.00000;1.00000;0.00000;,
 -0.43301;0.86603;0.25000;,
 0.00000;1.00000;0.00000;,
 -0.43301;0.86603;-0.25000;,
 0.00000;1.00000;0.00000;,
 0.00000;0.86603;-0.50000;,
 0.75000;0.50000;-0.43301;,
 0.00000;0.50000;-0.86603;,
 0.75000;0.50000;0.43301;,
 -0.00000;0.50000;0.86603;,
 -0.75000;0.50000;0.43301;,
 -0.75000;0.50000;-0.43301;,
 0.00000;0.50000;-0.86603;,
 0.86603;-0.00000;-0.50000;,
 0.00000;-0.00000;-1.00000;,
 0.86603;-0.00000;0.50000;,
 -0.00000;-0.00000;1.00000;,
 -0.86603;-0.00000;0.50000;,
 -0.86603;-0.00000;-0.50000;,
 0.00000;-0.00000;-1.00000;,
 0.75000;-0.50000;-0.43301;,
 0.00000;-0.50000;-0.86603;,
 0.75000;-0.50000;0.43301;,
 -0.00000;-0.50000;0.86603;,
 -0.75000;-0.50000;0.43301;,
 -0.75000;-0.50000;-0.43301;,
 0.00000;-0.50000;-0.86603;,
 0.43301;-0.86603;-0.25000;,
 0.00000;-0.86603;-0.50000;,
 0.43301;-0.86603;0.25000;,
 -0.00000;-0.86603;0.50000;,
 -0.43301;-0.86603;0.25000;,
 -0.43301;-0.86603;-0.25000;,
 0.00000;-0.86603;-0.50000;,
 0.00000;-0.86603;-0.50000;,
 0.43301;-0.86603;-0.25000;,
 0.00000;-1.00000;-0.00000;,
 0.43301;-0.86603;0.25000;,
 0.00000;-1.00000;-0.00000;,
 -0.00000;-0.86603;0.50000;,
 0.00000;-1.00000;-0.00000;,
 -0.43301;-0.86603;0.25000;,
 0.00000;-1.00000;-0.00000;,
 -0.43301;-0.86603;-0.25000;,
 0.00000;-1.00000;-0.00000;,
 0.00000;-0.86603;-0.50000;,
 0.00000;-1.00000;-0.00000;;
 
 36;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 4;2,1,13,14;,
 4;1,4,15,13;,
 4;4,6,16,15;,
 4;6,8,17,16;,
 4;8,10,18,17;,
 4;10,12,19,18;,
 4;14,13,20,21;,
 4;13,15,22,20;,
 4;15,16,23,22;,
 4;16,17,24,23;,
 4;17,18,25,24;,
 4;18,19,26,25;,
 4;21,20,27,28;,
 4;20,22,29,27;,
 4;22,23,30,29;,
 4;23,24,31,30;,
 4;24,25,32,31;,
 4;25,26,33,32;,
 4;28,27,34,35;,
 4;27,29,36,34;,
 4;29,30,37,36;,
 4;30,31,38,37;,
 4;31,32,39,38;,
 4;32,33,40,39;,
 3;41,42,43;,
 3;42,44,45;,
 3;44,46,47;,
 3;46,48,49;,
 3;48,50,51;,
 3;50,52,53;;
 
 MeshMaterialList {
  1;
  36;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  32;
  -0.000000;1.000000;0.000000;,
  -0.000000;0.870413;-0.492322;,
  0.426363;0.870413;-0.246161;,
  0.426363;0.870413;0.246161;,
  -0.000000;0.870413;0.492322;,
  -0.426363;0.870413;0.246161;,
  -0.426363;0.870413;-0.246161;,
  -0.000000;0.506749;-0.862093;,
  0.746595;0.506749;-0.431047;,
  0.746595;0.506749;0.431047;,
  -0.000000;0.506749;0.862093;,
  -0.746595;0.506749;0.431047;,
  -0.746595;0.506749;-0.431047;,
  -0.000000;-0.000000;-1.000000;,
  0.866025;-0.000000;-0.500000;,
  0.866025;-0.000000;0.500000;,
  -0.000000;-0.000000;1.000000;,
  -0.866025;-0.000000;0.500000;,
  -0.866025;-0.000000;-0.500000;,
  -0.000000;-0.506749;-0.862093;,
  0.746595;-0.506749;-0.431047;,
  0.746595;-0.506749;0.431047;,
  -0.000000;-0.506749;0.862093;,
  -0.746595;-0.506749;0.431047;,
  -0.746595;-0.506749;-0.431047;,
  -0.000000;-0.870413;-0.492322;,
  0.426363;-0.870413;-0.246161;,
  0.426363;-0.870413;0.246161;,
  -0.000000;-0.870413;0.492322;,
  -0.426363;-0.870413;0.246161;,
  -0.426363;-0.870413;-0.246161;,
  -0.000000;-1.000000;-0.000000;;
  36;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,1,6;,
  4;1,2,8,7;,
  4;2,3,9,8;,
  4;3,4,10,9;,
  4;4,5,11,10;,
  4;5,6,12,11;,
  4;6,1,7,12;,
  4;7,8,14,13;,
  4;8,9,15,14;,
  4;9,10,16,15;,
  4;10,11,17,16;,
  4;11,12,18,17;,
  4;12,7,13,18;,
  4;13,14,20,19;,
  4;14,15,21,20;,
  4;15,16,22,21;,
  4;16,17,23,22;,
  4;17,18,24,23;,
  4;18,13,19,24;,
  4;19,20,26,25;,
  4;20,21,27,26;,
  4;21,22,28,27;,
  4;22,23,29,28;,
  4;23,24,30,29;,
  4;24,19,25,30;,
  3;25,26,31;,
  3;26,27,31;,
  3;27,28,31;,
  3;28,29,31;,
  3;29,30,31;,
  3;30,25,31;;
 }
 MeshTextureCoords {
  54;
  0.083333;0.000000;,
  0.166667;0.166667;,
  0.000000;0.166667;,
  0.250000;0.000000;,
  0.333333;0.166667;,
  0.416667;0.000000;,
  0.500000;0.166667;,
  0.583333;0.000000;,
  0.666667;0.166667;,
  0.750000;0.000000;,
  0.833333;0.166667;,
  0.916667;0.000000;,
  1.000000;0.166667;,
  0.166667;0.333333;,
  0.000000;0.333333;,
  0.333333;0.333333;,
  0.500000;0.333333;,
  0.666667;0.333333;,
  0.833333;0.333333;,
  1.000000;0.333333;,
  0.166667;0.500000;,
  0.000000;0.500000;,
  0.333333;0.500000;,
  0.500000;0.500000;,
  0.666667;0.500000;,
  0.833333;0.500000;,
  1.000000;0.500000;,
  0.166667;0.666667;,
  0.000000;0.666667;,
  0.333333;0.666667;,
  0.500000;0.666667;,
  0.666667;0.666667;,
  0.833333;0.666667;,
  1.000000;0.666667;,
  0.166667;0.833333;,
  0.000000;0.833333;,
  0.333333;0.833333;,
  0.500000;0.833333;,
  0.666667;0.833333;,
  0.833333;0.833333;,
  1.000000;0.833333;,
  0.000000;0.833333;,
  0.166667;0.833333;,
  0.083333;1.000000;,
  0.333333;0.833333;,
  0.250000;1.000000;,
  0.500000;0.833333;,
  0.416667;1.000000;,
  0.666667;0.833333;,
  0.583333;1.000000;,
  0.833333;0.833333;,
  0.750000;1.000000;,
  1.000000;0.833333;,
  0.916667;1.000000;;
 }
}
