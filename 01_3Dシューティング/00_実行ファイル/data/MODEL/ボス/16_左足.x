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
 4.76111;-1.28032;5.75531;,
 3.20703;-1.28032;7.00530;,
 3.53307;-2.53797;9.46673;,
 5.25016;-2.53797;6.48610;,
 1.65296;-1.28032;7.94253;,
 1.81598;-2.53797;10.50229;,
 0.09889;-1.28032;7.94253;,
 0.09889;-2.53797;10.50228;,
 -1.45517;-1.28032;7.94253;,
 -1.61819;-2.53797;10.50229;,
 -3.00925;-1.28032;7.00528;,
 -3.00924;-2.69390;8.45296;,
 -4.56333;-1.28032;5.75531;,
 -4.56333;-2.69390;6.79854;,
 3.87442;-3.97185;10.48725;,
 5.76219;-3.97185;8.65929;,
 1.98666;-3.97185;11.52281;,
 0.09890;-3.97185;11.52281;,
 -1.78887;-3.97185;11.52280;,
 -3.67663;-3.97185;10.48726;,
 -5.56439;-3.97185;8.65928;,
 4.14747;-5.54219;11.38924;,
 6.17176;-5.54219;9.56128;,
 2.12318;-5.54219;12.42480;,
 0.09889;-5.54219;12.42480;,
 -1.92539;-5.54219;12.42480;,
 -3.94968;-5.54219;11.38924;,
 -5.97398;-5.54219;9.56128;,
 4.73108;-6.29771;12.38459;,
 7.04717;-6.29771;11.00350;,
 2.41499;-6.29771;13.42013;,
 0.09889;-6.29771;13.42013;,
 -2.21720;-6.29771;13.42015;,
 -4.53330;-6.29771;12.38459;,
 -6.84938;-6.29771;11.00350;,
 4.73108;-6.95676;12.38459;,
 7.04717;-6.95676;11.00350;,
 2.41499;-6.95676;13.42013;,
 0.09889;-6.95676;13.42013;,
 -2.21720;-6.95676;13.42015;,
 -4.53330;-6.95676;12.38459;,
 -6.84938;-6.95676;11.00350;,
 4.73108;-7.61577;12.38459;,
 7.04717;-7.61577;11.00350;,
 2.41499;-7.61577;13.42013;,
 0.09889;-7.61577;13.42013;,
 -2.21720;-7.61577;13.42015;,
 -4.53330;-7.61577;12.38459;,
 -6.84938;-7.61577;11.00350;,
 -4.56333;-1.28032;5.75531;,
 -4.63360;-1.28032;5.20524;,
 -5.94376;-2.69390;3.07934;,
 -4.56333;-2.69390;6.79854;,
 -5.94375;-1.28032;2.62054;,
 -6.47844;-2.69390;0.49465;,
 -6.47844;-1.28032;0.03585;,
 -6.47844;-2.69390;-2.09004;,
 -6.47844;-1.28032;-2.54885;,
 -5.94375;-2.69390;-4.67474;,
 -5.94375;-1.28032;-5.13354;,
 -6.57760;-2.53797;-7.89382;,
 -5.94375;-1.28032;-7.71825;,
 -5.05237;-2.53797;-11.41380;,
 -7.24125;-3.97185;4.12291;,
 -5.56439;-3.97185;8.65928;,
 -7.89073;-3.97185;-1.59614;,
 -7.24125;-3.97185;-4.73582;,
 -7.24125;-3.97185;-7.87551;,
 -5.56440;-3.97185;-11.65775;,
 -5.56440;-3.97185;-14.54218;,
 -7.77209;-5.54219;4.69091;,
 -5.97398;-5.54219;9.56128;,
 -8.46855;-5.54219;-1.44175;,
 -7.77209;-5.54219;-7.39784;,
 -5.97398;-5.54219;-11.42751;,
 -5.97398;-5.54219;-14.52058;,
 -5.97398;-5.54219;-17.61363;,
 -8.90668;-6.29771;5.37625;,
 -6.84938;-6.29771;11.00350;,
 -9.70356;-6.29771;-1.64044;,
 -8.90668;-6.29771;-8.45510;,
 -6.84938;-6.29771;-12.84469;,
 -6.84938;-6.29771;-16.38364;,
 -6.84939;-6.29771;-19.92255;,
 -8.90668;-6.95676;5.37625;,
 -6.84938;-6.95676;11.00350;,
 -9.70356;-6.95676;-1.64044;,
 -8.90668;-6.95676;-8.45510;,
 -6.84938;-6.95676;-12.84469;,
 -6.84938;-6.95676;-16.38364;,
 -6.84939;-6.95676;-19.92255;,
 -8.90668;-7.61577;5.37625;,
 -6.84938;-7.61577;11.00350;,
 -9.70356;-7.61577;-1.64044;,
 -8.90668;-7.61577;-8.45510;,
 -6.84938;-7.61577;-12.84469;,
 -6.84938;-7.61577;-16.38364;,
 -6.84939;-7.61577;-19.92255;,
 -5.94375;-1.28032;-7.71825;,
 -3.00925;-1.28032;-10.87598;,
 -3.33528;-2.53797;-14.04767;,
 -5.05237;-2.53797;-11.41380;,
 -1.91532;-1.28032;-7.71825;,
 -1.61819;-2.53797;-11.41380;,
 0.09889;-1.28032;-10.87598;,
 0.09889;-2.53797;-14.04767;,
 2.11311;-1.28032;-7.71825;,
 1.81598;-2.53797;-11.41380;,
 3.20703;-1.28032;-10.87598;,
 3.53307;-2.53797;-14.04767;,
 6.14154;-1.28032;-7.71825;,
 5.25016;-2.53797;-11.41380;,
 -3.67663;-3.97185;-17.43787;,
 -5.56440;-3.97185;-14.54218;,
 -1.78887;-3.97185;-14.54218;,
 0.09889;-3.97185;-17.43787;,
 1.98666;-3.97185;-14.54218;,
 3.87442;-3.97185;-17.43787;,
 5.76219;-3.97185;-14.54218;,
 -3.94968;-5.54219;-20.71871;,
 -5.97398;-5.54219;-17.61363;,
 -1.92540;-5.54219;-17.61363;,
 0.09889;-5.54219;-20.71872;,
 2.12319;-5.54219;-17.61363;,
 4.14747;-5.54219;-20.71871;,
 6.17176;-5.54219;-17.61363;,
 -4.53330;-6.29771;-23.47525;,
 -6.84939;-6.29771;-19.92255;,
 -2.21720;-6.29771;-19.92255;,
 0.09889;-6.29771;-23.47525;,
 2.41498;-6.29771;-19.92255;,
 4.73108;-6.29771;-23.47524;,
 7.04717;-6.29771;-19.92255;,
 -4.53330;-6.95676;-23.47525;,
 -6.84939;-6.95676;-19.92255;,
 -2.21720;-6.95676;-19.92255;,
 0.09889;-6.95676;-23.47525;,
 2.41498;-6.95676;-19.92255;,
 4.73108;-6.95676;-23.47524;,
 7.04717;-6.95676;-19.92255;,
 -4.53330;-7.61577;-23.47525;,
 -6.84939;-7.61577;-19.92255;,
 -2.21720;-7.61577;-19.92255;,
 0.09889;-7.61577;-23.47525;,
 2.41498;-7.61577;-19.92255;,
 4.73108;-7.61577;-23.47524;,
 7.04717;-7.61577;-19.92255;,
 6.14154;-1.28032;-7.71825;,
 6.14155;-1.28032;-5.13354;,
 6.77539;-2.53797;-7.89382;,
 5.25016;-2.53797;-11.41380;,
 6.67623;-1.28032;-2.54885;,
 6.77539;-2.53797;-5.03802;,
 6.67623;-1.28032;0.03585;,
 7.36617;-2.53797;-2.18220;,
 6.14155;-1.28032;2.62054;,
 7.36617;-2.53797;0.67362;,
 4.83138;-1.28032;5.20524;,
 6.77539;-2.53797;3.52943;,
 4.76111;-1.28032;5.75531;,
 5.25016;-2.53797;6.48610;,
 5.76219;-3.97185;-11.65775;,
 5.76219;-3.97185;-14.54218;,
 7.43903;-3.97185;-7.87551;,
 7.43903;-3.97185;-4.73582;,
 8.08853;-3.97185;-1.59614;,
 7.43903;-3.97185;4.12291;,
 5.76219;-3.97185;8.65929;,
 6.17176;-5.54219;-14.52058;,
 6.17176;-5.54219;-17.61363;,
 6.17176;-5.54219;-11.42751;,
 7.96987;-5.54219;-4.80851;,
 8.66634;-5.54219;-1.44175;,
 7.96987;-5.54219;4.69091;,
 6.17176;-5.54219;9.56128;,
 7.04717;-6.29771;-16.38364;,
 7.04717;-6.29771;-19.92255;,
 7.04717;-6.29771;-12.84469;,
 9.10448;-6.29771;-5.49251;,
 9.90135;-6.29771;-1.64044;,
 9.10448;-6.29771;5.37625;,
 7.04717;-6.29771;11.00350;,
 7.04717;-6.95676;-16.38364;,
 7.04717;-6.95676;-19.92255;,
 7.04717;-6.95676;-12.84469;,
 9.10448;-6.95676;-5.49251;,
 9.90135;-6.95676;-1.64044;,
 9.10448;-6.95676;5.37625;,
 7.04717;-6.95676;11.00350;,
 7.04717;-7.61577;-16.38364;,
 7.04717;-7.61577;-19.92255;,
 7.04717;-7.61577;-12.84469;,
 9.10448;-7.61577;-8.45510;,
 9.90135;-7.61577;-1.64044;,
 9.10448;-7.61577;5.37625;,
 7.04717;-7.61577;11.00350;,
 3.20703;-1.28032;-10.87598;,
 3.20703;-0.72752;-8.50140;,
 6.14155;-1.28032;-5.13354;,
 2.11311;-1.28032;-7.71825;,
 2.11311;-0.72752;-5.13354;,
 0.09889;-0.72752;-7.72829;,
 -1.91532;-1.28032;-7.71825;,
 -1.91532;-0.72752;-5.13354;,
 -3.00925;-1.28032;-10.87598;,
 -3.92954;-0.72752;-7.72829;,
 -5.94375;-1.28032;-5.13354;,
 4.12732;-0.72752;-5.14360;,
 6.67623;-1.28032;-2.54885;,
 2.29134;-0.03364;-2.54885;,
 0.09889;-0.03364;-5.14360;,
 -2.09355;-0.03364;-2.54885;,
 -3.92954;-0.72752;-5.14360;,
 -6.47844;-1.28032;-2.54885;,
 4.48378;-0.72752;-2.55891;,
 6.67623;-1.28032;0.03585;,
 2.29134;-0.03364;0.03585;,
 0.09889;-0.03364;-2.55891;,
 -2.09355;-0.03364;0.03585;,
 -4.28601;-0.72752;-2.55891;,
 -6.47844;-1.28032;0.03585;,
 4.48378;-0.72752;0.02579;,
 6.14155;-1.28032;2.62054;,
 2.11311;-0.03364;2.62054;,
 0.09889;-0.03364;0.02579;,
 -1.91532;-0.03364;2.62054;,
 -4.28601;-0.72752;0.02579;,
 -5.94375;-1.28032;2.62054;,
 4.12732;-0.72752;5.20524;,
 4.83138;-1.28032;5.20524;,
 2.11311;-0.03364;5.20524;,
 0.09889;-0.03364;5.20524;,
 -1.91532;-0.03364;5.20524;,
 -3.92954;-0.72752;5.20524;,
 -4.63360;-1.28032;5.20524;,
 3.20703;-1.28032;7.00530;,
 4.76111;-1.28032;5.75531;,
 1.65296;-1.28032;7.94253;,
 0.09889;-1.28032;7.94253;,
 -1.45517;-1.28032;7.94253;,
 -3.00925;-1.28032;7.00528;,
 -4.56333;-1.28032;5.75531;,
 7.04717;-7.61577;-16.38364;,
 4.73108;-7.61577;-19.93631;,
 4.73108;-7.61577;-23.47524;,
 2.41498;-7.61577;-16.38364;,
 2.41498;-7.61577;-19.92255;,
 0.09889;-7.61577;-19.93631;,
 -2.21720;-7.61577;-16.38364;,
 -2.21720;-7.61577;-19.92255;,
 -4.53330;-7.61577;-19.93631;,
 -4.53330;-7.61577;-23.47525;,
 -6.84938;-7.61577;-16.38364;,
 7.04717;-7.61577;-12.84469;,
 4.73108;-7.61577;-16.39742;,
 2.41498;-7.61577;-12.84469;,
 0.09889;-7.61577;-16.39742;,
 -2.21720;-7.61577;-12.84469;,
 -4.53330;-7.61577;-16.39742;,
 -6.84938;-7.61577;-12.84469;,
 9.10448;-7.61577;-8.45510;,
 4.73108;-7.61577;-12.85846;,
 3.10076;-7.61577;-8.45510;,
 0.09889;-7.61577;-12.85846;,
 -2.90297;-7.61577;-8.45510;,
 -4.53330;-7.61577;-12.85846;,
 -8.90668;-7.61577;-8.45510;,
 9.90135;-7.61577;-1.64044;,
 6.10262;-7.61577;-8.47010;,
 3.36638;-7.61577;-1.64044;,
 0.09889;-7.61577;-8.47009;,
 -3.16859;-7.61577;-1.64044;,
 -5.90483;-7.61577;-8.47009;,
 -9.70356;-7.61577;-1.64044;,
 9.10448;-7.61577;5.37625;,
 6.10262;-7.61577;5.37625;,
 3.10076;-7.61577;5.37625;,
 0.09889;-7.61577;5.37625;,
 -2.90296;-7.61577;5.37625;,
 -5.90483;-7.61577;5.37625;,
 -8.90668;-7.61577;5.37625;,
 7.04717;-7.61577;11.00350;,
 4.73108;-7.61577;12.38459;,
 2.41499;-7.61577;13.42013;,
 0.09889;-7.61577;13.42013;,
 -2.21720;-7.61577;13.42015;,
 -4.53330;-7.61577;12.38459;,
 -6.84938;-7.61577;11.00350;;
 
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
  203;
  0.634423;0.694230;0.339929;,
  0.397927;0.823822;0.403697;,
  0.133580;0.893961;0.427774;,
  0.000000;0.903888;0.427770;,
  -0.197135;0.867943;0.455865;,
  -0.469290;0.752809;0.461570;,
  0.682429;0.618829;0.389026;,
  0.457863;0.712018;0.532345;,
  0.171524;0.764956;0.620823;,
  -0.000001;0.761960;0.647624;,
  -0.255999;0.757799;0.600170;,
  -0.489397;0.704388;0.514128;,
  0.709180;0.544943;0.447327;,
  0.506173;0.561657;0.654469;,
  0.208425;0.550362;0.808493;,
  -0.000001;0.539602;0.841920;,
  -0.231865;0.588082;0.774854;,
  -0.480249;0.645208;0.594195;,
  0.585703;0.703123;0.403200;,
  0.395835;0.696503;0.598497;,
  0.169519;0.677925;0.715319;,
  -0.000000;0.660476;0.750847;,
  -0.169518;0.677926;0.715318;,
  -0.395834;0.696504;0.598496;,
  0.378713;0.880692;0.284531;,
  0.415121;0.487278;0.768267;,
  0.186950;0.462440;0.866717;,
  0.000002;0.444630;0.895714;,
  -0.186949;0.462442;0.866716;,
  -0.415122;0.487279;0.768266;,
  0.770098;0.000000;0.637925;,
  0.460956;0.000000;0.887423;,
  0.208679;0.000000;0.977984;,
  0.000003;0.000000;1.000000;,
  -0.208678;0.000000;0.977984;,
  -0.460958;0.000000;0.887422;,
  0.208679;0.000000;0.977984;,
  -0.208678;0.000000;0.977984;,
  -0.460958;0.000000;0.887422;,
  -0.721977;0.565534;0.398649;,
  -0.782906;0.559491;0.272083;,
  -0.896626;0.382474;0.223103;,
  -1.000000;-0.000000;0.000000;,
  -0.998474;-0.017049;-0.052527;,
  -0.966461;0.238781;-0.094536;,
  -0.668991;0.633611;0.388572;,
  -0.843154;0.483278;0.235654;,
  -0.894539;0.428826;0.126129;,
  -0.918920;0.392501;-0.039091;,
  -0.954153;0.290628;-0.071601;,
  -0.941339;0.315944;-0.118577;,
  -0.634865;0.657410;0.405906;,
  -0.790562;0.581129;0.193134;,
  -0.825190;0.564853;-0.001485;,
  -0.832299;0.539393;-0.127808;,
  -0.899058;0.412279;-0.147384;,
  -0.941543;0.313944;-0.122215;,
  -0.585703;0.703123;0.403200;,
  -0.736652;0.653714;0.173211;,
  -0.760882;0.648794;-0.011180;,
  -0.748520;0.642763;-0.163014;,
  -0.804033;0.571818;-0.162959;,
  -0.850588;0.523082;-0.053705;,
  -0.378715;0.880691;0.284531;,
  -0.845994;0.494741;0.198809;,
  -0.871654;0.490120;-0.000988;,
  -0.470912;0.872893;-0.127673;,
  -0.862074;0.474197;-0.178786;,
  -0.909220;0.416316;0.000001;,
  -0.770099;0.000000;0.637924;,
  -0.973256;0.000000;0.229722;,
  -0.999999;0.000000;-0.001661;,
  -0.961787;0.000000;-0.273800;,
  -0.976085;0.000000;-0.217388;,
  -1.000000;0.000000;0.000001;,
  -0.973256;0.000000;0.229722;,
  -0.999999;0.000000;-0.001661;,
  -0.976085;0.000000;-0.217388;,
  -0.553487;0.801664;-0.225804;,
  -0.150584;0.965603;-0.211980;,
  0.207968;0.952989;-0.220366;,
  -0.000001;0.961442;-0.275008;,
  0.381507;0.888724;-0.254208;,
  -0.329043;0.920970;-0.208671;,
  -0.705834;0.656637;-0.265756;,
  -0.447497;0.834995;-0.320203;,
  0.573461;0.751089;-0.327121;,
  -0.000001;0.925973;-0.377589;,
  0.503188;0.800205;-0.326304;,
  -0.573463;0.751087;-0.327121;,
  -0.769022;0.599304;-0.222352;,
  -0.490677;0.810500;-0.319885;,
  0.579927;0.721630;-0.378068;,
  -0.532784;0.771687;-0.347334;,
  0.532782;0.771688;-0.347334;,
  -0.579927;0.721630;-0.378068;,
  -0.657763;0.739530;-0.142978;,
  -0.115837;0.940954;-0.318100;,
  0.267447;0.895029;-0.356926;,
  -0.201930;0.928771;-0.310821;,
  0.161331;0.922500;-0.350665;,
  -0.292363;0.896605;-0.332602;,
  -0.833676;0.506033;-0.221168;,
  0.111202;0.952198;-0.284524;,
  0.069093;0.945528;-0.318124;,
  0.000000;0.964431;-0.264335;,
  -0.069091;0.945528;-0.318124;,
  -0.111200;0.952198;-0.284524;,
  -0.958569;0.000000;-0.284862;,
  -0.837706;0.000000;-0.546122;,
  0.837706;0.000000;-0.546121;,
  -0.837707;0.000000;-0.546121;,
  0.837707;0.000000;-0.546120;,
  -0.837704;0.000000;-0.546124;,
  -0.837706;0.000000;-0.546122;,
  0.837706;0.000000;-0.546121;,
  0.837707;0.000000;-0.546120;,
  0.539072;0.811986;-0.223785;,
  0.614356;0.779478;-0.122399;,
  0.626216;0.776286;-0.072351;,
  0.607905;0.794010;0.000621;,
  0.613172;0.776931;0.142824;,
  0.650387;0.720590;0.240305;,
  0.705834;0.656637;-0.265757;,
  0.893153;0.419256;-0.162796;,
  0.895792;0.428749;-0.117182;,
  0.892111;0.449171;-0.048807;,
  0.870563;0.481469;0.101530;,
  0.815170;0.523667;0.247530;,
  0.769022;0.599304;-0.222352;,
  0.938604;0.312255;-0.146693;,
  0.947304;0.278927;-0.157525;,
  0.942937;0.306530;-0.130036;,
  0.927073;0.374767;-0.009269;,
  0.869361;0.439176;0.226575;,
  0.657764;0.739530;-0.142978;,
  0.850589;0.523082;-0.053705;,
  0.844578;0.519451;-0.129843;,
  0.801297;0.577580;-0.155963;,
  0.771911;0.634768;-0.034980;,
  0.736652;0.653714;0.173211;,
  0.487173;0.867653;-0.099202;,
  0.909220;0.416316;0.000000;,
  0.882137;0.456671;-0.115266;,
  0.846420;0.491416;-0.205144;,
  0.869521;0.492360;-0.038914;,
  0.845993;0.494743;0.198809;,
  0.958568;0.000000;-0.284863;,
  1.000000;0.000000;0.000000;,
  0.981776;0.110290;-0.154763;,
  0.954573;0.169860;-0.244821;,
  0.997577;0.060619;-0.034144;,
  0.973256;0.000000;0.229723;,
  0.959578;0.222701;-0.172089;,
  0.908979;0.336291;-0.246302;,
  0.992363;0.121252;-0.022673;,
  0.973256;0.000000;0.229723;,
  -0.018085;0.991448;-0.129245;,
  0.008480;0.979512;-0.201205;,
  -0.000001;0.973104;-0.230368;,
  -0.080760;0.979448;-0.184823;,
  -0.067937;0.991693;-0.109222;,
  0.204159;0.977190;-0.058469;,
  0.157040;0.982126;-0.103760;,
  -0.000000;0.991162;-0.132659;,
  -0.157040;0.982126;-0.103760;,
  -0.204243;0.977676;-0.049345;,
  0.273215;0.961953;-0.000500;,
  0.152635;0.988279;-0.002625;,
  0.000000;1.000000;0.000000;,
  -0.152634;0.988279;-0.002625;,
  -0.273215;0.961953;-0.000499;,
  0.329510;0.942679;0.052719;,
  0.155784;0.987777;0.005261;,
  -0.155783;0.987777;0.005261;,
  -0.329510;0.942679;0.052719;,
  0.391222;0.893784;0.219307;,
  0.153670;0.963249;0.220310;,
  0.000000;0.977256;0.212064;,
  -0.153669;0.963249;0.220310;,
  -0.391222;0.893784;0.219308;,
  0.000000;-1.000000;-0.000000;,
  0.579971;0.763259;-0.284726;,
  -0.493319;0.809586;-0.318131;,
  -0.503190;0.800204;-0.326303;,
  -0.563288;0.792378;-0.234188;,
  0.428015;0.839010;-0.335953;,
  0.447496;0.834995;-0.320203;,
  0.490677;0.810500;-0.319885;,
  0.593733;0.705450;-0.387068;,
  -0.552143;0.752044;-0.359955;,
  0.552141;0.752045;-0.359956;,
  -0.593733;0.705450;-0.387068;,
  0.514067;0.789569;-0.335134;,
  -0.837706;0.000000;-0.546122;,
  0.837706;0.000000;-0.546121;,
  -0.837704;0.000000;-0.546124;,
  0.837706;0.000000;-0.546122;,
  0.837706;0.000000;-0.546122;,
  -0.264282;0.961590;-0.074163;,
  -0.254630;0.966786;-0.022118;,
  -0.244471;0.969648;0.004191;,
  -0.244304;0.969370;0.025242;;
  216;
  4;0,1,7,6;,
  4;1,2,8,7;,
  4;2,3,9,8;,
  4;3,4,10,9;,
  4;4,5,11,10;,
  4;5,39,45,11;,
  4;6,7,13,12;,
  4;7,8,14,13;,
  4;8,9,15,14;,
  4;9,10,16,15;,
  4;10,11,17,16;,
  4;11,45,51,17;,
  4;12,13,19,18;,
  4;13,14,20,19;,
  4;14,15,21,20;,
  4;15,16,22,21;,
  4;16,17,23,22;,
  4;17,51,57,23;,
  4;18,19,25,24;,
  4;19,20,26,25;,
  4;20,21,27,26;,
  4;21,22,28,27;,
  4;22,23,29,28;,
  4;23,57,63,29;,
  4;30,25,31,30;,
  4;25,26,32,31;,
  4;26,27,33,32;,
  4;27,28,34,33;,
  4;28,29,35,34;,
  4;29,69,69,35;,
  4;30,31,31,30;,
  4;31,32,36,31;,
  4;32,33,33,36;,
  4;33,34,37,33;,
  4;34,35,38,37;,
  4;35,69,69,38;,
  4;39,40,46,45;,
  4;40,41,47,46;,
  4;41,42,48,47;,
  4;42,43,49,48;,
  4;43,44,50,49;,
  4;44,78,84,50;,
  4;45,46,52,51;,
  4;46,47,53,52;,
  4;47,48,54,53;,
  4;48,49,55,54;,
  4;49,50,56,55;,
  4;50,84,90,56;,
  4;51,52,58,57;,
  4;52,53,59,58;,
  4;53,54,60,59;,
  4;54,55,61,60;,
  4;55,56,62,61;,
  4;56,90,96,62;,
  4;57,58,64,63;,
  4;58,59,65,64;,
  4;59,60,66,65;,
  4;60,61,67,66;,
  4;61,62,68,67;,
  4;62,96,102,68;,
  4;69,64,70,69;,
  4;64,65,71,70;,
  4;65,72,72,71;,
  4;72,67,73,72;,
  4;67,68,74,73;,
  4;68,102,108,74;,
  4;69,70,75,69;,
  4;70,71,76,75;,
  4;71,72,72,76;,
  4;72,73,77,72;,
  4;73,74,74,77;,
  4;74,108,108,74;,
  4;78,79,85,84;,
  4;182,80,86,86;,
  4;183,81,87,184;,
  4;81,82,88,87;,
  4;185,83,89,89;,
  4;186,117,123,187;,
  4;84,85,91,90;,
  4;86,86,92,92;,
  4;184,87,93,93;,
  4;87,88,94,94;,
  4;89,89,95,95;,
  4;187,123,129,188;,
  4;90,91,97,96;,
  4;92,92,98,189;,
  4;93,93,99,190;,
  4;94,94,100,191;,
  4;95,95,101,192;,
  4;188,129,135,193;,
  4;96,97,103,102;,
  4;97,98,104,103;,
  4;98,99,105,104;,
  4;99,100,106,105;,
  4;100,101,107,106;,
  4;101,135,141,107;,
  4;102,194,109,108;,
  4;195,195,110,110;,
  4;111,111,111,111;,
  4;116,116,112,112;,
  4;196,196,113,113;,
  4;197,147,147,197;,
  4;108,109,114,108;,
  4;110,110,115,115;,
  4;111,111,111,111;,
  4;112,112,116,116;,
  4;113,113,113,113;,
  4;197,147,147,198;,
  4;117,118,124,123;,
  4;118,119,125,124;,
  4;119,120,126,125;,
  4;120,121,127,126;,
  4;121,122,128,127;,
  4;122,0,6,128;,
  4;123,124,130,129;,
  4;124,125,131,130;,
  4;125,126,132,131;,
  4;126,127,133,132;,
  4;127,128,134,133;,
  4;128,6,12,134;,
  4;129,130,136,135;,
  4;130,131,137,136;,
  4;131,132,138,137;,
  4;132,133,139,138;,
  4;133,134,140,139;,
  4;134,12,18,140;,
  4;135,136,142,141;,
  4;136,137,143,142;,
  4;137,138,144,143;,
  4;138,139,145,144;,
  4;139,140,146,145;,
  4;140,18,24,146;,
  4;147,142,148,147;,
  4;142,143,149,148;,
  4;143,144,150,149;,
  4;144,145,151,150;,
  4;145,146,152,151;,
  4;146,30,30,152;,
  4;147,148,148,147;,
  4;148,149,153,148;,
  4;149,150,154,153;,
  4;150,151,155,154;,
  4;151,152,156,155;,
  4;152,30,30,156;,
  4;117,83,157,118;,
  4;83,185,158,157;,
  4;82,81,159,158;,
  4;81,80,160,159;,
  4;80,79,161,160;,
  4;79,78,199,161;,
  4;118,157,162,119;,
  4;157,158,163,162;,
  4;158,159,164,163;,
  4;159,160,165,164;,
  4;160,161,166,165;,
  4;161,199,200,166;,
  4;119,162,167,120;,
  4;162,163,168,167;,
  4;163,164,169,168;,
  4;164,165,170,169;,
  4;165,166,171,170;,
  4;166,200,201,171;,
  4;120,167,172,121;,
  4;167,168,173,172;,
  4;168,169,169,173;,
  4;169,170,174,169;,
  4;170,171,175,174;,
  4;171,201,202,175;,
  4;121,172,176,122;,
  4;172,173,177,176;,
  4;173,169,178,177;,
  4;169,174,179,178;,
  4;174,175,180,179;,
  4;175,41,40,180;,
  4;122,176,1,0;,
  4;176,177,2,1;,
  4;177,178,3,2;,
  4;178,179,4,3;,
  4;179,180,5,4;,
  4;180,40,39,5;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;,
  4;181,181,181,181;;
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
