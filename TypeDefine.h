/*
  TypeDefine.h
  Define Some Useful Data Type in 3D Clipping and Projectting
*/
#if !defined TypeDef

typedef struct Ipoint {
  int x,y;
} Ipoint_t, *Ipoint_p;

typedef struct Gpoint {
  float x,y,z;
} Gpoint_t, *Gpoint_p;

typedef struct poly {
  int      clipCount;
  int      polyCount;          // Original polygon point number
  float    polyLight[10];
  float    polyVector[3];      // Polygon Normal Vector
  BOOL     polyVisible;        // Polygon whether visible
  Gpoint_t polyObject[5];      // Original Object
  Gpoint_t transObject[5];     // Transform Original Object
  Gpoint_t clipObject[10];     // Clip Transform Object
  Gpoint_t projectObject[10];  // Project Clip Object
  Ipoint_t zBufferObject[10];  // Project Object Trans to Project Plane for Z-Buffer processing

  Gpoint_t viewDrawObject[5];       // View Draw Object
  Gpoint_t viewTransObject[5];       // View Transform Object
  Gpoint_t viewProjectObject[5];     // View Transform Project Object

} Poly_t, *Poly_p;

typedef struct object {
  int    polyCount;            // Object polygons number
  BOOL   objectVisible;        // Whether object visible
  Poly_t objectSpace[400];     // Object polygons
  float  transMatrix[4][3];    // Object transforms matrix
  Gpoint_t objCenter;          // Object center point
} Object_t, *Object_p;

#define TypeDef

#endif