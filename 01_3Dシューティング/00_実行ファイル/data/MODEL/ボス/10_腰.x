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
 288;
 -5.74865;-38.58485;5.54773;,
 -3.89021;-38.58485;6.72952;,
 -3.89021;-37.19921;6.72952;,
 -5.74865;-37.19921;5.54773;,
 -1.94511;-38.58485;7.52336;,
 -1.94511;-37.19921;7.52336;,
 0.00000;-38.58485;7.75538;,
 0.00000;-37.19921;7.75538;,
 1.94511;-38.58485;7.52336;,
 1.94511;-37.19921;7.52336;,
 3.89021;-38.58485;6.72952;,
 3.89021;-37.19921;6.72952;,
 5.74865;-38.58485;5.54773;,
 5.74865;-37.19921;5.54773;,
 -5.54324;-34.52438;9.63813;,
 -8.19137;-34.52438;7.95417;,
 -2.77162;-34.52438;10.76929;,
 0.00000;-34.52438;11.09991;,
 2.77162;-34.52438;10.76929;,
 5.54324;-34.52438;9.63813;,
 8.19137;-34.52438;7.95417;,
 -8.01775;-28.69972;13.99219;,
 -11.84800;-28.69972;11.55650;,
 -4.00888;-28.69972;15.62828;,
 0.00000;-28.69972;16.10654;,
 4.00888;-28.69972;15.62828;,
 8.01775;-28.69972;13.99219;,
 11.84800;-28.69972;11.55650;,
 -9.88615;-24.23285;17.27972;,
 -14.60898;-24.23283;14.27645;,
 -4.94307;-24.23285;19.29709;,
 0.00000;-24.23283;19.88682;,
 4.94307;-24.23285;19.29709;,
 9.88615;-24.23285;17.27972;,
 14.60898;-24.23283;14.27645;,
 -10.49589;-20.71047;18.35262;,
 -15.50999;-20.71047;15.16412;,
 -5.24795;-20.71047;20.49440;,
 0.00000;-20.71047;21.12050;,
 5.24795;-20.71047;20.49440;,
 10.49589;-20.71047;18.35262;,
 15.50999;-20.71047;15.16412;,
 -11.77167;-13.77159;20.59746;,
 -17.39525;-13.77159;17.02134;,
 -5.88584;-13.77159;22.99956;,
 0.00000;-13.77159;23.70176;,
 5.88584;-13.77159;22.99956;,
 11.77167;-13.77159;20.59746;,
 17.39525;-13.77159;17.02134;,
 5.74865;-38.58485;5.54773;,
 6.87930;-38.58485;3.73606;,
 6.87930;-37.19921;3.73605;,
 5.74865;-37.19921;5.54773;,
 7.52547;-38.58485;1.81024;,
 7.52547;-37.19921;1.81024;,
 7.83180;-38.58485;-0.11555;,
 7.83180;-37.19921;-0.11556;,
 7.52547;-38.58485;-2.04136;,
 7.52547;-37.19921;-2.04136;,
 6.87930;-38.58485;-3.96717;,
 6.87930;-37.19921;-3.96717;,
 5.74865;-38.58485;-5.77883;,
 5.74865;-37.19921;-5.77883;,
 9.80244;-34.52438;5.37268;,
 8.19137;-34.52438;7.95417;,
 10.72318;-34.52438;2.62856;,
 11.15969;-34.52438;-0.11556;,
 10.72318;-34.52438;-2.85967;,
 9.80244;-34.52438;-5.60379;,
 8.19137;-34.52438;-8.18527;,
 14.17828;-28.69972;7.82263;,
 11.84800;-28.69972;11.55650;,
 15.51002;-28.69972;3.85354;,
 16.14137;-28.69972;-0.11555;,
 15.51002;-28.69972;-4.08464;,
 14.17828;-28.69972;-8.05373;,
 11.84800;-28.69972;-11.78760;,
 17.48224;-24.23283;9.67246;,
 14.60898;-24.23283;14.27645;,
 19.12436;-24.23283;4.77845;,
 19.90285;-24.23283;-0.11555;,
 19.12436;-24.23283;-5.00957;,
 17.48224;-24.23282;-9.90358;,
 14.60898;-24.23283;-14.50756;,
 18.56050;-20.71047;10.27616;,
 15.50999;-20.71047;15.16412;,
 20.30387;-20.71047;5.08030;,
 21.13041;-20.71047;-0.11555;,
 20.30387;-20.71047;-5.31143;,
 18.56050;-20.71047;-10.50729;,
 15.50999;-20.71047;-15.39521;,
 20.81656;-13.77159;11.53927;,
 17.39525;-13.77159;17.02134;,
 22.77184;-13.77159;5.71186;,
 23.69882;-13.77159;-0.11555;,
 22.77184;-13.77159;-5.94297;,
 20.81656;-13.77159;-11.77039;,
 17.39525;-13.77159;-17.25247;,
 5.74865;-38.58485;-5.77883;,
 3.89021;-38.58485;-6.96062;,
 3.89021;-37.19921;-6.96063;,
 5.74865;-37.19921;-5.77883;,
 1.94511;-38.58485;-7.75448;,
 1.94511;-37.19921;-7.75448;,
 0.00000;-38.58485;-7.98653;,
 0.00000;-37.19921;-7.98652;,
 -1.94511;-38.58485;-7.75448;,
 -1.94511;-37.19921;-7.75448;,
 -3.89021;-38.58485;-6.96062;,
 -3.89021;-37.19921;-6.96063;,
 -5.74865;-38.58485;-5.77883;,
 -5.74865;-37.19921;-5.77883;,
 5.54324;-34.52438;-9.86924;,
 8.19137;-34.52438;-8.18527;,
 2.77162;-34.52438;-11.00041;,
 0.00000;-34.52438;-11.33106;,
 -2.77162;-34.52438;-11.00041;,
 -5.54324;-34.52438;-9.86924;,
 -8.19137;-34.52438;-8.18527;,
 8.01775;-28.69972;-14.22330;,
 11.84800;-28.69972;-11.78760;,
 4.00888;-28.69972;-15.85940;,
 0.00000;-28.69972;-16.33764;,
 -4.00888;-28.69972;-15.85940;,
 -8.01775;-28.69972;-14.22330;,
 -11.84800;-28.69972;-11.78760;,
 9.88615;-24.23282;-17.51084;,
 14.60898;-24.23283;-14.50756;,
 4.94307;-24.23283;-19.52820;,
 0.00000;-24.23283;-20.11791;,
 -4.94307;-24.23283;-19.52820;,
 -9.88615;-24.23282;-17.51084;,
 -14.60898;-24.23283;-14.50756;,
 10.49589;-20.71047;-18.58372;,
 15.50999;-20.71047;-15.39521;,
 5.24795;-20.71047;-20.72550;,
 0.00000;-20.71047;-21.35163;,
 -5.24795;-20.71047;-20.72550;,
 -10.49589;-20.71047;-18.58372;,
 -15.50999;-20.71047;-15.39521;,
 11.77167;-13.77159;-20.82855;,
 17.39525;-13.77159;-17.25247;,
 5.88584;-13.77159;-23.23067;,
 0.00000;-13.77159;-23.93287;,
 -5.88584;-13.77159;-23.23067;,
 -11.77167;-13.77159;-20.82855;,
 -17.39525;-13.77159;-17.25247;,
 -5.74865;-38.58485;-5.77883;,
 -6.87930;-38.58485;-3.96717;,
 -6.87930;-37.19921;-3.96717;,
 -5.74865;-37.19921;-5.77883;,
 -7.52547;-38.58485;-2.04136;,
 -7.52547;-37.19921;-2.04136;,
 -7.83180;-38.58485;-0.11555;,
 -7.83180;-37.19921;-0.11556;,
 -7.52547;-38.58485;1.81024;,
 -7.52547;-37.19921;1.81024;,
 -6.87930;-38.58485;3.73606;,
 -6.87930;-37.19921;3.73605;,
 -5.74865;-38.58485;5.54773;,
 -5.74865;-37.19921;5.54773;,
 -9.80244;-34.52438;-5.60379;,
 -8.19137;-34.52438;-8.18527;,
 -10.72318;-34.52438;-2.85967;,
 -11.15969;-34.52438;-0.11556;,
 -10.72318;-34.52438;2.62856;,
 -9.80244;-34.52438;5.37268;,
 -8.19137;-34.52438;7.95417;,
 -14.17828;-28.69972;-8.05373;,
 -11.84800;-28.69972;-11.78760;,
 -15.51002;-28.69972;-4.08464;,
 -16.14137;-28.69972;-0.11555;,
 -15.51002;-28.69972;3.85354;,
 -14.17828;-28.69972;7.82263;,
 -11.84800;-28.69972;11.55650;,
 -17.48224;-24.23282;-9.90358;,
 -14.60898;-24.23283;-14.50756;,
 -19.12436;-24.23283;-5.00957;,
 -19.90285;-24.23283;-0.11555;,
 -19.12436;-24.23283;4.77845;,
 -17.48224;-24.23283;9.67246;,
 -14.60898;-24.23283;14.27645;,
 -18.56050;-20.71047;-10.50729;,
 -15.50999;-20.71047;-15.39521;,
 -20.30387;-20.71047;-5.31143;,
 -21.13041;-20.71047;-0.11555;,
 -20.30387;-20.71047;5.08030;,
 -18.56050;-20.71047;10.27616;,
 -15.50999;-20.71047;15.16412;,
 -20.81656;-13.77159;-11.77039;,
 -17.39525;-13.77159;-17.25247;,
 -22.77184;-13.77159;-5.94297;,
 -23.69882;-13.77159;-0.11555;,
 -22.77184;-13.77159;5.71186;,
 -20.81656;-13.77159;11.53927;,
 -17.39525;-13.77159;17.02134;,
 -3.89021;-38.58485;-6.96062;,
 -4.58620;-40.67560;-4.67895;,
 -6.87930;-38.58485;-3.96717;,
 -1.94511;-38.58485;-7.75448;,
 -2.29310;-40.67560;-5.20817;,
 0.00000;-40.67560;-5.36287;,
 1.94511;-38.58485;-7.75448;,
 2.29310;-40.67560;-5.20817;,
 3.89021;-38.58485;-6.96062;,
 4.58620;-40.67560;-4.67895;,
 6.87930;-38.58485;-3.96717;,
 -5.01698;-40.67560;-2.39726;,
 -7.52547;-38.58485;-2.04136;,
 -2.50849;-41.63579;-2.66187;,
 0.00000;-41.63579;-2.73922;,
 2.50849;-41.63579;-2.66187;,
 5.01698;-40.67560;-2.39726;,
 7.52547;-38.58485;-2.04136;,
 -5.22121;-40.67560;-0.11555;,
 -7.83180;-38.58485;-0.11555;,
 -2.61061;-41.63579;-0.11555;,
 0.00000;-42.31414;-0.11555;,
 2.61061;-41.63579;-0.11555;,
 5.22121;-40.67560;-0.11555;,
 7.83180;-38.58485;-0.11555;,
 -5.01698;-40.67560;2.16614;,
 -7.52547;-38.58485;1.81024;,
 -2.50849;-41.63579;2.43075;,
 0.00000;-41.63579;2.50811;,
 2.50849;-41.63579;2.43075;,
 5.01698;-40.67560;2.16614;,
 7.52547;-38.58485;1.81024;,
 -4.58620;-40.67560;4.44782;,
 -6.87930;-38.58485;3.73606;,
 -2.29310;-40.67560;4.97706;,
 0.00000;-40.67560;5.13175;,
 2.29310;-40.67560;4.97706;,
 4.58620;-40.67560;4.44782;,
 6.87930;-38.58485;3.73606;,
 -3.89021;-38.58485;6.72952;,
 -5.74865;-38.58485;5.54773;,
 -1.94511;-38.58485;7.52336;,
 0.00000;-38.58485;7.75538;,
 1.94511;-38.58485;7.52336;,
 3.89021;-38.58485;6.72952;,
 5.74865;-38.58485;5.54773;,
 -20.81656;-13.77159;-11.77039;,
 -15.03056;-7.40273;-15.07135;,
 -11.77167;-13.77159;-20.82855;,
 -7.51528;-7.40273;-16.80581;,
 -5.88584;-13.77159;-23.23067;,
 0.00000;-7.40273;-17.31282;,
 7.51528;-7.40273;-16.80581;,
 5.88584;-13.77159;-23.23067;,
 15.03056;-7.40273;-15.07135;,
 11.77167;-13.77159;-20.82855;,
 20.81656;-13.77159;-11.77039;,
 -22.77184;-13.77159;-5.94297;,
 -16.44239;-7.40273;-7.59347;,
 -8.22120;-2.13214;-8.46068;,
 0.00000;-2.13213;-8.71419;,
 8.22120;-2.13214;-8.46068;,
 16.44239;-7.40273;-7.59347;,
 22.77184;-13.77159;-5.94297;,
 -23.69882;-13.77159;-0.11555;,
 -17.11171;-7.40273;-0.11555;,
 -8.55586;-2.13214;-0.11555;,
 0.00000;-0.29873;-0.11555;,
 8.55586;-2.13214;-0.11555;,
 17.11171;-7.40273;-0.11555;,
 23.69882;-13.77159;-0.11555;,
 -22.77184;-13.77159;5.71186;,
 -16.44239;-7.40273;7.36234;,
 -8.22120;-2.13214;8.22957;,
 0.00000;-2.13214;8.48307;,
 8.22120;-2.13214;8.22957;,
 16.44239;-7.40273;7.36234;,
 22.77184;-13.77159;5.71186;,
 -20.81656;-13.77159;11.53927;,
 -15.03056;-7.40273;14.84025;,
 -7.51528;-7.40273;16.57468;,
 0.00000;-7.40273;17.08170;,
 7.51528;-7.40273;16.57468;,
 15.03056;-7.40273;14.84025;,
 20.81656;-13.77159;11.53927;,
 -17.39525;-13.77159;17.02134;,
 -11.77167;-13.77159;20.59746;,
 -5.88584;-13.77159;22.99956;,
 0.00000;-13.77159;23.70176;,
 5.88584;-13.77159;22.99956;,
 11.77167;-13.77159;20.59746;,
 17.39525;-13.77159;17.02134;;
 
 216;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;3,2,14,15;,
 4;2,5,16,14;,
 4;5,7,17,16;,
 4;7,9,18,17;,
 4;9,11,19,18;,
 4;11,13,20,19;,
 4;15,14,21,22;,
 4;14,16,23,21;,
 4;16,17,24,23;,
 4;17,18,25,24;,
 4;18,19,26,25;,
 4;19,20,27,26;,
 4;22,21,28,29;,
 4;21,23,30,28;,
 4;23,24,31,30;,
 4;24,25,32,31;,
 4;25,26,33,32;,
 4;26,27,34,33;,
 4;29,28,35,36;,
 4;28,30,37,35;,
 4;30,31,38,37;,
 4;31,32,39,38;,
 4;32,33,40,39;,
 4;33,34,41,40;,
 4;36,35,42,43;,
 4;35,37,44,42;,
 4;37,38,45,44;,
 4;38,39,46,45;,
 4;39,40,47,46;,
 4;40,41,48,47;,
 4;49,50,51,52;,
 4;50,53,54,51;,
 4;53,55,56,54;,
 4;55,57,58,56;,
 4;57,59,60,58;,
 4;59,61,62,60;,
 4;52,51,63,64;,
 4;51,54,65,63;,
 4;54,56,66,65;,
 4;56,58,67,66;,
 4;58,60,68,67;,
 4;60,62,69,68;,
 4;64,63,70,71;,
 4;63,65,72,70;,
 4;65,66,73,72;,
 4;66,67,74,73;,
 4;67,68,75,74;,
 4;68,69,76,75;,
 4;71,70,77,78;,
 4;70,72,79,77;,
 4;72,73,80,79;,
 4;73,74,81,80;,
 4;74,75,82,81;,
 4;75,76,83,82;,
 4;78,77,84,85;,
 4;77,79,86,84;,
 4;79,80,87,86;,
 4;80,81,88,87;,
 4;81,82,89,88;,
 4;82,83,90,89;,
 4;85,84,91,92;,
 4;84,86,93,91;,
 4;86,87,94,93;,
 4;87,88,95,94;,
 4;88,89,96,95;,
 4;89,90,97,96;,
 4;98,99,100,101;,
 4;99,102,103,100;,
 4;102,104,105,103;,
 4;104,106,107,105;,
 4;106,108,109,107;,
 4;108,110,111,109;,
 4;101,100,112,113;,
 4;100,103,114,112;,
 4;103,105,115,114;,
 4;105,107,116,115;,
 4;107,109,117,116;,
 4;109,111,118,117;,
 4;113,112,119,120;,
 4;112,114,121,119;,
 4;114,115,122,121;,
 4;115,116,123,122;,
 4;116,117,124,123;,
 4;117,118,125,124;,
 4;120,119,126,127;,
 4;119,121,128,126;,
 4;121,122,129,128;,
 4;122,123,130,129;,
 4;123,124,131,130;,
 4;124,125,132,131;,
 4;127,126,133,134;,
 4;126,128,135,133;,
 4;128,129,136,135;,
 4;129,130,137,136;,
 4;130,131,138,137;,
 4;131,132,139,138;,
 4;134,133,140,141;,
 4;133,135,142,140;,
 4;135,136,143,142;,
 4;136,137,144,143;,
 4;137,138,145,144;,
 4;138,139,146,145;,
 4;147,148,149,150;,
 4;148,151,152,149;,
 4;151,153,154,152;,
 4;153,155,156,154;,
 4;155,157,158,156;,
 4;157,159,160,158;,
 4;150,149,161,162;,
 4;149,152,163,161;,
 4;152,154,164,163;,
 4;154,156,165,164;,
 4;156,158,166,165;,
 4;158,160,167,166;,
 4;162,161,168,169;,
 4;161,163,170,168;,
 4;163,164,171,170;,
 4;164,165,172,171;,
 4;165,166,173,172;,
 4;166,167,174,173;,
 4;169,168,175,176;,
 4;168,170,177,175;,
 4;170,171,178,177;,
 4;171,172,179,178;,
 4;172,173,180,179;,
 4;173,174,181,180;,
 4;176,175,182,183;,
 4;175,177,184,182;,
 4;177,178,185,184;,
 4;178,179,186,185;,
 4;179,180,187,186;,
 4;180,181,188,187;,
 4;183,182,189,190;,
 4;182,184,191,189;,
 4;184,185,192,191;,
 4;185,186,193,192;,
 4;186,187,194,193;,
 4;187,188,195,194;,
 4;147,196,197,198;,
 4;196,199,200,197;,
 4;199,104,201,200;,
 4;104,202,203,201;,
 4;202,204,205,203;,
 4;204,61,206,205;,
 4;198,197,207,208;,
 4;197,200,209,207;,
 4;200,201,210,209;,
 4;201,203,211,210;,
 4;203,205,212,211;,
 4;205,206,213,212;,
 4;208,207,214,215;,
 4;207,209,216,214;,
 4;209,210,217,216;,
 4;210,211,218,217;,
 4;211,212,219,218;,
 4;212,213,220,219;,
 4;215,214,221,222;,
 4;214,216,223,221;,
 4;216,217,224,223;,
 4;217,218,225,224;,
 4;218,219,226,225;,
 4;219,220,227,226;,
 4;222,221,228,229;,
 4;221,223,230,228;,
 4;223,224,231,230;,
 4;224,225,232,231;,
 4;225,226,233,232;,
 4;226,227,234,233;,
 4;229,228,235,236;,
 4;228,230,237,235;,
 4;230,231,238,237;,
 4;231,232,239,238;,
 4;232,233,240,239;,
 4;233,234,241,240;,
 4;242,243,244,190;,
 4;243,245,246,244;,
 4;245,247,143,246;,
 4;247,248,249,143;,
 4;248,250,251,249;,
 4;250,252,97,251;,
 4;253,254,243,242;,
 4;254,255,245,243;,
 4;255,256,247,245;,
 4;256,257,248,247;,
 4;257,258,250,248;,
 4;258,259,252,250;,
 4;260,261,254,253;,
 4;261,262,255,254;,
 4;262,263,256,255;,
 4;263,264,257,256;,
 4;264,265,258,257;,
 4;265,266,259,258;,
 4;267,268,261,260;,
 4;268,269,262,261;,
 4;269,270,263,262;,
 4;270,271,264,263;,
 4;271,272,265,264;,
 4;272,273,266,265;,
 4;274,275,268,267;,
 4;275,276,269,268;,
 4;276,277,270,269;,
 4;277,278,271,270;,
 4;278,279,272,271;,
 4;279,280,273,272;,
 4;281,282,275,274;,
 4;282,283,276,275;,
 4;283,284,277,276;,
 4;284,285,278,277;,
 4;285,286,279,278;,
 4;286,287,280,279;;
 
 MeshMaterialList {
  5;
  216;
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
  232;
  -0.693212;-0.216187;0.687546;,
  -0.458244;-0.359714;0.812784;,
  -0.210970;-0.411670;0.886577;,
  0.000000;-0.430864;0.902417;,
  0.210970;-0.411670;0.886577;,
  0.458244;-0.359714;0.812784;,
  -0.636902;-0.442100;0.631588;,
  -0.413593;-0.433671;0.800544;,
  -0.225520;-0.434774;0.871844;,
  0.000000;-0.434184;0.900824;,
  0.225520;-0.434774;0.871844;,
  0.413593;-0.433671;0.800544;,
  -0.486700;-0.728109;0.482681;,
  -0.318781;-0.719370;0.617160;,
  -0.173785;-0.720076;0.671780;,
  0.000000;-0.719560;0.694430;,
  0.173785;-0.720076;0.671780;,
  0.318781;-0.719370;0.617160;,
  -0.534514;-0.658260;0.530084;,
  -0.349265;-0.648739;0.676130;,
  -0.190432;-0.649484;0.736143;,
  0.000000;-0.648929;0.760849;,
  0.190432;-0.649484;0.736143;,
  0.349265;-0.648739;0.676130;,
  -0.612494;-0.505904;0.607382;,
  -0.398435;-0.496468;0.771213;,
  -0.217275;-0.497284;0.839941;,
  0.000000;-0.496718;0.867912;,
  0.217275;-0.497284;0.839941;,
  0.398435;-0.496468;0.771213;,
  -0.665914;-0.347171;0.660327;,
  -0.431776;-0.339471;0.835661;,
  -0.235502;-0.340066;0.910436;,
  0.000000;-0.339621;0.940562;,
  0.235502;-0.340066;0.910436;,
  0.431776;-0.339471;0.835661;,
  -0.707102;-0.090256;0.701328;,
  -0.491760;0.108969;0.863885;,
  -0.225484;0.189884;0.955563;,
  0.000000;-0.348657;0.937250;,
  0.265360;-0.025134;0.963822;,
  0.543780;-0.088956;0.834500;,
  0.693212;-0.216187;0.687546;,
  0.825888;-0.363415;0.431089;,
  0.889570;-0.410800;0.199769;,
  0.903249;-0.429117;0.000000;,
  0.889570;-0.410801;-0.199769;,
  0.825888;-0.363414;-0.431091;,
  0.636902;-0.442100;0.631588;,
  0.814876;-0.433982;0.384236;,
  0.876432;-0.430788;0.215147;,
  0.901015;-0.433788;0.000000;,
  0.876432;-0.430789;-0.215147;,
  0.814875;-0.433983;-0.384237;,
  0.486700;-0.728109;0.482681;,
  0.628436;-0.719291;0.296123;,
  0.678955;-0.715014;0.166658;,
  0.696158;-0.717889;-0.000000;,
  0.678956;-0.715014;-0.166658;,
  0.628435;-0.719291;-0.296123;,
  0.534514;-0.658260;0.530084;,
  0.688466;-0.648635;0.324480;,
  0.743007;-0.643953;0.182385;,
  0.762445;-0.647053;-0.000000;,
  0.743007;-0.643953;-0.182385;,
  0.688466;-0.648635;-0.324480;,
  0.612494;-0.505904;0.607382;,
  0.785166;-0.496443;0.370215;,
  0.845485;-0.492014;0.207552;,
  0.868832;-0.495107;0.000000;,
  0.845485;-0.492014;-0.207552;,
  0.785165;-0.496443;-0.370216;,
  0.665914;-0.347171;0.660327;,
  0.850759;-0.339394;0.401275;,
  0.914817;-0.335668;0.224582;,
  0.941101;-0.338126;0.000000;,
  0.914817;-0.335668;-0.224581;,
  0.850758;-0.339395;-0.401275;,
  0.707102;-0.090256;0.701328;,
  0.848861;-0.088594;0.521139;,
  0.911670;-0.344626;0.223808;,
  0.937816;-0.347132;0.000000;,
  0.911671;-0.344625;-0.223808;,
  0.878639;0.113694;-0.463754;,
  0.693211;-0.216187;-0.687547;,
  0.458246;-0.359713;-0.812783;,
  0.210977;-0.411671;-0.886575;,
  0.000000;-0.430864;-0.902417;,
  -0.210977;-0.411671;-0.886575;,
  -0.458246;-0.359713;-0.812783;,
  0.636902;-0.442101;-0.631588;,
  0.413596;-0.433672;-0.800542;,
  0.225528;-0.434774;-0.871842;,
  0.000000;-0.434184;-0.900824;,
  -0.225528;-0.434773;-0.871842;,
  -0.413596;-0.433672;-0.800542;,
  0.486700;-0.728108;-0.482681;,
  0.318783;-0.719370;-0.617159;,
  0.173788;-0.720076;-0.671780;,
  0.000000;-0.719560;-0.694431;,
  -0.173788;-0.720076;-0.671780;,
  -0.318783;-0.719370;-0.617159;,
  0.534514;-0.658260;-0.530084;,
  0.349266;-0.648738;-0.676130;,
  0.190433;-0.649482;-0.736144;,
  0.000000;-0.648927;-0.760851;,
  -0.190433;-0.649482;-0.736144;,
  -0.349266;-0.648738;-0.676130;,
  0.612494;-0.505903;-0.607382;,
  0.398436;-0.496466;-0.771214;,
  0.217275;-0.497284;-0.839941;,
  0.000000;-0.496719;-0.867911;,
  -0.217275;-0.497284;-0.839941;,
  -0.398436;-0.496466;-0.771214;,
  0.665913;-0.347171;-0.660327;,
  0.431776;-0.339471;-0.835661;,
  0.235503;-0.340067;-0.910435;,
  0.000000;-0.339624;-0.940561;,
  -0.235503;-0.340067;-0.910435;,
  -0.431776;-0.339471;-0.835661;,
  0.707100;-0.090257;-0.701330;,
  0.543780;-0.088956;-0.834500;,
  0.265363;-0.025134;-0.963821;,
  0.000000;-0.348656;-0.937251;,
  -0.225486;0.189883;-0.955563;,
  -0.491760;0.108968;-0.863885;,
  -0.693211;-0.216187;-0.687547;,
  -0.825888;-0.363414;-0.431091;,
  -0.889570;-0.410801;-0.199769;,
  -0.903249;-0.429117;0.000000;,
  -0.889570;-0.410800;0.199769;,
  -0.825888;-0.363415;0.431089;,
  -0.636902;-0.442101;-0.631588;,
  -0.814875;-0.433983;-0.384237;,
  -0.876432;-0.430788;-0.215147;,
  -0.901015;-0.433788;0.000000;,
  -0.876432;-0.430788;0.215147;,
  -0.814876;-0.433982;0.384236;,
  -0.486700;-0.728108;-0.482682;,
  -0.628435;-0.719291;-0.296123;,
  -0.678956;-0.715014;-0.166658;,
  -0.696158;-0.717889;-0.000000;,
  -0.678955;-0.715014;0.166658;,
  -0.628436;-0.719291;0.296123;,
  -0.534514;-0.658260;-0.530084;,
  -0.688466;-0.648635;-0.324480;,
  -0.743007;-0.643953;-0.182385;,
  -0.762445;-0.647053;-0.000000;,
  -0.743007;-0.643953;0.182385;,
  -0.688466;-0.648635;0.324480;,
  -0.612494;-0.505903;-0.607382;,
  -0.785165;-0.496443;-0.370216;,
  -0.845485;-0.492014;-0.207552;,
  -0.868832;-0.495108;0.000000;,
  -0.845485;-0.492014;0.207552;,
  -0.785166;-0.496443;0.370215;,
  -0.665913;-0.347171;-0.660327;,
  -0.850758;-0.339395;-0.401275;,
  -0.914817;-0.335668;-0.224581;,
  -0.941101;-0.338126;0.000000;,
  -0.914817;-0.335667;0.224582;,
  -0.850759;-0.339394;0.401275;,
  -0.707100;-0.090257;-0.701330;,
  -0.878639;0.113694;-0.463754;,
  -0.911671;-0.344625;-0.223808;,
  -0.937816;-0.347132;0.000000;,
  -0.911670;-0.344626;0.223808;,
  -0.848861;-0.088594;0.521139;,
  -0.439855;-0.790699;-0.425819;,
  -0.131786;-0.868317;-0.478182;,
  0.000000;-0.868235;-0.496153;,
  0.131786;-0.868317;-0.478182;,
  0.439855;-0.790699;-0.425819;,
  -0.482227;-0.866916;-0.126152;,
  -0.184746;-0.965600;-0.182990;,
  0.000000;-0.970039;-0.242950;,
  0.184746;-0.965600;-0.182990;,
  0.482227;-0.866916;-0.126152;,
  -0.500115;-0.865959;0.000000;,
  -0.244392;-0.969676;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.244392;-0.969676;0.000000;,
  0.500115;-0.865959;0.000000;,
  -0.482227;-0.866916;0.126152;,
  -0.184747;-0.965600;0.182990;,
  0.000000;-0.970039;0.242950;,
  0.184747;-0.965600;0.182990;,
  0.482227;-0.866916;0.126152;,
  -0.439855;-0.790701;0.425817;,
  -0.131784;-0.868317;0.478183;,
  0.000000;-0.868234;0.496155;,
  0.131784;-0.868317;0.478183;,
  0.439855;-0.790701;0.425817;,
  -0.521556;0.687744;-0.504964;,
  -0.173777;0.786206;-0.593027;,
  0.000000;0.785413;-0.618972;,
  0.173777;0.786206;-0.593027;,
  0.521556;0.687744;-0.504964;,
  -0.597235;0.784569;-0.166620;,
  -0.265575;0.927530;-0.262980;,
  0.000000;0.944583;-0.328272;,
  0.265575;0.927530;-0.262980;,
  0.597235;0.784569;-0.166620;,
  -0.623404;0.781900;0.000000;,
  -0.330327;0.943867;0.000000;,
  0.000000;1.000000;0.000000;,
  0.330327;0.943867;0.000000;,
  0.623404;0.781900;0.000000;,
  -0.597234;0.784569;0.166620;,
  -0.265575;0.927530;0.262980;,
  0.000000;0.944583;0.328272;,
  0.265575;0.927530;0.262980;,
  0.597234;0.784569;0.166620;,
  -0.521556;0.687744;0.504963;,
  -0.173776;0.786207;0.593027;,
  0.000000;0.785413;0.618971;,
  0.173776;0.786207;0.593027;,
  0.521556;0.687744;0.504964;,
  0.000000;0.712410;-0.701763;,
  0.065156;0.710897;-0.700272;,
  0.234645;0.626357;-0.743383;,
  -0.725926;0.673258;-0.140555;,
  0.725926;0.673258;-0.140555;,
  -0.706445;0.707768;0.000000;,
  0.706445;0.707768;0.000000;,
  -0.725926;0.673258;0.140555;,
  0.725926;0.673258;0.140555;,
  -0.744915;0.638493;0.193465;,
  0.744915;0.638493;0.193465;,
  0.000000;0.712411;0.701762;,
  0.065156;0.710897;0.700271;,
  0.234643;0.626358;0.743383;;
  216;
  4;0,1,7,6;,
  4;1,2,8,7;,
  4;2,3,9,8;,
  4;3,4,10,9;,
  4;4,5,11,10;,
  4;5,42,48,11;,
  4;6,7,13,12;,
  4;7,8,14,13;,
  4;8,9,15,14;,
  4;9,10,16,15;,
  4;10,11,17,16;,
  4;11,48,54,17;,
  4;12,13,19,18;,
  4;13,14,20,19;,
  4;14,15,21,20;,
  4;15,16,22,21;,
  4;16,17,23,22;,
  4;17,54,60,23;,
  4;18,19,25,24;,
  4;19,20,26,25;,
  4;20,21,27,26;,
  4;21,22,28,27;,
  4;22,23,29,28;,
  4;23,60,66,29;,
  4;24,25,31,30;,
  4;25,26,32,31;,
  4;26,27,33,32;,
  4;27,28,34,33;,
  4;28,29,35,34;,
  4;29,66,72,35;,
  4;30,31,37,36;,
  4;31,32,38,37;,
  4;32,33,39,38;,
  4;33,34,40,39;,
  4;34,35,41,40;,
  4;35,72,78,41;,
  4;42,43,49,48;,
  4;43,44,50,49;,
  4;44,45,51,50;,
  4;45,46,52,51;,
  4;46,47,53,52;,
  4;47,84,90,53;,
  4;48,49,55,54;,
  4;49,50,56,55;,
  4;50,51,57,56;,
  4;51,52,58,57;,
  4;52,53,59,58;,
  4;53,90,96,59;,
  4;54,55,61,60;,
  4;55,56,62,61;,
  4;56,57,63,62;,
  4;57,58,64,63;,
  4;58,59,65,64;,
  4;59,96,102,65;,
  4;60,61,67,66;,
  4;61,62,68,67;,
  4;62,63,69,68;,
  4;63,64,70,69;,
  4;64,65,71,70;,
  4;65,102,108,71;,
  4;66,67,73,72;,
  4;67,68,74,73;,
  4;68,69,75,74;,
  4;69,70,76,75;,
  4;70,71,77,76;,
  4;71,108,114,77;,
  4;72,73,79,78;,
  4;73,74,80,79;,
  4;74,75,81,80;,
  4;75,76,82,81;,
  4;76,77,83,82;,
  4;77,114,120,83;,
  4;84,85,91,90;,
  4;85,86,92,91;,
  4;86,87,93,92;,
  4;87,88,94,93;,
  4;88,89,95,94;,
  4;89,126,132,95;,
  4;90,91,97,96;,
  4;91,92,98,97;,
  4;92,93,99,98;,
  4;93,94,100,99;,
  4;94,95,101,100;,
  4;95,132,138,101;,
  4;96,97,103,102;,
  4;97,98,104,103;,
  4;98,99,105,104;,
  4;99,100,106,105;,
  4;100,101,107,106;,
  4;101,138,144,107;,
  4;102,103,109,108;,
  4;103,104,110,109;,
  4;104,105,111,110;,
  4;105,106,112,111;,
  4;106,107,113,112;,
  4;107,144,150,113;,
  4;108,109,115,114;,
  4;109,110,116,115;,
  4;110,111,117,116;,
  4;111,112,118,117;,
  4;112,113,119,118;,
  4;113,150,156,119;,
  4;114,115,121,120;,
  4;115,116,122,121;,
  4;116,117,123,122;,
  4;117,118,124,123;,
  4;118,119,125,124;,
  4;119,156,162,125;,
  4;126,127,133,132;,
  4;127,128,134,133;,
  4;128,129,135,134;,
  4;129,130,136,135;,
  4;130,131,137,136;,
  4;131,0,6,137;,
  4;132,133,139,138;,
  4;133,134,140,139;,
  4;134,135,141,140;,
  4;135,136,142,141;,
  4;136,137,143,142;,
  4;137,6,12,143;,
  4;138,139,145,144;,
  4;139,140,146,145;,
  4;140,141,147,146;,
  4;141,142,148,147;,
  4;142,143,149,148;,
  4;143,12,18,149;,
  4;144,145,151,150;,
  4;145,146,152,151;,
  4;146,147,153,152;,
  4;147,148,154,153;,
  4;148,149,155,154;,
  4;149,18,24,155;,
  4;150,151,157,156;,
  4;151,152,158,157;,
  4;152,153,159,158;,
  4;153,154,160,159;,
  4;154,155,161,160;,
  4;155,24,30,161;,
  4;156,157,163,162;,
  4;157,158,164,163;,
  4;158,159,165,164;,
  4;159,160,166,165;,
  4;160,161,167,166;,
  4;161,30,36,167;,
  4;126,89,168,127;,
  4;89,88,169,168;,
  4;88,87,170,169;,
  4;87,86,171,170;,
  4;86,85,172,171;,
  4;85,84,47,172;,
  4;127,168,173,128;,
  4;168,169,174,173;,
  4;169,170,175,174;,
  4;170,171,176,175;,
  4;171,172,177,176;,
  4;172,47,46,177;,
  4;128,173,178,129;,
  4;173,174,179,178;,
  4;174,175,180,179;,
  4;175,176,181,180;,
  4;176,177,182,181;,
  4;177,46,45,182;,
  4;129,178,183,130;,
  4;178,179,184,183;,
  4;179,180,185,184;,
  4;180,181,186,185;,
  4;181,182,187,186;,
  4;182,45,44,187;,
  4;130,183,188,131;,
  4;183,184,189,188;,
  4;184,185,190,189;,
  4;185,186,191,190;,
  4;186,187,192,191;,
  4;187,44,43,192;,
  4;131,188,1,0;,
  4;188,189,2,1;,
  4;189,190,3,2;,
  4;190,191,4,3;,
  4;191,192,5,4;,
  4;192,43,42,5;,
  4;163,193,125,162;,
  4;193,194,124,125;,
  4;194,195,218,124;,
  4;195,196,219,218;,
  4;196,197,220,122;,
  4;197,83,120,121;,
  4;221,198,193,163;,
  4;198,199,194,193;,
  4;199,200,195,194;,
  4;200,201,196,195;,
  4;201,202,197,196;,
  4;202,222,83,197;,
  4;223,203,198,221;,
  4;203,204,199,198;,
  4;204,205,200,199;,
  4;205,206,201,200;,
  4;206,207,202,201;,
  4;207,224,222,202;,
  4;225,208,203,223;,
  4;208,209,204,203;,
  4;209,210,205,204;,
  4;210,211,206,205;,
  4;211,212,207,206;,
  4;212,226,224,207;,
  4;227,213,208,225;,
  4;213,214,209,208;,
  4;214,215,210,209;,
  4;215,216,211,210;,
  4;216,217,212,211;,
  4;217,228,226,212;,
  4;36,37,213,167;,
  4;37,38,214,213;,
  4;38,229,215,214;,
  4;229,230,216,215;,
  4;40,231,217,216;,
  4;41,78,79,217;;
 }
 MeshTextureCoords {
  288;
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;0.166670;,
  0.000000;0.166670;,
  0.333330;0.000000;,
  0.333330;0.166670;,
  0.500000;0.000000;,
  0.500000;0.166670;,
  0.666670;0.000000;,
  0.666670;0.166670;,
  0.833330;0.000000;,
  0.833330;0.166670;,
  1.000000;0.000000;,
  1.000000;0.166670;,
  0.166670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.500000;0.333330;,
  0.666670;0.333330;,
  0.833330;0.333330;,
  1.000000;0.333330;,
  0.166670;0.500000;,
  0.000000;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.166670;0.666670;,
  0.000000;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.166670;0.833330;,
  0.000000;0.833330;,
  0.333330;0.833330;,
  0.500000;0.833330;,
  0.666670;0.833330;,
  0.833330;0.833330;,
  1.000000;0.833330;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;0.166670;,
  0.000000;0.166670;,
  0.333330;0.000000;,
  0.333330;0.166670;,
  0.500000;0.000000;,
  0.500000;0.166670;,
  0.666670;0.000000;,
  0.666670;0.166670;,
  0.833330;0.000000;,
  0.833330;0.166670;,
  1.000000;0.000000;,
  1.000000;0.166670;,
  0.166670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.500000;0.333330;,
  0.666670;0.333330;,
  0.833330;0.333330;,
  1.000000;0.333330;,
  0.166670;0.500000;,
  0.000000;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.166670;0.666670;,
  0.000000;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.166670;0.833330;,
  0.000000;0.833330;,
  0.333330;0.833330;,
  0.500000;0.833330;,
  0.666670;0.833330;,
  0.833330;0.833330;,
  1.000000;0.833330;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;0.166670;,
  0.000000;0.166670;,
  0.333330;0.000000;,
  0.333330;0.166670;,
  0.500000;0.000000;,
  0.500000;0.166670;,
  0.666670;0.000000;,
  0.666670;0.166670;,
  0.833330;0.000000;,
  0.833330;0.166670;,
  1.000000;0.000000;,
  1.000000;0.166670;,
  0.166670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.500000;0.333330;,
  0.666670;0.333330;,
  0.833330;0.333330;,
  1.000000;0.333330;,
  0.166670;0.500000;,
  0.000000;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.166670;0.666670;,
  0.000000;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.166670;0.833330;,
  0.000000;0.833330;,
  0.333330;0.833330;,
  0.500000;0.833330;,
  0.666670;0.833330;,
  0.833330;0.833330;,
  1.000000;0.833330;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;0.166670;,
  0.000000;0.166670;,
  0.333330;0.000000;,
  0.333330;0.166670;,
  0.500000;0.000000;,
  0.500000;0.166670;,
  0.666670;0.000000;,
  0.666670;0.166670;,
  0.833330;0.000000;,
  0.833330;0.166670;,
  1.000000;0.000000;,
  1.000000;0.166670;,
  0.166670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.500000;0.333330;,
  0.666670;0.333330;,
  0.833330;0.333330;,
  1.000000;0.333330;,
  0.166670;0.500000;,
  0.000000;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.166670;0.666670;,
  0.000000;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.166670;0.833330;,
  0.000000;0.833330;,
  0.333330;0.833330;,
  0.500000;0.833330;,
  0.666670;0.833330;,
  0.833330;0.833330;,
  1.000000;0.833330;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.166670;0.000000;,
  0.166670;0.166670;,
  0.000000;0.166670;,
  0.333330;0.000000;,
  0.333330;0.166670;,
  0.500000;0.166670;,
  0.666670;0.000000;,
  0.666670;0.166670;,
  0.833330;0.000000;,
  0.833330;0.166670;,
  1.000000;0.166670;,
  0.166670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.500000;0.333330;,
  0.666670;0.333330;,
  0.833330;0.333330;,
  1.000000;0.333330;,
  0.166670;0.500000;,
  0.000000;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.166670;0.666670;,
  0.000000;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.166670;0.833330;,
  0.000000;0.833330;,
  0.333330;0.833330;,
  0.500000;0.833330;,
  0.666670;0.833330;,
  0.833330;0.833330;,
  1.000000;0.833330;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.000000;0.833330;,
  0.166670;0.833330;,
  0.166670;1.000000;,
  0.333330;0.833330;,
  0.333330;1.000000;,
  0.500000;0.833330;,
  0.666670;0.833330;,
  0.666670;1.000000;,
  0.833330;0.833330;,
  0.833330;1.000000;,
  1.000000;0.833330;,
  0.000000;0.666670;,
  0.166670;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.000000;0.500000;,
  0.166670;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.000000;0.333330;,
  0.166670;0.333330;,
  0.333330;0.333330;,
  0.500000;0.333330;,
  0.666670;0.333330;,
  0.833330;0.333330;,
  1.000000;0.333330;,
  0.000000;0.166670;,
  0.166670;0.166670;,
  0.333330;0.166670;,
  0.500000;0.166670;,
  0.666670;0.166670;,
  0.833330;0.166670;,
  1.000000;0.166670;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.333330;0.000000;,
  0.500000;0.000000;,
  0.666670;0.000000;,
  0.833330;0.000000;,
  1.000000;0.000000;;
 }
}
