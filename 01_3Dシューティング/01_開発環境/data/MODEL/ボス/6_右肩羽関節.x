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
 61;
 1.10811;14.49581;-0.00988;,
 0.78179;14.49582;0.77791;,
 0.98002;13.06679;0.97614;,
 1.38846;13.06679;-0.00989;,
 -0.00600;14.49581;1.10423;,
 -0.00600;13.06679;1.38456;,
 -0.79380;14.49582;0.77791;,
 -0.99203;13.06679;0.97614;,
 -1.12012;14.49581;-0.00988;,
 -1.40047;13.06679;-0.00989;,
 -0.79380;14.49582;-0.79769;,
 -0.99203;13.06679;-0.99592;,
 -0.00600;14.49581;-1.12400;,
 -0.00600;13.06679;-1.40434;,
 0.78179;14.49582;-0.79769;,
 0.98002;13.06679;-0.99592;,
 1.10811;14.49581;-0.00988;,
 1.38846;13.06679;-0.00989;,
 1.29124;10.67684;1.28736;,
 1.82858;10.67683;-0.00989;,
 -0.00600;10.67683;1.82470;,
 -1.30325;10.67683;1.28736;,
 -1.84058;10.67684;-0.00989;,
 -1.30325;10.67683;-1.30714;,
 -0.00600;10.67683;-1.84448;,
 1.29124;10.67684;-1.30714;,
 1.82858;10.67683;-0.00989;,
 0.98002;8.28683;0.97615;,
 1.38846;8.28681;-0.00988;,
 -0.00600;8.28682;1.38456;,
 -0.99203;8.28683;0.97615;,
 -1.40046;8.28682;-0.00988;,
 -0.99203;8.28684;-0.99592;,
 -0.00600;8.28682;-1.40435;,
 0.98002;8.28684;-0.99592;,
 1.38846;8.28681;-0.00988;,
 0.78179;6.85778;0.77791;,
 1.10811;6.85778;-0.00988;,
 -0.00601;6.85778;1.10423;,
 -0.79380;6.85776;0.77791;,
 -1.12012;6.85776;-0.00988;,
 -0.79380;6.85779;-0.79770;,
 -0.00601;6.85778;-1.12401;,
 0.78179;6.85779;-0.79770;,
 1.10811;6.85778;-0.00988;,
 -0.00600;21.24077;-0.00989;,
 -0.00600;21.24077;-0.00989;,
 -0.00600;21.24077;-0.00989;,
 -0.00600;21.24077;-0.00989;,
 -0.00600;21.24077;-0.00989;,
 -0.00600;21.24077;-0.00989;,
 -0.00600;21.24077;-0.00989;,
 -0.00600;21.24077;-0.00989;,
 -0.00601;0.11290;-0.00989;,
 -0.00601;0.11290;-0.00989;,
 -0.00601;0.11290;-0.00989;,
 -0.00601;0.11290;-0.00989;,
 -0.00601;0.11290;-0.00989;,
 -0.00601;0.11290;-0.00989;,
 -0.00601;0.11290;-0.00989;,
 -0.00601;0.11290;-0.00989;;
 
 48;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;3,2,18,19;,
 4;2,5,20,18;,
 4;5,7,21,20;,
 4;7,9,22,21;,
 4;9,11,23,22;,
 4;11,13,24,23;,
 4;13,15,25,24;,
 4;15,17,26,25;,
 4;19,18,27,28;,
 4;18,20,29,27;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;25,26,35,34;,
 4;28,27,36,37;,
 4;27,29,38,36;,
 4;29,30,39,38;,
 4;30,31,40,39;,
 4;31,32,41,40;,
 4;32,33,42,41;,
 4;33,34,43,42;,
 4;34,35,44,43;,
 3;45,1,0;,
 3;46,4,1;,
 3;47,6,4;,
 3;48,8,6;,
 3;49,10,8;,
 3;50,12,10;,
 3;51,14,12;,
 3;52,16,14;,
 3;53,37,36;,
 3;54,36,38;,
 3;55,38,39;,
 3;56,39,40;,
 3;57,40,41;,
 3;58,41,42;,
 3;59,42,43;,
 3;60,43,44;;
 
 MeshMaterialList {
  5;
  48;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.000000;0.800000;0.006400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data/TEXTURE/���b.png";
   }
  }
  Material {
   0.160000;0.160000;0.160000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data/TEXTURE/���b.png";
   }
  }
  Material {
   0.780800;0.800000;0.000000;0.700000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  48;
  0.697654;0.162969;0.697653;,
  0.984073;0.177764;0.000003;,
  0.695844;0.177763;0.695846;,
  0.000003;0.177762;0.984073;,
  -0.695842;0.177764;0.695848;,
  -0.984073;0.177765;0.000003;,
  -0.695842;0.177765;-0.695848;,
  0.000003;0.177763;-0.984073;,
  0.695843;0.177764;-0.695846;,
  0.982395;0.186814;0.000001;,
  0.694657;0.186813;0.694660;,
  0.000002;0.186813;0.982396;,
  -0.694656;0.186813;0.694661;,
  -0.982396;0.186813;0.000001;,
  -0.694656;0.186814;-0.694661;,
  0.000002;0.186814;-0.982395;,
  0.694657;0.186815;-0.694660;,
  1.000000;0.000002;0.000000;,
  0.707104;0.000003;0.707109;,
  0.000002;0.000002;1.000000;,
  -0.707106;0.000002;0.707108;,
  -1.000000;0.000001;0.000000;,
  -0.707107;0.000001;-0.707106;,
  0.000002;0.000002;-1.000000;,
  0.707106;0.000002;-0.707107;,
  0.982396;-0.186811;0.000002;,
  0.694655;-0.186811;0.694663;,
  0.000001;-0.186810;0.982396;,
  -0.694657;-0.186809;0.694661;,
  -0.982397;-0.186808;0.000001;,
  -0.694661;-0.186808;-0.694657;,
  0.000001;-0.186809;-0.982396;,
  0.694659;-0.186810;-0.694659;,
  0.984073;-0.177765;0.000004;,
  0.695841;-0.177765;0.695848;,
  -0.000001;-0.177763;0.984073;,
  -0.695843;-0.177761;0.695847;,
  -0.984074;-0.177761;0.000003;,
  -0.695846;-0.177761;-0.695844;,
  -0.000002;-0.177761;-0.984074;,
  0.695844;-0.177764;-0.695845;,
  0.697651;-0.162972;0.697655;,
  -0.697652;0.162970;0.697655;,
  -0.697651;0.162970;-0.697656;,
  0.697653;0.162969;-0.697654;,
  -0.697653;-0.162971;0.697654;,
  -0.697654;-0.162972;-0.697653;,
  0.697652;-0.162973;-0.697654;;
  48;
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;24,17,25,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,25,33,40;,
  3;0,2,1;,
  3;0,3,2;,
  3;42,4,3;,
  3;42,5,4;,
  3;43,6,5;,
  3;43,7,6;,
  3;44,8,7;,
  3;44,1,8;,
  3;41,33,34;,
  3;41,34,35;,
  3;45,35,36;,
  3;45,36,37;,
  3;46,37,38;,
  3;46,38,39;,
  3;47,39,40;,
  3;47,40,33;;
 }
 MeshTextureCoords {
  61;
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.500000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.000000;,
  0.625000;0.250000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.000000;,
  0.875000;0.250000;,
  1.000000;0.000000;,
  1.000000;0.250000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;1.000000;,
  0.375000;1.000000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.750000;1.000000;,
  0.875000;1.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}
