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
 -4.37699;-38.42903;4.31360;,
 -2.96442;-38.42903;5.21187;,
 -2.96442;-33.38634;5.21187;,
 -4.37699;-33.38634;4.31360;,
 -1.48595;-38.42903;5.81527;,
 -1.48595;-33.38634;5.81527;,
 -0.00750;-38.42903;5.99164;,
 -0.00750;-33.38634;5.99164;,
 1.47097;-38.42903;5.81527;,
 1.47097;-33.38634;5.81527;,
 2.94943;-38.42903;5.21187;,
 2.94943;-33.38634;5.21187;,
 4.36201;-38.42903;4.31360;,
 4.36201;-33.38634;4.31360;,
 -2.54082;-25.33419;4.10418;,
 -4.33362;-26.72530;3.92442;,
 -1.27417;-25.33419;4.57910;,
 -0.00750;-25.33419;4.71791;,
 1.25917;-25.33419;4.57910;,
 2.52583;-25.33419;4.10418;,
 4.31865;-26.72530;3.92442;,
 -3.67171;-19.45500;5.93227;,
 -5.42214;-19.45500;4.90962;,
 -1.83959;-19.45500;6.61921;,
 -0.00750;-19.45500;6.82002;,
 1.82461;-19.45500;6.61921;,
 3.65670;-19.45500;5.93227;,
 5.40717;-19.45500;4.90962;,
 -4.52556;-16.79590;7.31259;,
 -6.68394;-16.79590;6.05162;,
 -2.26653;-16.79590;8.15960;,
 -0.00750;-16.79590;8.40719;,
 2.25155;-16.79590;8.15960;,
 4.51060;-16.79590;7.31259;,
 6.66899;-16.79590;6.05162;,
 -5.44120;-14.01384;8.79277;,
 -8.03701;-14.01384;7.27625;,
 -2.72435;-14.01384;9.81141;,
 -0.00750;-14.01384;10.10917;,
 2.70936;-14.01384;9.81141;,
 5.42624;-14.01384;8.79277;,
 8.02203;-14.01384;7.27625;,
 -5.63424;-9.33464;9.10482;,
 -8.32226;-9.33464;7.53440;,
 -2.82088;-9.33464;10.15967;,
 -0.00750;-9.33464;10.46802;,
 2.80589;-9.33464;10.15967;,
 5.61928;-9.33464;9.10482;,
 8.30733;-9.33464;7.53440;,
 4.36201;-38.42903;4.31360;,
 5.22140;-38.42903;2.93658;,
 5.22140;-33.38634;2.93657;,
 4.36201;-33.38634;4.31360;,
 5.71254;-38.42903;1.47277;,
 5.71254;-33.38634;1.47277;,
 5.94539;-38.42903;0.00900;,
 5.94539;-33.38634;0.00899;,
 5.71254;-38.42903;-1.45480;,
 5.71254;-33.38634;-1.45480;,
 5.22140;-38.42903;-2.91859;,
 5.22140;-33.38634;-2.91859;,
 4.36201;-38.42903;-4.29563;,
 4.36201;-33.38634;-4.29562;,
 5.16950;-26.72530;2.67188;,
 4.31865;-26.72530;3.92442;,
 5.65577;-26.72530;1.34045;,
 5.88631;-26.72530;0.00899;,
 5.65577;-26.72530;-1.32245;,
 5.16950;-26.72530;-2.65390;,
 4.31865;-26.72530;-3.90643;,
 6.47213;-19.45500;3.34191;,
 5.40717;-19.45500;4.90962;,
 7.08076;-19.45500;1.67546;,
 7.36932;-19.45500;0.00900;,
 7.08076;-19.45500;-1.65746;,
 6.47213;-19.45500;-3.32393;,
 5.40717;-19.45500;-4.89164;,
 7.98210;-16.79590;4.11859;,
 6.66899;-16.79590;6.05162;,
 8.73258;-16.79590;2.06379;,
 9.08835;-16.79590;0.00900;,
 8.73258;-16.79590;-2.04581;,
 7.98210;-16.79590;-4.10061;,
 6.66899;-16.79590;-6.03364;,
 9.60128;-14.01384;4.95145;,
 8.02203;-14.01384;7.27625;,
 10.50385;-14.01384;2.48021;,
 10.93175;-14.01384;0.00900;,
 10.50385;-14.01384;-2.46224;,
 9.60128;-14.01384;-4.93348;,
 8.02203;-14.01384;-7.25825;,
 9.94268;-9.33464;5.12705;,
 8.30733;-9.33464;7.53440;,
 10.87729;-9.33464;2.56802;,
 11.32039;-9.33464;0.00900;,
 10.87729;-9.33464;-2.55004;,
 9.94268;-9.33464;-5.10907;,
 8.30733;-9.33464;-7.51644;,
 4.36201;-38.42903;-4.29563;,
 2.94943;-38.42903;-5.19389;,
 2.94943;-33.38634;-5.19389;,
 4.36201;-33.38634;-4.29562;,
 1.47097;-38.42903;-5.79730;,
 1.47097;-33.38634;-5.79730;,
 -0.00750;-38.42903;-5.97367;,
 -0.00750;-33.38634;-5.97367;,
 -1.48595;-38.42903;-5.79730;,
 -1.48595;-33.38634;-5.79730;,
 -2.96442;-38.42903;-5.19389;,
 -2.96442;-33.38634;-5.19389;,
 -4.37699;-38.42903;-4.29563;,
 -4.37699;-33.38634;-4.29562;,
 2.92007;-26.72530;-4.72348;,
 4.31865;-26.72530;-3.90643;,
 1.45628;-26.72530;-5.27234;,
 -0.00750;-26.72530;-5.43276;,
 -1.47127;-26.72530;-5.27234;,
 -2.93507;-26.72530;-4.72348;,
 -4.33362;-26.72530;-3.90643;,
 3.65670;-19.45500;-5.91429;,
 5.40717;-19.45500;-4.89164;,
 1.82461;-19.45500;-6.60122;,
 -0.00750;-19.45500;-6.80202;,
 -1.83959;-19.45500;-6.60122;,
 -3.67171;-19.45500;-5.91429;,
 -5.42214;-19.45500;-4.89164;,
 4.51060;-16.79590;-7.29459;,
 6.66899;-16.79590;-6.03364;,
 2.25155;-16.79590;-8.14161;,
 -0.00750;-16.79590;-8.38920;,
 -2.26653;-16.79590;-8.14161;,
 -4.52556;-16.79590;-7.29459;,
 -6.68394;-16.79590;-6.03364;,
 5.42624;-14.01384;-8.77475;,
 8.02203;-14.01384;-7.25825;,
 2.70936;-14.01384;-9.79341;,
 -0.00750;-14.01384;-10.09121;,
 -2.72435;-14.01384;-9.79341;,
 -5.44120;-14.01384;-8.77475;,
 -8.03701;-14.01384;-7.25825;,
 5.61928;-9.33464;-9.08683;,
 8.30733;-9.33464;-7.51644;,
 2.80589;-9.33464;-10.14167;,
 -0.00750;-9.33464;-10.45004;,
 -2.82088;-9.33464;-10.14167;,
 -5.63424;-9.33464;-9.08683;,
 -8.32226;-9.33464;-7.51644;,
 -4.37699;-38.42903;-4.29563;,
 -5.23635;-38.42903;-2.91859;,
 -5.23635;-33.38634;-2.91859;,
 -4.37699;-33.38634;-4.29562;,
 -5.72752;-38.42903;-1.45480;,
 -5.72752;-33.38634;-1.45480;,
 -5.96036;-38.42903;0.00900;,
 -5.96036;-33.38634;0.00899;,
 -5.72752;-38.42903;1.47277;,
 -5.72752;-33.38634;1.47277;,
 -5.23635;-38.42903;2.93658;,
 -5.23635;-33.38634;2.93657;,
 -4.37699;-38.42903;4.31360;,
 -4.37699;-33.38634;4.31360;,
 -5.18446;-26.72530;-2.65390;,
 -4.33362;-26.72530;-3.90643;,
 -5.67073;-26.72530;-1.32245;,
 -5.90127;-26.72530;0.00899;,
 -5.67073;-26.72530;1.34045;,
 -5.18446;-26.72530;2.67188;,
 -4.33362;-26.72530;3.92442;,
 -6.48710;-19.45500;-3.32393;,
 -5.42214;-19.45500;-4.89164;,
 -7.09570;-19.45500;-1.65746;,
 -7.38427;-19.45500;0.00900;,
 -7.09570;-19.45500;1.67546;,
 -6.48710;-19.45500;3.34191;,
 -5.42214;-19.45500;4.90962;,
 -7.99706;-16.79590;-4.10061;,
 -6.68394;-16.79590;-6.03364;,
 -8.74754;-16.79590;-2.04581;,
 -9.10331;-16.79590;0.00900;,
 -8.74754;-16.79590;2.06379;,
 -7.99706;-16.79590;4.11859;,
 -6.68394;-16.79590;6.05162;,
 -9.61625;-14.01384;-4.93348;,
 -8.03701;-14.01384;-7.25825;,
 -10.51879;-14.01384;-2.46224;,
 -10.94668;-14.01384;0.00900;,
 -10.51879;-14.01384;2.48021;,
 -9.61625;-14.01384;4.95145;,
 -8.03701;-14.01384;7.27625;,
 -9.95762;-9.33464;-5.10907;,
 -8.32226;-9.33464;-7.51644;,
 -10.89223;-9.33464;-2.55004;,
 -11.33533;-9.33464;0.00900;,
 -10.89223;-9.33464;2.56802;,
 -9.95762;-9.33464;5.12705;,
 -8.32226;-9.33464;7.53440;,
 -2.96442;-38.42903;-5.19389;,
 -3.89770;-43.83876;-3.86187;,
 -5.23635;-38.42903;-2.91859;,
 -1.48595;-38.42903;-5.79730;,
 -1.95260;-43.83876;-4.31078;,
 -0.00750;-43.83876;-4.44200;,
 1.47097;-38.42903;-5.79730;,
 1.93762;-43.83876;-4.31078;,
 2.94943;-38.42903;-5.19389;,
 3.88272;-43.83876;-3.86187;,
 5.22140;-38.42903;-2.91859;,
 -4.26311;-43.83876;-1.92645;,
 -5.72752;-38.42903;-1.45480;,
 -2.13530;-45.22065;-2.15090;,
 -0.00750;-45.22065;-2.21651;,
 2.12031;-45.22065;-2.15090;,
 4.24812;-43.83876;-1.92645;,
 5.71254;-38.42903;-1.45480;,
 -4.43635;-43.83876;0.00900;,
 -5.96036;-38.42903;0.00900;,
 -2.22192;-45.22065;0.00900;,
 -0.00750;-46.19693;0.00900;,
 2.20693;-45.22065;0.00900;,
 4.42136;-43.83876;0.00900;,
 5.94539;-38.42903;0.00900;,
 -4.26311;-43.83876;1.94443;,
 -5.72752;-38.42903;1.47277;,
 -2.13530;-45.22065;2.16887;,
 -0.00750;-45.22065;2.23449;,
 2.12031;-45.22065;2.16887;,
 4.24812;-43.83876;1.94443;,
 5.71254;-38.42903;1.47277;,
 -3.89770;-43.83876;3.87985;,
 -5.23635;-38.42903;2.93658;,
 -1.95260;-43.83876;4.32877;,
 -0.00750;-43.83876;4.45998;,
 1.93762;-43.83876;4.32877;,
 3.88272;-43.83876;3.87985;,
 5.22140;-38.42903;2.93658;,
 -2.96442;-38.42903;5.21187;,
 -4.37699;-38.42903;4.31360;,
 -1.48595;-38.42903;5.81527;,
 -0.00750;-38.42903;5.99164;,
 1.47097;-38.42903;5.81527;,
 2.94943;-38.42903;5.21187;,
 4.36201;-38.42903;4.31360;,
 -9.95762;-9.33464;-5.10907;,
 -7.78879;-5.03986;-7.10422;,
 -5.63424;-9.33464;-9.08683;,
 -3.89816;-5.03986;-7.92915;,
 -2.82088;-9.33464;-10.14167;,
 -0.00750;-5.03986;-8.17030;,
 3.88317;-5.03986;-7.92915;,
 2.80589;-9.33464;-10.14167;,
 7.77384;-5.03986;-7.10422;,
 5.61928;-9.33464;-9.08683;,
 9.94268;-9.33464;-5.10907;,
 -10.89223;-9.33464;-2.55004;,
 -8.51971;-5.03986;-3.54763;,
 -4.26362;-1.48565;-3.96008;,
 -0.00750;-1.48565;-4.08066;,
 4.24863;-1.48565;-3.96008;,
 8.50475;-5.03986;-3.54763;,
 10.87729;-9.33464;-2.55004;,
 -11.33533;-9.33464;0.00900;,
 -8.86620;-5.03986;0.00900;,
 -4.43687;-1.48565;0.00900;,
 -0.00750;-0.24930;0.00900;,
 4.42187;-1.48565;0.00900;,
 8.85127;-5.03986;0.00900;,
 11.32039;-9.33464;0.00900;,
 -10.89223;-9.33464;2.56802;,
 -8.51971;-5.03986;3.56560;,
 -4.26362;-1.48565;3.97806;,
 -0.00750;-1.48565;4.09863;,
 4.24863;-1.48565;3.97806;,
 8.50475;-5.03986;3.56560;,
 10.87729;-9.33464;2.56802;,
 -9.95762;-9.33464;5.12705;,
 -7.78879;-5.03986;7.12221;,
 -3.89816;-5.03986;7.94713;,
 -0.00750;-5.03986;8.18827;,
 3.88317;-5.03986;7.94713;,
 7.77384;-5.03986;7.12221;,
 9.94268;-9.33464;5.12705;,
 -8.32226;-9.33464;7.53440;,
 -5.63424;-9.33464;9.10482;,
 -2.82088;-9.33464;10.15967;,
 -0.00750;-9.33464;10.46802;,
 2.80589;-9.33464;10.15967;,
 5.61928;-9.33464;9.10482;,
 8.30733;-9.33464;7.53440;;
 
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
  218;
  -0.709515;-0.040237;0.703541;,
  -0.488926;-0.083236;0.868345;,
  -0.223701;-0.119914;0.967253;,
  -0.000001;-0.134454;0.990920;,
  0.223701;-0.119914;0.967253;,
  0.488925;-0.083236;0.868346;,
  -0.675136;0.034429;0.736889;,
  -0.415546;0.062345;0.907433;,
  -0.245108;0.076492;0.966474;,
  -0.000001;0.077956;0.996957;,
  0.245108;0.076492;0.966474;,
  0.415546;0.062345;0.907433;,
  -0.607427;-0.083327;0.789993;,
  -0.336579;-0.086509;0.937673;,
  -0.235485;-0.096196;0.967106;,
  -0.000000;-0.093681;0.995602;,
  0.235485;-0.096196;0.967106;,
  0.336578;-0.086509;0.937674;,
  -0.577415;-0.396586;0.713661;,
  -0.330609;-0.410026;0.850045;,
  -0.209320;-0.428872;0.878780;,
  -0.000000;-0.426661;0.904411;,
  0.209320;-0.428872;0.878780;,
  0.330607;-0.410028;0.850045;,
  -0.572776;-0.542402;0.614595;,
  -0.365648;-0.523368;0.769667;,
  -0.197933;-0.519632;0.831147;,
  -0.000000;-0.517201;0.855864;,
  0.197932;-0.519633;0.831147;,
  0.365647;-0.523369;0.769667;,
  -0.645159;-0.325213;0.691380;,
  -0.407806;-0.311867;0.858157;,
  -0.220360;-0.309542;0.925000;,
  -0.000000;-0.307891;0.951422;,
  0.220358;-0.309542;0.925001;,
  0.407804;-0.311868;0.858158;,
  -0.682612;-0.002120;0.730778;,
  -0.462092;0.089538;0.882300;,
  -0.206816;0.169387;0.963605;,
  -0.000000;0.198657;0.980069;,
  0.206814;0.169387;0.963606;,
  0.462091;0.089539;0.882301;,
  0.709509;-0.040237;0.703547;,
  0.883865;-0.085586;0.459845;,
  0.969772;-0.120259;0.212319;,
  0.991134;-0.132869;0.000001;,
  0.969772;-0.120259;-0.212319;,
  0.883865;-0.085586;-0.459845;,
  0.675130;0.034429;0.736895;,
  0.900823;0.012597;0.434003;,
  0.969931;0.006915;0.243280;,
  0.999987;0.005136;0.000000;,
  0.969931;0.006915;-0.243280;,
  0.900823;0.012597;-0.434003;,
  0.607423;-0.083327;0.789997;,
  0.890369;-0.086703;0.446907;,
  0.963350;-0.092249;0.251889;,
  0.995449;-0.095296;-0.000000;,
  0.963350;-0.092248;-0.251887;,
  0.890369;-0.086702;-0.446906;,
  0.577412;-0.396587;0.713662;,
  0.825279;-0.374388;0.422785;,
  0.896067;-0.373969;0.239189;,
  0.925702;-0.378254;0.000000;,
  0.896067;-0.373969;-0.239188;,
  0.825280;-0.374388;-0.422784;,
  0.572776;-0.542403;0.614595;,
  0.747416;-0.542919;0.382895;,
  0.811641;-0.542484;0.216682;,
  0.836716;-0.547638;0.000001;,
  0.811640;-0.542484;-0.216681;,
  0.747416;-0.542920;-0.382895;,
  0.645159;-0.325214;0.691379;,
  0.841703;-0.324964;0.431201;,
  0.913873;-0.324546;0.243939;,
  0.944547;-0.328375;0.000001;,
  0.913873;-0.324546;-0.243938;,
  0.841703;-0.324964;-0.431202;,
  0.682612;-0.002122;0.730778;,
  0.866554;0.098856;0.489195;,
  0.955966;0.183530;0.229010;,
  0.977623;0.210365;0.000001;,
  0.955966;0.183531;-0.229009;,
  0.866554;0.098857;-0.489196;,
  0.709509;-0.040237;-0.703547;,
  0.488925;-0.083236;-0.868345;,
  0.223703;-0.119915;-0.967252;,
  -0.000001;-0.134455;-0.990920;,
  -0.223703;-0.119915;-0.967252;,
  -0.488927;-0.083237;-0.868344;,
  0.703190;0.023172;-0.710624;,
  0.451465;0.032225;-0.891707;,
  0.245628;0.037837;-0.968626;,
  -0.000001;0.039980;-0.999200;,
  -0.245627;0.037837;-0.968626;,
  -0.451466;0.032225;-0.891706;,
  0.687669;-0.076110;-0.722024;,
  0.436006;-0.062324;-0.897783;,
  0.236150;-0.055858;-0.970110;,
  -0.000001;-0.053121;-0.998588;,
  -0.236149;-0.055858;-0.970110;,
  -0.436009;-0.062325;-0.897782;,
  0.632594;-0.374356;-0.677998;,
  0.400577;-0.359094;-0.842965;,
  0.216529;-0.356295;-0.908938;,
  -0.000000;-0.354391;-0.935097;,
  -0.216529;-0.356294;-0.908939;,
  -0.400579;-0.359092;-0.842965;,
  0.572774;-0.542402;-0.614597;,
  0.365647;-0.523367;-0.769669;,
  0.197934;-0.519633;-0.831146;,
  -0.000000;-0.517204;-0.855862;,
  -0.197935;-0.519633;-0.831146;,
  -0.365649;-0.523366;-0.769668;,
  0.645157;-0.325215;-0.691382;,
  0.407804;-0.311868;-0.858158;,
  0.220363;-0.309542;-0.924999;,
  -0.000000;-0.307891;-0.951422;,
  -0.220365;-0.309542;-0.924999;,
  -0.407806;-0.311868;-0.858157;,
  0.682610;-0.002123;-0.730780;,
  0.462089;0.089538;-0.882302;,
  0.206818;0.169387;-0.963605;,
  -0.000000;0.198657;-0.980069;,
  -0.206820;0.169386;-0.963605;,
  -0.462091;0.089537;-0.882301;,
  -0.709515;-0.040237;-0.703540;,
  -0.883865;-0.085584;-0.459846;,
  -0.969772;-0.120257;-0.212324;,
  -0.991134;-0.132868;0.000001;,
  -0.969772;-0.120257;0.212324;,
  -0.883865;-0.085584;0.459846;,
  -0.703197;0.023172;-0.710618;,
  -0.900823;0.012597;-0.434003;,
  -0.969930;0.006916;-0.243284;,
  -0.999987;0.005137;0.000000;,
  -0.969930;0.006916;0.243284;,
  -0.900823;0.012597;0.434003;,
  -0.687674;-0.076110;-0.722019;,
  -0.890371;-0.086702;-0.446904;,
  -0.963350;-0.092247;-0.251887;,
  -0.995449;-0.095294;-0.000000;,
  -0.963350;-0.092247;0.251889;,
  -0.890370;-0.086703;0.446904;,
  -0.632598;-0.374354;-0.677996;,
  -0.825282;-0.374388;-0.422781;,
  -0.896068;-0.373969;-0.239185;,
  -0.925702;-0.378255;-0.000000;,
  -0.896068;-0.373969;0.239186;,
  -0.825281;-0.374388;0.422782;,
  -0.572775;-0.542401;-0.614597;,
  -0.747417;-0.542920;-0.382892;,
  -0.811642;-0.542483;-0.216679;,
  -0.836717;-0.547636;0.000001;,
  -0.811641;-0.542483;0.216679;,
  -0.747417;-0.542920;0.382892;,
  -0.645157;-0.325214;-0.691382;,
  -0.841704;-0.324963;-0.431200;,
  -0.913875;-0.324544;-0.243935;,
  -0.944548;-0.328373;0.000001;,
  -0.913874;-0.324544;0.243935;,
  -0.841705;-0.324963;0.431199;,
  -0.682610;-0.002121;-0.730780;,
  -0.866554;0.098858;-0.489194;,
  -0.955967;0.183530;-0.229007;,
  -0.977623;0.210364;0.000001;,
  -0.955967;0.183530;0.229007;,
  -0.866555;0.098857;0.489194;,
  -0.658410;-0.404463;-0.634749;,
  -0.212075;-0.606628;-0.766177;,
  -0.000000;-0.596603;-0.802537;,
  0.212075;-0.606629;-0.766176;,
  0.658410;-0.404465;-0.634747;,
  -0.770595;-0.603874;-0.203761;,
  -0.293974;-0.910267;-0.291537;,
  -0.000000;-0.922713;-0.385488;,
  0.293974;-0.910267;-0.291537;,
  0.770595;-0.603876;-0.203758;,
  -0.804716;-0.593660;0.000001;,
  -0.387273;-0.921965;0.000001;,
  -0.000000;-1.000000;0.000001;,
  0.387272;-0.921965;0.000001;,
  0.804715;-0.593661;0.000001;,
  -0.770596;-0.603874;0.203761;,
  -0.293974;-0.910267;0.291537;,
  -0.000000;-0.922713;0.385488;,
  0.293974;-0.910267;0.291536;,
  0.770595;-0.603876;0.203758;,
  -0.658411;-0.404462;0.634748;,
  -0.212074;-0.606628;0.766177;,
  -0.000000;-0.596603;0.802537;,
  0.212074;-0.606629;0.766176;,
  0.658411;-0.404464;0.634747;,
  -0.618016;0.464770;-0.634070;,
  -0.207692;0.619102;-0.757348;,
  -0.000000;0.614446;-0.788959;,
  0.207691;0.619103;-0.757348;,
  0.618015;0.464772;-0.634070;,
  -0.736733;0.639121;-0.220792;,
  -0.327199;0.880083;-0.344084;,
  -0.000000;0.904352;-0.426788;,
  0.327197;0.880084;-0.344084;,
  0.736731;0.639123;-0.220793;,
  -0.768276;0.640119;0.000000;,
  -0.404728;0.914437;0.000000;,
  0.000000;1.000000;0.000001;,
  0.404725;0.914438;0.000000;,
  0.768274;0.640121;0.000000;,
  -0.736733;0.639121;0.220793;,
  -0.327199;0.880083;0.344085;,
  -0.000000;0.904351;0.426789;,
  0.327197;0.880084;0.344084;,
  0.736731;0.639123;0.220793;,
  -0.618017;0.464769;0.634070;,
  -0.207690;0.619104;0.757348;,
  -0.000000;0.614447;0.788958;,
  0.207689;0.619104;0.757348;,
  0.618015;0.464772;0.634070;;
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
  4;194,195,123,124;,
  4;195,196,122,123;,
  4;196,197,121,122;,
  4;197,83,120,121;,
  4;164,198,193,163;,
  4;198,199,194,193;,
  4;199,200,195,194;,
  4;200,201,196,195;,
  4;201,202,197,196;,
  4;202,82,83,197;,
  4;165,203,198,164;,
  4;203,204,199,198;,
  4;204,205,200,199;,
  4;205,206,201,200;,
  4;206,207,202,201;,
  4;207,81,82,202;,
  4;166,208,203,165;,
  4;208,209,204,203;,
  4;209,210,205,204;,
  4;210,211,206,205;,
  4;211,212,207,206;,
  4;212,80,81,207;,
  4;167,213,208,166;,
  4;213,214,209,208;,
  4;214,215,210,209;,
  4;215,216,211,210;,
  4;216,217,212,211;,
  4;217,79,80,212;,
  4;36,37,213,167;,
  4;37,38,214,213;,
  4;38,39,215,214;,
  4;39,40,216,215;,
  4;40,41,217,216;,
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
