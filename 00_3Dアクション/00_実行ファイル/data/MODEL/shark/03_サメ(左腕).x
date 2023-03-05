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
 53;
 0.00000;5.66567;0.63227;,
 4.59352;5.02168;0.45971;,
 4.59352;5.31045;-2.88134;,
 0.00000;6.05069;-3.82247;,
 4.59352;4.29833;-4.56850;,
 0.00000;4.70120;-6.07201;,
 4.59352;2.57824;-3.61344;,
 0.00002;2.40774;-4.79859;,
 4.59352;1.15778;-0.57562;,
 0.00000;0.51379;-0.74817;,
 4.59352;0.86903;2.76544;,
 0.00000;0.12878;3.70657;,
 4.59352;1.88114;4.45259;,
 0.00000;1.47827;5.95611;,
 4.59352;3.60123;3.49753;,
 0.00000;3.77173;4.68269;,
 4.59352;5.02168;0.45971;,
 0.00000;5.66567;0.63227;,
 12.09146;4.11930;1.25155;,
 12.79548;4.28691;-0.88291;,
 13.08713;3.60185;-1.96919;,
 12.79548;2.46543;-1.37097;,
 12.09146;1.54335;0.56133;,
 11.38739;1.37574;2.69579;,
 11.09577;2.06080;3.78207;,
 11.38739;3.19722;3.18385;,
 12.09146;4.11930;1.25155;,
 16.43409;2.98340;2.91485;,
 17.19183;3.01617;2.03808;,
 17.50564;2.65250;1.57383;,
 17.19183;2.10543;1.79405;,
 16.43409;1.69542;2.56974;,
 15.67639;1.66266;3.44649;,
 15.36252;2.02633;3.91074;,
 15.67639;2.57340;3.69053;,
 16.43409;2.98340;2.91485;,
 20.00392;1.65546;5.29483;,
 20.00392;1.65546;5.29483;,
 20.00392;1.65546;5.29483;,
 20.00392;1.65546;5.29483;,
 20.00392;1.65546;5.29483;,
 20.00392;1.65546;5.29483;,
 20.00392;1.65546;5.29483;,
 20.00392;1.65546;5.29483;,
 0.00000;3.08973;-0.05795;,
 0.00000;5.66567;0.63227;,
 0.00000;6.05069;-3.82247;,
 0.00000;4.70120;-6.07201;,
 0.00002;2.40774;-4.79859;,
 0.00000;0.51379;-0.74817;,
 0.00000;0.12878;3.70657;,
 0.00000;1.47827;5.95611;,
 0.00000;3.77173;4.68269;;
 
 40;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;9,8,10,11;,
 4;11,10,12,13;,
 4;13,12,14,15;,
 4;15,14,16,17;,
 4;1,18,19,2;,
 4;2,19,20,4;,
 4;4,20,21,6;,
 4;6,21,22,8;,
 4;8,22,23,10;,
 4;10,23,24,12;,
 4;12,24,25,14;,
 4;14,25,26,16;,
 4;18,27,28,19;,
 4;19,28,29,20;,
 4;20,29,30,21;,
 4;21,30,31,22;,
 4;22,31,32,23;,
 4;23,32,33,24;,
 4;24,33,34,25;,
 4;25,34,35,26;,
 3;27,36,28;,
 3;28,37,29;,
 3;29,38,30;,
 3;30,39,31;,
 3;31,40,32;,
 3;32,41,33;,
 3;33,42,34;,
 3;34,43,35;,
 3;44,45,46;,
 3;44,46,47;,
 3;44,47,48;,
 3;44,48,49;,
 3;44,49,50;,
 3;44,50,51;,
 3;44,51,52;,
 3;44,52,45;;
 
 MeshMaterialList {
  5;
  40;
  1,
  1,
  4,
  4,
  4,
  4,
  1,
  1,
  1,
  1,
  4,
  4,
  4,
  4,
  1,
  1,
  1,
  1,
  4,
  4,
  4,
  4,
  1,
  1,
  1,
  1,
  4,
  4,
  4,
  2,
  1,
  1,
  1,
  1,
  4,
  4,
  4,
  4,
  1,
  1;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.194510;0.304314;0.461176;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
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
    "C:\\Users\\student\\Desktop\\3D表\現技術(後期)\\作品\\Ver.1.1(試作3号)\\data\\TEXTURE\\口.png";
   }
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
  0.143636;0.955910;0.256135;,
  0.198603;0.955587;-0.217739;,
  0.236667;0.833170;-0.499816;,
  0.198602;-0.718693;-0.666361;,
  0.143635;-0.955910;-0.256135;,
  0.198602;-0.955587;0.217739;,
  0.236667;-0.833171;0.499815;,
  0.198603;0.718694;0.666361;,
  0.115080;0.957781;0.263461;,
  0.184905;0.959661;-0.211802;,
  0.229444;0.838330;-0.494528;,
  0.184905;-0.725190;-0.663257;,
  0.115080;-0.961193;-0.250727;,
  0.136143;-0.963741;0.229495;,
  0.154992;-0.842269;0.516295;,
  0.136144;0.719877;0.680618;,
  0.103644;0.949473;0.296241;,
  0.256864;0.953944;-0.154955;,
  0.347690;0.835097;-0.426292;,
  0.256864;-0.748663;-0.611167;,
  0.103645;-0.970388;-0.218184;,
  0.041829;-0.964543;0.260589;,
  0.017830;-0.837204;0.546601;,
  0.041828;0.705025;0.707948;,
  0.116272;0.934513;0.336402;,
  0.384023;0.922161;-0.046328;,
  0.537679;0.796023;-0.277936;,
  0.384022;-0.775451;-0.501201;,
  0.116272;-0.977513;-0.175923;,
  -0.049271;-0.962681;0.266115;,
  -0.127730;-0.834022;0.536743;,
  -0.049271;0.700648;0.711804;,
  0.296463;0.938300;0.178051;,
  -1.000000;-0.000001;-0.000001;,
  0.236667;-0.471640;-0.849438;,
  0.229443;-0.478752;-0.847439;,
  0.236667;0.471639;0.849438;,
  0.154992;0.471279;0.868259;,
  0.347689;-0.510071;-0.786727;,
  0.017830;0.451738;0.891972;,
  0.537676;-0.550413;-0.638710;,
  -0.127733;0.453906;0.881847;,
  0.177470;-0.978191;-0.107916;,
  -0.217686;0.469359;0.855754;,
  -1.000000;0.000000;0.000000;,
  -1.000000;-0.000005;-0.000001;,
  -1.000000;-0.000004;-0.000003;,
  -1.000000;0.000001;-0.000002;;
  40;
  4;0,8,9,1;,
  4;1,9,10,2;,
  4;34,35,11,3;,
  4;3,11,12,4;,
  4;4,12,13,5;,
  4;5,13,14,6;,
  4;36,37,15,7;,
  4;7,15,8,0;,
  4;8,16,17,9;,
  4;9,17,18,10;,
  4;35,38,19,11;,
  4;11,19,20,12;,
  4;12,20,21,13;,
  4;13,21,22,14;,
  4;37,39,23,15;,
  4;15,23,16,8;,
  4;16,24,25,17;,
  4;17,25,26,18;,
  4;38,40,27,19;,
  4;19,27,28,20;,
  4;20,28,29,21;,
  4;21,29,30,22;,
  4;39,41,31,23;,
  4;23,31,24,16;,
  3;24,32,25;,
  3;25,32,26;,
  3;40,42,27;,
  3;27,42,28;,
  3;28,42,29;,
  3;29,42,30;,
  3;41,43,31;,
  3;31,32,24;,
  3;33,44,44;,
  3;33,44,45;,
  3;33,45,46;,
  3;33,46,47;,
  3;33,47,44;,
  3;33,44,44;,
  3;33,44,44;,
  3;33,44,44;;
 }
 MeshTextureCoords {
  53;
  0.000000;1.000000;,
  0.000000;0.750000;,
  0.125000;0.750000;,
  0.125000;1.000000;,
  0.250000;0.750000;,
  0.250000;1.000000;,
  0.375000;0.750000;,
  0.375000;1.000000;,
  0.500000;0.750000;,
  0.500000;1.000000;,
  0.625000;0.750000;,
  0.625000;1.000000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  0.875000;0.750000;,
  0.875000;1.000000;,
  1.000000;0.750000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  0.125000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.250000;,
  0.125000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.062500;0.000000;,
  0.125000;0.000000;,
  0.187500;0.000000;,
  0.250000;0.000000;,
  0.312500;0.000000;,
  0.375000;0.000000;,
  0.437500;0.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}
